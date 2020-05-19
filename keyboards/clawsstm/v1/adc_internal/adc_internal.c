/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
// нужно засинхронизировать запуск по таймеру и тогда необходимость в потоке
// отпадет (данные забирать в калбеке)

#include "adc_internal.h"

#include "ch.h"
#include "hal.h"
//#include "chprintf.h"

#include "thermometer_int.h"
#include "voltage.h"
#include "joystick.h"
#include "display.h"

//BaseSequentialStream * chp = (BaseSequentialStream *) &SD2;

adcint_t adcint;

// 5ть каналов в одном семпле оцифровывает за 80микросек при ADC_SAMPLE_144
#define NUM_CHANNELS     5
#define NUM_SAMPELS      1

static adcsample_t adc_buff[NUM_SAMPELS] [NUM_CHANNELS];

// ADC1_in8 5v

static const ADCConversionGroup adc_group_conf = {
  FALSE,                            // не циклично
  NUM_CHANNELS,                        // количесво каналов в группе семпла
  NULL,
  NULL,
  0,                                  /* CR1 */
  ADC_CR2_SWSTART,                    /* CR2 */
  ADC_SMPR1_SMP_AN15(ADC_SAMPLE_144) | ADC_SMPR1_SMP_SENSOR(ADC_SAMPLE_144) | ADC_SMPR1_SMP_VREF(ADC_SAMPLE_144), /* SMPR1 */
  ADC_SMPR2_SMP_AN9(ADC_SAMPLE_144) | ADC_SMPR2_SMP_AN8(ADC_SAMPLE_144), /* SMPR2 */
  ADC_SQR1_NUM_CH(NUM_CHANNELS),         /* SQR1 */
  0,                                  /* SQR2 */
  // порядок опроса в семпле
  ADC_SQR3_SQ5_N(ADC_CHANNEL_SENSOR) |
  ADC_SQR3_SQ4_N(ADC_CHANNEL_VREFINT) |
  ADC_SQR3_SQ3_N(ADC_CHANNEL_IN8) |
  ADC_SQR3_SQ2_N(ADC_CHANNEL_IN9) |
  ADC_SQR3_SQ1_N (ADC_CHANNEL_IN15)   /* SQR3 */
};

static THD_WORKING_AREA(adcThread1, 128);
static THD_FUNCTION(funADCThread1, arg) {
  (void) arg;
  chRegSetThreadName("TreadADCinternal");

  ADCinternal_init();
  adcint.is_adc_sampl = FALSE;
  adcStart(&ADCD1, NULL);
  adcSTM32EnableTSVREFE();

  chThdSleepMilliseconds(100);

  while(TRUE) {

  //   if (!adcint.is_adc_sampl){ // если обработали предідущий семпл

      //palSetLine(LED_OK);
      adcConvert(&ADCD1, &adc_group_conf, (adcsample_t*) adc_buff, NUM_SAMPELS);
      //palClearLine(LED_OK); // 0 = led on

      // забираю данные
      adcint.x_raw = adc_buff[0][0];
      adcint.y_raw = adc_buff[0][1];
      adcint.volt5_raw = adc_buff[0][2];
      adcint.voltref_raw = adc_buff[0][3];
      adcint.temp_raw = adc_buff[0][4];

      work_temperature(&adcint);
      work_usb_voltage(&adcint);
      work_3v3_voltage(&adcint);
      work_joystik(&adcint);

      display_print_adc(&adcint);

      adcint.is_adc_sampl = TRUE;
      adcint.cnt++;
 //   }
    chThdSleepMilliseconds(1);
  }
}

void ADCinternal_star_thread(void) {
  chThdCreateStatic(adcThread1, sizeof(adcThread1), NORMALPRIO + 1, funADCThread1, NULL);
}

void ADCinternal_init(void){
  palSetLineMode(VADC1, PAL_MODE_INPUT_ANALOG);
  palSetLineMode(VADC2, PAL_MODE_INPUT_ANALOG);
  palSetLineMode(VADC3, PAL_MODE_INPUT_ANALOG);
}

