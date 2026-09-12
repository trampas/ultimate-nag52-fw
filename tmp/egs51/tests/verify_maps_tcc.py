#!/usr/bin/env python3
"""Byte map, fill term and final TCC demand/override ROM comparisons."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, base, word, check_memory, U8, U16
rng=random.Random(0xb77b)
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-maps-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        for name,args,ret in [('map8',[ptr,c.c_uint,U16,U8,U8],U8),('curve16',[ptr,c.c_uint,U16,U16],U16),
                             ('fill_term',[ptr],U8),('tcc_demand',[ptr],None),('tcc_override',[ptr],None)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=args; fn.restype=ret
        for j in range(3000):
            cpu=base(); cpu.x[0x17b]=(j%3)<<4; cpu.run(0x20bc)
            desc=cpu.x[0x3c8]*256+cpu.x[0x3c9]; x=rng.randrange(7); y=rng.randrange(256)
            # Nonzero high bytes prove 1904 consumes only the low input bytes.
            word(cpu.im,0xa5,0x7300+x); word(cpu.im,0xa7,0x8100+y)
            cpu.wr(6,desc>>8); cpu.wr(7,desc); s=state(cpu); cpu.run(0x1904)
            assert cpu.r(7)==lib.egs51_map8(c.byref(s),1,desc,x,y)
            cpu.im[0x56]=rng.randrange(5); cpu.im[0xac]=rng.randrange(1,9); cpu.x[0x76]=y
            cpu.wr(7,255) # deliberately different from IRAM56
            for a in range(0x16d,0x174): cpu.x[a]=rng.randrange(256)
            s=state(cpu); cpu.run(0x6856); ret=lib.egs51_fill_term(c.byref(s))
            assert ret==cpu.r(7); check_memory(cpu,s,xs=range(1024))
        print('PASS: 3000 byte-map + 3000 full fill-term calls across three variants')
        for j in range(3000):
            cpu=base(0); value=rng.randrange(65536); word(cpu.im,0xa5,value)
            cpu.wr(6,0xed); cpu.wr(7,0xec); s=state(cpu); cpu.run(0x12be)
            assert cpu.r(6)*256+cpu.r(7)==lib.egs51_curve16(c.byref(s),0,0xedec,value)
        print('PASS: 3000 word-curve lookups')
        for j in range(5000):
            cpu=base(0); cpu.im[0x56]=rng.choice([0,1,2]); word(cpu.im,0x4e,rng.randrange(65536))
            cpu.x[0x76]=rng.randrange(256); cpu.x[0x11e]=rng.randrange(256)
            s=state(cpu); cpu.run(0xb77b); lib.egs51_tcc_demand(c.byref(s))
            check_memory(cpu,s,[0x36],range(1024))
        print('PASS: 5000 final TCC demand conversions')
        for j in range(5000):
            cpu=base(0); cpu.x[:]=rng.randbytes(1024)
            cpu.im[0x36]=rng.randrange(256); cpu.im[0x56]=rng.choice([0,0,1]); cpu.im[0xb6]=rng.choice([0,0,2]); cpu.im[0xb9]=rng.choice([0,0,3])
            for a in (0x1ca,0x1cb,0x73): cpu.x[a]=rng.choice([0,0,rng.randrange(256)])
            for a in (0x316,0x383): cpu.x[a]=rng.choice([0,1,255])
            s=state(cpu); cpu.run(0x9f23); lib.egs51_tcc_override(c.byref(s))
            check_memory(cpu,s,[0x36,0x64,0x65],range(1024))
        print('PASS: 5000 complete TCC override/diagnostic timer calls')
if __name__=='__main__': main()
