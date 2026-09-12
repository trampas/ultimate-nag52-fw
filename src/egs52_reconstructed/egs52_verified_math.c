/* EGS52 A0325452132, decoded CPU byte order.
 * These routines were transcribed from instructions, with explicit wrapping
 * and staged integer division. They do not depend on Ghidra's inferred ABI.
 * See tests/verify_math.py for original-instruction differential checks.
 * This file is the verified arithmetic subset, not the whole ECU program.
 */
#include "egs52_math.h"

static int32_t signed_word(uint16_t value)
{
    return value < 0x8000u ? (int32_t)value : (int32_t)value - 65536;
}

/* 0x0df1f8..0x0df220: numerator is 32 bits, divisor is weight+1. */
uint16_t egs52_weighted_average_u16(uint8_t weight, uint16_t next, uint16_t old)
{
    return (uint16_t)(((uint32_t)old * weight + next) / ((uint16_t)weight + 1u));
}

/* 0x0df222..0x0df24e: TWO divisions, each truncates before addition. */
uint16_t egs52_blend_percent_u16(uint8_t weight, uint16_t a, uint16_t b)
{
    return (uint16_t)(((uint32_t)weight * a) / 100u +
                      ((uint32_t)(100u - weight) * b) / 100u);
}

/* 0x0df250..0x0df27c: signed multiply and DIVL, truncating toward zero. */
int16_t egs52_blend_percent_s16(uint8_t weight, int16_t a, int16_t b)
{
    int32_t value = ((int32_t)weight * a) / 100 + ((int32_t)(100 - weight) * b) / 100;
    return (int16_t)value;
}

/* 0x0df27e..0x0df2ae: divisor zero selects the target immediately. */
uint16_t egs52_ramp_u16(uint16_t old, uint16_t target, uint16_t divisor)
{
    if (divisor == 0) return target;
    if (target > old) return (uint16_t)(old + (target - old) / divisor);
    return (uint16_t)(old - (old - target) / divisor);
}

/* 0x0df2b0..0x0df2ea: exactly three Newton iterations, not integer sqrt.
 * In particular, values 1..7 return zero because the initial guess is zero. */
uint16_t egs52_sqrt_estimate_u16(uint16_t value)
{
    uint16_t guess = value >> 3;
    if (value > 100) guess >>= 2;
    if (value > 5000) guess >>= 2;
    for (unsigned i = 0; i < 3 && guess != 0; ++i)
        guess = (uint16_t)(guess + value / guess) >> 1;
    return guess;
}

/* 0x09223a..0x092246: NEG preserves 0x8000 for input -32768. */
uint16_t egs52_abs_s16_bits(int16_t value)
{
    return value < 0 ? (uint16_t)(-(int32_t)value) : (uint16_t)value;
}

static uint16_t lerp_interior(const uint16_t v[5])
{
    int32_t dy = signed_word((uint16_t)(v[1] - v[0]));
    int32_t dx = signed_word((uint16_t)(v[4] - v[2]));
    int32_t span = signed_word((uint16_t)(v[3] - v[2]));
    return (uint16_t)(v[0] + (dy * dx) / span);
}

/* 0x0df3a4..0x0df3f6: check the upper endpoint before the lower one. */
uint16_t egs52_lerp_unsigned_axis(const uint16_t v[5])
{
    if (v[4] >= v[3]) return v[1];
    if (v[4] <= v[2]) return v[0];
    return lerp_interior(v);
}

/* 0x0df3f8..0x0df44a: same arithmetic with signed axis comparisons. */
uint16_t egs52_lerp_signed_axis(const uint16_t v[5])
{
    if (signed_word(v[4]) >= signed_word(v[3])) return v[1];
    if (signed_word(v[4]) <= signed_word(v[2])) return v[0];
    return lerp_interior(v);
}

/* 0x0df44c..0x0df504: unsigned magnitudes on both rising/falling spans. */
uint16_t egs52_curve_u16(uint16_t count, const uint16_t *axis,
                         const uint16_t *values, uint16_t input)
{
    if (input <= axis[0]) return values[0];
    if (input >= axis[count - 1]) return values[count - 1];
    uint8_t i = 1;
    while (input > axis[i]) ++i;
    uint16_t a = values[i - 1], b = values[i];
    uint16_t magnitude = a > b ? a - b : b - a;
    uint16_t delta = (uint16_t)(((uint32_t)(input - axis[i - 1]) * magnitude) /
                               (axis[i] - axis[i - 1]));
    return a > b ? (uint16_t)(a - delta) : (uint16_t)(a + delta);
}

/* 0x0df894: byte axes, byte values, same staged unsigned interpolation. */
uint8_t egs52_curve_u8(uint8_t count, const uint8_t *axis,
                       const uint8_t *values, uint8_t input)
{
    if (input <= axis[0]) return values[0];
    if (input >= axis[count - 1]) return values[count - 1];
    uint8_t i = 1;
    while (input > axis[i]) ++i;
    uint8_t a = values[i - 1], b = values[i];
    unsigned magnitude = a > b ? a - b : b - a;
    unsigned delta = ((unsigned)(input - axis[i - 1]) * magnitude) /
                     (axis[i] - axis[i - 1]);
    return a > b ? (uint8_t)(a - delta) : (uint8_t)(a + delta);
}

/* 0x092118..0x09212c returns the segment in R5 and offset in R4. */
uint32_t egs52_near_to_physical(uint16_t pointer, const uint16_t dpp[4])
{
    return ((uint32_t)(dpp[pointer >> 14] & 0x3ffu) << 14) | (pointer & 0x3fffu);
}

/* 0x0df1c6..0x0df1f6, including compiler multiply helper 0x09212e. */
int16_t egs52_weighted_average_s16(uint8_t weight, int16_t next, int16_t old)
{
    return (int16_t)(((int32_t)old * weight + next) / ((int32_t)weight + 1));
}

/* 0x0dfcd6..0x0dfce2: all three context words are reset. */
void egs52_pid_reset(uint16_t state[3])
{
    state[0] = state[1] = state[2] = 0;
}

static int16_t saturate_signed_word(int32_t value)
{
    if (value > 32767) return 32767;
    if (value < -32768) return -32768;
    return (int16_t)value;
}

/* 0x0dfce4..0x0dfdc2: integral state and combined output saturate
 * independently. Derivative subtraction wraps before signed multiplication. */
int16_t egs52_pid_step(uint16_t state[3], const int16_t gains[3],
                       int16_t error, int16_t *integral_term)
{
    int32_t proportional = ((int32_t)gains[0] * error) / 1000;
    state[1] = (uint16_t)saturate_signed_word(signed_word(state[1]) + error);
    int32_t integral = (signed_word(state[1]) * gains[1]) / 1000;
    int32_t delta = signed_word((uint16_t)((uint16_t)error - state[0]));
    int32_t derivative = (delta * gains[2]) / 1000;
    state[0] = (uint16_t)error;
    *integral_term = (int16_t)integral;
    return saturate_signed_word(proportional + integral + derivative);
}

/* 0x0dfc18..0x0dfcd4: signed comparisons, signed wrapped magnitudes.
 * The descending branch negates the difference BEFORE multiplication. */
int16_t egs52_curve_s16(uint8_t count, const int16_t *axis,
                        const int16_t *values, int16_t input)
{
    if (input <= axis[0]) return values[0];
    if (input >= axis[count - 1]) return values[count - 1];
    unsigned i = 1;
    while (input > axis[i]) ++i;
    int32_t a = values[i - 1], b = values[i];
    int32_t magnitude = signed_word((uint16_t)(a > b ? a - b : b - a));
    int32_t dx = signed_word((uint16_t)(input - axis[i - 1]));
    int32_t span = signed_word((uint16_t)(axis[i] - axis[i - 1]));
    int32_t delta = dx * magnitude / span;
    return (int16_t)signed_word((uint16_t)(a > b ? a - delta : a + delta));
}

static unsigned bracket_u16(uint16_t count, const uint16_t *axis, uint16_t *x)
{
    if (*x <= axis[0]) { *x = axis[0]; return 1; }
    if (*x >= axis[count - 1]) { *x = axis[count - 1]; return count - 1; }
    unsigned i = 1;
    while (*x > axis[i]) ++i;
    return i;
}

static unsigned bracket_s16(uint16_t count, const int16_t *axis, int16_t *x)
{
    if (*x <= axis[0]) { *x = axis[0]; return 1; }
    if (*x >= axis[count - 1]) { *x = axis[count - 1]; return count - 1; }
    unsigned i = 1;
    while (*x > axis[i]) ++i;
    return i;
}

static uint16_t map_unsigned_span(uint16_t a, uint16_t b, uint16_t dx, uint16_t span)
{
    int32_t difference = signed_word((uint16_t)(b - a));
    uint32_t magnitude = (uint32_t)(difference < 0 ? -difference : difference);
    uint16_t delta = (uint16_t)((uint32_t)dx * magnitude / span);
    return difference < 0 ? (uint16_t)(a - delta) : (uint16_t)(a + delta);
}

/* 0x0df506..0x0df72c: X then Y; each of the three divisions truncates.
 * Values use signed wrapped differences even though the axes are unsigned. */
uint16_t egs52_map_u16(uint16_t nx, uint16_t ny, const uint16_t *xs,
                       const uint16_t *ys, const uint16_t *cells,
                       uint16_t x, uint16_t y)
{
    unsigned ix = bracket_u16(nx, xs, &x), iy = bracket_u16(ny, ys, &y);
    unsigned lower = (iy - 1) * nx + ix - 1, upper = lower + nx;
    uint16_t dx = x - xs[ix - 1], span = xs[ix] - xs[ix - 1];
    uint16_t a = map_unsigned_span(cells[lower], cells[lower + 1], dx, span);
    uint16_t b = map_unsigned_span(cells[upper], cells[upper + 1], dx, span);
    return map_unsigned_span(a, b, y - ys[iy - 1], ys[iy] - ys[iy - 1]);
}

/* 0x0df72e..0x0df892: signed axes and signed wrapped MUL/DIVL operands. */
int16_t egs52_map_s16(uint16_t nx, uint16_t ny, const int16_t *xs,
                      const int16_t *ys, const int16_t *cells,
                      int16_t x, int16_t y)
{
    unsigned ix = bracket_s16(nx, xs, &x), iy = bracket_s16(ny, ys, &y);
    unsigned lower = (iy - 1) * nx + ix - 1, upper = lower + nx;
    uint16_t v[5] = {(uint16_t)cells[lower], (uint16_t)cells[lower + 1],
                     (uint16_t)xs[ix - 1], (uint16_t)xs[ix], (uint16_t)x};
    uint16_t a = lerp_interior(v);
    v[0] = (uint16_t)cells[upper]; v[1] = (uint16_t)cells[upper + 1];
    uint16_t b = lerp_interior(v);
    uint16_t last[5] = {a, b, (uint16_t)ys[iy - 1], (uint16_t)ys[iy], (uint16_t)y};
    return (int16_t)signed_word(lerp_interior(last));
}

static unsigned bracket_u8(uint8_t count, const uint8_t *axis, uint8_t *x)
{
    if (*x <= axis[0]) { *x = axis[0]; return 1; }
    if (*x >= axis[count - 1]) { *x = axis[count - 1]; return count - 1; }
    unsigned i = 1;
    while (*x > axis[i]) ++i;
    return i;
}

static uint8_t map_byte_span(uint8_t a, uint8_t b, unsigned dx, unsigned span)
{
    unsigned magnitude = a > b ? a - b : b - a;
    unsigned delta = dx * magnitude / span;
    return a > b ? (uint8_t)(a - delta) : (uint8_t)(a + delta);
}

/* 0x0df980..0x0dfc16: cell indexing itself wraps to eight bits. */
uint8_t egs52_map_u8(uint8_t nx, uint8_t ny, const uint8_t *xs,
                     const uint8_t *ys, const uint8_t *cells,
                     uint8_t x, uint8_t y)
{
    unsigned ix = bracket_u8(nx, xs, &x), iy = bracket_u8(ny, ys, &y);
    uint8_t right = (uint8_t)((iy - 1) * nx + ix);
    unsigned dx = x - xs[ix - 1], span = xs[ix] - xs[ix - 1];
    uint8_t a = map_byte_span(cells[(uint8_t)(right - 1)], cells[right], dx, span);
    right = (uint8_t)(iy * nx + ix);
    uint8_t b = map_byte_span(cells[(uint8_t)(right - 1)], cells[right], dx, span);
    return map_byte_span(a, b, y - ys[iy - 1], ys[iy] - ys[iy - 1]);
}

/* 0x0df2ec..0x0df36c: three 32-bit Newton steps; return only low word.
 * The additional threshold is 100000, and addition wraps at 32 bits. */
uint16_t egs52_sqrt_estimate_u32(uint32_t value)
{
    uint32_t guess = value >> 3;
    if (value > 100u) guess >>= 2;
    if (value > 5000u) guess >>= 2;
    if (value > 100000u) guess >>= 2;
    for (unsigned i = 0; i < 3 && guess != 0; ++i)
        guess = (guess + value / guess) >> 1;
    return (uint16_t)guess;
}

/* 0x0df36e..0x0df3a2: unsigned squares and a wrapping 32-bit sum. */
uint16_t egs52_vector_length_estimate(uint16_t x, uint16_t y)
{
    return egs52_sqrt_estimate_u32((uint32_t)x * x + (uint32_t)y * y);
}

/* 0x09efaa..0x09efe4: reflected CRC; caller supplies initial CRC.
 * Callback retains the actual 24-bit far addresses, including wraparound. */
uint16_t egs52_crc16_a001_far(egs52_read_byte_fn read_byte, void *context,
                             uint32_t address, uint16_t count, uint16_t crc)
{
    for (uint32_t i = 0; i < count; ++i) {
        uint8_t data = read_byte(context, (address + i) & 0xffffffu);
        for (unsigned bit = 0; bit < 8; ++bit) {
            unsigned feedback = (crc ^ data) & 1u;
            crc >>= 1;
            if (feedback) crc ^= 0xa001u;
            data >>= 1;
        }
    }
    return crc;
}

/* 0x092248..0x092264: forward byte copies, including overlap propagation.
 * Uses a caller-provided near RAM image to preserve 16-bit address wrapping.
 * Addresses must refer to ordinary RAM, not SFRs or the active CPU stack. */
uint16_t egs52_memcpy_near(uint8_t memory[65536], uint16_t destination,
                          uint16_t source, uint16_t count)
{
    for (uint32_t i = 0; i < count; ++i)
        memory[(uint16_t)(destination + i)] = memory[(uint16_t)(source + i)];
    return destination;
}

/* Ordinary near-RAM semantic models. The supplied image excludes peripheral
 * side effects; words use CPU little-endian order. */
static uint16_t ram_word(const uint8_t *ram, uint16_t address)
{
    return (uint16_t)(ram[address] | (uint16_t)ram[(uint16_t)(address + 1)] << 8);
}

static void ram_store_word(uint8_t *ram, uint16_t address, uint16_t value)
{
    ram[address] = (uint8_t)value;
    ram[(uint16_t)(address + 1)] = (uint8_t)(value >> 8);
}

/* 0x0d2008..0x0d202c: the flag enables an unsigned upper limit. */
void egs52_clamp_d488_when_fd4e_bit5_set(uint8_t ram[65536])
{
    uint16_t value = ram_word(ram, 0xd48a);
    ram_store_word(ram, 0xd488, value);
    if (ram_word(ram, 0xfd4e) & 0x20u) {
        uint16_t limit = ram_word(ram, 0xd480);
        if (value >= limit) value = limit;
        ram_store_word(ram, 0xd488, value);
    }
}

/* 0x0d2938..0x0d2956: byte arguments, wrapped difference/product/sum. */
void egs52_update_d7d8_from_byte_delta(uint8_t ram[65536], uint8_t weight,
                                      uint8_t reference, uint16_t base)
{
    ram_store_word(ram, 0xd7d8, base);
    uint16_t difference = (uint16_t)(ram[0xd579] - reference);
    uint16_t product = (uint16_t)((uint32_t)difference * weight);
    ram_store_word(ram, 0xd7d8, (uint16_t)(base + product));
}

/* 0x0d7b70..0x0d7b88: quotient goes to RAM, not a C return register.
 * D46E must be nonzero and the unsigned quotient must fit a word. */
void egs52_scale_and_store_d4ae(uint8_t ram[65536], uint16_t value, uint8_t weight)
{
    uint16_t quotient = (uint16_t)((uint32_t)value * weight / ram_word(ram, 0xd46e));
    ram_store_word(ram, 0xd4ae, quotient);
}

/* 0x0d7bc0..0x0d7be0: the final addition wraps, rather than saturating.
 * The unsigned divided product must fit a word. */
void egs52_combine_percent_term_d402(uint8_t ram[65536])
{
    uint16_t term = (uint16_t)((uint32_t)ram[0xd4df] * ram_word(ram, 0xd492) / 100u);
    ram_store_word(ram, 0xd402, (uint16_t)(ram_word(ram, 0xd4ae) + term));
}

/* 0x0d7e64..0x0d7e86: wrap the initial addition BEFORE floor/ceiling. */
uint16_t egs52_offset_and_clamp_u16(const uint8_t ram[65536], uint16_t input)
{
    uint16_t sum = (uint16_t)(input + ram_word(ram, 0xd54a));
    uint16_t floor = ram_word(ram, 0xd536), ceiling = ram_word(ram, 0xd552);
    uint16_t result = sum < floor ? 0 : (uint16_t)(sum - floor);
    return result > ceiling ? ceiling : result;
}

/* 0x0de014..0x0de028: NEG of 0x8000 stays 0x8000. */
uint8_t egs52_classify_negated_input(const uint8_t ram[65536], uint16_t input)
{
    int32_t negated = signed_word((uint16_t)(0u - input));
    return negated > signed_word(ram_word(ram, 0xd4c2)) ? 2 : 1;
}

/* 0x0e0036..0x0e004c: input is live in R13. The coefficient pointer
 * must resolve to ordinary near RAM in the supplied image. */
static void filter_d710(uint8_t ram[65536], int16_t input)
{
    uint16_t coefficient = (uint16_t)(ram_word(ram, 0xf65e) + 0x48u);
    int16_t previous = (int16_t)signed_word(ram_word(ram, 0xd710));
    int16_t filtered = egs52_weighted_average_s16(ram[coefficient], input, previous);
    ram_store_word(ram, 0xd710, (uint16_t)filtered);
}

/* 0x0e0000..0x0e0052, including shared tail at 0x0e0036.
 * Pointer targets must be ordinary near RAM. The signed product / 300 must
 * fit a word. The zero path assumes the architectural ZEROS register. */
void egs52_update_scaled_difference_d712(uint8_t ram[65536])
{
    uint16_t current = ram_word(ram, 0xd504);
    int32_t difference = signed_word((uint16_t)(current - ram_word(ram, 0xd790)));
    uint16_t gain_address = (uint16_t)(ram_word(ram, 0xf61e) + 0x24u);
    int32_t gain = signed_word(ram_word(ram, gain_address));
    int16_t scaled = (int16_t)(difference * gain / 300);
    ram_store_word(ram, 0xd712, (uint16_t)scaled);
    ram_store_word(ram, 0xd790, current);
    uint16_t threshold_address = (uint16_t)(ram_word(ram, 0xf65a) + 0x10u);
    if (ram_word(ram, 0xd500) <= ram_word(ram, threshold_address))
        ram_store_word(ram, 0xd710, 0);
    else
        filter_d710(ram, scaled);
}

/* 0x09f858..0x09f872: exactly 128 status bytes and one enable word. */
uint8_t egs52_initialize_fault_status(uint8_t ram[65536])
{
    for (unsigned i = 0; i < 128; ++i) ram[0xc3ac + i] = 0x28;
    ram_store_word(ram, 0xf84c, 1);
    return 0;
}

/* 0x09f7d8, 0x09f7ec, 0x09f800, 0x09f814: the index is truncated
 * to a byte. Firmware applies no 128-entry bounds check on these queries. */
uint8_t egs52_test_fault_status_bit4(const uint8_t ram[65536], uint8_t index)
{
    return (uint8_t)((ram[0xc3ac + index] >> 4) & 1u);
}
uint8_t egs52_test_fault_status_bit3(const uint8_t ram[65536], uint8_t index)
{
    return (uint8_t)((ram[0xc3ac + index] >> 3) & 1u);
}
uint8_t egs52_test_fault_status_bit2(const uint8_t ram[65536], uint8_t index)
{
    return (uint8_t)((ram[0xc3ac + index] >> 2) & 1u);
}
uint8_t egs52_test_fault_status_bit7(const uint8_t ram[65536], uint8_t index)
{
    return (uint8_t)((ram[0xc3ac + index] >> 7) & 1u);
}

/* 0x09f828..0x09f856: separate word bitmap, not a status-byte bit. */
uint8_t egs52_test_fault_bitmap(const uint8_t ram[65536], uint8_t index)
{
    uint16_t word = ram_word(ram, (uint16_t)(0xc42c + 2u * (index >> 4)));
    return (uint8_t)((word >> (index & 15u)) & 1u);
}

/* Compiler runtime, 0x09212e: R5:R4 times R11:R10, low 32 bits.
 * These native APIs model useful results, not scratch-register/PSW clobbers. */
uint32_t egs52_multiply_u32_registers(uint32_t lhs, uint32_t rhs)
{
    return lhs * rhs;
}

/* 0x0921b4; denominator must be nonzero. */
uint32_t egs52_divide_u32_registers(uint32_t numerator, uint32_t denominator)
{
    return numerator / denominator;
}

/* 0x0921ce is the shared tail entered only for a nonzero high divisor word. */
uint32_t egs52_divide_u32_wide_divisor(uint32_t numerator, uint32_t denominator)
{
    return numerator / denominator;
}

static int64_t signed_dword(uint32_t value)
{
    return value < UINT32_C(0x80000000) ? (int64_t)value : (int64_t)value - INT64_C(4294967296);
}

/* 0x09214e: preserve quotient word bits, including INT32_MIN / -1.
 * A nonzero denominator is required. The wider host division avoids C UB. */
uint32_t egs52_divide_s32_registers(uint32_t numerator_bits, uint32_t denominator_bits)
{
    return (uint32_t)(signed_dword(numerator_bits) / signed_dword(denominator_bits));
}

/* 0x09222c: two aligned far word reads. R5:R4 advances by TWO bytes,
 * not four. Its full register representation wraps at 32 bits; EXTS uses
 * only the low 24 bits to form each physical read address. */
uint32_t egs52_read_far_u32_registers(egs52_read_byte_fn read_byte, void *context,
                                      uint32_t *pointer_bits)
{
    uint32_t address = *pointer_bits & UINT32_C(0xffffff);
    uint32_t low = read_byte(context, address);
    low |= (uint32_t)read_byte(context, address + 1u) << 8;
    *pointer_bits += 2u;
    address = *pointer_bits & UINT32_C(0xffffff);
    uint32_t high = read_byte(context, address);
    high |= (uint32_t)read_byte(context, address + 1u) << 8;
    return low | high << 16;
}

/* 0x09226c and 0x09227c: state={R3 count,R4 source,R10 destination}.
 * Count zero still copies ONE element and leaves count 0xffff. Native RAM
 * addresses must resolve to ordinary memory, excluding CPU/peripheral state. */
void egs52_copy_bytes_registers(uint8_t ram[65536], uint16_t state[3])
{
    uint32_t iterations = state[0] ? state[0] : 1u;
    for (uint32_t i = 0; i < iterations; ++i) {
        ram[state[2]] = ram[state[1]];
        ++state[1]; ++state[2]; --state[0];
    }
}

void egs52_copy_words_registers(uint8_t ram[65536], uint16_t state[3])
{
    uint32_t iterations = state[0] ? state[0] : 1u;
    for (uint32_t i = 0; i < iterations; ++i) {
        uint16_t value = ram_word(ram, state[1]);
        ram_store_word(ram, state[2], value);
        state[1] = (uint16_t)(state[1] + 2u);
        state[2] = (uint16_t)(state[2] + 2u);
        --state[0];
    }
}

/* 0x092226 and boot copy 0x083132. PUSH R5; PUSH R4; RETS transfers
 * control to the far target. Its own return goes to the original caller.
 * The callback owns the target's register/memory effects through context. */
void egs52_call_far_indirect(egs52_far_call_fn call_target, void *context,
                             uint16_t segment, uint16_t offset)
{
    call_target(context, ((uint32_t)(segment & 0xffu) << 16) | offset);
}

void egs52_boot_call_far_indirect(egs52_far_call_fn call_target, void *context,
                                  uint16_t segment, uint16_t offset)
{
    egs52_call_far_indirect(call_target, context, segment, offset);
}

/* 0x083138: boot copy of the same word-pair loader at 0x09222c. */
uint32_t egs52_boot_read_far_u32_registers(egs52_read_byte_fn read_byte, void *context,
                                           uint32_t *pointer_bits)
{
    return egs52_read_far_u32_registers(read_byte, context, pointer_bits);
}

/* Explicit PSW interfaces include final condition flags. Instruction timing
 * and asynchronous interrupt arrival are outside these sequential models. */
void egs52_enable_interrupts(uint16_t *psw)
{
    *psw |= 0x0800u;
}

/* 0x097938: saved R6 is restored by the last MOV, which sets N/Z/E.
 * The earlier BMOV clears C/V. Exposing preserved_r6 retains these flags. */
uint8_t egs52_disable_interrupts_save(uint16_t *psw, uint16_t preserved_r6)
{
    uint8_t enabled = (uint8_t)((*psw >> 11) & 1u);
    *psw = (uint16_t)((*psw & 0xf7e0u) |
           ((preserved_r6 & 0x8000u) ? 1u : 0u) |
           (preserved_r6 == 0 ? 8u : 0u) |
           (preserved_r6 == 0x8000u ? 16u : 0u));
    return enabled;
}

/* 0x0a7d38: ORs the entire requested word, not just its high nibble.
 * The final AND on the return register supplies N/Z and clears C/V/E. */
uint16_t egs52_exchange_interrupt_priority(uint16_t *psw, uint16_t requested)
{
    uint16_t previous = *psw & 0xf000u;
    *psw = (uint16_t)((((*psw & 0x0fffu) | requested) & 0xffe0u) |
           ((previous & 0x8000u) ? 1u : 0u) | (previous == 0 ? 8u : 0u));
    return previous;
}

/* 0x0d30f2: fifth operand is on the compiler's R0 stack. */
uint16_t egs52_lerp_signed_registers(uint16_t low, uint16_t high,
                                    int16_t x0, int16_t x1, int16_t input)
{
    const uint16_t values[5] = {low, high, (uint16_t)x0, (uint16_t)x1, (uint16_t)input};
    return egs52_lerp_signed_axis(values);
}

/* 0x0a626c: byte index; upper R12 byte is ignored. */
uint16_t egs52_read_indexed_record_word(const uint8_t ram[65536], uint8_t index)
{
    if (index > ram[0xcda6]) return 0;
    uint16_t base = index < 14u ? 0xef00u : 0xee00u;
    uint16_t slot = index < 14u ? index : (uint16_t)(index - 14u);
    return ram_word(ram, (uint16_t)(base + slot * 16u + 16u));
}

/* 0x098164: PSW bit 6 receives the inverse of FD02 bit 0. The final
 * BMOV sets Z and clears N/C/V/E; only RL4 is the function result. */
uint8_t egs52_test_fd02_bit0_clear(uint16_t fd02, uint16_t *psw)
{
    uint8_t result = (uint8_t)((fd02 & 1u) ^ 1u);
    *psw = (uint16_t)((*psw & 0xffa0u) | ((uint16_t)result << 6) | 8u);
    return result;
}

/* 0x09eee4: the fourth word comes from [R0], not R15. */
uint8_t egs52_stage_request_words(uint8_t ram[65536], uint16_t word0,
                                  uint16_t word1, uint16_t word2, uint16_t word3)
{
    if ((ram[0xc32a] & 0x11u) == 0) return 0x22;
    if ((ram[0xc32a] & 4u) != 0) return 0x21;
    ram[0xc32a] |= 4u;
    ram_store_word(ram, 0xc332, word0);
    ram_store_word(ram, 0xc334, word1);
    ram_store_word(ram, 0xc336, word2);
    ram_store_word(ram, 0xc338, word3);
    return 0;
}

static void boot_irq_move_flags(Egs52BootIrqState *state, uint16_t value)
{
    state->psw = (uint16_t)((state->psw & (uint16_t)~0x19u) |
        ((value & 0x8000u) ? 1u : 0u) | (value == 0 ? 8u : 0u) |
        (value == 0x8000u ? 16u : 0u));
}

/* Common branch at 0x083618. This is a shared tail, not a separate ROM
 * function. The 255-iteration delay has no I/O; its final MDH/flags are kept. */
static void boot_irq_route(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context,
    uint32_t vector)
{
    if ((read_word(context, 0xfdee) & 1u) == 0) {
        event(context, EGS52_FORWARD_VECTOR, vector);
        return;
    }
    state->dpp3 = 3;
    boot_irq_move_flags(state, 3);
    state->mdh = read_word(context, 0xffac);
    boot_irq_move_flags(state, state->mdh);
    write_word(context, 0xe7fe, state->mdh);
    boot_irq_move_flags(state, state->mdh);
    state->mdh ^= 0xffffu;
    state->psw = (uint16_t)((state->psw & 0xffe0u) |
        ((state->mdh & 0x8000u) ? 1u : 0u) | (state->mdh == 0 ? 8u : 0u));
    write_word(context, 0xe800, state->mdh);
    boot_irq_move_flags(state, state->mdh);
    write_word(context, 0xffae, 0xff00);
    boot_irq_move_flags(state, 0xff00);
    event(context, EGS52_SERVICE_WATCHDOG, 0);
    state->mdh = 0;
    state->psw = (uint16_t)((state->psw & 0xffe0u) | 0x0au);
    event(context, EGS52_REQUEST_RESET, 0);
}

/* 0x0835f4, 0x083600, 0x08360c: no CALL/RET is invented for a JMPS. */
void egs52_interrupt_010(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context)
{
    boot_irq_route(state, read_word, write_word, event, context, 0x093b10);
}
void egs52_interrupt_018(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context)
{
    boot_irq_route(state, read_word, write_word, event, context, 0x093b18);
}
void egs52_interrupt_028(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context)
{
    boot_irq_route(state, read_word, write_word, event, context, 0x093b28);
}
