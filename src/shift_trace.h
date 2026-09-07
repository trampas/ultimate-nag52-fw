#ifndef SHIFT_TRACE_H
#define SHIFT_TRACE_H

#include <stdint.h>
#include "common_structs.h"

/**
 * @brief High rate shift recorder.
 *
 * The diagnostic link is request/response, so a host poll costs one round trip
 * per record (~6.5 ms measured) and a full record set only manages ~17 Hz. A
 * shift's inertia phase lasts 100-200 ms, which that rate resolves with about
 * two samples - far too few to see how a shift actually went, let alone to fit
 * a model to it.
 *
 * So the TCU records it itself. A ring in PSRAM is filled from
 * Gearbox::controller_loop at its native 20 ms period, which is also the period
 * ShiftingAlgorithm steps at (SHIFT_DELAY_MS), so the capture is lossless with
 * respect to the algorithm. The host reads the ring out afterwards, in the quiet
 * time between shifts.
 *
 * Nothing here runs inside the shift control path, and the sampler is O(1) with
 * no allocation.
 *
 * Readout: fetch ShiftTraceHeader from RLI_SHIFT_TRACE, then pull samples with
 * ReadMemoryByAddress using `buffer_addr` (each response carries at most 255
 * bytes and the host asks for one chunk at a time, so the USB serial bridge's
 * FIFO is never burst through). `seq` counts every sample ever written, so
 * sample n is still in the ring while `seq - n < capacity`, which is also how
 * the host detects an overrun.
 */

#define SHIFT_TRACE_MAGIC 0x43415254u  // 'TRAC'
#define SHIFT_TRACE_VERSION 1u
#define SHIFT_TRACE_CAPACITY 512u      // 512 * 20 ms = 10.2 s of history
#define SHIFT_TRACE_EVENTS 4u

struct ShiftTraceSample {
    uint32_t t_ms;          // GET_CLOCK_TIME() when sampled
    uint16_t input_rpm;
    uint16_t output_rpm;
    uint16_t engine_rpm;
    int16_t  input_torque;
    uint16_t p_on;          // on clutch pressure  (mBar)
    uint16_t p_off;         // off clutch pressure (mBar)
    uint16_t spc;           // corrected shift pressure      (mBar)
    uint16_t mpc;           // corrected modulating pressure (mBar)
    uint8_t  phase;         // ShiftingAlgorithm phase id
    uint8_t  subphase_shift;
    uint8_t  subphase_mod;
    uint8_t  flags;         // bit0 shifting, bits 1-4 shift circuit flags
    uint8_t  pedal;         // raw, 0-250
    uint8_t  gear;          // actual << 4 | target
} __attribute__((packed));  // 26 bytes

struct ShiftTraceEvent {
    uint32_t seq_start;     // sample index at which the shift began
    uint32_t seq_end;       // sample index at which it ended (valid when done)
    uint8_t  gear_from;
    uint8_t  gear_to;
    uint8_t  done;
    uint8_t  _pad;
} __attribute__((packed));  // 12 bytes

struct ShiftTraceHeader {
    uint32_t magic;
    uint8_t  version;
    uint8_t  sample_size;
    uint16_t capacity;
    uint32_t buffer_addr;   // real address of sample 0, for ReadMemoryByAddress
    uint32_t seq;           // total samples written since boot
    uint32_t dropped;       // shifts whose window was overwritten before readout
    uint8_t  n_events;      // number of valid entries in `events`
    uint8_t  _pad[3];
    ShiftTraceEvent events[SHIFT_TRACE_EVENTS];
} __attribute__((packed));

// The host decoder (logger/nag52logger/shift_trace.py) unpacks these by size, and
// the header carries sample_size so a mismatch is reported rather than silently
// mis-decoded. Pin them here so the two cannot drift apart unnoticed.
static_assert(sizeof(ShiftTraceSample) == 26, "ShiftTraceSample must stay 26 bytes");
static_assert(sizeof(ShiftTraceEvent) == 12, "ShiftTraceEvent must stay 12 bytes");
static_assert(sizeof(ShiftTraceHeader) == 24 + (12 * SHIFT_TRACE_EVENTS), "ShiftTraceHeader layout changed");

namespace ShiftTrace {
    /// Allocate the ring. Safe to fail - tracing is then simply inactive.
    void init(void);
    /// One sample. Called from Gearbox::controller_loop every 20 ms.
    void sample(const SensorData* sd, const ShiftAlgoFeedback* algo, bool shifting,
                uint8_t gear_actual, uint8_t gear_target, uint16_t spc, uint16_t mpc,
                uint8_t circuit_flags);
    /// Header for the diagnostic readout, or nullptr if tracing is inactive.
    const ShiftTraceHeader* get_header(void);
}

#endif
