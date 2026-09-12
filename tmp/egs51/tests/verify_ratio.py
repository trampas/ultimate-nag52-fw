#!/usr/bin/env python3
"""Ratio observation and recovery compared with complete unhooked ROM calls."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, base, state, word, check_memory
ROUTINES=[('wheel_motion',0xd3e2),('ratio_recovery',0xd8d2),('ratio_observer',0xd456)]
IMS=[*range(0x20,0x30),*range(0x80,0x9b),*range(0xa9,0xc0)]
def main():
    rng=random.Random(0xd456);visited=set()
    with tempfile.TemporaryDirectory(prefix='egs51-ratio-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry in ROUTINES:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(State)];fn.restype=None
            for j in range(16000):
                cpu=base(0);cpu.x[:]=rng.randbytes(1024)
                for a in IMS:cpu.im[a]=rng.randrange(256)
                cpu.x[0x390]=rng.choice([0,0,0,1,2,3,4,5,253,254,255,6])
                cpu.x[0x35e]=rng.randrange(4);cpu.x[0x210]=rng.randrange(3)
                cpu.x[0x2ec]=rng.choice([0,1,2,3,4,5,0x17,0x58,255]);cpu.x[0x389]=rng.choice([0,1,3,5,0x17,255])
                cpu.x[0x334]=rng.randrange(1,9);cpu.im[0xb9]=rng.randrange(1,6);cpu.im[0xb6]=rng.randrange(8)
                for a in (0x2a4,0x359,0x352,0x2a8):cpu.x[a]=rng.choice([0,0,1,255])
                cpu.im[0x9a]&=rng.choice([254,255]);cpu.x[0x78]&=rng.choice([253,255]);cpu.x[0x73]&=rng.choice([253,255])
                if j%2:
                    cpu.x[0x1c6]=8;cpu.x[0x6e]=0;cpu.x[0x1cb]=0;cpu.x[0x1bb]=0;cpu.im[0x24]&=254
                    speed=rng.choice([200,500,1000,1500]);word(cpu.x,0x375,speed)
                    ratio=rng.choice([508,910,1000,1486,1899,2408])+rng.randrange(-30,31)
                    word(cpu.im,0x81,ratio*speed//1000)
                    word(cpu.im,0x83,rng.choice([0,ratio*speed//1000,500]))
                    for a in (0x332,0x349,0x314,0x323):word(cpu.x,a,rng.choice([0,100,1000]))
                native=state(cpu);cpu.run(entry);fn(c.byref(native));visited.update(cpu.visited)
                try:check_memory(cpu,native,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 16000 complete {name} comparisons',flush=True)
        # Persistent observer/timer sequence: no oracle state copied into native.
        cpu=base(0);cpu.x[0x1c6]=8;cpu.im[0xb9]=3;cpu.x[0x334]=3
        native=state(cpu)
        for tick in range(3200):
            for st in (cpu,native):
                word(st.x,0x375,1000)
                ratio=[1486,2408,1000,508,3000,0][(tick//80)%6]
                word(st.im,0x81,ratio);word(st.im,0x83,0 if tick%160<80 else ratio)
                st.im[0xb6]=0 if tick%200<150 else 3
                st.x[0x73]=2 if tick%397<5 else 0
                for a in (0x332,0x349,0x314,0x323):word(st.x,a,1000 if tick%400<300 else 0)
            for name,entry in [('ratio_observer',0xd456),('timers_tick',0xe48d)]:
                cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native));visited.update(cpu.visited)
                check_memory(cpu,native,IMS,range(1024))
        required={0xd605,0xd60d,0xd65b,0xd6a3,0xd6e2,0xd71e,0xd75c,0xd764,
                  0xd8f8,0xdc50,0xdcdd,0xdd39,0xdd86,0xde15,0xded9,0xdf3f,0xdf79}
        assert required<=visited,('missing branches',sorted(required-visited))
        print('PASS: 6400 persistent ratio/timer calls; every recognition and recovery state',flush=True)
if __name__=='__main__':main()
