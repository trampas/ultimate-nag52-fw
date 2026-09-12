"""Small fail-closed ROM instruction oracle, not a complete MCU emulator.

Executes raw 8051 bytes, with separate direct SFR and indirect upper RAM.
Models the inferred MDU write protocol, TCON bank selection, hardware stack,
external ADC page inputs and immediate SPI responses/compare-write events.
Interrupt entries execute as standalone calls; no concurrent interrupts,
peripheral latency or undocumented divide-by-zero behavior is modeled.
"""
class CPU:
    def __init__(self, rom, bank=1):
        self.rom=rom; self.bank=bank
        self.code=rom[bank*65536:(bank+1)*65536]
        self.im=bytearray(256); self.x=bytearray(1024); self.sfr=bytearray(128)
        self.pc=0; self.mdu_writes=[]; self.visited=set()
        self.sfr[0x81-128]=0xc0; self.sfr[0x88-128]=bank<<4
        self.input_pages=None; self.spi_rx=[]; self.spi_tx=[]; self.events=[]
    def direct(self,a):
        if a==0x92 and self.input_pages is not None: return self.input_pages[self.sfr[0x91-128]]
        return self.im[a] if a<128 else self.sfr[a-128]
    def put(self,a,v):
        v &= 255
        if a<128: self.im[a]=v
        else: self.sfr[a-128]=v
        if a in (0xa5,0xa6,0xa7,0xad,0xae,0xaf): self.mdu_writes.append(a)
        if a==0x88:
            self.bank=(v>>4)&1; self.code=self.rom[self.bank*65536:(self.bank+1)*65536]
        if a==0xc7 and v&128 and self.spi_rx:
            self.spi_tx.append(self.sfr[0xc6-128])
            self.sfr[0xc6-128]=self.spi_rx.pop(0); self.sfr[a-128]=v&127
        if a==0xdd: self.events.append((self.direct(0xf4)*256+self.direct(0xf3),v))
    @property
    def a(self): return self.direct(0xe0)
    @a.setter
    def a(self,v):
        self.put(0xe0,v)
        self.put(0xd0,(self.direct(0xd0)&254)|((v&255).bit_count()&1))
    @property
    def cy(self): return self.direct(0xd0)>>7
    @cy.setter
    def cy(self,v): self.put(0xd0,(self.direct(0xd0)&127)|(bool(v)<<7))
    @property
    def dp(self): return self.direct(0x83)*256+self.direct(0x82)
    @dp.setter
    def dp(self,v): self.put(0x82,v); self.put(0x83,v>>8)
    def ri(self,n): return (self.direct(0xd0)&0x18)+n
    def r(self,n): return self.im[self.ri(n)]
    def wr(self,n,v): self.im[self.ri(n)]=v&255
    def bit(self,b): return (self.direct(b&0xf8) if b>=128 else self.im[32+b//8])>>(b&7)&1
    def wb(self,b,v):
        a=(b&0xf8) if b>=128 else 32+b//8
        self.put(a,(self.direct(a)&~(1<<(b&7)))|((v&1)<<(b&7)))
    def byte(self):
        v=self.code[self.pc]; self.pc=(self.pc+1)&65535; return v
    def rel(self):
        v=self.byte(); return v if v<128 else v-256
    def mdu(self,target):
        regs=(0xa5,0xa6,0xa7,0xad,0xae,0xaf)
        if self.mdu_writes[-4:]==[0xa5,0xae,0xa6,0xaf]:
            assert self.mdu_writes[-4:]==[0xa5,0xae,0xa6,0xaf], self.mdu_writes
            a=self.direct(0xa5)+256*self.direct(0xa6)
            b=self.direct(0xae)+256*self.direct(0xaf)
            p=a*b
            for k,r in enumerate(regs[:4]): self.put(r,p>>(8*k))
        else:
            seq=self.mdu_writes
            width=4 if seq[-6:]==list(regs) else 2
            assert width==4 or seq[-4:]==[0xa5,0xa6,0xae,0xaf],seq
            a=sum(self.direct(r)<<(8*k) for k,r in enumerate(regs[:width]))
            b=self.direct(0xae)+256*self.direct(0xaf)
            assert b, 'MDU division by zero: no assumed hardware result'
            q=a//b
            for k,r in enumerate(regs[:4] if width==4 else regs[:2]): self.put(r,q>>(8*k))
            remainder=a%b
            self.put(0xae,remainder); self.put(0xaf,remainder>>8)
        self.mdu_writes=[]
    def push(self,v):
        sp=(self.direct(0x81)+1)&255; self.put(0x81,sp); self.im[sp]=v&255
    def pop(self):
        sp=self.direct(0x81); v=self.im[sp]; self.put(0x81,sp-1); return v
    def run(self,entry,limit=50000,stop=None,stop_bank=None):
        self.pc=entry; start_sp=self.direct(0x81); self.mdu_writes=[]
        for _ in range(limit):
            pc=self.pc
            if pc==stop and (stop_bank is None or self.bank==stop_bank): return
            self.visited.add(pc); op=self.byte()
            if op==0x00: pass
            elif op in (0x22,0x32):
                if self.direct(0x81)==start_sp: return
                self.pc=self.pop()*256+self.pop()
            elif op==0xc0: self.push(self.direct(self.byte()))
            elif op==0xd0: self.put(self.byte(),self.pop())
            elif op&0x1f in (1,0x11):
                low=self.byte(); target=(self.pc&0xf800)|((op&0xe0)<<3)|low
                if op&0x1f==0x11: self.push(self.pc); self.push(self.pc>>8)
                self.pc=target
            elif op in (0x02,0x12):
                target=self.byte()*256+self.byte()
                if op==0x12 and target in (0x1dca,0x1dcb): self.mdu(target)
                else:
                    if op==0x12: self.push(self.pc); self.push(self.pc>>8)
                    self.pc=target
            elif op==0x73: self.pc=(self.dp+self.a)&65535
            elif op in (0x80,0x40,0x50,0x60,0x70):
                off=self.rel()
                if {0x80:True,0x40:self.cy==1,0x50:self.cy==0,0x60:self.a==0,0x70:self.a!=0}[op]: self.pc=(self.pc+off)&65535
            elif op in (0x20,0x30,0x10):
                b=self.byte(); off=self.rel(); v=self.bit(b)
                if v==(op!=0x30):
                    if op==0x10: self.wb(b,0)
                    self.pc=(self.pc+off)&65535
            elif op==0x90: self.dp=self.byte()*256+self.byte()
            elif op==0xa3: self.dp=(self.dp+1)&65535
            elif op==0x93: self.a=self.code[(self.dp+self.a)&65535]
            elif op==0x83: self.a=self.code[(self.pc+self.a)&65535]
            elif op==0xe0: self.a=self.x[self.dp]
            elif op==0xf0: self.x[self.dp]=self.a
            elif op==0x74: self.a=self.byte()
            elif op==0x75:
                a=self.byte(); self.put(a,self.byte())
            elif op==0x85:
                a=self.byte(); b=self.byte(); self.put(b,self.direct(a))
            elif op==0xe5: self.a=self.direct(self.byte())
            elif op==0xf5: self.put(self.byte(),self.a)
            elif 0x78<=op<=0x7f: self.wr(op&7,self.byte())
            elif 0xe8<=op<=0xef: self.a=self.r(op&7)
            elif 0xf8<=op<=0xff: self.wr(op&7,self.a)
            elif 0xa8<=op<=0xaf: self.wr(op&7,self.direct(self.byte()))
            elif 0x88<=op<=0x8f: self.put(self.byte(),self.r(op&7))
            elif op in (0xe6,0xe7): self.a=self.im[self.r(op&1)]
            elif op in (0xf6,0xf7): self.im[self.r(op&1)]=self.a
            elif op in (0x76,0x77): self.im[self.r(op&1)]=self.byte()
            elif op in (0xa6,0xa7): self.im[self.r(op&1)]=self.direct(self.byte())
            elif op in (0x86,0x87): self.put(self.byte(),self.im[self.r(op&1)])
            elif op in (0xe4,0xf4): self.a=0 if op==0xe4 else self.a^255
            elif op in (0xc3,0xd3,0xb3): self.cy=0 if op==0xc3 else 1 if op==0xd3 else 1-self.cy
            elif op in (0xc2,0xd2,0xb2):
                b=self.byte(); self.wb(b,0 if op==0xc2 else 1 if op==0xd2 else 1-self.bit(b))
            elif op==0xa2: self.cy=self.bit(self.byte())
            elif op==0x92: self.wb(self.byte(),self.cy)
            elif op==0xc4: self.a=(self.a<<4)|(self.a>>4)
            elif op in (0x13,0x33):
                a=self.a; c=self.cy
                self.cy=(a&1) if op==0x13 else a>>7
                self.a=(a>>1)|(c<<7) if op==0x13 else (a<<1)|c
            elif op in (0x03,0x23): self.a=(self.a>>1)|(self.a<<7) if op==0x03 else (self.a<<1)|(self.a>>7)
            elif op in (0x04,0x14): self.a=self.a+(1 if op==4 else -1)
            elif op in (0x05,0x15):
                a=self.byte(); self.put(a,self.direct(a)+(1 if op==5 else -1))
            elif op in (0x06,0x07,0x16,0x17):
                a=self.r(op&1); self.im[a]=(self.im[a]+(1 if op<0x10 else -1))&255
            elif 0x08<=op<=0x0f or 0x18<=op<=0x1f: self.wr(op&7,self.r(op&7)+(1 if op<0x10 else -1))
            elif op in (0xc5,0xc6,0xc7) or 0xc8<=op<=0xcf:
                v=self.a
                if op==0xc5:
                    a=self.byte(); self.a=self.direct(a); self.put(a,v)
                elif op<0xc8:
                    a=self.r(op&1); self.a=self.im[a]; self.im[a]=v
                else: self.a=self.r(op&7); self.wr(op&7,v)
            elif op in (0xd6,0xd7):
                a=self.r(op&1); v=self.im[a]; self.im[a]=(v&240)|(self.a&15); self.a=(self.a&240)|(v&15)
            elif op==0xa4:
                p=self.a*self.direct(0xf0); self.a=p; self.put(0xf0,p>>8); self.cy=0; self.wb(0xd2,p>255)
            elif op in (0xb4,0xb5,0xb6,0xb7) or 0xb8<=op<=0xbf:
                if op==0xb4: a=self.a; b=self.byte()
                elif op==0xb5: a=self.a; b=self.direct(self.byte())
                elif op<0xb8: a=self.im[self.r(op&1)]; b=self.byte()
                else: a=self.r(op&7); b=self.byte()
                off=self.rel(); self.cy=a<b
                if a!=b: self.pc=(self.pc+off)&65535
            elif op==0xd5 or 0xd8<=op<=0xdf:
                if op==0xd5:
                    a=self.byte(); self.put(a,self.direct(a)-1); v=self.direct(a)
                else: self.wr(op&7,self.r(op&7)-1); v=self.r(op&7)
                off=self.rel()
                if v: self.pc=(self.pc+off)&65535
            elif op in (0x42,0x43,0x52,0x53,0x62,0x63):
                a=self.byte(); v=self.byte() if op&1 else self.a; old=self.direct(a)
                self.put(a,old|v if op<0x50 else old&v if op<0x60 else old^v)
            elif (0x24<=op<=0x2f or 0x34<=op<=0x3f or 0x44<=op<=0x4f or
                  0x54<=op<=0x5f or 0x64<=op<=0x6f or 0x94<=op<=0x9f):
                kind=op&0xf0; mode=op&15
                v=self.byte() if mode==4 else self.direct(self.byte()) if mode==5 else self.im[self.r(mode&1)] if mode<8 else self.r(mode&7)
                if kind in (0x20,0x30):
                    a=self.a; carry=self.cy if kind==0x30 else 0; p=a+v+carry
                    self.wb(0xd2, bool((~(a^v)&(a^p))&128)); self.wb(0xd6,(a&15)+(v&15)+carry>15)
                    self.cy=p>255; self.a=p
                elif kind==0x90:
                    a=self.a; carry=self.cy; p=a-v-carry
                    self.wb(0xd2,bool(((a^v)&(a^p))&128)); self.wb(0xd6,(a&15)<(v&15)+carry)
                    self.cy=p<0; self.a=p
                else: self.a=self.a|v if kind==0x40 else self.a&v if kind==0x50 else self.a^v
            else: raise AssertionError(f'unsupported opcode {op:02x} at {pc:04x}')
        raise AssertionError(f'instruction limit at {self.pc:04x}')
