#pragma once

#include "quantum.h"

void ADCinternal_star_thread(void);
void ADCinternal_init(void);

typedef struct {
  bool is_adc_sampl;
  uint16_t cnt;
  int32_t x_raw;
  int32_t y_raw;
  int32_t volt5_raw;
  int32_t voltref_raw;
  int32_t temp_raw;

  uint16_t joystik_dx;
  uint16_t joystik_dy;

  float voltage_usb;
  float voltage_3v3;

  float temp_core;
} adcint_t;

