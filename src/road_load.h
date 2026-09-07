#ifndef ROAD_LOAD_H
#define ROAD_LOAD_H

#include <stdint.h>
#include "common_structs.h"

/**
 * @brief Online estimate of how hard the road is working the car.
 *
 * Method from Vahidi, Stefanopoulou & Peng, "Recursive Least Squares with
 * Forgetting for Online Estimation of Vehicle Mass and Road Grade" (Vehicle
 * System Dynamics 43:1). Longitudinal dynamics in linear parametric form:
 *
 *     y = phi^T theta,   theta = [ 1/M , sin(beta + beta_mu) ]
 *     y    = dv/dt
 *     phi1 = (T - J dw/dt) / r_g  -  F_aero
 *     phi2 = -g
 *
 * Mass is piecewise constant and grade is time varying, so they need different
 * forgetting factors - that is the whole point of the paper, and a single
 * forgetting factor cannot track both.
 *
 * Why this is worth having on a transmission controller: SAE 930674 identifies
 * running resistance estimation as the standard way to stop a shift schedule
 * hunting, and a TCU without it shifts too often and runs out of pull on a
 * climb. It is also the third axis of Miao, Liu & Zhu's three-parameter shift
 * schedule, where a terrain coefficient joins pedal and speed.
 *
 * ABSOLUTE VALUES ARE NOT TRUSTWORTHY HERE, AND DO NOT NEED TO BE. The ECM
 * reports torque from factory maps rather than what a worn engine delivers, and
 * that bias lands directly in phi1. Checked against a drive log: scaling torque
 * from 0.7 to 1.1 moves the mass estimate from 1808 to 2805 kg - it *is* the
 * torque error - while the grade estimate moves only from +1.02 to +1.25 deg,
 * because grade is identified from how the same torque produces different
 * acceleration on different slopes. So terrain_coeff is usable and mass_kg is
 * really a combined mass-and-torque-scale figure. Treat it as relative.
 *
 * Nothing consumes this yet. It is here so the signal exists to build a
 * grade-aware shift schedule against, and so it can be checked on the road
 * before anything depends on it.
 */
struct RoadLoad {
    int16_t terrain_coeff;  // sin(grade + rolling resistance) x 10000
    uint16_t mass_kg;       // mass combined with the engine torque scale error
    uint8_t confidence;     // 0-100, how much excitation has been seen
    uint8_t updating;       // 1 when conditions currently allow an update
};

namespace RoadLoadEstimator {
    void init(void);
    /**
     * @brief One RLS step. Call at a steady rate with the car in gear.
     *
     * Skips itself unless the conditions the method needs hold: not shifting
     * (the paper flags tracking through a shift as a known difficulty), not
     * braking (brake force cannot be turned into torque without a model the TCU
     * does not have, so those samples are dropped rather than modelled), under
     * power, and moving fast enough for the model to mean anything.
     */
    void update(const SensorData* sd, float gear_ratio, bool shifting, bool braking);
    RoadLoad get(void);

    /**
     * @brief Predicted output shaft acceleration if the car were in a gear of
     *        this ratio right now, in output shaft RPM/s.
     *
     * The same model the estimator fits, run forwards instead of backwards:
     *
     *     a = ( T / r_g  -  F_aero ) / M  -  g * sin(grade)
     *
     * with M and the grade taken from the fitted state. Both the fit and this
     * prediction use the ECM's reported torque, so the ECM's scale error is
     * common to the two and cancels - which is the only reason a figure built
     * on an admittedly wrong mass is worth anything. Do not "improve" this by
     * correcting the torque here without correcting the fit as well.
     *
     * Torque is used unchanged, NOT scaled by a torque-vs-RPM curve for the
     * lower RPM the new gear lands at. That looks like an omission and is not:
     * measured over 91 upshifts in scripts/next_gear.py, a flat assumption
     * predicts better (correlation 0.62) than either the measured power curve
     * (0.59) or the ECM's own broadcast max torque (0.53).
     *
     * Returns 0 if the estimator has no usable state.
     */
    int16_t predict_output_accel(const SensorData* sd, float gear_ratio);
}

#endif
