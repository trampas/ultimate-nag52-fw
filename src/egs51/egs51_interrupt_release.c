/* A0215451432 release-family interruption control, bank1. */
#include "egs51_internal.h"
static uint16_t sub(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t pos(uint16_t a) { return signed16(a)>0?a:0; }
static uint16_t minp(uint16_t a,uint16_t b) { return a<b?a:b; }
void egs51_interrupt_fill_capacity(Egs51 *s,uint8_t gain) { /* 875D */
    XP(0x1d6,md(egs51_handoff_low_pressure(s,I(0xb6)),gain,IW(0x52)));
}
uint16_t egs51_interrupt_release_pressure(const Egs51 *s) { /* 877A */
    uint16_t t=pos((uint16_t)(IW(0xad)+XW(0x384)-XW(0x303)-XW(0x38c)));
    t=pos((uint16_t)(egs51_signed_md(t,IW(0x54),X(0x2ab))+IW(0x4c)));
    return minp(sub(t,IW(0x50)),XW(0x273));
}
uint16_t egs51_interrupt_release_mod_pressure(const Egs51 *s,uint8_t idx,uint16_t pressure) { /* 8836 */
    uint16_t t=pos((uint16_t)(IW(0xad)+XW(0x384)-XW(0x303)));
    t=sub((uint16_t)(md(t,XW(0x33a),R(0xffd1))+XW(0x2a1)),XW(0x231));
    uint16_t hyd=XW(0x3ce);
    t=sub(md(t,RW(hyd+((idx==0 || idx==4)?1:3)),1000),RW(hyd+5));
    uint16_t off=sub((uint16_t)(egs51_handoff_low_pressure(s,I(0xb6))+IW(0x4a)),IW(0x4e));
    uint16_t mixed=egs51_overlap_pressure(s,(idx+4)&7,pressure,off);
    return minp(t>mixed?t:mixed,XW(0x329));
}
uint16_t egs51_interrupt_release_settle_pressure(const Egs51 *s,uint8_t idx) { /* 89B5 */
    uint16_t t=sub(pos((uint16_t)(IW(0xad)-XW(0x1d6))),md(X(0x397),XW(0x2f5),100));
    t=sub((uint16_t)(md(t,IW(0x54),X(0x2ab))+IW(0x4c)),IW(0x50));
    return minp(md(t,R(XW(0x3ca)+0xa+idx),100),XW(0x273));
}
uint16_t egs51_interrupt_transfer_mod_pressure(const Egs51 *s,uint8_t idx) { /* 8A92 */
    idx=(idx+4)&7;
    uint16_t p=sub((uint16_t)(md(IW(0xad),IW(0x52),R(0xffd0))+IW(0x4a)),IW(0x4e));
    return egs51_overlap_pressure(s,idx,(idx==0 || idx==1)?IW(0x4c):IW(0x46),p);
}
uint16_t egs51_interrupt_transfer_pressure(const Egs51 *s) { /* 8B0C */
    uint16_t t,p,cal=XW(0x3ca);
    if(I(0xac)==5 || I(0xac)==6) {
        if(X(0x285)<R(cal+0x31) && (I(0x96)&0x40)) {
            t=(uint16_t)(XW(0x384)+XW(0x378)-XW(0x38c)-md(X(0x397),XW(0x2f9),100));
            uint16_t low=(uint16_t)(0-RW(XW(0x3c6)+0x39));
            if(signed16(t)<signed16(low)) t=low;
            p=pos((uint16_t)(egs51_signed_md(t,IW(0x54),X(0x2ab))+IW(0x4c)-IW(0x50)));
        } else {
            t=pos((uint16_t)(IW(0xad)+XW(0x378)+XW(0x384)-XW(0x38c)));
            p=md(sub(t,md(X(0x397),XW(0x2f9),100)),IW(0x54),X(0x2ab));
            p=sub((uint16_t)(p+IW(0x4c)),IW(0x50));
        }
        p=md(p,R(cal+0x1f),100);
    } else {
        t=pos((uint16_t)(IW(0xad)+XW(0x378)+XW(0x384)-XW(0x38c)-XW(0x228)));
        p=pos((uint16_t)(md(t,IW(0x54),X(0x2ab))+IW(0x4c)-IW(0x50)));
    }
    return minp(p,XW(0x273));
}
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p)); }
static void modulate(Egs51 *s) { IP(0x44,egs51_interrupt_release_mod_pressure(s,I(0xac)-1,IW(0x46))); }
static void momentum(Egs51 *s) {
    XP(0x20c,egs51_percent_filter(R(XW(0x3be)+0x19),XW(0x27c),XW(0x20c)));
    egs51_shift_momentum_control(s,XW(0x20c));
}
static int withdrawn(const Egs51 *s) {
    return (I(0xb6)==2 && signed16(XW(0x2b9))>signed16((uint16_t)(0-RW(XW(0x3ca)+0x2f)))) ||
           (I(0xb6)==3 && XW(0x2b9)<RW(XW(0x3ca)+0x3c));
}
void egs51_interrupt_release(Egs51 *s) { /* 9F91..A3A4 */
    egs51_shift_fill_torque(s); egs51_shift_gain(s); egs51_interrupt_fill_capacity(s,X(0x2ab));
    uint16_t cal=XW(0x3ca),speed;
    switch(I(0xb4)) {
    case 0:
        I(0x95)|=0x40; XP(0x38c,0); I(0xb1)=egs51_release_ramp_time(s,I(0xac)); IP(0xb7,RW(0xffb5));
        for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
        XP(0x20c,0); XP(0x27c,0); ++I(0xb4);
        /* fall through */
    case 1:
        apply(s,egs51_lag(IW(0x46),egs51_interrupt_release_pressure(s),I(0xb1))); modulate(s);
        if(!I(0xb1) || signed16(XW(0x357))>=signed16(egs51_shift_threshold(s,I(0xac)-1,R(cal+2)))) ++I(0xb4);
        break;
    case 2:
        speed=XW(0x2bb); if(signed16(speed)<0) speed=(uint16_t)(0-speed);
        if(signed16(speed)>signed16(RW(cal+0x20)) || IW(0x46)<=IW(0x4c) ||
           signed16(XW(0x357))<signed16(egs51_shift_threshold(s,I(0xac)-1,R(cal+2)))) {
            ++I(0xb4); XP(0x27c,XW(0x1d6)+XW(0x303)); XP(0x20c,XW(0x27c));
            XP(0x2a9,XW(0x22f)); flag(&I(0x98),4,XW(0x1f6)>0);
        } else {
            XP(0x38c,XW(0x38c)+RW(cal+6)); apply(s,egs51_interrupt_release_pressure(s)); modulate(s);
        }
        break;
    case 3:
        XP(0x27c,XW(0x1d6)+XW(0x303)); momentum(s); apply(s,egs51_interrupt_release_pressure(s)); modulate(s);
        if(signed16(XW(0x357))<signed16(egs51_shift_threshold(s,I(0xac)-1,R(cal+2)))) { ++I(0xb4); I(0xb1)=R(cal+2); }
        break;
    case 4:
        XP(0x27c,egs51_lag(XW(0x27c),egs51_release_momentum(s),I(0xb1))); momentum(s);
        apply(s,egs51_lag(IW(0x46),egs51_interrupt_release_settle_pressure(s,I(0xac)-1),I(0xb1))); modulate(s);
        if(!I(0xb1)) { ++I(0xb4); I(0xb1)=R(cal+3); }
        break;
    case 5:
        apply(s,egs51_interrupt_release_settle_pressure(s,I(0xac)-1)); modulate(s);
        if(!I(0xb1)) I(0xb4)=0;
        break;
    default: break;
    }
    if(!IW(0xb7) || !I(0xb4) || signed16(XW(0x357))<signed16(RW(cal+0x20))) {
        I(0xb4)=I(0xb5)=0; ++I(0xaa);
    } else if(withdrawn(s)) { I(0xb4)=I(0xb5)=0; I(0xaa)=11; }
}
static void capacity(Egs51 *s,uint16_t low) {
    XP(0x1d6,md(low,R(0xffd0),IW(0x52)));
    XP(0x228,minp((uint16_t)(XW(0x1d6)+md(X(0x397),XW(0x2f9),100)),XW(0x303)));
}
void egs51_interrupt_release_transfer(Egs51 *s) { /* A3A5..A557 */
    uint16_t low=egs51_handoff_low_pressure(s,I(0xb6)),cal=XW(0x3ca);
    if(!I(0xb4)) {
        I(0x95)|=0x40; XP(0x2dc,IW(0x46));
        I(0xb0)=R(cal+I(0xac)+(I(0xac)<=4?0x31:0x2d)); I(0xb1)=R(cal+0x36);
        capacity(s,low); ++I(0xb4);
    }
    if(I(0xb4)==1) {
        if(I(0xac)==7) {
            if(!I(0xb1)) XP(0x228,egs51_lag(XW(0x228),IW(0xad),I(0xb0)));
            else capacity(s,low);
        } else {
            egs51_applying_capacity(s,IW(0x46),R(0xffd0));
            XP(0x228,XW(0x1d6)+md(X(0x397),XW(0x2f9),100));
        }
        apply(s,egs51_lag(IW(0x46),egs51_interrupt_transfer_pressure(s),I(0xb0)));
        IP(0x44,egs51_lag(IW(0x44),egs51_interrupt_transfer_mod_pressure(s,I(0xac)-1),I(0xb0)));
    }
    if(!IW(0xb7) || !I(0xb0)) { I(0xb0)=I(0xb1)=I(0xb4)=I(0xb5)=0; ++I(0xaa); }
    else if(withdrawn(s)) { I(0xb4)=I(0xb5)=0; I(0xaa)=11; }
}
