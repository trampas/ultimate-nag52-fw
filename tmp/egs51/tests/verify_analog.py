#!/usr/bin/env python3
"""Full analog scan against raw ROM, including persistent filter trajectories."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, base, check_memory, U8
rng=random.Random(0x206e)
class Inputs(c.Structure):
    _fields_=[(name,U8) for name in ('p7','p5','p9','pb','p11','p13','pf1','pf2')]
class Pages:
    def __init__(self,values):
        self.values=dict(zip((7,5,9,11,17,19),values[:6])); self.f=iter(values[6:])
    def __getitem__(self,page):
        return next(self.f) if page==15 else self.values[page]
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-analog-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); lib.egs51_analog_scan.argtypes=[c.POINTER(State),c.POINTER(Inputs)]
        lib.egs51_analog_scan.restype=None
        visited=set()
        def compare(cpu,s,values):
            cpu.input_pages=Pages(values); inputs=Inputs(*values)
            cpu.run(0x206e); lib.egs51_analog_scan(c.byref(s),c.byref(inputs))
            check_memory(cpu,s,[0x20,0x24,0x2b,0x80],range(1024),[0x91-128,0xa0-128])
            visited.update(cpu.visited)
        for j in range(10000):
            cpu=base(0); cpu.x[:]=rng.randbytes(1024)
            for a in (0x20,0x23,0x24,0x2b): cpu.im[a]=rng.randrange(256)
            for a in (0x23,0x24): cpu.im[a]&=rng.choice([255,0])
            for a in (0x6e,0x6f,0x78): cpu.x[a]&=rng.choice([255,0])
            cpu.x[0x75]=rng.randrange(10); cpu.x[0x1b7]=rng.choice([0,255])
            for a in (0x16,0x18,0x1b,0x1c,0x1f): cpu.x[a]=rng.choice([0,0,1,2,3,8,9,10,255])
            cpu.sfr[0xa0-128]=rng.randrange(256)
            raw=rng.choice([0,50,51,52,75,76,77,237,238,239,306,307,308,637,rng.randrange(638)])
            p1=min(raw//2,255); p2=2*(raw-2*p1)
            compare(cpu,state(cpu),[*rng.randbytes(6),p1,p2])
        print('PASS: 10000 full analog scans, fault/clamp/filter/debounce boundaries')
        cpu=base(0); cpu.x[0x75]=3; cpu.x[0x97]=100; s=state(cpu)
        for j in range(3000):
            raw=0 if j%173<4 else 350 if j%233<5 else 76+(j//10)%163
            values=[*rng.randbytes(6),raw//2,2*(raw%2)]
            compare(cpu,s,values)
            # Execute the separately verified timer service between samples.
            cpu.run(0xe48d); lib.egs51_timers_tick(c.byref(s))
            check_memory(cpu,s,xs=range(1024))
        print(f'PASS: 3000 persistent analog/filter + timer cycles; {sum(0x206e<=p<=0x2498 for p in visited)} analog instruction PCs')
if __name__=='__main__': main()
