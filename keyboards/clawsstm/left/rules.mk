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
#C:\qmk_firmware>dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -R -D .build/clawsstm_left_default.bin
#dfu-util.exe -a 0 -d 0483:df11 -s 0x08000000:leave -D "C:\qmk_firmware\clawsstm_left_default.bin"


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
#WS2812_DRIVER = bitbang
RGBLIGHT_CUSTOM_DRIVER = yes

# project specific files
VPATH += keyboards/clawsstm/v1/rgbled
SRC += rgbled/ws2812_pwm.c
