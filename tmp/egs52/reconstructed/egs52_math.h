#ifndef EGS52_MATH_H
#define EGS52_MATH_H
#include <stdint.h>

/* Native semantic reconstructions. CPU addresses are in the implementation.
 * Integer timer/sensor units are retained; no physical units are inferred.
 * Curve axes must strictly increase, with 2..255 points. Arrays are native
 * uint16_t values, decoded from little-endian firmware words by the caller.
 * Percent functions require weight 0..100. */
uint16_t egs52_weighted_average_u16(uint8_t weight, uint16_t next, uint16_t old);
uint16_t egs52_blend_percent_u16(uint8_t weight, uint16_t a, uint16_t b);
int16_t egs52_blend_percent_s16(uint8_t weight, int16_t a, int16_t b);
uint16_t egs52_ramp_u16(uint16_t old, uint16_t target, uint16_t divisor);
uint16_t egs52_sqrt_estimate_u16(uint16_t value);
uint16_t egs52_abs_s16_bits(int16_t value);
/* Layout: y0, y1, x0, x1, x. Interior interpolation uses signed 16-bit
 * differences, even in the unsigned-axis routine. The signed differences and
 * quotient must fit int16_t, and x1-x0 must be nonzero. Endpoint branches have
 * no division requirement. Return value preserves the original word bits. */
uint16_t egs52_lerp_unsigned_axis(const uint16_t values[5]);
uint16_t egs52_lerp_signed_axis(const uint16_t values[5]);
uint16_t egs52_curve_u16(uint16_t count, const uint16_t *axis,
                         const uint16_t *values, uint16_t input);
uint8_t egs52_curve_u8(uint8_t count, const uint8_t *axis,
                       const uint8_t *values, uint8_t input);
/* DPP conversion: physical 24-bit address, not the compiler's padded far
 * pointer representation. DPP registers contain 10-bit page numbers. */
uint32_t egs52_near_to_physical(uint16_t pointer, const uint16_t dpp[4]);
int16_t egs52_weighted_average_s16(uint8_t weight, int16_t next, int16_t old);
/* PID state words: previous error, accumulated error, reserved. Gains scale
 * by 1000. Individual divided products must fit int16_t (DIVL requirement).
 * The integral term is also returned because ROM writes it to RAM 0xd494. */
void egs52_pid_reset(uint16_t state[3]);
int16_t egs52_pid_step(uint16_t state[3], const int16_t gains[3],
                       int16_t error, int16_t *integral_term);
/* Signed curve: 2..255 strictly increasing points; wrapped signed operand
 * arithmetic and each DIVL quotient must be valid (see lerp domain above). */
int16_t egs52_curve_s16(uint8_t count, const int16_t *axis,
                        const int16_t *values, int16_t input);
/* Maps: cells[y * nx + x], both axes strictly increasing, >=2 points.
 * Word maps require all table offsets to fit the original near address space;
 * signed maps require nonzero wrapped spans and signed-word DIVL quotients.
 * Byte maps intentionally wrap cell indices modulo 256; supply all accessed
 * cells (256 bytes suffice even when nx * ny exceeds 256).
 * All maps clamp inputs but still evaluate three separate interpolations. */
uint16_t egs52_map_u16(uint16_t nx, uint16_t ny, const uint16_t *xs,
                       const uint16_t *ys, const uint16_t *cells, uint16_t x, uint16_t y);
int16_t egs52_map_s16(uint16_t nx, uint16_t ny, const int16_t *xs,
                      const int16_t *ys, const int16_t *cells, int16_t x, int16_t y);
uint8_t egs52_map_u8(uint8_t nx, uint8_t ny, const uint8_t *xs,
                     const uint8_t *ys, const uint8_t *cells, uint8_t x, uint8_t y);
/* Firmware estimates, not exact square roots. Vector sum wraps to 32 bits. */
uint16_t egs52_sqrt_estimate_u32(uint32_t value);
uint16_t egs52_vector_length_estimate(uint16_t x, uint16_t y);
/* Memory helpers expose firmware addresses rather than host pointer casts. */
typedef uint8_t (*egs52_read_byte_fn)(void *context, uint32_t address);
uint16_t egs52_crc16_a001_far(egs52_read_byte_fn read_byte, void *context,
                             uint32_t address, uint16_t count, uint16_t crc);
uint16_t egs52_memcpy_near(uint8_t memory[65536], uint16_t destination,
                          uint16_t source, uint16_t count);
/* Control helpers use a caller-owned ordinary near-RAM image. Words are
 * little endian. These APIs expose implicit firmware RAM, not extra ROM args.
 * The scale helpers require nonzero divisors and word-sized DIVLU quotients.
 * filter_d710 requires F65E's pointer plus 0x48 to address ordinary near RAM. */
void egs52_clamp_d488_when_fd4e_bit5_set(uint8_t ram[65536]);
void egs52_update_d7d8_from_byte_delta(uint8_t ram[65536], uint8_t weight,
                                      uint8_t reference, uint16_t base);
void egs52_scale_and_store_d4ae(uint8_t ram[65536], uint16_t value, uint8_t weight);
void egs52_combine_percent_term_d402(uint8_t ram[65536]);
uint16_t egs52_offset_and_clamp_u16(const uint8_t ram[65536], uint16_t input);
uint8_t egs52_classify_negated_input(const uint8_t ram[65536], uint16_t input);
/* F61E+0x24 gain and F65A+0x10 threshold must resolve to near RAM.
 * Signed wrapped difference times gain / 300 must fit int16_t. */
void egs52_update_scaled_difference_d712(uint8_t ram[65536]);
uint8_t egs52_initialize_fault_status(uint8_t ram[65536]);
/* Queries preserve the byte index and perform no bounds check. */
uint8_t egs52_test_fault_status_bit4(const uint8_t ram[65536], uint8_t index);
uint8_t egs52_test_fault_status_bit3(const uint8_t ram[65536], uint8_t index);
uint8_t egs52_test_fault_status_bit2(const uint8_t ram[65536], uint8_t index);
uint8_t egs52_test_fault_status_bit7(const uint8_t ram[65536], uint8_t index);
uint8_t egs52_test_fault_bitmap(const uint8_t ram[65536], uint8_t index);
/* Compiler helper results. Division requires nonzero denominator; the wide
 * divisor entry additionally requires denominator >= 65536. Signed division
 * accepts/returns word bits so INT32_MIN / -1 retains firmware wraparound. */
uint32_t egs52_multiply_u32_registers(uint32_t lhs, uint32_t rhs);
uint32_t egs52_divide_u32_registers(uint32_t numerator, uint32_t denominator);
uint32_t egs52_divide_u32_wide_divisor(uint32_t numerator, uint32_t denominator);
uint32_t egs52_divide_s32_registers(uint32_t numerator_bits, uint32_t denominator_bits);
/* Far pointer must be word aligned; two word reads and a TWO-byte advance. */
uint32_t egs52_read_far_u32_registers(egs52_read_byte_fn read_byte, void *context,
                                      uint32_t *pointer_bits);
/* State: count/source/destination register words; ordinary near RAM only.
 * Word source/destination must be aligned. Zero count still copies once. */
void egs52_copy_bytes_registers(uint8_t ram[65536], uint16_t state[3]);
void egs52_copy_words_registers(uint8_t ram[65536], uint16_t state[3]);
/* Dynamic targets are explicit callbacks, preserving target side effects.
 * The callback's context carries registers/results as needed by its caller. */
typedef void (*egs52_far_call_fn)(void *context, uint32_t target);
void egs52_call_far_indirect(egs52_far_call_fn call_target, void *context,
                             uint16_t segment, uint16_t offset);
void egs52_boot_call_far_indirect(egs52_far_call_fn call_target, void *context,
                                  uint16_t segment, uint16_t offset);
uint32_t egs52_boot_read_far_u32_registers(egs52_read_byte_fn read_byte, void *context,
                                           uint32_t *pointer_bits);
/* Sequential PSW helpers include final N/C/V/Z/E flags. For save/disable,
 * preserved_r6 is the caller's R6 value restored by the last MOV instruction.
 * Hardware interrupt timing is outside this interface. */
void egs52_enable_interrupts(uint16_t *psw);
uint8_t egs52_disable_interrupts_save(uint16_t *psw, uint16_t preserved_r6);
uint16_t egs52_exchange_interrupt_priority(uint16_t *psw, uint16_t requested);
/* Same signed-axis division domain as egs52_lerp_signed_axis. */
uint16_t egs52_lerp_signed_registers(uint16_t low, uint16_t high,
                                    int16_t x0, int16_t x1, int16_t input);
/* Ordinary near RAM; CDA6 is the inclusive byte-index limit. */
uint16_t egs52_read_indexed_record_word(const uint8_t ram[65536], uint8_t index);
/* FD02 is the sampled architectural word; includes final PSW flags. */
uint8_t egs52_test_fd02_bit0_clear(uint16_t fd02, uint16_t *psw);
/* Copies the four words only when C32A bits 0/4 permit and bit 2 is clear. */
uint8_t egs52_stage_request_words(uint8_t ram[65536], uint16_t word0,
                                  uint16_t word1, uint16_t word2, uint16_t word3);
/* Boot IRQ models stop at application forwarding or a reset request. The
 * callbacks expose ordered word I/O and control events; they must not mutate
 * the model's PSW/DPP3/MDH state. Timing and post-reset hardware are external. */
typedef struct { uint16_t psw, dpp3, mdh; } Egs52BootIrqState;
typedef uint16_t (*egs52_read_word_fn)(void *context, uint16_t address);
typedef void (*egs52_write_word_fn)(void *context, uint16_t address, uint16_t value);
typedef void (*egs52_control_event_fn)(void *context, uint8_t kind, uint32_t target);
enum { EGS52_FORWARD_VECTOR = 0, EGS52_SERVICE_WATCHDOG = 1, EGS52_REQUEST_RESET = 2 };
void egs52_interrupt_010(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context);
void egs52_interrupt_018(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context);
void egs52_interrupt_028(Egs52BootIrqState *state, egs52_read_word_fn read_word,
    egs52_write_word_fn write_word, egs52_control_event_fn event, void *context);
#endif
