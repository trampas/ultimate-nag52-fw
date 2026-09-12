/* A0215451432 bank1 B708..C0D2. Qualification during the shift and
 * completed-shift correction distribution. All cells remain OEM RAM cells. */
#include "egs51_internal.h"
static uint16_t absolute(uint16_t v) { return signed16(v)<0?(uint16_t)(0-v):v; }
static int signed8(uint8_t v) { return v<128?v:(int)v-256; }
static void add_cell(Egs51 *s,uint16_t cell,uint16_t correction) {
    assert(cell<sizeof(s->x));
    X(cell)=egs51_adapt_limit(s,(uint16_t)(signed8(X(cell))+correction));
}
static void positive_correction(Egs51 *s) {
    if((I(0x99)&0x40) && signed16(XW(0x307))<=0) XP(0x307,0);
}
void egs51_shift_cell_adaptation(Egs51 *s) {
    uint16_t cal=XW(0x3bc);
    if(I(0xb6)) {
        if(I(0xb6)>=5) { I(0x99)&=0xdf; return; }
        if(X(0x1f5)>1) return;
        if(!X(0x1f5)) { I(0x99)|=0x20; XP(0x32c,XW(0x2ac)); X(0x1f5)++; }
        X(0x313)=I(0xb6);
        uint16_t delta=(uint16_t)(XW(0x2ac)-XW(0x32c)); XP(0x32c,XW(0x2ac));
        int inhibit=0;
        if(I(0xaa)>0 && I(0xaa)<((I(0x95)&0x20)?3:4)) {
            if(signed16((uint16_t)(absolute(XW(0x224))-R(cal+4)))>0) inhibit=1;
            uint16_t torque=(uint16_t)((X(0x313)&1)?XW(0x2b9):0-XW(0x2b9));
            if(signed16(torque)>signed16(RW(cal+0x0e + 2*X(0x313)))) {
                uint16_t factor=egs51_signed_md(630,XW(0x203),XW(0x181));
                uint8_t gear=(uint8_t)(I(0xb9)+((X(0x313)&2)?((X(0x313)&1)?1:-1):0));
                uint16_t value=egs51_signed_md(RW(cal+0x16+2*X(0x313)),RW(0x1040+2*gear),100);
                value=egs51_signed_md(value,IW(0xad),10000);
                value=egs51_signed_md(factor,value,100);
                if(signed16(absolute(delta))>=signed16(value)) inhibit=1;
            }
            if((X(0x1c7)&7) || (I(0x99)&0x10)) inhibit=1;
        }
        if((I(0x96)&0x6d) || X(0x76)>R(cal+3) || X(0x76)<R(cal+2) ||
           ((X(0x1bb)&1) && X(0x1e5)<R(cal+0x21)) || (X(0x1cb)&8) ||
           (X(0x1ca)&11) || (X(0x1c5)&0x40)) inhibit=1;
        if(inhibit) I(0x99)&=0xdf;
        return;
    }
    X(0x1f5)=0;
    if(X(0x79)&12) return;
    unsigned index=(uint8_t)(I(0xac)-1);
    uint8_t bit=index<8?(uint8_t)(1u<<index):0;
    if(!(R(cal+((X(0x313)==1 || X(0x313)==3)?1:15))&bit)) I(0x99)&=0xdf;
    if(!(I(0x99)&0x20) || !X(0x1e5)) goto done;
    uint16_t correction=egs51_signed_md(XW(0x1ee),R(cal+5),100);
    correction=(uint16_t)(signed16(correction)/X(0x1e5));
    XP(0x307,correction);
    uint16_t momentum=egs51_signed_md(XW(0x38c),R(cal+0x23),100);
    uint16_t integral=egs51_signed_md(XW(0x206),R(cal+0x24),100);
    correction=(uint16_t)((X(0x313)==2 || X(0x313)==4)?correction+momentum-integral:correction-momentum+integral);
    correction=(uint16_t)(signed16(correction)/3);
    uint16_t limit=RW(cal+6),lower=(uint16_t)(0-limit);
    if(signed16(correction)>=signed16(limit)) correction=limit;
    if(signed16(correction)<=signed16(lower)) correction=lower;
    XP(0x307,correction);
    switch(X(0x313)) {
    case 1:
        positive_correction(s);
        egs51_shift_adapt_address(s,6,1,0x127);
        XP(0x298,md(XW(0x317),RW(0x103e + 2*I(0xb9)),1000));
        if(signed16(XW(0x23b))>signed16(RW(cal+8))) {
            egs51_adapt_weights(s,XW(0x23b),XW(0x307),RW(cal+8),RW(cal+10));
            egs51_adapt_cells(s,XW(0x298),0);
        } else {
            egs51_adapt_weights(s,XW(0x23b),XW(0x307),(uint16_t)(0-RW(XW(0x3ca)+0x2d)),RW(cal+8));
            egs51_adapt_cells(s,XW(0x298),2);
        }
        break;
    case 3:
        positive_correction(s);
        egs51_shift_adapt_address(s,4,5,0x147);
        XP(0x298,md(XW(0x317),RW(0x1040+2*I(0xb9)),1000));
        egs51_adapt_weights(s,XW(0x23b),XW(0x307),RW(XW(0x3ca)+0x2f),RW(cal+10));
        egs51_adapt_cells(s,XW(0x298),0);
        break;
    case 2:
        XP(0x307,0-XW(0x307)); positive_correction(s);
        egs51_adapt_weights(s,XW(0x298),XW(0x307),RW(cal+0x26),RW(cal+0x0c));
        add_cell(s,XW(0x305),XW(0x2e5)); add_cell(s,XW(0x305)+1,XW(0x38a));
        break;
    case 4: {
        XP(0x307,0-XW(0x307)); positive_correction(s);
        egs51_shift_adapt_address(s,4,5,0x157);
        XP(0x298,md(XW(0x317),RW(0x1040+2*I(0xb9)),1000));
        egs51_adapt_weights(s,XW(0x298),XW(0x307),RW(cal+0x26),RW(cal+0x0c));
        uint16_t cell=(uint16_t)(XW(0x305)+(signed16(XW(0x23b))<0?2:0));
        add_cell(s,cell,XW(0x2e5)); add_cell(s,cell+1,XW(0x38a));
        break;
    }
    default: break;
    }
 done:
    I(0x99)&=0xdf;
}
