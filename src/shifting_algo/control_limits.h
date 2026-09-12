#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>

// Pure control primitives, shared by the firmware and host regression tests.
namespace ShiftControl {
inline float clamp(float v, float lo, float hi) {
    return std::max(lo, std::min(v, hi));
}

// Conditional integration: do not accumulate error that drives an already
// limited actuator farther into its limit. An error reversal may unwind it.
inline float pid(float error, float previous_error, float& integral,
                 float kp, float ki, float kd, float dt_scale,
                 float lower, float upper) {
    dt_scale = clamp(dt_scale, 0.25f, 2.5f);
    const float candidate = clamp(integral + error * dt_scale, -32768, 32767);
    const float pd = kp * error + kd * (error - previous_error) / dt_scale;
    const float output = pd + ki * candidate;
    const float integral_step = ki * (candidate - integral);
    if (!((output > upper && integral_step > 0) ||
          (output < lower && integral_step < 0))) {
        integral = candidate;
    }
    return clamp(pd + ki * integral, lower, upper);
}

inline float turbine_target(float previous, float actual, float synchronous,
                            float step, bool upshift) {
    // An upshift that ran ahead of the planned trajectory must not be ordered
    // to accelerate back toward the old gear. Never ramp past the new ratio.
    return upshift ? std::max(synchronous, std::min(previous - step, actual))
                   : std::min(synchronous, previous + step);
}

inline float releasing_torque(float previous, float requested, float minimum,
                             float freeing, float target_ms, float dt_ms) {
    // Once release has begun, a pedal rise must not re-clamp the old clutch.
    // Spend half the target inertia time releasing the freeing-torque budget;
    // speed feedback takes over as soon as the off clutch starts to move.
    const float rate = std::max(0.0f, freeing) / std::max(100.0f, target_ms * 0.5f);
    return std::max(minimum, std::min(previous, requested) - rate * dt_ms);
}
}
