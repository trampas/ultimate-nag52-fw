#!/usr/bin/env python3
"""
Check the shift maps in src/maps.cpp against what the engine and gearbox can do.

Written after a run of road tests where each fix revealed the next problem,
because shift points were being tuned against complaints instead of against a
target band. Every check here corresponds to a defect that actually reached the
car and cost a drive:

  dead_band     Full throttle sat between the downshift threshold and the boost
                point, so it would neither pull nor downshift. Measured: 76 % of
                time above 70 % pedal was spent under 2400 rpm.
  never_coast   A coast column of 100 rpm meant "never downshift", so the box
                coasted to a standstill in 3rd and then slammed two power-on
                downshifts when the driver touched the throttle.
  hunt          A downshift that lands above the lower gear's upshift point
                shifts straight back up.
  ladder_time   Coast downshifts are serialised, each blocking the next, so a
                4-3-2-1 ladder that takes longer than the car takes to stop
                leaves the last shift completing at standstill - felt as a clunk
                on brake release.
  redline       A downshift that lands past the redline.
  monotonic     A map cell out of order with its neighbours (the 4-3 row had
                2100 at 90 % pedal and 2000 at 100 %).

Usage:
    scripts/shift_envelope.py            # check, exit 1 on any error
    scripts/shift_envelope.py --verbose  # also print the landing table
"""
from __future__ import annotations

import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAPS = os.path.join(REPO, "src", "maps.cpp")

# ---------------------------------------------------------------------------
# Vehicle envelope. These are the numbers a calibration has to be judged
# against; without them "is this shift point right?" has no answer.
#
# W210 1999 turbodiesel. Ratios and diff come from the TCU's own calibration
# block (read it back with LogFile.load(x).snapshot["calibration"], do not
# assume). The power band was measured from four drives at >75 % pedal using
# acceleration, speed and gear with a nominal mass - relative power, since only
# the shape matters for choosing shift points:
#
#     2000-2250 rpm   65 % of peak      3000-3250    85 %
#     2250-2500       76 %              3250-3750   100 %  <- peak
#     2500-3000       80-82 %           3750-4250    87-96 %
# ---------------------------------------------------------------------------
ENVELOPE = {
    "name": "W210 1999 diesel (EGS51)",
    "ratios": {1: 3.932, 2: 2.408, 3: 1.486, 4: 1.000, 5: 0.830},
    "redline": 4500,
    "boost_rpm": 2400,       # below this the turbo is not making useful power
    "economy_rpm": 2000,     # best specific fuel consumption sits just under
    "peak_power": (3250, 3750),
    "idle_rpm": 650,
    # A shift takes roughly this long and blocks the next one, which is what
    # makes a coast-down ladder a timing problem rather than a threshold problem.
    "shift_ms": 1200,
    # Typical stop: output shaft rpm falls this fast when coasting to rest.
    "coast_decel_rpm_per_s": 170,
}

PEDAL_COLS = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
UP_ROWS = ["1->2", "2->3", "3->4", "4->5"]
DN_ROWS = ["2->1", "3->2", "4->3", "5->4"]


def parse_maps(path: str = MAPS) -> dict:
    """Pull every *_SHIFT_MAP array out of maps.cpp as {name: [[row], ...]}."""
    src = open(path).read()
    src = re.sub(r"/\*.*?\*/", " ", src, flags=re.S)      # strip comments
    out = {}
    # NB the arrays are named *_UPSHIFT_MAP / *_DOWNSHIFT_MAP, so the name ends in
    # "SHIFT_MAP" with no underscore before it. Requiring "_SHIFT_MAP" here matched
    # nothing at all and the checker silently passed everything.
    for m in re.finditer(r"const\s+int16_t\s+(\w*SHIFT_MAP)\s*\[[^\]]*\]\s*=\s*\{(.*?)\};", src, re.S):
        name, body = m.group(1), m.group(2)
        vals = [int(v) for v in re.findall(r"-?\d+", body)]
        if len(vals) != 44:
            continue
        out[name] = [vals[i * 11:(i + 1) * 11] for i in range(4)]
    return out


class Problem:
    def __init__(self, kind, sev, profile, shift, pedal, msg):
        self.kind, self.sev, self.profile = kind, sev, profile
        self.shift, self.pedal, self.msg = shift, pedal, msg

    def __str__(self):
        loc = "%s %s @%3d%%" % (self.profile, self.shift, self.pedal) if self.pedal is not None \
            else "%s %s" % (self.profile, self.shift)
        return "%-5s %-28s %s" % (self.sev, loc, self.msg)


def check(profile: str, up: list, dn: list, env: dict) -> list:
    R, redline, boost = env["ratios"], env["redline"], env["boost_rpm"]
    probs = []

    for r, key in enumerate(DN_ROWS):
        hi, lo = int(key[0]), int(key[-1])          # e.g. 3->2 : from 3 to 2
        for c, pct in enumerate(PEDAL_COLS):
            thr = dn[r][c]
            lands = thr * R[lo] / R[hi]

            if thr <= env["idle_rpm"] * 0.4:
                probs.append(Problem("never_coast", "ERROR", profile, key, pct,
                                     "threshold %d rpm is below any reachable speed: "
                                     "this gear will never be left" % thr))
            if lands > redline:
                probs.append(Problem("redline", "ERROR", profile, key, pct,
                                     "lands at %.0f rpm, past the %d redline" % (lands, redline)))
            # Hunting: after the downshift, are we already past the point at
            # which the lower gear wants to shift back up?
            up_key = "%d->%d" % (lo, lo + 1)
            if up_key in UP_ROWS:
                up_pt = up[UP_ROWS.index(up_key)][c]
                if lands > up_pt:
                    probs.append(Problem("hunt", "ERROR", profile, key, pct,
                                         "lands at %.0f rpm but %s upshifts at %d - will shift straight back"
                                         % (lands, up_key, up_pt)))
            # Dead band: at high load, a gap between the downshift threshold and
            # the boost point is engine speed the car cannot use and will not leave.
            # Only worth flagging where it can actually be closed - raising the
            # threshold to the boost point is only possible if the result still
            # lands below the lower gear's upshift point. Where it does not, the
            # upshift map is the blocker and moving the downshift map alone just
            # trades a dead band for hunting; say so instead.
            if pct >= 80 and thr < boost:
                hunt_limit = None
                if up_key in UP_ROWS:
                    hunt_limit = up[UP_ROWS.index(up_key)][c] * R[hi] / R[lo]
                if hunt_limit is not None and boost > hunt_limit:
                    probs.append(Problem("conflict", "WARN", profile, key, pct,
                                         "cannot reach the %d rpm boost point: anything over %.0f hunts "
                                         "against %s (upshift %d). The upshift map has to move too."
                                         % (boost, hunt_limit, up_key, up[UP_ROWS.index(up_key)][c])))
                else:
                    probs.append(Problem("dead_band", "WARN", profile, key, pct,
                                         "at %d%% pedal will not downshift until %d rpm, but boost needs %d: "
                                         "%d rpm of unusable band" % (pct, thr, boost, boost - thr)))

        for c in range(len(PEDAL_COLS) - 1):
            if dn[r][c] > dn[r][c + 1]:
                probs.append(Problem("monotonic", "WARN", profile, key, PEDAL_COLS[c + 1],
                                     "%d rpm is below the %d%% cell (%d): downshift threshold falls as "
                                     "pedal rises" % (dn[r][c + 1], PEDAL_COLS[c], dn[r][c])))

    for r, key in enumerate(UP_ROWS):
        lo, hi = int(key[0]), int(key[-1])
        for c, pct in enumerate(PEDAL_COLS):
            pt = up[r][c]
            if pt > redline:
                probs.append(Problem("redline", "ERROR", profile, key, pct,
                                     "upshifts at %d rpm, past the %d redline" % (pt, redline)))
            lands = pt * R[hi] / R[lo]
            if pct >= 90 and lands < boost:
                probs.append(Problem("dead_band", "WARN", profile, key, pct,
                                     "at %d%% pedal lands at %.0f rpm, under the %d boost point"
                                     % (pct, lands, boost)))
        for c in range(len(PEDAL_COLS) - 1):
            if up[r][c] > up[r][c + 1]:
                probs.append(Problem("monotonic", "WARN", profile, key, PEDAL_COLS[c + 1],
                                     "%d rpm is below the %d%% cell (%d)" % (up[r][c + 1], PEDAL_COLS[c], up[r][c])))

    probs += check_coast_ladder(profile, dn, env)
    return probs


def check_coast_ladder(profile: str, dn: list, env: dict) -> list:
    """
    Can the box get down to 1st before the car stops?

    Shifts are serialised - Gearbox::controller_loop only asks the profile when
    it is not already shifting - so the ladder is a time budget, not just a set
    of thresholds. Walk it at the coast deceleration rate and see where it ends.
    """
    R, probs = env["ratios"], []
    shift_s = env["shift_ms"] / 1000.0
    decel = env["coast_decel_rpm_per_s"]
    out = dn[3][0] / R[5]            # output rpm at the 5->4 coast threshold
    t, gear = 0.0, 5
    while gear > 1:
        thr = dn[gear - 2][0]        # 0 % pedal cell for this gear change
        need = thr / R[gear]         # output rpm at which it triggers
        wait = max(0.0, (out - need) / decel)
        t += wait
        out -= wait * decel
        if out <= 0:
            probs.append(Problem("ladder_time", "ERROR", profile, "%d->%d" % (gear, gear - 1), 0,
                                 "car stops before this downshift is even requested"))
            break
        t += shift_s
        out -= shift_s * decel
        if out <= 0:
            probs.append(Problem("ladder_time", "WARN", profile, "%d->%d" % (gear, gear - 1), 0,
                                 "completes at or after standstill (%.1f s into the stop) - "
                                 "engages at rest, felt as a clunk on brake release" % t))
            break
        gear -= 1
    return probs


def landing_table(profile, up, dn, env):
    R = env["ratios"]
    print("\n  %s: where each shift leaves the engine" % profile)
    print("  %-6s %s" % ("", "".join("%7d%%" % p for p in PEDAL_COLS)))
    for r, key in enumerate(UP_ROWS):
        lo, hi = int(key[0]), int(key[-1])
        print("  %-6s %s" % (key, "".join("%8.0f" % (up[r][c] * R[hi] / R[lo]) for c in range(11))))
    for r, key in enumerate(DN_ROWS):
        hi, lo = int(key[0]), int(key[-1])
        print("  %-6s %s" % (key, "".join("%8.0f" % (dn[r][c] * R[lo] / R[hi]) for c in range(11))))
    print("  (boost %d, peak power %d-%d, redline %d)" % (
        env["boost_rpm"], env["peak_power"][0], env["peak_power"][1], env["redline"]))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--verbose", "-v", action="store_true")
    ap.add_argument("--maps", default=MAPS)
    args = ap.parse_args()

    maps = parse_maps(args.maps)
    if not maps:
        print("ERROR: parsed no shift maps from %s - the checker would pass everything" % args.maps)
        return 2
    env = ENVELOPE
    print("Shift map check against %s" % env["name"])
    print("boost %d rpm, economy %d, peak power %d-%d, redline %d\n" % (
        env["boost_rpm"], env["economy_rpm"], env["peak_power"][0], env["peak_power"][1], env["redline"]))

    all_probs = []
    for prof in ("S", "C", "A"):
        u, d = "%s_DIESEL_UPSHIFT_MAP" % prof, "%s_DIESEL_DOWNSHIFT_MAP" % prof
        if u not in maps or d not in maps:
            continue
        probs = check(prof, maps[u], maps[d], env)
        all_probs += probs
        if args.verbose:
            landing_table(prof, maps[u], maps[d], env)

    errs = [p for p in all_probs if p.sev == "ERROR"]
    warns = [p for p in all_probs if p.sev == "WARN"]
    for p in errs + warns:
        print(p)
    print("\n%d error(s), %d warning(s)" % (len(errs), len(warns)))
    return 1 if errs else 0


if __name__ == "__main__":
    sys.exit(main())
