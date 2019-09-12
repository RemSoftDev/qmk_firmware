#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    TarasTest
#define PRODUCT         hwtest_left   //tt это видно пользователю когда винда нашла новое оборудование и пытается найти драйвер
#define DESCRIPTION     test hw
/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { F7, F6, F5, F4, F0, F1 }
#define MATRIX_COL_PINS { C6, C7, B0, B1, B2, B3, B7, B4, B5, B6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3 //сменил с D0 тк был конфликт I2C
#define RGBLED_NUM 55
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define RGBLIGHT_LIMIT_VAL 64
#define USB_MAX_POWER_CONSUMPTION 400

//sets the I2C clock rate speed for keyboards using I2C. The default is `400000L`, except for keyboards using `split_common`, where the default is `100000L`.
#define F_SCL 100000L

#define USE_I2C

#define SLAVE_I2C_ADDRESS 0x32 // 0x30 - left 0x32 -right
#define N_NO_MASTER_I2C 200 // количество кругов главного цыкла без запросов от мастераI2C после которого принимается решение перейти на USB порт (20 = примерно 0.1сек)

