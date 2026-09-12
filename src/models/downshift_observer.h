#pragma once
#include <cstdint>

// Observes the existing decision path. No demand evaluation or control side effects.
namespace DownshiftObserver {
enum class State : uint8_t {
    Unavailable, Shifting, TargetPending, RatioMismatch, NoRequest, UpshiftPriority,
    HuntingInhibit, CannotFinish, NoReserve, RpmVeto, Accepted, NoProfile, Count
};
constexpr uint8_t STATE_COUNT = static_cast<uint8_t>(State::Count);
constexpr uint8_t CAPACITY = 16;
struct Transition {
    uint32_t t_ms;
    uint8_t state, actual, target, flags; // flags: bit0 manual, bit1 kickdown
} __attribute__((packed));
struct Snapshot {
    uint8_t version = 1, count = 0, capacity = CAPACITY, reserved = 0;
    uint32_t t_ms = 0, seq = 0; // seq counts transitions, not polls
    uint32_t elapsed_ms[STATE_COUNT] = {};
    Transition transitions[CAPACITY] = {}; // oldest first; first sequence is seq-count
} __attribute__((packed));
static_assert(sizeof(Snapshot) == 188, "RLI 0x34 wire layout changed");

// Caller serializes update/read (controller and KWP run on different tasks).
class Recorder {
public:
    void update(uint32_t now, State state, uint8_t actual, uint8_t target, uint8_t flags) {
        if (initialized) {
            totals[previous.state] += now - last_ms; // unsigned clock wrap
        }
        last_ms = now;
        if (!initialized || previous.state != static_cast<uint8_t>(state) ||
            previous.actual != actual || previous.target != target || previous.flags != flags) {
            previous = {now, static_cast<uint8_t>(state), actual, target, flags};
            ring[next] = previous;
            next = (next + 1) % CAPACITY;
            if (count < CAPACITY) { ++count; }
            ++seq;
        }
        initialized = true;
    }
    Snapshot read() const {
        Snapshot out;
        out.t_ms = last_ms;
        out.seq = seq;
        out.count = count;
        for (uint8_t i = 0; i < STATE_COUNT; ++i) { out.elapsed_ms[i] = totals[i]; }
        for (uint8_t i = 0; i < count; ++i) {
            out.transitions[i] = ring[(next + CAPACITY - count + i) % CAPACITY];
        }
        return out;
    }
private:
    bool initialized = false;
    uint8_t next = 0, count = 0;
    uint32_t last_ms = 0, seq = 0, totals[STATE_COUNT] = {};
    Transition previous = {}, ring[CAPACITY] = {};
};
}
