/**
 * config.h
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

// define if left board
//#define LEFT_CLAW

/* USB Device descriptor parameter */
#define VENDOR_ID       0x60BE
#define PRODUCT_ID      0x00BE
#define DEVICE_VER      0x0001

/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER    TarasTest

#ifdef LEFT_CLAW
#define PRODUCT         hwtest_left_claw   //tt это видно пользователю когда винда нашла новое оборудование и пытается найти драйвер
#define WS_LED_CAPS_LOCK 25    // номер светодиода WS2812 отвечающего CAPSLOCK
#define WS_LED_CAPS_LOCK_R   100
#define WS_LED_CAPS_LOCK_G   0
#define WS_LED_CAPS_LOCK_B   100
#else
#define PRODUCT         hwtest_right_claw
#endif

#define DESCRIPTION     keyboard test hw

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { B13, B12, B14, B15, C9, A8 }
#define MATRIX_COL_PINS { A0, A1, A4, A5, A6, A7, C4, C5, A15, D2 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 0

#define WS2812_LED_N 54
#define RGBLED_NUM WS2812_LED_N
#define WS2812_DMA_STREAM STM32_DMA1_STREAM6  // DMA stream for TIMx_UP (look up in reference manual under DMA Channel selection)
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 128
#define RGB_DI_PIN B8
#define WS2812_PWM_DRIVER PWMD4

#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP

 #define RGBLIGHT_HUE_STEP 8
 #define RGBLIGHT_SAT_STEP 8

// tapping setting
#define TAPPING_TERM 200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD

#define USB_POLLING_INTERVAL_MS   1


#endif
