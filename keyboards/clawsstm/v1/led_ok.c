
#include <stdint.h>
#include <stdbool.h>

#include "led_ok.h"
#include "wait.h"

// настройка порта управления светодиодом LD57
void led_ok_init_ports(void) {
  palSetLineMode(LED_OK, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(LED_OK);
}

void led_ok_on(void) {
	palClearLine(LED_OK); // 0 = led on
}

void led_ok_off(void) {
	palSetLine(LED_OK); // 1 = led off
}


// мигает светикоом с заданsv тактом (в милисекундах)
void led_ok_blink(uint16_t takt_ms) {
	static uint16_t d1_timer = 0;
	static bool is_d1 = false;

    if (timer_elapsed(d1_timer) > takt_ms) {
		d1_timer = timer_read();
		if (is_d1) {
			is_d1 = false;
			led_ok_off();
		}
		else {
			is_d1 = true;
			led_ok_on();
		}
    }
}
