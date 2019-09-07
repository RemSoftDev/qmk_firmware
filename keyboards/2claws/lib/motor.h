/*
 * motor.h
 *
 *  Created on: 5 сент. 2019 г.
 *      Author: Taras
 */

#ifndef KEYBOARDS_2CLAWS_BRAIN_MOTOR_H_
#define KEYBOARDS_2CLAWS_BRAIN_MOTOR_H_

#include <stdint.h>
#include <stdbool.h>

typedef union {
    uint8_t raw;
    struct {
        bool    mot1 :1;
        bool    mot2 :1;
        bool    mot3 :1;
        bool    mot4 :1;
        bool    mot5 :1;
        // в резерве
        bool    r1 :1;
        bool    r2 :1;
        bool    r3 :1;
    };
} motors_config_t;

void motors_init(void);
void motor_chek(void);
void slaves_motors_init(void);
uint8_t get_motors_state(uint8_t slave_i2c_addr);
void set_motors_state(uint8_t raw);
void slave_motor_on(uint8_t slave_i2c_addr, uint8_t motor_number);
void slave_motor_off(uint8_t slave_i2c_addr, uint8_t motor_number);

#endif /* KEYBOARDS_2CLAWS_BRAIN_MOTOR_H_ */
