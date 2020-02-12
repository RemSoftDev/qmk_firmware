/**
 * claws.c
 */

#include "left.h"
#include "rgblight.h"

void matrix_scan_kb(void) { matrix_scan_user(); }

void matrix_init_kb(void) {
  matrix_init_user();
}
__attribute__((weak))
void matrix_init_user(void) {

    //palSetPadMode(GPIOC, 13, PAL_MODE_OUTPUT_PUSHPULL); // LED
    palSetPadMode(GPIOB, 02, PAL_MODE_OUTPUT_PUSHPULL); // EXT1
    
    palSetLineMode(N_OE_PORT, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(N_OE_PORT);

    palSetLineMode(SEL_INTERF, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(SEL_INTERF);

    palSetLineMode(SEL_PORT, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(SEL_PORT);

    palSetLineMode(MOT1, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT1);
    palSetLineMode(MOT2, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT2);
    palSetLineMode(MOT3, PAL_MODE_OUTPUT_PUSHPULL);
    palClearLine(MOT3);
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
