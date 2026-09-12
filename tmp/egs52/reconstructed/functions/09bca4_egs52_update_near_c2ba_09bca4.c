/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bca4; FLS offset 0x01bca4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09be40) */
/* WARNING: Removing unreachable block (ram,0x09be3c) */
/* WARNING: Removing unreachable block (ram,0x09be38) */
/* WARNING: Removing unreachable block (ram,0x09be32) */
/* WARNING: Removing unreachable block (ram,0x09be24) */
/* WARNING: Removing unreachable block (ram,0x09be0a) */
/* WARNING: Removing unreachable block (ram,0x09be04) */
/* WARNING: Removing unreachable block (ram,0x09bdfa) */
/* WARNING: Removing unreachable block (ram,0x09bde8) */
/* WARNING: Removing unreachable block (ram,0x09bdd4) */
/* WARNING: Removing unreachable block (ram,0x09bdcc) */
/* WARNING: Removing unreachable block (ram,0x09bdc8) */
/* WARNING: Removing unreachable block (ram,0x09bdc2) */
/* WARNING: Removing unreachable block (ram,0x09bdbc) */
/* WARNING: Removing unreachable block (ram,0x09bda8) */
/* WARNING: Removing unreachable block (ram,0x09bda4) */
/* WARNING: Removing unreachable block (ram,0x09bda0) */
/* WARNING: Removing unreachable block (ram,0x09bd9c) */
/* WARNING: Removing unreachable block (ram,0x09bd76) */
/* WARNING: Removing unreachable block (ram,0x09bd72) */
/* WARNING: Removing unreachable block (ram,0x09bd6e) */
/* WARNING: Removing unreachable block (ram,0x09bd6a) */
/* WARNING: Removing unreachable block (ram,0x09bd64) */
/* WARNING: Removing unreachable block (ram,0x09bd50) */
/* WARNING: Removing unreachable block (ram,0x09bd94) */
/* WARNING: Removing unreachable block (ram,0x09bd90) */
/* WARNING: Removing unreachable block (ram,0x09bd8c) */
/* WARNING: Removing unreachable block (ram,0x09bd88) */
/* WARNING: Removing unreachable block (ram,0x09bd82) */
/* WARNING: Removing unreachable block (ram,0x09bd46) */
/* WARNING: Removing unreachable block (ram,0x09bd3e) */
/* WARNING: Removing unreachable block (ram,0x09bd3a) */
/* WARNING: Removing unreachable block (ram,0x09bd34) */
/* WARNING: Removing unreachable block (ram,0x09bd2c) */
/* WARNING: Removing unreachable block (ram,0x09bd28) */
/* WARNING: Removing unreachable block (ram,0x09bd24) */
/* WARNING: Removing unreachable block (ram,0x09bd1e) */
/* WARNING: Removing unreachable block (ram,0x09bd12) */
/* WARNING: Removing unreachable block (ram,0x09bcfa) */
/* WARNING: Removing unreachable block (ram,0x09bcf0) */
/* WARNING: Removing unreachable block (ram,0x09bcd4) */
/* WARNING: Removing unreachable block (ram,0x09bce6) */
/* WARNING: Removing unreachable block (ram,0x09bcbc) */
/* WARNING: Removing unreachable block (ram,0x09bdb6) */
/* WARNING: Removing unreachable block (ram,0x09bcdc) */
/* WARNING: Removing unreachable block (ram,0x09bdf0) */

void egs52_update_near_c2ba_09bca4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  byte bVar7;
  
  uVar1 = Ram00fdea;
  if (((uVar1 & 8) == 0) || (uVar1 = Ram00fdec, (uVar1 & 0x20) == 0)) {
    uVar1 = Ram00fdea;
    if ((uVar1 & 4) == 0) {
      cRam00f581 = '\"';
      egs52_update_near_c2c6_09bbce();
      bVar7 = 0;
      while ((bVar7 < 2 && (cRam00f581 == '\"'))) {
        uVar1 = (uint)bVar7 * 0x34 + 0xe000;
        uVar2 = 0x24;
        if (((uVar1 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))
           )) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
          cRam00f581 = '\0';
        }
        bVar7 = bVar7 + 1;
      }
      if (cRam00f581 == '\0') {
        iVar3 = (uint)(byte)(bVar7 - 1) * 0x34;
        uVar1 = iVar3 + 0xe001;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        egs52_memcpy_near(puRam00f464,(uchar *)(iVar3 + -0x1ffe),
                          (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
        uVar1 = iVar3 + 0xe001;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cRam00f469 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + '\x01';
        puRam00f462 = puRam00f464;
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 | 0x100;
        uRam00f57c = 3;
        uRam00f576 = 1;
        UNK_00c2ba = 0;
        uVar1 = Ram00fd02;
        Ram00fd02 = uVar1 | 0x40;
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 | 0x20;
        cVar6 = UNK_00f814;
        if (cVar6 == -1) {
          if (bRam0904ee == 0) {
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 | 4;
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 | 8;
          }
          else {
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 | 4;
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 & 0xfff7;
            uVar1 = Ram00fdf2;
            iVar3 = Ram00fdf4;
            Ram00c2c8 = bRam0904ee + uVar1;
            Ram00c2ca = iVar3 + (uint)CARRY2((uint)bRam0904ee,uVar1);
          }
        }
        else {
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 | 4;
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 & 0xfff7;
          bVar7 = UNK_00f814;
          uVar1 = Ram00fdf2;
          iVar3 = Ram00fdf4;
          Ram00c2c8 = bVar7 + uVar1;
          Ram00c2ca = iVar3 + (uint)CARRY2((uint)bVar7,uVar1);
        }
      }
    }
    else {
      uVar1 = Ram00c2c8;
      uVar2 = Ram00c2ca;
      uVar4 = Ram00fdf2;
      uVar5 = Ram00fdf4;
      if (uVar2 - uVar5 == (uint)(uVar1 < uVar4) && uVar1 == uVar4 ||
          (uVar2 < uVar5 || uVar2 == uVar5 && uVar1 < uVar4)) {
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 | 8;
      }
    }
  }
  else {
    puRam00f464 = puRam00f464 + -2;
    uRam00f57a = 0xc;
    Ram00feb4 = 0xc;
    cRam00f581 = '\"';
    bVar7 = 0;
    while ((bVar7 < 2 && (cRam00f581 == '\"'))) {
      uVar1 = (uint)bVar7 * 0x34 + 0xe000;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
        cRam00f581 = '\0';
      }
      bVar7 = bVar7 + 1;
    }
    cRam00f581 = '\0';
    iVar3 = (uint)(byte)(bVar7 - 1) * 0x34;
    uVar1 = iVar3 + 0xe001;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_memcpy_near(puRam00f464,(uchar *)(iVar3 + -0x1ffe),
                      (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
    uVar1 = iVar3 + 0xe001;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cRam00f469 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + '\x01';
    puRam00f462 = puRam00f464;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 | 0x100;
    uVar1 = Ram00fd02;
    Ram00fd02 = uVar1 | 0x80;
  }
  return;
}


