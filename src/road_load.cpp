#include "road_load.h"
#include "nvs/eeprom_config.h"
#include "clock.hpp"
#include "esp_log.h"
#include <math.h>

// Forgetting factors, one per parameter - the point of the method. Mass does not
// change while driving, so it is never forgotten; grade changes with the road.
#define LAMBDA_MASS   1.00f
#define LAMBDA_GRADE  0.98f

#define UPDATE_MS       100     // 10 Hz is ample; RLS does not need the control rate
#define MIN_SPEED_MS    4.0f    // below this the model means little
#define J_TURBINE       0.16f   // kg m^2, fitted from logged inertia phases
#define RHO_CDA         0.744f  // 0.5 * 1.2 * 0.62 (W210 saloon Cd x A)
#define GRAVITY         9.81f
#define MASS_MIN        700.0f
#define MASS_MAX        4000.0f

static float theta[2];          // [1/M, sin(grade + rolling)]
static float P[2][2];
static float r_wheel = 0.0f;
static float diff_ratio = 0.0f;
static uint32_t last_ms = 0;
static float prev_v = 0.0f, prev_w = 0.0f;
static bool have_prev = false;
static uint16_t updates = 0;
static bool updating_now = false;

void RoadLoadEstimator::init(void) {
    // Seed with a plausible car on a flat road; RLS pulls it from there.
    theta[0] = 1.0f / 1700.0f;
    theta[1] = 0.013f;                 // rolling resistance with no grade
    P[0][0] = 1e-8f; P[0][1] = 0.0f;
    P[1][0] = 0.0f;  P[1][1] = 1e-3f;
    updates = 0;
    have_prev = false;
    if (VEHICLE_CONFIG.diff_ratio != 0) {
        diff_ratio = (float)VEHICLE_CONFIG.diff_ratio / 1000.0f;
        r_wheel = ((float)VEHICLE_CONFIG.wheel_circumference / 1000.0f) / (2.0f * (float)M_PI);
    }
}

RoadLoad RoadLoadEstimator::get(void) {
    float m = (theta[0] > 1e-6f) ? (1.0f / theta[0]) : 0.0f;
    return RoadLoad {
        .terrain_coeff = (int16_t)(theta[1] * 10000.0f),
        .mass_kg = (uint16_t)((m > 0.0f && m < 65535.0f) ? m : 0),
        // Confidence is just how much usable data has been seen. The estimate is
        // only meaningful with persistent excitation, and a steady cruise
        // identifies nothing, so a consumer needs to know how much to trust it.
        .confidence = (uint8_t)((updates > 500u) ? 100u : (updates / 5u)),
        .updating = (uint8_t)(updating_now ? 1 : 0),
    };
}

int16_t RoadLoadEstimator::predict_accel_mms2(const SensorData* sd, float gear_ratio) {
    if (nullptr == sd || r_wheel <= 0.0f || gear_ratio <= 0.0f || theta[0] <= 1e-6f) {
        return 0;
    }
    float circ = (float)VEHICLE_CONFIG.wheel_circumference / 1000.0f;
    if (circ <= 0.0f || diff_ratio <= 0.0f) {
        return 0;
    }
    float v = ((float)sd->output_rpm / 60.0f / diff_ratio) * circ;
    float r_g = r_wheel / (gear_ratio * diff_ratio);
    // m/s^2 in the candidate gear
    float a = ((((float)sd->input_torque / r_g) - (RHO_CDA * v * v)) * theta[0])
              - (GRAVITY * theta[1]);
    // Reported in mm/s^2 so the threshold it is compared against can be written
    // in SI and mean something to whoever sets it.
    float mms2 = a * 1000.0f;
    if (mms2 > 32000.0f) { mms2 = 32000.0f; }
    if (mms2 < -32000.0f) { mms2 = -32000.0f; }
    return (int16_t)mms2;
}

void RoadLoadEstimator::update(const SensorData* sd, float gear_ratio,
                               bool shifting, bool braking) {
    updating_now = false;
    if (nullptr == sd || r_wheel <= 0.0f || gear_ratio <= 0.0f) {
        return;
    }
    uint32_t now = GET_CLOCK_TIME();
    if (now - last_ms < UPDATE_MS) {
        return;
    }
    float dt = (float)(now - last_ms) / 1000.0f;
    last_ms = now;

    float v = ((float)sd->output_rpm / 60.0f / diff_ratio) *
              ((float)VEHICLE_CONFIG.wheel_circumference / 1000.0f);
    float w = (float)sd->input_rpm * 2.0f * (float)M_PI / 60.0f;

    // Conditions the method needs. Anything else and we keep the state but do
    // not update - a bad sample is worse than no sample.
    bool usable = !shifting && !braking && sd->input_torque > 0 && v >= MIN_SPEED_MS;
    if (!have_prev || dt > 0.5f || !usable) {
        prev_v = v; prev_w = w; have_prev = true;
        return;
    }
    float dv = (v - prev_v) / dt;
    float dw = (w - prev_w) / dt;
    prev_v = v; prev_w = w;

    float r_g = r_wheel / (gear_ratio * diff_ratio);
    float phi1 = (((float)sd->input_torque - J_TURBINE * dw) / r_g) - (RHO_CDA * v * v);
    float phi2 = -GRAVITY;
    float y = dv;

    float Pp0 = P[0][0] * phi1 + P[0][1] * phi2;
    float Pp1 = P[1][0] * phi1 + P[1][1] * phi2;
    float denom = 1.0f + phi1 * Pp0 + phi2 * Pp1;
    if (fabsf(denom) < 1e-9f) {
        return;
    }
    float k0 = Pp0 / denom;
    float k1 = Pp1 / denom;
    float err = y - (phi1 * theta[0] + phi2 * theta[1]);
    theta[0] += k0 * err;
    theta[1] += k1 * err;
    P[0][0] -= k0 * Pp0; P[0][1] -= k0 * Pp1;
    P[1][0] -= k1 * Pp0; P[1][1] -= k1 * Pp1;
    // Per-parameter forgetting: keep mass, let grade go stale quickly.
    P[0][0] /= LAMBDA_MASS;
    P[1][1] /= LAMBDA_GRADE;

    // Keep the parameters physical while they converge, and guard against a
    // divergence putting nonsense into anything that reads this later.
    if (theta[0] < 1.0f / MASS_MAX) { theta[0] = 1.0f / MASS_MAX; }
    if (theta[0] > 1.0f / MASS_MIN) { theta[0] = 1.0f / MASS_MIN; }
    if (theta[1] < -0.30f) { theta[1] = -0.30f; }   // ~17 degrees, beyond any road
    if (theta[1] > 0.30f)  { theta[1] = 0.30f; }
    if (!isfinite(theta[0]) || !isfinite(theta[1]) ||
        !isfinite(P[0][0]) || !isfinite(P[1][1])) {
        ESP_LOG_LEVEL(ESP_LOG_WARN, "ROADLOAD", "Estimator diverged, resetting");
        RoadLoadEstimator::init();
        return;
    }
    if (updates < 60000u) { updates += 1; }
    updating_now = true;
}
