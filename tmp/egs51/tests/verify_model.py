#!/usr/bin/env python3
"""Build semantic C and differentially compare it to raw ROM execution.

Run from any directory. Requires the local (uncommitted) 128 KiB ROM, Python3,
and a C compiler. Fails on unsupported opcodes and unknown MDU operations.
No routine under test is hooked: arithmetic/map/helper calls execute ROM bytes;
only the MDU timing-pad calls simulate the inferred arithmetic peripheral.
"""
import ctypes as c
import hashlib
from pathlib import Path
import random
import re
import subprocess
import tempfile
from mcs51 import CPU
ROOT=Path(__file__).resolve().parents[1]
ROM=(ROOT/'EGS51_A0215451432.bin').read_bytes()
assert len(ROM)==131072
assert hashlib.md5(ROM).hexdigest()=='46be22165b2489d311a28bb489885825'
U8=c.c_uint8; U16=c.c_uint16
class State(c.Structure):
    _fields_=[('im',U8*256),('x',U8*1024),('sfr',U8*128),('rom',c.POINTER(U8))]
blob=(U8*len(ROM)).from_buffer_copy(ROM)
rng=random.Random(0x51c810)
def word(a,p,v): a[p]=v>>8; a[p+1]=v&255
def state(cpu):
    s=State(); s.rom=blob
    s.im[:]=cpu.im; s.x[:]=cpu.x; s.sfr[:]=cpu.sfr
    return s
def base(bank=1):
    cpu=CPU(ROM,bank)
    word(cpu.x,0x3ce,0xf17a); word(cpu.x,0x273,12000)
    cpu.im[0xac]=1
    return cpu

def check_memory(cpu,s,ims=(),xs=(),sfrs=()):
    for label,old,new,indices in [('im',cpu.im,s.im,ims),('x',cpu.x,s.x,xs),('sfr',cpu.sfr,s.sfr,sfrs)]:
        for a in indices:
            assert old[a]==new[a], f'{label}[{a:03x}]: ROM={old[a]} C={new[a]}'

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-verify-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *[str(p) for p in sorted((ROOT/'reconstructed').glob('egs51_*.c'))],'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        signatures={
            'lag':([U16,U16,U8],U16),'lerp':([U16]*5,U16),
            'map16':([ptr,c.c_uint,U16,U16,U16],U16),'spc':([ptr,U8,U16],U16),
            'pressure_demand':([ptr,U16],U16),'fill_time':([ptr],U8),'hold_time':([ptr],U8),
            'engagement':([ptr],None),'current_control':([ptr],None),'frame_compose':([ptr],None),
            'gear_map':([ptr],None),'output_pattern':([ptr],None),'shift_solenoid_select':([ptr],None),
        }
        for name,(args,ret) in signatures.items():
            f=getattr(lib,'egs51_'+name); f.argtypes=args; f.restype=ret
        def result(cpu): return cpu.r(6)*256+cpu.r(7)
        for j in range(2000):
            cpu=base(); cur=rng.randrange(65536); target=rng.randrange(65536); n=rng.randrange(256)
            cpu.wr(6,cur>>8); cpu.wr(7,cur); cpu.wr(4,target>>8); cpu.wr(5,target); cpu.wr(3,n)
            cpu.run(0x1061)
            assert result(cpu)==lib.egs51_lag(cur,target,n)
            vals=[rng.randrange(65536) for _ in range(5)]
            vals[2:4]=sorted(vals[2:4])
            for k,v in enumerate(vals): word(cpu.im,0x9b+2*k,v)
            cpu.wr(7,0x9b); cpu.run(0x1412)
            assert result(cpu)==lib.egs51_lerp(*vals), vals
        print('PASS: 2000 unsigned ramps + 2000 clamped interpolations')
        for j in range(2000):
            cpu=base(); x=rng.randrange(16000); y=rng.randrange(256)
            word(cpu.im,0xa5,x); word(cpu.im,0xa7,y)
            cpu.wr(6,0xea); cpu.wr(7,0x82); s=state(cpu); cpu.run(0x14f3)
            assert result(cpu)==lib.egs51_map16(c.byref(s),1,0xea82,x,y),(x,y,result(cpu))
        print('PASS: 2000 PCS map lookups (two-stage integer rounding)')
        for j in range(3000):
            cpu=base(); idx=rng.randrange(8); p=rng.randrange(65536)
            cpu.im[0xb6]=rng.randrange(8)
            for a in (0x167,0x168,0x174): cpu.x[a]=rng.randrange(256)
            word(cpu.x,0x273,rng.randrange(20000))
            cpu.wr(7,idx); cpu.wr(4,p>>8); cpu.wr(5,p); s=state(cpu)
            cpu.run(0x7093)
            assert result(cpu)==lib.egs51_spc(c.byref(s),idx,p),(idx,p,result(cpu))
        print('PASS: 3000 clutch-to-SPC conversions, including signed wrap')
        for j in range(2000):
            cpu=base(); p=rng.randrange(16000)
            cpu.im[0xb6]=rng.randrange(8); cpu.im[0xb9]=rng.randrange(7); cpu.im[0xac]=rng.randrange(1,9)
            word(cpu.im,0x44,rng.randrange(16000)); word(cpu.im,0x46,rng.randrange(16000))
            word(cpu.x,0x275,rng.randrange(65536)); word(cpu.x,0x329,rng.randrange(16000)); cpu.x[0x76]=rng.randrange(256)
            cpu.wr(6,p>>8); cpu.wr(7,p); s=state(cpu); cpu.run(0xd76e)
            assert result(cpu)==lib.egs51_pressure_demand(c.byref(s),p),(j,p,result(cpu),lib.egs51_pressure_demand(c.byref(s),p))
        print('PASS: 2000 complete pressure-to-demand calls')
        for j in range(1000):
            cpu=base(); cpu.x[0x76]=j%256; cpu.im[0x9a]=rng.randrange(256)
            word(cpu.x,0x2ac,rng.choice([0,999,1000,1005,2000,65535]))
            word(cpu.x,0x2ef,rng.choice([0,1,2000,65535]))
            s=state(cpu); cpu.run(0x56a6)
            assert cpu.r(7)==lib.egs51_fill_time(c.byref(s))
            cpu.run(0x56de)
            assert cpu.r(7)==lib.egs51_hold_time(c.byref(s))
        print('PASS: 1000 fill/hold helper pairs, including zero engine speed')
        seen=set()
        for j in range(12000):
            cpu=base()
            for a in (0x94,0x95,0x96,0x9a): cpu.im[a]=rng.randrange(256)
            cpu.im[0xb4]=j%10 # nine states and invalid state guard
            for a in (0xb0,0xb1,0xb2): cpu.im[a]=rng.choice([0,0,1,10,255])
            cpu.im[0xb3]=rng.randrange(9); cpu.im[0xab]=rng.randrange(9); cpu.im[0xac]=rng.randrange(1,9)
            cpu.im[0xb6]=rng.randrange(8)
            for a in (0x1bd,0x1c2,0x1ca): cpu.x[a]=rng.randrange(4)
            cpu.x[0x334]=rng.randrange(1,9); cpu.x[0x76]=rng.choice([0,20,49,50,69,70,255])
            for a in (0x1f6,0x22f): word(cpu.x,a,rng.choice([0,110,111,112,1000]))
            word(cpu.x,0x2ac,rng.choice([0,999,1000,1005,1006])); word(cpu.x,0x2ef,rng.choice([0,1,2400]))
            for a in (0x44,0x46,0x48): word(cpu.im,a,rng.randrange(16000))
            for a in (0x167,0x168,0x174): cpu.x[a]=rng.randrange(256)
            s=state(cpu); before=(bytes(cpu.im),bytes(cpu.x)); cpu.run(0x5bb6); lib.egs51_engagement(c.byref(s)); seen.update(cpu.visited)
            try: check_memory(cpu,s,list(range(0x44,0x4a))+[0x94,0x95,0x96,0x9a,0xaa,0xac,0xb0,0xb1,0xb2,0xb4])
            except AssertionError as exc: raise AssertionError(f'engagement case {j}, initial state {j%10}: {exc}; im={before[0][0x94:0xba].hex()} flags={[(hex(a),before[1][a]) for a in (0x1bd,0x1c2,0x334)]}') from exc
        # Rare no-drive state-2 branch: P selected, no force-neutral flags.
        cpu=base(); cpu.im[0xb4]=2; cpu.x[0x334]=8
        s=state(cpu); cpu.run(0x5bb6); lib.egs51_engagement(c.byref(s)); seen.update(cpu.visited)
        check_memory(cpu,s,list(range(0x44,0x4a))+[0x94,0x95,0x96,0x9a,0xaa,0xac,0xb0,0xb1,0xb2,0xb4])
        assert s.im[0xb4]==2 and s.im[0xb0]==0
        listing=ROOT/'disasm/bank1.bin.asm'
        if listing.exists():
            addresses={int(a,16) for a in re.findall(r'^CODE:([0-9a-f]{4}) ',listing.read_text(),re.M) if 0x5bb6<=int(a,16)<=0x6191}
            print('Engagement unvisited listing addresses:', ' '.join(f'{a:04x}' for a in sorted(addresses-seen)))
        print(f'PASS: 12001 engagement calls; {len([a for a in seen if 0x5bb6<=a<=0x6191])} ROM instruction addresses exercised')
        for j in range(3000):
            cpu=base(0); cpu.put(0xd0,0x18) # ISR register bank 3 is significant
            for a in (0x35,0x37,0x42,0x43): cpu.im[a]=rng.randrange(256)
            for a in (0x31,0x33): word(cpu.im,a,rng.choice([0,32767,32768,32769,65535,rng.randrange(65536)]))
            s=state(cpu); cpu.run(0x3eec); lib.egs51_current_control(c.byref(s))
            check_memory(cpu,s,range(0x31,0x35),[0x102,0x105],[0xd9-128,0xda-128])
        print('PASS: 3000 dual current-control updates (scale and polarity)')
        for j in range(2000):
            cpu=base(0); cpu.im[0x21]=rng.randrange(256); cpu.x[0x21]=rng.randrange(256); cpu.x[0x78]=rng.randrange(4)
            for a in range(0xc,0x15): cpu.x[a]=rng.randrange(4)
            s=state(cpu); cpu.run(0x711); lib.egs51_frame_compose(c.byref(s))
            check_memory(cpu,s,[0x21],range(0xc,0x15),[0x20,0x18])
        print('PASS: 2000 peak/hold frame compositions')
        for target in range(256):
            cpu=base(); cpu.x[0x334]=target; cpu.x[0x223]=4; s=state(cpu)
            cpu.run(0x2b86); lib.egs51_gear_map(c.byref(s)); check_memory(cpu,s,[0xb9],[0x223])
        print('PASS: all 256 gear-map inputs')
        for phase in (0,1,4,255):
            for idx in range(256):
                cpu=base(); cpu.im[0xaa]=phase; cpu.im[0xac]=idx; cpu.im[0x95]=0xa0
                s=state(cpu); cpu.run(0x23ee,stop=0x2438); lib.egs51_shift_solenoid_select(c.byref(s))
                check_memory(cpu,s,[0x95])
        for pattern in range(256):
            cpu=base(0); cpu.im[0x95]=pattern; cpu.im[0x21]=0xf8
            s=state(cpu); cpu.run(0x6bcc,stop=0x6be2); lib.egs51_output_pattern(c.byref(s))
            check_memory(cpu,s,[0x21])
            s.x[0x1b3]=1; s.im[0x95]^=7; old=s.im[0x21]
            lib.egs51_output_pattern(c.byref(s)); assert s.im[0x21]==old
        print('PASS: 1024 shift-selection + 256 pattern-transfer fragments')
if __name__=='__main__': main()
