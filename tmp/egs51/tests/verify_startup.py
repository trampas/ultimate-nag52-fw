#!/usr/bin/env python3
"""OEM startup, physical selector decoding and platform timers."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, base, state, word, check_memory
ROUTINES=[('controller_init',0x6ec2),('pressure_init',0x10ba),('selector_inputs',0x1dd0),('platform_timers',0x6cf8)]
IMS=[*range(0x20,0x30),*range(0x80,0x9b),*range(0xa9,0xc0)]
def configured():
    cpu=base(0);cpu.x[0x175]=ROM[0xfbfb];cpu.x[0x176]=ROM[0xfbfc]
    cpu.x[0x183]=1;cpu.x[0x184]=3;cpu.x[0x185]=10;cpu.run(0x7138);assert cpu.r(7)==0
    return cpu

def main():
    rng=random.Random(0x8814);visited=set()
    with tempfile.TemporaryDirectory(prefix='egs51-demand-load-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry in ROUTINES:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(State)];fn.restype=c.c_uint8 if name.endswith("init") else None
            for j in range(16000):
                cpu=configured();cpu.x[:0x3a4]=rng.randbytes(0x3a4)
                for a in IMS:cpu.im[a]=rng.randrange(256)
                cpu.x[0x17b]=rng.choice([0,16,32]);cpu.x[0x17c]=rng.choice([0,1,2,16,17,18,32,33,34])
                cpu.x[0x75]=rng.randrange(1,9);cpu.x[0x227]=rng.randrange(1,6)
                cpu.x[0x183]=rng.randrange(3);cpu.x[0x184]=rng.choice([2,3])
                cpu.x[3]=rng.randrange(10);cpu.x[0]=rng.randrange(16)
                cpu.put(0xf8,rng.randrange(256))
                word(cpu.x,0x181,rng.randrange(1,65536))
                cpu.im[0xb9]=cpu.x[0x227]=rng.randrange(1,6)
                cpu.x[0x2d1]=min(cpu.x[0x227]-1,3);cpu.x[0x2eb]=max(cpu.x[0x227]-2,0)
                cpu.im[0xb6]=rng.choice([0,0,0,1,7]);cpu.x[0x335]=cpu.x[0x338]=0
                cpu.x[0x1c5]&=rng.choice([0,0,0,255]);cpu.x[0x1c7]&=251
                cpu.x[0x1cb]&=rng.choice([0,0,255]);cpu.x[0x377]=rng.choice([0,4,0x40,0x44])
                word(cpu.x,0x2ac,rng.choice([0,1,100,200,5000]) if name=='vehicle_acceleration' else rng.randrange(200,5000));word(cpu.x,0x29d,rng.randrange(101))
                cpu.x[0x1cc]=rng.randrange(101)
                # FC8E is zero in this ROM; an asserted 1C5.6 with nonzero
                # load reaches a zero divisor in the original MDU as well.
                if name=='load_scale' and cpu.x[0x1c5]&0x40:word(cpu.x,0x1f3,0)
                if name=='pressure_init':cpu.put(0x88,cpu.direct(0x88)|16)
                native=state(cpu);cpu.run(entry);result=fn(c.byref(native));visited.update(cpu.visited)
                if name in ('controller_init','pressure_init'):assert result==cpu.r(7)
                try:check_memory(cpu,native,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 16000 complete {name} comparisons',flush=True)
if __name__=='__main__':main()
