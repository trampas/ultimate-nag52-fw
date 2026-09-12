#include "egs52_hw.h"
#include "egs52_math.h"

/* Forward declarations of hidden transition routines */
void egs52_update_near_c170_097634(uint16_t param);
void egs52_register_sequence_097676(uint16_t param);
void egs52_update_near_c1aa_0994ba(void);
void egs52_latch_request_mask(uint16_t mask);
void egs52_clear_status_c118(void);

/* 0x09496c: Initialize Operating Masks
 * Sets default operating state.
 */
void egs52_initialize_operating_masks(void) {
    EGS_RAM->unknown_c06c = 3;
    EGS_RAM->operating_mask_combined = 0x100;
    EGS_RAM->current_active_mask = 0x100;
}

/* 0x094dcc: Get Current Operating Mask
 */
uint16_t egs52_get_operating_mask(void) {
    return EGS_RAM->current_active_mask;
}

/* 0x094980: Update Operating Masks
 * Selects the client/operating mode bitmask for the system.
 * This is a complex priority-based state machine that triggers
 * various initialization/deinitialization routines when bits change.
 */
void egs52_update_operating_masks(uint16_t mask, uint8_t client_id) {
    uint16_t old_combined = EGS_RAM->operating_mask_combined;
    
    if (client_id < 8) {
        EGS_RAM->client_masks[client_id] = mask;
    }

    EGS_RAM->can_status_flags |= 1; 
    EGS_RAM->operating_mask_scratch = 0;

    // Persist bits 5 and 6 (0x60) during reconfiguration
    if (EGS_RAM->operating_mask_combined & 0x60) {
        EGS_RAM->operating_mask_scratch = EGS_RAM->operating_mask_combined & 0x60;
    }

    // Combine all client masks into one active set
    for (int i = 0; i < 8; i++) {
        EGS_RAM->operating_mask_scratch |= EGS_RAM->client_masks[i];
    }

    // Critical section for updating the shared state
    EGS_RAM->operating_mask_combined = EGS_RAM->operating_mask_scratch;
    EGS_RAM->can_status_flags &= ~1;

    uint16_t current = EGS_RAM->operating_mask_combined;
    bool handled = false;
    bool change_detected = false;

    // Bit 8 priority (0x100): Normal Operation
    if (current & 0x100) {
        EGS_RAM->current_active_mask = 0x100;
        handled = true;
    } else if (old_combined & 0x100) {
        change_detected = true;
    }

    // Bit 10 priority (0x400): Unknown Special Mode
    if (!handled) {
        if (current & 0x400) {
            EGS_RAM->current_active_mask = 0x400;
            if (!(old_combined & 0x400) || change_detected) {
                egs52_update_near_c170_097634(0x100);
                egs52_register_sequence_097676(0x200);
            }
            handled = true;
        } else if (old_combined & 0x400) {
            change_detected = true;
        }
    }

    // Bit 9 priority (0x200): Diagnostics / KWP2000
    if (!handled) {
        if (current & 0x200) {
            EGS_RAM->current_active_mask = 0x200;
            if (!(old_combined & 0x200) || change_detected) {
                egs52_update_near_c170_097634(0x100);
                egs52_register_sequence_097676(0x200);
            }
            handled = true;
        } else if (old_combined & 0x200) {
            change_detected = true;
        }
    }

    // Bit 7 priority (0x80): Unknown
    if (!handled) {
        if (current & 0x80) {
            EGS_RAM->current_active_mask = 0x80;
            if (!(old_combined & 0x80) || change_detected) {
                egs52_update_near_c170_097634(0);
                egs52_register_sequence_097676(0);
            }
            handled = true;
        } else if (old_combined & 0x80) {
            change_detected = true;
        }
    }

    // Bit 6 priority (0x40): Flash / Programming Mode?
    if (!handled) {
        if (current & 0x40) {
            if (!(current & 0x08) && !(current & 0x200)) {
                EGS_RAM->current_active_mask = 0x40;
                if (!(old_combined & 0x40) || change_detected) {
                    egs52_update_near_c170_097634(0);
                    egs52_register_sequence_097676(0);
                    egs52_update_near_c1aa_0994ba();
                }
                handled = true;
            } else {
                EGS_RAM->client_masks[client_id] &= ~0x40;
                EGS_RAM->operating_mask_combined &= ~0x40;
            }
        } else if (old_combined & 0x40) {
            change_detected = true;
        }
    }

    // Bit 11 priority (0x800): SBC/Maybach Brake Interaction
    if (!handled) {
        if (current & 0x800) {
            EGS_RAM->current_active_mask = 0x800;
            if (!(old_combined & 0x800) || change_detected) {
                egs52_update_near_c170_097634(0);
                egs52_register_sequence_097676(0);
            }
            handled = true;
        } else if (old_combined & 0x800) {
            change_detected = true;
        }
    }

    // Bit 3 priority (0x08): Limp Home Mode
    if (!handled) {
        if (current & 0x08) {
            EGS_RAM->current_active_mask = 0x08;
            if (!(old_combined & 0x08) || change_detected) {
                egs52_update_near_c170_097634(0x100);
                egs52_register_sequence_097676(0x200);
            }
            handled = true;
        } else if (old_combined & 0x08) {
            change_detected = true;
        }
    }

    // Bit 2 priority (0x04): Unknown Fault state
    if (!handled) {
        if (current & 0x04) {
            EGS_RAM->current_active_mask = 0x04;
            if (!(old_combined & 0x04) || change_detected) {
                egs52_update_near_c170_097634(0x100);
                egs52_register_sequence_097676(0x200);
            }
            handled = true;
        } else if (old_combined & 0x04) {
            change_detected = true;
        }
    }

    // Bit 1 priority (0x02): Unknown Init state
    if (!handled) {
        if (current & 0x02) {
            EGS_RAM->current_active_mask = 0x02;
            if (!(old_combined & 0x02) || change_detected) {
                egs52_update_near_c170_097634(0x100);
                egs52_register_sequence_097676(0x200);
                egs52_latch_request_mask(0x800);
            }
            handled = true;
        } else if (old_combined & 0x02) {
            change_detected = true;
        }
    }

    // Bit 0 priority (0x01): Initial Boot / Reset
    if (!handled && (current & 0x01)) {
        EGS_RAM->current_active_mask = 0x01;
        if (!(old_combined & 0x01) || change_detected) {
            egs52_update_near_c170_097634(0x100);
            egs52_register_sequence_097676(0x200);
            egs52_clear_status_c118();
        }
    }
}

/* 0x0e813e: Select Client 3 Operating Mask
 * Specific logic for Maybach/SBC/Transmission mode interaction.
 */
void egs52_select_client3_operating_mask(void) {
    uint16_t mask = 1;
    if (EGS_RAM->can_status_flags & 0x1) {
        mask = 0x800; // Special mode for Maybach / SBC
    }
    egs52_update_operating_masks(mask, 3);
}

/* 0x0d2008: MPC Pressure Clamp
 * Clamps target pressure to an upper limit if specific status bit is set.
 */
void egs52_clamp_mpc_target_pressure(void) {
    uint16_t target = EGS_RAM->mpc_pressure_target;
    EGS_RAM->mpc_pressure_current = target;
    
    // Status flag check from 0xFD4E bit 5
    if (EGS_RAM->system_status_flags & 0x20u) {
        uint16_t limit = *((uint16_t*)0xD480);
        if (target >= limit) {
            EGS_RAM->mpc_pressure_current = limit;
        }
    }
}
