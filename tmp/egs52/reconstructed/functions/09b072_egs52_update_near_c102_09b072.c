/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09b072; FLS offset 0x01b072.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09b1ba) */
/* WARNING: Removing unreachable block (ram,0x09b1d0) */
/* WARNING: Removing unreachable block (ram,0x09b1c8) */
/* WARNING: Removing unreachable block (ram,0x09b1e4) */
/* WARNING: Removing unreachable block (ram,0x09b1b2) */
/* WARNING: Removing unreachable block (ram,0x09b1a8) */
/* WARNING: Removing unreachable block (ram,0x09b1a2) */
/* WARNING: Removing unreachable block (ram,0x09b194) */
/* WARNING: Removing unreachable block (ram,0x09b0be) */
/* WARNING: Removing unreachable block (ram,0x09b0ce) */
/* WARNING: Removing unreachable block (ram,0x09b0ca) */
/* WARNING: Removing unreachable block (ram,0x09b0c4) */
/* WARNING: Removing unreachable block (ram,0x09b0ac) */
/* WARNING: Removing unreachable block (ram,0x09b0a8) */
/* WARNING: Removing unreachable block (ram,0x09b09e) */
/* WARNING: Removing unreachable block (ram,0x09b18a) */
/* WARNING: Removing unreachable block (ram,0x09b180) */
/* WARNING: Removing unreachable block (ram,0x09b172) */
/* WARNING: Removing unreachable block (ram,0x09b16c) */
/* WARNING: Removing unreachable block (ram,0x09b140) */
/* WARNING: Removing unreachable block (ram,0x09b15c) */
/* WARNING: Removing unreachable block (ram,0x09b156) */
/* WARNING: Removing unreachable block (ram,0x09b152) */
/* WARNING: Removing unreachable block (ram,0x09b14e) */
/* WARNING: Removing unreachable block (ram,0x09b136) */
/* WARNING: Removing unreachable block (ram,0x09b12c) */
/* WARNING: Removing unreachable block (ram,0x09b118) */
/* WARNING: Removing unreachable block (ram,0x09b10e) */
/* WARNING: Removing unreachable block (ram,0x09b124) */
/* WARNING: Removing unreachable block (ram,0x09b11c) */
/* WARNING: Removing unreachable block (ram,0x09b108) */
/* WARNING: Removing unreachable block (ram,0x09b100) */
/* WARNING: Removing unreachable block (ram,0x09b0f8) */
/* WARNING: Removing unreachable block (ram,0x09b0f4) */
/* WARNING: Removing unreachable block (ram,0x09b0f0) */
/* WARNING: Removing unreachable block (ram,0x09b0ea) */
/* WARNING: Removing unreachable block (ram,0x09b0e6) */
/* WARNING: Removing unreachable block (ram,0x09b0dc) */
/* WARNING: Removing unreachable block (ram,0x09b0d8) */
/* WARNING: Removing unreachable block (ram,0x09b098) */
/* WARNING: Removing unreachable block (ram,0x09b094) */
/* WARNING: Removing unreachable block (ram,0x09b08a) */
/* WARNING: Removing unreachable block (ram,0x09b1f8) */
/* WARNING: Removing unreachable block (ram,0x09b1da) */
/* WARNING: Removing unreachable block (ram,0x09b1c4) */
/* WARNING: Removing unreachable block (ram,0x09b200) */
/* WARNING: Removing unreachable block (ram,0x09b204) */
/* WARNING: Removing unreachable block (ram,0x09b208) */
/* WARNING: Removing unreachable block (ram,0x09b216) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f462 : 0x09b094 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_c102_09b072(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  
  uVar1 = Ram00fdec;
  if ((uVar1 & 0x20) == 0) {
    uVar1 = Ram00fd02;
    if ((uVar1 & 0x20) != 0) {
      uVar1 = Ram00fd02;
      Ram00fd02 = uVar1 & 0xffdf;
      if (bRam00f469 != 3) {
        uRam00f581 = 0x79;
        return;
      }
      uVar1 = uRam00f462 + 1;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      UNK_00c2b8 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      egs52_update_near_c2ba_09bca4();
      return;
    }
    uVar1 = Ram00fdea;
    if ((uVar1 & 4) == 0) {
      if (bRam00f469 != 3) {
        uRam00f581 = 0x79;
        return;
      }
      uVar1 = 0x24;
      if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) != '\x05') {
        uVar1 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == '\x06') {
          uRam00f462 = uRam00f462 + 1;
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          UNK_00c2b8 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff));
          UNK_00c102 = 6;
          cVar5 = UNK_00c2b8;
          UNK_00c103 = cVar5;
          if (cVar5 == cRam0cf85e) {
            UNK_00c2c2 = 0xb;
            while( true ) {
              uVar4 = UNK_00c2c2;
              iVar6 = egs52_call_095b6a_095abc(uVar4);
              Ram00c2c0 = iVar6;
              if ((iVar6 == 0) || (cVar5 = UNK_00c2c2, cVar5 == '\x0f')) break;
              cVar5 = UNK_00c2c2;
              UNK_00c2c2 = cVar5 + '\x01';
            }
            cVar5 = UNK_00c2c2;
            if ((cVar5 == '\v') && (iVar6 = Ram00c2c0, iVar6 == 0)) {
              uRam00f581 = 0x22;
              return;
            }
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 | 4;
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 & 0xfff7;
            uRam00f581 = 0x78;
            iRam00f464 = iRam00f464 + (uint)bRam00f469;
            return;
          }
          iVar6 = egs52_call_095b6a_095abc(0xb);
          if (iVar6 == 0) {
            uRam00f581 = 0x22;
            return;
          }
          uRam00f581 = 0;
          bRam00f469 = 2;
          egs52_update_near_c2ba_09bca4();
          return;
        }
        uRam00f581 = 0x22;
        return;
      }
      cVar5 = UNK_00c102;
      if (cVar5 == '\x06') {
        UNK_00c102 = 5;
        UNK_00c103 = 0;
        iVar6 = egs52_call_095b6a_095abc(0xb);
        if (iVar6 == 0) {
          uRam00f581 = 0x42;
          return;
        }
      }
      uRam00f462 = uRam00f462 + 1;
      uVar1 = 0x24;
      if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00c2b8 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff));
      egs52_update_near_c2ba_09bca4();
      return;
    }
    uVar1 = Ram00fdea;
    if ((uVar1 & 8) != 0) {
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xfffb;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xfff7;
      uRam00f581 = 0;
      bRam00f469 = 2;
      egs52_update_near_c2ba_09bca4();
      return;
    }
    iVar6 = Ram00c2c0;
    if (iVar6 == 0) {
      while( true ) {
        uVar4 = UNK_00c2c2;
        iVar6 = egs52_call_095b6a_095abc(uVar4);
        Ram00c2c0 = iVar6;
        if (iVar6 == 0) {
          return;
        }
        cVar5 = UNK_00c2c2;
        if (cVar5 == '\x0f') break;
        cVar5 = UNK_00c2c2;
        UNK_00c2c2 = cVar5 + '\x01';
      }
    }
    else {
      cVar5 = UNK_00c2c2;
      if (cVar5 == '\x0f') {
        uVar3 = Ram00c2c0;
        cVar5 = egs52_call_095b6a_095b38(uVar3,0xf);
        if (cVar5 == '\x03') {
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 | 8;
          return;
        }
      }
    }
  }
  else {
    egs52_update_near_c2ba_09bca4();
  }
  return;
}


