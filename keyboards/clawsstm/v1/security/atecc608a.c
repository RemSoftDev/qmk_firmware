
#include "atecc608a.h"

#include "ch.h"
#include "hal.h"

#define ATECC608A_I2C_ADDR     0x60

static const I2CConfig i2cconfig = {
  OPMODE_I2C,
  100000,
  STD_DUTY_CYCLE //STD_DUTY_CYCLE_2,
};

void atecc608a_Init(void){

  // даташит - Wake: if SDA is held low for a period of greater than tWLO
  palSetLineMode(I2C3_SDA, PAL_STM32_OTYPE_OPENDRAIN);
  palClearLine(I2C3_SDA);
  chThdSleepMicroseconds(200); //min 60
  palSetLine(I2C3_SDA);
  chThdSleepMicroseconds(1600); //min1500

  // настройка портов на режим I2C atecc608a
  palSetLineMode(I2C3_SCL, PAL_MODE_ALTERNATE(4) |
                 PAL_STM32_OTYPE_OPENDRAIN |
                 PAL_STM32_OSPEED_HIGHEST |
                 PAL_STM32_PUPDR_PULLUP);
  palSetLineMode(I2C3_SDA, PAL_MODE_ALTERNATE(4) |
                 PAL_STM32_OTYPE_OPENDRAIN |
                 PAL_STM32_OSPEED_HIGHEST |
                 PAL_STM32_PUPDR_PULLUP);
  chThdSleepMicroseconds(3000);

  i2cStart( &I2CD3, &i2cconfig );

  uint8_t txbuf=0;
  msg_t msg = i2cMasterTransmitTimeout( &I2CD3, 0x00,
                                          &txbuf, sizeof(txbuf),
                                          NULL, 0,
                                          TIME_US2I( 50 ));
  if(msg != MSG_OK) ;
}


// thread
static THD_WORKING_AREA(securityThread1, 128);
static THD_FUNCTION(funThread1, arg) {
  (void)arg;
  chRegSetThreadName("ThreadSecurity");

  atecc608a_Init();

  chek_bme280();

  while (true) {
    //palToggleLine(LED_OK);
    chThdSleepMilliseconds(100);
  }
}

void security_star_thread(void) {
  chThdCreateStatic(securityThread1, sizeof(securityThread1), NORMALPRIO + 1, funThread1, NULL);
}

void chek_bme280(void){

//  uint8_t txbuf[1];
  uint8_t rxbuf[14];

/*
  txbuf[0]=0;
  msg_t msg = i2cMasterTransmitTimeout( &I2CD3, 0x76,
                                          txbuf, 1,
                                          rxbuf, sizeof(rxbuf),
                                          TIME_US2I( 500 ));
  if(msg != MSG_OK) ;
*/
  while (true) {

    chThdSleepMilliseconds(100);

    msg_t msg = i2cMasterReceiveTimeout( &I2CD3, 0x76,
                                          rxbuf, sizeof(rxbuf),
                                          TIME_MS2I( 10 ));
    if(msg != MSG_OK) chThdSleepMilliseconds(100);

  }
}
