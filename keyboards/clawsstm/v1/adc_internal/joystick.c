
#include "joystick.h"
#include "config.h"

// !!!! Должна быть калибровка центра и крайних пол...
void work_joystik(adcint_t *adc){
  uint32_t xx = adc->x_raw;
  uint32_t yy = adc->y_raw;
  uint16_t adc_centr = ADC_MAX_VL/2;
  uint16_t adc_blind_zone = ADC_MAX_VL*JOYSTIK_BLIND/100; // ЗОНА нечуствительности в центре

  if(xx > (adc_centr+adc_blind_zone) || xx < (adc_centr-adc_blind_zone) ){

  }else {
    adc->joystik_dx = 0;
  }

  if(yy > (adc_centr+adc_blind_zone) || yy < (adc_centr-adc_blind_zone) ){

  }else {
    adc->joystik_dy = 0;
  }
}

