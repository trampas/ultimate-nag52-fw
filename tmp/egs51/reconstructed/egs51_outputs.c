/*
 * EGS51 A0215451432 - reconstructed output path, 2026-09-09 (revised late 09-09).
 *
 * OUR reconstruction from the disassembly, written to be read next to the
 * listing: addresses in comments, names from symbols.txt, "bank1:" where the
 * code is in the second bank. Behaviour is transcribed; inferences are marked (?).
 *
 * Confirmed against: the ST L9341 datasheet (tmp/datasheet/) - 16-bit SPI word,
 * MSB first, bits 15-12/11-8/7-4/3-0 = channel 4/3/2/1 duty code, Fig. 5 duty
 * table; and the owner's board traces - OUT1 = Y5, OUT2 = Y4, OUT3 = Y3,
 * OUT4 = TCC, SDI from MCU pin 9 (top-left count) via 1 kOhm.
 */

#include <stdint.h>

/* ---- SFRs of the SEC 51C810-N ------------------------------------------- */
__sfr  __at(0xC6) SPI_DATA;      /* shift register to the L9341                 */
__sfr  __at(0xC7) SPI_CTRL;      /* bit7 = start; busy while set                */
__sbit __at(0x87) SPI_CS_N;      /* P0.7                                         */
__sbit __at(0xA2) FRAME_STROBE;  /* P2.2                                         */
__sfr  __at(0x98) WDT_SEQ;       /* sequence watchdog: each task stamps its byte */

/* ---- XRAM (on-chip) -------------------------------------------------------- */
__xdata __at(0x0012) uint8_t l9341_frame[2]; /* [0] = bits 15-8: TCC<<4 | Y3, [1] = bits 7-0: Y4<<4 | Y5 */
__xdata __at(0x00FD) uint8_t spi_buf[2];     /* TX out, Fig. 7 status back            */
__xdata __at(0x000F) uint8_t l9341_status[2];/* status copy; [1] = 4 channels x 2 bits */
__xdata __at(0x000B) uint8_t temp_load_idx;  /* 0..4 (FUN_1FC6)                         */
__xdata __at(0x0014) uint8_t temp_idx;       /* 3/4/5 from ATF temp (FUN_0711)          */
__xdata __at(0x000C) uint8_t inrush_cnt[3];  /* Y3, Y5, Y4 : 3-period inrush countdown  */
__xdata __at(0x0021) uint8_t atf_temp;       /* paged input, page 9                     */
__xdata __at(0x0078) uint8_t fault_flags;    /* bit1: output fault                      */
__xdata __at(0x01B3) uint8_t output_inhibit; /* non-zero: output stage skipped          */
__xdata __at(0x0334) uint8_t target_gear;    /* 1-5, 6 = N, 7 = R, 8 = P                */
__xdata __at(0x01BD) uint8_t flags_1bd;      /* bit0: engine-speed-shaped threshold flag (FUN_913D) */
__xdata __at(0x01C2) uint8_t flags_1c2;      /* bit0: (?) gates the N/P idle state      */

/* ---- internal RAM ---------------------------------------------------------- */
__bit  __at(0x08) y3_on;        /* -> frame[0] low nibble  (OUT3)              */
__bit  __at(0x09) y5_on;        /* -> frame[1] low nibble  (OUT1)              */
__bit  __at(0x0A) y4_on;        /* -> frame[1] high nibble (OUT2)              */
__bit  __at(0x0C) y3_was; __bit __at(0x0D) y5_was; __bit __at(0x0E) y4_was;
__data __at(0x36) uint8_t tcc_demand;   /* 0..238; <14 off; 0xFF idle; 0xFE/0xED test codes */
__data __at(0x95) uint8_t sol_pattern;  /* bit0 Y3, bit1 Y5, bit2 Y4 (bits 3-6: other flags) */
__data __at(0xAA) uint8_t shift_phase;  /* 0 = start, 4 = end                          */
__data __at(0xAC) uint8_t shift_index;  /* 1=1-2 2=2-3 3=3-4 4=4-5 5=2-1 6=3-2 7=4-3 8=5-4 */
__data __at(0xB4) uint8_t engage_state; /* 0..8; 8 = N/P idle                          */
__data __at(0xB0) uint8_t t_b0; __data __at(0xB1) uint8_t t_b1; __data __at(0xB2) uint8_t t_b2;
__data __at(0xB3) uint8_t gear_b3;      /* gear value used by the state-2 branches (?) */
__data __at(0xB9) uint8_t current_gear; /* 0 = N/P, 6 = R, 1-5 forward                  */
__data __at(0xAB) uint8_t gear_ab;      /* gear-shaped, from FUN_7331 (?)               */

/* ---- calibration (bank0 ROM unless noted) ---------------------------------- */
#define INRUSH_CODE          (*(const __code uint8_t *)0x088D)  /* 0x0F  = 15/16 on (ch 1,3) */
#define HOLD_CODE(i)         (*(const __code uint8_t *)(0x087F + (i)))  /* 04 05 06 = 4..6/16 */
#define Y4_INRUSH_CODE       (*(const __code uint8_t *)0x089C)  /* 0x10: ch2 code 1 = 15/16 */
#define Y4_HOLD_CODE(i)      (*(const __code uint8_t *)(0x088E + (i)))  /* C0 B0 A0: 4..6/16 */
#define B1_NP_IDLE_TIMER     (*(const __code uint8_t *)0xFFA1)  /* bank1: 80              */

/* ================= spi_exchange  (0x068E, R7 == 1) ======================= */
void spi_exchange_2(void)
{
    SPI_CTRL = 0x03;
    SPI_CS_N = 0;
    SPI_DATA = spi_buf[0]; SPI_CTRL |= 0x80; while (SPI_CTRL & 0x80) ;
    spi_buf[0] = SPI_DATA;                       /* Fig. 7 bits 15-8 come back  */
    SPI_DATA = spi_buf[1]; SPI_CTRL |= 0x80; while (SPI_CTRL & 0x80) ;
    spi_buf[1] = SPI_DATA;                       /* bits 7-0                     */
    SPI_CS_N = 1;                                /* rising CS latches the word   */
}

/* ================= output stage  (0x6BC3-0x6BE2, in the main loop 0x675E) == */
/* Every cycle after the scheduler (0x6E6A): shift the pattern byte into the
 * three request bits. Ghidra prints these as MOV 0x08,CY etc. */
void output_stage(void)
{
    if (output_inhibit) { WDT_SEQ = 0x04; WDT_SEQ = 0xF7; WDT_SEQ = 0x10; WDT_SEQ = 0xDF; return; }
    y3_on = sol_pattern & 0x01;
    y5_on = (sol_pattern >> 1) & 0x01;
    y4_on = (sol_pattern >> 2) & 0x01;
}

/* ================= frame_compose  (0x0711) ================================ */
/* Peak-and-hold for the three shift solenoids: inrush for 3 PWM periods when
 * a channel turns on, then a hold code by ATF temperature (colder -> higher).
 * With the Fig. 5 table all three come out identical: 15/16 then 4-6/16.
 * The TCC nibble (frame[0] high) is owned by the PWM engine below. */
void frame_compose(void)
{
    temp_idx = (atf_temp < 0x69) ? 5 : (atf_temp < 0x83) ? 4 : 3;
    if (fault_flags & 0x02) { y3_on = y5_on = y4_on = 0; }
    FRAME_STROBE = 0;

    if (!y5_on) l9341_frame[1] = 0;                              /* OUT1 = Y5 */
    else { if (!y5_was) inrush_cnt[1] = 3;
           l9341_frame[1] = inrush_cnt[1] ? INRUSH_CODE : HOLD_CODE(temp_idx); }
    WDT_SEQ = 0x40;
    if (!y4_on) l9341_frame[1] &= 0x0F;                          /* OUT2 = Y4 */
    else { if (!y4_was) inrush_cnt[2] = 3;
           l9341_frame[1] |= inrush_cnt[2] ? Y4_INRUSH_CODE : Y4_HOLD_CODE(temp_idx); }
    if (!y3_on) l9341_frame[0] = 0;                              /* OUT3 = Y3 */
    else { if (!y3_was) inrush_cnt[0] = 3;
           l9341_frame[0] = inrush_cnt[0] ? INRUSH_CODE : HOLD_CODE(temp_idx); }
    FRAME_STROBE = 1;
    y3_was = y3_on; y5_was = y5_on; y4_was = y4_on;
}

/* ================= TCC PWM engine  (ISR 0x02AC, vector 0x0024) ============ */
/* Torque converter lockup on OUT4. State XRAM 0x0007 schedules on/off inside a
 * 0x1388-tick period; next match = {FB:FA} + delta (table 0x089D indexed by the
 * demand); 0xDD = 0x88 set-on-match / 0x08 clear-on-match. The OUT4 nibble gets
 * a coarse level by temp x load; code 0 = off below demand 14. FUN_B8FF only
 * runs the shift-time modulation (FUN_B77B, 8-point curve at 0xFE01) while the
 * current gear is 3-5 and a shift is active - lockup is off in N/P/R/1st/2nd. */
void tcc_engine_isr(void)
{
    l9341_frame[0] &= 0x0F;
    if (fault_flags & 0x02) tcc_demand = 0;
    if (tcc_demand < 0x0E)        { tcc_demand = 0; }                            /* off  */
    else if (tcc_demand == 0xFF)  { l9341_frame[0] |= 0x10; }                    /* idle */
    else                          { l9341_frame[0] |= *(const __code uint8_t *)(0x088E + temp_load_idx); }
    spi_buf[0] = l9341_frame[0]; spi_buf[1] = l9341_frame[1];
    spi_exchange_2();
    l9341_status[0] = spi_buf[0];
    l9341_status[1] = (spi_buf[1] & 0x3F) | (l9341_status[1] & 0xC0);
}

/* ================= shift solenoid select  (bank1 0x23E9, in FUN_2344) ===== */
/* At shift phase 0, energise the solenoid of the circuit being shifted. This
 * is the 722.6 valve assignment: Y3 = 1-2 and 4-5, Y5 = 2-3, Y4 = 3-4. */
void shift_solenoid_select(void)
{
    if (shift_phase != 0) return;
    switch (shift_index) {
    case 1: case 4: case 5: case 8: sol_pattern |= 0x01; break;   /* Y3 */
    case 2: case 6:                 sol_pattern |= 0x02; break;   /* Y5 */
    case 3: case 7:                 sol_pattern |= 0x04; break;   /* Y4 */
    }
}
/* bank1 0x29E3: at shift phase 4 (end), sol_pattern &= 0xF8 - all three off.
 * The shift solenoids are momentary during shifts, as in nag52. */

/* ================= engagement state machine  (bank1 0x5BB6) ============== */
/* Sub-state engage_state 0..8, dispatched via the LJMP table at 0x5C66. Only
 * the pattern-relevant parts are transcribed; the timed steps use tables at
 * bank1 0xFF78/0xFF7B/0xFF87 through 0x1061 (temperature interpolation). */
void engagement_state_machine(void)
{
    /* prologue 0x5C1A: enter the N/P idle state */
    if (target_gear == 6 /* N */ && /* 0x94.4 (?) */ 1) { t_b0 = B1_NP_IDLE_TIMER; engage_state = 8; }
    if (flags_1c2 & 0x01)                                { t_b0 = B1_NP_IDLE_TIMER; engage_state = 8; }
    /* (decompile) also: (flags_1bd & 1) && target_gear > 6  -> state 8 */
    if (engage_state > 8) return;

    switch (engage_state) {
    case 8:                                   /* 0x60A1: N/P IDLE                    */
        sol_pattern &= ~0x01;                 /*   Y3 off                            */
        sol_pattern |=  0x02;                 /*   Y5 ON                             */
        sol_pattern |=  0x04;                 /*   Y4 ON  -> the hydraulic-neutral pair */
        if (!(flags_1c2 & 0x01)) return;
        if (t_b0) return;
        /* ... selector/speed checks against ROM 0xFFA2 (50), 0xFFAD/0xFFAE ... */
        /* 0x612E / 0x6180: leaving N/P for a gear                                  */
        sol_pattern &= ~0x02;                 /*   Y5 off                            */
        sol_pattern &= ~0x04;                 /*   Y4 off - both released FIRST      */
        engage_state = 0; shift_phase = 0;    /*   restart the engagement sequence   */
        return;

    case 0:                                   /* 0x5C81                              */
        /* special case: y4_on && shift_index == 7 (4-3) -> timer from ROM 0xFF9F   */
        t_b0 = 0; engage_state++; return;

    case 1:                                   /* 0x5CB7                              */
        /* timers from the 0xFF87 table; normal path 0x5CF8:                         */
        shift_index = 1;                      /*   1-2                               */
        sol_pattern &= ~0x04;                 /*   Y4 off                            */
        /* alternate path 0x5D35 under gear_b3 >= 6: sol_pattern |= 0x04 (Y4 on) */
        engage_state++; return;

    case 2:                                   /* 0x5D3C                              */
        if (t_b0) return;
        /* 0x5D7D / 0x5DA9: sol_pattern |= 0x01 (Y3 on) from a ROM 0xFF81 compare   */
        if (gear_b3 >= 6) {
            if ((flags_1bd & 0x01) && target_gear == 7 /* R */) {
                sol_pattern |= 0x04;          /*   0x5E1F: Y4 ON for Reverse          */
                engage_state = 6; return;
            }
            engage_state = 7; return;
        }
        if (gear_b3 >= 4)      { sol_pattern |= 0x02; return; }              /* Y5     */
        if (gear_b3 == 3)      { if (!y3_on && !y4_on) sol_pattern |= 0x06; return; } /* Y5+Y4 */
        if (gear_b3 < 2 && !y3_on && gear_ab >= 3) {
            sol_pattern |= 0x02; sol_pattern &= ~0x04;                       /* Y5 on, Y4 off */
            shift_index = 2;                  /*   2-3                               */
            engage_state++; return;
        }
        /* 0x5E8F: R or forward -> t_b0 = t_b1; state 7; N/P -> state 1              */
        return;

    /* states 3, 4, 5, 7: timed fill/apply/hold steps, each ending in a pattern
     * update (0x5F24, 0x5F81, 0x5F93, 0x5FDE, 0x6007, 0x608C); state 6 (0x6021)
     * waits on flags_1bd before going to state 7. Not transcribed. */
    default: return;
    }
}

/* ================= actuator test  (0x6DE5) =============================== */
/* KWP actuator test (XRAM 0x1B7 == 2): energise Y3, Y5, Y4 in turn for 50 ticks
 * each with TCC demand code 0xFE, then release with 0xED. */

/* ================= gear_map  (bank1 0x2B80) ============================== */
void gear_map(void)
{
    switch (target_gear) {
    case 8: current_gear = 0; break;  /* P */
    case 6: current_gear = 0; break;  /* N */
    case 7: current_gear = 6; break;  /* R */
    default: current_gear = *(__xdata uint8_t *)0x0223; break;
    }
}
