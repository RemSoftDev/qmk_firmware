#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TarasTest
#define PRODUCT         2claws
#define DESCRIPTION     test2claws
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 6

/* key matrix pins */
// MCU = at90usb1286
#define MATRIX_ROW_PINS { A0, A1, A2, A3 }
#define MATRIX_COL_PINS { C1, C2, C3, C4, C5, C6 }
#define UNUSED_PINS

#define DIRECT_PINS { { D4 } }		//  * pins mapped to rows and columns, from left to right. Defines a matrix where each switch is connected to a separate pin and ground.

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#define BACKLIGHT_LEVELS 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN B5

#define RGBLED_NUM 120
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define RGBLIGHT_LIMIT_VAL 255
#define USB_MAX_POWER_CONSUMPTION 400

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_IC OLED_IC_SSD1306
//#define OLED_IC OLED_IC_SH1106
#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 64
#define OLED_MATRIX_SIZE 1024




