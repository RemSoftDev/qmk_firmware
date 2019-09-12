#include "split_util.h"
#include "matrix.h"
#include "keyboard.h"
#include "config.h"
#include "timer.h"
#include "transport.h"
#include "quantum.h"

#ifdef EE_HANDS
#    include "tmk_core/common/eeprom.h"
#    include "eeconfig.h"
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLED_SPLIT)
#    include "rgblight.h"
#endif

volatile bool isLeftHand = true;
volatile bool isUsbConnected = false;

__attribute__((weak)) bool is_keyboard_left(void) {

#ifdef N_SLAVES_I2C
	return true;
#else
	return false; //tt левая и правая = слейвы в понимании qmk правые по дефолту
#endif

}

// имеет два смысла: 1мастер шины i2c; 2слейв не отдает данные в usb
__attribute__((weak)) bool is_keyboard_master(void) {

//#ifdef N_SLAVES_I2C
	return true;
//#else
//	return false; //tt левая и правая = слейвы
//#endif
}

static void keyboard_master_setup(void) {
#if defined(USE_I2C) || defined(EH)
#    ifdef SSD1306OLED
    matrix_master_OLED_init();
#    endif
#endif
    transport_master_init();
}

void keyboard_slave_setup(void) { transport_slave_init(); }

// this code runs before the usb and keyboard is initialized
void matrix_setup(void) {
    isLeftHand = is_keyboard_left();

#if defined(RGBLIGHT_ENABLE) && defined(RGBLED_SPLIT)
    uint8_t num_rgb_leds_split[2] = RGBLED_SPLIT;
    if (isLeftHand) {
        rgblight_set_clipping_range(0, num_rgb_leds_split[0]);
    } else {
        rgblight_set_clipping_range(num_rgb_leds_split[0], num_rgb_leds_split[1]);
    }
#endif

    if (is_keyboard_master() && is_keyboard_left()) {
        keyboard_master_setup();
    } else {
       //keyboard_slave_setup(); // transport_slave_init(); = вызову когда убедюсь что нет связи по USB
    }
}
