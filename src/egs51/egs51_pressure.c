/* Semantic C reconstruction, reviewed against ROM instructions. See README.md
 * for evidence, tests and coverage limits. All addresses below are bank1 unless
 * specified. No native struct is overlaid on big-endian calibration bytes. */
#include "egs51_model.h"
#define I(a) s->im[a]
#define X(a) s->x[a]
#define IW(a) egs51_word(&I(a))
#define XW(a) egs51_word(&X(a))
#define R8(a) egs51_rom8(s,1,(uint16_t)(a))
#define R16(a) egs51_rom16(s,1,(uint16_t)(a))
#define PUT(a,v) egs51_put(&I(a),(uint16_t)(v))
static uint16_t muldiv(uint16_t a,uint16_t b,uint16_t c) {
    assert(c); /* hardware divide-by-zero result is not established */
    return (uint16_t)((uint32_t)a*b/c);
}
/* 1061 uses unsigned magnitude, including differences exceeding INT16_MAX. */
uint16_t egs51_lag(uint16_t cur,uint16_t target,uint8_t n) {
    if (!n) return target;
    return target>=cur ? (uint16_t)(cur+(target-cur)/n) : (uint16_t)(cur-(cur-target)/n);
}
/* 1412: descending interpolation subtracts a truncated positive magnitude. */
uint16_t egs51_lerp(uint16_t y0,uint16_t y1,uint16_t x0,uint16_t x1,uint16_t x) {
    if (x>=x1) return y1;
    if (x<=x0) return y0;
    return y1>=y0 ? (uint16_t)(y0+muldiv(y1-y0,x-x0,x1-x0))
                  : (uint16_t)(y0-muldiv(y0-y1,x-x0,x1-x0));
}
static unsigned interval(const Egs51 *s,unsigned bank,uint16_t axis,unsigned n,uint16_t *v) {
    assert(n>=2);
    uint16_t first=egs51_rom16(s,bank,axis),last=egs51_rom16(s,bank,(uint16_t)(axis+2*(n-1)));
    if (*v<=first) { *v=first; return 1; }
    if (*v>=last) { *v=last; return n-1; }
    unsigned j=1;
    while (*v>egs51_rom16(s,bank,(uint16_t)(axis+2*j))) ++j;
    return j;
}
/* 14F3 is specifically u16 axes AND u16 z. Interpolate x in each row,
 * truncate each result, then interpolate y. This differs from one float lerp. */
uint16_t egs51_map16(const Egs51 *s,unsigned bank,uint16_t desc,uint16_t x,uint16_t y) {
    unsigned nx=egs51_rom8(s,bank,desc+1),ny=egs51_rom8(s,bank,desc+3);
    uint16_t ax=egs51_rom16(s,bank,desc+4),ay=egs51_rom16(s,bank,desc+6),z=egs51_rom16(s,bank,desc+8);
    unsigned ix=interval(s,bank,ax,nx,&x),iy=interval(s,bank,ay,ny,&y);
    uint16_t x0=egs51_rom16(s,bank,ax+2*(ix-1)),x1=egs51_rom16(s,bank,ax+2*ix);
    uint16_t row[2];
    for (unsigned k=0;k<2;k++) {
        unsigned off=2*((iy-1+k)*nx+ix-1);
        row[k]=egs51_lerp(egs51_rom16(s,bank,z+off),egs51_rom16(s,bank,z+off+2),x0,x1,x);
    }
    return egs51_lerp(row[0],row[1],egs51_rom16(s,bank,ay+2*(iy-1)),egs51_rom16(s,bank,ay+2*iy),y);
}
/* 7093: gain is the DIVISOR (R4:R5=1000, R2:R3=gain at 717E).
 * Signed add wraps to 16 bits before the signed-positive clamp at 7133. */
uint16_t egs51_spc(const Egs51 *s,uint8_t idx,uint16_t clutch) {
    uint16_t h=XW(0x3ce);
    unsigned a= I(0xb6)==6 || idx==6 ? 0x174 : idx==0 || idx==4 ? 0x167 : 0x168;
    int32_t term=(X(a)<128 ? (int32_t)X(a) : (int32_t)X(a)-256)*20;
    uint16_t p=(uint16_t)(clutch+term);
    if (p>=0x8000) p=0;
    if (p>XW(0x273)) p=XW(0x273);
    return (uint16_t)(R16(h+0x37)+muldiv(p,1000,R16(h+0x39+2*idx)));
}
/* D76E..D99F returns a WORD; the caller stores its low byte as demand.
 * 5F..66 are internal scratch, not XRAM. Per-shift correction is additive. */
uint16_t egs51_pressure_demand(const Egs51 *s,uint16_t p) {
    uint16_t h=XW(0x3ce),factor,add=0,subtract=0;
    if (!I(0xb6)) factor=R16(h+((I(0xb9)==1 || I(0xb9)==6)?1:3));
    else {
        int first=I(0xac)==1 || I(0xac)==5;
        factor=R16(h+(first?1:3));
        add=egs51_lerp(0,R16(first?0xffe7:0xffe9),R16(0xffe3),R16(0xffe5),XW(0x275));
        if (I(0xac)==1) subtract=muldiv(IW(0x46),R16(0xffeb),100);
    }
    uint16_t line=(uint16_t)(muldiv(1000,(uint16_t)(R16(h+5)+IW(0x44)),factor)+add);
    line=line>subtract ? (uint16_t)(line-subtract) : 0;
    uint16_t inlet=egs51_lerp(R16(0xffda),R16(0xffdc),R16(0xffd6),R16(0xffd8),line);
    uint16_t correction=muldiv(R8(0xffd3),(uint16_t)(R16(0xffdc)-inlet),1000);
    if (p<inlet) {
        uint16_t offset=(uint16_t)(p+R16(0xffd4));
        if (offset>=0x8000) offset=0;
        p=(uint16_t)(p+muldiv(correction,offset,1000));
    } else p=XW(0x329);
    return muldiv(egs51_map16(s,1,0xea82,p,X(0x76)),10,45);
}
/* bank0 3F5C: biased integrator, signed error, saturating word output. */
uint16_t egs51_pi(uint16_t *integrator,uint8_t demand,uint8_t feedback,uint8_t kp,uint8_t ki) {
    int32_t e=(int32_t)demand-feedback;
    int32_t i=*integrator+ki*e;
    if (i<0) i=0;
    if (i>65535) i=65535;
    *integrator=(uint16_t)i;
    int32_t u=i-32768+kp*e;
    if (u<0) u=0;
    if (u>65535) u=65535;
    return (uint16_t)u;
}
/* bank0 3EEC: ISR uses register bank 3. XCHD with IRAM 19 (R1) combines
 * A:B >> 4, saturates at 255. MPC D9=255-u; SPC DA=u (not inverted). */
void egs51_current_control(Egs51 *s) {
    const unsigned demand[2]={0x37,0x35},feedback[2]={0x42,0x43},integ[2]={0x31,0x33},out[2]={0x105,0x102};
    for (unsigned j=0;j<2;j++) {
        uint16_t v=0,i=IW(integ[j]);
        if (I(demand[j])) v=egs51_pi(&i,I(demand[j]),I(feedback[j]),egs51_rom8(s,0,0xb38),egs51_rom8(s,0,0xb39));
        PUT(integ[j],i);
        v>>=4;
        uint8_t u=v>255?255:(uint8_t)v;
        X(out[j])=u;
        s->sfr[(j?0xda:0xd9)-0x80]=j?u:(uint8_t)(255-u);
    }
}
uint8_t egs51_fill_time(const Egs51 *s) {
    return (uint8_t)egs51_lerp(R8(0xff73),R8(0xff9e),R8(0xff91),R8(0xff92),X(0x76));
}
uint8_t egs51_hold_time(const Egs51 *s) {
    if ((I(0x9a)&8) && XW(0x2ac)>=R16(0xff9b) && XW(0x2ef)<=R16(0xfc3e)) return R8(0xff9d);
    return (uint8_t)egs51_lerp(R8(0xff76),R8(0xff71),R8(0xff91),R8(0xff92),X(0x76));
}
static void spc_update(Egs51 *s) { PUT(0x48,egs51_spc(s,(uint8_t)(I(0xac)-1),IW(0x46))); }
static void ramp(Egs51 *s) {
    PUT(0x44,egs51_lag(IW(0x44),R16(0xff87),I(0xb1)));
    PUT(0x46,egs51_lag(IW(0x46),4000,I(0xb1)));
    spc_update(s);
}
void egs51_engagement(Egs51 *s) {
    /* 5BB6 prologue; bit7 of 94, bit1 of 1C2 (not bits4/0). */
    I(0x9a)&=0xd7;
    uint8_t target=X(0x334);
    if (!(I(0x94)&0x80) && (target<=5 || target==7 || (I(0x96)&4))) {
        I(0x96)&=0xfb; I(0x94)|=0x80;
    }
    if (I(0xb4)!=8 && (((X(0x1bd)&1) && target>=7) ||
        ((I(0x94)&0x80) && target==6) || (X(0x1c2)&2))) {
        I(0xb0)=R8(0xffa1); I(0xb4)=8;
    }
    switch (I(0xb4)) {
    case 0: /* 5C81 falls through into state 1 in the SAME invocation. */
        I(0xb0)=0;
        if ((I(0x95)&4) && I(0xac)==7) {
            uint8_t t=egs51_hold_time(s);
            I(0xb0)=t>R8(0xff9f)?t:R8(0xff9f);
        }
        ++I(0xb4);
        /* fall through */
    case 1:
        PUT(0x44,R16(0xff87)); PUT(0x46,4000); spc_update(s);
        if ((I(0x95)&4) && I(0xac)==7) {
            if (I(0xb0)) return;
            I(0x9a)&=0xef; I(0xac)=1; I(0x95)&=0xfb;
            I(0xb0)=egs51_hold_time(s); ++I(0xb4); return;
        }
        ++I(0xb4); I(0xb0)=egs51_hold_time(s);
        if (I(0xb3)>=6 && !(I(0x9a)&0x10)) I(0x95)|=4;
        return;
    case 2:
        if (I(0xb0)) return;
        if (!(I(0x95)&1) && !(X(0x1bd)&2)) {
            uint16_t threshold=R16(0xff81);
            if (I(0xab)==1 || I(0xab)==5 || I(0xab)==6) {
                if (XW(0x1f6)>threshold) I(0x95)|=1;
            } else if (XW(0x1f6)<=threshold && XW(0x22f)>threshold) I(0x95)|=1;
        }
        I(0xb0)=egs51_fill_time(s); I(0xb1)=R8(0xff78);
        if ((I(0x9a)&0x14)!=0) {
            if (I(0x95)&1) ++I(0xb4);
            else { I(0xac)=5; I(0xb4)=0; I(0xaa)=0; }
            return;
        }
        ++I(0xb4);
        if (I(0xb3)>=6) {
            /* 5E00 tests bit1; 5E12 tests bit0. These are NOT complements. */
            if (((X(0x1bd)&2) && target!=7) || ((X(0x1bd)&1) && target==7)) {
                I(0x95)|=4; I(0xb4)=6;
            } else I(0xb4)=7;
            return;
        }
        if (I(0xb3)>=4) { I(0x95)|=2; return; }
        if (I(0xb3)==3 && !(I(0x95)&6)) { I(0x95)|=6; return; }
        if (I(0xb3)<=2 && !(I(0x95)&2)) {
            if (I(0xab)>=3) {
                I(0x95)=(I(0x95)|2)&0xfb;
                I(0xb2)=(uint8_t)(I(0xb0)+egs51_fill_time(s));
                I(0xac)=2; ++I(0xb4);
            } else if (target==7 || target<=5) { I(0xb0)=I(0xb1); I(0xb4)=7; }
            else { I(0xb0)=0; --I(0xb4); }
            return;
        }
        ++I(0xb4);
        if (I(0xb3)==3 && (I(0x95)&2)) I(0xb2)=(uint8_t)(I(0xb0)+egs51_fill_time(s));
        else { ++I(0xb4); I(0xb1)=0; I(0xb2)=egs51_fill_time(s); }
        return;
    case 3: case 4: case 7:
        ramp(s);
        if (I(0xb0)) return;
        if (I(0xb4)==4) {
            I(0x95)=(I(0x95)&0xfe)|4;
            if (I(0xb2)) return;
            I(0x95)&=0xfb; I(0xb1)=egs51_hold_time(s);
            I(0xb0)=(uint8_t)(I(0xb1)+R8(0xff7b));
            I(0xb2)=(uint8_t)(I(0xb0)+egs51_hold_time(s)); ++I(0xb4);
        } else {
            I(0x95)&=I(0xb4)==3?0xf8:0xfc;
            I(0x9a)|=0x10; I(0xb4)=0;
        }
        return;
    case 5:
        if (I(0xb1)) return;
        PUT(0x48,0); PUT(0x46,0); PUT(0x44,4500);
        if (I(0xac)==2) {
            if (I(0xb0)) return;
            I(0x95)&=0xfd; /* released BEFORE B2 expires */
            if (I(0xb2)) return;
            I(0xb0)=(uint8_t)(2*R8(0xff78)); I(0xb1)=R8(0xff78); I(0xb4)=3;
        } else {
            if (I(0xb2)) return;
            I(0x95)|=4; I(0xb0)=egs51_fill_time(s); I(0xb1)=R8(0xff78); I(0xb4)=3;
        }
        return;
    case 6:
        PUT(0x48,0); PUT(0x46,0); PUT(0x44,0); I(0x95)&=0xfe;
        if (!(X(0x1bd)&2)) I(0xb4)=7;
        return;
    case 8:
        I(0x95)=(I(0x95)&0xfe)|6;
        PUT(0x44,0); PUT(0x46,200); PUT(0x48,800);
        if ((X(0x1c2)&2) || I(0xb0)) return;
        if (((I(0x94)&0x80) && (target<=5 || target==7) && X(0x76)>=R8(0xffa2)
             && !(X(0x1ca)&2) && XW(0x2ac)<=R16(0xffad)) ||
            (!(I(0x94)&0x80) && (!(X(0x1bd)&1) || (target<=5 && XW(0x2ac)<R16(0xffa7))))) {
            I(0x9a)|=0x10; I(0x94)|=1; I(0x95)&=0xf9; I(0xb4)=0; I(0xaa)=0;
        }
        return;
    default: return;
    }
}
