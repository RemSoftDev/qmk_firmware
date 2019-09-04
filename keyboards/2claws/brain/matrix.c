/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "split_util.h"
#include "config.h"
#include "quantum.h"
#include "debounce.h"
#include "transport.h"

#include "debug.h"

#ifdef ENCODER_ENABLE
#    include "encoder.h"
#endif

#if (MATRIX_COLS <= 8)
#    define print_matrix_header() print("\nr/c 01234567\n")
#    define print_matrix_row(row) print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop32(matrix[i])
#    define ROW_SHIFTER ((uint32_t)1)
#endif

#define ERROR_DISCONNECT_COUNT 5

//#define ROWS_PER_HAND (MATRIX_ROWS / 2)
#define ROWS_PER_HAND 3

#ifdef DIRECT_PINS
static pin_t direct_pins[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;
#else
static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t raw_matrix[ROWS_BRAIN];

// row offsets for each hand
uint8_t thisHand, thatHand;

// user-defined overridable functions

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

__attribute__((weak)) void matrix_slave_scan_user(void) {}

// helper functions

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }

inline uint8_t matrix_cols(void) { return MATRIX_COLS; }

bool matrix_is_modified(void) {
    if (debounce_active()) return false;
    return true;
}

inline bool matrix_is_on(uint8_t row, uint8_t col) { return (matrix[row] & ((matrix_row_t)1 << col)); }

inline matrix_row_t matrix_get_row(uint8_t row) { return matrix[row]; }

void matrix_print(void) {
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row);
        print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

uint8_t matrix_key_count(void) {
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }
    return count;
}

// matrix code

#ifdef DIRECT_PINS

static void init_pins(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            pin_t pin = direct_pins[row][col];
            if (pin != NO_PIN) {
                setPinInputHigh(pin);
            }
        }
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    matrix_row_t last_row_value = current_matrix[current_row];
    current_matrix[current_row] = 0;

    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        pin_t pin = direct_pins[current_row][col_index];
        if (pin != NO_PIN) {
            current_matrix[current_row] |= readPin(pin) ? 0 : (ROW_SHIFTER << col_index);
        }
    }

    return (last_row_value != current_matrix[current_row]);
}

#elif (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) { setPinInputHigh(row_pins[row]); }

static void unselect_rows(void) {
    for (uint8_t x = 0; x < ROWS_PER_HAND; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    wait_us(30);

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Populate the matrix row with the state of the col pin
        current_matrix[current_row] |= readPin(col_pins[col_index]) ? 0 : (ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

#elif (DIODE_DIRECTION == ROW2COL)

static void select_col(uint8_t col) {
    setPinOutput(col_pins[col]);
    writePinLow(col_pins[col]);
}

static void unselect_col(uint8_t col) { setPinInputHigh(col_pins[col]); }

static void unselect_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

static void init_pins(void) {
    unselect_cols();
    for (uint8_t x = 0; x < ROWS_PER_HAND; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;

    // Select col and wait for col selecton to stabilize
    select_col(current_col);
    wait_us(30);

    // For each row...
    for (uint8_t row_index = 0; row_index < ROWS_PER_HAND; row_index++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[row_index];

        // Check row pin state
        if (readPin(row_pins[row_index])) {
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~(ROW_SHIFTER << current_col);
        } else {
            // Pin LO, set col bit
            current_matrix[row_index] |= (ROW_SHIFTER << current_col);
        }

        // Determine if the matrix changed state
        if ((last_row_value != current_matrix[row_index]) && !(matrix_changed)) {
            matrix_changed = true;
        }
    }

    // Unselect col
    unselect_col(current_col);

    return matrix_changed;
}

#endif

void matrix_init(void) {
    debug_enable = true;
    debug_matrix = true;
    debug_mouse  = true;

    // Set pinout for right half if pinout for that half is defined
    if (!isLeftHand) {
#ifdef DIRECT_PINS_RIGHT
        const pin_t direct_pins_right[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS_RIGHT;
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            for (uint8_t j = 0; j < MATRIX_COLS; j++) {
                direct_pins[i][j] = direct_pins_right[i][j];
            }
        }
#endif
#ifdef MATRIX_ROW_PINS_RIGHT
        const pin_t row_pins_right[MATRIX_ROWS] = MATRIX_ROW_PINS_RIGHT;
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            row_pins[i] = row_pins_right[i];
        }
#endif
#ifdef MATRIX_COL_PINS_RIGHT
        const pin_t col_pins_right[MATRIX_COLS] = MATRIX_COL_PINS_RIGHT;
        for (uint8_t i = 0; i < MATRIX_COLS; i++) {
            col_pins[i] = col_pins_right[i];
        }
#endif
    }

    thisHand = isLeftHand ? 0 : (ROWS_PER_HAND);
    thatHand = ROWS_PER_HAND - thisHand;

    // initialize key pins
    init_pins();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

    debounce_init(ROWS_PER_HAND);

    matrix_init_quantum();
}

uint8_t _matrix_scan(void) {
    bool changed = false;

    // Set row, read cols
    uint8_t current_row = 0; // первая строка
        changed |= read_cols_on_row(raw_matrix, current_row);

    debounce(raw_matrix, matrix + 0, 1, changed);

    return (uint8_t)changed;
}


void mat_tst(uint16_t takt) {
	static uint16_t count_mat = 0;
	static bool is_tst = false;
	uint16_t tmp;
    if (timer_elapsed(count_mat) > takt) {
    	count_mat = timer_read();
		if (is_tst) {
			is_tst = false;
	        //phex(takt);
	        //print(": ");
	       // print_matrix_row(row);
	        //print("\n");
			matrix_print();
			//tmp = sizeof(matrix_row_t); // вернуло 4 зависит от MATRIX_COLS  у лев и проай будут 2!!!!
			//dprintf("matrix_row_t=%u\n", tmp);
			//tmp = sizeof(matrix); // вернуло 28 (28/4= 7 строк: 1+3+3 3*4=12 байт от половинки = вся матрица половинки )
			//dprintf("matrix=%u\n", tmp);
	        PORTD |=(1<<7); // 1=led off
		}
		else {
			is_tst = true;
			PORTD &= ~(1<<7); // 0 = led on
		}
    }
}

uint8_t matrix_scan(void) {

	mat_tst(1000);
    uint8_t ret = _matrix_scan();  // опрос локальной матрицы = по сути одной кнопки.
//    dprintf("m");

//        for (uint8_t n_slaves_i2c=0; n_slaves_i2c<N_SLAVES_I2C*2; n_slaves_i2c=n_slaves_i2c+2 ) { // перебираю подчиненые клавиатуры

        	//uint8_t	slave_i2c_addr = SLAVE_I2C_ADDRESS+n_slaves_i2c; //  I2C адрес следующего раба от базоваого адреса

			//                смещение в матрице
        	transport_master( (matrix +1) , SLAVE_I2C_ADDRESS ); // возвращет всеравно всегда true
			transport_master( (matrix +1+3) , (SLAVE_I2C_ADDRESS+2) ); // возвращет всеравно всегда true
			//dprintf("slave_i2c_addr = %d\n", slave_i2c_addr);
			//dprintf("error_count = %d\n", error_count);
			// reset other half if disconnected
			//dprint("\nr/c ERROR_DISCONNECT_COUNT %x\n",slave_i2c_addr);
			//dprintf("slave_i2c_addr = %d\n", slave_i2c_addr);

       // }

        matrix_scan_quantum();
    return ret;
}
