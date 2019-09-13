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
enum layer_number {
    _QWERTY = 0,
    _FN,
};

enum custom_keycodes {
  HWTEST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
HWTEST, \
\
	KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                                        \
	KC_P1,   KC_PAST,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,  KC_INS,  \
	KC_P2,   KC_PSLS,  KC_P9,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PSCR,  KC_NLCK, \
	KC_P3,   KC_APP,   KC_P8,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_UP,    KC_PPLS, \
	KC_P4,   KC_LCTL,  KC_P7,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PENT,  KC_END,  \
	KC_LCTL, KC_LALT,  KC_P6,   KC_P5,   KC_SPC,  KC_ESC,  KC_TAB,  KC_CAPS,           KC_PDOT, \
\
								   								 KC_F7,    KC_F8,   KC_F9,    KC_F10,    KC_F11,   KC_F12,  \
							KC_HOME, KC_SLCK,  KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_MINS,   KC_EQL,   KC_NUBS,  \
							KC_PGUP, KC_BRK,   KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,   KC_RBRC,  KC_F13, \
							KC_P3,   KC_PMNS,   KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_PCMM,   KC_NUHS,  KC_F14, \
							KC_P4,   KC_PPLS,  KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_BSLS,  KC_DEL,    KC_SLSH,  KC_F15,  \
							KC_DOWN,           KC_LALT, KC_LEFT, KC_UP,    KC_RGHT, KC_COMM,  KC_PGUP,   KC_RALT,  MO(_FN)
		),
	[_FN] = LAYOUT(
			KC_TRNS, \
			KC_TRNS,   KC_TRNS,   KC_F3,    KC_F4,   KC_F5,   KC_F6,                                                                               KC_2,    KC_3,    KC_4,    KC_5,    KC_PGDN,   KC_PGUP, \
			KC_TRNS,   KC_TRNS,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGDN,  KC_PGUP, KC_E,     KC_ESC,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGDN,   KC_PGUP, \
			KC_TRNS,   KC_TRNS,   KC_RBRC,  KC_W,    KC_E,    KC_R,    KC_T,    KC_B,    KC_RWIN,  KC_SLCK, KC_P,     KC_EQL,   KC_SLSH,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_HOME,   KC_END,\
			KC_TRNS,   KC_TRNS,   KC_LBRC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PDOT,  KC_BSLS, KC_P,     KC_NLCK,  KC_MINS,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_PSCR,   KC_INS,\
			KC_TRNS,   KC_TRNS,   KC_APP,   KC_Q,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_RCTL, KC_NLCK,  KC_F11,   KC_QUOT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_PAUS,   KC_PAST,\
			KC_TRNS,   KC_TRNS,   _______,  KC_P8,   KC_LEFT, KC_UP,   KC_RGHT, KC_DOWN,            KC_ENT, KC_CAPS,            KC_P9,    KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_RCTL,   KC_PMNS
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

bool is_hwtest;


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
    rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
	rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE); // sets mode to Fast breathing without saving
	rgblight_enable_noeeprom(); // enables Rgb, without saving settings
}


// для проверки rgb матрицы
// каждый  вызов зажигает следующий светодиод
/*
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
*/
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
    case _FN:
      oled_write_ln_P(PSTR("Function"), false);
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
 }
 
void rgb_matrix_indicators_user(void){

	static bool is_rgb_hwtest;

	if (is_rgb_hwtest != is_hwtest) {
		is_rgb_hwtest = is_hwtest;
    	//rgb_chek_matrix();
    }
}


// сюда попадаем по событию нажата или отжата клавиша
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HWTEST: //
      if (record->event.pressed) {
    	  is_hwtest = !is_hwtest;
      } else { // when keycode is released
    	;
      }
      break;
  }
  return true;
};
