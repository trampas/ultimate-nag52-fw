#include "shift_trace.h"
#include "tcu_alloc.h"
#include "clock.hpp"
#include "esp_log.h"
#include <string.h>

static ShiftTraceHeader trace_header = {};
static ShiftTraceSample* trace_ring = nullptr;
static bool was_shifting = false;

void ShiftTrace::init(void) {
    // PSRAM: 13 KB is nothing there, and keeping it out of internal RAM leaves
    // the shift task's headroom alone.
    // TCU_HEAP_ALLOC is already the PSRAM heap on ESP32.
    trace_ring = static_cast<ShiftTraceSample*>(
        TCU_HEAP_ALLOC(SHIFT_TRACE_CAPACITY * sizeof(ShiftTraceSample)));
    if (nullptr == trace_ring) {
        // Not fatal - the TCU drives fine without a trace, so say so and move on.
        ESP_LOG_LEVEL(ESP_LOG_WARN, "TRACE", "Shift trace buffer allocation failed, tracing disabled");
        return;
    }
    memset(trace_ring, 0x00, SHIFT_TRACE_CAPACITY * sizeof(ShiftTraceSample));
    trace_header.magic = SHIFT_TRACE_MAGIC;
    trace_header.version = SHIFT_TRACE_VERSION;
    trace_header.sample_size = (uint8_t)sizeof(ShiftTraceSample);
    trace_header.capacity = (uint16_t)SHIFT_TRACE_CAPACITY;
    trace_header.buffer_addr = (uint32_t)trace_ring;
    trace_header.seq = 0;
    trace_header.dropped = 0;
    trace_header.n_events = 0;
    ESP_LOG_LEVEL(ESP_LOG_INFO, "TRACE", "Shift trace ready: %u samples x %u bytes at 0x%08X (%u ms of history)",
        (unsigned)SHIFT_TRACE_CAPACITY, (unsigned)sizeof(ShiftTraceSample),
        (unsigned)trace_header.buffer_addr, (unsigned)(SHIFT_TRACE_CAPACITY * 20u));
}

const ShiftTraceHeader* ShiftTrace::get_header(void) {
    return (nullptr == trace_ring) ? nullptr : &trace_header;
}

/**
 * @brief Start a new event, retiring the oldest if the list is full.
 *
 * Events are kept newest-last so the host can walk them in order. Four is
 * enough: a shift's window is ~2.3 s and draining it costs ~72 ms, while the
 * shortest gap between shifts seen on the road is ~1.9 s.
 */
static void push_event(uint32_t seq, uint8_t from, uint8_t to) {
    if (trace_header.n_events == SHIFT_TRACE_EVENTS) {
        // Oldest event is about to be lost. If the host never read it, its
        // samples are long gone from the ring too - count it so a gap in the
        // recorded shifts is visible rather than silent.
        if (0 == trace_header.events[0].done ||
            (trace_header.seq - trace_header.events[0].seq_start) >= SHIFT_TRACE_CAPACITY) {
            trace_header.dropped += 1;
        }
        memmove(&trace_header.events[0], &trace_header.events[1],
                sizeof(ShiftTraceEvent) * (SHIFT_TRACE_EVENTS - 1));
        trace_header.n_events -= 1;
    }
    ShiftTraceEvent* e = &trace_header.events[trace_header.n_events];
    e->seq_start = seq;
    e->seq_end = seq;
    e->gear_from = from;
    e->gear_to = to;
    e->done = 0;
    e->_pad = 0;
    trace_header.n_events += 1;
}

void ShiftTrace::sample(const SensorData* sd, const ShiftAlgoFeedback* algo, bool shifting,
                        uint8_t gear_actual, uint8_t gear_target, uint16_t spc, uint16_t mpc,
                        uint8_t circuit_flags) {
    if (nullptr == trace_ring || nullptr == sd || nullptr == algo) {
        return;
    }
    ShiftTraceSample* s = &trace_ring[trace_header.seq % SHIFT_TRACE_CAPACITY];
    s->t_ms = GET_CLOCK_TIME();
    s->input_rpm = sd->input_rpm;
    s->output_rpm = sd->output_rpm;
    s->engine_rpm = sd->engine_rpm;
    s->input_torque = sd->input_torque;
    s->p_on = algo->p_on;
    s->p_off = algo->p_off;
    s->spc = spc;
    s->mpc = mpc;
    s->phase = algo->shift_phase;
    s->subphase_shift = algo->subphase_shift;
    s->subphase_mod = algo->subphase_mod;
    s->flags = (shifting ? 0x01u : 0x00u) | (uint8_t)((circuit_flags & 0x0Fu) << 1);
    s->pedal = (sd->pedal_pos > 250) ? 250u : (uint8_t)sd->pedal_pos;
    s->gear = (uint8_t)((gear_actual & 0x0Fu) << 4 | (gear_target & 0x0Fu));

    // Shift boundaries are detected here rather than hooked into elapse_shift,
    // so the shift control path is untouched.
    if (shifting && !was_shifting) {
        push_event(trace_header.seq, gear_actual, gear_target);
    } else if (!shifting && was_shifting && trace_header.n_events > 0) {
        ShiftTraceEvent* e = &trace_header.events[trace_header.n_events - 1];
        if (0 == e->done) {
            e->seq_end = trace_header.seq;
            e->done = 1;
        }
    }
    was_shifting = shifting;
    trace_header.seq += 1;
}
