#!/usr/bin/env python3
"""Differential checks for TCC entry, operating states and adaptation."""
import ctypes as c
import argparse
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, state, base, word, check_memory
from verify_tcc_control import configured
rng=random.Random(0xa04b)
def main():
    parser=argparse.ArgumentParser(); parser.add_argument('--only'); args=parser.parse_args()
    with tempfile.TemporaryDirectory(prefix='egs51-tcc-states-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry,count in [('tcc_entry',0xa04b,12000),('tcc_excess_slip',0xa632,10000),('tcc_supervisor',0xa88b,20000),('tcc_adapt',0xafe1,24000),('tcc_scheduler',0xb838,24000)]:
            if args.only and args.only!=name: continue
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]; fn.restype=None
            visited=set()
            for j in range(count):
                cpu=configured(); cpu.x[0x30d]=j%7; cpu.x[0x37d]=rng.choice([0,0,1,2,255])
                cpu.im[0x2b]=rng.choice([0,128]); cpu.x[0x79]=rng.choice([0,2]); cpu.x[0x246]=rng.choice([0,2])
                for addr in (0x224,0x2b5): word(cpu.x,addr,rng.choice([0,1,65535,rng.randrange(65536)]))
                cpu.x[0x1c0]=rng.randrange(256)
                if name=='tcc_supervisor':
                    cpu.im[0x56]=j%5; cpu.im[0xb6]=rng.choice([0,0,0,1,2])
                    cpu.x[0x331]=rng.choice([0,0,0,1,255]); cpu.x[0x1c7]=rng.choice([0,0,0,32])
                    cpu.x[0x1c8]=rng.choice([0,0,0,64]); cpu.x[0x76]=rng.randrange(80,180)
                    word(cpu.x,0x1f3,rng.randrange(6000)); word(cpu.x,0x340,rng.randrange(1000,6000))
                if name=='tcc_adapt':
                    cpu.im[0x56]=3 if j%7 else 2; word(cpu.x,0x1dc,0 if j%11 else 1)
                    cpu.x[0x76]=rng.choice([109,110,111,130,159,160,161])
                    word(cpu.x,0x224,rng.choice([0,34,35,36,65535])); word(cpu.x,0x1f3,rng.randrange(2500))
                    word(cpu.x,0x340,rng.randrange(1000,3000))
                    word(cpu.x,0x1d4,rng.choice([0xffc3,0xffc4,0xffc5,0xffd8,0xffe6,0xffe7,0xffe8,0,19,20,21,35,36,49,50,51,99,100,101,199,200,201]))
                    word(cpu.im,0x50,abs(int.from_bytes(cpu.x[0x2b5:0x2b7],'big',signed=True)))
                    word(cpu.im,0x4e,rng.choice([399,400,401,2000,2999,3000,3001]))
                    cpu.x[0x2b4]=rng.choice([0,1,49,50,51]); cpu.x[0x2e7]=rng.randrange(3)
                    cpu.x[0x277]=rng.choice([0,1,99,100,101])
                if name=='tcc_scheduler':
                    cpu.x[0x252:0x266]=cpu.im[0x44:0x58]
                    cpu.x[0x264]=j%5; cpu.x[0x265]=rng.randrange(3)
                    cpu.x[0x78]=rng.choice([0,0,0,2]); cpu.x[0x73]=rng.choice([0,0,0,8])
                    cpu.x[0x1ca]=rng.choice([0,0,0,0,1,2,8]); cpu.x[0x1cb]=rng.choice([0,0,0,8])
                    cpu.x[0x246]=rng.choice([1,5,7,16,20,22]); cpu.x[0x1c6]=rng.randrange(2)
                    cpu.x[0x3d6]=rng.choice([0,1,2,255]); cpu.x[0x1c8]=rng.choice([0,64])
                    cpu.x[0x331]=rng.choice([0,0,0,1]); cpu.im[0xb6]=rng.choice([0,0,1])
                    cpu.x[0x1c7]=rng.choice([0,0,32]); cpu.x[0x76]=rng.randrange(80,180)
                    word(cpu.x,0x1dc,0 if j%3 else 1)
                    word(cpu.x,0x1f3,rng.randrange(2500)); word(cpu.x,0x340,rng.randrange(1000,3000))
                    word(cpu.x,0x395,rng.choice([0,150,30,65500,rng.randrange(65536)]))
                before=(bytes(cpu.im),bytes(cpu.x)); s=state(cpu)
                cpu.run(entry); fn(c.byref(s)); visited.update(cpu.visited)
                # 64/65 are helper scratch in the enclosing scheduler; the
                # persistent context is44..57, stored back into X252..265.
                try: check_memory(cpu,s,([0x36] if name=='tcc_scheduler' else [])+list(range(0x44,0x58)),range(1024),[0x98-128] if name=='tcc_scheduler' else [])
                except AssertionError as exc:
                    raise AssertionError(f'{name} case{j}, phase={before[1][0x30d]} timer={before[1][0x37d]} flags={before[1][0x1c0]:02x}: {exc}') from exc
            print(f'PASS: {count} complete {name} calls; {len(visited)} instruction PCs including callees')
        if not args.only or args.only=='persistent':
            for name in ('tcc_scheduler','timers_tick'):
                fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]; fn.restype=None
            # This trajectory intentionally uses variant0: variant1 has zero
            # entry timers and need not expose every phase at call boundaries.
            cpu=base(0)
            for cell,table in ((0x3b0,0xecb0),(0x3b8,0xec90)):
                word(cpu.x,cell,int.from_bytes(ROM[table:table+2],'big'))
            cpu.x[0x252:0x266]=bytes(20)
            cpu.x[0x264]=0; cpu.x[0x265]=1; cpu.x[0x30d]=0; cpu.im[0xb9]=4; cpu.im[0xb6]=0
            for a in (0x78,0x73,0x1ca,0x1cb,0x1c7,0x1c8,0x1c0,0x331,0x3d6,0x79): cpu.x[a]=0
            cpu.im[0x2b]=0; cpu.x[0x1c6]=0; cpu.x[0x246]=7
            cpu.x[0x76]=130; cpu.x[0x285]=40; word(cpu.x,0x2ac,5000)
            word(cpu.x,0x340,2000); word(cpu.x,0x1da,1800); word(cpu.x,0x395,40)
            word(cpu.x,0x1f3,0); word(cpu.x,0x224,0); word(cpu.x,0x1dc,0)
            word(cpu.x,0x2c5,40)
            cpu.x[0x11f]=100; cpu.x[0x11d]=0; cpu.x[0x11e]=0
            cpu.x[0x121:0x127]=bytes([100]*6)
            s=state(cpu); phases=set(); modes=set()
            for j in range(3000):
                # Toggle inhibit long enough to observe release and restart.
                cpu.x[0x1c7]=s.x[0x1c7]=32 if j%600>=400 else 0
                cpu.run(0xb838); lib.egs51_tcc_scheduler(c.byref(s))
                check_memory(cpu,s,[0x36,*range(0x44,0x58)],range(1024),[0x98-128])
                phases.add(cpu.x[0x30d]); modes.add(cpu.x[0x264])
                cpu.run(0xe48d); lib.egs51_timers_tick(c.byref(s)); check_memory(cpu,s,xs=range(1024))
            assert {1,2,3,4}<=phases and {0,1,2,3}<=modes,(phases,modes)
            print(f'PASS: 3000 persistent TCC scheduler/timer cycles; entry phases {sorted(phases)}, operating modes {sorted(modes)}')
if __name__=='__main__': main()
