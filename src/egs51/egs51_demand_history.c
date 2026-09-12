/* Bank0 9538..9B09: OEM demand history and filtered load feedback. */
#include "egs51_internal.h"
static uint16_t mag(uint16_t v) { return v&0x8000?(uint16_t)(0u-v):v; }
static uint16_t uavg(uint16_t old,uint16_t next,uint8_t n) { return (uint16_t)(((uint32_t)old*n+next)/(n+1u)); }
static uint16_t savg(uint16_t old,uint16_t next,uint8_t n) { return (uint16_t)((signed16(old)*n+signed16(next))/(n+1)); }
void egs51_demand_activity(Egs51 *s) { /* 9538..9876 */
    if((X(0x1c6)&1) || !(B(0xfc36)&2) || (X(0x1c7)&0x10)) {
        XP(0x27a,B(0xfcec)); for(unsigned a=0x247;a<0x251;a++) X(a)=0; XP(0x325,0); return;
    }
    unsigned slot=X(0x23d),cell=0x247+(uint8_t)(2u*slot);
    uint16_t divisor=BW(0xfcc9+(uint8_t)(2u*slot)); assert(divisor);
    XP(0x325,XW(0x325)-XW(cell)/divisor);
    uint16_t value;
    switch(slot) {
    case 0:
        value=(X(0x1c5)&0x20)?0:md(XW(0x2ef),mag(XW(0x213)),250);
        XP(0x247,uavg(XW(0x247),value,B(0xfcd4))); break;
    case 1:
        value=md(16u*I(0x86),mag((uint16_t)((int)X(0x205)-I(0x86))),20);
        XP(0x249,uavg(XW(0x249),value,B(0xfcd6))); X(0x205)=I(0x86); break;
    case 2: {
        uint16_t speed=egs51_curve8(s,0,0xee04,X(0x219));
        uint16_t accel=egs51_curve16(s,0,signed16(XW(0x213))>0?0xee0a:0xee28,mag(XW(0x213)));
        uint16_t load=egs51_curve16(s,0,0xee10,mag(XW(0x320)));
        value=md((uint16_t)(speed*accel),load,10);
        XP(0x24b,uavg(XW(0x24b),value,B(0xfcd8))); break;
    }
    case 3:
        value=(uint16_t)(XW(0x24d)+(uint16_t)(mag((uint16_t)((int)X(0x22a)-I(0xab)))*BW(0xfcdd)));
        XP(0x24d,md(value,BW(0xfcd9),(uint16_t)(BW(0xfcd9)+1))); X(0x22a)=I(0xab); break;
    default:
        value=(X(0x1c5)&0x20)?mag(XW(0x213)):0;
        value=(uint16_t)(XW(0x24f)+md(value,BW(0xfcdf),200));
        XP(0x24f,md(value,BW(0xfcdb),(uint16_t)(BW(0xfcdb)+1))); break;
    }
    XP(0x325,XW(0x325)+XW(cell)/divisor);
    X(0x23d)=slot<4?(uint8_t)(slot+1):0;
    value=XW(0x325)>BW(0xfcef)?(uint16_t)(XW(0x325)-BW(0xfcef)):0;
    XP(0x27a,value>250?250:value);
}
void egs51_load_bias(Egs51 *s) { /* 9877..99BC */
    if(mag(XW(0x2ed))<B(0xfce1) && mag(XW(0x1cf))<BW(0xfce2) &&
       XW(0x2d4)>BW(0xfce4) && !(X(0x1c5)&0x20) && !(X(0x1c7)&4)) {
        if(signed16(XW(0x1de))>0) XP(0x301,XW(0x301)-1);
        else if(signed16(XW(0x1de))<0) XP(0x301,XW(0x301)+1);
    } else XP(0x301,0);
    uint16_t step=egs51_curve16(s,0,0xee16,mag(XW(0x1de)));
    if(signed16(XW(0x301))<=signed16((uint16_t)(0u-BW(0xfce6)))) {
        XP(0x22b,XW(0x22b)+step); XP(0x301,0);
    } else if(signed16(XW(0x301))>=signed16(BW(0xfce6))) {
        XP(0x22b,XW(0x22b)-step); XP(0x301,0);
    }
    XP(0x2e1,md(XW(0x33e),XW(0x22b),10000));
}
void egs51_load_feedback(Egs51 *s) { /* 99BD..9B09 */
    XP(0x2cc,uavg(XW(0x2cc),(uint16_t)((XW(0x2e1)>>1)+(XW(0x31e)>>1)),B(0xfceb)));
    uint8_t weight=B(X(0x219)>B(0xfcee)?0xfcea:0xfce9);
    if((X(0x1c7)&4) || XW(0x2d4)<=BW(0xfce4)) { XP(0x1de,0); XP(0x320,0); return; }
    uint16_t old=XW(0x1de);
    XP(0x1de,savg(old,(uint16_t)(5u*(uint16_t)(XW(0x31e)-XW(0x2e1))),weight));
    uint16_t value=egs51_signed_md((uint16_t)(XW(0x1de)-old),XW(0x181),1500);
    XP(0x2ed,savg(XW(0x2ed),value,B(0xfce8)));
    value=egs51_signed_md(XW(0x1de),XW(0x2cc)>>1,BW(XW(0x3a4)+0x21)>>1);
    XP(0x320,savg(XW(0x320),value,B(0xfd4f)));
}

void egs51_coast_hold(Egs51 *s) { /* 9B0A..9F22 */
    if(!(B(0xfc36)&((X(0x1c6)&1)?0x10:1))) { XP(0x238,0); XP(0x2a5,0); return; }
    uint16_t limit=BW(XW(0x3a8)+0x39+2u*X(0x2d1)),span=0,position=0;
    if(limit>XW(0x2ac) && limit>XW(0x2c1)) {
        span=(uint16_t)(limit-XW(0x2c1)); position=md((uint16_t)(limit-XW(0x2ac)),1000,span);
    }
    if(XW(0x29a)>BW(0xfd48) && !(X(0x1c7)&0x10) && X(0x334)>X(0x227) &&
       !(X(0x327)>I(0xab) && XW(0x2a5))) {
        if(signed16(XW(0x224))>=-(int)B(0xfc6d)) X(0x272)=X(0x285);
        uint16_t decay=0,pedal_decay=0,addition=0;
        if(signed16(XW(0x224))<signed16((uint16_t)(0u-egs51_curve16(s,0,0xee34,X(0x272))))) {
            if(!(I(0x95)&0x10) || (I(0xaa)>1 && !(I(0x96)&1))) {
                XP(0x2a5,BW(0xfd46)); X(0x2cb)=0;
            } else { X(0x1bc)|=0x40; XP(0x2a5,0); }
            XP(0x280,XW(0x2ac));
        } else if((I(0xab)>X(0x327) && XW(0x2a5)) || (X(0x1bc)&0x20)) XP(0x2a5,BW(0xfd46));
        else {
            if(X(0x285)>B(0xfd4e)) {
                if(X(0x285)>X(0x2cb)) X(0x2cb)=X(0x285);
                else pedal_decay=egs51_curve16(s,0,0xee2e,(uint16_t)(X(0x2cb)-X(0x285)));
            } else X(0x2cb)=X(0x285);
            if(XW(0x2ac)>XW(0x280)) decay=BW((uint16_t)(XW(0x2ac)-XW(0x280))>B(0xfd50)?0xfd51:0xfd4c);
            else XP(0x280,XW(0x2ac));
            if(XW(0x29a)<BW(0xfd4a)) addition=egs51_curve16(s,0,0xee1c,mag(XW(0x320)));
        }
        X(0x1bc)&=0xdf;
        if(!(I(0x95)&0x10) && (X(0x1bc)&0x40)) X(0x1bc)=(X(0x1bc)|0x20)&0xbf;
        uint16_t divisor=egs51_curve16(s,0,0xee22,position); assert(divisor);
        decay=(decay>pedal_decay?decay:pedal_decay)/divisor;
        if(XW(0x2a5)>decay) {
            uint16_t value=(uint16_t)(XW(0x2a5)-decay+addition);
            XP(0x2a5,value>BW(0xfd46)?BW(0xfd46):value);
        } else XP(0x2a5,0);
    } else { X(0x272)=X(0x285); X(0x1bc)&=0x9f; XP(0x2a5,0); }
    if(signed16(XW(0x224))<-(int)B(0xfd55) && !X(0x2a3)) X(0x2a3)=B(0xfd53);
    XP(0x20a,(X(0x2a3)>B(0xfd54)?BW(0xfd46):XW(0x2a5))/60);
    X(0x327)=I(0xab); XP(0x238,md(XW(0x20a),span,1000));
}
