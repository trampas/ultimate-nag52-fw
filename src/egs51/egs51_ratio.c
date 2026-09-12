/* A0215451432 bank0 D3A5..E01D: ratio observation and fault recovery. */
#include "egs51_internal.h"
static unsigned above(Egs51 *s,uint16_t threshold) {
    return (XW(0x332)>threshold)+(XW(0x349)>threshold)+
           (XW(0x314)>threshold)+(XW(0x323)>threshold);
}
void egs51_wheel_motion(Egs51 *s) { /* D3E2 */
    if(X(0x210)==2) { if(above(s,BW(0xff3e))<3) X(0x210)=1; return; }
    if(above(s,BW(0xff3c))==4 && !(X(0x1c7)&0x80)) {
        if(!X(0x359)) X(0x210)=1;
    } else { X(0x359)=B(0xff33); X(0x210)=0; }
    if(above(s,BW(0xff4c))==4) X(0x210)=2;
}
static uint16_t absword(uint16_t value) {
    return value&0x8000?(uint16_t)(0u-value):value;
}
static int gear_valid(unsigned g) { return g>=1 && g<=5; }
static int excess_slip(Egs51 *s) {
    return signed16(XW(0x2cf))>signed16(BW(0xff42)) &&
           signed16(XW(0x35c))>signed16(BW(0xff21));
}
static void recovery_enter(Egs51 *s,uint8_t next,unsigned calibration) {
    X(0x2a4)=B(calibration); X(0x390)=next;
}
static void mismatch_increment(Egs51 *s) {
    if(X(0x2e8)<253 && !(X(0x1ca)&8)) X(0x2e8)+=2;
}
void egs51_ratio_recovery(Egs51 *s) { /* D8D2..E01D */
    uint8_t gear=X(0x2ec),actual=I(0xb9),mode=I(0xb6);
    switch(X(0x390)) {
    case 0: /* D8F8 */
        X(0x1c2)&=0xbf;
        if(I(0x9a)&1) {
            if(!mode) { X(0x389)=5; recovery_enter(s,253,0xff31); X(0x1c2)|=0x40; }
            break;
        }
        X(0x1c2)&=0xcc;
        if(!mode) {
            if(!(X(0x1c9)&2)) X(0x1f2)=actual;
            if(X(0x210)==2 || X(0x210)==1) {
                if(gear_valid(gear)) {
                    if(gear==actual || (gear==1 && actual==2)) {
                        if(X(0x2e8) && (X(0x1c9)&2)) X(0x2e8)--;
                    } else {
                        X(0x1c2)|=1;
                        if(X(0x210)==1 || gear>actual ||
                           ((X(0x1c9)&2) && gear>=X(0x1f2) && X(0x1f2)<actual))
                            recovery_enter(s,2,0xff31);
                        else recovery_enter(s,1,0xff2f);
                        X(0x389)=gear;
                    }
                } else if(gear==0x17) {
                    X(0x1c2)|=1;
                    if(X(0x210)==2 && (actual==4 || actual==5)) {
                        recovery_enter(s,1,0xff2f); X(0x389)=gear;
                    } else recovery_enter(s,3,0xff31);
                } else if(gear==255) {
                    if(X(0x210)==2) { X(0x1c2)|=1; recovery_enter(s,4,0xff32); }
                    else recovery_enter(s,5,X(0x35e)?0xff30:0xff32);
                }
            }
            if(!(X(0x1c2)&1)) { X(0x1c9)&=0xfd; X(0x1f2)=actual; }
        } else if(mode<=4) {
            X(0x1c9)|=2;
            if((B(0xfef3)&1) && X(0x210)==2) {
                int mismatch;
                if(mode<=2) mismatch=(gear_valid(gear) && gear<(uint8_t)(actual-1)) || (gear==0x17 && actual==5);
                else mismatch=(gear_valid(gear) && gear<actual) || (gear==0x17 && actual==4);
                if(mismatch && signed16(XW(0x35c))>signed16(BW(0xff2d))) {
                    X(0x1c2)|=1; recovery_enter(s,1,0xff40); X(0x389)=gear;
                }
            }
        } else X(0x1c9)&=0xfd;
        break;
    case 1: /* DC50 */
        if(!X(0x2a4)) {
            X(0x1c2)|=2; I(0x28)|=1;
            if(X(0x210)<=1 && X(0x334)<=5) X(0x390)=0;
        } else if(!(X(0x389)==255 && gear==255 && excess_slip(s)) && gear!=X(0x389)) X(0x390)=0;
        break;
    case 2: /* DCDD */
        if(!X(0x2a4)) {
            X(0x1c2)|=0x20;
            if(I(0xa9)>=2) { X(0x390)=0; mismatch_increment(s); }
        } else if(gear!=X(0x389)) X(0x390)=0;
        break;
    case 3: /* DD39 */
        if(!X(0x2a4)) { X(0x1c2)|=0x10; X(0x390)=0; mismatch_increment(s); }
        else if(gear!=0x17) X(0x390)=0;
        break;
    case 4: /* DD86 */
        if(gear==255 && excess_slip(s)) { recovery_enter(s,1,0xff2f); X(0x389)=gear; }
        else {
            if(gear_valid(gear) || gear==0x17 || !gear) X(0x390)=0;
            if(!X(0x2a4)) { X(0x1c2)|=8; X(0x35e)=1; X(0x390)=0; }
        }
        break;
    case 5: /* DE15 */
        if(X(0x73)&2) { X(0x35e)=2; I(0x28)&=0xfd; }
        else if(X(0x35e)==2) { X(0x2a4)=B(0xff30); X(0x35e)=1; }
        switch(X(0x35e)) {
        case 0:
            X(0x1c2)&=0xf3;
            if(gear==255 && !mode) {
                if(!X(0x2a4)) { X(0x1c2)|=8; X(0x2a4)=B(0xff30); X(0x35e)++; }
            } else X(0x390)=0;
            break;
        case 1:
            if(gear==255 && !mode) { if(!X(0x2a4) && (B(0xfef5)&2)) I(0x28)|=2; }
            else X(0x390)=0;
            break;
        case 2: X(0x1c2)|=12; break;
        default: break;
        }
        if(X(0x35e)<=1 && X(0x210)==2) X(0x390)=0;
        break;
    case 253: /* DED9 */
        if(gear!=X(0x389) || absword(XW(0x35c))>=BW(0xff1f) || !X(0x210)) {
            X(0x2a4)=B(0xff31); if(gear_valid(gear)) X(0x389)=gear;
        }
        if(!X(0x2a4)) { I(0x9a)&=0xfe; X(0x1c2)|=0x20; X(0x390)=0; }
        break;
    case 254: /* DF3F */
        X(0x1c2)=(X(0x1c2)|1)&0xcd;
        if(!(X(0x78)&2)) {
            recovery_enter(s,253,0xff31); X(0x389)=gear; X(0x1c2)|=0x40;
        }
        break;
    case 255: if(X(0x334)<=5) X(0x390)=0; break;
    default: break;
    }
    I(0x27)&=0x7f;
    if(X(0x72)&0x80) X(0x1c2)|=3;
    else if((B(0xfef5)&0x80) && X(0x210)>=1 &&
            XW(0x275)>(uint16_t)(BW(XW(0x3a8)+1)+BW(0xff18))) I(0x27)|=0x80;
    I(0x23)&=0xdf;
    if(X(0x6e)&0x20) X(0x1c2)|=3;
    else if((B(0xfef4)&0x20) && (IW(0x81)>BW(0xff4e) || IW(0x83)>BW(0xff4e))) I(0x23)|=0x20;
}
static uint16_t tolerance(Egs51 *s,unsigned cal) {
    return egs51_lerp(2u*B(cal),2u*B(cal+1),BW(0xff12),BW(0xff16),XW(0x2ef));
}
void egs51_ratio_observer(Egs51 *s) { /* D456..E01D */
    uint16_t old=XW(0x32f); uint8_t oldgear=X(0x34c);
    XP(0x32f,0); XP(0x2cf,0); XP(0x31a,0); X(0x34c)=0;
    egs51_wheel_motion(s);
    if(!(I(0x24)&1)) X(0x1ff)=B(0xff1e);
    if((X(0x1c6)&8) && IW(0x81)>BW(0xff1c) && !(X(0x6e)&0x14) &&
       !(X(0x1cb)&0x81) && X(0x1ff) && !(X(0x1c6)&0x40) &&
       !(X(0x1bb)&10) && !(X(0x1cb)&0x40) && XW(0x375)>BW(0xff1a)) {
        uint16_t ratio=md(IW(0x81),1000,XW(0x375)); XP(0x32f,ratio);
        if(X(0x334)<=5) {
            X(0x34c)=255;
            if(absword((uint16_t)(ratio-2408))<=tolerance(s,0xff23)) {
                if(absword((uint16_t)(IW(0x81)-IW(0x83)))<=BW(0xff29)) X(0x34c)=2;
                else if(!IW(0x83)) X(0x34c)=1;
            } else if(absword((uint16_t)(ratio-1486))<=tolerance(s,0xff25)) X(0x34c)=3;
            else {
                uint16_t tol=tolerance(s,0xff27);
                if(absword((uint16_t)(ratio-1000))<=tol) X(0x34c)=4;
                else if(absword((uint16_t)(ratio-md(2408,830,3932)))<=tol) {
                    if(!IW(0x83)) X(0x34c)=5;
                } else if(absword((uint16_t)(ratio-md(2408,1486,3932)))<=tol && !IW(0x83)) X(0x34c)=0x17;
            }
        } else if(X(0x334)==7 && absword((uint16_t)(ratio-1899))<=2u*B(0xff23)) X(0x34c)=IW(0x83)?7:6;
        if(X(0x334)<=5) {
            XP(0x2cf,XW(0x22f)-md(XW(0x375),BW(0x1040+2u*I(0xb9)),1000));
            if(ratio && old) {
                int32_t delta=signed16((uint16_t)(ratio-old));
                if(delta<-125) delta=-125;
                if(delta>125) delta=125;
                XP(0x31a,(uint16_t)((uint8_t)delta*256u));
            }
        }
    }
    XP(0x35c,(signed16(XW(0x35c))*B(0xff49)+signed16(XW(0x31a)))/(B(0xff49)+1));
    if(!X(0x34c)) X(0x2ec)=0;
    else {
        if(X(0x34c)==255 && oldgear!=255) X(0x352)=B(0xff2b);
        else if(X(0x34c)!=oldgear) X(0x2a8)=B(0xff2c);
        X(0x2ec)=(X(0x352) || X(0x2a8))?0x58:X(0x34c);
    }
    if(X(0x334)>=6 && X(0x334)<=8) { X(0x1c9)&=0xfd; X(0x390)=255; }
    if(X(0x78)&2) {
        if(X(0x35e)==2) X(0x35e)=1;
        X(0x1c9)&=0xfd; X(0x390)=254;
    }
    egs51_ratio_recovery(s);
}
