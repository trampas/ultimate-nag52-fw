// Real trace recorder with only platform services stubbed by the test runner.
#include "shift_trace.cpp"
#include <cassert>
TCM_CORE_CONFIG VEHICLE_CONFIG = {};
MechanicalCalibration* MECH_PTR = nullptr;
SBS_MODULE_SETTINGS SBS_CURRENT_SETTINGS = SBS_DEFAULT_SETTINGS;
static uint32_t now_ms = 0;
uint32_t GET_CLOCK_TIME() { return now_ms; }
void sim_log(const char*, const char*, const char*, ...) {}
int main() {
    ShiftTrace::init();
    SensorData sd = {};
    sd.output_rpm = 1000; sd.input_rpm = 2000; sd.atf_temp = 65;
    ShiftAlgoFeedback fb = {};
    auto sample = [&](bool shifting, uint32_t id) {
        now_ms += 20;
        ShiftTrace::sample(&sd, &fb, shifting, 3, 2, 3000, 3000, 1, 120, 200, 50, 0, id, true, 120, 54);
    };
    ShiftStamp first = {}; first.flags = SHIFT_STAMP_ANNOTATED; first.target_time_ms = 500;
    ShiftTrace::annotate(&first, 1);
    sample(true, 1); sample(true, 1);
    ShiftStamp second = first; second.target_time_ms = 800;
    ShiftTrace::annotate(&second, 2); // Next shift starts before sampler saw an idle cycle.
    ShiftTrace::mark(SHIFT_STAMP_KICKDOWN, 2);
    sample(true, 2);
    const auto* h = ShiftTrace::get_header();
    assert(h && h->n_events == 2);
    assert(h->events[0].done && h->events[0].shift_id == 1);
    assert(h->events[0].seq_end == h->events[1].seq_start);
    assert(h->events[0].quality.duration_ms == 40);
    assert(h->events[0].stamp.target_time_ms == 500);
    assert(!(h->events[0].stamp.flags & SHIFT_STAMP_KICKDOWN));
    assert(h->events[1].stamp.target_time_ms == 800);
    assert(h->events[1].stamp.flags & SHIFT_STAMP_KICKDOWN);
    assert(h->events[1].atf_temp_start == 65);
    ShiftTraceEvent done;
    assert(ShiftTrace::take_completed(&done) && done.shift_id == 1);
    ShiftTrace::record_adaptation(0, 0, 0, 10);
    assert(h->events[0].stamp.shift_time_delta == 10);
    assert(h->events[0].stamp.flags & SHIFT_STAMP_ADAPTED);
    sample(true, 2); sample(false, 2);
    assert(h->events[1].done && h->events[1].quality.duration_ms == 40);
    assert(ShiftTrace::take_completed(&done) && done.shift_id == 2);
    ShiftTrace::record_adaptation(0, 0, 0, 0);
    assert(h->events[1].stamp.shift_time_delta == 0);
    assert(!(h->events[1].stamp.flags & SHIFT_STAMP_ADAPTED));
    assert(!ShiftTrace::take_completed(&done));
    // Late annotations also attach to the right event, never its predecessor.
    sample(true, 3);
    ShiftTrace::annotate(&first, 3);
    sample(false, 3);
    assert(h->events[2].stamp.target_time_ms == 500);
    for (uint32_t id = 4; id < 10; ++id) { sample(true, id); sample(false, id); }
    assert(h->n_events == 4 && h->events[3].shift_id == 9);
}
