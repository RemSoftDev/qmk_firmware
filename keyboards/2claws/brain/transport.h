#pragma once

#include <common/matrix.h>

void transport_master_init(void);
void transport_slave_init(void);

// returns false if valid data not received from slave
//bool transport_master(matrix_row_t matrix[]);
bool transport_master(matrix_row_t matrix[],uint8_t slave_i2c_addr);
void transport_slave(matrix_row_t matrix[]);
