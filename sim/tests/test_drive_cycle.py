"""Persistent controller/plant startup and automatic drive-cycle checks."""
import csv
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
ROM_PRESENT=(Path(__file__).resolve().parents[2]/'tmp/egs51/EGS51_A0215451432.bin').exists()
if ROM_PRESENT:
    import drive_cycle

@unittest.skipUnless(ROM_PRESENT,'local OEM ROM missing')
class DriveCycleTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp=tempfile.TemporaryDirectory();cls.folder=Path(cls.temp.name)
        cls.native,cls.plant=drive_cycle.build(cls.folder)
    @classmethod
    def tearDownClass(cls):cls.temp.cleanup()
    def test_startup_and_continuous_drive(self):
        result=drive_cycle.simulate(self.native,self.plant,self.folder/'drive.csv')
        rows=list(csv.DictReader((self.folder/'drive.csv').read_text().splitlines()))
        self.assertEqual(result['initializations'],1)
        self.assertEqual(result['scheduler_ticks'],3000)
        self.assertEqual(rows[0]['selector'],'8')
        self.assertEqual(float(rows[0]['speed_kph']),0)
        self.assertEqual(float(rows[0]['off_fill']),0)
        self.assertTrue(result['primed_at_acceleration'])
        self.assertTrue({1,2,3,4}<=set(result['gears']))
        self.assertIn(6,result['modes'])
        self.assertGreater(result['max_speed_kph'],40)
        self.assertEqual(result['final_selector'],8)
        self.assertLess(abs(result['final_speed_kph']),.01)
        self.assertFalse(result['controller_reset_during_cycle'])
        # Returning to Park must follow a physical stop, without a speed reset.
        park=[r for r in rows if r['segment']=='park_return']
        self.assertTrue(all(abs(float(r['speed_kph']))<.2 for r in park))
    def test_plant_idle_brakes_and_fill_continuity(self):
        exe=self.folder/'cycle_test'
        subprocess.run(['c++','-std=c++17','-O2','-Wall','-Wextra','-Werror',str(drive_cycle.ROOT/'sim/tests/cycle_plant_test.cpp'),'-o',str(exe)],check=True)
        subprocess.run([str(exe)],check=True)
    def test_continuous_timestep_convergence(self):
        a=drive_cycle.simulate(self.native,self.plant,self.folder/'a.csv')
        b=drive_cycle.simulate(self.native,self.plant,self.folder/'b.csv',dt_ms=.5)
        self.assertEqual(a['gears'],b['gears'])
        self.assertEqual(a['final_selector'],b['final_selector'])
        self.assertLess(abs(a['max_speed_kph']-b['max_speed_kph']),1)
        self.assertTrue(b['primed_at_acceleration'])
if __name__=='__main__':unittest.main()
