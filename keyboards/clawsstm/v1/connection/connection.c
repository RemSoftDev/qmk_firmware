// USART1 верхний - на раба
// USART2 боковой - на раба
// USART6 - на хост (переключается верх/бок вместе с USB)

#include "connection.h"

#include "ch.h"
#include "hal.h"

#include "chprintf.h"

BaseSequentialStream * bs1 = (BaseSequentialStream *) &SD1;
BaseSequentialStream * bs2 = (BaseSequentialStream *) &SD2;
BaseSequentialStream * bs6 = (BaseSequentialStream *) &SD6;

static bool is_swHostUp;

//connection thread
static THD_WORKING_AREA(conThread1, 128);
static THD_FUNCTION(funConThread1, arg) {
  (void)arg;
  chRegSetThreadName("ThreadConnection");

  conn_init_ports();

  //conn_test_usart_up(); // USB сбоку и usart к рабу сверху
  //conn_test_usart_side(); // USB вверх usart в сторону
  //conn_test_usart_host(); // USB сбоку и через десять секунд там usart6

  while(true) {

    chThdSleepMilliseconds(10);
  }
}

void connection_star_thread(void) {
  chThdCreateStatic(conThread1, sizeof(conThread1), NORMALPRIO + 1, funConThread1, NULL);
}

void conn_init_ports(void){

  palSetLineMode(MON_TX, PAL_MODE_RESET);
  palSetLineMode(MON_RX, PAL_MODE_RESET);
  palSetLineMode(TX1, PAL_MODE_RESET);
  palSetLineMode(RX1, PAL_MODE_RESET);
  palSetLineMode(TX6, PAL_MODE_RESET);
  palSetLineMode(RX6, PAL_MODE_RESET);

  palSetLineMode(STROB_PORT, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(STROB_PORT);

  palSetLineMode(SEL_PORT, PAL_MODE_OUTPUT_PUSHPULL);
}

//переключает мультиплексор связи с хостом на верхний
void conn_sw_up(void){
  palSetLine(SEL_PORT); // ВЕРХНИЙ
  chThdSleepMicroseconds(1);
  palSetLine(STROB_PORT);

  is_swHostUp = TRUE;

  chThdSleepMicroseconds(1);
  palClearLine(STROB_PORT);
}

//переключает мультиплексор связи с хостом на боковой
void conn_sw_side(void){
  palClearLine(SEL_PORT);
  chThdSleepMicroseconds(1);
  palSetLine(STROB_PORT);

  is_swHostUp = FALSE;

  chThdSleepMicroseconds(1);
  palClearLine(STROB_PORT);
}

void conn_init_usart_up(void) {
  //usart1
  palSetLineMode(TX1, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(7));
  palSetLineMode(RX1, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(7));
  sdStart(&SD1, NULL);
  //sdStart(&SD2, &sd2_configuration);
}

void conn_init_usart_side(void) {
  //usart2
  palSetLineMode(MON_TX, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(7));
  palSetLineMode(MON_RX, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(7));
  sdStart(&SD2, NULL);
}

void conn_init_usart_host(void) {
  //usart6
  palSetLineMode(TX6, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(8));
  palSetLineMode(RX6, PAL_STM32_MODE_ALTERNATE | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(8));
  // когда линия RX висит воздухе входной буфер сыплет мусором....
  //palSetLineMode(RX6, PAL_STM32_PUPDR_MASK | PAL_STM32_PUPDR_PULLUP | PAL_STM32_MODE_ALTERNATE | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(8));
  //GPIOC->PUPDR |= GPIO_PUPDR_PUPDR7_0;  // подтягивающий резистор на RX6
  sdStart(&SD6, NULL);
}



void conn_test_usart_up(void) {

  conn_sw_side(); // usb в сторону

  conn_init_usart_up();

  while (true) {

    static uint8_t cc;
    int32_t len;
    uint8_t buff[32];

    len = sdReadTimeout(&SD1, buff, sizeof(buff), OSAL_MS2I(100));
    chprintf(bs1, "> %03d -", cc++);
    chprintf(bs1, "len=%d -", len);
      if (len) {
        sdWriteTimeout(&SD1, buff, len, OSAL_MS2I(100));
        //chprintf(bs1, "%02x", buff[0]);
      } else {
        chnWrite(&SD1, (const uint8_t *)"NO? Hello USART1 ", 17);
        //chprintf(bs1, "no");
      }

    chprintf(bs1, "\r\n");
    chThdSleepMilliseconds(300);
  }
}

void conn_test_usart_side(void) {

  conn_sw_up();

  conn_init_usart_side();

  while (true) {

    static uint8_t cc;
    int32_t len;
    uint8_t buff[32];

    len = sdReadTimeout(&SD2, buff, sizeof(buff), OSAL_MS2I(100));
    chprintf(bs2, "> %03d -", cc++);
    chprintf(bs2, "len=%d -", len);
      if (len) {
        sdWriteTimeout(&SD2, buff, len, OSAL_MS2I(100));
      } else {
        chnWrite(&SD2, (const uint8_t *)"NO? Hello USART2 ", 17);
      }

    chprintf(bs2, "\r\n");
    chThdSleepMilliseconds(300);
  }
}

void conn_test_usart_host(void) {

  conn_sw_side(); // мултиплексор usb на боковой разем

  chThdSleepSeconds(10);

  // пины порта USB из альтернативного в аналоговое состояние
  palSetLineMode(OTG_FS_DM, PAL_MODE_INPUT_ANALOG);
  palSetLineMode(OTG_FS_DP, PAL_MODE_INPUT_ANALOG);
  //palSetLineMode(OTG_FS_DM, PAL_MODE_INPUT_PULLUP);
  //palSetLineMode(OTG_FS_DP, PAL_MODE_INPUT_PULLUP);

  conn_init_usart_host();

  while (true) {

    static uint8_t cc;
    int32_t len;
    uint8_t buff[32];

    len = sdReadTimeout(&SD6, buff, sizeof(buff), OSAL_MS2I(100));
    chprintf(bs6, "> %03d -", cc++);
    chprintf(bs6, "len=%d -", len);
      if (len) {
        sdWriteTimeout(&SD6, buff, len, OSAL_MS2I(100));
      } else {
        chnWrite(&SD6, (const uint8_t *)"NO? Hello USART6 ", 17);
      }

    chprintf(bs6, "\r\n");
    chThdSleepMilliseconds(300);
  }
}

