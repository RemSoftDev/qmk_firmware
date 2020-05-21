#pragma once

#include "quantum.h"


void connection_star_thread(void);

void conn_init_ports(void);

void conn_preset_ports(void);

void conn_sw_up(void);
void conn_sw_side(void);

void conn_init_usart_up(void);
void conn_init_usart_side(void);
void conn_init_usart_host(void);

void conn_test_usart_up(void);
void conn_test_usart_side(void);
void conn_test_usart_host(void);

