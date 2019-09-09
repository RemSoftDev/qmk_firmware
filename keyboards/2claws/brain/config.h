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
#define MATRIX_ROWS 13
#define MATRIX_COLS 10
#define ROWS_PER_HAND 6

// количество рядов заполняемых платой мозга (идут первыми в общей матрице клавиш)
#define ROWS_BRAIN 1
// следующие ряды от раба с наименьшим адресом I2C и так далее

/* key matrix pins */
// нет собственной марицы
//#define MATRIX_ROW_PINS { A0, A1, A2, A3 }
//#define MATRIX_COL_PINS { C1, C2, C3, C4, C5, C6 }
#define UNUSED_PINS

//  * pins mapped to rows and columns, from left to right. Defines a matrix where each switch is connected to a separate pin and ground.
#define NO NO_PIN
#define DIRECT_PINS {\
{ D4 } }
//00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F  00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F
//00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19 MATRIX_COLS=20
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

//#define TAP_CODE_DELAY 50 //Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN B5

// run RGB animations?
#define RGBLIGHT_ANIMATIONS

//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLED_NUM 120
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 200

#define DRIVER_LED_TOTAL 120 // єквивалент RGBLED_NUM 120
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
//#define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
//#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Sets the default mode, if none has been set

// sets the maximum power (in mA) over USB for the device (default: 500)
#define USB_MAX_POWER_CONSUMPTION 500

#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_IC OLED_IC_SSD1306
#define OLED_DISPLAY_128X64
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 64
#define OLED_MATRIX_SIZE 1024
#define OLED_DISABLE_TIMEOUT // шоб нетух єкран без нажатий (видит нажатия только своей платы!)

//sets the I2C clock rate speed for keyboards using I2C. The default is `400000L`, except for keyboards using `split_common`, where the default is `100000L`.
#define F_SCL 100000L

#define USE_I2C

#define N_SLAVES_I2C 2 // количество поддчиненных клавиатур
#define SLAVE_I2C_ADDRESS 0x30 // адрес первой подчиненой клавиатуры, у сдеуюющей буде адрес на 2 больше

// вывод в https://www.pjrc.com/teensy/hid_listen.html
//#define TEST_I2C // каждые 10000 запровсов по I2C выводит сколько небыло ответов - реализация в transport_master();
//#define TEST_MAT // выводит общую матрицу

