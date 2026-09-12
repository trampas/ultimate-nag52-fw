#!/usr/bin/env python3
"""OEM shaft capture-period processing and persistent range changes."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, base, state, word, check_memory
ROUTINES=[('shaft_capture_n2',0x547f),('shaft_capture_n3',0x5635)]
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
                cpu.x[0x1a8]=rng.choice([0,0,0,1]);cpu.im[0x80]=j%256
                cpu.x[3]=rng.randrange(10);cpu.x[0]=rng.randrange(16)
                cpu.put(0xf8,rng.randrange(256))
                cpu.put(0xc8,rng.randrange(256));cpu.put(0xa8,rng.randrange(256))
                cpu.put(0xfd,rng.randrange(256));cpu.put(0xfe,rng.randrange(256))
                word(cpu.im,0x8a,rng.randrange(1,65536));word(cpu.im,0x8c,rng.randrange(1,65536))
                word(cpu.im,0x5d,rng.randrange(65536));word(cpu.im,0x5f,rng.randrange(65536))
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
                try:check_memory(cpu,native,IMS,range(1024),[0x18,0x48,0x7d,0x7e])
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 16000 complete {name} comparisons',flush=True)
        cpu=configured();cpu.x[0xf3]=0xb8;cpu.x[0xf4]=0x8b
        native=state(cpu)
        functions=[lib.egs51_shaft_capture_n2,lib.egs51_shaft_capture_n3]
        for tick in range(2400):
            for st in (cpu,native):
                st.im[0x2d]|=12
                word(st.im,0x8a,[500,1250,3334,65000][(tick//60)%4])
                word(st.im,0x8c,[65000,500,625,2000][(tick//80)%4])
                if tick%7==0:st.im[0x2d]&=0xf3;st.x[0xfa]=st.x[0xfb]=0
            for fn,entry in zip(functions,[0x547f,0x5635]):
                cpu.run(entry);fn(c.byref(native))
                check_memory(cpu,native,IMS,range(1024),[0x18,0x48,0x7d,0x7e])
        print('PASS: 4800 persistent shaft capture calls with timeout and range transitions',flush=True)
if __name__=='__main__':main()
