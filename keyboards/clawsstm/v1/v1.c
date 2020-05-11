/**
 * v1.c
 */

#include "v1.h"
#include "rgblight.h"
#include "led_ok.h"

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

    //palSetPadMode(GPIOC, 13, PAL_MODE_OUTPUT_PUSHPULL); // LED
    palSetLineMode(MON_TX, PAL_MODE_RESET);
    palSetLineMode(MON_RX, PAL_MODE_RESET);
    palSetLineMode(TX1, PAL_MODE_RESET);
    palSetLineMode(RX1, PAL_MODE_RESET);
    palSetLineMode(TX6, PAL_MODE_RESET);
    palSetLineMode(RX6, PAL_MODE_RESET);
 //   palSetLineMode(N_OE_PORT, PAL_MODE_OUTPUT_PUSHPULL);
 //   palClearLine(N_OE_PORT);

 //   palSetLineMode(SEL_INTERF, PAL_MODE_OUTPUT_PUSHPULL);
 //   palClearLine(SEL_INTERF);

 //   palSetLineMode(SEL_PORT, PAL_MODE_OUTPUT_PUSHPULL);
 //   palClearLine(SEL_PORT);

    palSetLineMode(MOT1, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT1);
    palSetLineMode(MOT2, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT2);
    palSetLineMode(MOT3, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT3);

    led_ok_init_ports();
    led_ok_on();

    palSetLineMode(STROB_PORT, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(STROB_PORT);

    palSetLineMode(SEL_PORT, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(SEL_PORT); // БОКОВОЙ
    //palSetLine(SEL_PORT); // ВЕРХНИЙ
    led_ok_on();led_ok_on();led_ok_off();led_ok_on();
    palSetLine(STROB_PORT);
    led_ok_on();led_ok_on();led_ok_off();led_ok_on();
    palClearLine(STROB_PORT);

  palSetLineMode(OLED_ON, PAL_MODE_OUTPUT_PUSHPULL);
  //palClearLine(OLED_ON); // выкл 14В
  palSetLine(OLED_ON); // вкл 14В

  palSetLineMode(OLED_N_RESET, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(OLED_N_RESET);

  palSetLineMode(OLED_N_CS, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(OLED_N_CS);

  palSetLineMode(OLED_DC, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(OLED_DC);

  palSetLineMode(OLED_CLK, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(OLED_CLK);

  palSetLineMode(OLED_DIN, PAL_MODE_OUTPUT_PUSHPULL);
  palClearLine(OLED_DIN);

}

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(128, 128, 128); // sets the color without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
  wait_ms(5);// command first attempt fails
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}




__attribute__((weak))
void matrix_scan_user(void) {
  static uint16_t tik = 0;
  uint16_t takt = 1000;
  static bool is_t = false;
  //led_ok_blink(333);

  if(timer_elapsed(tik) > takt) {
    tik = timer_read();
    is_t = !is_t;
    if (is_t) {
      led_ok_off();
    }
    else {
	  led_ok_on();
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

