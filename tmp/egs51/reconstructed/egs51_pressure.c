/*
 * EGS51 A0215451432 - reconstructed pressure path, current loops and engagement
 * machine, 2026-09-09 (pass 3). Companion to egs51_outputs.c (solenoid pattern path).
 *
 * OUR reconstruction from the disassembly. Addresses in comments; names from
 * symbols.txt; "bank1:" where the code lives in the second bank. Transcribed
 * behaviour is stated flatly, inferences are marked (?). Units: pressures in
 * mbar as the calibration stores them; temperatures in the ROM's own encoding,
 * which is (degC + 50) - see atf_temperature() for the evidence.
 *
 * Reading order: mdu helpers -> calibration pointers -> temperature -> current
 * loop -> pressure_to_demand -> the engagement state machine that feeds it.
 */

#include <stdint.h>

/* ======================================================================
 * 1. The MDU and the library helpers (common area, identical in both banks)
 * ====================================================================== */

/* The six "reserved" SFRs are an 80C517-style multiply/divide unit. The
 * register ORDER of the writes selects the operation, exactly as on the
 * 80C517A datasheet; the two LCALLs to a bare RET are the required wait. */
__sfr __at(0xA5) MD0; __sfr __at(0xA6) MD1; __sfr __at(0xA7) MD2;
__sfr __at(0xAD) MD3; __sfr __at(0xAE) MD4; __sfr __at(0xAF) MD5;

/* 0x0BCC: (a*b)/c unsigned. 146 call sites in bank1, 96 in bank0. */
uint16_t mdu_muldiv_u16(uint16_t a, uint16_t b, uint16_t c)
{
    MD0 = a; MD4 = b; MD1 = a >> 8; MD5 = b >> 8;   /* MD0,MD4,MD1,MD5 = 16x16 multiply */
    /* LCALL 0x1DCA (RET): 4-cycle pad */
    uint32_t p = MD0 | (MD1 << 8) | ((uint32_t)MD2 << 16) | ((uint32_t)MD3 << 24);
    MD0 = p; MD1 = p >> 8; MD2 = p >> 16; MD3 = p >> 24; MD4 = c; MD5 = c >> 8; /* MD0..MD5 = 32/16 divide */
    /* LCALL 0x1DCB (4 NOP + RET): 8-cycle pad */
    return MD0 | (MD1 << 8);
}
/* 0x0C20: same, signed - takes |a|,|b|,|c|, counts sign bits in R0, negates if odd. */
int16_t  mdu_muldiv_s16(int16_t a, int16_t b, int16_t c);
/* 0x0C0C: 32-bit product only (R4:R5:R6:R7). 0x0C7B: 32-bit / INTMEM{0x75:0x76}. */

/* 0x1061: first-order lag with an integer divisor. Used for every pressure ramp.
 * With n counting DOWN each cycle (INTMEM 0xB1 is decremented by timers_tick)
 * this is a linear ramp that lands exactly on target when n reaches 1. */
uint16_t lag_div(uint16_t cur, uint16_t target, uint8_t n)
{
    if (n == 0) return target;
    int16_t d = target - cur;                       /* MD0,MD1,MD4,MD5 = 16/16 divide */
    return cur + d / n;
}

/* 0x1412: two-point linear interpolation, clamped. The descriptor is five u16
 * VALUES in internal RAM (the caller copies them out of ROM), R7 = its address. */
struct lerp1d { uint16_t y0, y1, x0, x1, x; };
uint16_t lerp1d_intmem(const struct lerp1d *d)
{
    if (d->x >= d->x1) return d->y1;
    if (d->x <  d->x0) return d->y0;
    return d->y0 + (int32_t)(d->y1 - d->y0) * (d->x - d->x0) / (d->x1 - d->x0);
}

/* 0x14F3: bilinear 2-D map. The descriptor lives in ROM (R6:R7 points at it):
 *   u8 x_intmem_addr, u8 nx, u8 y_intmem_addr, u8 ny, u16* x_axis, u16* y_axis, u16* z
 * The x and y INPUTS are read from internal RAM at the addresses in the
 * descriptor (every descriptor in this ROM uses 0xA5:0xA6 and 0xA7:0xA8, so the
 * caller loads INTMEM 0xA5..0xA8 first). Axes are u8 in this ROM (65 maps) except
 * the pcs map (u16). 0x1904 is the variant with u8 z. */
struct map2d { uint8_t xaddr, nx, yaddr, ny; const uint8_t *xax, *yax; const void *z; };
uint16_t map2d_rom(const struct map2d *d);   /* bilinear, clamped on both axes */

/* ======================================================================
 * 2. Calibration pointers (bank1 FUN_20BC, at init)
 * ====================================================================== */

/* Two coding bytes select, per block, one of up to three variants through pointer
 * tables in bank1 0xE882..0xEA62 (see `egs51tool.py calsets`). 0xFFFF = not
 * populated (R7 |= 1, a coding fault). On this car the mech/hydr nibble is 2:
 * mech = 0xF0DA, hydr = 0xF17A, byte-identical to what the TCU reports. */
__xdata __at(0x017B) uint8_t coding_a;   /* lo nibble -> 0x3B2/0x3B4; hi -> 0x3BC..0x3C4 */
__xdata __at(0x017C) uint8_t coding_b;   /* lo nibble -> 0x3D0/0x3CC/0x3D2; hi -> 0x3D4 (mech), 0x3CE (hydr) */

/* ROM layout of the hydr block (base = XRAM 0x3CE:0x3CF = 0xF17A on this car).
 * nag52's HydraulicCalibration was repacked from these values into the EGS52
 * layout; the fields agree but the offsets do not (note the 3-byte gap at +0x53). */
struct __attribute__((packed)) hydr_block {
    uint8_t  id;                              /* +0x00 = 3 */
    uint16_t p_multi_1;                       /* +0x01 = 431   gear 1 and R */
    uint16_t p_multi_other;                   /* +0x03 = 592 */
    uint16_t lp_reg_spring_pressure;          /* +0x05 = 1828 */
    uint16_t overlap_circuit_factor_spc[8];   /* +0x07 */
    uint16_t overlap_circuit_factor_mpc[8];   /* +0x17 */
    int16_t  overlap_circuit_spring_pressure[8]; /* +0x27 */
    uint16_t shift_reg_spring_pressure;       /* +0x37 = 601 */
    uint16_t shift_spc_gain[8];               /* +0x39 */
    uint16_t unused_49[3];                    /* +0x49 = 0,0,0 */
    uint16_t min_mpc_pressure;                /* +0x4F = 500 */
    uint8_t  filter_factor;                   /* +0x51 = 15 */
    uint8_t  mpc_flush_temp_threshold;        /* +0x52 = 75  -> 25 degC in the ROM's encoding (!) */
    uint8_t  gap_53[3];                       /* +0x53 = 0,0,0 */
    uint16_t mpc_no_flush_time;               /* +0x56 = 30000 */
    uint16_t mpc_flush_time;                  /* +0x58 = 50 */
    uint16_t unk_5a[3];                       /* +0x5A = 0,0,0 */
    /* +0x60: next block (XRAM 0x3B2 points here on the same variant): 0x001E, 0x1E, 0x64 ... */
};
/* mech block (base = XRAM 0x3D4:0x3D5 = 0xF0DA): +0 id, +1 friction_map[8 gears][6 clutches],
 * +0x61 max_torque_on_clutch[4], +0x69 max_torque_off_clutch[4], +0x71 release_spring_pressure[6],
 * +0x7D (10 bytes, ?), +0x87 strongest_loaded_clutch_idx[8]. Total 0xA0, hydr follows. */

/* Descriptor lists selected by coding_b.lo, each four maps (one per upshift index):
 *   XRAM 0x3D0 -> 6x8 u8 maps (x = 6 torque-ish points, y = 8), family A
 *   XRAM 0x3D2 -> 6x8 u8 maps, family B
 *   XRAM 0x3CC -> 3x2 u8 maps (downshifts)
 * Elsewhere: 6x10 maps (4 per variant), 3x4 maps (4 per variant), the 5x4 map at
 * XRAM 0x3C8 (gear index x ATF temperature) and a 4x4 map at 0x3C2/0x3B4.
 * None of their VALUES match nag52's SM00 arrays; the geometries match nag52's
 * trq_adder (6x8 up, 3x4 down) and momentum (6x10 up, 3x2 down) tables. */

/* ======================================================================
 * 3. Temperature
 * ====================================================================== */

/* ATF temperature is XRAM 0x76. The encoding looks to be degC + 50 (README 13.6 has the
 * full argument; it is strong but not airtight, so nothing was changed in nag52 for it).
 *   - source: paged input page 0xF read as 16 bits in FUN_206E, summed over 8 samples in
 *     FUN_2132, then XRAM 0x17 = ((mean8 * 177) >> 8 - 52) * 2 - a straight-line fit, so a
 *     KTY-class sensor, no resistance table anywhere in the ROM. Full scale spans about
 *     -50 .. +198 in degC terms, i.e. it bottoms out at 0 and would go negative below:
 *     the shape of an offset encoding.
 *   - open/short detection against 0x33/0x34 -> XRAM 0x15 bit 7 -> the substitute XRAM 0x97
 *     is used instead of the measurement;
 *   - the substitute comes from CAN (FUN_47A0): read the object at register 0xBA = 0xA8,
 *     then XRAM 0x97 = byte + 10, or the sentinel 0xE1 when the byte is >= 0xD8. Every MB
 *     engine temperature byte (T_MOT, T_OEL - both in MS_608) is degC + 40, so "+10" makes
 *     a degC + 50 value whichever byte it is. (?) which CAN object 0xA8 is has NOT been
 *     pinned: the acceptance table at 0xBA = 0x57 gives the IDs, not the window mapping.
 *   - boot default ROM[0xFF01] = 130 -> 30 degC.
 * If so, every threshold and axis in this ROM is degC + 50: hydr.mpc_flush_temp_threshold
 * 75 -> 25 degC; pcs_map_y {25,70,110,200} -> {-25,20,60,150}; the engagement-time axis
 * {20,70} -> {-30,+20}; the 5x4 fill map axis {30,55,75,110} -> {-20,5,25,60}; the solenoid
 * hold-current thresholds {70,170} -> {20,120}. nag52 reads the same numbers as degC.
 * XRAM 0x21 (page 9, 8-bit) is a SECOND temperature-shaped input used only by the on/off
 * solenoid hold-current index - most likely the ECU/driver temperature, not the ATF.
 * Section 10's "ATF = page 9" is withdrawn. */
__xdata __at(0x0076) uint8_t atf_temp;

/* ======================================================================
 * 4. The current loops (bank0, common stub) - MPC and SPC
 * ====================================================================== */

/* Vector 11 (0x0021) -> 0x01FD. Period: next compare {ED:EC} = {FB:FA} + ROM[0x0B3A:0x0B3B]
 * = 1250 counter ticks. Feedback comes from the paged input window (pages 1 and 3:
 * the two AD22057 current-sense amplifiers), scaled by bank1 FUN_5ACA (thunk 0x0B76)
 * with per-channel constants XRAM 0x188/0x18A:0x18B and 0x189/0x18C:0x18D (?: EEPROM
 * trims). Demand and feedback are in the same unit: 4.5 mA per count (255 = 1147 mA). */
__data __at(0x37) uint8_t  i_demand_mpc;    /* written at bank1 0x3198 = pressure_to_demand(P_MPC) */
__data __at(0x35) uint8_t  i_demand_spc;    /* written at bank1 0x318F = pressure_to_demand(P_SPC_SOL) */
__data __at(0x42) uint8_t  i_fb_mpc;        /* page 1 */
__data __at(0x43) uint8_t  i_fb_spc;        /* page 3 */
__data __at(0x31) uint16_t pi_int_mpc;      /* 0x31:0x32 */
__data __at(0x33) uint16_t pi_int_spc;      /* 0x33:0x34 */
__sfr  __at(0xD9) PWM_MPC_DUTY;             /* MCU pin 4 -> RY power stage -> MPC (owner's trace) */
__sfr  __at(0xDA) PWM_SPC_DUTY;             /* MCU pin 5 -> RY power stage -> SPC */
#define PI_KP  (*(const __code uint8_t *)0x0B38)   /* 4 */
#define PI_KI  (*(const __code uint8_t *)0x0B39)   /* 2 */
#define PI_INT_INIT_HI (*(const __code uint8_t *)0x0B3C)  /* 0x80: integrator rests at 0x8000 */

/* 0x3F5C, one channel. R5 = |e|, F0 = sign(e), R0/R1 -> integrator, DPTR = gains. */
static uint8_t pi_step(uint16_t *integ, uint8_t e_abs, uint8_t e_neg)
{
    uint16_t p = PI_KP * e_abs;
    uint16_t i = PI_KI * e_abs;
    if (!e_neg) { uint32_t s = *integ + i; *integ = s > 0xFFFF ? 0xFFFF : s; }
    else        { *integ = (*integ < i) ? 0 : *integ - i; }
    /* output = high byte of (I - 0x8000 +/- P), saturated at 0 / 0xFF */
    int32_t u = (int32_t)*integ - 0x8000 + (e_neg ? -(int32_t)p : (int32_t)p);
    if (u < 0) u = 0; if (u > 0xFFFF) u = 0xFFFF;
    return (uint8_t)(u >> 8);
}

void ISR_current_loop(void)                          /* 0x01FD .. 0x02AB */
{
    /* {ED:EC} = {FB:FA} + 1250 */
    i_fb_mpc = fb_scale(page_read(1), /*0x188, 0x18A:0x18B*/);   /* thunk 0x0B76 -> bank1 FUN_5ACA */
    i_fb_spc = fb_scale(page_read(3), /*0x189, 0x18C:0x18D*/);
    if (fault_flags & 0x02) { i_demand_mpc = 0; i_demand_spc = 0; }       /* XRAM 0x78 bit 1 */
    if (i_demand_mpc == 0) pi_int_mpc = PI_INT_INIT_HI << 8;
    if (i_demand_spc == 0) pi_int_spc = PI_INT_INIT_HI << 8;
    /* LCALL 0x0B7B -> bank0 0x3EEC: */
    {
        int16_t e = i_demand_mpc - i_fb_mpc;
        uint8_t u = i_demand_mpc ? pi_step(&pi_int_mpc, e < 0 ? -e : e, e < 0) : 0;
        xram[0x105] = u;  PWM_MPC_DUTY = 0xFF - u;
        e = i_demand_spc - i_fb_spc;
        u = i_demand_spc ? pi_step(&pi_int_spc, e < 0 ? -e : e, e < 0) : 0;
        xram[0x102] = u;  PWM_SPC_DUTY = 0xFF - u;
    }
    /* then a stuck-counter check on SFR 0xF8 & 0x0F vs XRAM 0x101 -> XRAM 0x03 */
}

/* ======================================================================
 * 5. Pressure -> current demand (bank1 FUN_D76E), and the pressure words
 * ====================================================================== */

/* The three words the state machines write (internal RAM, overlaid per machine): */
__data __at(0x44) uint16_t P_MPC;        /* mbar; -> i_demand_mpc */
__data __at(0x46) uint16_t P_CLUTCH;     /* mbar; target for the engaging circuit */
__data __at(0x48) uint16_t P_SPC_SOL;    /* mbar; = spc_from_clutch(P_CLUTCH) -> i_demand_spc */

/* bank1 0x7093. R7 = shift index - 1, R4:R5 = clutch pressure. Adds a torque-shaped
 * term (20 x XRAM 0x167 / 0x168 / 0x174 chosen by shift phase INTMEM 0xB6 and index),
 * clamps to P_SPC_MAX (XRAM 0x273:0x274 = (x * shift_spc_gain[idx]) / 1000, set in
 * shift_setup 0x2BB2), scales by shift_spc_gain[idx] / 1000 and adds
 * shift_reg_spring_pressure. This is nag52's "SPC solenoid pressure from clutch
 * pressure" relation with the OEM's own terms. */
uint16_t spc_from_clutch(uint8_t idx, uint16_t p_clutch)
{
    int16_t torque_term = 20 * (int8_t)xram[(shift_phase == 6) ? 0x174 : (idx == 0 || idx == 4) ? 0x167 : (idx == 6) ? 0x174 : 0x168];
    int32_t p = torque_term + p_clutch;  if (p < 0) p = 0;
    if (p > P_SPC_MAX) p = P_SPC_MAX;
    return HYDR->shift_reg_spring_pressure + (uint32_t)p * HYDR->shift_spc_gain[idx] / 1000;
}

/* bank1 0xD76E: mbar -> demand byte. Called twice per cycle at 0x3188-0x3198. */
uint8_t pressure_to_demand(uint16_t p /* R6:R7 */)
{
    uint16_t mult = (current_gear == 1 || current_gear == 6) ? HYDR->p_multi_1 : HYDR->p_multi_other;
    /* when a shift is in progress (INTMEM 0xB6 != 0) mult comes from a 1-D lerp over
     * ROM 0xFFE4.. instead (per shift index) */
    uint16_t p_line = (uint32_t)mult * (HYDR->lp_reg_spring_pressure + P_MPC) / 1000;
    p_line = p_line + 1000 - xram16(0x65);          /* offset terms, clamped at 0 (?) */
    /* inlet pressure map: input 3180..8820 -> output 2690..8330 (ROM 0xFFD6..0xFFDD) */
    uint16_t inlet = lerp1d(p_line, 3180, 8820, 2690, 8330);
    inlet = (uint32_t)(8330 - inlet) * ROM[0xFFD3] / 1000;
    if (p < inlet) p = p + ROM16(0xFFD4) /* offset */ ...;   /* see listing 0xD92E-0xD96F */
    else           p = P_LINE_BASE;                           /* XRAM 0x329:0x32A */
    /* pcs map: descriptor bank1 0xEA82 = {x@0xA5, 7, y@0xA7, 4, 0xFF21, 0xFF2F, 0xFF37}
     * x = pressure (u16 axis, 7 points), y = ATF temperature (degC+50: 25,70,110,200) */
    intmem16(0xA5) = p;  intmem16(0xA7) = atf_temp;
    uint16_t i_mA = map2d_rom((const struct map2d *)0xEA82);
    return (uint32_t)i_mA * 10 / 45;                /* 4.5 mA per count */
}

/* bank1 0x5480: MPC line pressure and the flush logic (hydr +0x4F..+0x58):
 *   p = (torque-shaped INTMEM 0x4A:0x4B + ...) * p_multi / 1000 - lp_reg_spring, floor 0
 *   p = max(p, P_LINE_BASE)
 *   if p == 0 && INTMEM 0x44:0x45 < min_mpc_pressure && atf_temp >= flush_temp(+0x52):
 *       alternate XRAM 0x2DF:0x2E0 between mpc_no_flush_time (+0x56) and mpc_flush_time (+0x58)
 *       on flag INTMEM 0x98 bit 3 (bit 4 = flushing)
 *   else filter with filter_factor (+0x51) through 0x1010 (x<<3 / (n+1)) */

/* ======================================================================
 * 6. The engagement state machine (bank1 FUN_5BB6, sub-state INTMEM 0xB4)
 * ====================================================================== */

/* Timers 0xB0/0xB1/0xB2 are decremented once per scheduler cycle by bank0 FUN_E48D
 * (the first task of the scheduler 0x6E6A). Calibration cells (bank1 ROM):
 *   0xFF87 = 1500 mbar   clutch target during fill (u16)
 *   0xFF78 = 10          lag divisor start (INTMEM 0xB1): p += (target-p)/n, n counting down
 *   0xFF7B = 26          hold time added after the ramp (state 4)
 *   0xFF9F = 45          minimum time in state 0
 *   0xFFA1 = 80          N/P idle timer
 *   0xFFA2 = 50          ATF threshold (degC+50 -> 0 degC) for leaving N/P via the fast path
 *   0xFF73 = 150, 0xFF9E = 40   t_lerp_150_40: fill/hold time, -30 degC .. +20 degC (FUN_56A6)
 *   0xFF76 = 40,  0xFF71 = 7    t_lerp_40_7 (FUN_56DE), or 0xFF9D = 80 on the fast condition
 *                             (which needs ENGINE_RPM <= bank1 ROM16[0xFC3E] = 0: never, on this cal)
 *   0xFF91 = 20, 0xFF92 = 70    the temperature axis of both (-30 .. +20 degC)
 *   0xFF81 = 111 (u16)    speed threshold for energising Y3 in state 2
 *   0xFFA7 = 1000, 0xFFAD = 1005 (u16)  SPEED_W thresholds for leaving N/P
 * Pattern byte INTMEM 0x95: bit0 Y3, bit1 Y5, bit2 Y4 (see egs51_outputs.c). */

void engagement_state_machine(void)
{
    /* entry (0x5BB6): if a drive range is selected or 0x96.2 -> 0x94 |= 0x80.
     * Any of (P/R with 0x1BD.0), (N with 0x94.7), (0x1C2.1) forces state 8 with 0xB0 = 80. */
    switch (engage_state) {                         /* jump table 0x5C66 */

    case 0:  /* 0x5C81: arm */
        if (y4_on && shift_index == 7 /* 4-3 */) { t = t_lerp_40_7(); t_b0 = (t < 45) ? 45 : t; }
        else t_b0 = 0;
        engage_state++;
        break;

    case 1:  /* 0x5CB7: set the targets */
        P_MPC    = ROM16(0xFF87);                    /* 1500 */
        P_CLUTCH = 4000;
        P_SPC_SOL = spc_from_clutch(shift_index - 1, P_CLUTCH);
        if (y4_on && shift_index == 7) {
            if (t_b0) return;                        /* wait */
            flags_9a &= ~0x10; shift_index = 1; y4_on = 0; t_b0 = t_lerp_40_7(); engage_state++;
        } else {
            engage_state++; t_b0 = t_lerp_40_7();
            if (gear_b3 >= 6 && !(flags_9a & 0x10)) y4_on = 1;   /* 0x5D35 */
        }
        break;

    case 2:  /* 0x5D3C: choose the valves */
        if (t_b0) return;
        if (!y3_on && !(flags_1bd & 1)) {
            /* energise Y3 (1-2 valve) when the speed word 0x1F6:0x1F7 is above ROM16(0xFF81)
             * (for 0xAB in {1,5,6}) or, otherwise, above it and 0x22F:0x230 as well */
            if (speed_1f6 >= ROM16(0xFF81) && ...) y3_on = 1;
        }
        t_b0 = t_lerp_150_40();                      /* 150 .. 44 cycles by ATF temperature */
        t_b1 = ROM8(0xFF78);                         /* n = 10: ramp divisor */
        if (!(flags_9a & 0x10) || !(flags_9a & 0x04)) {   /* 0x5DBE */
            if (y3_on) { engage_state++; return; }
            shift_index = 5 /* 2-1 */; engage_state = 0; shift_phase = 0; return;
        }
        engage_state++;
        if (gear_b3 >= 6) {                          /* 0x5DF2: R */
            if (((flags_1bd & 1) && target_gear == 7) || (!(flags_1bd & 1) && target_gear != 7)) { y4_on = 1; engage_state = 6; }
            else engage_state = 7;
            return;
        }
        if (gear_b3 >= 4) { y5_on = 1; return; }
        if (gear_b3 == 3) { if (!y3_on && !y4_on) { y5_on = 1; y4_on = 1; } return; }   /* into 3rd */
        if (gear_b3 < 2 && !y3_on) {                 /* 0x5E62: normal D engagement */
            if (gear_ab >= 3) { y5_on = 1; y4_on = 0; t_b2 = t_b0 + t_lerp_150_40(); shift_index = 2 /* 2-3 */; engage_state++; }
            else if (target_gear == 7 || target_gear < 6) { t_b0 = t_b1; engage_state = 7; }
            else { t_b0 = 0; engage_state--; }
            return;
        }
        engage_state++;                              /* 0x5EB1 */
        if (gear_b3 == 3 && y5_on) { t_b2 = t_b0 + t_lerp_150_40(); return; }
        engage_state++; t_b1 = 0; t_b2 = t_lerp_150_40();
        break;

    case 3:  /* 0x5EE0: ramp, then all valves off */
    case 4:  /* 0x5F3D: same ramp, Y3 off + Y4 on, then a hold */
    case 7:  /* 0x6048: same ramp, Y3 + Y5 off */
        P_MPC     = lag_div(P_MPC,    ROM16(0xFF87), t_b1);   /* -> 1500 */
        P_CLUTCH  = lag_div(P_CLUTCH, 4000,          t_b1);   /* -> 4000 */
        P_SPC_SOL = spc_from_clutch(shift_index - 1, P_CLUTCH);
        if (t_b0) return;
        if (engage_state == 3) { y3_on = y5_on = y4_on = 0; flags_9a |= 0x10; engage_state = 0; }
        else if (engage_state == 7) { y3_on = y5_on = 0;   flags_9a |= 0x10; engage_state = 0; }
        else {                                       /* 4 */
            y3_on = 0; y4_on = 1;
            if (t_b2) return;
            y4_on = 0; t_b1 = t_lerp_40_7(); t_b0 = t_b1 + ROM8(0xFF7B) /* 26 */;
            t_b2 = t_b0 + t_lerp_40_7(); engage_state++;
        }
        break;

    case 5:  /* 0x5FB7: settle */
        if (t_b1) return;
        P_SPC_SOL = 0; P_CLUTCH = 0; P_MPC = 4500;   /* 0x1194 */
        if (shift_index == 2) {
            if (t_b0 || t_b2) return;
            y5_on = 0; t_b0 = 2 * ROM8(0xFF78); t_b1 = t_b0; engage_state = 3;
        } else {
            if (t_b2) return;
            y4_on = 1; t_b0 = t_lerp_150_40(); t_b1 = ROM8(0xFF78); engage_state = 3;
        }
        break;

    case 6:  /* 0x6021: R, waiting for the engine-speed flag */
        P_SPC_SOL = P_CLUTCH = P_MPC = 0; y3_on = 0;
        if (flags_1bd & 1) return;
        engage_state = 7;
        break;

    case 8:  /* 0x60A1: N/P idle */
        y3_on = 0; y5_on = 1; y4_on = 1;             /* hydraulic neutral pair held */
        P_MPC = 0; P_CLUTCH = 200; P_SPC_SOL = 800;
        if (flags_1c2 & 1) return;
        if (t_b0) return;                            /* 80 cycles after entry */
        if (!(flags_94 & 0x10) && (target_gear <= 5 || target_gear == 7)
            && atf_temp >= ROM8(0xFFA2) /* 0 degC */ && !(flags_1ca & 1)
            && SPEED_W < ROM16(0xFFAD)) {
            /* fast path out of N/P */
            flags_9a |= 0x10; flags_94 |= 1; y5_on = 0; y4_on = 0; engage_state = 0; shift_phase = 0;
        } else if (!(flags_94 & 0x10)
                   && (!(flags_1bd & 1) || (target_gear <= 5 && SPEED_W < ROM16(0xFFA7)))) {
            /* normal path: both released, engagement starts at state 0 */
            flags_9a |= 0x10; flags_94 |= 1; y5_on = 0; y4_on = 0; engage_state = 0; shift_phase = 0;
        }
        break;
    }
}

/* Reading of the above for the garage-fill question:
 *   - in N/P the MPC target is 0 mbar (= maximum regulator current = minimum line
 *     pressure), the SPC solenoid word is 800 mbar and Y5 + Y4 are held;
 *   - on leaving N/P both are released, then P_MPC ramps 0 -> 1500 and P_CLUTCH
 *     0 -> 4000 as linear ramps over n = 10 cycles (lag_div with the divisor
 *     counting down), while the valve for the target range is energised;
 *   - the fill/hold time is t_lerp_150_40: 150 cycles at <= -30 degC, 40 cycles at
 *     >= +20 degC, linear in between - this is the temperature schedule that
 *     section 6 said was absent; it is a TIME schedule, not a pressure one;
 *   - the 5x4 map at XRAM 0x3C8 (gear index x ATF: 30/81/43/30/41 at -20 degC down
 *     to 8/7/7/9/6 at 60 degC) plus a per-clutch term from [0x16D + clutch] gives
 *     XRAM 0x339 through FUN_6856; it is called from the shift functions, not from
 *     this machine, so it is the fill schedule of SHIFTS, per gear and temperature.
 * The scheduler cycle time has not been measured; every "cycle" above is one pass of
 * bank0 FUN_6E6A. */
