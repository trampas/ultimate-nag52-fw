"""Execute boot IRQ bytes to the forwarding/reset boundary, recording word I/O.

No target routine is substituted. Execution stops on JMPS or SRST, the two
external control-transfer boundaries represented by the native callback API.
Watchdog/interrupt timing and hardware behavior after reset are not simulated.
"""
class BootIrqOracle:
    def __init__(self,rom,psw,dpp3,mdh,words):
        self.rom=rom;self.psw=psw;self.dpp3=dpp3;self.mdh=mdh
        self.words=dict(words);self.trace=[];self.seen=set()
    def state(self):return (self.psw,self.dpp3,self.mdh)
    def read(self,address):
        if address==0xff1e:return 65535
        value=self.words[address];self.trace.append(('read',address,value,self.state()));return value
    def write(self,address,value):
        self.words[address]=value;self.trace.append(('write',address,value,self.state()))
    def event(self,kind,target=0):self.trace.append(('event',kind,target,self.state()))
    def move_flags(self,value):
        self.psw=(self.psw&~0x19) | int(bool(value&0x8000)) | (8 if value==0 else 0) | (16 if value==0x8000 else 0)
    def run(self,entry):
        pc=entry
        for _ in range(2048):
            self.seen.add(pc);op,q,a,b=self.rom[pc-0x80000:pc-0x80000+4];imm=a|b<<8
            if op==0x9a:
                assert q==0x77 and b==0
                pc+=4
                if not self.read(0xfdee)&1:pc+=2*(a if a<128 else a-256)
            elif op in (0x0d,0x3d):
                pc+=2
                if op==0x0d or not self.psw&8:pc+=2*(q if q<128 else q-256)
            elif op==0xfa:
                self.event(0,q<<16|imm);return
            elif op==0xe6:
                if q==3:self.dpp3=imm
                elif q==6:self.mdh=imm
                else:
                    assert q==0xd7;self.write(0xffae,imm)
                self.move_flags(imm);pc+=4
            elif op==0xf2:
                assert q==6;self.mdh=self.read(imm);self.move_flags(self.mdh);pc+=4
            elif op==0xf6:
                assert q==6;self.write(imm,self.mdh);self.move_flags(self.mdh);pc+=4
            elif op==0x52:
                assert q==6 and imm==0xff1e
                self.mdh^=self.read(imm)
                self.psw=(self.psw&0xffe0) | int(bool(self.mdh&0x8000)) | (8 if self.mdh==0 else 0)
                pc+=4
            elif op==0x02:
                assert q==6 and imm==0xff1e
                lhs=self.mdh;rhs=self.read(imm);result=lhs+rhs;self.mdh=result&65535
                flags=int(bool(self.mdh&0x8000)) | (2 if result>65535 else 0) | (4 if (~(lhs^rhs)&(lhs^result)&0x8000) else 0) | (8 if self.mdh==0 else 0)
                self.psw=(self.psw&0xffe0)|flags;pc+=4
            elif (op,q,a,b)==(0xa7,0x58,0xa7,0xa7):self.event(1);pc+=4
            elif (op,q,a,b)==(0xb7,0x48,0xb7,0xb7):self.event(2);return
            else:raise AssertionError((hex(pc),hex(op)))
        raise AssertionError('Boot IRQ instruction limit')
