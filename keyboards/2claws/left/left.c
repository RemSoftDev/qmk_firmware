#include "left.h"

// мультиплексор на управление светодиодами локально
void hvb_init_local(void) {
	DDRE |= (1<<2); // OUT
	PORTE &= ~(1<<2); // 0 = rgb led local control
	//PORTE |= (1<<2); // 1 = rgb led extern control
}
// мультиплексор на управление светодиодами из платы мозгов
void hvb_init_extern(void) {
	DDRE |= (1<<2); // OUT
	PORTE |= (1<<2); // 1 = rgb led extern control
}

// настройка портов управления моторами
void motor_init_ports(void) {
	DDRD |= (1<<7) | (1<<6) | (1<<5) | (1<<4); // OUT
	DDRE |= (1<<6); // OUT
	
	//all motor off
	PORTD &= ~( (1<<7) | (1<<6) | (1<<5) | (1<<4) ); // 0 = motor off
	PORTE &= ~(1<<6); // 0
}

void motor_on(void) {
	PORTD |= (1<<7) | (1<<6) | (1<<5) | (1<<4);
	PORTE |= (1<<6);
}

void motor_off(void) {
	PORTD &= ~( (1<<7) | (1<<6) | (1<<5) | (1<<4) );
	PORTE &= ~(1<<6); 
}

// M1
void motor1_on(void) {
	PORTE |= (1<<6);
}

void motor1_off(void) {
	PORTE &= ~(1<<6); 
}

void motor2_on(void) {
	PORTD |= (1<<7);
}

void motor2_off(void) {
	PORTD &= ~(1<<7);
}

void motor3_on(void) {
	PORTD |= (1<<6);
}

void motor3_off(void) {
	PORTD &= ~(1<<6);
}

void motor4_on(void) {
	PORTD |= (1<<5);
}

void motor4_off(void) {
	PORTD &= ~(1<<5);
}

void motor5_on(void) {
	PORTD |= (1<<4);
}

void motor5_off(void) {
	PORTD &= ~(1<<4);
}

// для проверки моторов
void motor_chek(void) {
static uint8_t state = 1;

 switch (state) {
    case 1:
		dprint("motor1_on\n");	
		motor1_on();
      break;
	case 2:
		dprint("motor2_on\n");	
		motor2_on();
		motor1_off();
      break;
	case 3:
		dprint("motor3_on\n");	
		motor3_on();
		motor2_off();
      break;
	case 4:
		dprint("motor4_on\n");	
		motor4_on();
		motor3_off();
      break;	  
	case 5: 
		dprint("motor5_on\n");
		motor5_on();
		motor4_off();
      break;
	case 6:
		dprint("motor_off\n");	
		motor5_off();
      break;
	case 7:
		dprint("motor_on\n");
		motor_on();
      break;
	case 8:
		dprint("motor_off\n");
		motor_off();
      break;
	  
	default:
		state = 0;
	  break;
 }
 state++;
	  
}

// для проверки rgb led
void rgb_chek(void) {
static uint8_t state = 1;
//dprintf("%d string\n", state);
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
//    matrix_init_user();
    rgblight_enable_noeeprom();
	motor_init_ports();
	hvb_init_local();
//	hvb_init_extern();
//    rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
//rgblight_setrgb(0x00, 0x00, 0xFF);
//	rgblight_mode_noeeprom(3);
_delay_ms(10);

/*
while (1){

_delay_ms(2000);
motor_chek();
rgb_chek();

}
*/

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
}



uint16_t test_timer = 0;        // таймер "штуки"

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer. 

    if (timer_elapsed(test_timer) > 2000) {
		test_timer = timer_read();
		
		rgb_chek();
		motor_chek();
    }
 }
 
 
 void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}



