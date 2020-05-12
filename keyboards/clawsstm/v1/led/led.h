//LED_H конфликтует
#ifndef LED_USE_H
#define LED_USE_H

#include "quantum.h"

void led_ok_on(void);
void led_ok_off(void);
void led_init_ports(void);
// мигает светикоом с заданsv тактом (в милисекундах)
void led_ok_blink(uint16_t takt_ms);
void led_star_thread(void);

#endif /* LED_H */
