#include "meas.h"

/**
 * @brief Function to read INA226 register and convert to uint16 fake float
 * @param[out] *r -> project structure pointer
 */
void VAW_Conversion(rps_type *r) {
    RPS_CHECK_STRUCT_PTR();

    // static uint16_t med_fil_volt_buf[3],med_fil_curr_buf[3];

    r->val.volt = INA_GetBusVoltageTiny();
    // FilterMedian(&r->val.volt, med_fil_volt_buf);

    r->val.curr = INA_GetCurrentTiny();
    // FilterMedian(&r->val.curr, med_fil_curr_buf);

    r->val.watt = INA_GetPowerTiny();
}