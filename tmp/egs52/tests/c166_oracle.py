"""Small independent raw-instruction C166 oracle for the arithmetic tests.

This is not a whole-CPU emulator. No function is replaced by a Python arithmetic
shortcut. Unsupported opcodes, divide overflow/zero and step limits fail closed.
Instruction encodings: Infineon C166 Instruction Set Manual v2.0 (2001).
"""
class C166:
    def __init__(self, rom):
        self.rom = rom
        self.r = [0]*16
        self.r[0] = 0xf800
        self.mem = bytearray(65536)
        self.c = self.z = self.n = self.v = False
        self.seen = set()
        self.far_mem = {}
        self.ext_segment = None
        # Hardware SP is separate from the compiler's R0 stack. Install a
        # synthetic outer far return; CALLS/PUSH/RETS use the real RAM stack.
        self.wr(0xfe12,0xf740)
        self.wr(0xf740,0xffff);self.wr(0xf742,0xff)
        self.return_sentinel=0xffffff

    def rd(self, a, width=16):
        a &= 65535
        if a in (0xff1c,0xff1e):return 0 if a==0xff1c else (1<<width)-1
        if a >= 0xffe0 and width == 16:
            return self.r[(a-0xffe0)//2]
        return self.mem[a] if width == 8 else self.mem[a] | self.mem[(a+1)&65535]<<8

    def wr(self, a, value, width=16):
        a &= 65535
        if a >= 0xffe0 and width == 16:
            self.r[(a-0xffe0)//2] = value & 65535
        else:
            self.mem[a] = value & 255
            if width == 16: self.mem[(a+1)&65535] = value>>8 & 255

    def reg(self, n, width=16):
        return self.r[n] if width==16 else self.r[n//2] >> (n%2*8) & 255

    def setreg(self, n, v, width=16):
        if width==16:self.r[n]=v&65535
        else:
            k=n//2;shift=n%2*8
            self.r[k]=(self.r[k]&~(255<<shift)) | (v&255)<<shift

    def short(self, n, width=16):
        return self.reg(n-0xf0,width) if n>=0xf0 else self.rd(0xfe00+n*2,width)

    def setshort(self, n, v, width=16):
        if n>=0xf0:self.setreg(n-0xf0,v,width)
        else:self.wr(0xfe00+n*2,v,width)

    def flags(self, x, width=16):
        self.z = (x & ((1<<width)-1)) == 0
        self.n = bool(x & (1<<(width-1)))

    def alu(self, op, a, b, width=16):
        mask=(1<<width)-1; sign=1<<(width-1)
        if op in ('add','addc'):
            carry=int(self.c) if op=='addc' else 0
            x=a+b+carry
            self.c=x>mask; self.v=bool((~(a^b)&(a^x))&sign)
        elif op in ('sub','subc','cmp'):
            carry=int(self.c) if op=='subc' else 0
            x=a-b-carry
            self.c=x<0;self.v=bool(((a^b)&(a^x))&sign)
        elif op=='or':x=a|b;self.c=self.v=False
        elif op=='and':x=a&b;self.c=self.v=False
        elif op=='xor':x=a^b;self.c=self.v=False
        else:raise AssertionError(op)
        old_z=self.z
        self.flags(x,width)
        if op in ('addc','subc'):self.z=self.z and old_z
        return x&mask

    def cond(self, cc):
        assert cc != 1, "NET condition requires an unimplemented end-of-table flag"
        return [True,False,self.z,not self.z,self.v,not self.v,self.n,not self.n,
                self.c,not self.c,not self.z and self.n==self.v,self.z or self.n!=self.v,
                self.n!=self.v,self.n==self.v,not self.c and not self.z,self.c or self.z][cc]

    @staticmethod
    def signed(x, width=16):return x-(1<<width) if x&(1<<(width-1)) else x

    def run(self, entry, limit=100000):
        pc=entry
        for _ in range(limit):
            self.seen.add(pc)
            off=pc-0x80000
            assert 0<=off<len(self.rom)-3 and pc%2==0,hex(pc)
            op,q,b2,b3=self.rom[off:off+4];imm=b2|b3<<8
            hi=q>>4;lo=q&15;nextpc=pc+2
            segment=self.ext_segment;self.ext_segment=None
            if segment is not None:
                assert op in (0xa8,0xa9), 'Unsupported instruction under EXTS'
            if op==0xdb:
                sp=self.rd(0xfe12)
                target=self.rd(sp)|((self.rd(sp+2)&255)<<16)
                self.wr(0xfe12,sp+4)
                if target==self.return_sentinel:return self.r[4]
                pc=target;continue
            if op==0xda:
                sp=(self.rd(0xfe12)-4)&65535
                self.wr(sp,(pc+4)&65535);self.wr(sp+2,pc>>16)
                self.wr(0xfe12,sp);pc=q<<16|imm;continue
            if op==0xec:
                value=self.short(q);sp=(self.rd(0xfe12)-2)&65535
                self.wr(sp,value);self.wr(0xfe12,sp)
            elif op==0xfc:
                sp=self.rd(0xfe12);value=self.rd(sp)
                self.wr(0xfe12,sp+2);self.setshort(q,value)
            elif op&15==13:
                if self.cond(op>>4):nextpc += 2*self.signed(q,8)
            elif op==0xdc:
                assert hi==0, 'Only one-instruction EXTS is implemented'
                self.ext_segment=self.r[lo]&255
            elif op in (0x8a,0x9a):
                assert q>=0xf0 and b3&15==0, 'Only register JB/JNB is implemented'
                nextpc=pc+4
                bit=bool(self.r[q-0xf0]>>(b3>>4)&1)
                if bit==(op==0x8a):nextpc+=2*self.signed(b2,8)
            elif op in (0xf0,0xf1):
                width=16 if op==0xf0 else 8
                x=self.reg(lo,width);self.setreg(hi,x,width);self.flags(x,width)
            elif op in (0xe0,0xe1):
                width=16 if op==0xe0 else 8
                self.setreg(lo,hi,width);self.flags(hi,width)
            elif op in (0xe6,0xe7):
                width=16 if op==0xe6 else 8
                self.setshort(q,imm,width);self.flags(imm,width);nextpc+=2
            elif op in (0xf2,0xf3):
                width=16 if op==0xf2 else 8
                x=self.rd(imm,width);self.setshort(q,x,width);self.flags(x,width);nextpc+=2
            elif op in (0xf6,0xf7):
                width=16 if op==0xf6 else 8
                x=self.short(q,width);self.wr(imm,x,width);self.flags(x,width);nextpc+=2
            elif op==0xea:
                nextpc=pc+4
                if self.cond(hi):nextpc=(pc&0xff0000)|imm
            elif op==0x84:
                assert hi==0
                x=self.rd(imm);self.wr(self.r[lo],x);self.flags(x);nextpc+=2
            elif op in (0xe8,0xe9):
                width=16 if op==0xe8 else 8
                x=self.rd(self.r[lo],width)
                self.wr(self.r[hi],x,width);self.r[lo]=(self.r[lo]+width//8)&65535
                self.flags(x,width)
            elif op==0xa0:
                old=self.r[lo];self.alu('cmp',old,hi);self.r[lo]=(old-1)&65535
            elif op in (0xc8,0xc9):
                width=16 if op==0xc8 else 8
                x=self.rd(self.r[lo],width);self.wr(self.r[hi],x,width);self.flags(x,width)
            elif op==0x4a:
                assert q>=0xf0 and b2>=0xf0
                src=self.r[q-0xf0]>>(b3>>4)&1
                dst=b2-0xf0;bit=b3&15
                self.r[dst]=(self.r[dst]&~(1<<bit)) | src<<bit
                nextpc+=2
            elif op==0xc2:
                x=self.rd(imm,8);self.setshort(q,x);self.flags(x);nextpc+=2
            elif op==0xc0:
                self.r[lo]=self.reg(hi,8);self.flags(self.r[lo])
            elif op in (0xa8,0xa9):
                width=16 if op==0xa8 else 8
                if segment is None:x=self.rd(self.r[lo],width)
                else:
                    addr=(segment<<16)|self.r[lo]
                    x=self.far_mem[addr]
                    if width==16:x|=self.far_mem[(addr+1)&0xffffff]<<8
                self.setreg(hi,x,width);self.flags(x,width)
            elif op in (0xb8,0xb9):
                width=16 if op==0xb8 else 8
                x=self.reg(hi,width);self.wr(self.r[lo],x,width);self.flags(x,width)
            elif op in (0x88,0x89):
                width=16 if op==0x88 else 8
                self.r[lo]=(self.r[lo]-width//8)&65535
                self.wr(self.r[lo],self.reg(hi,width),width)
            elif op in (0x98,0x99):
                width=16 if op==0x98 else 8
                x=self.rd(self.r[lo],width);self.r[lo]=(self.r[lo]+width//8)&65535
                self.setreg(hi,x,width)
            elif op in (0xc4,0xe4):
                width=16 if op==0xc4 else 8
                x=self.reg(hi,width);self.wr(self.r[lo]+imm,x,width);self.flags(x,width);nextpc+=2
            elif op in (0xd4,0xf4):
                width=16 if op==0xd4 else 8
                x=self.rd(self.r[lo]+imm,width);self.setreg(hi,x,width);self.flags(x,width);nextpc+=2
            elif op in (0x4c,0x6c,0xac,0x5c,0x7c,0xbc,0x0c,0x1c,0x2c,0x3c):
                variable=op in (0x4c,0x6c,0xac,0x0c,0x2c)
                dest=hi if variable else lo;count=(self.r[lo]&15) if variable else hi
                a=self.r[dest];self.c=False;self.v=False
                if op in (0x4c,0x5c,0x0c,0x1c):
                    x=a<<count
                    if count:self.c=bool(a&(1<<(16-count)))
                    if op in (0x0c,0x1c):x|=a>>(16-count)
                else:
                    x=self.signed(a)>>count if op in (0xac,0xbc) else a>>count
                    if count:self.c=bool(a&(1<<(count-1)))
                    if op in (0x2c,0x3c):x|=a<<(16-count)
                    elif count>1:self.v=bool(a&((1<<(count-1))-1))
                self.r[dest]=x&65535;self.flags(x)
            elif op in (0x0b,0x1b):
                a,b=self.r[hi],self.r[lo]
                if op==0x0b:a,b=self.signed(a),self.signed(b)
                x=a*b&0xffffffff;self.wr(0xfe0c,x>>16);self.wr(0xfe0e,x)
            elif op in (0x5b,0x6b,0x7b):
                divisor=self.r[hi];assert hi==lo
                dividend=self.rd(0xfe0e)
                if op!=0x5b:dividend |= self.rd(0xfe0c)<<16
                if op==0x6b:dividend=self.signed(dividend,32);divisor=self.signed(divisor)
                assert divisor!=0,('divide zero',hex(pc))
                quot=abs(dividend)//abs(divisor)
                if (dividend<0)!=(divisor<0):quot=-quot
                assert (-32768<=quot<=32767 if op==0x6b else 0<=quot<=65535),('divide overflow',hex(pc))
                self.wr(0xfe0e,quot);self.wr(0xfe0c,dividend-quot*divisor)
            elif op==0x75:
                self.wr(imm,self.alu('or',self.rd(imm,8),self.short(q,8),8),8);nextpc+=2
            elif op==0x43:
                self.alu('cmp',self.short(q,8),self.rd(imm,8),8);nextpc+=2
            elif op==0x81 and lo==0:
                x=self.alu('sub',0,self.r[hi]);self.r[hi]=x
            elif op in (0x02,0x12,0x22,0x32,0x42,0x52,0x62,0x72,
                         0x01,0x11,0x21,0x31,0x41,0x51,0x61,0x71,
                         0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,
                         0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78,
                         0x09,0x19,0x29,0x39,0x49,0x59,0x69,0x79,
                         0x06,0x16,0x26,0x36,0x46,0x56,0x66,0x76,0x47,0x27):
                name={0:'add',1:'addc',2:'sub',3:'subc',4:'cmp',5:'xor',6:'and',7:'or'}[op>>4]
                width=8 if op&15 in (1,7,9) else 16
                if op&15 in (2,6,7):
                    a=self.short(q,width);b=(imm&((1<<width)-1)) if op&15 in (6,7) else self.rd(imm);dest=q-0xf0;nextpc+=2
                else:
                    dest=hi;a=self.reg(dest,width)
                    if op&15 in (0,1):b=self.reg(lo,width)
                    elif lo<8:b=lo
                    else:
                        reg=lo&3;b=self.rd(self.r[reg],width)
                        if lo&4:self.r[reg]=(self.r[reg]+width//8)&65535
                x=self.alu(name,a,b,width)
                if name!='cmp':self.setreg(dest,x,width)
            else:raise AssertionError(f'unsupported opcode at {pc:06x}: {op:02x} {q:02x}')
            pc=nextpc
        raise AssertionError('instruction limit')
