/* OEM shared shift entry/finish and mode2/3 transfer/matching phases, bank1. */
#include "egs51_internal.h"
static uint16_t sf(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t pos(uint16_t v) { return signed16(v)>0?v:0; }
static uint16_t minimum(uint16_t a,uint16_t b) { return a<b?a:b; }
static uint16_t maximum(uint16_t a,uint16_t b) { return a>b?a:b; }
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p)); }
/* 72AA..7301 */
uint16_t egs51_release_bleed_pressure(const Egs51 *s,uint8_t idx,uint16_t on) {
    uint16_t off=sf((uint16_t)(md(XW(0x233),IW(0x54),R(0xffd0))+IW(0x4c)),IW(0x50));
    return egs51_overlap_pressure(s,idx,on,off);
}
/* 97EC..9933 valid mode1..4 entry (B4=0 or1). High pressure is intentionally
 * evaluated before context refresh, following the actual call order. */
void egs51_release_entry(Egs51 *s) {
    assert(I(0xb6)>=1 && I(0xb6)<=4);
    egs51_shift_fill_torque(s);
    uint16_t high=egs51_handoff_clutch_pressure(s,egs51_handoff_high_pressure(s,I(0xb6)));
    if(I(0xb2)) return;
    assert(I(0xb4)<=1);
    if(!I(0xb4)) {
        egs51_shift_clutch_context(s); IP(0xb7,RW((I(0x96)&0x40)?0xffb7:0xffb5));
        I(0xb0)=I(0xb6)==3?(uint8_t)egs51_lerp(R(0xffb0),RW(0xffcc),R(0xffb9),R(0xffba),X(0x76)):R(0xffb0);
        ++I(0xb4);
    }
    uint8_t idx=I(0xac)-1;
    apply(s,egs51_lag(IW(0x46),high,I(0xb0)));
    if(!I(0xb0)) { I(0x95)|=R(0xe67c+idx); I(0xb4)=I(0xb5)=0; ++I(0xaa); }
    if(I(0xb6)==2 || I(0xb6)==3) {
        if(I(0xac)==2) high=md(high,RW(XW(0x3ce)+0x39),1000);
        IP(0x44,egs51_release_bleed_pressure(s,idx,high));
    } else IP(0x44,egs51_crossover_bleed_pressure(s,idx,high));
}
/* 7CEE..7D74 */
uint16_t egs51_release_transfer_apply(const Egs51 *s) {
    uint16_t demand=sf((uint16_t)(md(IW(0x52),IW(0xad),R(0xffd0))+IW(0x4a)),IW(0x4e));
    return minimum(maximum(demand,sf(XW(0x2dc),IW(0x4e))),XW(0x273));
}
/* 79BD..7CED: index is one-based, with distinct freewheel cases5/6. */
uint16_t egs51_release_transfer_mod(const Egs51 *s,uint8_t idx) {
    uint16_t on=IW(0x46),off,t;
    uint16_t cal=XW(0x3ca);
    if(idx==5 || idx==6) {
        uint16_t inertia=md(X(0x397),XW(0x2f9),100);
        if(X(0x285)<R(cal+0x31) && (I(0x96)&0x40)) {
            t=(uint16_t)(XW(0x384)+XW(0x378)-XW(0x38c)-inertia);
            uint16_t floor=(uint16_t)(0u-RW(XW(0x3c6)+0x39));
            if(signed16(t)<signed16(floor)) t=floor;
            off=pos((uint16_t)(egs51_signed_md(t,IW(0x54),X(0x2ab))+IW(0x4c)-IW(0x50)));
        } else {
            t=pos((uint16_t)(IW(0xad)+XW(0x378)+XW(0x384)-XW(0x38c)));
            off=sf((uint16_t)(md(sf(t,inertia),IW(0x54),X(0x2ab))+IW(0x4c)),IW(0x50));
        }
        off=md(off,R(cal+0x1f),100); on=sf(XW(0x2dc),IW(0x4e));
    } else {
        t=pos((uint16_t)(IW(0xad)+XW(0x378)+XW(0x384)-XW(0x38c)-XW(0x228)));
        off=pos((uint16_t)(md(t,IW(0x54),X(0x2ab))+IW(0x4c)-IW(0x50)));
    }
    return egs51_overlap_pressure(s,idx-1,on,off);
}
static void transfer_capacity(Egs51 *s,uint16_t low) {
    /* 1FED followed by 6F85, including intermediate wrap before min. */
    XP(0x1d6,md(low,R(0xffd0),IW(0x52)));
    XP(0x228,minimum((uint16_t)(XW(0x1d6)+md(X(0x397),XW(0x2f9),100)),XW(0x303)));
}
/* 96BB..97EB */
void egs51_release_transfer(Egs51 *s) {
    uint16_t low=egs51_handoff_low_pressure(s,I(0xb6)),cal=XW(0x3ca);
    if(!I(0xb4)) {
        I(0x95)|=0x40; XP(0x2dc,IW(0x46)+IW(0x4e));
        I(0xb0)=R(cal+I(0xac)+(I(0xac)<=4?0x31:0x2d)); I(0xb1)=R(cal+0x36);
        transfer_capacity(s,low); ++I(0xb4);
    }
    if(I(0xb4)==1) {
        apply(s,egs51_lag(IW(0x46),egs51_release_transfer_apply(s),I(0xb0)));
        if(I(0xac)==7) {
            if(!I(0xb1)) XP(0x228,egs51_lag(XW(0x228),IW(0xad),I(0xb0)));
            else transfer_capacity(s,low);
        } else {
            egs51_applying_capacity(s,IW(0x46),R(0xffd0));
            XP(0x228,XW(0x1d6)+md(X(0x397),XW(0x2f9),100));
        }
        IP(0x44,egs51_release_transfer_mod(s,I(0xac)));
    }
    if(!IW(0xb7) || !I(0xb0)) { I(0xb4)=0; ++I(0xaa); }
}
/* 8200..844D */
uint16_t egs51_release_match_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t on,off;
    if(idx==4 || idx==5) {
        uint16_t t=pos((uint16_t)(IW(0xad)+XW(0x378)+XW(0x384)-XW(0x38c)));
        off=sf((uint16_t)(md(sf(t,md(X(0x397),XW(0x2f5),100)),IW(0x54),X(0x2ab))+IW(0x4c)),IW(0x50));
        off=md(off,R(XW(0x3ca)+0x1f),100); on=sf(IW(0x4a),IW(0x4e));
    } else {
        on=minimum(sf((uint16_t)(md(IW(0xad),IW(0x52),R(0xffd0))+IW(0x4a)),IW(0x4e)),XW(0x273));
        off=sf(IW(0x4c),IW(0x50));
    }
    return egs51_overlap_pressure(s,idx,on,off);
}
/* 9A6B..9ACD: SPC pressure matching before circuit release is preserved. */
void egs51_release_match(Egs51 *s) {
    IP(0x44,egs51_release_match_pressure(s,I(0xac)-1));
    if(!I(0xb4)) {
        I(0x95)&=0xbf; I(0xb0)=R(0xffb1);
        I(0xb1)=(uint8_t)(I(0xb0)+egs51_lerp(R(0xffb2),R(0xffbe),R(0xffb3),R(0xffb4),X(0x76)));
        ++I(0xb4);
    }
    if(I(0xb4)==1) apply(s,egs51_lag(IW(0x46),XW(0x273),I(0xb0)));
    if(!I(0xb1)) { I(0xb4)=0; ++I(0xaa); }
}
/* 9934..99C6 */
void egs51_shift_finish(Egs51 *s) {
    I(0x95)&=0xf8;
    if(!I(0xb4)) {
        I(0xb0)=(uint8_t)egs51_lerp(R(0xffbb),R(0xffbc),R(0xffbd),R(0xffc7),X(0x76)); ++I(0xb4);
    }
    if(I(0xb4)==1) apply(s,XW(0x273));
    if(!I(0xb0)) {
        I(0x96)&=0x90; I(0x95)&=0xc7;
        IP(0xb7,0); I(0xb0)=I(0xb1)=I(0xaf)=I(0xb6)=I(0xb4)=I(0xb5)=I(0xaa)=0;
        if(I(0xb9)<=I(0xa9)) X(0x202)=10;
    }
}
