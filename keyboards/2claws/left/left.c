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
/*
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
*/



void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
//    led_init_ports();
//    matrix_init_user();
//    rgblight_enable_noeeprom();
	motor_init_ports();
//	hvb_init_local();
	hvb_init_extern();
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

// SSD1306 OLED driver logic
#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
  static const char PROGMEM rgbkb_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(rgbkb_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0},
    {0xb5,0xb6,0},
    {0x97,0x98,0},
    {0xb7,0xb8,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_ln_P(mode_logo[0], false);
    oled_write_ln_P(mode_logo[1], false);
  } else {
    oled_write_ln_P(mode_logo[2], false);
    oled_write_ln_P(mode_logo[3], false);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _QWERTY:
      oled_write_ln_P(PSTR("QWERTY"), false);
      break;
    case _COLEMAK:
      oled_write_ln_P(PSTR("Colemak"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    case _ADJ:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_ln_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
	
//	D1_blink(1000);
//  if (is_keyboard_master()) {
	if (false) {
    render_status();
  } else {
    render_logo();
//    oled_scroll_left();
  }
}

#endif

uint16_t test_timer = 0;        // таймер "штуки"

// эта функция вызывается в главном цикле
void matrix_scan_user(void) {     //# The very important timer. 

    if (timer_elapsed(test_timer) > 2000) {
		test_timer = timer_read();
		
//		rgb_chek();
		motor_chek();
    }
 }
 
 
 void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}



