#!/usr/bin/env python3
"""Pass-5 ROM comparisons. SPI bytes and ADC pages are external test inputs;
all firmware callees, ISR stack operations and bank trampolines execute ROM.
"""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, state, base, word, check_memory, U8, U16
from mcs51 import CPU
SPI=c.CFUNCTYPE(U8,c.c_void_p,U8)
MATCH=c.CFUNCTYPE(None,c.c_void_p,U16,U8)
class IO(c.Structure):
    _fields_=[('spi_byte',SPI),('compare',MATCH),('context',c.c_void_p)]
rng=random.Random(0x51_20260910)
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-pass5-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        for name,args,ret in [('cal_select',[ptr],U8),('cal_select_bank0',[ptr],U8),('timers_tick',[ptr],None),('gs218_compose',[ptr],None),
                             ('feedback_scale',[U8,U8,U16],U8),('current_interrupt',[ptr,U8,U8],None),
                             ('spi_exchange',[ptr,U8,c.POINTER(IO)],None),('tcc_interrupt',[ptr,c.POINTER(IO)],None)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=args; fn.restype=ret
        for j in range(512):
            cpu=base(); cpu.x[0x17b]=j%256 if j<256 else 0x22; cpu.x[0x17c]=0x22 if j<256 else j%256
            s=state(cpu); cpu.run(0x20bc); ret=lib.egs51_cal_select(c.byref(s))
            assert ret==cpu.r(7); check_memory(cpu,s,xs=range(0x3b2,0x3d6))
        print('PASS: 512 calibration selector calls, every coding-byte value')
        for j in range(3024):
            cpu=base(0)
            cpu.x[0x175]=ROM[0xfbfb]; cpu.x[0x176]=ROM[0xfbfc]
            cpu.x[0x183]=1; cpu.x[0x184]=2; cpu.x[0x185]=3
            if j<1024: cpu.x[0x177+j//256]=j%256
            else:
                for a in (*range(0x175,0x17b),0x183,0x184,0x185):
                    cpu.x[a]=rng.choice([0,1,2,3,15,255,rng.randrange(256)])
            s=state(cpu); cpu.run(0x7138); ret=lib.egs51_cal_select_bank0(c.byref(s))
            assert ret==cpu.r(7); check_memory(cpu,s,xs=range(1024))
        print('PASS: 3024 bank0 calibration/coding validators, all coding bytes and F fallback')
        for j in range(1000):
            cpu=base(0); cpu.x[:]=rng.randbytes(1024)
            for a in range(0xb0,0xba): cpu.im[a]=rng.choice([0,1,255,rng.randrange(256)])
            s=state(cpu); cpu.run(0xe48d); lib.egs51_timers_tick(c.byref(s))
            check_memory(cpu,s,range(0xb0,0xba),range(1024))
        print('PASS: 1000 complete scheduler timer updates')
        for j in range(4000):
            cpu=base(0); cpu.x[:]=rng.randbytes(1024)
            for a in (0x20,0x85,0x95,0x97,0x9a): cpu.im[a]=rng.randrange(256)
            cpu.im[0xb6]=rng.randrange(8); cpu.im[0xb9]=rng.randrange(9)
            cpu.x[0x334]=rng.randrange(9); cpu.x[0x264]=rng.randrange(9)
            word(cpu.x,0x2f5,rng.choice([0,1,65535])); word(cpu.x,0x2f7,rng.randrange(65536))
            s=state(cpu); cpu.run(0xcfb1); lib.egs51_gs218_compose(c.byref(s))
            check_memory(cpu,s,[0x85],range(1024))
        print('PASS: 4000 GS218 composers, including request latch and fault overrides')
        for j in range(4000):
            cpu=base(0); cpu.put(0xd0,0x18)
            raw=rng.randrange(256); trim=rng.randrange(256); offset=rng.choice([0,32767,32768,65535,rng.randrange(65536)])
            cpu.wr(7,raw); cpu.wr(3,trim); cpu.wr(4,offset>>8); cpu.wr(5,offset)
            cpu.run(0x5aca)
            out=lib.egs51_feedback_scale(raw,trim,offset)
            assert out==cpu.r(7),(raw,trim,offset,out,cpu.r(7))
        print('PASS: 4000 feedback scalings, signed trim/overflow/rounding')
        for j in range(2000):
            cpu=base(j%2); p1=rng.randrange(256); p3=rng.randrange(256); cpu.input_pages={1:p1,3:p3}
            for a in (0x35,0x37,0x188,0x189):
                (cpu.im if a<256 else cpu.x)[a]=rng.randrange(256)
            for a in (0x18a,0x18c): word(cpu.x,a,rng.randrange(65536))
            for a in (0x31,0x33): word(cpu.im,a,rng.randrange(65536))
            for a in (0x78,0x101,3): cpu.x[a]=rng.randrange(4)
            for a in (0xfa,0xfb,0xf8): cpu.put(a,rng.randrange(256))
            s=state(cpu); cpu.run(0x1fd); lib.egs51_current_interrupt(c.byref(s),p1,p3)
            check_memory(cpu,s,[0x31,0x32,0x33,0x34,0x35,0x37,0x42,0x43],range(1024),[0x91-128,0xd9-128,0xda-128,0xec-128,0xed-128,0x88-128])
            assert cpu.bank==j%2
        print('PASS: 2000 complete current ISRs, both entry banks and bank restoration')
        for j in range(2000):
            cpu=base(0); cpu.x[:]=rng.randbytes(1024)
            cpu.x[7]=j%4; cpu.x[0xb]=rng.randrange(5); cpu.im[0x36]=j%256
            cpu.x[0x78]=rng.choice([0,0,0,2]); cpu.im[0x21]=rng.randrange(256); cpu.im[0x2a]=rng.randrange(256)
            cpu.put(0xfa,rng.randrange(256)); cpu.put(0xfb,rng.randrange(256))
            rx=list(rng.randbytes(2)); cpu.spi_rx=rx.copy(); sent=[]; matches=[]
            @SPI
            def spi(_,tx): sent.append(tx); return rx[len(sent)-1]
            @MATCH
            def match(_,counter,control): matches.append((counter,control))
            io=IO(spi,match,None); s=state(cpu); cpu.run(0x2ac); lib.egs51_tcc_interrupt(c.byref(s),c.byref(io))
            check_memory(cpu,s,[0x21,0x2a,0x36],range(1024),[a-128 for a in (0x80,0xc6,0xc7,0xee,0xef,0xdd,0xf3,0xf4)])
            assert cpu.spi_tx==sent and cpu.events==matches
        print('PASS: 2000 full TCC interrupt state machines and SPI/compare event sequences')
        for j in range(1000):
            cpu=base(0); mode=j%4; n=rng.randrange(16); cpu.x[0xfc]=n; cpu.x[0x195]=rng.randrange(3)
            cpu.x[0xfd:0x10d]=rng.randbytes(16)
            rx=list(rng.randbytes(2 if mode==1 else max(1,n))); cpu.spi_rx=rx.copy(); sent=[]
            @SPI
            def spi(_,tx): sent.append(tx); return rx[len(sent)-1]
            @MATCH
            def match(_,counter,control): raise AssertionError('unexpected compare')
            io=IO(spi,match,None); s=state(cpu); cpu.wr(7,mode); cpu.run(0x68e)
            lib.egs51_spi_exchange(c.byref(s),mode,c.byref(io))
            check_memory(cpu,s,xs=range(1024),sfrs=[a-128 for a in (0x80,0x88,0xc6,0xc7)])
            assert cpu.spi_tx==sent
        print('PASS: 1000 SPI calls, both modes, zero length and ignored modes')
if __name__=='__main__': main()
