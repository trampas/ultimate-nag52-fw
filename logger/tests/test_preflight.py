"""
Tests for scripts/preflight.py.

They live here because this is the repo's only wired-up test runner.

The point of every test below is that the check can FAIL. scripts/shift_envelope.py
shipped once in a state where it parsed no maps and therefore passed calibrations
that were known to be broken, and a gate that cannot go red is worse than no gate
at all. So each check gets a fixture that trips it and a fixture that does not,
and the tripping fixture is built from the shape of a defect that actually reached
the car on 2026-09-08.
"""
import json
import os
import sys
import tempfile
import unittest

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.join(REPO, "logger"))

import preflight as PF  # noqa: E402
from nag52logger.reader import LogFile  # noqa: E402


def sample(t_ms, **kw):
    s = {
        "t_ms": t_ms, "input_rpm": 1000, "output_rpm": 400, "engine_rpm": 1000,
        "input_torque": 100, "p_on": 3000, "p_off": 3000, "spc": 3000, "mpc": 3000,
        "phase": 1, "subphase_shift": 0, "subphase_mod": 0, "pedal": 100,
        "trq_req_amount": None, "engine_torque": 200, "seq": 0, "shifting": True,
        "circuits": 1, "gear_actual": "3", "gear_target": "2",
    }
    s.update(kw)
    return s


def write_log(logs=(), traces=(), cycles=()):
    fd, path = tempfile.mkstemp(suffix=".jsonl")
    with os.fdopen(fd, "w") as fh:
        fh.write(json.dumps({"type": "header", "format": 1, "logger_version": "t"}) + "\n")
        for t, tag, msg in logs:
            fh.write(json.dumps({"type": "log", "t": t, "tcu_ms": int(t * 1000),
                                 "level": "I", "tag": tag, "msg": msg}) + "\n")
        for tr in traces:
            fh.write(json.dumps(dict(tr, type="shift_trace")) + "\n")
        for c in cycles:
            fh.write(json.dumps(dict(c, type="cycle")) + "\n")
    return path


class Base(unittest.TestCase):
    def setUp(self):
        self.paths = []

    def tearDown(self):
        for p in self.paths:
            os.unlink(p)

    def load(self, **kw):
        p = write_log(**kw)
        self.paths.append(p)
        return LogFile.load(p)

    def errs(self, findings, check):
        return [f for f in findings if f.check == check and f.sev == "ERROR"]


class TestTorqueRequest(Base):
    """The 2026-09-08 kickdown: the commanded amount ratcheted 284 -> 2 Nm and the
    engine went to -81 Nm with the pedal held down."""

    def trace(self, amounts, torques, pedal=197):
        return {
            "t": 10.0, "gear_from": "3", "gear_to": "2",
            "quality": {"duration_ms": 900, "response_ms": 300},
            "samples": [sample(1000 + 20 * i, trq_req_amount=a, engine_torque=e, pedal=pedal)
                        for i, (a, e) in enumerate(zip(amounts, torques))],
        }

    def test_collapsing_request_is_an_error(self):
        log = self.load(traces=[self.trace([284, 221, 157, 70, 24, 9, 2],
                                           [300, 297, 252, 165, 78, 9, -33])])
        f = self.errs(PF.check_torque_request(log), "torque_request")
        self.assertTrue(any("ratcheting into a cut" in x.msg for x in f))

    def test_negative_engine_torque_under_pedal_is_an_error(self):
        # Amount holds station, but the engine still ends up dragging.
        log = self.load(traces=[self.trace([200, 200, 200, 200, 200, 200, 200],
                                           [300, 250, 200, 100, 20, -40, -81])])
        f = self.errs(PF.check_torque_request(log), "torque_request")
        self.assertTrue(any("net torque undershoot" in x.msg for x in f))

    def test_healthy_request_passes(self):
        # What the fix produces: the amount settles at a level and is released.
        log = self.load(traces=[self.trace([284, 264, 243, 222, 201, 202, 208],
                                           [300, 290, 260, 240, 210, 205, 210])])
        self.assertEqual(self.errs(PF.check_torque_request(log), "torque_request"), [])

    def test_coasting_negative_torque_is_not_a_cut(self):
        # Pedal released: negative torque is the driver's doing, not ours.
        log = self.load(traces=[self.trace([100, 100, 100], [50, 0, -40], pedal=0)])
        self.assertEqual(self.errs(PF.check_torque_request(log), "torque_request"), [])

    def test_dropped_read_is_not_treated_as_a_cut(self):
        log = self.load(traces=[self.trace([200, 200, 200], [None, None, None])])
        self.assertEqual(self.errs(PF.check_torque_request(log), "torque_request"), [])


class TestGarage(Base):
    """The 2026-09-08 N->D: aborted, re-entered, 3.9 s and three max-pressure ramps."""

    def test_abort_is_an_error(self):
        log = self.load(logs=[(20.57, "SHIFTER", "Garage shift"),
                              (22.29, "SHIFT", "Garage shift aborted")])
        self.assertTrue(any("aborted" in x.msg
                            for x in self.errs(PF.check_garage_engagement(log), "garage")))

    def test_slow_engagement_is_an_error(self):
        log = self.load(logs=[(22.30, "SHIFTER", "Garage shift"),
                              (24.46, "SHIFT", "Garage shift completed OK")])
        f = self.errs(PF.check_garage_engagement(log), "garage")
        self.assertTrue(any("within the duration limit" in x.msg for x in f))

    def test_reentry_after_abort_is_an_error(self):
        log = self.load(logs=[(20.57, "SHIFTER", "Garage shift"),
                              (22.29, "SHIFT", "Garage shift aborted"),
                              (22.30, "SHIFTER", "Garage shift"),
                              (24.46, "SHIFT", "Garage shift completed OK")])
        f = self.errs(PF.check_garage_engagement(log), "garage")
        self.assertTrue(any("re-entered" in x.msg for x in f))

    def test_selector_cancellation_is_not_a_failed_engagement(self):
        log = self.load(logs=[(20.0, "SHIFT", "Garage shift"),
                             (23.0, "SHIFT", "Garage shift cancelled by selector"),
                             (23.1, "SHIFT", "Garage shift"),
                             (24.1, "SHIFT", "Garage shift completed OK")])
        self.assertEqual(self.errs(PF.check_garage_engagement(log), "garage"), [])

    def test_clean_engagement_passes(self):
        # What the pre-merge firmware did every time: 1020 ms, first attempt.
        log = self.load(logs=[(14.51, "SHIFTER", "Garage shift"),
                              (15.53, "SHIFT", "Garage shift completed OK")])
        self.assertEqual(self.errs(PF.check_garage_engagement(log), "garage"), [])


class TestGarageSyncGate(Base):
    """Substage 8 confirmed at < 20 rpm while sync was declared at up to 350."""

    def trace(self, checks, gear_to="2"):
        return {
            "t": 25.0, "gear_from": "N/P", "gear_to": gear_to,
            "quality": {"duration_ms": 1700, "response_ms": 0},
            "samples": [sample(21000 + 20 * i, phase=8, input_rpm=ir,
                               output_rpm=orpm, pedal=ped)
                        for i, (ir, orpm, ped) in enumerate(checks)],
        }

    def test_completion_sample_alone_does_not_prove_rejection(self):
        # Stationary, driver on the pedal: turbine at 96 rpm is a real engagement,
        # but the fixed 20 rpm gate throws it away.
        log = self.load(traces=[self.trace([(96, 0, 79)])])
        f = self.errs(PF.check_garage_sync_gate(log), "garage_sync")
        self.assertEqual(f, [])
        self.assertTrue(any(x.sev == "WARN" for x in PF.check_garage_sync_gate(log)))

    def test_genuine_non_engagement_is_not_flagged(self):
        # Clutch never engaged: turbine near engine speed, delta far above 350.
        log = self.load(traces=[self.trace([(1100, 0, 79)])])
        self.assertEqual(self.errs(PF.check_garage_sync_gate(log), "garage_sync"), [])

    def test_real_sync_is_not_flagged(self):
        log = self.load(traces=[self.trace([(0, 0, 0)])])
        self.assertEqual(self.errs(PF.check_garage_sync_gate(log), "garage_sync"), [])

    def test_forward_gear_shift_is_ignored(self):
        tr = self.trace([(96, 0, 79)])
        tr["gear_from"] = "3"
        log = self.load(traces=[tr])
        self.assertEqual(self.errs(PF.check_garage_sync_gate(log), "garage_sync"), [])


class TestShiftCompletion(Base):
    def trace(self, dur, resp):
        return {"t": 1.0, "gear_from": "2", "gear_to": "3",
                "quality": {"duration_ms": dur, "response_ms": resp},
                "samples": [sample(1000)]}

    def test_overlong_shift_is_an_error(self):
        log = self.load(traces=[self.trace(3067, 300)])
        self.assertTrue(self.errs(PF.check_shift_completion(log), "shift_completion"))

    def test_slow_response_is_an_error(self):
        log = self.load(traces=[self.trace(900, 1165)])
        self.assertTrue(self.errs(PF.check_shift_completion(log), "shift_completion"))

    def test_normal_shift_passes(self):
        log = self.load(traces=[self.trace(1200, 500)])
        self.assertEqual(self.errs(PF.check_shift_completion(log), "shift_completion"), [])


class TestQuantisationLadder(unittest.TestCase):
    """The offline peak_jerk on the 2026-09-08 drive was 35 of 43 values sitting on
    exact multiples of 29.7 - quantisation steps of an integer rpm signal, not a
    measurement. A gate built on it would fire constantly and mean nothing."""

    def test_finds_a_ladder_whose_step_is_absent_from_the_data(self):
        vals = [59.4, 59.4, 89.1, 89.1, 118.8, 148.5, 178.2, 207.9, 89.1, 59.4]
        base, n, total = PF.quantisation_ladder(vals)
        self.assertAlmostEqual(base, 29.7, places=3)
        self.assertEqual(n, total)

    def test_real_measurements_are_not_a_ladder(self):
        vals = [12.3, 14.7, 9.8, 21.4, 17.2, 8.1, 25.9, 11.6, 19.3, 13.4]
        base, n, total = PF.quantisation_ladder(vals)
        self.assertLessEqual(n, 0.6 * total)

    def test_too_few_values_is_inconclusive(self):
        base, n, total = PF.quantisation_ladder([59.4, 89.1, 118.8])
        self.assertIsNone(base)


class TestRunner(Base):
    def test_findings_are_deduplicated(self):
        # The trace ring overlaps, so the same sample arrives in two traces.
        tr = {"t": 25.0, "gear_from": "N/P", "gear_to": "2",
              "quality": {"duration_ms": 1700, "response_ms": 0},
              "samples": [sample(21507, phase=8, input_rpm=96, output_rpm=0, pedal=79)]}
        log = self.load(traces=[tr, dict(tr, t=25.3)])
        f = [x for x in PF.run_checks(log) if x.check == "garage_sync" and x.sev == "WARN"]
        self.assertEqual(len(f), 1)

    def test_a_check_with_no_data_warns_instead_of_passing(self):
        """Firmware older than the torque-request trace fields logs no
        trq_req_amount at all. The check then examines nothing, and must say so:
        this is how shift_envelope.py once passed calibrations known to be broken."""
        log = self.load(traces=[{
            "t": 5.0, "gear_from": "2", "gear_to": "3",
            "quality": {"duration_ms": 1100, "response_ms": 400},
            "samples": [{"t_ms": 1000, "input_rpm": 900, "output_rpm": 400,
                         "pedal": 90, "phase": 1}]}])
        warns = [f for f in PF.run_checks(log)
                 if f.check == "torque_request" and f.sev == "WARN"]
        self.assertTrue(any("no data" in w.msg for w in warns))
        self.assertEqual(PF.coverage(log)["torque_request"], 0)

    def test_coverage_is_nonzero_when_the_data_is_there(self):
        log = self.load(traces=[{
            "t": 5.0, "gear_from": "3", "gear_to": "2",
            "quality": {"duration_ms": 1100, "response_ms": 400},
            "samples": [sample(1000, trq_req_amount=200, engine_torque=250)]}])
        self.assertEqual(PF.coverage(log)["torque_request"], 1)

    def test_a_clean_log_produces_no_errors(self):
        log = self.load(
            logs=[(14.51, "SHIFTER", "Garage shift"),
                  (15.53, "SHIFT", "Garage shift completed OK")],
            traces=[{"t": 30.0, "gear_from": "2", "gear_to": "3",
                     "quality": {"duration_ms": 1200, "response_ms": 500},
                     "samples": [sample(30000 + 20 * i, trq_req_amount=a, engine_torque=e)
                                 for i, (a, e) in enumerate(
                                     zip([200, 195, 190, 192, 198],
                                         [260, 250, 240, 245, 250]))]}])
        self.assertEqual([f for f in PF.run_checks(log) if f.sev == "ERROR"], [])


if __name__ == "__main__":
    unittest.main()


class TestSlipEnergy(Base):
    """Added after the 2026-09-08 review: the duration and response gates passed
    every 3->4 on that drive while 3->4 ran a median 25.7 kJ and a peak of 64.6 kJ,
    four times any other shift type. A gate that misses the worst-wearing shift
    class is not doing its job."""

    def trace(self, joules):
        return {"t": 66.9, "gear_from": "3", "gear_to": "4",
                "quality": {"duration_ms": 1483, "response_ms": 741,
                            "slip_energy_j": joules},
                "samples": [sample(1000)]}

    def test_damaging_slip_is_an_error(self):
        log = self.load(traces=[self.trace(64612)])
        self.assertTrue(self.errs(PF.check_slip_energy(log), "slip_energy"))

    def test_over_agility_target_is_a_warning_not_an_error(self):
        log = self.load(traces=[self.trace(31893)])
        f = PF.check_slip_energy(log)
        self.assertEqual(self.errs(f, "slip_energy"), [])
        self.assertTrue([x for x in f if x.sev == "WARN"])

    def test_normal_slip_passes(self):
        log = self.load(traces=[self.trace(6467)])
        self.assertEqual(PF.check_slip_energy(log), [])

    def test_missing_slip_field_is_no_data_not_a_pass(self):
        tr = self.trace(0)
        del tr["quality"]["slip_energy_j"]
        log = self.load(traces=[tr])
        self.assertEqual(PF.coverage(log)["slip_energy"], 0)
