/* Native startup of the bank0 normal controller, 6EC2..7137. */
#include "egs51_internal.h"
uint8_t egs51_controller_init(Egs51 *s) {
    uint8_t result=egs51_cal_select_bank0(s);
    XP(0x203,XW(0x17f)); I(0xb9)=I(0xab)=I(0xa9)=I(0xb3)=1;
    X(0x223)=1; X(0x202)=10;
    egs51_vehicle_flags(s);
    X(0x334)=X(0x1e8)=X(0x3a3)=X(0x75);
    flag(&X(0x1c6),5,I(0x20)&4); X(0x1c7)|=0x40;
    egs51_target_step(s);
    I(0x9a)|=7; I(0x94)&=0xf3; X(0x1c2)|=1; I(0xac)=I(0xb6)=0;
    X(0x34f)=I(0x86); X(0x2c0)=X(0x183)==1?B(0xffa4):X(0x183)==2?B(0xffa5):100;
    XP(0x340,IW(0x87)); XP(0x275,IW(0x87));
    XP(0x31e,25u*XW(0x81)); XP(0x33e,25u*XW(0x84));
    XP(0x2ef,((uint16_t)(25u*XW(0x89))>>1)+((uint16_t)(25u*XW(0x87))>>1));
    egs51_wheel_inputs(s); egs51_clutch_speeds(s); XP(0x1da,XW(0x22f));
    X(0x335)=B(0xfc49); X(0x264)=0; XP(0x25c,0); X(0x265)=0;
    X(0x246)=B(0xfe12); X(0x383)=B(0xfe78);
    if((X(0x179)&15)==15 || (X(0x120)&0x40)) X(0x246)=0;
    uint32_t count=(((uint32_t)XW(0x169)<<16)|XW(0x16b))+B(0xff6b);
    XP(0x28a,count>>16); XP(0x28c,count);
    XP(0x381,BW(0xff58)); X(0x388)=B(0xff6a); X(0x1bf)|=2; X(0x218)=2;
    XP(0x270,md(XW(0x203),1667,XW(0x181))); X(0x1bc)&=0x7f;
    X(0x300)=X(0x75); XP(0x22b,10000); egs51_gear_qualification(s);
    X(0x377)=B(0xfc36); XP(0x27a,0); I(0xb9)=I(0xb3)=I(0xa9);
    if((X(0x1c6)&0x20) && (I(0xb9)==1 || I(0xb9)==6)) I(0x95)|=1;
    return result;
}

uint8_t egs51_pressure_init(Egs51 *s) { /* bank1 10BA..10F7 */
    uint8_t result=egs51_cal_select(s);
    XP(0x329,RW(RW(0xea86)+2u*(uint8_t)(R(0xea83)-1)));
    return result; /* cross-bank 0BF3 only writes compiler scratch */
}
void egs51_selector_inputs(Egs51 *s) { /* bank0 1DD0..1EA0 */
    unsigned pins=S(0xf8);
    flag(&I(0x2e),4,pins&0x20); flag(&I(0x2e),8,pins&0x10);
    if(!!(pins&0x20)==!!(I(0x20)&2)) {
        if(!X(2)) flag(&I(0x20),1,!(pins&0x20));
    } else { X(2)=2; flag(&I(0x20),2,pins&0x20); }
    if(!!(pins&0x10)==!!(I(0x20)&8)) {
        if(!X(1)) flag(&I(0x20),4,pins&0x10);
    } else { X(1)=3; flag(&I(0x20),8,pins&0x10); }
    if(X(0x6e)&0x80) { I(0x24)&=0xfe; X(0x6f)&=0xfe; }
    else {
        S(0xa0)&=0xfd;
        if(X(3)>=6) {
            X(4)=X(0); X(3)=0; S(0xa0)|=2;
            X(4)=B(0x31b2+X(4));
            if((X(4)&0xf0)==0xf0) { I(0x23)|=0x80; I(0x24)&=0xfe; }
            else {
                I(0x23)&=0x7f;
                if(X(4)==0xaa) I(0x24)|=1;
                else { X(0x75)=X(4); I(0x24)&=0xfe; }
            }
        } else S(0xa0)|=2;
        if(X(0x78)&8) { I(0x23)&=0x7f; I(0x24)&=0xfe; }
    }
    X(0x77)=B(0x31b2+(S(0xf8)&15));
}
void egs51_platform_timers(Egs51 *s) { /* bank0 6CF8..6DCA */
    static const uint16_t cells[]={0xfa,0xfb,0x6a,0x36,0xc,0xd,0xe,0x103,0x106,
        0x1a8,0x1b3,0x1a3,0x1ad,0x1c,0x1b,2,1,0xa6};
    for(unsigned k=0;k<sizeof(cells)/sizeof(cells[0]);k++) if(X(cells[k])) X(cells[k])--;
    for(unsigned k=B(0x3051);k>0;k--) if(X(0xb3+k-1)) X(0xb3+k-1)--;
    decword(&X(0x1b9)); if(X(0xb2)<255) X(0xb2)++;
}
void egs51_starter_interlock(Egs51 *s) { /* bank0 5880..58E7 */
    int allow=0;
    if(!X(0x1a8)) {
        int park_neutral=X(0x75)==6 || X(0x75)==8;
        if(!(X(0x6f)&4)) allow=(I(0x20)&0x10) &&
            (park_neutral || (X(0x6f)&1) || (X(0x6e)&0x80) || (X(0x78)&8));
        else allow=((I(0x20)&0x10) || (I(0x2b)&0x40)) && park_neutral &&
            !(X(0x6e)&0x80) && !(X(0x6f)&1) && !(I(0x23)&0x80) && !(I(0x24)&1);
    }
    flag(&I(0x20),0x40,allow);
}
void egs51_voltage_qualification(Egs51 *s) { /* bank0 58E8..5934 */
    unsigned v=I(0x80);
    flag(&X(0x78),8,v<0x55); if(v<0x55) X(0x1a3)=B(0xff34);
    flag(&I(0x24),8,(X(0x6f)&8)?(v<=0x5a || v>=0xa4):(v<0x55 || v>0xa9));
}
void egs51_analog_reference_fault(Egs51 *s) { /* bank0 6312..6338 */
    flag(&I(0x23),2,!(X(0x78)&8) && (X(0x1e)<0xa0 || X(0x1e)>0xf0));
}
void egs51_analog_supply_fault(Egs51 *s) { /* bank0 6339..6378 */
    int delta=(int)I(0x80)-X(0x21); if(delta<0) delta=-delta;
    flag(&I(0x23),1,(X(0x78)&2)?X(0x21)>30:delta>20);
}
void egs51_output_enable_monitor(Egs51 *s) { /* bank0 57EC..5820 */
    if(X(0x1b7)>2) return;
    flag(&I(0x22),0x40,!!(S(0x80)&0x40)==!!(S(0x96)&0x10));
    if(X(0x6d)&0x40) I(0x20)&=0x7f;
    flag(&S(0x80),0x40,I(0x20)&0x80);
}
void egs51_starter_output_monitor(Egs51 *s) { /* bank0 5821..587F */
    if(X(0x1b7)<=2) {
        flag(&I(0x2b),0x20,S(0xf8)&0x40);
        flag(&I(0x22),0x80,!(S(0x88)&0x20) && (S(0xf8)&0x45)==0x45);
        if(X(0x6d)&0x80) I(0x20)&=0xbf;
        flag(&S(0x88),0x20,!(I(0x20)&0x40));
    }
    if(X(0x1b3)) {
        flag(&X(0x90),8,I(0x20)&0x10); flag(&X(0x90),2,I(0x20)&0x40);
    }
}
void egs51_supply_temperature_band(Egs51 *s) { /* bank0 1FC6..206D */
    unsigned voltage=X(0x21)<126?2:X(0x21)>145?0:1;
    unsigned temperature=(X(0x6f)&4)?2:X(0x76)<70?0:X(0x76)<170?1:2;
    X(0xb)=voltage+temperature;
}
uint8_t egs51_solenoid_fault_monitor(Egs51 *s) { /* bank0 1EA1..1FC5 */
    S(0xa0)&=0xfb;
    static const unsigned shifts[]={0,2,4},commands[]={0x10,0x20,4},faults[]={2,4,1},timers[]={0xd,0xe,0xc};
    for(unsigned k=0;k<3;k++) {
        unsigned pair=(X(0x10)>>shifts[k])&3;
        int on=!!(I(0x2a)&commands[k]);
        if((on && pair==0) || (!on && (pair&2))) I(0x22)&=(uint8_t)~faults[k];
        else if(!X(timers[k])) I(0x22)|=faults[k];
    }
    unsigned pair=X(0x10)&0xc0;
    if(X(0x11)==2) flag(&I(0x22),8,pair!=0);
    else if(X(0x11)==3) flag(&I(0x22),8,pair&0x40);
    else if(X(0x11)==1) flag(&I(0x22),8,!(pair&0x80));
    if(!(X(0xf)&2) && !(X(0x74)&2) && !(I(0x29)&2) &&
       (X(0xf)&1) && !(X(0x73)&0x80) && !(I(0x28)&0x80)) {
        X(0x3fe)=0xc3;
        return 0; /* OEM halts at 1FB2; caller must handle this terminal outcome. */
    }
    if(X(0x78)&2) I(0x22)&=0xf0;
    S(0xa0)|=4;
    return 1;
}
