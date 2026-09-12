#!/usr/bin/env python3
"""CAN receive parity using inferred descending hardware object-window reads."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, state, word, check_memory
from mcs51 import CPU
class CanCPU(CPU):
    def __init__(self):
        super().__init__(ROM,0)
        self.can=bytearray(256);self.cursor=0
    def direct(self,a):
        if a==0xb9:
            v=self.can[self.cursor]
            if self.sfr[0x38]&128:self.cursor=(self.cursor-1)&255
            return v
        return super().direct(a)
    def put(self,a,v):
        if a==0xba:self.cursor=v&255
        if a==0xb9:self.can[self.cursor]=v&255
        super().put(a,v)
class Rx(c.Structure):
    _fields_=[('registers',c.c_uint8*256)]
def main():
    rng=random.Random(0x47a0)
    with tempfile.TemporaryDirectory(prefix='egs51-can-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
            *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_can_receive;fn.argtypes=[c.POINTER(State),c.POINTER(Rx)]
        for j in range(20000):
            cpu=CanCPU();cpu.x[:]=rng.randbytes(1024);cpu.can[:]=rng.randbytes(256)
            for a in range(0x20,0x30):cpu.im[a]=rng.randrange(256)
            cpu.x[0x183]=rng.choice([0,1,2,3,4,255]);cpu.x[0x184]=rng.choice([0,2,3,255])
            word(cpu.x,0xa3,rng.randrange(1,65536))
            if j%3==0:
                for a in [0xde,0xda,0xd9,0xa6,0xa5,0xa4,0xa3,0xa8,0xb5,0xb4,0xb3,0xb2,0x87,0x86,0x85,0x84,0x9a,0x99]:cpu.can[a]=255
            native=state(cpu);rx=Rx();rx.registers[:]=cpu.can
            cpu.run(0x47a0);fn(c.byref(native),c.byref(rx))
            try:
                check_memory(cpu,native,[*range(0x20,0x30),*range(0x80,0x9b)],range(1024))
                assert bytes(rx.registers)==cpu.can, 'CAN pending acknowledgements'
            except AssertionError as e:raise AssertionError((j,str(e))) from e
        print('PASS: 20000 CAN receive comparisons, including invalid and absent objects')
if __name__=='__main__':main()
