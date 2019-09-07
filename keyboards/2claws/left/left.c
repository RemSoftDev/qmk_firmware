#include "left.h"
#include "motor.h"
#include "split_util.h"

// мультиплексор на управление светодиодами локально
void hvb_init_local(void) {
	DDRE |= (1<<2); // OUT
	PORTE &= ~(1<<2); // 0 = rgb led local control
}
// мультиплексор на управление светодиодами из платы мозгов
void hvb_init_extern(void) {
	DDRE |= (1<<2); // OUT
	PORTE |= (1<<2); // 1 = rgb led extern control
}


// для проверки rgb led
void rgb_chek(void) {
static uint8_t state = 1;
dprintf("%d string\n", state);
 switch (state) {
    case 1:	
		rgblight_setrgb(0x00, 0x00, 0x00);
      break;
	case 2: 
		rgblight_setrgb(0x00, 0x00, 0x3F);
      break;
	case 3: 
		rgblight_setrgb(0x00, 0x3F, 0x00);
      break;
	case 4: 
		rgblight_setrgb(0x3F, 0x00, 0x00);
      break;	  
	case 5: 
		// РАЗМЕЩЕНО последним чтобы была возможность успеть нажать ресет до того как выполнение кода сюда доберется
		// ВКЛЮЧЕНИЕ ВСЕХ СВЕТОДИОДОВ НА (0xFF, 0xFF, 0xFF); ПРИВОДИТ К ПРОСАДКЕ НАПРЯЖЕНИЯ ПИТАНИЯ И ЗАВИСАНИЮ
		rgblight_setrgb(0x3F, 0x3F, 0x3F);
      break;

	default:
		state = 0;
	  break;
 }
 state++;
	  
}




void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
//    led_init_ports();

//  rgblight_enable_noeeprom();
//	motor_init_ports();
//	hvb_init_local(); isUsbConnected = true;

	motors_init();
//	motor1_on();
//	motor2_on();
//    rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
//rgblight_setrgb(0x00, 0x00, 0xFF);
//	rgblight_mode_noeeprom(3);
_delay_ms(10);

//while (1){ _delay_ms(2000); motor_chek(); rgb_chek(); }


//rgblight_sethsv_noeeprom_white();
//rgblight_sethsv_noeeprom_white();
//#define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#define RGBLIGHT_EFFECT_SNAKE
//#define RGBLIGHT_EFFECT_KNIGHT
//#define RGBLIGHT_EFFECT_CHRISTMAS
//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//rgblight_setrgb(0x00, 0x00, 0xFF);
//    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING);
//	rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
matrix_init_user();
}


// вызввается после того как все встроенные модули проинициализировались
void keyboard_post_init_kb(void) {
	debug_enable = true; // нужно для работы dprintf
	debug_keyboard = true;

	uint16_t usb_timer = timer_read();
	while (timer_elapsed(usb_timer) < 5000) {
		if (USB_DeviceState != DEVICE_STATE_Configured) {
//#if defined(INTERRUPT_CONTROL_ENDPOINT)
//		         ;
//#else
		         USB_USBTask();
//#endif
		}
		else{
			isUsbConnected = true;
			break;
		}
	}

//	isUsbConnected = false;
	if (isUsbConnected == true){
		dprint("USB_DeviceState == DEVICE_STATE_Configured\n");
		hvb_init_local();
		wait_ms(1000);
		motor1_on();
		wait_ms(1000);
		motor1_off();
	}
	else{
		dprint("USB_DeviceState != DEVICE_STATE_Configured\n");
		hvb_init_extern();
		keyboard_slave_setup();
	}

	keyboard_post_init_user();
}

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ
};

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer.
//void matrix_slave_scan_user(void) {
;

static uint16_t test_timer = 0;        // таймер
	if (timer_elapsed(test_timer) > 2000) {
		test_timer = timer_read();
		
		rgb_chek();
		motor_chek();
    }

 }
 
/*
void matrix_scan_kb(void) {
// put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}
*/


