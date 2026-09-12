/* A0215451432 mode6 engagement control, bank1. */
#include "egs51_internal.h"
static uint16_t absw(uint16_t v) { return signed16(v)<0?(uint16_t)(0-v):v; }
static uint16_t minp(uint16_t a,uint16_t b) { return a<b?a:b; }
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p)); }
static uint16_t sync_error(const Egs51 *s) { return absw((uint16_t)(XW(0x22f)-egs51_gear_sync_speed(s,I(0xb9)))); }
static uint16_t sync_limit(const Egs51 *s) { return RW(X(0x285)>R(0xffa4)?0xffa9:0xff83); }
uint16_t egs51_engage_timeout(const Egs51 *s) { /* 31AE */
    return egs51_lerp(RW(0xff97),RW(0xff99),R(0xff91),R(0xff92),X(0x76));
}
uint16_t egs51_engage_torque_pressure(const Egs51 *s,uint16_t torque) { /* 31EE */
    return minp((uint16_t)(md(md(IW(0x52),torque,X(0x2ab)),XW(0x288),1000)+IW(0x4a)),XW(0x273));
}
void egs51_engage_momentum(Egs51 *s) { /* 323D */
    uint16_t sync=egs51_gear_sync_speed(s,I(0xb9)),a=absw((uint16_t)(XW(0x275)-sync));
    if(a>XW(0x3a1)) XP(0x3a1,a);
    a=absw((uint16_t)(XW(0x275)-XW(0x2c9))); if(a>XW(0x336)) XP(0x336,a);
    uint8_t factor;
    if(XW(0x275)>RW(0xff7f)) factor=R(XW(0x3b2)+2);
    else if((X(0x1c6)&0x20) || XW(0x275)<=sync) { factor=R(XW(0x3b2)+1); XP(0x336,0); }
    else factor=R(XW(0x3b2)+2);
    uint16_t divisor=20u*factor;
    XP(0x343,md(R(XW(0x3d4)+0x7c+I(0xac)),XW(0x3a1),divisor)+md(X(0x32e),XW(0x336),divisor));
}
uint8_t egs51_engage_match(Egs51 *s,uint8_t ramp,uint8_t hold,uint8_t inhibit,uint8_t clutch) { /* 33D6; fourth arg originally scratch6C */
    uint16_t error=sync_error(s),limit=sync_limit(s);
    if(!inhibit && error<=limit) { I(0x9a)&=0xdf; I(0x97)&=0xfe; }
    if(!ramp) {
        if(IW(0xb7)) {
            if(!(I(0x9a)&0xc0)) { I(0x9a)&=0xdf; I(0x97)&=0xfe; }
            I(0x95)&=0xf8;
        }
        if(clutch==1) { IP(0x46,XW(0x273)); IP(0x48,XW(0x329)); IP(0x44,5000); }
        else IP(0x44,XW(0x329));
        return !hold;
    }
    if(clutch==1) { apply(s,egs51_lag(IW(0x46),XW(0x273),I(0xb0))); IP(0x44,egs51_lag(IW(0x44),5000,ramp)); }
    else IP(0x44,egs51_lag(IW(0x44),XW(0x329),ramp));
    if(X(0x251)) {
        if(error<=limit) {
            if(!--X(0x251)) { I(0xb0)=R(0xff79); I(0xb1)=(uint8_t)(I(0xb0)+egs51_hold_time(s)); }
        } else X(0x251)=R(0xffa6);
    }
    return 0;
}
void egs51_engage_recover(Egs51 *s) { /* 3545 */
    I(0x9a)&=0xdf; I(0x97)&=0xfe;
    uint16_t threshold=RW((I(0x9a)&0xc0)?0xff85:0xff95);
    if(sync_error(s)<=sync_limit(s) || absw((uint16_t)(XW(0x275)-XW(0x22f)))>threshold) {
        I(0xb4)=I(0xb5)=0; I(0xaa)=2; return;
    }
    I(0x9a)|=0x20;
    if(XW(0x2ac)>=RW(0xff7d)) { I(0xb4)=I(0xb5)=0; I(0xaa)=4; }
    else { I(0x95)&=0xfb; I(0xb0)=egs51_hold_time(s); ++I(0xb4); }
}
void egs51_engage_prepare(Egs51 *s) { /* 3646 */
    flag(&I(0x94),0x20,XW(0x2ac)>RW(0xff9b)); I(0x9a)=(I(0x9a)&0xfd)|0x20;
    I(0xb4)=I(0xb5)=I(0xb0)=I(0xb1)=I(0xb2)=0; X(0x251)=R(0xffa6);
    if((X(0x334)==7 && (X(0x1bd)&1)) || ((I(0x9a)&4) && XW(0x2ac)>=RW(0xffa7))) {
        IP(0x44,0); IP(0x46,0); IP(0x48,0); I(0x95)|=6; return;
    }
    uint8_t gear=I(0xb9); uint16_t mech=XW(0x3d4);
    I(0x56)=R(0xe654+gear); XP(0x288,RW(XW(0x3b2)+4+2*gear));
    IP(0x52,RW(mech+1+12*gear+2*I(0x56))); IP(0x4a,RW(mech+0x71+2*I(0x56))); IP(0x4e,egs51_speed_pressure(s,I(0x56)));
    if(gear==7) IP(0x52,md(IW(0x52),RW(mech+0x21),RW(mech+0x15)));
    I(0xac)=(gear<=2 || gear>=6)?1:3;
    if((I(0x9a)&4) && ((X(0x1c6)&0x20) || X(0x1e8)==6)) I(0xac)=1;
    I(0xaa)=1;
}
void egs51_engage_finish(Egs51 *s) { /* 423B */
    I(0x95)&=0xf8; IP(0x44,5100); apply(s,XW(0x273)); I(0x9a)&=0xe8; I(0x94)&=0x3f;
    I(0xb0)=I(0xb1)=I(0xb2)=I(0xb6)=I(0xb4)=I(0xb5)=I(0xaa)=0; IP(0xb7,0); I(0xb0)=R(0xff72);
    I(0x94)=X(0x334)==7?(I(0x94)&0xfb)|8:(I(0x94)|4)&0xf7;
}
void egs51_engage_abort(Egs51 *s) { /* 42BE */
    if(!I(0xb4)) { I(0x95)=(I(0x95)&0xfe)|6; I(0xb0)=egs51_fill_time(s); ++I(0xb4); }
    if(I(0xb4)!=1) return;
    IP(0x46,0); IP(0x48,0); IP(0x44,0);
    if(!I(0xb0)) { I(0x95)&=0xf8; I(0x9a)|=0x10; I(0xb4)=I(0xb5)=0; I(0xaa)=1; }
}
void egs51_engage_resolve(Egs51 *s) { /* 4311 */
    if(!I(0xb4)) { I(0xb0)=R(0xff94); ++I(0xb4); }
    uint8_t reported=X(0x2ec);
    if(I(0xb4)==1) {
        if(!reported || reported==0x58) { if(!I(0xb0)) { I(0xb4)=0; I(0xaa)=reported?3:2; } }
        else { X(0x37e)=reported; ++I(0xb4); }
    } else if(I(0xb4)==2) {
        if(!reported || reported==0x58) {
            if(!I(0xb0)) { I(0xb4)=0; if(!reported) egs51_engage_recover(s); else I(0xaa)=3; }
        } else if(reported==255 || reported!=X(0x37e)) { I(0xb4)=0; I(0xaa)=3; }
        else if(!I(0xb0)) { I(0xb9)=I(0xb3)=reported>=1 && reported<=7?reported:3; I(0xb4)=0; I(0xaa)=2; }
    }
}
static uint16_t positive(uint16_t v) { return signed16(v)>0?v:0; }
static uint16_t subtract(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t fill_base(const Egs51 *s,int early) {
    uint16_t cal=XW(0x3b2),offset=early?0:8;
    if(I(0x56)==1) return RW(cal+0x19+offset);
    return egs51_lerp(RW(cal+0x15+offset),RW(cal+(I(0x56)==4?0x17:0x1b)+offset),R(cal+0x2b),R(cal+0x2c),X(0x76));
}
static void enter_match(Egs51 *s,uint8_t phase) {
    I(0xb0)=R(0xff79); I(0xb1)=(uint8_t)(I(0xb0)+egs51_hold_time(s)); I(0xb2)=R(0xffa0); I(0xb4)=phase;
}
void egs51_engage_control(Egs51 *s) { /* 37CC..423A, all ten substates */
    egs51_engage_momentum(s);
    uint16_t error=sync_error(s),limit=sync_limit(s),cal=XW(0x3b2);
    uint16_t extra=minp(md(RW(cal+0x3a),X(0x285),R(cal+0x2f)),RW(cal+0x3a));
    extra=(uint16_t)(extra+md(positive((uint16_t)(XW(0x275)-RW(0xffab))),R(cal+0x2e),100));
    flag(&I(0x94),0x10,XW(0x398)<=RW(cal+0x3c) && !(I(0x9a)&0x40));
    uint16_t p,t;
    switch(I(0xb4)) {
    case 0:
        XP(0x343,0); XP(0x3a1,0); XP(0x336,0);
        if(I(0xb9)<=2 || I(0xb9)>=6) I(0x95)=(I(0x95)&0xfd)|4;
        else I(0x95)=(I(0x95)|2)&0xfb;
        IP(0xb7,egs51_engage_timeout(s));
        I(0xb0)=(uint8_t)egs51_lerp(R(cal+0x31),R(cal+0x30),45,70,X(0x76)); ++I(0xb4);
        /* fall through */
    case 1:
        IP(0x44,3000);
        apply(s,(I(0x9a)&0x80)?XW(0x273):(uint16_t)(egs51_handoff_clutch_pressure(s,fill_base(s,1))+extra));
        if(!I(0xb0)) {
            I(0xb0)=egs51_map8(s,1,XW(0x3b4),I(0x56)==4?0:I(0x56)==1?2:3,X(0x76)); ++I(0xb4);
        }
        break;
    case 2:
        if(I(0xb0) && (XW(0x398)>RW(cal+0x32) || X(0x76)<=R(0xff74))) { IP(0x44,3000); break; }
        I(0xb0)=X(0x285)>R(0xffa4)?R(0xffa5):R(cal+0x25);
        if(XW(0x2ac)<RW(0xff9b) && X(0x76)>60 && XW(0x398)<=RW(cal+0x32)) I(0x9a)&=0xdf;
        ++I(0xb4); break;
    case 3:
        if(!I(0xb0) || (I(0x94)&0x10)) {
            I(0xb0)=R(cal+(I(0x56)==4?0x26:I(0x56)==1?0x28:0x29)); ++I(0xb4); break;
        }
        IP(0x44,3000);
        if(I(0x9a)&0x80) apply(s,XW(0x273));
        else apply(s,egs51_lag(IW(0x46),(uint16_t)(egs51_handoff_clutch_pressure(s,fill_base(s,0))+extra),I(0xb0)));
        if(error<=limit) enter_match(s,7);
        break;
    case 4:
        if(!I(0xb0) || (I(0x94)&0x10)) {
            XP(0x2dc,IW(0x46)); for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
            XP(0x2a9,XW(0x22f)); XP(0x2b1,XW(0x275));
            t=positive((uint16_t)(IW(0x46)+IW(0x4e)-IW(0x4a)));
            XP(0x27c,subtract(md(md(X(0x2ab),t,IW(0x52)),1000,XW(0x288)),IW(0xad))); XP(0x20c,0);
            if((I(0x9a)&0x80) && !(I(0x9a)&0x10)) enter_match(s,6);
            else { I(0xb0)=R(cal+0x14); I(0xb1)=R(0xff77); I(0xb4)=5; }
            break;
        }
        IP(0x44,3000);
        apply(s,(I(0x9a)&0x80)?XW(0x273):(uint16_t)(egs51_handoff_clutch_pressure(s,fill_base(s,0))+extra));
        if(error<=limit) {
            if(X(0x285)>R(cal+0x2f)) { I(0xb0)=I(0xb1)=I(0xb2)=0; I(0xb4)=7; }
            else enter_match(s,7);
        }
        break;
    case 5:
        if(!(I(0x9a)&0x10) || (X(0x1c6)&0x20)) {
            XP(0x27c,egs51_lag(XW(0x27c),XW(0x343),I(0xb0)));
            XP(0x20c,egs51_percent_filter(R(XW(0x3be)+0x19),XW(0x27c),XW(0x20c)));
            egs51_shift_momentum_control(s,XW(0x20c));
            p=egs51_engage_torque_pressure(s,positive((uint16_t)(IW(0xad)+XW(0x343)+XW(0x384))));
            if(XW(0x2dc)>p) p=XW(0x2dc);
        } else p=XW(0x273);
        apply(s,egs51_lag(IW(0x46),p,I(0xb1)));
        if(IW(0x48)>=(uint16_t)(XW(0x329)-1500) || !IW(0xb7) || error<=limit) enter_match(s,7);
        break;
    case 6: case 7:
        if(egs51_engage_match(s,I(0xb0),I(0xb1),I(0xb2),1)) I(0xb4)=8;
        break;
    case 8: egs51_engage_recover(s); break;
    case 9: if(!I(0xb0)) I(0xb4)=I(0xb5)=0; break;
    default: break;
    }
    if(I(0xb4)>=2 && I(0xb4)<6) {
        if(X(0x2de)>R(cal+0x2d)) {
            I(0x9a)&=0xef; I(0xb0)=R(0xff90); I(0xb1)=(uint8_t)(I(0xb0)+R(0xff94)); I(0xb2)=R(0xffa0); I(0xb4)=6;
        } else if(I(0x94)&0x20) {
            I(0x9a)&=0xef; I(0xb0)=R(0xff9d); I(0xb1)=(uint8_t)(I(0xb0)+R(0xff79)); I(0xb2)=R(0xffa0); I(0xb4)=6;
        }
    }
}
