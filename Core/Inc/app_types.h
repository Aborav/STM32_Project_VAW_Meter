/*
 * app_types.h
 *
 *  Created on: Mar 8, 2026
 *      Author: aborav
 */

#ifndef INC_APP_TYPES_H_
#define INC_APP_TYPES_H_

#include "main.h"

/*---------------------------------------------DEFINES------------------------------------------------*/
// Fast functions
/////////////////////////////////////////////////////
// empty pointer check
#define RPS_CHECK_STRUCT_PTR()                                                 \
    do {                                                                       \
        if (r == 0) {                                                          \
            r->err.bit.empty_ptr = 1;                                          \
            return;                                                            \
        }                                                                      \
    } while (0);

// Limits & values
/////////////////////////////////////////////////////
#define VAL_VOLT_MAX 2600U
#define VAL_CURR_MAX 5000U
#define VAL_WATT_MAX 1250U

#define BTN_DEBOUNCE_DELAY 100U
#define TEMP_HIGH_LIMIT 50U

#define TEMP_CONVERS_TIME 1000U

/*---------------------------------------------TYPES------------------------------------------------*/

// Values structure
////////////////////////////////////////////////////////////
typedef struct _values_type {
    // VAW
    uint16_t volt; ///< value from measuring source (INA226)
    uint16_t curr; ///< value from measuring source (INA226)
    uint16_t watt; ///< value from measuring source (INA226)
    int8_t temp_t; ///< termperature from transisotors sink DS18B20

} values_type;

// Bits field for status flags
////////////////////////////////////////////////////////////
typedef struct _flags_type {
    unsigned temp_conv_ready : 1; ///< ds18b20 ready for temperature conversion
    unsigned disp_meas_page : 1;  ///< draw measurement page
    unsigned tl494_on : 1;        ///< TL494 is on
    unsigned
        overheat : 1; ///< transistors heat sink temperature high limit reached
    unsigned overcurr : 1; ///< high current limit reached
    unsigned reserved : 3; // reserved bits;

} flags_type;

// Bits field for errors
////////////////////////////////////////////////////////////
typedef union _errors_type {
    uint8_t all_errors;
    struct {
        unsigned cicle_timeout : 1; ///< we are stuck in a cycle
        unsigned ina226_off : 1;    ///< INA226 doesn't respond at start
        unsigned flash_erase : 1;   ///< flash erase error
        unsigned flash_write : 1;   ///< flash write error
        unsigned
            wrong_channel : 1;  ///< wrong function input channel _CURR,_VOLT
        unsigned empty_ptr : 1; ///< empty pointer as input
        unsigned reserved : 3;
    } bit;
} errors_type;

// COMMON STRUCTURE
////////////////////////////////////////////////////////////
typedef struct _rps_type {
    values_type val;
    flags_type fl;
    errors_type err;
} rps_type;

#endif /* INC_APP_TYPES_H_ */
