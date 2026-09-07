#!/usr/bin/env python3
"""
Estimate vehicle mass and road grade from a drive log.

Method follows Vahidi, Stefanopoulou & Peng, "Recursive Least Squares with
Forgetting for Online Estimation of Vehicle Mass and Road Grade" (Vehicle System
Dynamics 43:1). Longitudinal dynamics in linear parametric form:

    y = phi^T theta      theta = [ 1/M , sin(beta + beta_mu) ]
    y    = dv/dt
    phi1 = (T - J*dw/dt)/r_g - F_aero        r_g = r_wheel / (gear * final drive)
    phi2 = -g

The two parameters change at very different rates - mass is piecewise constant,
grade is time varying - which is why a single forgetting factor cannot track
both, and why the paper uses one per parameter. That is the whole trick.

Notes specific to this car:

* Torque is taken at the TURBINE, not the flywheel, and the gear ratio excludes
  the final drive accordingly. The paper assumes a locked converter; we do not
  have to, because the TCU already models turbine torque.
* Braking is excluded rather than modelled. The paper does the same ("we will
  dismiss portions of data in which service brakes were activated") because
  turning brake pressure into force needs a model they did not have. Logs from
  2026-09 onward carry brake_pressed in the driving_dynamics record; older ones
  do not, and there the only safe thing is to drop every decelerating sample,
  which discards most of a drive.
* Gear shifts are excluded - the paper flags parameter tracking during a shift
  as a known difficulty.

The estimate is only meaningful when the input is persistently exciting; a
steady cruise identifies nothing. Convergence is reported so a flat result is
visible rather than mistaken for an answer.
"""
from __future__ import annotations

import argparse
import math
import os
import statistics
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "logger"))
from nag52logger.reader import LogFile  # noqa: E402

RATIOS = {1: 3.932, 2: 2.408, 3: 1.486, 4: 1.000, 5: 0.830}
GEAR_IDX = {"D1": 1, "D2": 2, "D3": 3, "D4": 4, "D5": 5}
G = 9.81
RHO = 1.2
CDA = 0.62              # W210 saloon, Cd ~0.29 x A ~2.1
J_TURBINE = 0.16        # kg m^2, fitted from logged inertia phases
LAMBDA_MASS = 1.0       # mass is constant - do not forget it
LAMBDA_GRADE = 0.98     # grade changes with the road - forget quickly


def estimate(log, diff, circ, verbose=False, torque_scale=1.0):
    r_wheel = circ / (2.0 * math.pi)
    # theta = [1/M, sin(beta+beta_mu)]; seed with a plausible car and flat road
    theta = [1.0 / 1700.0, 0.013]
    P = [[1e-8, 0.0], [0.0, 1e-3]]
    rows, used, skipped = [], 0, 0
    prev = None
    for c in log.cycles:
        s, can, live = c.get("sensors") or {}, c.get("can") or {}, c.get("shift_live") or {}
        o, i = s.get("output_rpm"), s.get("input_rpm")
        trq, g = live.get("input_torque"), str(live.get("actual_gear"))
        ped = can.get("pedal_pos")
        if None in (o, i, trq, ped) or g not in GEAR_IDX:
            prev = None
            continue
        v = o / 60.0 / diff * circ
        w = i * 2.0 * math.pi / 60.0
        if prev is None:
            prev = (c["t"], v, w, g)
            continue
        dt = c["t"] - prev[0]
        if not (0.03 < dt < 0.15) or g != prev[3]:
            prev = (c["t"], v, w, g)
            continue
        # Exclude: shifting, braking, and too slow for the model to mean anything.
        # With a brake signal we only have to drop actual braking, which keeps the
        # coasting samples; without one, every zero-pedal sample has to go.
        dyn = c.get("driving_dynamics") or {}
        braking = bool(dyn.get("brake_pressed")) if "brake_pressed" in dyn else (ped == 0)
        if (c.get("shift_algo") or {}).get("active") or braking or trq <= 0 or v < 4.0:
            prev = (c["t"], v, w, g)
            skipped += 1
            continue
        dv, dw = (v - prev[1]) / dt, (w - prev[2]) / dt
        prev = (c["t"], v, w, g)
        r_g = r_wheel / (RATIOS[GEAR_IDX[g]] * diff)
        phi1 = (trq * torque_scale - J_TURBINE * dw) / r_g - 0.5 * RHO * CDA * v * v
        phi2 = -G
        y = dv
        # RLS update with per-parameter forgetting
        Pphi = [P[0][0] * phi1 + P[0][1] * phi2, P[1][0] * phi1 + P[1][1] * phi2]
        denom = 1.0 + phi1 * Pphi[0] + phi2 * Pphi[1]
        K = [Pphi[0] / denom, Pphi[1] / denom]
        err = y - (phi1 * theta[0] + phi2 * theta[1])
        theta = [theta[0] + K[0] * err, theta[1] + K[1] * err]
        P = [[P[0][0] - K[0] * Pphi[0], P[0][1] - K[0] * Pphi[1]],
             [P[1][0] - K[1] * Pphi[0], P[1][1] - K[1] * Pphi[1]]]
        P[0][0] /= LAMBDA_MASS
        P[1][1] /= LAMBDA_GRADE
        if theta[0] < 1.0 / 4000.0:
            theta[0] = 1.0 / 4000.0        # keep mass physical while it converges
        if theta[0] > 1.0 / 700.0:
            theta[0] = 1.0 / 700.0
        used += 1
        rows.append((c["t"], 1.0 / theta[0], math.degrees(math.asin(max(-0.3, min(0.3, theta[1])))), v))
    return rows, used, skipped


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log")
    ap.add_argument("--diff", type=float, default=None, help="final drive (default: from the log)")
    ap.add_argument("--circ", type=float, default=None, help="wheel circumference m (default: from the log)")
    ap.add_argument("--mass", type=float, default=None, metavar="KG",
                    help="known vehicle mass - solves for the engine torque scale "
                         "factor instead of the mass, i.e. how much of its mapped "
                         "torque the engine is actually delivering")
    args = ap.parse_args()
    log = LogFile.load(args.log)
    cfg = (log.snapshot.get("records") or {}).get("tcm_config") or {}
    diff = args.diff or (cfg.get("diff_ratio", 3070) / 1000.0)
    circ = args.circ or (cfg.get("wheel_circumference", 1975) / 1000.0)
    print("final drive %.3f, wheel circumference %.3f m" % (diff, circ))
    if args.mass:
        # Fix mass, solve for the torque scale. The ECM reports torque from
        # factory maps, not what a worn engine actually delivers, and that error
        # goes straight into phi1 - which is why an implausible mass is the
        # symptom of a torque bias rather than a broken estimator.
        best, best_err = None, None
        for k in [x / 100.0 for x in range(50, 151, 2)]:
            rows, used, _ = estimate(log, diff, circ, torque_scale=k)
            if used < 50:
                continue
            m = statistics.median([r[1] for r in rows[len(rows) // 2:]])
            err = abs(m - args.mass)
            if best_err is None or err < best_err:
                best, best_err = k, err
        if best is None:
            print("not enough data")
            return 1
        rows, used, _ = estimate(log, diff, circ, torque_scale=best)
        g = [r[2] for r in rows[len(rows) // 2:]]
        print("assuming %.0f kg, the engine is delivering %.0f %% of the torque the "
              "ECM reports" % (args.mass, best * 100))
        print("  (a %.0f %% shortfall - driveline losses, rotating inertia and engine "
              "wear all land here)" % ((1 - best) * 100))
        print("  grade with that correction: median %+.2f deg, range %+.2f to %+.2f" % (
            statistics.median(g), min(g), max(g)))
        return 0
    rows, used, skipped = estimate(log, diff, circ)
    if used < 50:
        print("only %d usable samples - not enough excitation to identify anything" % used)
        return 1
    settle = rows[len(rows) // 2:]
    mass = [r[1] for r in settle]
    grade = [r[2] for r in settle]
    print("%d samples used, %d excluded (shifting, overrun or too slow)\n" % (used, skipped))
    print("mass   %6.0f kg   (last half: median %.0f, spread %.0f-%.0f)" % (
        rows[-1][1], statistics.median(mass), min(mass), max(mass)))
    print("grade  %+6.2f deg  (median %+.2f, range %+.2f to %+.2f over the drive)" % (
        rows[-1][2], statistics.median(grade), min(grade), max(grade)))
    print("\nconvergence of the mass estimate:")
    n = len(rows)
    for i in range(10):
        seg = rows[i * n // 10:(i + 1) * n // 10]
        print("  %3d%%  %6.0f kg   grade %+5.2f deg" % (
            (i + 1) * 10, statistics.median([r[1] for r in seg]),
            statistics.median([r[2] for r in seg])))
    print("\nA flat convergence trace means the drive did not excite the model -")
    print("the paper is explicit that the estimate needs persistent excitation.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
