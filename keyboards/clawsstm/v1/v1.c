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
#include "atecc608a.h"

void matrix_scan_kb(void) {

  // при статическом режиме подсветке нужно обновить светодиоды
  static uint8_t led_kbrd_old = 0;
  uint8_t led_kbrd = host_keyboard_leds();
  if (led_kbrd_old != led_kbrd) {
    led_kbrd_old = led_kbrd;
    rgblight_set();
  }
    matrix_scan_user();
}

__attribute__((weak))
void encoder_update_user(uint8_t index, bool clockwise){;}

void encoder_update_kb(uint8_t index, bool clockwise) {
  encoder_update_user(index, clockwise);
}

void matrix_init_kb(void) {

  motor_init_port();
  led_init_ports();

  conn_init_ports();

#ifdef TYPE_C_UP
  conn_sw_up();
#else
  conn_sw_side(); //
#endif
 // connection_star_thread();

  led_star_thread();

  ADCinternal_star_thread();

  display_star_thread();

//  security_star_thread();

  ws2812_init();
  matrix_init_user();
}

__attribute__((weak))
void matrix_init_user(void) {
;
}

__attribute__((weak))
void matrix_scan_user(void) {
;
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
        case DISPLAY_TEST:
         display_run_demo(2);// количество цыклов
        return false;
        default:
        break;
    }
  }
  return process_record_user(keycode, record);
}


void motor_init_port (void){
  palSetLineMode(MOT1, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT1);
  palSetLineMode(MOT2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT2);
  palSetLineMode(MOT3, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(MOT3);
}
