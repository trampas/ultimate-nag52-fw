/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09887a; FLS offset 0x01887a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x098920) */
/* WARNING: Removing unreachable block (ram,0x098912) */
/* WARNING: Removing unreachable block (ram,0x09890a) */
/* WARNING: Removing unreachable block (ram,0x0988f6) */
/* WARNING: Removing unreachable block (ram,0x098952) */
/* WARNING: Removing unreachable block (ram,0x098944) */
/* WARNING: Removing unreachable block (ram,0x09893c) */
/* WARNING: Removing unreachable block (ram,0x098932) */
/* WARNING: Removing unreachable block (ram,0x098928) */
/* WARNING: Removing unreachable block (ram,0x0988e6) */
/* WARNING: Removing unreachable block (ram,0x0988d8) */
/* WARNING: Removing unreachable block (ram,0x0988d0) */
/* WARNING: Removing unreachable block (ram,0x0988c6) */
/* WARNING: Removing unreachable block (ram,0x0988bc) */
/* WARNING: Removing unreachable block (ram,0x098900) */

void egs52_update_near_c19d_09887a(char param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = egs52_update_near_c170_097904();
  if (((uVar2 & 0x100) != 0) && (uVar2 = egs52_update_near_c170_097904(), (uVar2 & 0x200) != 0)) {
    if (param_1 == '\x01') {
      uVar2 = Ram00ffc0;
      if ((uVar2 & 0x10) == 0) {
        uVar2 = Ram00ff54;
        Ram00ff54 = uVar2 & 0xfff8 | 1;
        uVar2 = Ram00ffc0;
        if ((uVar2 & 0x10) != 0) {
          uVar2 = Ram00ff80;
          Ram00ff80 = uVar2 | 0x80;
        }
        iVar1 = Ram00fe50;
        Ram00fe98 = iVar1 + 3000;
        uVar2 = Ram00ff90;
        Ram00ff90 = uVar2 & 0xff7f;
        uVar2 = Ram00ff90;
        Ram00ff90 = uVar2 | 0x40;
        uVar2 = Ram00fd02;
        Ram00fd02 = uVar2 | 4;
        UNK_00c19c = 3;
      }
    }
    else if (param_1 == '\x02') {
      uVar2 = Ram00ffc0;
      if ((uVar2 & 0x20) == 0) {
        uVar2 = Ram00ff54;
        Ram00ff54 = uVar2 & 0xff8f | 0x10;
        uVar2 = Ram00ffc0;
        if ((uVar2 & 0x20) != 0) {
          uVar2 = Ram00ff82;
          Ram00ff82 = uVar2 | 0x80;
        }
        iVar1 = Ram00fe50;
        Ram00fe9a = iVar1 + 3000;
        uVar2 = Ram00ff92;
        Ram00ff92 = uVar2 & 0xff7f;
        uVar2 = Ram00ff92;
        Ram00ff92 = uVar2 | 0x40;
        uVar2 = Ram00fd02;
        Ram00fd02 = uVar2 | 8;
        UNK_00c19d = 3;
      }
    }
    else if ((param_1 == '\x03') && (uVar2 = Ram00ffc0, (uVar2 & 0x40) == 0)) {
      uVar2 = Ram00ff54;
      Ram00ff54 = uVar2 & 0xf8ff | 0x100;
      uVar2 = Ram00ffc0;
      if ((uVar2 & 0x40) != 0) {
        uVar2 = Ram00ff84;
        Ram00ff84 = uVar2 | 0x80;
      }
      iVar1 = Ram00fe50;
      Ram00fe9c = iVar1 + 3000;
      uVar2 = Ram00ff94;
      Ram00ff94 = uVar2 & 0xff7f;
      uVar2 = Ram00ff94;
      Ram00ff94 = uVar2 | 0x40;
      uVar2 = Ram00fd02;
      Ram00fd02 = uVar2 | 0x10;
      UNK_00c19e = 3;
    }
  }
  return;
}


