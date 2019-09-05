/*
 * motor.c
 *
 *  Created on: 5 сент. 2019 г.
 *      Author: Taras
 */

#include "motor.h"


#ifdef N_SLAVES_I2C // если обьявлены рабы значит это мастер

motors_config_t motors_config[N_SLAVES_I2C];

void slaves_motors_init(void)
{
	for (uint8_t i=0; i < N_SLAVES_I2C; i++ ) {
		//motors_config[i].raw=0;
		motors_config[i].mot1=false;
		motors_config[i].mot2=false;
		motors_config[i].mot3=false;
		motors_config[i].mot4=false;
		motors_config[i].mot5=false;
		motors_config[i].r1=false;
		motors_config[i].r2=false;
		motors_config[i].r3=false;
	}
}


void slave_motor_on(uint8_t slave_i2c_addr, uint8_t motor_number)
{
	uint8_t  i;

	if (slave_i2c_addr==SLAVE_I2C_ADDRESS) i = 0;
	else i = 1;

	 switch (motor_number) {
	    case 1:
	    	motors_config[i].mot1=true;
	      break;
		case 2:
			motors_config[i].mot2=true;
	      break;
		case 3:
			motors_config[i].mot3=true;
	      break;
		case 4:
			motors_config[i].mot4=true;
	      break;
		case 5:
			motors_config[i].mot5=true;
	      break;

		default:
		  break;
	 }
}

void slave_motor_off(uint8_t slave_i2c_addr, uint8_t motor_number)
{
	uint8_t  i;

	if (slave_i2c_addr==SLAVE_I2C_ADDRESS) i = 0;
	else i = 1;

	 switch (motor_number) {
	    case 1:
	    	motors_config[i].mot1=false;
	      break;
		case 2:
			motors_config[i].mot2=false;
	      break;
		case 3:
			motors_config[i].mot3=false;
	      break;
		case 4:
			motors_config[i].mot4=false;
	      break;
		case 5:
			motors_config[i].mot5=false;
	      break;

		default:
		  break;
	 }
}

uint8_t get_motors_state(uint8_t slave_i2c_addr)
{
	uint8_t  i;

	if (slave_i2c_addr==SLAVE_I2C_ADDRESS) i = 0;
	else i = 1;
	return motors_config[i].raw;
}

#endif
//----------- значит раб ---------


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

motors_config_t motors_config_old;
void motors_init(void)
{
	motor_init_ports();
	motor_off();
	motors_config_old.mot1=false;
	motors_config_old.mot2=false;
	motors_config_old.mot3=false;
	motors_config_old.mot4=false;
	motors_config_old.mot5=false;
	motors_config_old.r1=false;
	motors_config_old.r2=false;
	motors_config_old.r3=false;
}

// получает значения из буфера I2C
void set_motors_state(uint8_t input_dat)
{
	motors_config_t motors_config = (motors_config_t) input_dat;

	if (motors_config_old.raw != motors_config.raw) {
		motors_config_old.raw = motors_config.raw;

		if (motors_config.mot1) motor1_on();
		else motor1_off();

		if (motors_config.mot2) motor2_on();
		else motor2_off();

		if (motors_config.mot3) motor3_on();
		else motor3_off();

		if (motors_config.mot4) motor4_on();
		else motor4_off();

		if (motors_config.mot5) motor5_on();
		else motor5_off();
	}
}

