#pragma once
#include <algorithm>
#include <cstdint>

namespace ShiftDemand {
inline float projected_rpm(float output_rpm, float output_accel_rpm_s,
                           float ratio, uint32_t duration_ms) {
    return (output_rpm + std::max(0.0f, output_accel_rpm_s) * duration_ms / 1000.0f) * ratio;
}

inline bool useful_downshift(float predicted_turbine, float converter_slip,
                            float redline, float next_upshift_point) {
    return redline > 1000 && predicted_turbine + std::max(0.0f, converter_slip) < redline - 500 &&
           predicted_turbine < next_upshift_point - 150;
}

// The raw switch is a held demand (false also means expired on the CAN HAL).
// Track it outside the shift-decision gate; release, missing pedal or leaving D
// cancels it. Never latch a release indefinitely while a shift is running.
inline bool kickdown(bool held, bool pedal_valid, uint8_t pedal, bool in_drive) {
    return held && pedal_valid && pedal > 10 && in_drive;
}

class LiftHold {
public:
    void update(uint32_t now, uint8_t pedal, bool valid, bool in_drive) {
        if (!valid || !in_drive) { armed = false; peak = pedal; peak_ms = now; return; }
        if (pedal >= peak || now - peak_ms > 250) { peak = pedal; peak_ms = now; }
        if (!armed && peak >= 125 && pedal < 125 && pedal + 62 <= peak) {
            armed = true;
            started = now;
            peak = pedal;
            peak_ms = now;
        }
        if (armed && (now - started >= 1000 || pedal >= 125)) { armed = false; }
    }
    bool active(uint32_t now) const { return armed && now - started < 1000; }
private:
    uint32_t peak_ms = 0, started = 0;
    uint8_t peak = 0;
    bool armed = false;
};
}
