#include "ws2812_pwm.h"
#include "quantum.h"
#include "hal.h"

#include "rgblight.h"
#include <string.h>

// reff https://github.com/joewa/WS2812-LED-Driver_ChibiOS/

#ifndef WS2812_PWM_TARGET_PERIOD
#    define WS2812_PWM_TARGET_PERIOD 800000
#endif

/* --- PRIVATE CONSTANTS ---------------------------------------------------- */

#define WS2812_PWM_FREQUENCY (STM32_SYSCLK / 2)                             /**< Clock frequency of PWM, must be valid with respect to system clock! */
#define WS2812_PWM_PERIOD (WS2812_PWM_FREQUENCY / WS2812_PWM_TARGET_PERIOD) /**< Clock period in ticks. 1 / 800kHz = 1.25 uS (as per datasheet) */

/**
 * @brief   Number of bit-periods to hold the data line low at the end of a frame
 *
 * The reset period for each frame must be at least 50 uS; so we add in 50 bit-times
 * of zeroes at the end. (50 bits)*(1.25 uS/bit) = 62.5 uS, which gives us some
 * slack in the timing requirements
 */
#define WS2812_RESET_BIT_N (96)  // при 50 проскакивали включение светодиода цветом соседа...
#define WS2812_COLOR_BIT_N (RGBLED_NUM * 24)                   /**< Number of data bits */
#define WS2812_BIT_N (WS2812_COLOR_BIT_N + WS2812_RESET_BIT_N) /**< Total number of bits in a frame */

/**
 * @brief   High period for a zero, in ticks
 *
 * Per the datasheet:
 * WS2812:
 * - T0H: 200 nS to 500 nS, inclusive
 * - T0L: 650 nS to 950 nS, inclusive
 * WS2812B:
 * - T0H: 200 nS to 500 nS, inclusive
 * - T0L: 750 nS to 1050 nS, inclusive
 *
 * The duty cycle is calculated for a high period of 350 nS.
 */
#define WS2812_DUTYCYCLE_0 (WS2812_PWM_FREQUENCY / (1000000000 / 350))

/**
 * @brief   High period for a one, in ticks
 *
 * Per the datasheet:
 * WS2812:
 * - T1H: 550 nS to 850 nS, inclusive
 * - T1L: 450 nS to 750 nS, inclusive
 * WS2812B:
 * - T1H: 750 nS to 1050 nS, inclusive
 * - T1L: 200 nS to 500 nS, inclusive
 *
 * The duty cycle is calculated for a high period of 800 nS.
 * This is in the middle of the specifications of the WS2812 and WS2812B.
 */
#define WS2812_DUTYCYCLE_1 (WS2812_PWM_FREQUENCY / (1000000000 / 800))

/* --- PRIVATE MACROS ------------------------------------------------------- */

/**
 * @brief   Determine the index in @ref ws2812_frame_buffer "the frame buffer" of a given bit
 *
 * @param[in] led:                  The led index [0, @ref RGBLED_NUM)
 * @param[in] byte:                 The byte number [0, 2]
 * @param[in] bit:                  The bit number [0, 7]
 *
 * @return                          The bit index
 */
#define WS2812_BIT(led, byte, bit) (24 * (led) + 8 * (byte) + (7 - (bit)))

/**
 * @brief   Determine the index in @ref ws2812_frame_buffer "the frame buffer" of a given red bit
 *
 * @note    The red byte is the middle byte in the color packet
 *
 * @param[in] led:                  The led index [0, @ref RGBLED_NUM)
 * @param[in] bit:                  The bit number [0, 7]
 *
 * @return                          The bit index
 */
#define WS2812_RED_BIT(led, bit) WS2812_BIT((led), 1, (bit))

/**
 * @brief   Determine the index in @ref ws2812_frame_buffer "the frame buffer" of a given green bit
 *
 * @note    The red byte is the first byte in the color packet
 *
 * @param[in] led:                  The led index [0, @ref RGBLED_NUM)
 * @param[in] bit:                  The bit number [0, 7]
 *
 * @return                          The bit index
 */
#define WS2812_GREEN_BIT(led, bit) WS2812_BIT((led), 0, (bit))

/**
 * @brief   Determine the index in @ref ws2812_frame_buffer "the frame buffer" of a given blue bit
 *
 * @note    The red byte is the last byte in the color packet
 *
 * @param[in] led:                  The led index [0, @ref RGBLED_NUM)
 * @param[in] bit:                  The bit index [0, 7]
 *
 * @return                          The bit index
 */
#define WS2812_BLUE_BIT(led, bit) WS2812_BIT((led), 2, (bit))

/* --- PRIVATE VARIABLES ---------------------------------------------------- */

static uint32_t ws2812_frame_buffer[WS2812_BIT_N + 1]; /**< Buffer for a frame */

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */
/*
 * Gedanke: Double-buffer type transactions: double buffer transfers using two memory pointers for
the memory (while the DMA is reading/writing from/to a buffer, the application can
write/read to/from the other buffer).
 */

void ws2812_init(void) {
    // Initialize led frame buffer
    uint32_t i;
    for (i = 0; i < WS2812_COLOR_BIT_N; i++) ws2812_frame_buffer[i] = WS2812_DUTYCYCLE_0;      // All color bits are zero duty cycle
    for (i = 0; i < WS2812_RESET_BIT_N; i++) ws2812_frame_buffer[i + WS2812_COLOR_BIT_N] = 0;  // All reset bits are zero

    palSetLineMode(RGB_DI_PIN, PAL_MODE_ALTERNATE(WS2812_PWM_PAL_MODE) | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_PUPDR_FLOATING);

    // PWM Configuration
    //#pragma GCC diagnostic ignored "-Woverride-init"  // Turn off override-init warning for this struct. We use the overriding ability to set a "default" channel config
    static const PWMConfig ws2812_pwm_config = {
        .frequency = WS2812_PWM_FREQUENCY,
        .period    = WS2812_PWM_PERIOD,  // Mit dieser Periode wird UDE-Event erzeugt und ein neuer Wert (Länge WS2812_BIT_N) vom DMA ins CCR geschrieben
        .callback  = NULL,
        .channels =
            {
                [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},     // Channels default to disabled
                [WS2812_PWM_CHANNEL - 1] = {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},  // Turn on the channel we care about
            },
        .cr2  = 0,
        .dier = TIM_DIER_UDE,  // DMA on update event for next period
    };
    //#pragma GCC diagnostic pop  // Restore command-line warning options

    // Configure DMA
    // dmaInit(); // Joe added this
    dmaStreamAllocate(WS2812_DMA_STREAM,
                      10,
                      NULL,
                      NULL);
    dmaStreamSetPeripheral(WS2812_DMA_STREAM,
                           &(WS2812_PWM_DRIVER.tim->CCR[WS2812_PWM_CHANNEL - 1]));
    dmaStreamSetMemory0(WS2812_DMA_STREAM, ws2812_frame_buffer);
    dmaStreamSetTransactionSize(WS2812_DMA_STREAM, WS2812_BIT_N);
    dmaStreamSetMode(WS2812_DMA_STREAM,
                     STM32_DMA_CR_CHSEL(WS2812_DMA_CHANNEL) | STM32_DMA_CR_DIR_M2P | STM32_DMA_CR_PSIZE_WORD | STM32_DMA_CR_MSIZE_WORD | STM32_DMA_CR_MINC | STM32_DMA_CR_CIRC | STM32_DMA_CR_PL(3));
    // M2P: Memory 2 Periph; PL: Priority Level

    // Start DMA
    dmaStreamEnable(WS2812_DMA_STREAM);

    // Configure PWM
    // NOTE: It's required that preload be enabled on the timer channel CCR register. This is currently enabled in the
    // ChibiOS driver code, so we don't have to do anything special to the timer. If we did, we'd have to start the timer,
    // disable counting, enable the channel, and then make whatever configuration changes we need.
    pwmStart(&WS2812_PWM_DRIVER, &ws2812_pwm_config);
    pwmEnableChannel(&WS2812_PWM_DRIVER, WS2812_PWM_CHANNEL - 1, 0);  // Initial period is 0; output will be low until first duty cycle is DMA'd in
}

void ws2812_write_led(uint16_t led_number, uint8_t r, uint8_t g, uint8_t b) {
    // Write color to frame buffer
    for (uint8_t bit = 0; bit < 8; bit++) {
        ws2812_frame_buffer[WS2812_RED_BIT(led_number, bit)]   = ((r >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        ws2812_frame_buffer[WS2812_GREEN_BIT(led_number, bit)] = ((g >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        ws2812_frame_buffer[WS2812_BLUE_BIT(led_number, bit)]  = ((b >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
    }
}

// Setleds for standard RGB
void ws2812_setleds(LED_TYPE* ledarray, uint16_t leds) {
    for (uint16_t i = 0; i < leds; i++) {
        ws2812_write_led(i, ledarray[i].r, ledarray[i].g, ledarray[i].b);
    }
}

void ws2812_test_blok(void){
  int s = 0;
  uint8_t r=0, b=0, g=0;
  while (true) {

    for (int n = 0; n < WS2812_LED_N; n++) {
      // colorwheel function
      int position = (s + 5*n) % 100;
      switch (position >> 5) {
      case 0:
        r = 31 - position % 32; // Red down
        g = position % 32;      // Green up
        b = 0;                  // blue off
        break;
      case 1:
        g = 31 - position % 32; // green down
        b = position % 32;      // blue up
        r = 0;                  // red off
        break;
      case 2:
        b = 31 - position % 32; // blue down
        r = position % 32;      // red up
        g = 0;                  // green off
        break;
      }
      ws2812_write_led(n, r, g, b);
    }
    s += 3;
    chThdSleepMilliseconds(50);
  }
}

void ws2812_test_main(uint16_t sped){

  static int s = 0;
  uint8_t r=0, b=0, g=0;
  static uint16_t d1_timer = 0;

  if (timer_elapsed(d1_timer) > sped) {
    d1_timer = timer_read();

    for (int n = 0; n < WS2812_LED_N; n++) {
      // colorwheel function
      int position = (s + 5*n) % 100;
      switch (position >> 5) {
      case 0:
        r = 31 - position % 32; // Red down
        g = position % 32;      // Green up
        b = 0;                  // blue off
        break;
      case 1:
        g = 31 - position % 32; // green down
        b = position % 32;      // blue up
        r = 0;                  // red off
        break;
      case 2:
        b = 31 - position % 32; // blue down
        r = position % 32;      // red up
        g = 0;                  // green off
        break;
      }
      ws2812_write_led(n, r, g, b);
    }
    s += 3;
  }
}

// вызывается QMK
void rgblight_set(void) {

  // поверх єфекта сотояние CAPSLOCK
  if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
    led[1].r = 64;
    led[1].g = 0;
    led[1].b = 64;
  }else{
    led[1].r = 0;
    led[1].g = 0;
    led[1].b = 0;
  }

  ws2812_setleds(led, RGBLED_NUM);
}

