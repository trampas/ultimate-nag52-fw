/* Complete bank0 TCC scheduler, operating states, regulation and adaptation.
 * Context and calibration must be initialized by the caller; see README.md. */
#include "egs51_internal.h"
static int32_t sb(uint8_t v) { return v<128?v:(int32_t)v-256; }
static uint16_t absolute(uint16_t v) { return v<32768?v:(uint16_t)(0u-v); }
static uint16_t smd(uint16_t a,uint16_t b,uint16_t divisor) {
    assert(divisor);
    return (uint16_t)(signed16(a)*signed16(b)/signed16(divisor));
}
/* A7E6..A88A: sequential scaling truncates after each divide. */
uint8_t egs51_tcc_target(const Egs51 *s) {
    uint16_t v=egs51_map8(s,0,XW(0x3b0)+0x2a,(uint8_t)(XW(0x340)/25),X(0x285));
    if(!(X(0x1c0)&2)) v=md(v,B(0xfe3c),100);
    if(I(0x95)&8) v=md(v,B(0xfe3b),100);
    if(X(0x1c8)&0x40) v=md(v,B(0xfe7a),100);
    return (uint8_t)v;
}
/* AD0B..AE32: feedforward, selected by direction latch bit1. */
void egs51_tcc_feedforward(Egs51 *s) {
    uint16_t v;
    if(X(0x1c0)&2) {
        uint16_t curve=egs51_curve8(s,0,BW(0xedd4+2*I(0xb9)),(uint8_t)(XW(0x340)/25));
        XP(0x295,curve);
        v=md(BW(XW(0x3b8)+0x31),absolute(XW(0x1d4)),1000);
        v=md(v,X(0x121+X(0x39e)),100);
        v=(uint16_t)(v+md(curve,X(0x121+X(0x1e9)),20));
    } else {
        v=egs51_curve16(s,0,XW(0x3b0)+0x1e,XW(0x340)/25);
        v=(uint16_t)(v+egs51_curve16(s,0,XW(0x3b0)+0x24,absolute(XW(0x1d4))));
        v=md(v,X(0x11f),20);
    }
    IP(0x4c,v); IP(0x4a,I(0x57)?v:0);
}
/* A472..A631: signed thresholds with hysteresis; mode57 differs from mode56. */
void egs51_tcc_direction(Egs51 *s) {
    uint16_t cal=XW(0x3b8);
    int32_t input=signed16(XW(0x1d4)),hi=sb(B(cal+1)),lo=sb(B(cal+2)),hyst=sb(B(cal+3));
    X(0x1c0)&=0xfb;
    switch(I(0x57)) {
    case 2:
        if(input<=lo+hyst) break;
        X(0x1c0)|=4;
        if(input>hi+hyst) {
            I(0x57)=1; IP(0x46,smd(XW(0x30e),B(cal+8),100)); X(0x1c0)|=2;
        } else I(0x57)=0;
        break;
    case 1:
        if(input>=hi) break;
        X(0x1c0)|=4; X(0x1c0)&=0xfd;
        if(input<lo) { I(0x57)=2; IP(0x46,smd(XW(0x30e),B(cal+8),100)); }
        else I(0x57)=0;
        break;
    case 0:
        if(input<lo) { I(0x57)=2; X(0x1c0)&=0xfd; }
        else if(input>hi+hyst) { I(0x57)=1; X(0x1c0)|=2; }
        else X(0x1c0)|=4;
        break;
    default: break;
    }
}
/* AB5B..AD0A: slip PI and signed correction paths. Word arithmetic wraps. */
void egs51_tcc_slip_pi(Egs51 *s) {
    uint16_t cal=XW(0x3b8);
    if(I(0x57)) XP(0x30e,IW(0x46));
    IP(0x50,egs51_tcc_target(s)); IP(0x54,IW(0x52)-IW(0x50));
    uint16_t kp=egs51_curve16(s,0,(X(0x1c0)&2)?0xedb0:0xedb6,IW(0x52));
    uint16_t ki=egs51_curve16(s,0,(X(0x1c0)&2)?0xedbc:0xedc2,IW(0x52));
    IP(0x46,IW(0x46)+smd(smd(ki,IW(0x54),100),20,100));
    if(!I(0x57)) IP(0x46,smd(XW(0x30e),B(cal+8),100));
    else {
        int32_t accel=signed16(XW(0x224));
        if(accel>signed16(BW(0xfe4b)) && I(0x57)==1)
            IP(0x46,IW(0x46)-smd(XW(0x224),BW(0xfe4d),100));
        if(accel<=signed16(BW(0xfe49))) { I(0x56)=0; X(0x331)=B(0xfe2d); }
        else if(accel<=signed16(BW(0xfe45)))
            IP(0x46,IW(0x46)-smd(absolute(XW(0x224)),BW(0xfe47),100));
    }
    if(X(0x1c0)&0x80) IP(0x46,IW(0x46)-BW(cal+0x33));
    IP(0x44,smd(kp,IW(0x54),1000)+signed16(IW(0x46))/10);
}
/* AE33..AFE0: complete regulator with feedforward, PI and lower/upper clamps. */
void egs51_tcc_regulate(Egs51 *s) {
    egs51_tcc_direction(s);
    IP(0x44,0); IP(0x4a,0); IP(0x4e,IW(0x48));
    if(I(0x56)==0) { IP(0x48,0); IP(0x4e,0); }
    else if(I(0x56)==2) {
        uint16_t step=BW((X(0x1c0)&1)?0xfe4d:0xfe41);
        if(IW(0x48)>step && IW(0x48)>BW(0xfe16)) IP(0x48,IW(0x48)-step);
        else { X(0x331)=B(0xfe2d); I(0x56)=0; IP(0x48,0); }
        IP(0x4e,IW(0x48));
    } else if(I(0x56)==3) {
        IP(0x48,0); egs51_tcc_feedforward(s); egs51_tcc_slip_pi(s);
        uint16_t sum=(uint16_t)(IW(0x4a)+IW(0x44)),floor=BW(0xfe16);
        if(signed16(sum)<signed16(floor)) {
            if(X(0x1c0)&0x80) {
                uint16_t kp=egs51_curve16(s,0,(X(0x1c0)&2)?0xedb0:0xedb6,IW(0x52));
                IP(0x44,floor-IW(0x4a));
                IP(0x46,10u*(uint16_t)(IW(0x44)-smd(kp,IW(0x54),1000)));
            } else if(signed16(IW(0x46))<signed16(XW(0x30e)) && !(X(0x1c0)&4)) IP(0x46,XW(0x30e));
            IP(0x4e,floor);
        } else IP(0x4e,sum);
    }
    if(IW(0x4e)>BW(0xfe18)) {
        IP(0x4e,BW(0xfe18));
        if(signed16(IW(0x46))>signed16(XW(0x30e))) IP(0x46,XW(0x30e));
    }
}
/* A04B..A471: entry phases0..4 plus fill-time adaptation. State0 falls into1;
 * subsequent phase advances wait until the next invocation. Timer service is
 * external. The signed byte shifts and wrapping timer sums are intentional. */
void egs51_tcc_entry(Egs51 *s) {
    uint16_t cal=XW(0x3b8);
    unsigned inhibit=(I(0x2b)&0x80) || (X(0x79)&2);
    switch(X(0x30d)) {
    case 0:
        X(0x37d)=(uint8_t)(B(cal+0x39)+X(0x11d)); X(0x217)=0;
        X(0x1c0)|=8; ++X(0x30d);
        if(!(signed16(XW(0x2b5))>signed16(BW(0xfe72)) &&
             signed16(XW(0x2b5))<signed16(BW(0xfe6e)) && XW(0x340)>BW(0xfe76))) X(0x1c0)&=0xf7;
        /* fall through */
    case 1:
        IP(0x48,BW(cal+0x37));
        if(!X(0x37d)) {
            egs51_tcc_feedforward(s); XP(0x286,md(IW(0x4a),B(0xfe27),100));
            if(XW(0x286)<BW(cal+0x35)) XP(0x286,BW(cal+0x35));
            X(0x37d)=B(cal+0x3a); ++X(0x30d);
        }
        break;
    case 2:
        IP(0x48,egs51_lag(IW(0x48),XW(0x286),X(0x37d)));
        if(!X(0x37d)) { X(0x37d)=B(cal+0x3b); ++X(0x30d); }
        break;
    case 3:
        IP(0x48,XW(0x286));
        if(!X(0x37d)) { X(0x37d)=B(cal+0x3c); ++X(0x30d); }
        break;
    case 4: {
        egs51_tcc_feedforward(s);
        uint8_t percent=B(cal+((X(0x1c0)&2)?0x3d:0x3e));
        XP(0x286,md(IW(0x4a),percent,100));
        if(XW(0x286)<BW(cal+0x35)) XP(0x286,BW(cal+0x35));
        IP(0x48,egs51_lag(IW(0x48),XW(0x286),X(0x37d)));
        if(!X(0x37d)) {
            if((X(0x1c0)&8) && sb(X(0x11d))<sb(B(0xfe7b))) {
                if(!inhibit) ++X(0x11d);
                X(0x1c0)&=0xf7;
            }
            I(0x56)=3; XP(0x1dc,BW(0xfe30)); X(0x2b4)=0;
            XP(0x309,0); XP(0x30b,0); X(0x277)=0; XP(0x278,0);
            IP(0x46,smd(IW(0x4a),(uint16_t)(percent-100),10));
        }
        break;
    }
    default: break;
    }
    if(!(X(0x246)&2)) return;
    ++X(0x217);
    if(absolute(XW(0x224))>=BW(0xfe74) || !(X(0x1c0)&8) || X(0x76)<=B(0xfe7d)) {
        X(0x1c0)&=0xf7; return;
    }
    if(signed16(XW(0x2b5))>=signed16(BW(0xfe70))) return;
    X(0x1c0)&=0xf7;
    uint8_t total=(uint8_t)(B(cal+0x39)+X(0x11d)+B(cal+0x3a)+B(cal+0x3b));
    unsigned shifts=(uint8_t)(B(0xfe7e)+1);
    for(unsigned k=0;k<shifts;k++) total=(uint8_t)((total>>1)|(total&0x80));
    if(inhibit) return;
    uint8_t margin=B(0xfe7c);
    if(X(0x217)<(uint8_t)(total-margin)) {
        if(sb(X(0x11d))>sb((uint8_t)(0u-B(0xfe7b)))) --X(0x11d);
    } else if(X(0x217)>(unsigned)total+margin && sb(X(0x11d))<sb(B(0xfe7b))) ++X(0x11d);
}
/* A632..A7E5: accumulate a signed slip/torque metric, adjust the per-gear
 * adaptive factor when the accumulator exceeds its limit, then release. */
void egs51_tcc_excess_slip(Egs51 *s) {
    uint16_t cal=XW(0x3b8);
    uint16_t metric=smd((uint16_t)(absolute(XW(0x1d4))-XW(0x2c5)),XW(0x386),10);
    XP(0x2f1,metric);
    uint8_t increment;
    if(signed16(metric)>signed16(BW(0xfe5f))) increment=B(0xfe54);
    else if(signed16(metric)<signed16(BW(0xfe55))) increment=B(0xfe4f);
    else {
        unsigned k=1;
        while(signed16(metric)>signed16(BW(0xfe55+2*k))) ++k;
        increment=B(0xfe4e + k);
    }
    XP(0x293,XW(0x293)+sb(increment));
    if(signed16(XW(0x293))<0 || !(X(0x1c0)&2)) XP(0x293,0);
    if(XW(0x293)<=BW(0xfe61)) return;
    uint8_t status=X(0x120),limit=B(cal+0x20);
    unsigned cell=0x121+X(0x39e),inhibit=(I(0x2b)&0x80) || (X(0x79)&2);
    if(X(cell)>=limit) status|=0x10;
    else {
        status&=0xef;
        if(!inhibit) { X(cell)=(uint8_t)(X(cell)+B(cal+0x2b)); if(X(cell)>limit) X(cell)=limit; }
    }
    status=(uint8_t)((status&0xf0)+(status&15)+1);
    I(0x56)=0; X(0x331)=B(0xfe2d);
    if(!inhibit) X(0x120)=status;
}
/* A88B..AB5A: operating-state selection, including the complete entry sequence
 * and excess-slip adaptation above. Mode56 is separate from entry phase30D. */
void egs51_tcc_supervisor(Egs51 *s) {
    uint16_t cal=XW(0x3b8),curves=XW(0x3b0);
    X(0x345)=signed16(XW(0x1f3))/100>B(cal+0x0c);
    if(!I(0x56)) {
        if(X(0x76)<B(0xfe13) || X(0x76)>B(0xfe14)) X(0x345)=1;
    } else if(X(0x76)<(uint8_t)(B(0xfe13)-B(0xfe1e)) || X(0x76)>(unsigned)B(0xfe14)+B(0xfe1e)) X(0x345)=1;
    if(!I(0x56) && IW(0x52)<B(0xfe15)) X(0x345)=1;
    if(I(0x56)==3) egs51_tcc_excess_slip(s); else XP(0x293,0);
    if(X(0x1c8)&0x40) { X(0x345)=1; X(0x331)=B(0xfe2d); }
    switch(I(0x56)) {
    case 0:
        X(0x1c0)&=0xfe; IP(0x46,0); X(0x30d)=0;
        if(!X(0x331) && !(X(0x1c7)&0x20) && !I(0xb6) && !X(0x345)) {
            uint16_t threshold=25u*egs51_curve8(s,0,BW(curves+2*I(0xb9)),X(0x285));
            if(XW(0x2ac)>threshold) { I(0x56)=1; egs51_tcc_entry(s); }
        }
        break;
    case 1: {
        uint16_t threshold=25u*egs51_curve8(s,0,BW(curves+2*I(0xb9)-6),X(0x285));
        if(XW(0x2ac)<threshold || (X(0x1c7)&0x20) || X(0x345) ||
           ((I(0xb6) || (X(0x1c0)&0x80)) && X(0x30d)<4)) {
            I(0x56)=0; X(0x331)=B(0xfe2d);
        } else egs51_tcc_entry(s);
        break;
    }
    case 3: {
        uint16_t threshold=25u*egs51_curve8(s,0,BW(curves+2*I(0xb9)-6),X(0x285));
        if(XW(0x2ac)<threshold || (X(0x1c7)&0x20) || X(0x345)==1) {
            I(0x56)=2; IP(0x48,IW(0x4e));
        }
        break;
    }
    default: break;
    }
    if(XW(0x340)<BW(0xfe3d)) { I(0x56)=0; X(0x331)=B(0xfe2d); }
}
static uint32_t accumulator(const Egs51 *s) { return ((uint32_t)XW(0x309)<<16)|XW(0x30b); }
static void put_accumulator(Egs51 *s,uint32_t v) { XP(0x309,v>>16); XP(0x30b,v); }
static void clear_average(Egs51 *s) { X(0x2b4)=0; put_accumulator(s,0); }
static void clear_bias_average(Egs51 *s) { X(0x277)=0; XP(0x278,0); }
/* AFE1..B77A: three PI-output averaging regions and low-demand bias learning.
 * Parameter thresholds determine which factor is updated: X121+39E,
 * X121+1E9, X11F, or signed-byte X11E. No EEPROM write occurs here. */
void egs51_tcc_adapt(Egs51 *s) {
    if(XW(0x1dc)) return;
    uint16_t cal=XW(0x3b8);
    int32_t input=signed16(XW(0x1d4));
    unsigned inhibit=(I(0x2b)&0x80) || (X(0x79)&2);
    if(signed16(XW(0x224))>=signed16(BW(cal+0x10)) ||
       X(0x76)<=B(0xfe1f) || X(0x76)>=B(0xfe20) ||
       signed16(absolute(XW(0x1f3)))/100>=B(cal+0x0f) ||
       I(0x56)!=3 || XW(0x340)>=BW(cal+0x12)) {
        clear_average(s); clear_bias_average(s); return;
    }
    int region=-1;
    if(input>B(cal+0x24) && input<signed16(BW(cal+0x25))) region=2;
    else if(IW(0x4e)>BW(0xfe16)) {
        if(input>B(cal+0x22) && input<B(cal+0x23)) region=1;
        else if(input>sb(B(cal+0x1e)) && input<sb(B(cal+0x1f)) &&
                absolute((uint16_t)(absolute(XW(0x2b5))-IW(0x50)))<B(cal+0x1d) && XW(0x340)>BW(cal+0x14)) region=0;
    } else {
        clear_average(s);
        if(input>B(cal+0x18) && input<B(cal+0x23)) {
            uint8_t count=B(0xfe32);
            if(X(0x277)>=count) {
                if(!inhibit) {
                    assert(count);
                    uint16_t mean=(uint16_t)(signed16(XW(0x278))/count); XP(0x2d2,mean);
                    if(signed16(mean)>B(cal+0x1a) && sb(X(0x11e))<sb(B(cal+0x1b))) ++X(0x11e);
                    if(signed16(mean)<B(cal+0x19) && sb(X(0x11e))>sb((uint8_t)(0u-B(cal+0x1b)))) --X(0x11e);
                }
                clear_bias_average(s);
            } else { XP(0x278,XW(0x278)+XW(0x386)); ++X(0x277); }
        } else clear_bias_average(s);
        return;
    }
    clear_bias_average(s);
    if(region<0) { clear_average(s); return; }
    uint8_t count=B(cal+0x1c);
    if(X(0x2b4)<count) {
        if(!X(0x2b4)) X(0x2e7)=(uint8_t)region;
        if(X(0x2e7)==region) {
            put_accumulator(s,accumulator(s)+(uint32_t)signed16(IW(0x44))); ++X(0x2b4);
        } else clear_average(s);
        return;
    }
    if(!inhibit && (region!=2 || IW(0x4e)<BW(0xfe18))) {
        assert(count);
        uint32_t bits=accumulator(s);
        int64_t total=bits<0x80000000u?(int64_t)bits:(int64_t)bits-INT64_C(4294967296);
        uint16_t mean=(uint16_t)(total/count); XP(0x35a,mean);
        unsigned cell=region==2?0x121+X(0x39e):region==1?0x121+X(0x1e9):0x11f;
        uint16_t delta=BW(cal+(region==2?0x27:0x29));
        uint16_t center=region==0?BW(cal+0x16):0;
        if(signed16(mean)>signed16((uint16_t)(center+delta)) && X(cell)<B(cal+0x20)) ++X(cell);
        if(signed16(mean)<signed16((uint16_t)(center-delta)) && X(cell)>B(cal+0x21)) --X(cell);
    }
    clear_average(s);
}
/* 0FD2..100F: signed weighted average, unlike the unsigned ramp at1061. */
static uint16_t signed_filter(uint16_t old,uint16_t next,uint8_t weight) {
    return (uint16_t)((signed16(old)*weight+signed16(next))/(weight+1));
}
/* B838..BA17: complete TCC scheduler, including load/store of its 20-byte
 * context at X252, operating-state control, all adaptation and final override. */
void egs51_tcc_scheduler(Egs51 *s) {
    S(0x98)=0x10;
    for(unsigned k=0;k<20;k++) I(0x44+k)=X(0x252+k);
    XP(0x386,XW(0x340)-XW(0x1da));
    XP(0x2b5,signed_filter(XW(0x2b5),XW(0x386),B(0xfe39)));
    IP(0x52,absolute(XW(0x386)));
    flag(&X(0x1c0),0x80,(X(0x1c8)^X(0x1c0))&0x40);
    if(X(0x1c0)&0x80) X(0x3d6)=B(0xfe7f);
    if(!X(0x3d6)) XP(0x1d4,XW(0x395));
    else if(!--X(0x3d6)) {
        XP(0x1d4,XW(0x395)); egs51_tcc_feedforward(s);
        IP(0x46,IW(0x46)-10u*(uint16_t)(IW(0x4a)-XW(0x258)));
    } else XP(0x1d4,signed_filter(XW(0x1d4),XW(0x395),B(0xfe80)));
    unsigned gear=I(0xb9);
    if(!(X(0x78)&2) && !(X(0x73)&8) && !(X(0x1ca)&9) && !(X(0x1cb)&8) &&
       gear>=3 && gear<=5 && ((X(0x1c6)&1)?(X(0x246)&0x10):(X(0x246)&1))) {
        X(0x39e)=(uint8_t)(2*gear-5); X(0x1e9)=(uint8_t)(2*gear-6);
        egs51_tcc_supervisor(s); egs51_tcc_regulate(s);
        if((X(0x246)&4) && !(X(0x1ca)&2)) egs51_tcc_adapt(s);
        egs51_tcc_demand(s);
    } else { I(0x56)=0; IP(0x4e,0); IP(0x44,0); I(0x36)=0; }
    flag(&X(0x1c0),0x40,X(0x1c8)&0x40);
    egs51_tcc_override(s);
    for(unsigned k=0;k<20;k++) X(0x252+k)=I(0x44+k);
}
