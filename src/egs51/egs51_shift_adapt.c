/* A0215451432 OEM shift adaptation observations. */
#include "egs51_internal.h"
static uint16_t sub(uint16_t a,uint16_t b) { return a>b?a-b:0; }
uint16_t egs51_adapt_speed_excursion(Egs51 *s) { /* A97E */
    uint16_t low=XW(0x34d),speed=XW(0x2bb);
    if(signed16(speed)<signed16(low)) low=speed;
    if(signed16(low)>signed16((uint16_t)(0-RW(XW(0x3ba)+0x17)))) low=0;
    XP(0x34d,low);
    uint16_t delta=(uint16_t)(speed-low);
    return signed16(delta)<0?(uint16_t)(0-delta):delta;
}
void egs51_adapt_fill_error(Egs51 *s,uint8_t elapsed) { /* A9F2 */
    uint16_t high=egs51_handoff_root_test(egs51_handoff_high_pressure(s,I(0xb6)));
    uint16_t low=egs51_handoff_root_test(egs51_handoff_low_pressure(s,I(0xb6)));
    uint16_t t=(uint16_t)(elapsed-egs51_fill_term(s)-R(XW(0x3c6)+0x22)-(R(XW(0x3c6)+0x23+I(0x56))>>1));
    t=egs51_signed_md(low,t,high);
    X(0x1e4)=!t?0:signed16(t)>=1?1:255;
}
void egs51_adapt_fill_observe(Egs51 *s) { /* AA98..AC64 */
    if(!(I(0x99)&4) || (I(0x99)&8)) return;
    if(!X(0x380)) { XP(0x34d,0); X(0x380)=255; X(0x1e4)=0; I(0x99)&=0xf7; }
    uint16_t cal=XW(0x3ba);
    if(egs51_adapt_speed_excursion(s)<=RW(cal+0x17)) return;
    uint16_t delta=R(cal+0x12);
    if(!((XW(0x22f)<(uint16_t)(XW(0x275)-delta) && (I(0x95)&8)) ||
         (XW(0x275)<(uint16_t)(XW(0x22f)-delta) && (I(0x95)&0x10)))) return;
    I(0x99)|=8;
    /* AB58..ABAA calculates a temporary capacity which is not used afterward. */
    (void)md(RW(XW(0x3c6)+0x18+2*I(0x56)),X(0x2ab),IW(0x52));
    X(0x380)=(uint8_t)(255-X(0x380));
    unsigned idx=(uint8_t)(I(0xac)-1);
    uint16_t bit=idx<16?(uint16_t)(1u<<idx):0;
    uint8_t offset=R(cal+((RW(cal+0x1e)&bit)?0x14:0x1a));
    X(0x380)=(uint8_t)sub(X(0x380),offset);
    if(X(0x380)<egs51_fill_term(s)) { X(0x1e4)=255; return; }
    if(X(0x380)<egs51_fill_term(s)+R(XW(0x3c6)+0x22)) { X(0x1e4)=255; return; }
    egs51_adapt_fill_error(s,X(0x380));
}
void egs51_adapt_transfer_observe(Egs51 *s) { /* AC65..ADF5 */
    if(!(I(0x99)&4) || (I(0x99)&8)) return;
    uint16_t excursion=egs51_adapt_speed_excursion(s);
    uint16_t capacity=md(RW(XW(0x3c6)+0x18+2*I(0x56)),X(0x2ab),IW(0x52));
    if(capacity<=IW(0xad)) { I(0x99)&=0xfb; return; }
    uint16_t cal=XW(0x3ba),delta=R(cal+0x12);
    if(excursion<=RW(cal+0x17) || !((XW(0x22f)<(uint16_t)(XW(0x275)-delta) && (I(0x95)&8)) ||
         (XW(0x275)<(uint16_t)(XW(0x22f)-delta) && (I(0x95)&0x10)))) return;
    I(0x99)|=8;
    X(0x380)=(uint8_t)(255-X(0x380));
    unsigned idx=(uint8_t)(I(0xac)-1);
    uint16_t bit=idx<16?(uint16_t)(1u<<idx):0;
    X(0x380)=(uint8_t)sub(X(0x380),R(cal+((RW(cal+0x1e)&bit)?0x14:0x1a)));
    egs51_adapt_fill_error(s,X(0x380));
}

void egs51_adapt_inertia_observe(Egs51 *s) { /* ADF6..AF11 */
    if(!(I(0x99)&4) || (I(0x99)&8)) return;
    uint16_t cal=XW(0x3ba);
    uint16_t capacity=md(RW(XW(0x3c6)+0x18+2*I(0x56)),X(0x2ab),IW(0x52));
    if(capacity<(uint16_t)(IW(0xad)+RW(cal+0x1c))) { I(0x99)&=0xfb; return; }
    I(0x99)|=8;
    X(0x380)=(uint8_t)(255-X(0x380));
    unsigned idx=(uint8_t)(I(0xac)-1);
    uint16_t bit=idx<16?(uint16_t)(1u<<idx):0;
    X(0x380)=(uint8_t)sub(X(0x380),R(cal+((RW(cal+0x1e)&bit)?0x14:0x1a)));
    egs51_adapt_fill_error(s,X(0x380));
}
static int signed8(uint8_t v) { return v<128?v:(int)v-256; }
void egs51_shift_adaptation(Egs51 *s) { /* AF12..B2C8 */
    uint16_t cal=XW(0x3ba);
    if(!I(0xb6)) {
        X(0x39a)=0;
        if((I(0x99)&12)==12) {
            if(X(0x79)&0x10) goto done;
            I(0x99)&=0xf3;
            uint8_t idx=X(0x32b)==8?6:R(0xe65b+X(0x32b));
            uint16_t cell=0x16d+idx;
            X(cell)+=X(0x1e4);
            int v=signed8(X(cell)),limit=signed8(R(cal+0x19));
            if(v>0 && v>limit) X(cell)=(uint8_t)limit;
            else if(v<0 && v<signed8((uint8_t)(0-R(cal+0x19)))) X(cell)=(uint8_t)(0-R(cal+0x19));
            if(X(0x1e4)) { X(0x1e4)=0; X(0x1bf)|=1; }
        } else I(0x99)&=0xf3;
        goto done;
    }
    switch(X(0x39a)) {
    case 0: {
        I(0x99)|=4;
        unsigned idx=(uint8_t)(I(0xac)-1);
        uint8_t bit=idx<8?(uint8_t)(1u<<idx):0;
        if(!(R(cal+1)&bit) || X(0x76)>R(cal+0x16) || X(0x76)<R(cal+0x15) || X(0x20f) ||
           ((I(0x96)&0x20) && I(0xb9)==3 && X(0x76)>=R(XW(0x3c6)+0x37))) I(0x99)&=0xfb;
        X(0x39a)++;
        /* OEM deliberately continues qualification in the same invocation. */
    }
    /* fall through */
    case 1:
        X(0x32b)=I(0xac);
        if(I(0xb6)==2 || I(0xb6)==3 || IW(0xad)>=RW(cal+2*I(0xac)) || (I(0x96)&4) ||
           (I(0xaa)==1 && I(0xb4)>=4) || (I(0x98)&1) || (I(0xb6)==4 && I(0xa9)>=X(0x334))) I(0x99)&=0xfb;
        if(!(I(0x99)&4) || (I(0x99)&8)) X(0x39a)++;
        break;
    case 2:
        if((X(0x1ca)&10) || (X(0x1cb)&8) || (I(0x99)&0x10)) I(0x99)&=0xfb;
        if(I(0xaa)>3) break;
        if(I(0xb6)==4 && signed16(XW(0x2bb))<0 && signed16(XW(0x2bb))<signed16(XW(0x33c)) && (I(0x99)&8)) I(0x99)&=0xf7;
        if(signed16(XW(0x2bb))>0 && signed8(X(0x1e4))<0 &&
           ((XW(0x22f)>(uint16_t)(XW(0x275)-R(cal+0x12)) && (I(0x95)&8)) ||
            (XW(0x275)>(uint16_t)(XW(0x22f)-R(cal+0x12)) && (I(0x95)&0x10)))) I(0x99)&=0xfb;
        break;
    default: break;
    }
    X(0x20f)=R(cal+0x1b);
done:
    XP(0x33c,XW(0x2bb));
}
/* 6AA3..6B79: demand factor latch used before forward pressure dispatch.
 * X224 is an OEM signed qualification signal; physical units are not inferred. */
void egs51_shift_demand_factor(Egs51 *s) {
    uint8_t next;
    if(I(0x95)&8) { next=10; X(0x202)=10; }
    else if((X(0x1c5)&0x80) || I(0xa9)>=X(0x334) || (I(0x96)&2)) next=R(XW(0x3ca)+0x2c);
    else if(signed16(XW(0x224))<0) next=10;
    else next=(uint8_t)egs51_lerp(10,R(XW(0x3ca)+0x2c),R(XW(0x3ca)+0x2a),R(XW(0x3ca)+0x2b),XW(0x224)/10);
    if(next>X(0x202)) X(0x202)=next;
}
