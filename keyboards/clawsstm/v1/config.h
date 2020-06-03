/**
 * config.h
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

// define if left board
#define LEFT_CLAW

// если обьявлено то верхний разем для связи с хостом
#define TYPE_C_UP

// в роли опорного выступает питающее напряжение спу
#define ADC_REF_MV       3300
#define ADC_MAX_VL       0xFFF
#define ADC_1V2_MV       1502       // 3300mV/4095==1210mV/x -> x=1502

#define JOYSTIK_BLIND    10     // (процент) зона нечуствителтности в центальном положении

#define R_DEL_UP      10000     // Ом сопротивление верхнего плеча делителя
#define R_DEL_DW      15000     // Ом сопротивление нижнего плеча делителя

/* USB Device descriptor parameter */
#define VENDOR_ID       0x60BE
#define PRODUCT_ID      0x00B0
#define DEVICE_VER      0x0001

/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER    TarasTest

#ifdef LEFT_CLAW
#define PRODUCT         v1_board_left_claw   //tt это видно пользователю когда винда нашла новое оборудование и пытается найти драйвер
// номер светодиода WS2812 отвечающего CAPSLOCK (єнкодер=0 джойстик=1 SW29=25)
#define WS_LED_CAPS_LOCK 25
#define WS_LED_CAPS_LOCK_R   100
#define WS_LED_CAPS_LOCK_G   0
#define WS_LED_CAPS_LOCK_B   100
// джойстик запаян
//#define JOYSTIK
#else  //#ifdef LEFT_CLAW
#define PRODUCT         v1_board_right_claw
//#define WS_LED_CAPS_LOCK 1
#define WS_LED_CAPS_LOCK_R   100
#define WS_LED_CAPS_LOCK_G   0
#define WS_LED_CAPS_LOCK_B   100

#define JOYSTIK
#endif //#ifdef LEFT_CLAW

#define DESCRIPTION     clawsKeyboard.com

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 10

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
// on scheme              R1  R2  R3  R4  R5  R6
#define MATRIX_ROW_PINS { A0, A1, A4, A6, C4, B2 }
// on scheme              C1  C2  C3  C4  C5   C6  C7   C8  C9  C10
#define MATRIX_COL_PINS { C0, C1, C2, C3, C13, D2, A15, B9, B4, B5 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 0

#define ENCODERS_PAD_A { C12 }
#define ENCODERS_PAD_B { C11 }
//#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 4

#define WS2812_LED_N 56
#define RGBLED_NUM WS2812_LED_N
#define WS2812_DMA_STREAM STM32_DMA1_STREAM6  // DMA stream for TIMx_UP (look up in reference manual under DMA Channel selection)
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 128
#define RGB_DI_PIN B8
#define WS2812_PWM_DRIVER PWMD4

#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP
// tapping setting
#define TAPPING_TERM 200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD


#endif
