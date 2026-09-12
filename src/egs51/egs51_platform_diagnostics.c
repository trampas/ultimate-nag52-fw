/* Bank0 platform fault qualification, independent of normal shift scheduling. */
#include "egs51_internal.h"
static int masked_fault(Egs51 *s,unsigned mask) {
    for(unsigned k=0;k<8;k++) if(X(0x6d+k)&B(mask+k)) return 1;
    return 0;
}
static void capture_fault(Egs51 *s,unsigned code) { /* 5194 */
    if((X(0x71)&8) && (code==0x23 || code==0x24 || (code>=0x26 && code<=0x29))) return;
    if(code==0x15 || code==0x12 || code==0x41) return;
    X(0xae)=code; X(0xaf)=X(0xb2); X(0xb0)=I(0x80); X(0xb1)=X(0x92);
}
static int stopped_fault(Egs51 *s) { /* 5436 */
    I(0x2e)&=0xbf;
    int moving=IW(0x81) || IW(0x87);
    if(I(0x2e)&0x20) {
        if((X(0xdf)&0x20) && (I(0x2c)&0x20) && !moving) I(0x2e)|=0x40;
    } else if((X(0x71)&0x20) || !(I(0x26)&0x20)) I(0x2c)&=0xf7;
    else {
        if(!(I(0x2c)&8)) I(0x2c)|=0x28;
        if(moving) I(0x2c)&=0xdf;
    }
    return !!(I(0x2e)&0x40);
}
static void save_faults(Egs51 *s,unsigned flags) { /* 507A */
    if(flags&1) return;
    for(unsigned k=0;k<8;k++) X(0xdb+k)=X(0x6d+k);
    if(X(0xdf)&8) X(0xdf)&=9;
    for(unsigned k=0;k<4;k++) X(0xe3+k)=X(0xae + k);
    for(unsigned k=0;k<8;k++) X(0xe7+k)|=X(0xdb+k);
    X(0xe9)&=0xf6; X(0xee)&=0x7f; I(0x2e)|=0x20;
    if(!stopped_fault(s)) { X(0x79)|=1; I(0x2d)&=0xfd; I(0x2c)&=0x7f; }
}
static void fault_count(Egs51 *s,unsigned flags) { /* 5129 */
    if(flags&0x20) return;
    unsigned count=X(0x19c);
    if(masked_fault(s,0x3052)) {
        if((X(0x78)&0x20) && !(I(0x2c)&4) && count<B(0xff48)) {
            count++; I(0x2c)|=4; if((I(0x2c)&2) && count<B(0xff48)) count++;
        }
    } else if((X(0x78)&0x10) && !(I(0x2c)&2) && count) { count--; I(0x2c)|=2; }
    if(count!=X(0x19c)) { X(0x19c)=count; X(0x79)|=0x20; }
}
void egs51_platform_diagnostics(Egs51 *s) { /* 4D40..5079 */
    S(0x98)=0x7f; unsigned initial_flags=X(0x79);
    for(unsigned group=0;group<8;group++) {
        unsigned raw=I(0x22+group),latched=X(0x6d+group),active=I(8+group);
        if(!(raw|latched|active)) continue;
        for(unsigned bit=0;bit<8;bit++) {
            unsigned mask=1u<<bit,desc=0x3072+5u*(group*8+bit);
            unsigned now=raw&1,old=latched&1,pending=active&1;
            raw>>=1; latched>>=1; active>>=1;
            flag(&I(0x2e),4,now); flag(&I(0x2e),8,old); flag(&I(0x2e),0x10,pending);
            unsigned timer=0xb3+B(desc+3),counter=0xa7+B(desc+4);
            if(old) {
                if(B(desc+1)) {
                    if(pending) {
                        if(now) X(counter)++;
                        if(X(counter)>B(desc+2)) I(8+group)&=(uint8_t)~mask;
                        else if(!X(timer)) {
                            I(8+group)&=(uint8_t)~mask;
                            if(!(I(0x2d)&1)) { X(0x6d+group)&=(uint8_t)~mask; I(0x2d)|=2; }
                        }
                    } else if(!now) { X(timer)=B(desc+1); X(counter)=0; I(8+group)|=mask; }
                }
            } else if(now) {
                if(!pending) { X(timer)=B(desc); I(8+group)|=mask; }
                if(!X(timer)) {
                    X(0x6d+group)|=mask; I(8+group)&=(uint8_t)~mask;
                    capture_fault(s,group*8+bit+2); I(0x2c)|=0x80;
                }
            } else if(pending) { X(timer)=0; I(8+group)&=(uint8_t)~mask; }
            X(0xa7)=0;
            if(!(raw|latched|active)) break;
        }
    }
    I(0x2e)&=0xdf; stopped_fault(s);
    if((I(0x2c)&0x80) || (I(0x2d)&2)) {
        save_faults(s,initial_flags); X(0x78)&=0xfe;
        for(unsigned k=0;k<8;k++) if(X(0x6d+k)) { X(0x78)|=1; break; }
    }
    if(X(0x1a3)) { I(0xa)&=15; I(0xb)=0; I(0xc)&=1; }
    if(masked_fault(s,0x305a)) {
        S(0xe8)&=0xfe; X(0x78)|=2; if(X(0x1b7)!=2) X(0x1b7)=0;
    } else if(masked_fault(s,0x306a) || (X(0x78)&4)) { S(0xe8)&=0xfe; X(0x78)|=2; }
    else if((X(0x78)&2) && X(0x1b7)) {
        /* 6DCB(0) pulses P0.0 and re-enables HIFLG.0, preserving C9. */
        S(0xe8)|=1; S(0x80)|=1; X(0x78)&=0xfd;
    }
    fault_count(s,initial_flags); flag(&I(0x2d),1,initial_flags&1);
}
