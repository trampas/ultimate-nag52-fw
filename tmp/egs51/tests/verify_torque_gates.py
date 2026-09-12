#!/usr/bin/env python3
"""OEM torque latch decisions, with all arithmetic callees executed from ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0xcad7)
    with tempfile.TemporaryDirectory(prefix='egs51-torque-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry in [('up_torque_enter',0xc9d1),('down_torque_enter',0xcad7),
                           ('up_torque_exit',0xcc38),('down_torque_exit',0xcc8a),('interrupted_torque_exit',0xcd9f)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]; fn.restype=None
            changes=0
            for j in range(12000):
                cpu=configured();cpu.x[0x32e]=rng.randrange(31);cpu.x[0x2ab]=rng.randrange(1,256)
                cpu.im[0xb6]=rng.choice([1,3,3,3,4,0])
                cpu.im[0xac]=rng.randrange(1,9)
                cpu.im[0xaa]=rng.randrange(14);cpu.im[0xb4]=rng.randrange(5)
                cpu.im[0x97]=rng.randrange(256);cpu.im[0x96]=rng.choice([0,0,0,rng.randrange(256)])
                word(cpu.im,0xad,rng.choice([0,1,50,100,200,1000,65535]))
                word(cpu.x,0x2b9,rng.choice([0,1,32767,32768,65535]))
                s=state(cpu);before=cpu.im[0x97];cpu.run(entry);fn(c.byref(s));changes+=before!=cpu.im[0x97]
                try:check_memory(cpu,s,IMS+[0x97],range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            assert changes>10,(name,changes)
            print(f'PASS: 12000 complete {name} calls, {changes} latch changes',flush=True)
if __name__=='__main__':main()
