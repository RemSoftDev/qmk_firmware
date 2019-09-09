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

_delay_ms(10);

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

// переключает режим работы USB<->I2C должна быть в главном цикле
void reconfig_connection (void) {

/*  операция аппаратно зависима только для ATmega32u4
//	if (UDADDR & _BV(ADDEN)){ // истина когда USB установлен реальный адрес (есть связь с хостом)
*/
	bool is_i2c_activ = i2c_activity_check();

	//нужно переконфигуриться на i2c
	if ( (is_i2c_activ || !(UDADDR & _BV(ADDEN)) ) && isUsbConnected ){
		isUsbConnected=false;

		motor_off();
		rgblight_setrgb(0x00, 0x00, 0x00);
		hvb_init_extern();
		keyboard_slave_setup();
	}
	else {
		// нужно переконфигуриться на USB
		if ( (UDADDR & _BV(ADDEN)) && (!is_i2c_activ) && (!isUsbConnected) ){
			isUsbConnected=true;

			motor_off();
			rgblight_setrgb(0x00, 0x00, 0x00);
			hvb_init_local();
			i2c_slave_stop();
		}
	}
}

// эта функция вызывается в главном цикле при работе на USB
void matrix_scan_kb(void) {
// put your looping keyboard code here
// runs every cycle (a lot)

	reconfig_connection();

	static uint16_t test_timer = 0;        // таймер
		if (timer_elapsed(test_timer) > 2000) {
			test_timer = timer_read();

			rgb_chek();
			motor_chek();
	    }

    matrix_scan_user();
}

// эта функция вызывается в главном цикле при работе на I2C
void matrix_slave_scan_user(void) {

	reconfig_connection();
}


