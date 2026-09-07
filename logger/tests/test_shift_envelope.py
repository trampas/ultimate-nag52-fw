"""
Tests for scripts/shift_envelope.py.

It lives here because this is the repo's only wired-up test runner.

The first version of the checker matched no maps at all - the arrays are named
``*_UPSHIFT_MAP``, not ``*_SHIFT_MAP`` - so it reported a clean bill of health on
maps that were known to be broken. A checker that passes everything is worse than
no checker, so the important tests here are that it finds the maps and that it
still fires on the calibration as it was before it was fixed.
"""
import os
import subprocess
import sys
import tempfile
import unittest

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(REPO, "scripts"))
import shift_envelope as SE  # noqa: E402


def maps_source(up_rows, dn_rows, prefix="S_DIESEL"):
    def row(vals):
        return ", ".join(str(v) for v in vals)
    return (
        "const int16_t %s_UPSHIFT_MAP[SHIFT_MAP_SIZE] = {\n%s\n};\n"
        "const int16_t %s_DOWNSHIFT_MAP[SHIFT_MAP_SIZE] = {\n%s\n};\n"
        % (prefix, ",\n".join(row(r) for r in up_rows),
           prefix, ",\n".join(row(r) for r in dn_rows))
    )


SHIPPED_UP = [[1400, 1550, 1800, 2000, 2200, 2450, 2600, 2850, 3200, 4000, 4500],
           [1400, 1550, 1700, 1850, 2000, 2200, 2350, 2600, 2900, 3550, 4500],
           [1400, 1550, 1700, 1850, 1950, 2050, 2200, 2450, 2700, 3450, 4500],
           [1500, 1550, 1700, 1800, 1950, 2050, 2200, 2450, 2650, 3400, 4500]]
SHIPPED_DN = [[600, 650, 850, 1050, 1200, 1400, 1500, 1700, 1890, 2380, 2400],
           [650, 750, 900, 1100, 1250, 1400, 1500, 1700, 1800, 2130, 2400],
           [700, 850, 1000, 1150, 1300, 1400, 1550, 1700, 1800, 2260, 2400],
           [900, 1000, 1100, 1200, 1350, 1450, 1500, 1970, 2130, 2400, 2500]]


class ParserTests(unittest.TestCase):
    def test_finds_the_real_maps(self):
        """The regression that made the checker useless: zero maps parsed."""
        maps = SE.parse_maps()
        self.assertGreater(len(maps), 8, "parsed no maps - the checker would pass everything")
        for n in ("S_DIESEL_UPSHIFT_MAP", "S_DIESEL_DOWNSHIFT_MAP",
                  "C_DIESEL_DOWNSHIFT_MAP", "A_DIESEL_DOWNSHIFT_MAP"):
            self.assertIn(n, maps)
            self.assertEqual(len(maps[n]), 4)
            self.assertEqual(len(maps[n][0]), 11)

    def test_ignores_the_shift_time_maps(self):
        # Those are 30 values, not 44, and mean something else entirely.
        self.assertNotIn("S_UPSHIFT_TIME_MAP", SE.parse_maps())


class CheckTests(unittest.TestCase):
    def kinds(self, up, dn):
        return {p.kind for p in SE.check("T", up, dn, SE.ENVELOPE)}

    def test_shipped_maps_have_no_new_defect_classes(self):
        """
        The shipped calibration is not clean, and this pins what is left so a
        change that introduces a NEW kind of defect fails here. The remaining
        findings need the upshift map moved too - see TRANSMISSION_NOTES.md.
        """
        self.assertEqual(self.kinds(SHIPPED_UP, SHIPPED_DN), {"hunt", "conflict", "dead_band"})

    def test_a_clean_calibration_is_reachable(self):
        """Guard against the checks being unsatisfiable by construction."""
        up = [r[:] for r in SHIPPED_UP]
        dn = [r[:] for r in SHIPPED_DN]
        R = SE.ENVELOPE["ratios"]
        for r, key in enumerate(SE.DN_ROWS):
            hi, lo = int(key[0]), int(key[-1])
            uk = "%d->%d" % (lo, lo + 1)
            if uk not in SE.UP_ROWS:
                continue
            for c in range(11):
                lim = up[SE.UP_ROWS.index(uk)][c] * R[hi] / R[lo]
                dn[r][c] = min(dn[r][c], int(lim) - 20)
        for r in range(4):
            for c in range(1, 11):
                dn[r][c] = max(dn[r][c], dn[r][c - 1])
        self.assertNotIn("hunt", self.kinds(up, dn))

    def test_never_leaves_the_gear(self):
        dn = [r[:] for r in SHIPPED_DN]
        dn[0][0] = 100                       # the original 2->1 coast cell
        self.assertIn("never_coast", self.kinds(SHIPPED_UP, dn))

    def test_dead_band_below_boost(self):
        dn = [r[:] for r in SHIPPED_DN]
        dn[2][10] = 2000                     # the original 4->3 full throttle cell
        self.assertIn("dead_band", self.kinds(SHIPPED_UP, dn))

    def test_hunting(self):
        dn = [r[:] for r in SHIPPED_DN]
        dn[1][5] = 1400                      # 3->2 lands above the 2->3 upshift point
        self.assertIn("hunt", self.kinds(SHIPPED_UP, dn))

    def test_non_monotonic_cell(self):
        dn = [r[:] for r in SHIPPED_DN]
        dn[2][10] = dn[2][9] - 100
        self.assertIn("monotonic", self.kinds(SHIPPED_UP, dn))

    def test_downshift_past_the_redline(self):
        dn = [r[:] for r in SHIPPED_DN]
        dn[0][10] = 4000                     # 2->1 from 4000 lands well past 4500
        self.assertIn("redline", self.kinds(SHIPPED_UP, dn))

    def test_ladder_that_cannot_finish_before_the_car_stops(self):
        """The regression that produced the standstill clunk."""
        slow = dict(SE.ENVELOPE, shift_ms=2000)
        probs = SE.check_coast_ladder("T", SHIPPED_DN, slow)
        self.assertTrue([p for p in probs if p.kind == "ladder_time"])
        # and the shipped timing must be fast enough
        self.assertEqual(SE.check_coast_ladder("T", SHIPPED_DN, SE.ENVELOPE), [])


class CliTests(unittest.TestCase):
    def test_exit_code_and_empty_parse_is_loud(self):
        with tempfile.TemporaryDirectory() as d:
            empty = os.path.join(d, "empty.cpp")
            open(empty, "w").write("// nothing here\n")
            r = subprocess.run([sys.executable, os.path.join(REPO, "scripts", "shift_envelope.py"),
                                "--maps", empty], capture_output=True, text=True)
            self.assertEqual(r.returncode, 2, "an empty parse must not look like a pass")
            self.assertIn("parsed no shift maps", r.stdout)

            bad = os.path.join(d, "bad.cpp")
            dn = [r_[:] for r_ in SHIPPED_DN]
            dn[0][0] = 100
            open(bad, "w").write(maps_source(SHIPPED_UP, dn))
            r = subprocess.run([sys.executable, os.path.join(REPO, "scripts", "shift_envelope.py"),
                                "--maps", bad], capture_output=True, text=True)
            self.assertEqual(r.returncode, 1)
            self.assertIn("never be left", r.stdout)


if __name__ == "__main__":
    unittest.main()
