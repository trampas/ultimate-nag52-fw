/* A0215451432 bank1 mode1/4 crossover pressure execution. */
#include "egs51_internal.h"
static uint16_t sub(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t minp(uint16_t a,uint16_t b) { return a<b?a:b; }
static uint16_t maxp(uint16_t a,uint16_t b) { return a>b?a:b; }
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,(uint8_t)(I(0xac)-1),p)); }
uint16_t egs51_crossover_clutch_pressure(const Egs51 *s,uint16_t p) { /* 71ED */
    return minp(sub((uint16_t)(p+IW(0x4a)),IW(0x4e)),XW(0x273));
}
uint16_t egs51_crossover_bleed_pressure(const Egs51 *s,uint8_t idx,uint16_t on) { /* 7225 */
    uint16_t off=sub((uint16_t)(md(XW(0x233),IW(0x54),R(0xffd0))+IW(0x4c)),IW(0x50));
    off=md(off,R(XW(0x3be)+5+idx),100);
    return egs51_overlap_pressure(s,idx,on,off);
}
uint16_t egs51_crossover_fill_pressure(const Egs51 *s,uint8_t idx,uint16_t low) { /* 7302 */
    uint16_t on=sub((uint16_t)(md(IW(0x52),IW(0xad),X(0x2ab))+IW(0x4a)),IW(0x4e));
    on=minp(maxp(on,sub((uint16_t)(low+IW(0x4a)),IW(0x4e))),XW(0x273));
    uint16_t off=md(sub(IW(0x4c),IW(0x50)),R(XW(0x3be)+5+idx),100);
    return egs51_overlap_pressure(s,idx,on,off);
}
uint16_t egs51_crossover_free_pressure(const Egs51 *s,uint8_t idx) { /* 7DDF */
    uint16_t cal=XW(0x3ce),gain=RW(cal+0x17+2*idx);
    uint16_t on=md(IW(0x46),RW(cal+7+2*idx),1000);
    uint16_t off=md(md(IW(0x50),gain,1000),R(XW(0x3be)+5+idx),100);
    off=(uint16_t)(off+md(RW(XW(0x3be)+0x26),gain,1000));
    uint16_t p=sub(on,off),spring=RW(cal+0x27+2*idx);
    p=signed16(spring)<0?sub(p,(uint16_t)(0-spring)):(uint16_t)(p+spring);
    return minp(p,XW(0x329));
}
static void fill_mod(Egs51 *s,uint16_t low,int freewheel) {
    uint8_t idx=(uint8_t)(I(0xac)-1);
    if(freewheel && ((IW(0xad)<RW(XW(0x3ba)+2*I(0xac)) && (I(0x98)&2)) || (I(0x96)&0x20)))
        IP(0x44,egs51_crossover_free_pressure(s,idx));
    else {
        if(freewheel) I(0x98)&=0xfd;
        IP(0x44,maxp(egs51_crossover_fill_pressure(s,idx,low),egs51_crossover_bleed_pressure(s,idx,IW(0x46))));
    }
}
static void fill_complete(Egs51 *s) {
    egs51_shift_pressure_compensation(s); I(0xb4)=I(0xb5)=0; ++I(0xaa);
}
void egs51_crossover_fill(Egs51 *s) { /* 4667..4BC8, all seven substates */
    uint16_t low=egs51_handoff_low_pressure(s,I(0xb6));
    uint16_t high=egs51_handoff_high_pressure(s,I(0xb6)),cal=XW(0x3c6);
    switch(I(0xb4)) {
    case 0:
        I(0xb0)=egs51_fill_term(s); ++I(0xb4); I(0x96)&=0xef; I(0x98)&=0xfd;
        /* fall through */
    case 1:
        apply(s,egs51_handoff_clutch_pressure(s,high));
        if(!I(0xb0)) {
            I(0xb0)=R(cal+0x22); if(I(0x99)&4) I(0x98)|=2;
            if(IW(0xad)<RW(cal+2+2*I(0xac)) && (I(0xb9)<X(0x334) || (I(0x95)&8))) {
                I(0x98)&=0xfd; I(0x96)|=0x10; I(0xb4)=4;
            } else ++I(0xb4);
        }
        fill_mod(s,low,0); break;
    case 2:
        apply(s,egs51_lag(IW(0x46),egs51_handoff_clutch_pressure(s,low),I(0xb0)));
        if(!I(0xb0)) { I(0xb0)=R(cal+0x23+I(0x56)); ++I(0xb4); }
        fill_mod(s,low,1); break;
    case 3:
        apply(s,egs51_handoff_clutch_pressure(s,low));
        if(!I(0xb0)) I(0xb4)=0;
        fill_mod(s,low,1); break;
    case 4: case 5: case 6: {
        uint8_t phase=I(0xb4);
        uint16_t p=phase==4?0:RW(cal+(phase==5?0x3f:0x41));
        apply(s,egs51_lag(IW(0x46),egs51_crossover_clutch_pressure(s,p),I(0xb0)));
        if(!I(0xb0)) {
            if(phase==6) I(0xb4)=0;
            else { I(0xb0)=R(cal+(phase==4?0x32:0x33)); ++I(0xb4); }
        }
        IP(0x44,egs51_crossover_free_pressure(s,(uint8_t)(I(0xac)-1))); break;
    }
    default: break;
    }
    if(!IW(0xb7) || !I(0xb0)) { fill_complete(s); return; }
    if(I(0xb4)<=3) {
        if(IW(0xad)>=R(cal+0x28) || (I(0x98)&1) ||
           signed16(XW(0x2bb))<=signed16(RW(XW(0x3ca)+0x20))) return;
        if(((I(0x95)&8) && signed16(XW(0x1fd))>R(cal+0x4f)) ||
           ((I(0x95)&0x10) && signed16(XW(0x1fd))<-(int32_t)R(cal+0x4f))) fill_complete(s);
    } else if(signed16(XW(0x357))<signed16(RW(XW(0x3ca)+0x20)) ||
              signed16(XW(0x1fd))>=signed16(md(150,RW(cal+2+2*I(0xac)),100))) fill_complete(s);
}
void egs51_crossover_momentum_target(Egs51 *s) { /* 6DC6..6E98 */
    uint16_t old=XW(0x37b);
    uint16_t next=(uint16_t)(6u*md(egs51_shift_factor(s),RW(0x1040+2*I(0xb9)),1000));
    next=md(next,XW(0x203),1000);
    next=egs51_signed_md(next,XW(0x213),XW(0x181));
    if(I(0x95)&0x10) { if(signed16(next)<signed16(old)) next=old; }
    else if(signed16(next)>signed16(old)) next=old;
    XP(0x37b,next);
}
uint16_t egs51_crossover_transfer_mod(const Egs51 *s,uint8_t idx) { /* 7851 */
    uint16_t off=md(sub(IW(0xad),XW(0x1d6)),IW(0x54),R(0xffd0));
    off=md(sub((uint16_t)(off+IW(0x4c)),IW(0x50)),R(XW(0x3be)+5+idx),100);
    return egs51_overlap_pressure(s,idx,IW(0x46),off);
}
uint16_t egs51_crossover_transfer_apply(const Egs51 *s) { /* 78F6 */
    uint16_t t=(uint16_t)(IW(0xad)+XW(0x378)-XW(0x2fd));
    if(signed16(t)<0) t=0;
    uint16_t p=sub((uint16_t)(md(IW(0x52),t,X(0x2ab))+IW(0x4a)),IW(0x4e));
    return minp(maxp(p,sub(XW(0x2dc),IW(0x4e))),XW(0x273));
}
uint16_t egs51_crossover_spring_mod(const Egs51 *s,uint8_t idx,uint16_t on) { /* 7D75 */
    uint16_t off=md(sub(IW(0x4c),IW(0x50)),R(XW(0x3be)+5+idx),100);
    return egs51_overlap_pressure(s,idx,on,off);
}
void egs51_crossover_transfer(Egs51 *s) { /* 9470..96BA */
    uint16_t cal=XW(0x3ca);
    uint8_t idx=(uint8_t)(I(0xac)-1);
    egs51_applying_capacity(s,IW(0x46),X(0x2ab));
    if(!I(0xb4)) {
        I(0x95)|=0x40; XP(0x2dc,IW(0x46)+IW(0x4e));
        egs51_crossover_momentum_target(s);
        I(0xb0)=(I(0x98)&0x20)?R(cal+0x37):(uint8_t)egs51_lerp(R(cal+0x22),R(cal+0x23),RW(cal+0x26),RW(cal+0x28),IW(0xad));
        ++I(0xb4);
    }
    if(I(0xb4)==1) {
        if(I(0x95)&0x10) egs51_crossover_momentum_target(s);
        egs51_shift_pressure_compensation(s);
        uint16_t target=egs51_crossover_transfer_apply(s);
        apply(s,egs51_lag(IW(0x46),target,I(0xb0)));
        uint8_t gearidx=I(0xac)<=4?I(0xac)-1:I(0xac)-5;
        if(IW(0xad)<md(150,RW(XW(0x3c6)+4+2*gearidx),100) && (I(0x96)&0x10))
            IP(0x44,egs51_crossover_free_pressure(s,idx));
        else {
            I(0x96)&=0xef;
            if((IW(0xad)<RW(XW(0x3ba)+2*I(0xac)) && (I(0x98)&2)) || (I(0x96)&0x20))
                IP(0x44,egs51_crossover_free_pressure(s,idx));
            else {
                I(0x98)&=0xfd;
                target=maxp(XW(0x2dc),target);
                IP(0x44,maxp(egs51_crossover_spring_mod(s,idx,target),egs51_crossover_transfer_mod(s,idx)));
            }
        }
    }
    if(!IW(0xb7) || !I(0xb0) || signed16(XW(0x2bb))>signed16(RW(cal+0x20))) { I(0xb4)=0; ++I(0xaa); }
}
uint16_t egs51_crossover_match_mod(const Egs51 *s,uint8_t idx) { /* 80BC */
    uint16_t cal=XW(0x3ce);
    uint16_t p=minp(sub((uint16_t)(md(IW(0xad),IW(0x52),R(0xffd0))+IW(0x4a)),IW(0x4e)),XW(0x273));
    p=md(p,RW(cal+7+2*idx),1000);
    uint16_t off=md(md(IW(0x50),RW(cal+0x17+2*idx),1000),R(XW(0x3be)+5+idx),100);
    p=sub(p,off);
    uint16_t spring=RW(cal+0x27+2*idx);
    p=signed16(spring)<0?sub(p,(uint16_t)(0-spring)):(uint16_t)(p+spring);
    return minp(p,XW(0x329));
}
uint16_t egs51_crossover_match_apply(const Egs51 *s) { /* 844E */
    uint16_t t=(uint16_t)(IW(0xad)+XW(0x1d8)+XW(0x384)+XW(0x378)-XW(0x2fd));
    if(signed16(t)<0) t=0;
    uint16_t p=sub((uint16_t)(md(t,IW(0x52),R(0xffd1))+IW(0x4a)),IW(0x4e));
    return minp(maxp(p,sub(XW(0x2dc),IW(0x4e))),XW(0x273));
}
void egs51_crossover_match(Egs51 *s) { /* 99C7..9A6A */
    IP(0x44,egs51_crossover_match_mod(s,(uint8_t)(I(0xac)-1)));
    if(!I(0xb4)) {
        I(0x95)&=0xbf; I(0xb0)=R(0xffce);
        I(0xb1)=(uint8_t)(I(0xb0)+R(0xffb1)+egs51_lerp(R(0xffb2),R(0xffbe),R(0xffb3),R(0xffb4),X(0x76)));
        ++I(0xb4);
    }
    if(I(0xb4)==1) {
        apply(s,egs51_lag(IW(0x46),egs51_crossover_match_apply(s),I(0xb0)));
        if(!I(0xb0)) { I(0xb0)=R(0xffb1); ++I(0xb4); }
    } else if(I(0xb4)==2) apply(s,egs51_lag(IW(0x46),XW(0x273),I(0xb0)));
    if(!I(0xb1)) { I(0xb4)=0; ++I(0xaa); }
}
