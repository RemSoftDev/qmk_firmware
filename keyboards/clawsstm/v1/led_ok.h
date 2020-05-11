#ifndef LED_OK_H
#define LED_OK_H

#include "quantum.h"

void led_ok_on(void);
void led_ok_off(void);
void led_ok_init_ports(void);
// мигает светикоом с заданsv тактом (в милисекундах)
void led_ok_blink(uint16_t takt_ms);

#endif /* LED_OK_H */
