#include "meas.h"

/**
 * @brief Function to read INA226 register and convert to uint16 fake float
 * @param[out] *r -> project structure pointer
 */
void VAW_Conversion(rps_type *r) {
    RPS_CHECK_STRUCT_PTR();

    r->val.volt = INA_GetBusVoltageTiny();

    r->val.curr = INA_GetCurrentTiny();
    if (r->val.curr < 0) {
        r->val.curr_u = -r->val.curr;
    } else {
        r->val.curr_u = r->val.curr;
    }

    r->val.watt = INA_GetPowerTiny();
}