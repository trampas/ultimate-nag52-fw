#ifndef EGS52_MATH_RECON_H
#define EGS52_MATH_RECON_H

#include <stdint.h>

/* Pressure Calculation Routines */
void egs52_update_total_mpc_pressure(void);
void egs52_clamp_mpc_target_pressure(void);

/* Shift Logic Routines */
void egs52_update_shift_state(void);

/* Calibration Helpers */
uint16_t egs52_read_calibration_word(uint16_t index);

/* Helper macros for fixed-point math used in EGS52 */
#define EGS_FIXED_MUL(a, b) (((uint32_t)(a) * (b)) / 100u)
#define EGS_BAR_TO_MBAR(x)  ((x) * 1000)

#endif
