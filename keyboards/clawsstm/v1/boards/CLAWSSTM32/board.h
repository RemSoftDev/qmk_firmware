/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 * !!! ME edit manually
 */

#ifndef BOARD_H
#define BOARD_H

/*
 * Board identifier.
 */
#ifdef LEFT_CLAW
#define BOARD_CLAWSKEYBOARD_LEFT
#define BOARD_NAME                  "Claws keyboard left"
#else
#define BOARD_CLAWSKEYBOARD_RIGHT
#define BOARD_NAME                  "Claws keyboard right"
#endif

/*
 *  Define for functional usb without VBUS detection
 */
#define BOARD_OTG_NOVBUSSENS

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

//#define STM32_HSE_BYPASS

/*
 * Board voltages. 330 = 3.3V
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F401xC

/*
 * IO pins assignments.
 */
#define GPIOA_RM1                   0U
#define GPIOA_RM2                   1U
#define GPIOA_MON_TX                2U
#define GPIOA_MON_RX                3U
#define GPIOA_RM3                   4U
#define GPIOA_MOT1                  5U
#define GPIOA_RM4                   6U
#define GPIOA_MOT2                  7U
#define GPIOA_I2C3_SCL              8U
#define GPIOA_OLED_N_RESET          9U
#define GPIOA_OLED_N_CS             10U
#define GPIOA_OTG_FS_DM             11U
#define GPIOA_OTG_FS_DP             12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_CM7                   15U

#define GPIOB_VADC1                 0U
#define GPIOB_VADC2                 1U
#define GPIOB_VADC3                 2U
#define GPIOB_PIN3                  3U
#define GPIOB_CM9                   4U
#define GPIOB_CM10                  5U
#define GPIOB_TX1                   6U
#define GPIOB_RX1                   7U
#define GPIOB_CPU_WS2812            8U
#define GPIOB_CM8                   9U
#define GPIOB_PIN10                 10U
#define GPIOB_PIN11                 11U
#define GPIOB_OLED_DC               12U
#define GPIOB_OLED_CLK              13U
#define GPIOB_OLED_ON               14U
#define GPIOB_OLED_DIN              15U

#define GPIOC_CM1                   0U
#define GPIOC_CM2                   1U
#define GPIOC_CM3                   2U
#define GPIOC_CM4                   3U
#define GPIOC_RM5                   4U
#define GPIOC_RM6                   5U
#define GPIOC_TX6                   6U
#define GPIOC_RX6                   7U
#define GPIOC_MOT3                  8U
#define GPIOC_I2C3_SDA              9U
#define GPIOC_LED_OK                10U
#define GPIOC_E1A                   11U
#define GPIOC_E1B                   12U
#define GPIOC_CM5                   13U
#define GPIOC_STROB_PORT            14U
#define GPIOC_SEL_PORT              15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_CM6                   2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_PIN13                 13U
#define GPIOD_PIN14                 14U
#define GPIOD_PIN15                 15U

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_PIN3                  3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_PIN12                 12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

/*
 * IO lines assignments.
 */
#define MON_TX                PAL_LINE(GPIOA, GPIOA_MON_TX)
#define MON_RX                PAL_LINE(GPIOA, GPIOA_MON_RX)

#define OTG_FS_DM             PAL_LINE(GPIOA, GPIOA_OTG_FS_DM)
#define OTG_FS_DP             PAL_LINE(GPIOA, GPIOA_OTG_FS_DP)

#define SWDIO                 PAL_LINE(GPIOA, GPIOA_SWDIO)
#define SWCLK                 PAL_LINE(GPIOA, GPIOA_SWCLK)

#define VADC1                 PAL_LINE(GPIOB, GPIOB_VADC1)
#define VADC2                 PAL_LINE(GPIOB, GPIOB_VADC2)
#define VADC3                 PAL_LINE(GPIOB, GPIOB_VADC3)

#define STROB_PORT            PAL_LINE(GPIOC, GPIOC_STROB_PORT)
#define SEL_PORT              PAL_LINE(GPIOC, GPIOC_SEL_PORT)

#define TX1                   PAL_LINE(GPIOB, GPIOB_TX1)
#define RX1                   PAL_LINE(GPIOB, GPIOB_RX1)

#define TX6                   PAL_LINE(GPIOC, GPIOC_TX6)
#define RX6                   PAL_LINE(GPIOC, GPIOC_RX6)

#define I2C3_SDA              PAL_LINE(GPIOC, GPIOC_I2C3_SDA)
#define I2C3_SCL              PAL_LINE(GPIOA, GPIOA_I2C3_SCL)

#define CPU_WS2812            PAL_LINE(GPIOB, GPIOB_CPU_WS2812)

#define LED_OK                PAL_LINE(GPIOC, GPIOC_LED_OK)

#define MOT1                  PAL_LINE(GPIOA, GPIOA_MOT1)
#define MOT2                  PAL_LINE(GPIOA, GPIOA_MOT2)
#define MOT3                  PAL_LINE(GPIOC, GPIOC_MOT3)

#define SPI3_SCK              PAL_LINE(GPIOC, GPIOC_SPI3_SCK)
#define SPI3_MISO             PAL_LINE(GPIOC, GPIOC_SPI3_MISO)
#define SPI3_MOSI             PAL_LINE(GPIOC, GPIOC_SPI3_MOSI)

#define OLED_N_RESET          PAL_LINE(GPIOA, GPIOA_OLED_N_RESET)
#define OLED_N_CS             PAL_LINE(GPIOA, GPIOA_OLED_N_CS)
#define OLED_DC               PAL_LINE(GPIOB, GPIOB_OLED_DC)
#define OLED_CLK              PAL_LINE(GPIOB, GPIOB_OLED_CLK)
#define OLED_ON               PAL_LINE(GPIOB, GPIOB_OLED_ON)
#define OLED_DIN              PAL_LINE(GPIOB, GPIOB_OLED_DIN)

#define E1A                  PAL_LINE(GPIOC, GPIOC_E1A)
#define E1B                  PAL_LINE(GPIOC, GPIOC_E1B)

#define RM1                  PAL_LINE(GPIOA, GPIOA_RM1)
#define RM2                  PAL_LINE(GPIOA, GPIOA_RM2)
#define RM3                  PAL_LINE(GPIOA, GPIOA_RM3)
#define RM4                  PAL_LINE(GPIOA, GPIOA_RM4)
#define RM5                  PAL_LINE(GPIOC, GPIOC_RM5)
#define RM6                  PAL_LINE(GPIOC, GPIOC_RM6)

#define CM1                  PAL_LINE(GPIOC, GPIOC_CM1)
#define CM2                  PAL_LINE(GPIOC, GPIOC_CM2)
#define CM3                  PAL_LINE(GPIOC, GPIOC_CM3)
#define CM4                  PAL_LINE(GPIOC, GPIOC_CM4)
#define CM5                  PAL_LINE(GPIOC, GPIOC_CM5)
#define CM6                  PAL_LINE(GPIOD, GPIOD_CM6)
#define CM7                  PAL_LINE(GPIOA, GPIOA_CM7)
#define CM8                  PAL_LINE(GPIOB, GPIOB_CM8)
#define CM9                  PAL_LINE(GPIOB, GPIOB_CM9)
#define CM10                 PAL_LINE(GPIOB, GPIOB_CM10)

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 * or https://hubstub.ru/stm32/151-stm32f3-i-stm32f4-gpio.html
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))


#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_RM1) |         \
                                     PIN_MODE_INPUT(GPIOA_RM2) |         \
                                     PIN_MODE_INPUT(GPIOA_MON_TX) |     \
                                     PIN_MODE_INPUT(GPIOA_MON_RX) |     \
                                     PIN_MODE_INPUT(GPIOA_RM3) |         \
                                     PIN_MODE_OUTPUT(GPIOA_MOT1) |        \
                                     PIN_MODE_INPUT(GPIOA_RM4) |     \
                                     PIN_MODE_OUTPUT(GPIOA_MOT2) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_I2C3_SCL) |         \
                                     PIN_MODE_OUTPUT(GPIOA_OLED_N_RESET) |         \
                                     PIN_MODE_OUTPUT(GPIOA_OLED_N_CS) |         \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DM) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DP) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_OUTPUT(GPIOA_CM7))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_RM1) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RM2) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MON_TX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MON_RX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RM3) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MOT1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RM4) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MOT2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_I2C3_SCL) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OLED_N_RESET) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OLED_N_CS) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_CM7))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_RM1) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_RM2) |         \
                                     PIN_OSPEED_HIGH(GPIOA_MON_TX) |     \
                                     PIN_OSPEED_HIGH(GPIOA_MON_RX) |     \
                                     PIN_OSPEED_VERYLOW(GPIOA_RM3) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_MOT1) |     \
                                     PIN_OSPEED_VERYLOW(GPIOA_RM4) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_MOT2) |        \
                                     PIN_OSPEED_HIGH(GPIOA_I2C3_SCL) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_OLED_N_RESET) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_OLED_N_CS) |         \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DM) |  \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DP) |  \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |      \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |      \
                                     PIN_OSPEED_VERYLOW(GPIOA_CM7))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLUP(GPIOA_RM1) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_RM2) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_MON_TX) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_MON_RX) |     \
                                     PIN_PUPDR_PULLUP(GPIOA_RM3) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_MOT1) |  \
                                     PIN_PUPDR_PULLUP(GPIOA_RM4) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOA_MOT2) |      \
                                     PIN_PUPDR_PULLUP(GPIOA_I2C3_SCL) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_OLED_N_RESET) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_OLED_N_CS) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DM) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DP) |  \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_PULLUP(GPIOA_CM7))
// GPIO port output data register (160 RM0368.pdf Rev 5)
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_RM1) |         \
                                     PIN_ODR_HIGH(GPIOA_RM2) |         \
                                     PIN_ODR_HIGH(GPIOA_MON_TX) |     \
                                     PIN_ODR_HIGH(GPIOA_MON_RX) |     \
                                     PIN_ODR_HIGH(GPIOA_RM3) |         \
                                     PIN_ODR_LOW(GPIOA_MOT1) |     \
                                     PIN_ODR_HIGH(GPIOA_RM4) |        \
                                     PIN_ODR_LOW(GPIOA_MOT2) |        \
                                     PIN_ODR_HIGH(GPIOA_I2C3_SCL) |         \
                                     PIN_ODR_HIGH(GPIOA_OLED_N_RESET) |         \
                                     PIN_ODR_HIGH(GPIOA_OLED_N_CS) |         \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DM) |  \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DP) |  \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |      \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |      \
                                     PIN_ODR_HIGH(GPIOA_CM7))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_RM1, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_RM2, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_MON_TX, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_MON_RX, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_RM3, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_MOT1, 0U) |     \
                                     PIN_AFIO_AF(GPIOA_RM4, 0U) |       \
                                     PIN_AFIO_AF(GPIOA_MOT2, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_I2C3_SCL, 4U) |        \
                                     PIN_AFIO_AF(GPIOA_OLED_N_RESET, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_OLED_N_CS, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DM, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DP, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_CM7, 0U))


#define VAL_GPIOB_MODER             (PIN_MODE_ANALOG(GPIOB_VADC1) |         \
                                     PIN_MODE_ANALOG(GPIOB_VADC2) |           \
                                     PIN_MODE_ANALOG(GPIOB_VADC3) |           \
                                     PIN_MODE_INPUT(GPIOB_PIN3) |        \
                                     PIN_MODE_INPUT(GPIOB_CM9) |         \
                                     PIN_MODE_INPUT(GPIOB_CM10) |         \
                                     PIN_MODE_INPUT(GPIOB_TX1) |        \
                                     PIN_MODE_INPUT(GPIOB_RX1) |           \
                                     PIN_MODE_OUTPUT(GPIOB_CPU_WS2812) |        \
                                     PIN_MODE_INPUT(GPIOB_CM8) |        \
                                     PIN_MODE_INPUT(GPIOB_PIN10) |         \
                                     PIN_MODE_INPUT(GPIOB_PIN11) |          \
                                     PIN_MODE_OUTPUT(GPIOB_OLED_DC) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_OLED_CLK) |          \
                                     PIN_MODE_OUTPUT(GPIOB_OLED_ON) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_OLED_DIN))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_VADC1) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VADC2) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VADC3) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CM9) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CM10) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_TX1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RX1) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CPU_WS2812) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CM8) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN10) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN11) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_OLED_DC) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_OLED_CLK) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_OLED_ON) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_OLED_DIN))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOB_VADC1) |         \
                                     PIN_OSPEED_VERYLOW(GPIOB_VADC2) |           \
                                     PIN_OSPEED_VERYLOW(GPIOB_VADC3) |           \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN3) |        \
                                     PIN_OSPEED_VERYLOW(GPIOB_CM9) |         \
                                     PIN_OSPEED_VERYLOW(GPIOB_CM10) |         \
                                     PIN_OSPEED_HIGH(GPIOB_TX1) |        \
                                     PIN_OSPEED_HIGH(GPIOB_RX1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_CPU_WS2812) |        \
                                     PIN_OSPEED_VERYLOW(GPIOB_CM8) |        \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN10) |         \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN11) |          \
                                     PIN_OSPEED_HIGH(GPIOB_OLED_DC) |          \
                                     PIN_OSPEED_HIGH(GPIOB_OLED_CLK) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_OLED_ON) |          \
                                     PIN_OSPEED_HIGH(GPIOB_OLED_DIN))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_VADC1) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_VADC2) |           \
                                     PIN_PUPDR_FLOATING(GPIOB_VADC3) |           \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN3) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_CM9) |         \
                                     PIN_PUPDR_PULLUP(GPIOB_CM10) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_TX1) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_RX1) |           \
                                     PIN_PUPDR_PULLDOWN(GPIOB_CPU_WS2812) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_CM8) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN10) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN11) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_OLED_DC) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_OLED_CLK) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_OLED_ON) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_OLED_DIN))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_VADC1) |         \
                                     PIN_ODR_HIGH(GPIOB_VADC2) |           \
                                     PIN_ODR_HIGH(GPIOB_VADC3) |           \
                                     PIN_ODR_HIGH(GPIOB_PIN3) |        \
                                     PIN_ODR_HIGH(GPIOB_CM9) |         \
                                     PIN_ODR_HIGH(GPIOB_CM9) |         \
                                     PIN_ODR_HIGH(GPIOB_TX1) |        \
                                     PIN_ODR_HIGH(GPIOB_RX1) |           \
                                     PIN_ODR_LOW(GPIOB_CPU_WS2812) |        \
                                     PIN_ODR_HIGH(GPIOB_CM8) |        \
                                     PIN_ODR_HIGH(GPIOB_PIN10) |         \
                                     PIN_ODR_HIGH(GPIOB_PIN11) |          \
                                     PIN_ODR_HIGH(GPIOB_OLED_DC) |          \
                                     PIN_ODR_HIGH(GPIOB_OLED_CLK) |          \
                                     PIN_ODR_HIGH(GPIOB_OLED_ON) |          \
                                     PIN_ODR_HIGH(GPIOB_OLED_DIN))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_VADC1, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_VADC2, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_VADC3, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN3, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_CM9, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_CM9, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_TX1, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_RX1, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_CPU_WS2812, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_CM8, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_PIN10, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_OLED_DC, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_OLED_CLK, 5U) |         \
                                     PIN_AFIO_AF(GPIOB_OLED_ON, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_OLED_DIN, 5U))


#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(GPIOC_CM1) |         \
                                     PIN_MODE_INPUT(GPIOC_CM2) |         \
                                     PIN_MODE_INPUT(GPIOC_CM3) |           \
                                     PIN_MODE_INPUT(GPIOC_CM4) |           \
                                     PIN_MODE_OUTPUT(GPIOC_RM5) |           \
                                     PIN_MODE_OUTPUT(GPIOC_RM6) |           \
                                     PIN_MODE_INPUT(GPIOC_TX6) |           \
                                     PIN_MODE_INPUT(GPIOC_RX6) |         \
                                     PIN_MODE_OUTPUT(GPIOC_MOT3) |           \
                                     PIN_MODE_ALTERNATE(GPIOC_I2C3_SDA) |           \
                                     PIN_MODE_OUTPUT(GPIOC_LED_OK) |          \
                                     PIN_MODE_INPUT(GPIOC_E1A) |          \
                                     PIN_MODE_INPUT(GPIOC_E1B) |          \
                                     PIN_MODE_INPUT(GPIOC_CM5) |         \
                                     PIN_MODE_OUTPUT(GPIOC_STROB_PORT) |       \
                                     PIN_MODE_OUTPUT(GPIOC_SEL_PORT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_CM1) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CM2) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CM3) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CM4) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RM5) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RM6) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_TX6) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RX6) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_MOT3) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_I2C3_SDA) |           \
                                     PIN_OTYPE_PUSHPULL(GPIOC_LED_OK) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOC_E1A) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOC_E1B) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOC_CM5) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_STROB_PORT) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SEL_PORT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOC_CM1) |         \
                                     PIN_OSPEED_VERYLOW(GPIOC_CM2) |         \
                                     PIN_OSPEED_VERYLOW(GPIOC_CM3) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_CM4) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_RM5) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_RM6) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_TX6) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_RX6) |         \
                                     PIN_OSPEED_VERYLOW(GPIOC_MOT3) |           \
                                     PIN_OSPEED_HIGH(GPIOC_I2C3_SDA) |           \
                                     PIN_OSPEED_VERYLOW(GPIOC_LED_OK) |          \
                                     PIN_OSPEED_VERYLOW(GPIOC_E1A) |          \
                                     PIN_OSPEED_VERYLOW(GPIOC_E1B) |          \
                                     PIN_OSPEED_VERYLOW(GPIOC_CM5) |         \
                                     PIN_OSPEED_VERYLOW(GPIOC_STROB_PORT) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_SEL_PORT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(GPIOC_CM1) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_CM2) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_CM3) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_CM4) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_RM5) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_RM6) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_TX6) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_RX6) |         \
                                     PIN_PUPDR_PULLDOWN(GPIOC_MOT3) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_I2C3_SDA) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_LED_OK) |          \
                                     PIN_PUPDR_PULLUP(GPIOC_E1A) |          \
                                     PIN_PUPDR_PULLUP(GPIOC_E1B) |          \
                                     PIN_PUPDR_PULLUP(GPIOC_CM5) |         \
                                     PIN_PUPDR_PULLUP(GPIOC_STROB_PORT) |       \
                                     PIN_PUPDR_PULLUP(GPIOC_SEL_PORT))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_CM1) |         \
                                     PIN_ODR_HIGH(GPIOC_CM2) |         \
                                     PIN_ODR_HIGH(GPIOC_CM3) |           \
                                     PIN_ODR_HIGH(GPIOC_CM4) |           \
                                     PIN_ODR_HIGH(GPIOC_RM5) |           \
                                     PIN_ODR_HIGH(GPIOC_RM6) |           \
                                     PIN_ODR_HIGH(GPIOC_TX6) |           \
                                     PIN_ODR_HIGH(GPIOC_RX6) |         \
                                     PIN_ODR_LOW(GPIOC_MOT3) |           \
                                     PIN_ODR_HIGH(GPIOC_I2C3_SDA) |           \
                                     PIN_ODR_HIGH(GPIOC_LED_OK) |          \
                                     PIN_ODR_HIGH(GPIOC_E1A) |          \
                                     PIN_ODR_HIGH(GPIOC_E1B) |          \
                                     PIN_ODR_HIGH(GPIOC_CM5) |         \
                                     PIN_ODR_HIGH(GPIOC_STROB_PORT) |       \
                                     PIN_ODR_HIGH(GPIOC_SEL_PORT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_CM1, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_CM2, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_CM3, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_CM4, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_RM5, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_RM6, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_TX6, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_RX6, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_MOT3, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_I2C3_SDA, 4U) |          \
                                     PIN_AFIO_AF(GPIOC_LED_OK, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_E1A, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_E1B, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_CM5, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_STROB_PORT, 0U) |      \
                                     PIN_AFIO_AF(GPIOC_SEL_PORT, 0U))


#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_OUTPUT(GPIOD_CM6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CM6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOD_PIN0) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN1) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_CM6) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN3) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN4) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN5) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN6) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN7) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN8) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN9) |          \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN10) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN11) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN12) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN13) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN14) |         \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_CM6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_CM6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_CM6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0U))

#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN15))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN15))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN15))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLUP(GPIOE_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN15))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN15))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN7, 0U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN15, 0U))

#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLUP(GPIOF_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0U))


#define VAL_GPIOG_MODER             (PIN_MODE_INPUT(GPIOG_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_HIGH(GPIOG_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_PULLUP(GPIOG_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOG_PIN15))
#define VAL_GPIOG_ODR               (PIN_ODR_HIGH(GPIOG_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN7, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN15, 0U))


#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOH_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN15))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOH_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN15, 0U))


#define VAL_GPIOI_MODER             (PIN_MODE_INPUT(GPIOI_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_HIGH(GPIOI_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_PULLUP(GPIOI_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(GPIOI_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN7, 0U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
