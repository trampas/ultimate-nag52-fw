"""Wire, recorder, real decision-branch, and gap attribution regressions."""
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "logger"))
sys.path.insert(0, str(ROOT / "scripts"))
from nag52logger.records import RECORDS
from skip_downshift_report import gap_causes, make_report


class ObserverTests(unittest.TestCase):
    def compile_run(self, source):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)
            (path / "test.cpp").write_text(source)
            result = subprocess.run(["g++", "-std=c++17", "-Wall", "-Wextra", "-Werror",
                                     "-I" + str(ROOT / "src"), str(path / "test.cpp"),
                                     "-o", str(path / "test")], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            return subprocess.check_output([str(path / "test")])

    def test_recorder_wrap_ring_and_wire(self):
        raw = self.compile_run(r'''
#include "models/downshift_observer.h"
#include <cassert>
#include <cstdio>
using namespace DownshiftObserver;
int main() {
 Recorder r;
 assert(r.read().count == 0);
 r.update(UINT32_MAX-9, State::NoRequest, 5, 5, 0);
 r.update(10, State::NoRequest, 5, 5, 0);
 assert(r.read().elapsed_ms[4] == 20);
 assert(r.read().count == 1);
 r.update(30, State::CannotFinish, 5, 5, 0);
 assert(r.read().elapsed_ms[4] == 40);
 for (int i=0; i<20; ++i) {
   r.update(50+i*20, i%2 ? State::RpmVeto : State::NoRequest, 4, 4, 2);
 }
 const auto out = r.read();
 assert(out.count == 16 && out.seq == 22);
 assert(out.transitions[0].t_ms == 130);
 assert(out.transitions[15].state == static_cast<uint8_t>(State::RpmVeto));
 fwrite(&out, sizeof(out), 1, stdout);
}
''')
        d = RECORDS["downshift_observer"].decode(raw)
        self.assertEqual(len(raw), 188)
        self.assertEqual(d["transitions"][0]["seq"], 6)
        self.assertEqual(d["transitions"][-1]["state"], "rpm_veto")
        self.assertTrue(d["transitions"][-1]["kickdown"])
        self.assertEqual(d["t_ms"], 430)
        self.assertIn("_error", RECORDS["downshift_observer"].decode(bytes(188)))
        malformed = bytearray(raw)
        malformed[1] = 17
        self.assertIn("_error", RECORDS["downshift_observer"].decode(malformed))
        self.assertIn("_raw", RECORDS["downshift_observer"].decode(raw[:-1]))

    def test_actual_firmware_veto_order_and_exceptions(self):
        code = (ROOT / "src/gearbox.cpp").read_text()
        start = code.index("{", code.index("else if (this->ask_downshift &&"))
        end, depth = start + 1, 1
        while depth:
            depth += (code[end] == "{") - (code[end] == "}")
            end += 1
        branch = code[start:end]
        self.compile_run(r'''
#include "models/downshift_observer.h"
#include <cassert>
#define GET_CLOCK_TIME() 1000u
enum class GearboxGear { First=1, Second, Third, Fourth, Fifth };
GearboxGear prev_gear(GearboxGear g) { return static_cast<GearboxGear>(static_cast<int>(g)-1); }
int rpm=2000;
int calc_input_rpm_from_req_gear(int, GearboxGear, int*) { return rpm; }
struct Gearbox {
 bool last_shift_was_upshift=false, manual_shift=false, shift_req_was_kickdown=false;
 bool ask_downshift=true, finish=true, reserve=true;
 int finish_calls=0, reserve_calls=0, redline_rpm=4500, pedal_at_last_shift=100, gearboxConfig=0;
 GearboxGear actual_gear=GearboxGear::Fourth, target_gear=actual_gear, restrict_target=GearboxGear::Fifth;
 struct { bool kickdown_pressed=false, brake_pressed=false; unsigned last_shift_time=0;
          int pedal_pos=100, output_rpm=500; } sensor_data;
 bool downshift_can_finish(int*) { ++finish_calls; return finish; }
 bool downshift_has_reserve(int*, GearboxGear) { ++reserve_calls; return reserve; }
 DownshiftObserver::State decide() {
   auto downshift_state=DownshiftObserver::State::NoRequest;
   auto kd_demand=sensor_data.kickdown_pressed;
   int* p=nullptr;
''' + branch + r'''
   return downshift_state;
 }
};
int main() {
 using S=DownshiftObserver::State;
 Gearbox g;
 g.last_shift_was_upshift=true; g.finish=false; g.reserve=false;
 assert(g.decide()==S::HuntingInhibit && g.finish_calls==0 && g.reserve_calls==0);
 g.last_shift_was_upshift=false;
 assert(g.decide()==S::CannotFinish && g.reserve_calls==0);
 g.finish=true;
 assert(g.decide()==S::NoReserve && g.target_gear==g.actual_gear);
 g.reserve=true; rpm=4000;
 assert(g.decide()==S::RpmVeto && g.target_gear==g.actual_gear);
 rpm=3999;
 assert(g.decide()==S::Accepted && g.target_gear==GearboxGear::Third);
 Gearbox manual; manual.manual_shift=true; manual.finish=false; manual.reserve=false;
 assert(manual.decide()==S::Accepted && manual.finish_calls==0 && manual.reserve_calls==0);
 Gearbox kd; kd.sensor_data.kickdown_pressed=true; kd.finish=false;
 assert(kd.decide()==S::Accepted && kd.finish_calls==0 && kd.shift_req_was_kickdown);
 Gearbox coast; coast.sensor_data.pedal_pos=0; coast.reserve=false;
 assert(coast.decide()==S::Accepted && coast.reserve_calls==0);
}
''')

    def test_gap_coverage_never_invents_missing_causes(self):
        events = {1: {"t_ms": 90, "end_ms": 120, "state": "no_request"},
                  4: {"t_ms": 160, "end_ms": 190, "state": "cannot_finish"}}
        self.assertEqual(gap_causes(100, 200, events),
                         {"no_request": 20, "cannot_finish": 30, "unknown": 50})
        self.assertEqual(gap_causes(100, 200, {}), {"unknown": 100})

    def test_ladder_uses_owned_tcu_samples_and_breaks_at_upshift_and_reboot(self):
        def shift(gf, gt, t0, t1, seq):
            return {"type": "shift_trace", "t": 9999, "seq_start": seq, "seq_end": seq+1,
                    "gear_from": gf, "gear_to": gt,
                    "samples": [{"seq": seq-1, "t_ms": 0}, {"seq": seq, "t_ms": t0},
                                {"seq": seq+1, "t_ms": t1}, {"seq": seq+2, "t_ms": 9000}]}
        entries = [{"type": "cycle", "tcu_ms": 100},
                   shift("5", "4", 100, 300, 10), shift("4", "3", 400, 600, 20),
                   shift("3", "4", 700, 800, 30), shift("4", "3", 900, 1100, 40),
                   {"type": "cycle", "tcu_ms": 1200}, {"type": "cycle", "tcu_ms": 10},
                   shift("3", "2", 1200, 1300, 50)]
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "drive.jsonl"
            path.write_text("\n".join(json.dumps(e) for e in entries) + '\n{"partial"')
            report = make_report(path)
        self.assertEqual(report["boundary_count"], 1)
        self.assertEqual(report["median_gap_ms"], 100)
        self.assertEqual(report["causes_ms"], {"unknown": 100})
        self.assertEqual(report["ladders"][0]["rungs"][0]["duration_ms"], 200)
