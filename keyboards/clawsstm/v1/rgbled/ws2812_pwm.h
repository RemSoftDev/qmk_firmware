#pragma once

#include "quantum.h"

void ws2812_init(void);

void ws2812_test_blok(void);
void ws2812_test_main(uint16_t sped);

void ws2812_setleds(LED_TYPE *ledarray, uint16_t number_of_leds);

void rgbled_layer(layer_state_t state);
