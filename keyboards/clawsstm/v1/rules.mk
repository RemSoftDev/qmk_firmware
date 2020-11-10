#
# ПАМЯТКА
# 0 предполагается установлена - wsl
# 1 запустить в рабочем каталоге(C:\qmk_firmware): bash
# 2 запустить в bash(taras@asusrog:/mnt/c/qmk_firmware$): make clean
# 3 запустить в bash(taras@asusrog:/mnt/c/qmk_firmware$): make clawsstm/v1
# 4 перевести STM32 в режим бутлоадера: удерживая нажатой TS2 подключить боковой разем USB (без USB хабов!)
# 5 Прошить контроллер (запустить в рабочем каталоге): dfu-util.exe -a 0 -d 0483:df11 -s 0x08000000:leave -D "C:\qmk_firmware\clawsstm_v1_default.bin"
#
## chip/board settings
# - the next two should match the directories in
#   <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = STM32
MCU_SERIES = STM32F4xx

# Linker script to use
# - it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#   or <this_dir>/ld/
MCU_LDSCRIPT = STM32F401_boot

# Startup code to use
#  - it should exist in <chibios>/os/common/startup/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = stm32f4xx

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = CLAWSSTM32

# Cortex version
MCU  = cortex-m4

# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7

USE_FPU = yes

# Options to pass to dfu-util when flashing
#DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave
#DFU_SUFFIX_ARGS = -p DF11 -v 0483
#C:\qmk_firmware>dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -R -D .build/clawsstm_v1_default.bin
#dfu-util.exe -a 0 -d 0483:df11 -s 0x08000000:leave -D "C:\qmk_firmware\clawsstm_v1_default.bin"


# Build Options
#   comment out to disable the options.
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes	    # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # USB Nkey Rollover
NO_USB_STARTUP_CHECK = yes  # Disable initialization only when usb is plugged in
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port
UNICODE_ENABLE = no         # Unicode
#CUSTOM_MATRIX = yes
RGB_MATRIX_ENABLE = no

RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
RGBLIGHT_CUSTOM_DRIVER = yes

#WS2812_DRIVER = bitbang

ENCODER_ENABLE = yes

KEYBOARD_SHARED_EP = yes

# project specific files
VPATH += keyboards/clawsstm/v1/led\
		keyboards/clawsstm/v1/display\
		keyboards/clawsstm/v1/adc_internal\
		keyboards/clawsstm/v1/connection\
		keyboards/clawsstm/v1/rgbled\
		keyboards/clawsstm/v1/security
SRC += led/led.c\
       display/display.c\
       display/ssd1331.c\
	   adc_internal/adc_internal.c\
	   adc_internal/joystick.c\
	   adc_internal/thermometer_int.c\
	   adc_internal/voltage.c\
	   connection/connection.c\
	   rgbled/ws2812_pwm.c\
	   security/atecc608a.c

SRC += $(QUANTUM_DIR)/color.c
SRC += $(QUANTUM_DIR)/rgb_matrix.c
SRC += $(QUANTUM_DIR)/rgb_matrix_drivers.c
#	   $(CHIBIOS)/os/various/syscalls.c\
# https://github.com/qmk/qmk_firmware/issues/7059
# sprintf вешает QMK
