/**
 * v1.c
 */

#include "v1.h"

#include "ch.h"
#include "hal.h"

#include "led.h"
#include "display.h"
#include "adc_internal.h"
#include "connection.h"
#include "ws2812_pwm.h"

void matrix_scan_kb(void) { matrix_scan_user(); }

void encoder_update_user(uint8_t index, bool clockwise);

void encoder_update_kb(uint8_t index, bool clockwise) {
  encoder_update_user(index, clockwise);
}

void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__((weak))
void matrix_init_user(void) {

  motor_init_port();

//  conn_init_ports(); conn_sw_side(); //

  connection_star_thread();

  led_star_thread();

  ADCinternal_star_thread();

  display_star_thread();

  ws2812_init();
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode
  rgblight_setrgb(14,14,14);
}

__attribute__((weak))
void matrix_scan_user(void) {
  static uint16_t tik = 0;
  uint16_t takt = 1000;
  static bool is_t = false;
  uint8_t led_kbrd_old = 0;
  //led_ok_blink(333);
  //ws2812_test_main(40);

  uint8_t led_kbrd = host_keyboard_leds();
  if (led_kbrd_old != led_kbrd) {
    led_kbrd_old = led_kbrd;
    rgblight_set();
    // TODO print oled
  }

  if(timer_elapsed(tik) > takt) {
    tik = timer_read();
    is_t = !is_t;
    if (is_t) {
     // led_ok_off();
    }
    else {
	 // led_ok_on();
    }
  }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
        case MOTOR1:
        palToggleLine(MOT1);
        return false;
        case MOTOR2:
        palToggleLine(MOT2);
        return false;
        case MOTOR3:
        palToggleLine(MOT3);
        return false;
        default:
        break;
    }
  }
  return true;
}

// https://docs.qmk.fm/#/feature_encoders
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}

void motor_init_port (void){
  palSetLineMode(MOT1, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT1);
  palSetLineMode(MOT2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT2);
  palSetLineMode(MOT3, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT3);
}
