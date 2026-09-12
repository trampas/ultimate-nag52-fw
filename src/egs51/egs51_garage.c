/* A0215451432 mode5 engagement selection and preparation, bank1. */
#include "egs51_internal.h"
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p)); }
void egs51_garage_select(Egs51 *s) { /* 575D..5905 */
    I(0xb4)=I(0xb5)=0; I(0x9a)&=0xdf; I(0x97)&=0xfe;
    uint8_t from=I(0xab),target=X(0x334);
    if(from<=2 && I(0xac)!=6 && !(I(0x9a)&0x12)) I(0x95)|=4;
    if((I(0x9a)&0x10) && !(I(0x94)&0x80) && (target<=5 || target==7 || (I(0x96)&4))) { I(0x96)&=0xfb; I(0x94)|=0x80; }
    if(((X(0x1bd)&2) && target!=7) || ((X(0x1bd)&1) && target>=6) || (X(0x1c2)&2)) { I(0xaa)=5; return; }
    if(I(0x9a)&2) {
        if((from==1 && (X(0x1c6)&0x20)) || ((from==1 || from==5) && XW(0x1f6)>RW(0xff81))) I(0xaa)=3;
        else I(0xaa)=1;
        return;
    }
    if(I(0xac)==7 || I(0xac)==8) { I(0xaa)=5; return; }
    if(!(I(0x9a)&0x10) && (I(0xac)!=6 || (X(0x1c6)&0x20))) I(0x95)|=4;
    if(X(0x1c8)&0x20) { I(0xaa)=4; return; }
    if(from==1 || from==5) I(0xaa)=XW(0x1f6)>RW(0xff81)?3:1;
    else {
        uint16_t speed=(uint16_t)(XW(0x1f0)-XW(0x1f6));
        if(signed16(speed)<0) speed=(uint16_t)(0-speed);
        I(0xaa)=signed16(speed)>signed16(RW(0xff81))?3:1;
    }
}
void egs51_garage_release(Egs51 *s) { /* 5906..59FB */
    if(!I(0xb4)) { I(0xb0)=R(0xff75); IP(0xb7,RW(0xff99)); ++I(0xb4); }
    if(I(0xb4)!=1) return;
    IP(0x44,egs51_lag(IW(0x44),RW(0xff87),I(0xb0)));
    apply(s,egs51_lag(IW(0x46),3000,I(0xb0)));
    if(I(0xb0)) return;
    I(0x95)&=0xfc; I(0x9a)&=0xf5;
    if((!(X(0x1bd)&2) && X(0x334)<=5) || (!(X(0x1bd)&1) && X(0x334)==7)) {
        if(XW(0x275)<RW(XW(0x3b2)+0x3e)) { I(0xaa)=I(0xb4)=I(0xb5)=0; I(0x9a)|=8; }
        else apply(s,500);
    } else I(0xaa)=I(0xb4)=I(0xb5)=0;
}
void egs51_garage_prefill(Egs51 *s) { /* 59FC..5B9B */
    uint16_t mech=XW(0x3d4),cal=XW(0x3c6);
    I(0x56)=0; IP(0x52,RW(mech+1+12*I(0xb9))); IP(0x4a,RW(mech+0x71));
    IP(0x4e,egs51_speed_pressure(s,0)); IP(0x44,RW(0xff87));
    switch(I(0xb4)) {
    case 0:
        I(0x95)|=1;
        I(0xb0)=(uint8_t)(md(R(XW(0x3b2)+3),egs51_fill_term(s),100)+R(cal+0x22)+R(cal+0x23));
        I(0xb2)=R(0xffa3); ++I(0xb4);
        /* fall through */
    case 1:
        apply(s,egs51_handoff_clutch_pressure(s,RW(cal+0x43)));
        if(!I(0xb0)) { I(0xb1)=R(0xff79); I(0xb0)=(uint8_t)(I(0xb1)+egs51_hold_time(s)); ++I(0xb4); }
        break;
    case 2:
        apply(s,egs51_lag(IW(0x46),(I(0x9a)&0x80)?XW(0x273):RW(0xff89),I(0xb1)));
        if(!I(0xb1)) I(0x95)&=0xfe;
        if(!I(0xb0)) { I(0xb4)=0; I(0xaa)=1; }
        break;
    default: break;
    }
    if(!I(0xb2) && !(I(0x9a)&0x10)) I(0x95)|=4;
}
void egs51_garage_inhibit(Egs51 *s) { /* 5B9C..5BB5 */
    IP(0x46,0); IP(0x48,0); if(!(X(0x1c8)&0x20)) I(0xaa)=0;
}
void egs51_fault_pressure(Egs51 *s) { /* A930..A97D */
    if(!I(0xb4)) { I(0xb0)=egs51_fill_time(s); ++I(0xb4); }
    if(I(0xb4)==1) { I(0x95)|=1; IP(0x44,egs51_mpc_line(s)); IP(0x46,XW(0x273)); IP(0x48,XW(0x329)); }
    if(!I(0xb0)) { I(0x95)&=0xfe; I(0xb6)=I(0xb4)=I(0xaa)=0; }
}
