#include"thermometer_int.h"
#include "config.h"

//volatile float temperature_int;

void work_temperature(adcint_t *adc){
  float temp;
  temp = adc->temp_raw;
  temp *= ADC_REF_MV;
  temp /= ADC_MAX_VL;
  temp /= 1000.0; //Reading in Volts
  temp -= 0.760; // Subtract the reference voltage at 25°C
  temp /= .0025; // Divide by slope 2.5mV
  temp += 25.0; // Add the 25°C

  adc->temp_core = temp;
}

