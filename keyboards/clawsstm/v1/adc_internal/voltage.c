
#include "voltage.h"
#include "config.h"

void work_usb_voltage(adcint_t *adc){

  float volt;

  volt = adc->volt5_raw;
  volt *= ADC_REF_MV;
  volt /= ADC_MAX_VL;
  // Uout = Uin *(Rniz/(Rniz+Rverh))
  volt *= ((float)R_DEL_DW+(float)R_DEL_UP)/(float)R_DEL_DW;
  //volt /= 1000.0; // mV to V
  adc->voltage_usb = volt;
}


void work_3v3_voltage(adcint_t *adc){

  adc->voltage_3v3 = (float)ADC_REF_MV*(float)ADC_1V2_MV/(float) adc->voltref_raw;
}


