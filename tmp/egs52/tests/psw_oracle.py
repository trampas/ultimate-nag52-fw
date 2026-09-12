"""Instruction oracle for explicit PSW effects; no function-level shortcuts.

C166 manual p35 overrides ordinary flags when PSW is the destination.
Only the opcodes reached by the tested PSW helpers are accepted. Scheduling,
interrupt arrival and instruction timing are outside this sequential model.
"""
class PswOracle:
    def __init__(self,rom,psw):
        self.rom=rom;self.psw=psw;self.r=[0]*16;self.r[0]=0xf800
        self.stack={};self.mem={};self.seen=set();self.atomic=[]
    def moved(self,x,width):
        x &= (1<<width)-1
        self.psw=(self.psw&~0x19) | int(bool(x&(1<<(width-1)))) | (8 if x==0 else 0) | (16 if x==0x8000 else 0)
    def logical(self,x):
        self.psw=(self.psw&0xffe0) | int(bool(x&0x8000)) | (8 if x==0 else 0)
    def run(self,entry):
        pc=entry
        for _ in range(100):
            self.seen.add(pc)
            op,q,a,b=self.rom[pc-0x80000:pc-0x80000+4];imm=a|(b<<8);hi=q>>4;lo=q&15
            pc+=2
            if op==0xdb:return self.r[4]
            if op==0xd1:
                assert q==0x20;self.atomic.append(3)
            elif op==0xcc:assert q==0
            elif op in (0xbe,0xbf):
                assert q==0x88
                self.psw=(self.psw&~0x800) if op==0xbe else self.psw|0x800
            elif op==0xf2:
                assert imm==0xff10 and q>=0xf0
                value=self.psw;self.r[q-0xf0]=value;self.moved(value,16);pc+=2
            elif op==0xf6:
                assert imm==0xff10 and q>=0xf0
                self.psw=self.r[q-0xf0];pc+=2
            elif op==0xf0:
                self.r[hi]=self.r[lo];self.moved(self.r[hi],16)
            elif op==0xf1:
                value=(self.r[lo//2]>>(8*(lo%2)))&255
                self.r[hi//2]=(self.r[hi//2]&~(255<<(8*(hi%2)))) | value<<(8*(hi%2))
                self.moved(value,8)
            elif op==0xe1:
                self.r[lo//2]=(self.r[lo//2]&~(255<<(8*(lo%2)))) | hi<<(8*(lo%2))
                self.moved(hi,8)
            elif op==0x66:
                assert q>=0xf0
                self.r[q-0xf0]&=imm;self.logical(self.r[q-0xf0]);pc+=2
            elif op==0x70:
                self.r[hi]|=self.r[lo];self.logical(self.r[hi])
            elif op==0x88:
                assert lo==0
                value=self.r[hi];self.r[0]=(self.r[0]-2)&65535;self.stack[self.r[0]]=value;self.moved(value,16)
            elif op==0x98:
                assert lo==0
                self.r[hi]=self.stack[self.r[0]];self.r[0]=(self.r[0]+2)&65535;self.moved(self.r[hi],16)
            elif op==0x3a:
                assert q==1 and a==0x88 and b==6
                value=(self.mem[0xfd02]&1)^1
                self.psw=(self.psw&~0x40) | value<<6;pc+=2
            elif op==0x4a:
                assert q==0x88 and a>=0xf0
                src=(self.psw>>(b>>4))&1;dest=a-0xf0;bit=b&15;old=(self.r[dest]>>bit)&1
                self.psw=(self.psw&0xffe0) | old | (0 if old else 8)
                self.r[dest]=(self.r[dest]&~(1<<bit)) | src<<bit;pc+=2
            else:raise AssertionError((hex(pc-2),hex(op)))
        raise AssertionError('PSW helper step limit')
