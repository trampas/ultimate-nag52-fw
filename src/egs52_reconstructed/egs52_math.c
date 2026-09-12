#include "egs52_hw.h"
#include "egs52_math.h"

/* 0x0d8166: Sum Pressure Terms
 * Computes the final MPC pressure command by combining various
 * dynamic and static offsets.
 */
void egs52_update_total_mpc_pressure(void) {
    int16_t base = *((int16_t*)0xD4D2);
    int16_t dynamic = *((int16_t*)0xD47C);
    int16_t reduction = EGS_RAM->spc_reduction_factor;
    int16_t fixed_offset = *((int16_t*)0xD4B2);

    int32_t total = (int32_t)base + dynamic - reduction - fixed_offset;
    
    if (total < 0) total = 0;
    if (total > 8000) total = 8000;

    EGS_RAM->mpc_total_pressure = (uint16_t)total;
}

/* 0x0d2008: MPC Pressure Clamp
 */
void egs52_clamp_mpc_target_pressure(void) {
    uint16_t target = EGS_RAM->mpc_pressure_target;
    EGS_RAM->mpc_pressure_current = target;
    
    if (EGS_RAM->system_status_flags & 0x20u) {
        uint16_t limit = *((uint16_t*)0xD480);
        if (target >= limit) {
            EGS_RAM->mpc_pressure_current = limit;
        }
    }
}

/* 0x095b6a: Read Channel Table Word
 * Accesses gearbox-specific calibration constants from the ROM tables.
 */
uint16_t egs52_read_calibration_word(uint16_t index) {
    // ROM table index is located at 0x24:F7C0 (offset in ROM)
    // The C166 DPP registers handle the segment switching.
    uint16_t* table = (uint16_t*)0xF7C0;
    return table[index & 0xFF];
}

/* 0x0d5b66: Update Shift State
 */
void egs52_update_shift_state(void) {
    uint16_t state = EGS_RAM->shift_state_index;
    
    if (state == 0) {
        if (EGS_RAM->current_gear != EGS_RAM->target_gear) {
            EGS_RAM->shift_state_index = 1; // Transition to FILLING
        }
    } else if (state == 1) {
        // Handle filling time adaptation and clutch pre-load
    }
}
