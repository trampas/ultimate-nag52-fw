/* A0215451432 bank1 D9C8..E16C. Pressure-error adaptation, raw OEM units.
 * Owns X266..26D <-> I44..4B; pressure state remains in X361..374. */
#include "egs51_internal.h"
static int eligible(const Egs51 *s) {
    return (I(0xb6)==1 && (I(0xac)==1 || I(0xac)==2)) || (I(0xb6)==4 && I(0xac)==7);
}
static int signed8(uint8_t v) { return v<128?v:(int)v-256; }
void egs51_pressure_adaptation(Egs51 *s) {
    for(unsigned k=0;k<8;k++) I(0x44+k)=X(0x266+k);
    uint16_t cal=XW(0x3c0),fill=XW(0x3ba);
    uint16_t next=md(X(0x397),XW(0x2c5),10),old=(uint16_t)(10u*XW(0x29f));
    uint8_t weight=R(cal+((I(0x96)&0x20)?10:6));
    uint16_t filtered=(uint16_t)(((uint32_t)old*weight+next)/(weight+1u));
    XP(0x29f,filtered/10);
    if(!I(0xb6)) {
        I(0x44)=0;
        if(I(0x99)&1) { X(0x1bf)|=1; I(0x99)&=0xfe; }
        goto done;
    }
    if(I(0x44)>0) {
        uint8_t delta=R(fill+0x12);
        if((X(0x1ca)&10) || (X(0x1cb)&8) || (I(0x99)&0x10)) I(0x99)&=0xfe;
        if(I(0x44)>=2 &&
           ((XW(0x22f)>=(uint16_t)(XW(0x275)-delta) && (I(0x95)&8)) ||
            (XW(0x275)>=(uint16_t)(XW(0x22f)-delta) && (I(0x95)&0x10)))) I(0x99)&=0xfe;
        if((I(0x96)&4) || (IW(0xad)>=RW(fill+2*I(0xac)) && I(0xaa)<3) ||
           (X(0x1bb)&1) || XW(0x275)>30u*R(cal+13) || !eligible(s) ||
           (I(0x98)&0x21) || (I(0xaa)==1 && I(0xb4)>=4) || X(0x264) || (X(0x1bc)&4)) I(0x99)&=0xfe;
        if(!(I(0x99)&1)) I(0x44)=4;
    }
    switch(I(0x44)) {
    case 0: {
        I(0x99)|=1;
        unsigned index=(uint8_t)(I(0xac)-1);
        uint8_t bit=index<8?(uint8_t)(1u<<index):0;
        if(!(R(cal+1)&bit) || !eligible(s) || X(0x76)>R(fill+0x16) || X(0x76)<R(fill+0x15)) I(0x99)&=0xfe;
        I(0x44)++;
    }
    /* fall through */
    case 1: {
        if(I(0xaa)>3) { I(0x99)&=0xfe; break; }
        uint8_t delta=R(fill+0x12);
        if(signed16(XW(0x2bb))>signed16(RW(fill+0x17)) &&
           ((XW(0x22f)<(uint16_t)(XW(0x275)-delta) && (I(0x95)&8)) ||
            (XW(0x275)<(uint16_t)(XW(0x22f)-delta) && (I(0x95)&0x10)))) {
            I(0x45)=R(cal+2); I(0x44)++;
        }
        break;
    }
    case 2:
        if(signed16(XW(0x2bb))<signed16(RW(fill+0x17))) I(0x44)=1;
        if(!I(0x45)) { I(0x45)=255; IP(0x46,XW(0x22f)); IP(0x48,0); I(0x44)++; }
        break;
    case 3: {
        uint16_t threshold=RW(fill+0x17);
        if(signed16(XW(0x2bb))<signed16(threshold)) I(0x44)=1;
        if(signed16(XW(0x357))>=signed16(threshold) && I(0xaa)<4) {
            uint16_t sum=(uint16_t)(XW(0x363)+XW(0x36b));
            uint16_t value=sum>XW(0x367)?md((uint16_t)(sum-XW(0x367)),X(0x2ab),XW(0x36f)):0;
            IP(0x48,IW(0x48)+value-XW(0x29f));
            break;
        }
        I(0x45)=(uint8_t)(254-I(0x45));
        if(I(0x45)<=R(cal+3)) { I(0x99)&=0xfe; break; }
        IP(0x48,(uint16_t)(signed16(IW(0x48))/I(0x45)));
        uint16_t momentum=egs51_signed_md(R(XW(0x3d4)+0x7c+I(0xac)),
                                        (uint16_t)(IW(0x46)-XW(0x22f)),20u*I(0x45));
        uint16_t error=(uint16_t)((I(0x95)&8)?IW(0x48)-momentum:IW(0x48)+momentum);
        error=egs51_signed_md(error,XW(0x36f),X(0x2ab));
        if(signed16(error)>=signed16(RW(cal+11))) error=RW(cal+11);
        uint16_t lower=(uint16_t)(0-RW(cal+14));
        if(signed16(error)<=signed16(lower)) error=lower;
        IP(0x4a,error);
        if((X(0x79)&0x10) || !error) { I(0x99)&=0xfe; break; }
        uint16_t cell=(I(0x95)&8)?0x166+I(0xac):0x174;
        /* Preserve interpolation operands left in indirect RAM. */
        IP(0x9b,R(cal+4)); IP(0x9d,R(cal+7)); IP(0x9f,R(cal+8));
        IP(0xa1,R(cal+9)); IP(0xa3,I(0x45));
        uint16_t scale=egs51_lerp(IW(0x9b),IW(0x9d),IW(0x9f),IW(0xa1),IW(0xa3));
        uint16_t value=(uint16_t)(egs51_signed_md(error,scale,2000)+signed8(X(cell)));
        uint16_t limit=md(R(cal+5),RW(XW(0x3ce)+0x37+2*I(0xac)),1000);
        lower=(uint16_t)(0-limit);
        if(signed16(value)<=signed16(lower)) value=lower;
        if(signed16(value)>=signed16(limit)) value=limit;
        X(cell)=(uint8_t)value; I(0x44)++;
        break;
    }
    default: break;
    }
 done:
    for(unsigned k=0;k<8;k++) X(0x266+k)=I(0x44+k);
}
