/**
 * config.h
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

// define if left board
//#define LEFT_CLAW

/* USB Device descriptor parameter */
#define VENDOR_ID       0x60BE   
#define PRODUCT_ID      0x00BE
#define DEVICE_VER      0x0001

/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER    TarasTest

#ifdef LEFT_CLAW
#define PRODUCT         hwtest_left_claw   //tt это видно пользователю когда винда нашла новое оборудование и пытается найти драйвер
#else
#define PRODUCT         hwtest_right_claw
#endif

#define DESCRIPTION     keyboard test hw

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { B13, B12, B14, B15, C9, A8 }
#define MATRIX_COL_PINS { A0, A1, A4, A5, A6, A7, C4, C5, A15, D2 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 0

/* indicator rgb -> NOAH 65 keyboard*/
//#define WS2812_LED_N 55
//#define RGBLED_NUM WS2812_LED_N
//#define WS2812_TIM_N 4
//#define WS2812_TIM_CH 3
//#define PORT_WS2812 GPIOB
//#define PIN_WS2812 8
//#define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA stream for TIMx_UP (look up in reference manual under DMA Channel selection)
//#define WS2812_DMA_CHANNEL 6                  // DMA channel for TIMx_UP
#define RGBLED_NUM 54
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 128
#define RGB_DI_PIN B8

// tapping setting
#define TAPPING_TERM 200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD


#endif
