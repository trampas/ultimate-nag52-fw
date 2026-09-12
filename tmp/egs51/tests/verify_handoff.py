#!/usr/bin/env python3
"""Native NAG52 handoff math and semantic helper tests against raw ROM.

No pressure/math/firmware calls are hooked. Snapshot inputs include physically
unreachable combinations to test integer boundaries; this is not a vehicle sim.
"""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, base, state, word, check_memory

rng=random.Random(0x9ace)
def configured():
    cpu=base()
    cpu.x[:]=rng.randbytes(1024)
    cpu.x[0x17b]=rng.randrange(3)*16+rng.randrange(2)
    cpu.x[0x17c]=rng.randrange(3)*16+rng.randrange(3)
    cpu.run(0x20bc); assert cpu.r(7)==0
    cpu.im[0xb6]=rng.randrange(1,5)
    cpu.im[0xb9]=rng.randrange(2,5)
    cpu.im[0xac]=rng.randrange(1,9)
    cpu.im[0x56]=rng.randrange(6)
    for a in range(0x44,0x56,2):word(cpu.im,a,rng.randrange(65536))
    for a in (0x95,0x96,0x98,0x99,0xaf,0xb0):cpu.im[a]=rng.randrange(256)
    return cpu

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-handoff-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        signatures={
            'handoff_root_test':([U16],U16),
            'handoff_high_pressure':([ptr,U8],U16),
            'handoff_low_pressure':([ptr,U8],U16),
            'handoff_clutch_pressure':([ptr,U16],U16),
            'shift_feedback_reset':([ptr],None),
            'shift_clutch_context':([ptr],None),
            'downshift_handoff_advance':([ptr],None),
        }
        for name,(args,ret) in signatures.items():
            fn=getattr(lib,'egs51_'+name);fn.argtypes=args;fn.restype=ret
        for value in range(65536):
            cpu=base();cpu.wr(6,value>>8);cpu.wr(7,value)
            cpu.run(0x0ce8)
            expected=cpu.r(6)*256+cpu.r(7)
            got=lib.egs51_handoff_root_test(value)
            assert expected==got,(value,expected,got)
        print('PASS: all 65536 root-helper inputs match native NAG52 arithmetic',flush=True)
        for name,entry in [('handoff_high_pressure',0x4480),('handoff_low_pressure',0x4535),
                           ('handoff_clutch_pressure',0x719a)]:
            for j in range(3000):
                cpu=configured()
                value=cpu.im[0xb6] if entry!=0x719a else rng.randrange(65536)
                cpu.wr(6,value>>8);cpu.wr(7,value)
                s=state(cpu);cpu.run(entry)
                expected=cpu.r(6)*256+cpu.r(7)
                got=getattr(lib,'egs51_'+name)(c.byref(s),value)
                assert expected==got,(name,j,expected,got)
                check_memory(cpu,s,xs=range(1024))
            print(f'PASS: 3000 {name} snapshots',flush=True)
        for name,entry in [('shift_feedback_reset',0x6192),('shift_clutch_context',0x61cf),
                           ('downshift_handoff_advance',0x9ace)]:
            for j in range(6000):
                cpu=configured()
                # Forward upshifts arrive in gears2..5; the handoff helper is
                # called from downshift modes with B9=2..4 before decrement.
                if entry==0x9ace:cpu.im[0xb6]=rng.choice([3,4])
                s=state(cpu);cpu.run(entry)
                getattr(lib,'egs51_'+name)(c.byref(s))
                check_memory(cpu,s,list(range(0x44,0x58))+list(range(0xaa,0xba))+[0x95,0x96,0x98,0x99],range(1024))
            print(f'PASS: 6000 complete {name} calls including all firmware callees',flush=True)
        print('PASS: 92536 raw-ROM comparisons; no physical timing or vehicle reachability claim')
if __name__=='__main__':main()
