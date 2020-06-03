/**
 * keymap.c
 */

/* прошивка, есть 2 слоя, есть комбинация клавиш ctrl+alt+delete, win+space, есть макрос,
* есть штука которая при длительном нажатии на клавишу отправляет другое значение.
*/

#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1

enum custom_keycodes {	// перечисление макросов
  QMKBEST = NEW_SAFE_RANGE,
  QMKURL,
  ALT_TAB,
  MY_OTHER_MACRO,
  THING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
// https://beta.docs.qmk.fm/features/keycodes_basic
 #ifdef LEFT_CLAW
		   KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,    KC_F6,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   \
		   KC_KP_1,   KC_ESC,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_KP_PLUS,   KC_KP_ASTERISK, \
		   KC_KP_2,   LCTL(KC_S),   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,  KC_BSLS, \
		   LALT(KC_TAB),   LCTL(KC_V),   KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PAUSE,   KC_DELETE, \
		   MEH(KC_QUOT),   LCTL(KC_C),  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC, KC_BSPACE, \
		   MO(_FN1),   KC_APP,  KC_LCTRL,   KC_LALT,   KC_LALT, KC_UP,   KC_RSFT, KC_END, KC_NO,    KC_NO \
		),
	[_FN1] = LAYOUT(
		   RESET, RGB_TOG, RGB_MOD,     RGB_MODE_PLAIN,    RGB_MODE_RGBTEST,    RGB_VAI,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   \
		   MOTOR1,   THING,   KC_MINS,   KC_0,    KC_9,    KC_8,    KC_7,    KC_6,   KC_PAUSE,  KC_SLCK,   \
		   MOTOR2,   MY_OTHER_MACRO,   KC_LBRC,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_ENT,  KC_PSCR, \
		   MOTOR3,   ALT_TAB,   KC_QUOT,  KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,    KC_DELETE,   KC_SPC, \
		   RGB_MODE_RGBTEST,   QMKURL,  KC_RSFT,   KC_SLSH,    KC_DOT,    KC_COMM,    KC_M,    KC_N,    KC_MS_RIGHT,    KC_MS_LEFT, \
		   MO(_FN1),   QMKBEST,  KC_HOME,   KC_PAUSE,    KC_RIGHT, KC_UP,   KC_LEFT, KC_DOWN, KC_NO,    KC_NO \
	),
#else // right CLAW
		   KC_F12,    KC_F11,     KC_F10,     KC_F9,    KC_F8,    KC_F7,    KC_KP_0,   KC_NO,   KC_NO,    KC_NO,   \
		   KC_BSPACE,   KC_EQL,   KC_MINS,   KC_0,    KC_9,    KC_8,    KC_7,    KC_6,   KC_PGUP,  KC_PGDN,   \
		   KC_DELETE,   KC_RBRC,   KC_LBRC,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_ENT,  RSFT(KC_QUOTE), \
		   KC_PAUSE,   KC_ENT,   KC_QUOT,  KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,    KC_DELETE,   KC_RWIN, \
		   KC_PSCR,   KC_VOLU,  KC_RSFT,   KC_SLSH,    KC_DOT,    KC_COMM,    KC_M,    KC_N,    KC_SPC,    KC_RSFT, \
		   MO(_FN1),   KC_VOLD,  KC_HOME,   KC_END,    KC_RIGHT, KC_UP,   KC_LEFT, KC_DOWN, KC_KP_9,    RESET \
		),
	[_FN1] = LAYOUT(
		   RESET, RGB_TOG, RGB_MOD,     RGB_MODE_PLAIN,    RGB_MODE_RGBTEST,    RGB_VAI,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   \
		   MOTOR1,   KC_ESC,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_PGUP,   KC_PGDN, \
		   MOTOR2,   KC_PDOT,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,  KC_DEL, \
		   MOTOR3,   KC_MS_WH_UP,   KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DELETE,   KC_BSLS, \
		   RGB_MODE_RGBTEST,   KC_MS_WH_DOWN,  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MS_BTN1, KC_MS_BTN2, \
		   MO(_FN1),   KC_LCTRL,  KC_LCTRL,   KC_LALT,   KC_LALT, KC_UP,   KC_SPC, KC_DOWN, KC_KP_9,    KC_KP_8 \
	),
#endif
};

bool is_alt_tab_active = false;    //# ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        //# we will be using them soon.

bool is_thing_pres = false;    // флаг штуки
uint16_t thing_timer = 0;        // таймер "штуки"

// сюда попадаем по событию нажата или отжата клавиша
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST: // макрос стринг
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
	  case QMKURL: // макрос стринг с кнопкой ENTER в конце стринга
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case MY_OTHER_MACRO: // макрос ctrl+a потом ctrl+c
      if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("ac")); // selects all and copies
      }
      break;
	  case ALT_TAB: // МЕГАудобно Super ALT↯TAB макрос из https://beta.docs.qmk.fm/features/feature_macros
      if (record->event.pressed) { // кнопка физически нажата
        if (!is_alt_tab_active) {	// если событие еще незарегистрировано
          is_alt_tab_active = true;
          register_code(KC_LALT); //  регистрируется событие "кнопка нажата и удерживается"
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else { // кнопка физически отжата
        unregister_code(KC_TAB);
      }
      break;

	  case THING: // штука
      if (record->event.pressed) { // кнопка физически нажата
          is_thing_pres = true;
          register_code(KC_1); //  регистрируется событие "кнопка нажата и удерживается"
		  thing_timer = timer_read();
      } else { // кнопка физически отжата
        unregister_code(KC_1);
		is_thing_pres = false;
      }
      break;

  }
  return true;
};

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

  // для штуки
  if (is_thing_pres) {	// если удерживается нажатым
	if (timer_elapsed(thing_timer) > 1000) { // удержано более 1000ms
		tap_code(KC_2); // тапаю кнопкой - показательно переодичность одна две милисекунды!
	}
  }
}
