#ifndef EGS51_HANDOFF_MATH_H
#define EGS51_HANDOFF_MATH_H

#include <stdint.h>

/* ROM-compatible handoff arithmetic, shared with the host reconstruction.
 * These are raw counter/pressure units, NOT milliseconds or a complete shift
 * algorithm. No actuator writes or runtime activation are provided here.
 * Preserve the OEM's intermediate word truncations: replacing this with sqrt
 * and floating-point interpolation changes the carried fill state.
 */
static inline uint16_t egs51_handoff_root(uint16_t value) {
    uint16_t estimate = value >> 3;
    if (value > 100) { estimate >>= 2; }
    if (value > 5000) { estimate >>= 2; }
    for (uint8_t i = 0; i < 3 && estimate; ++i) {
        const uint16_t denominator = (uint16_t)(estimate << 3);
        const uint16_t quotient = (uint16_t)((uint32_t)value * 8 / denominator);
        estimate = (uint16_t)(estimate + quotient) >> 1;
    }
    return estimate;
}

/* bank1 9B38..9BF8 after gear-dependent pressure context has been loaded.
 * Timer and elapsed values count OEM scheduler invocations; the conversion to
 * NAG52's timebase must be established before this can drive a live shift.
 */
static inline uint8_t egs51_handoff_fill_credit(uint16_t previous_pressure,
                                               uint16_t next_centrifugal,
                                               uint16_t next_spring,
                                               uint16_t next_fill_pressure,
                                               uint8_t base_timer,
                                               uint8_t elapsed) {
    if (next_fill_pressure == 0) { return UINT8_MAX; }
    const uint16_t gross = (uint16_t)(previous_pressure + next_centrifugal);
    const uint16_t net = gross > next_spring ? gross - next_spring : 0;
    const uint16_t ratio = (uint16_t)((uint32_t)10000 * net / next_fill_pressure);
    const uint16_t factor = egs51_handoff_root(ratio);
    const uint16_t half = (uint16_t)((uint16_t)(base_timer * (factor + 100)) >> 1);
    const uint16_t weighted_elapsed = (uint16_t)(factor * elapsed);
    const uint16_t credit = (uint16_t)(half + weighted_elapsed) / 100;
    return credit > UINT8_MAX ? UINT8_MAX : (uint8_t)credit;
}
#endif
