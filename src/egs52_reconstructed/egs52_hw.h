#ifndef EGS52_HW_RECON_H
#define EGS52_HW_RECON_H

#include <stdint.h>

/* EGS52 Memory-Mapped Registers (SFRs) */
#define PSW     (*(volatile uint16_t*)0xFF10)
#define DPP0    (*(volatile uint16_t*)0xFE00)
#define DPP1    (*(volatile uint16_t*)0xFE02)
#define DPP2    (*(volatile uint16_t*)0xFE04)
#define DPP3    (*(volatile uint16_t*)0xFE06)
#define MDC     (*(volatile uint16_t*)0xFF0E)
#define MDH     (*(volatile uint16_t*)0xFE0C)
#define MDL     (*(volatile uint16_t*)0xFE0E)

/* Core Near-RAM Structures */
typedef struct {
    uint8_t  padding_c000[0x6C];
    uint16_t unknown_c06c;            // 0xC06C
    uint16_t operating_mask_combined; // 0xC06E: Combined bitmask of all client masks
    uint16_t current_active_mask;     // 0xC070: Mask of the highest priority active mode
    uint16_t client_masks[8];         // 0xC072: Bitmasks for 8 different clients/modes
    uint8_t  padding_c082[2];
    uint16_t operating_mask_scratch;  // 0xC084: Temporary during mask update
    // 0xC100 variables
    uint8_t  padding_c086[0x7A];
    uint16_t unknown_c100;            // 0xC100
    uint8_t  padding_c102[2];
    uint8_t  unknown_c104;            // 0xC104
    uint8_t  unknown_c105;            // 0xC105
    // 0xC170 Variables
    uint8_t  padding_c106[0x6A];
    uint16_t unknown_c170;            // 0xC170
    uint16_t unknown_c172;            // 0xC172
    uint8_t  padding_c174[0x238];
    uint8_t  fault_status[128];       // 0xC3AC: Fault status bytes
    uint8_t  padding_c42c[0x3A];
    uint16_t fault_bitmap[8];         // 0xC42C
    
    // Torque and Pressure Control Variables
    uint8_t  padding_d400[0x8];
    uint16_t mpc_total_pressure;      // 0xD408
    uint8_t  padding_d40a[0x7E];
    uint16_t mpc_pressure_current;    // 0xD488
    uint16_t mpc_pressure_target;     // 0xD48A
    uint8_t  padding_d48c[0x2];
    uint16_t mpc_working_pressure;    // 0xD48E
    uint16_t spc_reduction_factor;    // 0xD490
    uint16_t pressure_scale_factor;   // 0xD492
    
    // Shift State Machine
    uint8_t  padding_d500[0x64];
    uint16_t shift_state_index;       // 0xD564
    uint8_t  padding_d566[2];
    uint16_t current_gear;            // 0xD568
    uint16_t target_gear;             // 0xD56A
    uint16_t unknown_d56c;            // 0xD56C
    
    // CAN/System flags
    uint8_t  padding_fd00[0x4E];      // 0xFD00
    uint16_t system_status_flags;     // 0xFD4E
    uint8_t  padding_fd50[0x12];
    uint16_t can_status_flags;        // 0xFD62
} Egs52SystemState;

extern Egs52SystemState* const EGS_RAM;

#endif
