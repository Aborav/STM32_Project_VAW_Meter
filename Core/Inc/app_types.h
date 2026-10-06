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
            return;                                                            \
        }                                                                      \
    } while (0);

// Limits & values
/////////////////////////////////////////////////////
#define VAL_VOLT_MAX 2600U
#define VAL_CURR_MAX 5000U
#define VAL_WATT_MAX 1300U

#define TEMp_OFF_LIMIT 30
#define TEMP_1ST_LIMIT 35
#define TEMP_2ND_LIMIT 40
#define TEMP_3RD_LIMIT 45
#define TEMP_HIGH_LIMIT 50
#define TEMP_CONVERS_TIME 1000U

/*---------------------------------------------TYPES------------------------------------------------*/

// Values structure
////////////////////////////////////////////////////////////
typedef struct _values_type {
    uint16_t volt;   ///< value from measuring source (INA226)
    int16_t curr;    ///< value from measuring source (INA226)
    uint16_t curr_u; ///< unsigned value of current
    uint16_t watt;   ///< value from measuring source (INA226)
    int8_t temp_t;   ///< termperature from transisotors sink DS18B20

} values_type;

// Bits field for status flags
////////////////////////////////////////////////////////////
typedef struct _flags_type {
    unsigned temp_conv_ready : 1; ///< ds18b20 ready for temperature conversion
    unsigned disp_meas_page : 1;  ///< draw measurement page
    unsigned tl494_on : 1;        ///< TL494 is on
    unsigned overheat : 1;        ///< transistors heat sink temp. high
    unsigned overcurr : 1;        ///< high current limit reached
    unsigned rev_curr : 1;        ///< reverse current detected
    unsigned reserved : 2;        // reserved bits;

} flags_type;

// COMMON STRUCTURE
////////////////////////////////////////////////////////////
typedef struct _rps_type {
    values_type val;
    flags_type fl;
} rps_type;

#endif /* INC_APP_TYPES_H_ */
