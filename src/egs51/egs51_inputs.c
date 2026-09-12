/* A0215451432 bank0 C449 and C6C6. Preserve staged 16-bit arithmetic. */
#include "egs51_internal.h"
void egs51_turbine_speed(Egs51 *s) {
    uint16_t sum=(uint16_t)(md(3932,XW(0x1f0),2408)+XW(0x1f6));
    uint16_t subtract=md(3932,XW(0x1f6),2408);
    XP(0x22f,sum>subtract?sum-subtract:0);
}
void egs51_clutch_speeds(Egs51 *s) {
    uint16_t a,b;
    if(!(X(0x1cb)&4)) egs51_turbine_speed(s);
    XP(0x1ea,0); XP(0x357,0); XP(0x2bb,0);
    if(I(0xb6)>=1 && I(0xb6)<=4) {
        switch(I(0xac)) {
        case 1: case 5:
            a=(uint16_t)(XW(0x1f0)-XW(0x1f6)); b=XW(0x1f6);
            XP(0x357,I(0xac)==1?a:b); XP(0x2bb,I(0xac)==1?b:a); break;
        case 2: case 6:
            a=(uint16_t)(XW(0x1f6)-md(1486,XW(0x375),1000));
            b=(uint16_t)(md(2408,md(1486,XW(0x375),922),1000)-md(1486,XW(0x1f6),922));
            XP(0x357,I(0xac)==2?a:b); XP(0x2bb,I(0xac)==2?b:a); break;
        case 3: case 7:
            b=(uint16_t)(md(1486,XW(0x375),486)-md(1000,XW(0x1f6),486));
            XP(0x1ea,b); a=(uint16_t)(XW(0x1f6)-b);
            XP(0x357,I(0xac)==3?a:b); XP(0x2bb,I(0xac)==3?b:a); break;
        case 4: case 8:
            XP(0x1ea,md(1486,XW(0x375),486)-md(1000,XW(0x22f),486));
            a=XW(0x1f6); b=(uint16_t)(XW(0x1f0)-a);
            XP(0x357,I(0xac)==4?a:b); XP(0x2bb,I(0xac)==4?b:a); break;
        default: break;
        }
    } else if(I(0xb6)==5 || I(0xb6)==6) {
        switch(I(0xb3)) {
        case 1: case 5:
            XP(0x1ea,md(2408,XW(0x375),1408)-md(1000,XW(0x1f0),1408)); break;
        case 4: XP(0x1ea,XW(0x1f6)); break;
        case 6: case 7:
            XP(0x1ea,md(2408,XW(0x375),1408)+md(1000,XW(0x1f0),1408)); break;
        default: break;
        }
    } else if(!I(0xb6) && I(0xb9)>=4 && I(0xb9)<=7) {
        XP(0x1ea,md(2408,XW(0x375),1408)-md(1000,XW(0x1f0),1408));
    }
}

/* Bank0 CF5B..CFB0: signed torque context, not shaft speed. */
void egs51_torque_context(Egs51 *s) {
    XP(0x2b9,XW(0x2c5));
    XP(0x1fb,egs51_signed_md(X(0x397),XW(0x395),100));
    uint16_t torque=egs51_signed_md(X(0x397),XW(0x2b9),100);
    XP(0x1fd,torque);
    IP(0xad,signed16(torque)<0?(uint16_t)(0-torque):torque);
}

/* Bank0 CA22..CA64: unsigned weighted filter, with word wrap before scaling. */
void egs51_turbine_filter(Egs51 *s) {
    uint16_t next=(uint16_t)(XW(0x22f)<<3),old=(uint16_t)(XW(0x1da)<<3);
    uint8_t weight=B(0xff8a);
    XP(0x1da,((uint32_t)old*weight+next)/(weight+1u)/8u);
}

/* Bank0 CA65..CFB0: qualification, torque-converter curves and signed context.
 * Preserve branch-specific CF5B versus CF6A entry: only engagement copies
 * converter torque X2C5 over the qualified X2B9 value. */
void egs51_torque_inputs(Egs51 *s) {
    X(0x1cb)&=0xf7;
    if(X(0x71)&8) {
        X(0x1cb)|=8; XP(0x347,BW(0xff07));
        XP(0x395,BW(0xff03)); XP(0x2b9,XW(0x395)); X(0x7c)=B(0xff0b);
    } else {
        if(X(0x184)==3) {
            if(X(0x71)&0x10) { X(0x9f)=B(0xff0a); X(0x9d)=B(0xff09); }
            if((X(0x71)&0x20) || (X(0x70)&0x2a)) {
                X(0x1cb)|=8; XP(0x347,BW(0xff07)); XP(0x395,BW(0xff03));
                XP(0x2b9,XW(0x395));
            } else {
                uint8_t limit=X(0x9e)<X(0x9f)?X(0x9e):X(0x9f);
                if(limit<X(0x9d)) limit=X(0x9d);
                if(limit>X(0x8b)) limit=X(0x8b);
                if(limit<X(0x9b)) limit=X(0x9b);
                XP(0x347,3u*limit);
                XP(0x2b9,XW(0x347)-3u*X(0x86));
                XP(0x395,3u*(uint16_t)(X(0x9b)-X(0x86)));
            }
        } else {
            if((X(0x71)&0x20) || (X(0x70)&8)) {
                X(0x1cb)|=8; XP(0x347,BW(0xff07)); XP(0x395,BW(0xff03));
            } else {
                XP(0x347,3u*X(0x9b));
                XP(0x395,3u*(uint16_t)(X(0x9b)-X(0x86)));
            }
            XP(0x2b9,XW(0x395));
        }
        if((X(0x71)&0x20) || (X(0x70)&0x10)) X(0x7c)=B(0xff0b);
    }
    if(!(X(0x1cb)&8)) {
        if(X(0x1c8)&8) {
            if(!X(0x284)) {
                X(0x2a7)+=B(0xff9e);
                if(X(0x2a7)>B(0xffa0)) X(0x2a7)=B(0xffa0);
            }
            X(0x2bd)=B(0xffa8);
        } else {
            if(!X(0x2bd)) X(0x2a7)=X(0x2a7)>B(0xff9f)?X(0x2a7)-B(0xff9f):0;
            X(0x284)=B(0xffa7);
        }
        XP(0x395,XW(0x395)-(X(0x2a7)>>2));
        XP(0x2b9,XW(0x2b9)-(X(0x2a7)>>2));
    }
    XP(0x398,0); X(0x1cb)&=0xef;
    if((X(0x1ca)&8) || (X(0x1cb)&4)) X(0x1cb)|=0x10;
    else if(XW(0x275)) XP(0x398,md(1000,XW(0x22f),XW(0x275)));
    IP(0xa5,XW(0x398));
    X(0x397)=(uint8_t)egs51_curve16(s,0,XW(0x3ac),IW(0xa5));
    if(X(0x1cb)&0x10) XP(0x2c9,BW(0xff0c));
    else {
        XP(0x21a,egs51_curve16(s,0,(uint16_t)(XW(0x3ac)+6),IW(0xa5)));
        uint16_t torque=md(XW(0x275),XW(0x275),1000);
        torque=md(XW(0x21a),torque,10000);
        torque=md(1,torque,10);
        XP(0x2c5,torque>BW(0xff9b)?BW(0xff9b):torque);
        if(I(0xb6)==6) {
            uint16_t ratio=XW(0x275)?md(1000,egs51_gear_sync_speed(s,I(0xb9)),XW(0x275)):0;
            IP(0xa5,ratio);
            uint16_t coefficient=egs51_curve16(s,0,(uint16_t)(XW(0x3ac)+6),ratio);
            if(coefficient) {
                uint16_t magnitude=XW(0x2b9);
                if(signed16(magnitude)<0) magnitude=(uint16_t)(0-magnitude);
                uint16_t a=egs51_handoff_root_test(md(magnitude,10,1));
                uint16_t b=egs51_handoff_root_test(md(10000,1000,coefficient));
                XP(0x2c9,(uint32_t)a*b);
            } else XP(0x2c9,XW(0x22f));
            XP(0x2b9,XW(0x2c5));
        }
    }
    XP(0x1fb,egs51_signed_md(X(0x397),XW(0x395),100));
    uint16_t torque=egs51_signed_md(X(0x397),XW(0x2b9),100);
    XP(0x1fd,torque); IP(0xad,signed16(torque)<0?(uint16_t)(0-torque):torque);
}
