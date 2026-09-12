#!/usr/bin/env python3
"""Execute the complete bank-switching normal scheduler through 6EC1 versus native C."""
import ctypes as c
from pathlib import Path
import subprocess
import tempfile
from verify_model import ROOT, State, ROM, base, state, word, check_memory

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-scheduler-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_scheduler_tick;fn.argtypes=[c.POINTER(State)];fn.restype=None
        cpu=base(0)
        cpu.x[0x175]=ROM[0xfbfb];cpu.x[0x176]=ROM[0xfbfc]
        cpu.x[0x183]=1;cpu.x[0x184]=3;cpu.x[0x185]=10;cpu.run(0x7138);assert cpu.r(7)==0
        cpu.x[0x17b]=32;cpu.x[0x17c]=34
        cpu.put(0x88,cpu.direct(0x88)|16);cpu.run(0x20bc);assert cpu.r(7)==0
        for a in (0xb9,0xb3,0xab,0xa9):cpu.im[a]=3
        cpu.x[0x75]=cpu.x[0x334]=cpu.x[0x227]=3
        cpu.x[0x76]=120;cpu.x[0x202]=10;cpu.x[0x2c0]=50;cpu.x[0x1c6]=16
        for a,v in ((0x329,9000),(0x181,1000),(0x17f,3000),(0x203,3000)):word(cpu.x,a,v)
        cpu.run(0x2bb2);cpu.x[0x361:0x375]=cpu.im[0x44:0x58]
        cpu.put(0x88,cpu.direct(0x88)&~16);native=state(cpu)
        ims=[*range(0x20,0x30),0x35,0x37,*range(0x44,0x58),*range(0x80,0x9b),*range(0xa9,0xba)]
        visited=set();modes=set()
        for tick in range(3200):
            # Scripted decoded inputs and physical selector/range, without a
            # transmission plant. Controller state is independently retained.
            desired=[3,2,1,3,5,4][(tick//300)%6]
            for st in (cpu,native):
                st.x[0x75]=desired # selector/range input; automatic gear demand IAB is controller-owned
                st.im[0x86]=80+(tick//100)%100
                word(st.im,0x87,1500+tick%500)
                word(st.im,0x81,1000+tick%700);word(st.im,0x83,800+tick%700)
                for a in (0x81,0x84,0x87,0x89):word(st.x,a,80+tick%100)
                st.x[0x9b]=100;st.x[0x9e]=110;st.x[0x9f]=120;st.x[0x8b]=120;st.x[0x86]=30
            try:
                cpu.run(0x6e6a,stop=0x6ec1,stop_bank=0);fn(c.byref(native))
                assert cpu.pc==0x6ec1 and cpu.bank==0 and cpu.direct(0x81)==0xc0
                check_memory(cpu,native,ims,range(1024))
            except Exception as e:raise AssertionError((tick,cpu.im[0xb6],cpu.im[0xaa],cpu.direct(0x88),str(e))) from e
            modes.add(native.im[0xb6]);visited.update(cpu.visited)
        assert {0xd456,0xb838,0xe01e,0xe0cb,0xe214,0x913d,0x7331,0xe260,0xcfb1,0xd259,0x0ba3,0x0ba8,0x0bad,0x0bb2,0x0bb7,0x0bbc}<=visited
        assert {0,1,3}<=modes,modes
        print(f'PASS: 3200 persistent original normal scheduler loops (complete 29-stage task chain); modes {sorted(modes)}',flush=True)
if __name__=='__main__':main()
