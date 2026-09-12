#!/usr/bin/env python3
"""Full TCC feedforward, direction and slip regulator versus raw ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, state, base, word, check_memory, U8, U16
rng=random.Random(0xae33)
def configured():
    cpu=base(); cpu.x[:]=rng.randbytes(1024)
    cpu.x[0x17b]=rng.randrange(3)*16+rng.randrange(2)
    cpu.x[0x17c]=rng.randrange(3)*16+rng.randrange(3)
    cpu.run(0x20bc); assert cpu.r(7)==0
    cpu.put(0x88,0); cpu.im[0xb9]=rng.randrange(3,6)
    n=rng.randrange(3)
    for cell,table in ((0x3b0,0xecb0),(0x3b8,0xec90)):
        word(cpu.x,cell,int.from_bytes(ROM[table+2*n:table+2*n+2],'big'))
    cpu.x[0x39e]=cpu.im[0xb9]*2-5; cpu.x[0x1e9]=cpu.im[0xb9]*2-6
    cpu.im[0x95]=rng.randrange(256)
    for a in range(0x44,0x58): cpu.im[a]=rng.randrange(256)
    cpu.im[0x56]=rng.randrange(5); cpu.im[0x57]=rng.randrange(4)
    return cpu
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-tcc-control-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        for name in ('tcc_target','tcc_feedforward','tcc_direction','tcc_slip_pi','tcc_regulate'):
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[ptr]; fn.restype=U8 if name=='tcc_target' else None
        lib.egs51_curve8.argtypes=[ptr,c.c_uint,U16,U8]; lib.egs51_curve8.restype=U8
        for j in range(3000):
            cpu=configured(); desc=cpu.code[0xedd4+2*cpu.im[0xb9]]*256+cpu.code[0xedd5+2*cpu.im[0xb9]]
            x=j%256; word(cpu.im,0xa5,0x8100+x); cpu.wr(6,desc>>8); cpu.wr(7,desc)
            s=state(cpu); cpu.run(0x1838)
            assert cpu.r(7)==lib.egs51_curve8(c.byref(s),0,desc,x)
        print('PASS: 3000 byte curves including every byte input')
        for name,entry,count in [('tcc_target',0xa7e6,3000),('tcc_feedforward',0xad0b,5000),
                                 ('tcc_direction',0xa472,5000),('tcc_slip_pi',0xab5b,5000),('tcc_regulate',0xae33,10000)]:
            visited=set()
            for j in range(count):
                cpu=configured(); s=state(cpu); before=bytes(cpu.im[0x44:0x58])
                cpu.run(entry); got=getattr(lib,'egs51_'+name)(c.byref(s)); visited.update(cpu.visited)
                try:
                    if name=='tcc_target': assert got==cpu.r(7),(got,cpu.r(7))
                    else: check_memory(cpu,s,range(0x44,0x58),range(1024))
                except AssertionError as exc: raise AssertionError(f'{name} case{j} {before.hex()}: {exc}') from exc
            print(f'PASS: {count} complete {name} calls; {len(visited)} instruction PCs including callees')
if __name__=='__main__': main()
