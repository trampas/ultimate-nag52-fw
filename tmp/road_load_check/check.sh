#!/bin/bash
# Does the firmware's road load prediction still agree with the script that
# validated it?
#
# RoadLoadEstimator::predict_accel_mms2 (src/road_load.cpp) and the model in
# scripts/next_gear.py are the same physics written twice. This repo has already
# learned what that costs - see "Doing it on the controller" in
# tmp/algorithms/shift-quality-metrics.md - so the two are pinned against each
# other here rather than trusted to stay in step.
#
# Compiles the real road_load.cpp for the host against the shift_replay stubs,
# runs both implementations over the same inputs, and fails on any disagreement
# larger than integer truncation.
#
# Usage: tmp/road_load_check/check.sh
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
FW=$(cd "$HERE/../.." && pwd)
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT

g++ -std=gnu++17 -O1 -w -include "$FW/tmp/shift_replay/stubs/preinclude.h" \
    -I"$FW/tmp/shift_replay" -I"$FW/tmp/shift_replay/stubs" \
    -I"$FW/src" -I"$FW" -I"$FW/lib/core" \
    "$HERE/main.cpp" "$FW/src/road_load.cpp" -o "$OUT/rl_check"

# out_rpm input_torque ratio - spanning the gears, a coasting case, and a
# standstill the prediction must refuse to answer.
CASES="1500 200 1.000 1500 200 0.830 800 120 2.408 2000 300 1.486 1500 -50 1.000 400 250 3.932 3000 380 1.000"
"$OUT/rl_check" $CASES > "$OUT/cpp.txt"

"$FW/.venv/bin/python" - "$OUT/cpp.txt" $CASES <<'PY'
import math, sys
# The seed state from RoadLoadEstimator::init(): a plausible car on a flat road.
# Seed rather than a converged fit, because both sides must start identical for
# the comparison to mean anything.
th0, th1 = 1.0 / 1700.0, 0.013
diff, circ = 3.070, 1.975            # matches the VEHICLE_CONFIG the harness sets
r_wheel = circ / (2 * math.pi)
RHO_CDA, G = 0.744, 9.81

def pred(out_rpm, trq, ratio):
    v = out_rpm / 60.0 / diff * circ
    r_g = r_wheel / (ratio * diff)
    a = ((trq / r_g) - RHO_CDA * v * v) * th0 - G * th1
    return a * 1000.0          # mm/s^2, SI, matching the firmware

cpp = [int(x) for x in open(sys.argv[1]).read().split()]
args = [float(x) for x in sys.argv[2:]]
cases = [tuple(args[i:i + 3]) for i in range(0, len(args), 3)]
assert len(cpp) == len(cases), "%d results for %d cases" % (len(cpp), len(cases))

bad = 0
print("%-26s %9s %9s %7s   (mm/s^2)" % ("out_rpm torque ratio", "python", "firmware", "delta"))
for c, e in zip(cases, cpp):
    p = pred(*c)
    d = p - e
    if abs(d) > 1.0:
        bad += 1
    print("%-26s %9.1f %9d %7.1f%s" % (
        "%.0f %.0f %.3f" % c, p, e, d, "   <-- DRIFT" if abs(d) > 1.0 else ""))
if bad:
    print("\n%d case(s) disagree by more than integer truncation." % bad)
    print("The firmware and scripts/next_gear.py no longer share a model; the")
    print("offline validation of the anti-bog check does not describe the car.")
    sys.exit(1)
print("\nagree")
PY
