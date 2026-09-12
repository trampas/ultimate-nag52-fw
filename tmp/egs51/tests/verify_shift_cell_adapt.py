#!/usr/bin/env python3
"""Complete B708 qualification and completed-shift cell updates versus ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory, base
from verify_handoff import configured

def main():
    rng=random.Random(0xb708);visited=set();writes=0
    with tempfile.TemporaryDirectory(prefix='egs51-shift-cells-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_shift_cell_adaptation;fn.argtypes=[c.POINTER(State)];fn.restype=None
        for j in range(20000):
            cpu=configured();cpu.im[0xb6]=rng.randrange(8) if j%2 else 0
            cpu.x[0x313]=1+(j//2)%4;cpu.x[0x1f5]=rng.choice([0,1,2,255])
            cpu.im[0xac]=rng.randrange(1,5) if cpu.x[0x313]<=2 else rng.randrange(5,9)
            cpu.im[0xb9]=rng.randrange(1,6);cpu.im[0xaa]=rng.randrange(6)
            word(cpu.x,0x181,rng.randrange(1,65536));word(cpu.x,0x305,0x13f)
            cpu.x[0x79]=rng.choice([0,0,4,8]);cpu.im[0x99]=rng.choice([0x20,0x60,0xff])
            cpu.x[0x1e5]=rng.choice([0,1,2,100,255])
            before=bytes(cpu.x[0x127:0x167]);s=state(cpu)
            cpu.run(0xb708);fn(c.byref(s));visited.update(cpu.visited)
            try:check_memory(cpu,s,range(0x95,0xc0),range(1024))
            except AssertionError as e:raise AssertionError((j,str(e))) from e
            writes+=bytes(cpu.x[0x127:0x167])!=before
        required={0xb726,0xb741,0xb79f,0xb832,0xb9ec,0xb9f3,0xbac3,
                  0xbc82,0xbd47,0xbdaf,0xbe64,0xbf47,0xc014,0xc074}
        assert required<=visited,('uncovered branches',sorted(required-visited))
        assert writes>0
        print(f'PASS: 20000 complete shift-cell adaptation calls; {writes} cell changes; all four completed-shift families',flush=True)
        changes=0;checks=0;clamps=0
        for mode in range(1,5):
            for polarity in (-1,1):
                cpu=base();cpu.x[0x17b]=0x20;cpu.x[0x17c]=0x22;cpu.run(0x20bc)
                cpu.im[0xac]=1 if mode<=2 else 5;cpu.im[0xb9]=3;cpu.x[0x76]=120
                word(cpu.x,0x305,0x13f);word(cpu.x,0x298,2000);word(cpu.x,0x317,1000)
                word(cpu.x,0x23b,100);word(cpu.x,0x181,1000)
                native=state(cpu)
                for shift in range(64):
                    # Completed shift observations are synthetic; adaptation
                    # qualifications, correction cells and their clamps persist.
                    for st in (cpu,native):
                        st.im[0xb6]=mode;st.x[0x1e5]=10
                        word(st.x,0x1ee,(polarity*2000)&65535)
                    cpu.run(0xb708);fn(c.byref(native));checks+=1
                    check_memory(cpu,native,range(0x95,0xc0),range(1024))
                    assert native.im[0x99]&0x20
                    before=bytes(native.x[0x127:0x167])
                    cpu.im[0xb6]=native.im[0xb6]=0
                    cpu.run(0xb708);fn(c.byref(native));checks+=1
                    check_memory(cpu,native,range(0x95,0xc0),range(1024))
                    assert not native.im[0x99]&0x20
                    changes+=bytes(native.x[0x127:0x167])!=before
                clamps+=any(v in (60,196) for v in native.x[0x127:0x167])
        assert changes and clamps==8,(changes,clamps)
        print(f'PASS: {checks} persistent qualification/completion calls, {changes} changing records; all 8 signed cell trajectories reach OEM clamps',flush=True)
if __name__=='__main__':main()
