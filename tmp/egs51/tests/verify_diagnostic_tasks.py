#!/usr/bin/env python3
"""Bank0 diagnostic/status tasks against original, unhooked ROM instructions."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, base, state, word, check_memory

ROUTINES=[('diagnostic_latches',0xe01e),('diagnostic_scan',0xe0cb),
          ('input_fault_summary',0xe214),('range_speed_latches',0x913d),
          ('status_compose',0xd259),('usage_counters',0xe260)]
IMS=[*range(0x20,0x30),*range(0x80,0xc0)]
def main():
    rng=random.Random(0xe01e)
    with tempfile.TemporaryDirectory(prefix='egs51-diagnostics-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));visited=set()
        for name,entry in ROUTINES:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(State)];fn.restype=None
            for j in range(12000):
                cpu=base(0);cpu.x[:]=rng.randbytes(1024)
                for a in IMS:cpu.im[a]=rng.randrange(256)
                cpu.im[0xb6]=rng.choice([0,0,1,255]);cpu.x[0x34b]=rng.choice([0,1,255])
                cpu.x[0x334]=rng.choice([1,5,6,7,8]);cpu.x[0x1cb]&=rng.choice([0,254,255])
                word(cpu.x,0x275,rng.choice([0,449,450,451,65535]))
                threshold=int.from_bytes(ROM[0xff80:0xff82],'big')
                word(cpu.x,0x2ac,rng.choice([threshold-1,threshold,threshold+1,65535]))
                threshold=int.from_bytes(ROM[rng.choice([0xfc3c,0xfc3e,0xfc84,0xfc86]):][:2],'big')
                word(cpu.x,0x2ef,rng.choice([threshold-1,threshold,threshold+1,65535]))
                for a,cal in ((0x2e8,0xff37),(0x2fb,0xff38),(0x120,0xff39)):
                    cpu.x[a]=rng.choice([(ROM[cal]-1)&255,ROM[cal],(ROM[cal]+1)&255,255])
                if name=='usage_counters':
                    word(cpu.x,0x27e,rng.choice([0,0,1,65535]))
                    word(cpu.x,0x381,rng.choice([0,0,1,65535]))
                    cpu.x[0x218]=rng.choice([0,1,2,4,8,16,255])
                    cpu.x[0x297]=rng.choice([0,ROM[0xff55]-1,255])
                    value=rng.choice([0,0xfffffe,0xffffff,0x1000000,0xffffffff])
                    cpu.x[0x119:0x11d]=value.to_bytes(4,'big')
                native=state(cpu);cpu.run(entry);fn(c.byref(native));visited.update(cpu.visited)
                try:check_memory(cpu,native,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 12000 complete {name} ROM comparisons',flush=True)
        cpu=base(0);native=state(cpu);reports=set()
        for tick in range(1600):
            for a,v in ((0x78,[0,1,0x11,0x21,0x31][(tick//64)%5]),
                        (0x73,(tick//17)%256),(0x1cb,(tick//31)%256),
                        (0x334,[3,7,8][(tick//32)%3])):
                cpu.x[a]=native.x[a]=v
            for st in (cpu,native):
                word(st.x,0x275,449 if tick%100<50 else 450)
                word(st.x,0x2ef,(tick%200)*10)
            for name,entry in ROUTINES:
                cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native))
                check_memory(cpu,native,IMS,range(1024));visited.update(cpu.visited)
            reports.add(native.x[0x21e]&31)
        assert set(range(1,17))<=reports,reports
        required={0xe02e,0xe045,0xe052,0xe069,0xe076,0xe08e,0xe09b,0xe0c2,0xe0c8,
                  0xe11b,0xe123,0xe1b0,0xe1ec,0xe201,0xe210,
                  0x9186,0x919b,0x91a4,0x91c0,0x91ee,0x9201,
                  0xe27e,0xe2d9,0xe2f5,0xe2fd,0xe323,0xe333,0xe3b2,0xe3c9,
                  0xe415,0xe428,0xe44e,0xe482}
        assert required<=visited,('missing branches',sorted(required-visited))
        # This ROM has no descriptor 128..135: E1D1 cannot be reached with its table.
        print('PASS: 9600 persistent diagnostic/status calls, all 16 report slots and selected latch branches',flush=True)
if __name__=='__main__':main()
