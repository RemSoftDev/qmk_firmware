
#include "joystick.h"
#include "config.h"

// !!!! Должна быть калибровка центра и крайних положений
void work_joystik(adcint_t *adc){
  uint32_t xx = adc->y_raw;
  uint32_t yy = adc->x_raw;
  uint16_t adc_centr = ADC_MAX_VL/2;
  uint16_t adc_blind_zone = ADC_MAX_VL*JOYSTIK_BLIND/100; // ЗОНА нечуствительности в центре

  static uint16_t xx_timer;
  static uint16_t yy_timer;

  if ( xx > (adc_centr+adc_blind_zone) ){
      if (timer_elapsed(xx_timer) > (ADC_MAX_VL-xx)/4 ) {
        tap_code(KC_DOWN);
        xx_timer = timer_read();
      }
  }
  if ( xx < (adc_centr-adc_blind_zone) ){
      if (timer_elapsed(xx_timer) > xx/4) {
        tap_code(KC_UP);
        xx_timer = timer_read();
      }
  }

  if(yy > (adc_centr+adc_blind_zone) ){
      if (timer_elapsed(yy_timer) > (ADC_MAX_VL-yy)/4) {
        tap_code(KC_RIGHT);
        yy_timer = timer_read();
      }
  }
  if(yy < (adc_centr-adc_blind_zone) ){
      if (timer_elapsed(yy_timer) > yy/4) {
        tap_code(KC_LEFT);
        yy_timer = timer_read();
      }
  }

}

