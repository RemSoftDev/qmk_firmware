#include QMK_KEYBOARD_H
#include <stdint.h>
#include <stdbool.h>

#define _BASE 0
#define _FN_NUM 1
#define _FN_EML 2
#define _FN_PSWD 3
#define _FN_DEV 4
#define _FN_CSGO 5
#define _FN_F 6

//Tap Dance Declarations
enum {
  TD_PSCREEN_CAD,
  TD_PAUSE_WINL,
  TD_WIN_SHIFT,
  TD_KC1_F1
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PSCREEN_CAD] = ACTION_TAP_DANCE_DOUBLE(KC_PSCREEN, LCTL(LALT(KC_DEL))),
    [TD_PAUSE_WINL]  = ACTION_TAP_DANCE_DOUBLE(KC_PAUSE, LWIN(KC_L)),
    [TD_WIN_SHIFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LWIN, MT(MOD_LSFT, KC_A)),
    [TD_KC1_F1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1)
};

enum custom_keycodes {
  EML_1 = SAFE_RANGE,
  EML_2,
  EML_3,
  EML_4,
  PSWD_1,
  PSWD_2,
  PSWD_3,
  PSWD_4,
  CAD__PS };

bool     long_press_was     = false;
bool     long_press_is      = false;
uint16_t long_press_value   = KC_NO;
uint16_t single_press_value = KC_NO;
const char *dd= "aaaa";
uint16_t long_press_timer   = 0;

void long_press(keyrecord_t *record, uint16_t single_press_val, char *long_press_val) {
  if (record->event.pressed) {
    single_press_value = single_press_val;
    dd   = long_press_val;

    long_press_is    = true;
    long_press_timer = timer_read();
  } else {
    long_press_is = false;
    if (long_press_was == false) {
      tap_code(single_press_value);
    }

    long_press_was     = false;
    long_press_timer   = 0;
    long_press_value   = KC_NO;
    single_press_value = KC_NO;
  }
}

char *dds= "aaaa";
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EML_1:
      if (record->event.pressed) {SEND_STRING("oleksandr.dubyna@accenture.com");} break;
    case EML_2:
      if (record->event.pressed) {SEND_STRING("oleksandr.dubyna@avanade.com");} break;
    case EML_3:
      if (record->event.pressed) {SEND_STRING("struggleendlessly@hotmail.com");} break;
    case EML_4:
      if (record->event.pressed) {SEND_STRING("se8se@hotmail.com");} break;

    case PSWD_1:
      if (record->event.pressed) {SEND_STRING("1qaz!QAZ");} break;
    case PSWD_2:
      if (record->event.pressed) {SEND_STRING("2wsx@WSX");} break;
    case PSWD_3:
      if (record->event.pressed) {SEND_STRING("4rfv0p;/)P:?");} break;
    case PSWD_4:
      if (record->event.pressed) {SEND_STRING("1976319");} break;

    case CAD__PS:
      long_press(record,  KC_1, SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))));
      break;
  }

  return true;
};

void matrix_scan_user(void) {
  if (long_press_is) {
    if (timer_elapsed(long_press_timer) > 300) {

      long_press_is  = false;
      long_press_was = true;
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
/*		 	0				1	    	2			3		4		 5		6		7			8			9		*/
/* 0 */	 TO(_FN_F),     KC_NO,       KC_GRAVE,     KC_1,    KC_2,    KC_3,  KC_4,     KC_5,    KC_PGUP,   KC_PGDOWN, \
/* 1 */	 TO(_FN_CSGO),  TG(_FN_NUM), KC_RBRACKET,  KC_W,    KC_E,    KC_R,  KC_T,     KC_B,    KC_ENTER,  TD(TD_PSCREEN_CAD), \
/* 2 */	 TO(_FN_EML),   KC_LCTRL,    KC_LBRACKET,  KC_A,    KC_S,    KC_D,  KC_F,     KC_G,    KC_SPACE,  TD(TD_WIN_SHIFT), \
/* 3 */	 TO(_FN_PSWD),  KC_LALT,     KC_LSHIFT,    KC_Q,    KC_Z,    KC_X,  KC_C,     KC_V,    KC_NO,     KC_ESCAPE, \
/* 4 */	 TO(_FN_DEV),   KC_TAB,      KC_F2,        KC_F5,   KC_LEFT, KC_UP, KC_RIGHT, KC_DOWN, KC_NO,     KC_BSPACE, \
/*		    0						1			2			3		4			 5		  6	    	7			8		9		*/
/* 5 */	 KC_AUDIO_VOL_UP,  	  KC_EQUAL,    KC_BSLASH,  KC_0,    KC_9,      KC_8,    KC_7,     KC_6,     KC_HOME,   KC_END, \
/* 6 */	 KC_AUDIO_VOL_DOWN,   TG(_FN_NUM), KC_MINS,    KC_P,    KC_O,      KC_I,    KC_U,     KC_Y,     KC_ENTER,  TD(TD_PAUSE_WINL), \
/* 7 */	 KC_MEDIA_NEXT_TRACK, KC_RCTRL,    KC_QUOT,    KC_SCLN, KC_L,      KC_K,    KC_J,     KC_H,     KC_SPACE,  KC_RWIN, \
/* 8 */	 KC_MEDIA_PREV_TRACK, KC_ENTER,    KC_RSHIFT,  KC_SLSH, KC_DOT,    KC_COMM, KC_M,     KC_N,     KC_NO,     KC_ESCAPE, \
/* 9 */	 KC_MEDIA_PLAY_PAUSE, KC_DELETE,   KC_F2,      KC_F5,   KC_RIGHT,  KC_UP,   KC_LEFT,  KC_DOWN,  KC_NO,     KC_BSPACE \
	),
	[_FN_NUM] = LAYOUT(
/*		 0		1	    	2			3			4		 5			6		7			8			9		*/
/* 0 */	 KC_TRNS, KC_NUMLOCK, KC_NO,     KC_NO,       KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_TRNS, KC_TRNS, \
/* 1 */	 KC_TRNS, TG(_FN_NUM),KC_PSLS,   KC_KP_MINUS, KC_KP_9,  KC_KP_8, KC_KP_7,  KC_NO,   KC_TRNS, KC_TRNS, \
/* 2 */	 KC_TRNS, KC_TRNS,    KC_PAST,   KC_KP_PLUS,  KC_KP_6,  KC_KP_5, KC_KP_4,  KC_NO,   KC_TRNS, KC_TRNS, \
/* 3 */	 KC_TRNS, KC_TRNS,    KC_LSHIFT, KC_KP_DOT,   KC_KP_3,  KC_KP_2, KC_KP_1,  KC_KP_0, KC_NO,   KC_TRNS, \
/* 4 */	 KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_NO,   KC_TRNS, \
/*		 0						1			2			3		    4		5		  6	    	7		8		9		*/
/* 5 */	 KC_TRNS, KC_NUMLOCK, KC_NO,     KC_NO,       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, \
/* 6 */	 KC_TRNS, TG(_FN_NUM),KC_PSLS,   KC_KP_MINUS, KC_KP_9,  KC_KP_8, KC_KP_7, KC_NO,   KC_TRNS, KC_TRNS, \
/* 7 */	 KC_TRNS, KC_TRNS,    KC_PAST,   KC_KP_PLUS,  KC_KP_6,  KC_KP_5, KC_KP_4, KC_NO,   KC_TRNS, KC_TRNS, \
/* 8 */	 KC_TRNS, KC_TRNS,    KC_RSHIFT, KC_KP_DOT,   KC_KP_3,  KC_KP_2, KC_KP_1, KC_KP_0, KC_NO,   KC_TRNS, \
/* 9 */	 KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS  \
	),
	[_FN_EML] = LAYOUT(
/*		 	0				1	   	2		3			4		 5			6			7		8		9		*/
/* 0 */	 KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 1 */	 KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 2 */	 TO(_BASE), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 3 */	 KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 4 */	 KC_TRNS,   KC_TRNS,  EML_1,    EML_2,    EML_3,    EML_4,    KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/*		 	0		1			2		3			4		 5		  6	    	7			8		9		*/
/* 5 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 6 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 7 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 8 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 9 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS  \
	),
	[_FN_PSWD] = LAYOUT(
/*		 	0				1	   	2		3			4		 5			6			7		8		9		*/
/* 0 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 1 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 2 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 3 */	 TO(_BASE),KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 4 */	 KC_TRNS,  KC_TRNS,  PSWD_1,   PSWD_2,   PSWD_3,   PSWD_4,   KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/*		 	0		1			2		3			4		 5		  6	    	7			8		9		*/
/* 5 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 6 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 7 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 8 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 9 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS  \
	),
	[_FN_DEV] = LAYOUT(
/*		 	0		1	  	 	2		3			4		 5		 6			7		   8		9		*/
/* 0 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 1 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 2 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 3 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 4 */	 TO(_BASE),KC_TRNS,  KC_F2,    KC_F5,    KC_F12,   KC_F9,    KC_F10,   KC_F11,   KC_NO,    KC_TRNS, \
/*		 	0		1			2		3			4		 5		  6	    	7			8		9		*/
/* 5 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 6 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 7 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 8 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS, \
/* 9 */	 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS  \
	),
	[_FN_CSGO] = LAYOUT(
/*		 	0		1	  	 	2		3			4		 5		 6			7		   8		9		*/
/* 0 */	 KC_NO,    KC_NO,  KC_NO,  KC_NO,     KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO, \
/* 1 */	 TO(_BASE),KC_NO,  KC_NO,  KC_1,      KC_2,   KC_3,  KC_4,  KC_B,   KC_ENTER, KC_NO, \
/* 2 */	 KC_F3,    KC_NO,  KC_NO,  KC_LSHIFT, KC_A,   KC_W,  KC_D,  KC_G,   KC_SPACE, KC_RWIN, \
/* 3 */	 KC_NO,    KC_NO,  KC_NO,  KC_LCTRL,  KC_Q,   KC_S,  KC_R,  KC_E,   KC_NO,    KC_ESCAPE, \
/* 4 */	 KC_NO,    KC_TAB, KC_NO,  KC_NO,     KC_NO,  KC_NO, KC_K,  KC_NO,  KC_NO,    KC_NO, \
/*		 	0		1			2		3			4		 5		  6	    	7			8		9		*/
/* 5 */	 KC_AUDIO_VOL_UP,  	  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
/* 6 */	 KC_AUDIO_VOL_DOWN,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
/* 7 */	 KC_MEDIA_NEXT_TRACK, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
/* 8 */	 KC_MEDIA_PREV_TRACK, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, \
/* 9 */	 KC_MEDIA_PLAY_PAUSE, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  \
	),
	[_FN_F] = LAYOUT(
/*		 0	    	1	    	2			3			4		 5			6		7			8			9		*/
/* 0 */	 TO(_BASE), KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, \
/* 1 */	 KC_TRNS,   KC_TRNS,    KC_NO,     KC_F12,  KC_F11,  KC_F10,  KC_F9,    KC_NO,   KC_TRNS, KC_TRNS, \
/* 2 */	 KC_TRNS,   KC_TRNS,    KC_NO  ,   KC_F8,   KC_F7,   KC_F6,   KC_F5,    KC_NO,   KC_TRNS, KC_TRNS, \
/* 3 */	 KC_TRNS,   KC_TRNS,    KC_LSHIFT, KC_F4,   KC_F3,   KC_F2,   KC_F1,    KC_NO,   KC_NO,   KC_TRNS, \
/* 4 */	 KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_NO,   KC_TRNS, \
/*		 0						1			2			3		    4		5		  6	    	7		8		9		*/
/* 5 */	 KC_TRNS, KC_TRNS,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, \
/* 6 */	 KC_TRNS, KC_TRNS,    KC_PSLS,   KC_F12,   KC_F11,   KC_F10,  KC_F9,   KC_NO,   KC_TRNS, KC_TRNS, \
/* 7 */	 KC_TRNS, KC_TRNS,    KC_PAST,   KC_F8,    KC_F7,    KC_F6,   KC_F5,   KC_NO,   KC_TRNS, KC_TRNS, \
/* 8 */	 KC_TRNS, KC_TRNS,    KC_RSHIFT, KC_F4,    KC_F3,    KC_F2,   KC_F1,   KC_KP_0, KC_NO,   KC_TRNS, \
/* 9 */	 KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS  \
	),
};
