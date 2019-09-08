#include "left.h"
#include "motor.h"
#include "split_util.h"
#include "i2c_slave.h"

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

//	motors_init();
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

// в самом начале инициалицации
void keyboard_pre_init_kb(void) {
  // Call the keyboard pre init code.
	motors_init();
}

// вызввается после того как все встроенные модули проинициализировались
void keyboard_post_init_kb(void) {
	debug_enable = true; // нужно для работы dprintf
	debug_keyboard = true;
	isUsbConnected = true;
	rgblight_setrgb(0x00, 0x00, 0x00);
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
		//motor_chek();
    }
 }

void reconfig_connection (void) {
//	isUsbConnected
//	static bool is_Usb_mode = true;

/*	if (UDADDR & _BV(ADDEN)){ // истина когда USB установлен реальный адрес (есть связь с хостом)
		motor1_off();
	}
	else {
		motor1_on();
	}
	*/
	bool is_i2c_activ = i2c_activity_check();

	//нужно переконфигуриться на i2c
	if ( (is_i2c_activ || !(UDADDR & _BV(ADDEN)) ) && isUsbConnected ){
		isUsbConnected=false;
		motor1_off();
		rgblight_setrgb(0x00, 0x00, 0x00);
		_delay_ms(10);
		hvb_init_extern();
		keyboard_slave_setup();
	}
	else {
		// нужно переконфигуриться на USB
		if ( (UDADDR & _BV(ADDEN)) && (!is_i2c_activ) && (!isUsbConnected) ){
			isUsbConnected=true;
			motor1_on();
			rgblight_setrgb(0x00, 0x00, 0x00);
			_delay_ms(10);
			hvb_init_local();
			i2c_slave_stop(); // ?
		}
	}
}


void matrix_scan_kb(void) {
// put your looping keyboard code here
// runs every cycle (a lot)

	reconfig_connection();

    matrix_scan_user();
}

void matrix_slave_scan_user(void) {

	reconfig_connection();

}


