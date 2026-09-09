/*
 * EGS51 A0215451432 - reconstructed output path, 2026-09-09.
 *
 * This is OUR reconstruction from the disassembly (bank0 unless noted), not the
 * Ghidra decompile, and it is written to be read next to the listing: addresses
 * are in the comments, names come from symbols.txt. Behaviour is transcribed;
 * where a meaning is inferred it is marked (?).
 *
 * Board (owner's traces, 2026-09-09):  L9341 OUT1 = Y5, OUT2 = Y4, OUT3 = Y3,
 * OUT4 = TCC (or its clamp).  Frame field <-> channel was derived from the ROM
 * independently and matched all four.
 *
 * STATUS: the owner cannot find SPI lines from the MCU to the L9341, and the
 * ROM never writes the Y5/Y3/TCC fields outside the actuator test, so "the
 * exchange below talks to the L9341" is UNCONFIRMED. It may talk to a latch
 * that feeds the L9341's inputs, or to another device. See README section 11
 * status flag. The P/N conclusion for Y4 does not depend on this.
 */

#include <stdint.h>

/* ---- SFRs of the SEC 51C810-N ------------------------------------------- */
__sfr __at(0xC6) SPI_DATA;      /* shift register                              */
__sfr __at(0xC7) SPI_CTRL;      /* bit7 = start; busy while set                */
__sbit __at(0x87) SPI_CS_N;     /* P0.7                                         */
__sbit __at(0xA2) FRAME_STROBE; /* P2.2                                         */
__sfr __at(0x98) WDT_SEQ;       /* sequence watchdog                            */
__sfr __at(0xDD) PWM_SETCLR;    /* 0x88 set-on-match, 0x08 clear-on-match       */
__sfr __at(0xF3) CMP_LO; __sfr __at(0xF4) CMP_HI;
__sfr __at(0xFA) CNT_LO; __sfr __at(0xFB) CNT_HI;

/* ---- XRAM ---------------------------------------------------------------- */
__xdata __at(0x0012) uint8_t l9341_frame[2];   /* [0]: OUT2<<4 | OUT1, [1]: OUT4<<4 | OUT3 */
__xdata __at(0x00FC) uint8_t spi_len;
__xdata __at(0x00FD) uint8_t spi_buf[2];       /* TX out, status back                 */
__xdata __at(0x000F) uint8_t l9341_status[2];
__xdata __at(0x000B) uint8_t temp_load_idx;    /* 0..4, FUN_1FC6                      */
__xdata __at(0x0014) uint8_t temp_idx;         /* 3/4/5, from ATF temp                */
__xdata __at(0x000C) uint8_t inrush_cnt[3];    /* OUT1, OUT3, OUT4                    */
__xdata __at(0x0021) uint8_t atf_temp;         /* paged input, page 9                 */
__xdata __at(0x0078) uint8_t fault_flags;      /* bit1: output fault                  */
__xdata __at(0x0334) uint8_t target_gear;      /* 1-5, 6=N, 7=R, 8=P                  */
__xdata __at(0x0316) uint8_t y4_np_timer;
__xdata __at(0x01C0) uint8_t flags_1c0;        /* bit5: N/P pulse done                */
__xdata __at(0x01C6) uint8_t flags_1c6;        /* bit3: threshold flag (FUN_BEC3)     */

/* ---- internal RAM ---------------------------------------------------------- */
__bit __at(0x08) out1_on;   /* Y5  */
__bit __at(0x09) out3_on;   /* Y3  */
__bit __at(0x0A) out4_on;   /* TCC */
__bit __at(0x0C) out1_was;  __bit __at(0x0D) out3_was;  __bit __at(0x0E) out4_was;
__data __at(0x36) uint8_t y4_demand;      /* 0..238; 0xFF idle; 0xFE/0xED test codes */
__data __at(0x56) uint8_t shift_active;
__data __at(0xB9) uint8_t current_gear;   /* 0 = N/P, 6 = R                       */

/* ---- calibration (bank0 ROM) --------------------------------------------- */
#define INRUSH_CODE        (*(const __code uint8_t *)0x088D)   /* 0x0F           */
#define HOLD_CODE(idx)     (*(const __code uint8_t *)(0x087F + (idx)))  /* 04 05 06 */
#define OUT4_INRUSH_CODE   (*(const __code uint8_t *)0x089C)   /* 0x10           */
#define OUT4_HOLD_CODE(idx)(*(const __code uint8_t *)(0x088E + (idx)))  /* C0 B0 A0 */
#define Y4_NP_PULSE_TICKS  (*(const __code uint8_t *)0xFE79)   /* 0x00 on this ROM */
extern const __code uint16_t y4_curve[8];  /* @0xFE01: 0,60,60,98,132,184,242,244 */

/* ================= spi_exchange  (0x068E) ================================ */
/* R7 == 1: 16-bit full-duplex exchange of spi_buf with the L9341.
 * The received bytes overwrite the transmitted ones. */
void spi_exchange_2(void)
{
    SPI_CTRL = 0x03;
    SPI_CS_N = 0;
    SPI_DATA = spi_buf[0]; SPI_CTRL |= 0x80; while (SPI_CTRL & 0x80) ;
    spi_buf[0] = SPI_DATA;
    SPI_DATA = spi_buf[1]; SPI_CTRL |= 0x80; while (SPI_CTRL & 0x80) ;
    spi_buf[1] = SPI_DATA;
    SPI_CS_N = 1;
}

/* ================= frame_compose  (0x0711) ================================ */
/* Builds the on/off channel codes. Each channel: when it turns on, the inrush
 * code for 3 calls, then a hold code chosen by ATF temperature (colder ->
 * higher). Note OUT2 (Y4) is NOT handled here - the PWM engine owns that
 * nibble - and the fault flag clears all three requests. */
void frame_compose(void)
{
    temp_idx = (atf_temp < 0x69) ? 5 : (atf_temp < 0x83) ? 4 : 3;
    if (fault_flags & 0x02) { out1_on = out3_on = out4_on = 0; }
    FRAME_STROBE = 0;

    /* OUT3 (Y3): low nibble of frame[1] */
    if (!out3_on) l9341_frame[1] = 0;
    else {
        if (!out3_was) inrush_cnt[1] = 3;
        l9341_frame[1] = inrush_cnt[1] ? INRUSH_CODE : HOLD_CODE(temp_idx);
    }
    WDT_SEQ = 0x40;
    /* OUT4 (TCC): high nibble of frame[1]; note the inverted code polarity */
    if (!out4_on) l9341_frame[1] &= 0x0F;
    else {
        if (!out4_was) inrush_cnt[2] = 3;
        l9341_frame[1] |= inrush_cnt[2] ? OUT4_INRUSH_CODE : OUT4_HOLD_CODE(temp_idx);
    }
    /* OUT1 (Y5): low nibble of frame[0] (the PWM engine ORs the OUT2 nibble in) */
    if (!out1_on) l9341_frame[0] = 0;
    else {
        if (!out1_was) inrush_cnt[0] = 3;
        l9341_frame[0] = inrush_cnt[0] ? INRUSH_CODE : HOLD_CODE(temp_idx);
    }
    FRAME_STROBE = 1;
    out1_was = out1_on; out3_was = out3_on; out4_was = out4_on;
}

/* ================= PWM engine for Y4 (OUT2)  (ISR 0x02AC, vector 0x0024) === */
/* Sketch of the part that matters. State XRAM 0x0007 (0/1/2) schedules on-time
 * and off-time inside a 0x1388-tick period; the next match is loaded relative
 * to the free-running counter; PWM_SETCLR picks set (0x88) or clear (0x08).
 * The OUT2 nibble carries a coarse level 15..11 by temp/load, 0 = off. */
void y4_pwm_engine_isr(void)
{
    l9341_frame[0] &= 0x0F;                       /* clear OUT2 nibble           */
    if (fault_flags & 0x02) y4_demand = 0;
    if (y4_demand == 0 || y4_demand < 0x0E) {      /* below 14: Y4 off            */
        y4_demand = 0;
        l9341_frame[0] &= 0x0F;
    } else if (y4_demand == 0xFF) {                /* idle code                   */
        l9341_frame[0] |= 0x10;
    } else {
        l9341_frame[0] |= (*(const __code uint8_t *)(0x088E + temp_load_idx)); /* F0..B0 */
        /* duty: 16-bit compare offset = y4_table_089D[y4_demand], period 0x1388 */
        /* CMP = CNT + delta; PWM_SETCLR = 0x88 / 0x08                            */
    }
    spi_buf[0] = l9341_frame[0]; spi_buf[1] = l9341_frame[1];
    spi_exchange_2();
    l9341_status[0] = spi_buf[0];
    l9341_status[1] = (spi_buf[1] & 0x3F) | (l9341_status[1] & 0xC0);
}

/* ================= y4_scheduler  (0xB8FF) / y4_shift_demand (0xB77B) ===== */
void y4_scheduler(void)
{
    if (!(fault_flags & 0x02) && /* ...several status bits clear... */
        current_gear > 2 && current_gear < 6 /* gears 3,4,5 */ ) {
        /* shift-time modulation: y4_shift_demand() -> y4_demand from the
         * 8-point curve at 0xFE01, argument {0x4E:0x4F} scaled through the
         * MDU with constants 0xFE62/0xFE64/0xFE66, clamped by ATF (XRAM 0x76). */
        y4_shift_demand();
    } else {
        shift_active = 0;
        y4_demand = 0;                             /* Y4 OFF: N, P, R, 1st, 2nd  */
    }
    y4_np_pulse();
}

/* ================= y4_np_pulse  (0x9F23) ================================= */
/* The N/P special case Ashcon described: while in N/P (current_gear == 0),
 * with flags_1c6.3 set and the pulse not yet done, drive Y4 at the top of
 * the curve (244) for Y4_NP_PULSE_TICKS, then mark done (flags_1c0.5).
 * On this calibration Y4_NP_PULSE_TICKS = 0, so the pulse never runs. */
void y4_np_pulse(void)
{
    if (current_gear == 0 && (flags_1c6 & 0x08) && !(flags_1c0 & 0x20)) {
        if (y4_np_timer != 0) { y4_demand = y4_curve[7]; return; }   /* 244 */
        flags_1c0 |= 0x20;
        return;
    }
    y4_np_timer = Y4_NP_PULSE_TICKS;        /* reloaded whenever not in N/P (?)   */
}

/* ================= actuator_test  (0x6DE5) =============================== */
/* Workshop actuation test (entered from the self-test sequencer when
 * XRAM 0x1B7 == 2): energise OUT1, OUT3, OUT4 in turn for 50 ticks each with
 * Y4 demand code 0xFE, then release with code 0xED. This is the ONLY place in
 * the visible code that sets out1_on/out3_on/out4_on. */

/* ================= gear_map  (bank1 0x2B80) ============================== */
void gear_map(void)
{
    switch (target_gear) {
    case 8: current_gear = 0; /* P */ break;
    case 6: current_gear = 0; /* N */ break;
    case 7: current_gear = 6; /* R */ break;
    default: current_gear = *(__xdata uint8_t *)0x0223; /* actual gear */ break;
    }
}
