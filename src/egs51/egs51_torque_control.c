/* A0215451432 bank1 CE9F..D76D. OEM torque-demand state machine.
 * Like the ROM, swaps the shared 44..4D workspace with XRAM2F3..2FC.
 */
#include "egs51_internal.h"
static uint16_t absword(uint16_t v) { return signed16(v)<0?(uint16_t)(0-v):v; }
static uint16_t minimum(uint16_t a,uint16_t b) { return a<b?a:b; }
static uint16_t remaining(uint16_t total,uint16_t reduction) { return total>reduction?total-reduction:0; }
static void ramp(Egs51 *s,uint16_t target,uint16_t reduction) {
    IP(0x48,egs51_lag(IW(0x48),target,I(0x45)));
    IP(0x46,egs51_lag(IW(0x46),reduction,I(0x45)));
}
void egs51_torque_control(Egs51 *s) {
    uint16_t cal=XW(0x3c2),target=XW(0x347),reduction=0,value,limit;
    for(unsigned k=0;k<10;k++) I(0x44+k)=X(0x2f3+k);
    if(I(0xb6)==1) {
        XP(0x2fd,0);
        if(target>=RW(cal+0x16)) {
            uint16_t desc=RW(XW(0x3d0)+2*I(0xac)-2);
            reduction=5u*egs51_map8(s,1,desc,(uint8_t)(XW(0x2ac)/30),(uint8_t)(IW(0xad)/5));
            if(reduction) {
                uint16_t momentum=(uint16_t)(XW(0x378)+XW(0x384));
                value=egs51_signed_md(R(cal+0x10),momentum,100);
                if(signed16(momentum)>0) {
                    limit=(uint16_t)(egs51_signed_md(R(cal+0x11),XW(0x347),100)-reduction);
                    if(signed16(limit)<0) limit=0;
                    XP(0x2fd,signed16(value)<signed16(limit)?value:limit);
                } else {
                    limit=(uint16_t)(0-reduction);
                    XP(0x2fd,signed16(value)>signed16(limit)?value:limit);
                }
            }
            reduction=(uint16_t)(reduction+XW(0x2fd));
            if(signed16(reduction)<0) reduction=0;
            target=remaining(XW(0x347),reduction);
        }
        switch(I(0x4d)) {
        case 0:
            I(0x45)=R(cal+8); IP(0x4a,0);
            if(I(0x97)&1) ++I(0x4d);
            else { IP(0x46,0); IP(0x48,I(0x45)?XW(0x347):target); }
            break;
        case 1:
            ramp(s,target,reduction);
            if(target>IW(0x48)) IP(0x48,target);
            if(!(I(0x97)&1)) { I(0x45)=R(cal+9); if(I(0x45)) I(0x97)|=1; ++I(0x4d); }
            break;
        case 2:
            if(!I(0x45)) { I(0x97)&=0xfe; I(0x4d)=0; }
            else { I(0x97)|=1; ramp(s,XW(0x347),0); }
            break;
        default: break;
        }
        IP(0x4a,(X(0x1bb)&1)?md(R(cal+0xf),IW(0x46),100):0);
    } else if(I(0xb6)==3) {
        switch(I(0x4d)) {
        case 0:
            IP(0x4a,0); IP(0x46,0); IP(0x48,target);
            if(I(0x97)&1) ++I(0x4d);
            break;
        case 1:
            if(target>=RW(cal+4) && X(0x397)) {
                reduction=(uint16_t)(absword(XW(0x2b9))-md(RW(XW(0x3d4)+0x57+2*I(0xac)),100,X(0x397)));
                reduction=minimum(reduction,md(RW(cal+6),XW(0x347),1000));
                target=remaining(XW(0x347),reduction);
            }
            IP(0x48,target); IP(0x46,reduction);
            if(I(0xb5)==2) { I(0x45)=egs51_release_ramp_time(s,I(0xac)); ++I(0x4d); }
            else if(!(I(0x97)&1)) I(0x4d)=0;
            break;
        case 2:
            value=egs51_shift_threshold(s,(uint8_t)(I(0xac)-1),R(XW(0x3ca)+2));
            if(signed16(XW(0x357))<signed16(value)) ++I(0x4d);
            else { ramp(s,target,reduction); if(!(I(0x97)&1)) I(0x4d)=0; }
            break;
        case 3:
            I(0x45)=R(cal+0xa); ++I(0x4d);
            /* OEM deliberately executes state4 in this same invocation. */
            /* fall through */
        case 4:
            if(XW(0x347)>=RW(cal+4)) {
                if(X(0x397)) {
                    reduction=md(XW(0x303),R(XW(0x3ca)+I(0xac)+9),X(0x397));
                    limit=RW(XW(0x3d4)+0x5f+2*I(0xac));
                    if(IW(0xad)>limit) {
                        value=remaining(absword(XW(0x2b9)),md(limit,100,X(0x397)));
                        if(value>reduction) reduction=value;
                    }
                    reduction=minimum(reduction,md(RW(cal+6),XW(0x347),1000));
                    target=remaining(XW(0x347),reduction);
                }
            } else I(0x45)=0;
            ramp(s,target,reduction);
            if(target>IW(0x48)) IP(0x48,target);
            if(!(I(0x97)&1)) { I(0x45)=R(cal+0xb); I(0x97)|=1; ++I(0x4d); }
            break;
        case 5:
            if(XW(0x347)<RW(cal+4)) I(0x45)=0;
            I(0x97)|=1; ramp(s,target,reduction);
            if(!I(0x45)) { I(0x97)&=0xfe; I(0x4d)=0; }
            break;
        default: break;
        }
        IP(0x4a,(X(0x1bb)&1)?0:IW(0x46));
    } else if(I(0xb6)<7) {
        I(0x4d)=0; IP(0x4a,0); XP(0x2fd,0); ramp(s,XW(0x347),0);
        if(!I(0x45) || !(I(0x97)&1)) { I(0x97)&=0xfe; I(0x45)=0; }
    }
    if(X(0x1c8)&2) {
        if(X(0x1cb)&8) X(0x1bb)|=1;
        if(!I(0x44) && !(X(0x1c5)&4) && IW(0x46)>0) {
            if(!(X(0x1bb)&1) && !(I(0x96)&4)) ++I(0x4c);
            X(0x1bb)|=1;
        }
    } else { I(0x44)=R(cal+0xe); X(0x1bb)&=0xfe; }
    for(unsigned k=0;k<10;k++) X(0x2f3+k)=I(0x44+k);
}
