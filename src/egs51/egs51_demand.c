/* A0215451432 bank0 7331..8813, normal gear-demand selector. */
#include "egs51_internal.h"
static uint16_t maximum(uint16_t a,uint16_t b) { return a>b?a:b; }
static uint16_t subtract_floor(uint16_t a,uint16_t b) { return a>b?(uint16_t)(a-b):0; }
static int feature(Egs51 *s,unsigned bit) { return B(0xfc35)&(1u<<(bit+((X(0x1c6)&1)?4:0))); }
static uint8_t curve_axis(Egs51 *s,uint16_t desc,unsigned offset,unsigned skip) {
    return B(BW(desc+offset)+(uint16_t)(B(desc+1)-1u-skip));
}
static uint16_t polynomial(Egs51 *s,unsigned index,unsigned base,uint8_t input) {
    uint16_t square=md(B(base+16+index),(uint16_t)(input*input),100);
    uint16_t sum=(uint16_t)(100u*B(base+index)+square+input*B(base+8+index));
    return md(sum,XW(0x270),1000);
}
void egs51_gear_demand(Egs51 *s) {
    S(0x98)=0xdf;
    X(0x219)=XW(0x2d4)<2500?(uint8_t)(XW(0x2d4)/10):250;
    XP(0x23e,((uint32_t)XW(0x23e)*B(0xfc74)+(uint16_t)(XW(0x275)*8u))/(B(0xfc74)+1u));
    if(I(0xb9)>=6) goto finish;
    uint8_t gear=I(0xb9)?I(0xb9):I(0xab);
    X(0x227)=I(0xab)=gear;
    unsigned down=gear==1?0:(uint8_t)(gear-2),up=gear==5?3:(uint8_t)(gear-1);
    X(0x2eb)=(uint8_t)down; X(0x2d1)=(uint8_t)up;
    uint16_t maps=XW(0x3aa),limits=XW(0x3a8),eco=XW(0x3ae);
    unsigned mapoffset=(X(0x1c6)&4)?16:0;
    uint16_t downmap=BW(maps+mapoffset+2u*down),upmap=BW(maps+mapoffset+8+2u*up);
    uint8_t ratio=B(0xfc79+gear);
    uint16_t downbase=(uint16_t)(B(BW(downmap+4))*ratio);
    XP(0x2c1,B(BW(upmap+4))*ratio);
    if(!I(0xb9)) { XP(0x21f,0); XP(0x242,0); goto maps; }
    X(0x353)=0; XP(0x1ec,0); XP(0x2e9,0);
    if(feature(s,2)) {
        X(0x1cc)=egs51_curve8(s,0,0xedfe,X(0x7c));
        if(X(0x184)!=3) X(0x353)=(uint8_t)md(X(0x1cc),egs51_curve8(s,0,maps+0x20,X(0x285)),1000);
        else XP(0x2e9,md(X(0x1cc),BW(limits+0x48),100));
        if((signed16(XW(0x1f3))>=signed16(BW(eco+5)) || X(0x7c)<=B(eco+9)) &&
           X(0x39d)>=curve_axis(s,downmap,2,B(0xfc69+down))) {
            uint16_t p=BW(XW(0x3b6)+0x2f+2u*down);
            if(p>downbase) XP(0x1ec,p-downbase);
        }
    }
    egs51_vehicle_acceleration(s); egs51_road_load(s); egs51_load_scale(s); egs51_load_corrections(s);
    egs51_load_bias(s); egs51_load_feedback(s); egs51_demand_activity(s); egs51_coast_hold(s);
    XP(0x2c7,0);
    uint16_t boost=BW(limits+5+2u*down);
    if(feature(s,1) && boost) {
        uint16_t pedal=(uint16_t)(curve_axis(s,downmap,2,B(0xfc69+down))+X(0x353));
        if(signed16(XW(0x224))>0) {
            if(signed16(XW(0x224))<=B(0xfc6d)) X(0x312)=X(0x285);
            uint16_t floor=(uint16_t)(curve_axis(s,downmap,4,B(0xfc69+down))*ratio),position;
            if(XW(0x2ac)>boost) position=0;
            else if(XW(0x2ac)<floor) position=100;
            else position=md((uint16_t)(XW(0x2ac)-floor),100,(uint16_t)(boost-floor));
            XP(0x39f,md(egs51_curve16(s,0,0xedf2,position),B(limits+13+down),100));
            XP(0x1cd,egs51_curve8(s,0,0xedf8,X(0x312)));
            XP(0x39f,md(XW(0x39f),XW(0x1cd),100));
            if(signed16(XW(0x224))>signed16(XW(0x39f)) && !(X(0x1c7)&0x10)) X(0x35f)=B(0xfc46);
        } else X(0x312)=X(0x285);
        if(X(0x35f) && X(0x39d)>=pedal) XP(0x2c7,boost-downbase);
        if(signed16(XW(0x213))<signed16(BW(limits+3)) && X(0x285)>pedal) {
            if(!XW(0x354)) XP(0x2c7,boost-downbase);
        } else XP(0x354,BW(0xfc47));
    }
    XP(0x2e3,0); XP(0x2af,0);
    if(feature(s,3)) {
        if(X(0x1ca)&2) X(0x20e)=B(0xfc80);
        else if(X(0x76)<B(0xfc38)) X(0x20e)=0;
        else if(X(0x76)>B(0xfc39)) X(0x20e)=150;
        else X(0x20e)=(uint8_t)md(150,(uint16_t)(X(0x76)-B(0xfc38)),(uint16_t)(B(0xfc39)-B(0xfc38)));
        X(0x346)=X(0x20e)>10u*X(0x328)?X(0x20e):(uint8_t)(10u*X(0x328));
        uint8_t demand=X(0x20e);
        if(X(0x1c7)&8) demand=X(0x346);
        else if((X(0x1c5)&8) && X(0x328) && !downbase) demand=10;
        X(0x1bc)&=0xfd;
        if(X(0x346)) {
            XP(0x2af,subtract_floor(polynomial(s,up,0xfc4d,X(0x346)),XW(0x2c1)));
            if(demand) {
                uint16_t p=polynomial(s,down,0xfc51,demand); XP(0x2e3,p);
                if(p>XW(0x2ac) && (signed16(XW(0x1f3))>signed16(BW(0xfc77)) || (X(0x1c7)&8))) X(0x1bc)|=2;
                XP(0x2e3,subtract_floor(p,downbase));
            }
        }
    }
    if(feature(s,0)) {
        if(XW(0x23e)>XW(0x1e2) && X(0x285)>B(0xfc81) && !I(0xb6)) {
            uint16_t next=md((uint16_t)(XW(0x23e)-XW(0x1e2)),XW(0x31c),8);
            XP(0x1e0,((uint32_t)XW(0x1e0)*B(0xfc6f)+next)/(B(0xfc6f)+1u));
        } else XP(0x1e0,0);
        uint8_t scale;
        if(X(0x76)<=B(0xfc3a)) scale=100;
        else if(X(0x76)>=B(0xfc3b)) scale=0;
        else scale=(uint8_t)md(100,(uint16_t)(B(0xfc3b)-X(0x76)),(uint16_t)(B(0xfc3b)-B(0xfc3a)));
        XP(0x1e2,XW(0x23e)); XP(0x310,md(scale,BW(limits+0x31+2u*down),100));
    }
    XP(0x242,maximum(maximum(XW(0x2e3),XW(0x2c7)),maximum(XW(0x244),XW(0x1ec))));
    XP(0x21f,maximum(maximum(XW(0x2af),XW(0x221)),XW(0x238)));
    XP(0x310,XW(0x310)+md(XW(0x2e9),1000,BW(0x1042+2u*down)));
    if((X(0x1bc)&3) || ((X(0x1bc)&4) && I(0xb6))) X(0x1bc)|=4;
    else {
        X(0x1bc)&=0xfb;
        if(X(0x285)<B(BW(downmap+2)+B(0xfc65+down))) XP(0x242,0);
    }
maps:
    X(0x39d)=X(0x285)>X(0x353)?(uint8_t)(X(0x285)-X(0x353)):0;
    uint8_t input=X(0x39d);
    uint16_t base=egs51_curve8(s,0,downmap,input);
    if(!(X(0x1c6)&4)) {
        uint16_t high=egs51_curve8(s,0,BW(maps+0x26+2u*down),input);
        if(high>base) base=(uint16_t)(base+md((uint16_t)(high-base),XW(0x27a),250));
    }
    XP(0x2c3,base*ratio);
    uint16_t previous_input=input;
    if((X(0x1c6)&4) && X(0x2ce)!=gear) {
        previous_input=(uint16_t)(X(0x39d)+X(0x38e));
        base=egs51_curve8(s,0,BW(maps+0x18+2u*up),(uint8_t)previous_input); X(0x2ce)=0;
    } else {
        uint16_t high=egs51_curve8(s,0,BW(maps+0x2e + 2u*up),(uint8_t)previous_input);
        previous_input=(uint16_t)(X(0x39d)+X(0x38e));
        base=egs51_curve8(s,0,BW(maps+8+2u*up),(uint8_t)previous_input);
        if(high>base) base=(uint16_t)(base+md((uint16_t)(high-base),XW(0x27a),250));
    }
    XP(0x290,base*ratio);
    if(XW(0x290) || X(0x20e)>B(0xfc7f) || X(0x328)) XP(0x290,maximum(XW(0x290),(uint16_t)(XW(0x2c1)+XW(0x21f))));
    if(XW(0x2c3) || X(0x20e)>B(0xfc7f) || X(0x328)) XP(0x2c3,maximum(XW(0x2c3),(uint16_t)(downbase+XW(0x242))));
    if(!I(0xb6) && X(0x2ff)==9 && X(0x342)==5 && (X(0x1bc)&0x10) && gear<5) { I(0xab)=gear+1; X(0x1be)|=4; }
    else X(0x1be)&=0xfb;
    X(0x342)=X(0x2ff); flag(&X(0x1bc),0x10,X(0x334)==5);
    unsigned offset=(X(0x1c6)&4)?0x21:0x11;
    uint16_t downlimit=BW(limits+offset+2u*down),uplimit=BW(limits+offset+8+2u*up);
    if(X(0x1c6)&4) previous_input=XW(0x2c3);
    if(downlimit>XW(0x310)) downlimit=(uint16_t)(downlimit-XW(0x310));
    if(X(0x1c5)&0x80) { XP(0x2c3,downlimit); XP(0x290,uplimit); }
    else {
        if(XW(0x2ac)>downlimit) XP(0x2c3,downlimit);
        if(B(eco+1+down) && XW(0x27a)<B(eco+8) && signed16(XW(0x1f3))<signed16(BW(eco+5)) && !(X(0x1c7)&8)) {
            uint16_t p=md(B(eco+1+down),XW(0x270),10);
            if(XW(0x2ac)>p && XW(0x2c3)>p) XP(0x2c3,p);
        }
    }
    if(gear<4 && B(eco+2+down) && XW(0x27a)<B(eco+8) && signed16(XW(0x1f3))<signed16(BW(eco+5)) && !(X(0x1c7)&8)) {
        uint16_t p=md(B(eco+2+down),XW(0x270),10);
        if(XW(0x2ac)>p && XW(0x2c3)>p) XP(0x2c3,p);
    }
    if(XW(0x2ac)<XW(0x2c3) && XW(0x391)<BW(limits+1)) { if(gear>1) I(0xab)=gear-1; }
    else if(XW(0x2ac)>=XW(0x290) || XW(0x275)>(uint16_t)(BW(limits+1)-XW(0x1e0)-XW(0x2e9))) { if(gear<5) I(0xab)=gear+1; }
    else if(!!(X(0x1c6)&4)!=!!(X(0x1bc)&0x80) && !XW(0x2c3) && gear==1) I(0xab)=2;
    if((X(0x1c6)&4) && !(X(0x1c5)&0x40) && XW(0x2ac)>previous_input) {
        if((X(0x1c5)&0x80) && XW(0x2ac)<XW(0x2c3)) X(0x2ce)=I(0xab);
    } else X(0x2ce)=0;
    if(XW(0x2ef)<BW(0xfc3e) && (X(0x334)>5 || I(0xb6)==6 || I(0xb6)==5) &&
       !!(X(0x1c6)&4)==!!(X(0x1bc)&0x80)) I(0xab)=gear;
    if(!I(0xaa)) flag(&X(0x1bc),0x80,X(0x1c6)&4);
    if(X(0x1c5)&2) {
        if(XW(0x275)>=(uint16_t)(BW(limits+1)-XW(0x1e0)) || XW(0x2ac)<=downbase || (X(0x1bc)&8)) X(0x1bc)|=8;
        else if(!I(0xb6)) I(0xab)=I(0xb9);
        else if(I(0xb6)<5 && I(0xaa)<2 && (!(I(0x95)&0x20) || I(0xb5)<2)) I(0xab)=X(0x1fa);
    }
    if(!I(0xb6)) { X(0x1fa)=I(0xb9); X(0x1bc)&=0xf7; }
    if(I(0xab)==1 && (X(0x1c5)&1) && X(0x334)<=5 && I(0xb6)!=6 && I(0xb6)!=5) I(0xab)++;
    uint16_t vehicle=XW(0x3a4);
    if(X(0x219)>=B(vehicle+0x29) && X(0x219)<B(vehicle+0x2a) && I(0xb9)==4 && I(0xab)==3 && !(X(0x1c5)&0x80) && (I(0x95)&0x10)) I(0xab)=4;
    if(X(0x334)==3 && I(0xb9)==3 && I(0xab)==2 && (X(0x1c5)&0x80) && X(0x219)<B(eco+11)) {
        if(!(X(0x1bd)&0x80)) { X(0x1bd)|=0x80; X(0x37a)=B(eco+10); }
    } else X(0x1bd)&=0x7f;
    if(X(0x37a)) I(0xab)=I(0xb9);
finish:
    flag(&X(0x1bd),0x40,XW(0x29d)<=6 && XW(0x27a)<=25);
}
