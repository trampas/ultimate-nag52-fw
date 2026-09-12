#!/usr/bin/env python3
"""Complete 7331 gear-demand routine against the original ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory
from verify_demand_load import configured, IMS

def main():
    rng=random.Random(0x7331);visited=set();demands=set()
    with tempfile.TemporaryDirectory(prefix='egs51-gear-demand-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_gear_demand;fn.argtypes=[c.POINTER(State)];fn.restype=None
        for j in range(12000):
            cpu=configured()
            cpu.x[:0x175]=rng.randbytes(0x175);cpu.x[0x186:0x3a4]=rng.randbytes(0x3a4-0x186)
            for a in IMS:cpu.im[a]=rng.randrange(256)
            cpu.im[0xb9]=rng.randrange(0,9);cpu.im[0xab]=rng.randrange(1,6);cpu.im[0xb6]=rng.randrange(8)
            cpu.im[0xaa]=rng.randrange(6);cpu.x[0x334]=rng.randrange(1,9);cpu.x[0x23d]=rng.randrange(5)
            cpu.x[0x1c5]&=0xbf # FC8E=0 has no defined load scale for nonzero road load.
            cpu.x[0x377]=rng.choice([0,4,0x40,0x44]);cpu.x[0x335]=cpu.x[0x338]=0
            cpu.x[0x328]=rng.randrange(16);cpu.x[0x2ce]=rng.randrange(6)
            cpu.x[0x353]=rng.randrange(80);cpu.x[0x76]=rng.randrange(60,200)
            cpu.x[0x285]=rng.randrange(251);cpu.x[0x39d]=rng.randrange(251)
            for a,v in ((0x181,1000),(0x270,1000),(0x275,rng.randrange(600,4500)),
                        (0x2ac,rng.randrange(200,5000)),(0x2d4,rng.randrange(3000)),
                        (0x2ef,rng.randrange(2000)),(0x27a,rng.randrange(251)),(0x29d,rng.randrange(101))):word(cpu.x,a,v)
            native=state(cpu)
            cpu.run(0x7331);fn(c.byref(native));visited.update(cpu.visited);demands.add(native.im[0xab])
            try:check_memory(cpu,native,IMS,range(1024),[0x18])
            except AssertionError as e:
                diffs=[(hex(a),cpu.x[a],native.x[a]) for a in range(1024) if cpu.x[a]!=native.x[a]]
                raise AssertionError((j,str(e),diffs)) from e
        print(f'PASS: 12000 complete gear-demand comparisons; demanded gears {sorted(demands)}',flush=True)
if __name__=='__main__':main()
