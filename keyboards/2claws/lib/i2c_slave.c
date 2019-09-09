/* Library made by: g4lvanix
 * Github repository: https://github.com/g4lvanix/I2C-slave-lib
 */

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "i2c_slave.h"

#ifndef N_NO_MASTER_I2C
	#define N_NO_MASTER_I2C 200
#endif


volatile uint8_t i2c_slave_reg[I2C_SLAVE_REG_COUNT];

static volatile uint8_t buffer_address;
static volatile bool slave_has_register_set = false;
static volatile uint8_t isr_i2c_cnt;


void i2c_slave_init(uint8_t address){
    // load address into TWI address register
    TWAR = address;
    // set the TWCR to enable address matching and enable TWI, clear TWINT, enable TWI interrupt
    TWCR = (1 << TWIE) | (1 << TWEA) | (1 << TWINT) | (1 << TWEN);
}

void i2c_slave_stop(void){
    // clear acknowledge and enable bits
    TWCR &= ~((1 << TWEA) | (1 << TWEN));
}

ISR(TWI_vect){
    uint8_t ack = 1;

    switch(TW_STATUS){
        case TW_SR_SLA_ACK:
            // The device is now a slave receiver
            slave_has_register_set = false;
            break;

        case TW_SR_DATA_ACK:
            // This device is a slave receiver and has received data
            // First byte is the location then the bytes will be writen in buffer with auto-incriment
            if(!slave_has_register_set){
                buffer_address = TWDR;

                if (buffer_address >= I2C_SLAVE_REG_COUNT) {  // address out of bounds dont ack
                  ack            = 0;
                  buffer_address = 0;
                }
                slave_has_register_set = true; // address has been receaved now fill in buffer
            } else {
                i2c_slave_reg[buffer_address] = TWDR;
                buffer_address++;
            }
            break;

        case TW_ST_SLA_ACK:
        case TW_ST_DATA_ACK:
            // This device is a slave transmitter and master has requested data
            TWDR = i2c_slave_reg[buffer_address];
            buffer_address++;
            isr_i2c_cnt++;
            break;

        case TW_BUS_ERROR:
            // We got an error, reset i2c
            TWCR = 0;
        default:
            break;
    }

    // Reset i2c state machine to be ready for next interrupt
    TWCR |= (1 << TWIE) | (1 << TWINT) | (ack << TWEA) | (1 << TWEN);
}

// вызывать в главном цикле
inline bool i2c_activity_check(void){
	static bool activ = false;
	static uint8_t n_fake_call = N_NO_MASTER_I2C;
	static uint8_t old_isr_i2c_cnt;

	if (old_isr_i2c_cnt==isr_i2c_cnt) {
		if(n_fake_call<N_NO_MASTER_I2C){
			n_fake_call++;
		}
		else {
		    if(n_fake_call==N_NO_MASTER_I2C) activ = false;
		}
	}
	else{
		old_isr_i2c_cnt=isr_i2c_cnt;
		n_fake_call=0;
		activ = true;
	}
	return activ;
}

