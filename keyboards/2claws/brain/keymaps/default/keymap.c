/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include <stdint.h>
#include <stdbool.h>

#include "motor.h"
#include "debug.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
  TD_SHIFT_CAPS,
  TD_ALT_ENTER,
  TD_F2_PLUS_ENTER
};

void F2_PLUS_ENTER(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_F2);
  } else {
    SEND_STRING("+"SS_TAP(X_ENTER));
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PSCREEN_CAD]   = ACTION_TAP_DANCE_DOUBLE(KC_PSCREEN, LCTL(LALT(KC_DEL))),
    [TD_PAUSE_WINL]    = ACTION_TAP_DANCE_DOUBLE(KC_PAUSE, LWIN(KC_L)),
    [TD_SHIFT_CAPS]    = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_CAPSLOCK),
    [TD_ALT_ENTER]     = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ENTER),
    [TD_F2_PLUS_ENTER] = ACTION_TAP_DANCE_FN (F2_PLUS_ENTER)
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
  HWTEST,
  CAD__PS };

bool     long_press_was     = false;
bool     long_press_is      = false;
uint16_t long_press_value   = KC_NO;
uint16_t single_press_value = KC_NO;
uint16_t long_press_timer   = 0;

void long_press(keyrecord_t *record, uint16_t single_press_val, char long_press_val) {
  if (record->event.pressed) {
    single_press_value = single_press_val;
    long_press_value   = long_press_val;

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
// сюда попадаем по событию нажата или отжата клавиша
bool is_hwtest;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EML_1:
      if (record->event.pressed) {SEND_STRING("struggleendlessly@hotmail.com");} break;
    case EML_2:
      if (record->event.pressed) {SEND_STRING("se8se@hotmail.com");} break;
    case EML_3:
      if (record->event.pressed) {SEND_STRING("oleksand.dubyna");} break;
    case EML_4:
      if (record->event.pressed) {SEND_STRING("321");} break;

    case PSWD_1:
      if (record->event.pressed) {SEND_STRING("1qaz!QAZ");} break;
    case PSWD_2:
      if (record->event.pressed) {SEND_STRING("2wsx@WSX");} break;
    case PSWD_3:
      if (record->event.pressed) {SEND_STRING("");} break;
    case PSWD_4:
      if (record->event.pressed) {SEND_STRING("1976319");} break;
	case HWTEST: if (record->event.pressed) {is_hwtest = !is_hwtest;}break;
/* SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))) */
    case CAD__PS:
      long_press(record,  KC_1, KC_1);
      break;
  }

  return true;
};

enum layer_number {
    _QWERTY = 0,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
/* brain key */	 HWTEST, \
/*		 	0				1	    	    2			        3		   4		 5		6		    7			8			9		*/
/* f */	 KC_F1,         KC_F2,            KC_F3,                KC_F4,   KC_F5,   KC_F6,
/* 0 */	 TO(_FN_F),     KC_W,            KC_GRAVE,             KC_1,    KC_2,    KC_3,    KC_4,      KC_5,     KC_PGUP,   KC_PGDOWN, \
/* 1 */	 TO(_FN_CSGO),  TG(_FN_NUM),      KC_RBRACKET,          KC_W,    KC_E,    KC_R,    KC_T,      KC_B,     KC_ENTER,  TD(TD_PSCREEN_CAD), \
/* 2 */	 TO(_FN_EML),   KC_LCTRL,         KC_LBRACKET,          KC_A,    KC_S,    KC_D,    KC_F,      KC_G,     KC_LWIN,   KC_ESCAPE, \
/* 3 */	 TO(_FN_PSWD),  TD(TD_ALT_ENTER), TD(TD_SHIFT_CAPS),    KC_Q,    KC_Z,    KC_X,    KC_C,      KC_V,     KC_SPACE,  KC_BSPACE, \
/* 4 */	 TO(_FN_DEV),   KC_TAB,           TD(TD_F2_PLUS_ENTER), KC_F5,   KC_LEFT, KC_UP,   KC_RIGHT,  KC_SPACE,            KC_DOWN, \
/*		    0					1			2		3	    	4		 5		  6	    	7			8	        	9		*/
/* f */							   							 KC_F7,   KC_F8,    KC_F9,    KC_F10,     KC_F11,       KC_F12, \
/* 5 */	 KC_HOME,  	          KC_END,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSLASH,  KC_EQUAL,     KC_AUDIO_VOL_UP, \
/* 6 */	 TD(TD_PAUSE_WINL),   KC_ENTER,  KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_MINS,    TG(_FN_NUM),  KC_AUDIO_VOL_DOWN, \
/* 7 */	 KC_ESCAPE,           KC_RWIN,   KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT,    KC_RCTRL,     KC_MEDIA_NEXT_TRACK, \
/* 8 */	 KC_BSPACE,           KC_SPACE,  KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH,  KC_RSHIFT,  KC_ENTER,     KC_MEDIA_PREV_TRACK, \
/* 9 */	 KC_DOWN,                        KC_SPACE, KC_LEFT,  KC_UP,   KC_RIGHT, KC_RALT,  KC_RWIN,    KC_DELETE,    KC_MEDIA_PLAY_PAUSE
		),

	[_FN_NUM] = LAYOUT(
/* brain key */	 HWTEST, \
/*		 	0	    	1	        2		   3		      4		   5	    	6		  7			8			9		*/
/* f */	 KC_TRNS,  KC_TRNS,       KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,
/* 0 */	 KC_TRNS,  KC_NUMLOCK,    KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, \
/* 1 */	 KC_TRNS,  TG(_FN_NUM),   KC_PSLS,   KC_KP_MINUS,  KC_KP_9,  KC_KP_8,   KC_KP_7,   KC_KP_0,  KC_TRNS,  KC_TRNS, \
/* 2 */	 KC_TRNS,  KC_TRNS,       KC_PAST,   KC_KP_PLUS,   KC_KP_6,  KC_KP_5,   KC_KP_4,   KC_KP_0,  KC_TRNS,  KC_TRNS, \
/* 3 */	 KC_TRNS,  KC_TRNS,       KC_TRNS,   KC_KP_DOT,    KC_KP_3,  KC_KP_2,   KC_KP_1,   KC_KP_0,  KC_TRNS,  KC_TRNS, \
/* 4 */	 KC_TRNS,  KC_TRNS,       KC_TRNS,   KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,            KC_TRNS, \
/*		    0			1		2		  3	    	4	       5		  6	          	7			8	        	9		*/
/* f */							   			      KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS, \
/* 5 */	 KC_TRNS,  	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_NUMLOCK,   KC_TRNS, \
/* 6 */	 KC_TRNS,   KC_TRNS,  KC_KP_0,  KC_KP_7,  KC_KP_8,  KC_KP_9,   KC_KP_MINUS,  KC_PSLS,    TG(_FN_NUM),  KC_TRNS, \
/* 7 */	 KC_TRNS,   KC_TRNS,  KC_KP_0,  KC_KP_4,  KC_KP_5,  KC_KP_6,   KC_KP_PLUS,   KC_PAST,    KC_TRNS,      KC_TRNS, \
/* 8 */	 KC_TRNS,   KC_TRNS,  KC_KP_0,  KC_KP_1,  KC_KP_2,  KC_KP_3,   KC_KP_DOT,    KC_TRNS,    KC_TRNS,      KC_TRNS, \
/* 9 */	 KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS
	),
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index https://beta.docs.qmk.fm/features/feature_rgb_matrix
		{ NO_LED },
		{ 64, 63, 62, 61, 60, 59, NO_LED, NO_LED, NO_LED, NO_LED },
		{ 58, 57, 56, 55, 54, 53, 52, 51, 50, 49 },
		{ 48, 47, 46, 45, 44, 43, 42, 41, 40, 39 },
		{ 38, 37, 36, 35, 34, 33, 32, 31, 30, 29 },
		{ 28, 27, 26, 25, 24, 23, 22, 21, 20, 19 },
		{ 18, 17, 16, 15, 14, 13, 12, 11, NO_LED, 10 },
	\
	    { NO_LED, NO_LED, NO_LED, NO_LED, 70, 69, 68, 67, 66, 65 },
	    { 80, 79, 78, 77, 76, 75, 74, 73, 72, 71 },
	    { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81 },
	    { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 },
	    { 110, 109, 108, 107, 106, 105, 104, 103, 102, 101 },
	    { 119, NO_LED, 118, 117, 116, 115, 114, 113, 112, 111 }
}, {
  // LED Index to Physical Position
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 },
  { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, { 0,  0 }, {  0,  0 }, {  0,  0 }
}, {
  // LED Index to Flag
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1
} };


// настройка порта управления светодиодом D1
void D1_init_ports(void) {
	DDRD |= (1<<7); // OUT
	//led on
	PORTD &= ~(1<<7); // 0 = led on
}

void D1_on(void) {
	PORTD &= ~(1<<7); // 0 = led on
}

void D1_off(void) {
	PORTD |=(1<<7);
}


// настройка порта управления EXT_LED
void ext_led_off(void) {
	DDRD |= (1<<6); // OUT
	//led on
	PORTD &= ~(1<<6); // 0 = xt_led_off
}

void ext_led_on(void) {
	DDRD |= (1<<6); // OUT
	//led on
	PORTD |= (1<<6); // 1 = xt_led_on
}

// настройка порта управления SEL
void sel_to_port1(void) {
	DDRD |= (1<<5); // OUT
	//led on
	PORTD &= ~(1<<5); // 0 = на LED1_IN
}

void sel_to_port2(void) {
	DDRD |= (1<<5); // OUT
	//led on
	PORTD |= (1<<5); // 1 = на LED2_IN
}

// мигает светикоом с заданsv тактом (в милисекундах)
void D1_blink(uint16_t takt) {
	static uint16_t d1_timer = 0;
	static bool is_d1 = false;

    if (timer_elapsed(d1_timer) > takt) {
		d1_timer = timer_read();
		if (is_d1) {
			is_d1 = false;
			D1_off();
		}
		else {
			is_d1 = true;
			D1_on();
		}
    }
}


void slave_motor_blink(uint16_t takt) {
	static uint16_t d1_timer = 0;
	static bool is_d1 = false;

    if (timer_elapsed(d1_timer) > takt) {
		d1_timer = timer_read();
		if (is_d1) {
			is_d1 = false;
			//D1_off();
			slave_motor_off(0x30, 1);
		}
		else {
			is_d1 = true;
			//D1_on();
			slave_motor_on(0x30, 1);//slave_motor_off(uint8_t slave_i2c_addr, uint8_t motor_number)
		}
    }
}

// в самом начале инициалицации
void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

    D1_init_ports();
	ext_led_on();
	sel_to_port1();

	slaves_motors_init();
}

// в середине инициализации
void matrix_init_user(void) {

}

// вызввается после того как все встроенные модули проинициализировались
void keyboard_post_init_user(void) {
	debug_enable = true; // нужно для работы dprintf
	debug_keyboard = true;
  // Call the post init code.
    rgblight_sethsv_noeeprom(100, 255, 100); // sets the color to teal/cyan without saving
	rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE); // sets mode to Fast breathing without saving
	rgblight_enable_noeeprom(); // enables Rgb, without saving settings
}


// для проверки rgb матрицы
// каждый  вызов зажигает следующий светодиод
void rgb_chek_matrix(void) {

	static uint8_t state_led = DRIVER_LED_TOTAL;

	if (state_led==DRIVER_LED_TOTAL){
		rgblight_disable_noeeprom();
	}
	else {
		rgb_matrix_set_color_all(0,0,0);
		rgb_matrix_set_color(state_led,100,100,100);
		rgb_matrix_update_pwm_buffers();
	}

	dprintf("state_led =%d\n", state_led);
	state_led++;
	if (state_led>=DRIVER_LED_TOTAL){
		state_led=0;
	}
}

// для проверки удаленны моторов
void slaves_motors_chek(void) {
static uint8_t state = 1;
 switch (state) {
    case 1:
    	slave_motor_on(SLAVE_I2C_ADDRESS, 1);
      break;
	case 2:
		slave_motor_off(SLAVE_I2C_ADDRESS, 1);
		slave_motor_on(SLAVE_I2C_ADDRESS, 2);
      break;
	case 3:
		slave_motor_off(SLAVE_I2C_ADDRESS, 2);
		slave_motor_on(SLAVE_I2C_ADDRESS, 3);
      break;
	case 4:
		slave_motor_off(SLAVE_I2C_ADDRESS, 3);
		slave_motor_on(SLAVE_I2C_ADDRESS, 4);
      break;
	case 5:
		slave_motor_off(SLAVE_I2C_ADDRESS, 4);
		slave_motor_on(SLAVE_I2C_ADDRESS, 5);
      break;
	case 6:
		slave_motor_off(SLAVE_I2C_ADDRESS, 5);
      break;

	case 7:
    	slave_motor_on(SLAVE_I2C_ADDRESS+2, 1);
      break;
	case 8:
		slave_motor_off(SLAVE_I2C_ADDRESS+2, 1);
		slave_motor_on(SLAVE_I2C_ADDRESS+2, 2);
      break;
	case 9:
		slave_motor_off(SLAVE_I2C_ADDRESS+2, 2);
		slave_motor_on(SLAVE_I2C_ADDRESS+2, 3);
      break;
	case 10:
		slave_motor_off(SLAVE_I2C_ADDRESS+2, 3);
		slave_motor_on(SLAVE_I2C_ADDRESS+2, 4);
      break;
	case 11:
		slave_motor_off(SLAVE_I2C_ADDRESS+2, 4);
		slave_motor_on(SLAVE_I2C_ADDRESS+2, 5);
      break;
	case 12:
		slave_motor_off(SLAVE_I2C_ADDRESS+2, 5);
      break;

	default:
		state = 0;
	  break;
 }
 state++;
}

// SSD1306 OLED driver logic
#ifdef OLED_DRIVER_ENABLE

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0},
    {0xb5,0xb6,0},
    {0x97,0x98,0},
    {0xb7,0xb8,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_ln_P(mode_logo[0], false);
    oled_write_ln_P(mode_logo[1], false);
  } else {
    oled_write_ln_P(mode_logo[2], false);
    oled_write_ln_P(mode_logo[3], false);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_ln_P(PSTR("QWERTY"), false);
      break;
    case _FN_NUM:
      oled_write_ln_P(PSTR("_FN_NUM"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_ln_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {

	render_status();
}

#endif

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer.

	static bool is_matrix_hwtest;
	D1_blink(1000); // мигает то прошивка независла

	if (is_matrix_hwtest != is_hwtest) {
		is_matrix_hwtest = is_hwtest;
		slaves_motors_chek();
    }

	  if (long_press_is) {
    if (timer_elapsed(long_press_timer) > 300) {
      char my_str[4] = "ok.";
send_string(my_str);
      long_press_is  = false;
      long_press_was = true;
    }
  }
 }

void rgb_matrix_indicators_user(void){

	static bool is_rgb_hwtest;

	if (is_rgb_hwtest != is_hwtest) {
		is_rgb_hwtest = is_hwtest;
    	rgb_chek_matrix();
    }
}



