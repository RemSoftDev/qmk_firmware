/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	[_BASE] = LAYOUT(
// LCTL(LALT(KC_DEL)) = комбинация клавиш ctrl+alt+delete = https://beta.docs.qmk.fm/features/feature_advanced_keycodes
// LWIN(KC_SPC) = комбинация клавиш win+space = https://beta.docs.qmk.fm/features/feature_advanced_keycodes
// MO(_FN1) = при удержании этой клавиши работает слой _FN1
		   KC_ESC,    KC_F6,     KC_F7,     KC_F8,    KC_F9,    KC_F10,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   \
		   KC_F1,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,  KC_9, \
		   KC_F2,   KC_DEL,   KC_RBRC,  KC_W,    KC_E,    KC_R,    KC_T,    KC_B,    KC_RWIN,  KC_SLCK, \
		   KC_F3,   KC_TAB,   KC_LBRC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PDOT,   KC_BSLS, \
		   KC_F4,   KC_LALT,  KC_APP,   KC_Q,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_P3,    KC_RCTL, \
		   KC_F5,   KC_P6,  KC_P7,   KC_P8,   KC_LEFT, KC_UP,   KC_RGHT, KC_DOWN, KC_NO,    KC_ENT \
		),
	[_FN1] = LAYOUT(
		   KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   \
		   KC_F1,   KC_ESC,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGDN,  KC_PGUP, \
		   KC_F2,   KC_DEL,   KC_RBRC,  KC_W,    KC_E,    KC_R,    KC_T,    KC_B,    KC_RWIN,  KC_SLCK, \
		   KC_F3,   KC_TAB,   KC_LBRC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PDOT,   KC_BSLS, \
		   KC_F4,   KC_LALT,  KC_APP,   KC_Q,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_P3,    KC_RCTL, \
		   KC_F5,   KC_P6,  KC_P7,   KC_P8,    KC_LEFT, KC_UP,   KC_RGHT, KC_DOWN, KC_NO,    KC_ENT \
	),

};
