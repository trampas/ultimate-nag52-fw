"""Exercise native EGS51 / raw-ROM agreement with independent persistent state."""
import csv
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
ROM_PRESENT=(Path(__file__).resolve().parents[2]/'tmp/egs51/EGS51_A0215451432.bin').exists()
if ROM_PRESENT:
    import egs51


@unittest.skipUnless(ROM_PRESENT,'local OEM ROM not present')
class Egs51PlantTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp=tempfile.TemporaryDirectory(prefix='test-egs51-plant-')
        cls.folder=Path(cls.tmp.name)
        cls.native,cls.plant=egs51.build(cls.folder)

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def run_case(self,name,compare=False,**changes):
        path=self.folder/(name+'.csv')
        result=egs51.simulate({**egs51.DEFAULTS,**changes},self.native,self.plant,path,compare)
        return result['result'],path.read_bytes()

    def test_pressure_schedule_and_rom_agreement(self):
        result,_=self.run_case('oracle',True)
        self.assertEqual(result['phases'],[0,1,2,3,4])
        self.assertTrue(result['pressure_schedule_completed'])
        self.assertTrue(result['final_sync'])
        self.assertTrue(result['final_sync_held_100ms'])
        self.assertTrue(result['warmup_old_gear_synchronized'])
        self.assertFalse(result['emergency_timer_expired'])
        self.assertGreater(result['rom_calls_checked'],200)
        # Completing this subset must not be presented as full OEM validation.
        self.assertFalse(result['controller_completed'])

    def test_oracle_does_not_change_trajectory(self):
        _,native=self.run_case('native')
        _,oracle=self.run_case('checked',True)
        self.assertEqual(native,oracle)

    def test_physical_feedback_changes_controller(self):
        _,normal=self.run_case('normal')
        result,weak=self.run_case('weak',True,capacity_scale=.35)
        self.assertNotEqual(normal,weak)
        def pressures(data):
            return [(r['mpc_raw'],r['clutch_raw']) for r in csv.DictReader(data.decode().splitlines())]
        self.assertNotEqual(pressures(normal),pressures(weak))
        self.assertGreater(result['rom_calls_checked'],200)

    def test_severe_capacity_loss_is_reported_as_preexisting_slip(self):
        result,_=self.run_case('preexisting_slip',True,capacity_scale=.1)
        self.assertFalse(result['warmup_old_gear_synchronized'])
        self.assertGreater(result['initial_old_ratio_slip_rpm'],2000)
        self.assertTrue(result['domain_exit'])
        self.assertFalse(result['final_sync_held_100ms'])
        self.assertIn('pre-shift old gear already slipping',result['scope_outcome'])

    def test_truncated_scenario_is_not_complete(self):
        result,_=self.run_case('short',seconds=.1)
        self.assertFalse(result['pressure_schedule_completed'])
        self.assertTrue(result['controller_timed_out'])

    def test_reject_invalid_step_and_unknown_parameters(self):
        for change in ({'dt_ms':3},{'mass_kg':-1},{'typo':1},{'tick_ms':float('nan')}):
            with self.assertRaises(ValueError):
                egs51.validate({**egs51.DEFAULTS,**change})


if __name__=='__main__':unittest.main()
