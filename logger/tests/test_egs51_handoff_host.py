"""Host checks for native handoff arithmetic and complete ROM trajectories."""
from pathlib import Path
import ctypes as c
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]


class HandoffMathTests(unittest.TestCase):
    def test_fill_progress_carries_across_pressure_change(self):
        # Exercise the NAG52 header under its C++ compiler, separately from the
        # full C semantic-model/raw-ROM differential suite.
        source = r'''
#include "shifting_algo/egs51_handoff_math.h"
#include <cassert>
int main() {
    // Equal net pressure preserves the base timer plus elapsed fill.
    assert(egs51_handoff_fill_credit(2000,0,0,2000,10,20)==30);
    // Quarter pressure carries only half of the elapsed contribution.
    assert(egs51_handoff_fill_credit(500,0,0,2000,10,20)==17);
    // Below the spring threshold, elapsed time gives no fill credit.
    assert(egs51_handoff_fill_credit(100,0,200,2000,10,200)==5);
    // Zero target pressure has the ROM's explicit 255 result, no divide.
    assert(egs51_handoff_fill_credit(2000,0,0,0,10,20)==255);
    assert(egs51_handoff_fill_credit(2000,0,0,2000,255,255)==255);
    // Gross pressure wraps as a word before the spring comparison.
    assert(egs51_handoff_fill_credit(65535,1,0,2000,10,20)==5);
    assert(egs51_handoff_root(10000)==100);
    assert(egs51_handoff_root(2500)==50);
    // This ROM helper is intentionally not an exact floor(sqrt(x)).
    assert(egs51_handoff_root(7)==0);
}
'''
        with tempfile.TemporaryDirectory() as tmp:
            base = Path(tmp)
            (base / 'test.cpp').write_text(source)
            result = subprocess.run(['g++', '-std=c++17', '-Wall', '-Wextra', '-Werror',
                                     '-fsanitize=undefined', '-fno-sanitize-recover=all',
                                     '-I' + str(ROOT / 'src'), str(base / 'test.cpp'),
                                     '-o', str(base / 'test')], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            subprocess.run([str(base / 'test')], check=True, capture_output=True)


@unittest.skipUnless((ROOT / 'tmp/egs51/EGS51_A0215451432.bin').exists(),
                     'local OEM ROM not present')
class HandoffRomTrajectoryTests(unittest.TestCase):
    def test_speed_and_timeout_paths_through_complete_oem_handler(self):
        sys.path.insert(0, str(ROOT / 'tmp/egs51/tools'))
        from replay_downshift_handoff import trajectory
        normal = trajectory(30)
        timeout = trajectory(0)
        for rows in (normal, timeout):
            self.assertEqual(rows[0]['gear'], 4)
            self.assertEqual(rows[0]['transferred_commands'], 5)
            self.assertEqual(rows[-1]['gear'], 3)
            self.assertEqual(rows[-1]['phase'], 1)
            self.assertEqual(rows[-1]['shift_index'], 7)
            self.assertEqual(rows[-1]['mod_substate'], 3)
            self.assertEqual(rows[-1]['transferred_commands'], 4)
            self.assertTrue(all(r['phase'] == 6 for r in rows[:-1]))
            self.assertEqual(sorted((r['gear'] for r in rows), reverse=True),
                             [r['gear'] for r in rows])
        normal_change = next(r for r in normal if r['gear'] == 3)
        timeout_change = next(r for r in timeout if r['gear'] == 3)
        self.assertGreater(normal_change['emergency_timer'], 0)
        self.assertEqual(timeout_change['emergency_timer'], 0)
        self.assertGreater(timeout_change['fill_credit'], normal_change['fill_credit'])

    def test_native_pressure_schedule_through_matching_and_release(self):
        sys.path.insert(0, str(ROOT / 'tmp/egs51/tools'))
        from replay_downshift_handoff import trajectory
        with tempfile.TemporaryDirectory(prefix='egs51-native-host-') as tmp:
            so = Path(tmp) / 'model.so'
            subprocess.run(['cc', '-std=c11', '-Wall', '-Wextra', '-Werror', '-pedantic',
                            '-fsanitize=undefined', '-fno-sanitize-recover=all', '-shared', '-fPIC',
                            *map(str, sorted((ROOT / 'tmp/egs51/reconstructed').glob('egs51_*.c'))),
                            '-o', str(so)], check=True, capture_output=True)
            native = c.CDLL(str(so))
            for rise in (0, 30, 100):
                for gear in (None, 1, 2, 3, 4):
                    with self.subTest(rise=rise, gear=gear):
                        rows = trajectory(rise, native, True, gear)
                        self.assertEqual(rows[-1]['phase'], 0)
                        self.assertEqual(rows[-1]['gear'], 3 if gear is None else gear)
                        self.assertEqual(rows[-1]['transferred_commands'], 0)
                        # Find actual circuit release, excluding the initial bleed
                        # (whose circuit starts off). The preceding pressure must
                        # already match line pressure before the command drops.
                        releases = [i for i in range(1,len(rows))
                                    if rows[i-1]['transferred_commands'] and
                                    not rows[i]['transferred_commands']]
                        self.assertEqual(len(releases), 1)
                        matched = rows[releases[0]-1]['spc_pressure_raw']
                        self.assertEqual(matched, rows[-1]['spc_pressure_raw'])
                        # The selected fixture's forward/inverse gain truncation
                        # yields 8999 or 9000 against line demand 9000.
                        self.assertIn(matched, (8999, 9000))
