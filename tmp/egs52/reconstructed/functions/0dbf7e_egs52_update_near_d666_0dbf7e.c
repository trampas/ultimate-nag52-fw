/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dbf7e; FLS offset 0x05bf7e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Removing unreachable block (ram,0x0dc32e) */
/* WARNING: Removing unreachable block (ram,0x0dc32a) */
/* WARNING: Removing unreachable block (ram,0x0dc326) */
/* WARNING: Removing unreachable block (ram,0x0dc322) */
/* WARNING: Removing unreachable block (ram,0x0dc31c) */
/* WARNING: Removing unreachable block (ram,0x0dc318) */
/* WARNING: Removing unreachable block (ram,0x0dc314) */
/* WARNING: Removing unreachable block (ram,0x0dc310) */
/* WARNING: Removing unreachable block (ram,0x0dc30c) */
/* WARNING: Removing unreachable block (ram,0x0dc306) */
/* WARNING: Removing unreachable block (ram,0x0dc304) */
/* WARNING: Removing unreachable block (ram,0x0dc2fc) */
/* WARNING: Removing unreachable block (ram,0x0dc2f8) */
/* WARNING: Removing unreachable block (ram,0x0dc2f0) */
/* WARNING: Removing unreachable block (ram,0x0dbfb0) */
/* WARNING: Removing unreachable block (ram,0x0dbfac) */
/* WARNING: Removing unreachable block (ram,0x0dbfa8) */
/* WARNING: Removing unreachable block (ram,0x0dbfa4) */
/* WARNING: Removing unreachable block (ram,0x0dbfa0) */
/* WARNING: Removing unreachable block (ram,0x0dbf9c) */
/* WARNING: Removing unreachable block (ram,0x0dbfe0) */
/* WARNING: Removing unreachable block (ram,0x0dbfdc) */
/* WARNING: Removing unreachable block (ram,0x0dbfce) */
/* WARNING: Removing unreachable block (ram,0x0dbfd8) */
/* WARNING: Removing unreachable block (ram,0x0dbfd4) */
/* WARNING: Removing unreachable block (ram,0x0dbfc8) */
/* WARNING: Removing unreachable block (ram,0x0dbfc0) */
/* WARNING: Removing unreachable block (ram,0x0dbfbc) */
/* WARNING: Removing unreachable block (ram,0x0dbfb8) */
/* WARNING: Removing unreachable block (ram,0x0dc094) */
/* WARNING: Removing unreachable block (ram,0x0dc08c) */
/* WARNING: Removing unreachable block (ram,0x0dc084) */
/* WARNING: Removing unreachable block (ram,0x0dc080) */
/* WARNING: Removing unreachable block (ram,0x0dc07c) */
/* WARNING: Removing unreachable block (ram,0x0dc06a) */
/* WARNING: Removing unreachable block (ram,0x0dc056) */
/* WARNING: Removing unreachable block (ram,0x0dc052) */
/* WARNING: Removing unreachable block (ram,0x0dc046) */
/* WARNING: Removing unreachable block (ram,0x0dc03c) */
/* WARNING: Removing unreachable block (ram,0x0dc042) */
/* WARNING: Removing unreachable block (ram,0x0dc036) */
/* WARNING: Removing unreachable block (ram,0x0dc032) */
/* WARNING: Removing unreachable block (ram,0x0dc02a) */
/* WARNING: Removing unreachable block (ram,0x0dc01c) */
/* WARNING: Removing unreachable block (ram,0x0dc014) */
/* WARNING: Removing unreachable block (ram,0x0dc010) */
/* WARNING: Removing unreachable block (ram,0x0dc00c) */
/* WARNING: Removing unreachable block (ram,0x0dc172) */
/* WARNING: Removing unreachable block (ram,0x0dc16e) */
/* WARNING: Removing unreachable block (ram,0x0dc166) */
/* WARNING: Removing unreachable block (ram,0x0dc15e) */
/* WARNING: Removing unreachable block (ram,0x0dc15a) */
/* WARNING: Removing unreachable block (ram,0x0dc156) */
/* WARNING: Removing unreachable block (ram,0x0dc136) */
/* WARNING: Removing unreachable block (ram,0x0dc132) */
/* WARNING: Removing unreachable block (ram,0x0dc11c) */
/* WARNING: Removing unreachable block (ram,0x0dc118) */
/* WARNING: Removing unreachable block (ram,0x0dc10a) */
/* WARNING: Removing unreachable block (ram,0x0dc102) */
/* WARNING: Removing unreachable block (ram,0x0dc0fa) */
/* WARNING: Removing unreachable block (ram,0x0dc0f6) */
/* WARNING: Removing unreachable block (ram,0x0dc0f2) */
/* WARNING: Removing unreachable block (ram,0x0dc25a) */
/* WARNING: Removing unreachable block (ram,0x0dc256) */
/* WARNING: Removing unreachable block (ram,0x0dc252) */
/* WARNING: Removing unreachable block (ram,0x0dc24e) */
/* WARNING: Removing unreachable block (ram,0x0dc24a) */
/* WARNING: Removing unreachable block (ram,0x0dc246) */
/* WARNING: Removing unreachable block (ram,0x0dc242) */
/* WARNING: Removing unreachable block (ram,0x0dc230) */
/* WARNING: Removing unreachable block (ram,0x0dc21c) */
/* WARNING: Removing unreachable block (ram,0x0dc218) */
/* WARNING: Removing unreachable block (ram,0x0dc20c) */
/* WARNING: Removing unreachable block (ram,0x0dc208) */
/* WARNING: Removing unreachable block (ram,0x0dc2b4) */
/* WARNING: Removing unreachable block (ram,0x0dc2b0) */
/* WARNING: Removing unreachable block (ram,0x0dc29e) */
/* WARNING: Removing unreachable block (ram,0x0dc28a) */
/* WARNING: Removing unreachable block (ram,0x0dc286) */
/* WARNING: Removing unreachable block (ram,0x0dc27a) */
/* WARNING: Removing unreachable block (ram,0x0dc2ea) */
/* WARNING: Removing unreachable block (ram,0x0dc2e6) */
/* WARNING: Removing unreachable block (ram,0x0dc2e2) */
/* WARNING: Removing unreachable block (ram,0x0dc2de) */
/* WARNING: Removing unreachable block (ram,0x0dc2d6) */
/* WARNING: Removing unreachable block (ram,0x0dc2d2) */
/* WARNING: Removing unreachable block (ram,0x0dc2ca) */
/* WARNING: Removing unreachable block (ram,0x0dc2c2) */
/* WARNING: Removing unreachable block (ram,0x0dc2be) */
/* WARNING: Removing unreachable block (ram,0x0dc2ba) */
/* WARNING: Removing unreachable block (ram,0x0dc274) */
/* WARNING: Removing unreachable block (ram,0x0dc26c) */
/* WARNING: Removing unreachable block (ram,0x0dc268) */
/* WARNING: Removing unreachable block (ram,0x0dc264) */
/* WARNING: Removing unreachable block (ram,0x0dc1f8) */
/* WARNING: Removing unreachable block (ram,0x0dc1f2) */
/* WARNING: Removing unreachable block (ram,0x0dc1ee) */
/* WARNING: Removing unreachable block (ram,0x0dc1e6) */
/* WARNING: Removing unreachable block (ram,0x0dc1de) */
/* WARNING: Removing unreachable block (ram,0x0dc1da) */
/* WARNING: Removing unreachable block (ram,0x0dc1d2) */
/* WARNING: Removing unreachable block (ram,0x0dc1ce) */
/* WARNING: Removing unreachable block (ram,0x0dc1c6) */
/* WARNING: Removing unreachable block (ram,0x0dc1c2) */
/* WARNING: Removing unreachable block (ram,0x0dc1be) */
/* WARNING: Removing unreachable block (ram,0x0dc1b6) */
/* WARNING: Removing unreachable block (ram,0x0dc1b0) */
/* WARNING: Removing unreachable block (ram,0x0dc1ac) */
/* WARNING: Removing unreachable block (ram,0x0dc1a2) */
/* WARNING: Removing unreachable block (ram,0x0dc19e) */
/* WARNING: Removing unreachable block (ram,0x0dc196) */
/* WARNING: Removing unreachable block (ram,0x0dc192) */
/* WARNING: Removing unreachable block (ram,0x0dc18a) */
/* WARNING: Removing unreachable block (ram,0x0dc186) */
/* WARNING: Removing unreachable block (ram,0x0dc182) */
/* WARNING: Removing unreachable block (ram,0x0dc17e) */
/* WARNING: Removing unreachable block (ram,0x0dc17a) */
/* WARNING: Removing unreachable block (ram,0x0dc0ea) */
/* WARNING: Removing unreachable block (ram,0x0dc0e6) */
/* WARNING: Removing unreachable block (ram,0x0dc0de) */
/* WARNING: Removing unreachable block (ram,0x0dc0d6) */
/* WARNING: Removing unreachable block (ram,0x0dc0ce) */
/* WARNING: Removing unreachable block (ram,0x0dc0b8) */
/* WARNING: Removing unreachable block (ram,0x0dc0b4) */
/* WARNING: Removing unreachable block (ram,0x0dc0ae) */
/* WARNING: Removing unreachable block (ram,0x0dc0a6) */
/* WARNING: Removing unreachable block (ram,0x0dc09c) */
/* WARNING: Removing unreachable block (ram,0x0dc004) */
/* WARNING: Removing unreachable block (ram,0x0dbffc) */
/* WARNING: Removing unreachable block (ram,0x0dbff4) */
/* WARNING: Removing unreachable block (ram,0x0dbfe8) */
/* WARNING: Removing unreachable block (ram,0x0dbf80) */
/* WARNING: Removing unreachable block (ram,0x0dc0bc) */
/* WARNING: Removing unreachable block (ram,0x0dc0d2) */
/* WARNING: Removing unreachable block (ram,0x0dc10e) */
/* WARNING: Removing unreachable block (ram,0x0dc162) */
/* WARNING: Removing unreachable block (ram,0x0dc16a) */
/* WARNING: Removing unreachable block (ram,0x0dc020) */
/* WARNING: Removing unreachable block (ram,0x0dc088) */
/* WARNING: Removing unreachable block (ram,0x0dc090) */
/* WARNING: Removing unreachable block (ram,0x0dbfc4) */
/* WARNING: Removing unreachable block (ram,0x0dbf98) */
/* WARNING: Removing unreachable block (ram,0x0dc2f4) */

void egs52_update_near_d666_0dbf7e(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  ushort old;
  ushort uVar14;
  uint uVar15;
  
  cVar6 = UNK_00d704;
  if (cVar6 == '\0') {
    Ram00d666 = 0;
    Ram00d668 = 0;
    Ram00d706 = 0;
    goto LAB_0dc2fc;
  }
  if (cVar6 == '\x01') {
    Ram00d666 = 0;
    Ram00d6f8 = 0;
    uVar8 = Ram00d668;
    Ram00d706 = uVar8;
    iVar2 = Ram00f652;
    uVar15 = iVar2 + 0x6e;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    UNK_00d697 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    goto LAB_0dc2fc;
  }
  if (cVar6 == '\x02') {
    Ram00d666 = 0;
    Ram00d6f8 = 0;
    iVar2 = Ram00f652;
    uVar15 = iVar2 + 0x74;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar15 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    uVar4 = Ram00d668;
    if (uVar15 < uVar4) {
      iVar2 = Ram00d668;
      Ram00d668 = iVar2 - uVar15;
    }
    else {
      UNK_00d704 = 0;
      Ram00d668 = 0;
    }
    uVar8 = Ram00d668;
    Ram00d706 = uVar8;
    goto LAB_0dc2fc;
  }
  if (cVar6 != '\x03') goto LAB_0dc2fc;
  Ram00d668 = 0;
  egs52_update_near_d68a_0dbbbc();
  egs52_update_near_d6b4_0dbe10();
  uVar15 = Ram00fd2a;
  if ((((uVar15 & 0x100) != 0) || (uVar15 = Ram00fd2a, (uVar15 & 0x200) != 0)) &&
     (bVar3 = UNK_00d646, (bVar3 & 0x40) != 0)) {
    iVar2 = Ram00f652;
    uVar15 = iVar2 + 0x6e;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    UNK_00d697 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    uVar7 = Ram00d6f8;
    uVar15 = iVar2 + 0x79;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d706 = (int)(((ulong)uVar7 *
                      (ulong)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff))) / 100);
    uVar15 = Ram00d660;
    uVar4 = Ram00d706;
    uVar7 = Ram00d706;
    if (uVar15 == uVar7 || uVar15 < uVar4) {
      uVar15 = Ram00d706;
    }
    else {
      uVar15 = Ram00d660;
    }
    Ram00d706 = uVar15;
    iVar1 = Ram00d69a;
    iVar2 = Ram00d662;
    uVar4 = (uint)(((long)iVar1 * (long)iVar2) / 1000);
    uVar7 = Ram00d6f8;
    lVar5 = CONCAT22((-(uint)(uVar15 < uVar4) - ((int)uVar4 >> 0xf)) -
                     (uint)(uVar15 - uVar4 < uVar7),(uVar15 - uVar4) - uVar7) * 10;
    Ram00d670 = (int)lVar5;
    Ram00d672 = (int)((ulong)lVar5 >> 0x10);
    iVar2 = Ram00f652;
    uVar15 = iVar2 + 0x80;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d684 = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    uVar15 = iVar2 + 0xf0;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d6ec = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    goto LAB_0dc2fc;
  }
  cVar6 = UNK_00d650;
  if ((cVar6 == '\x03') && (bVar3 = UNK_00d646, (bVar3 & 0x20) != 0)) {
    cVar6 = UNK_00d651;
    if (cVar6 != '\0') {
      bVar3 = UNK_00d697;
      iVar2 = Ram00f652;
      uVar15 = iVar2 + 0x6e;
      uVar4 = 0x24;
      if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (((int)(*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) - 1) <= (int)(uint)bVar3)
         && (cVar6 != '\x06')) goto LAB_0dc17a;
    }
    iVar2 = Ram00f652;
    uVar15 = iVar2 + 0xbe;
    uVar4 = 0x24;
    if (((uVar15 & 0xc000) != 0) &&
       ((uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000 && (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000))))
    {
      uVar4 = 3;
    }
    uVar15 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
    uVar4 = Ram00d63e;
    uVar7 = Ram00d63e;
    if ((uVar15 != uVar7 && uVar4 <= uVar15) && (uVar15 = Ram00fd2c, (uVar15 & 0x20) != 0)) {
      uVar15 = iVar2 + 0xd8;
      uVar4 = 0x24;
      if (((uVar15 & 0xc000) != 0) &&
         ((uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000 && (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000))
         )) {
        uVar4 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
      bVar10 = UNK_00d697;
      bVar11 = UNK_00d697;
      if (bVar3 == bVar11 || bVar3 < bVar10) {
        old = Ram00d706;
        uVar14 = Ram00d660;
        bVar3 = UNK_00d697;
        uVar14 = egs52_ramp_u16(old,uVar14,(uint)bVar3);
        Ram00d706 = uVar14;
        iVar2 = Ram00f652;
        uVar15 = iVar2 + 0x6d;
        uVar4 = 0x24;
        if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        iVar2 = Ram00d6f8;
        iVar1 = Ram00d706;
        uVar15 = (uint)(((long)(int)(*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) - 100
                                    ) * (long)(iVar2 - iVar1)) / 100);
        iVar1 = Ram00d69a;
        iVar2 = Ram00d662;
        uVar4 = (uint)(((long)iVar1 * (long)iVar2) / 1000);
        lVar5 = CONCAT22((((int)uVar15 >> 0xf) - ((int)uVar4 >> 0xf)) - (uint)(uVar15 < uVar4),
                         uVar15 - uVar4) * 10;
        Ram00d670 = (int)lVar5;
        Ram00d672 = (int)((ulong)lVar5 >> 0x10);
        iVar2 = Ram00f652;
        uVar15 = iVar2 + 0x80;
        uVar4 = 0x24;
        if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        Ram00d684 = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
        uVar15 = iVar2 + 0xf0;
        uVar4 = 0x24;
        if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        Ram00d6ec = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
        Ram00d692 = 0;
        goto LAB_0dc2fc;
      }
    }
  }
LAB_0dc17a:
  iVar2 = Ram00f652;
  uVar15 = iVar2 + 0x6e;
  uVar4 = 0x24;
  if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  UNK_00d697 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
  uVar15 = iVar2 + 0xfa;
  uVar4 = 0x24;
  if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar1 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
  iVar12 = Ram00d6e0;
  iVar13 = Ram00d6e0;
  if (iVar1 != iVar13 && iVar12 <= iVar1) {
    uVar15 = iVar2 + 0xfc;
    uVar4 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    iVar1 = Ram00d6e0;
    if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) < iVar1) {
      iVar1 = Ram00d63e;
      uVar15 = iVar2 + 0xfe;
      uVar4 = 0x24;
      if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) < iVar1) {
        uVar15 = iVar2 + 0x100;
        uVar4 = 0x24;
        if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        iVar2 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
        iVar1 = Ram00d6be;
        iVar12 = Ram00d6be;
        if ((iVar2 != iVar12 && iVar1 <= iVar2) || (uVar15 = Ram00fd2c, (uVar15 & 0x400) != 0)) {
          iVar2 = Ram00f652;
          uVar15 = iVar2 + 0x102;
          uVar4 = 0x24;
          if (((uVar15 & 0xc000) != 0) &&
             ((uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000 &&
              (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)))) {
            uVar4 = 3;
          }
          iVar1 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
          iVar12 = Ram00d6be;
          iVar13 = Ram00d6be;
          if (iVar1 != iVar13 && iVar12 <= iVar1) {
            uVar15 = iVar2 + 0x104;
            uVar4 = 0x24;
            if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            iVar1 = Ram00d644;
            if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) < iVar1) {
              uVar15 = iVar2 + 0x106;
              uVar4 = 0x24;
              if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              iVar1 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
              iVar12 = Ram00d644;
              iVar13 = Ram00d644;
              if ((iVar1 != iVar13 && iVar12 <= iVar1) && (uVar15 = Ram00fd2c, (uVar15 & 0x20) != 0)
                 ) {
                uVar15 = iVar2 + 0x108;
                uVar4 = 0x24;
                if (((uVar15 & 0xc000) != 0) &&
                   ((uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000 &&
                    (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)))) {
                  uVar4 = 3;
                }
                uVar15 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
                uVar4 = Ram00d640;
                uVar7 = Ram00d640;
                if (uVar15 != uVar7 && uVar4 <= uVar15) {
                  uVar15 = iVar2 + 0xf4;
                  uVar4 = 0x24;
                  if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  if ((*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) & 0x10) != 0) {
                    uVar15 = Ram00fd2c;
                    Ram00fd2c = uVar15 | 0x400;
                    uVar4 = Ram00d660;
                    Ram00d706 = uVar4;
                    iVar1 = Ram00d69a;
                    iVar2 = Ram00d662;
                    uVar15 = (uint)(((long)iVar1 * (long)iVar2) / 1000);
                    uVar7 = Ram00d6f8;
                    lVar5 = CONCAT22((-(uint)(uVar4 < uVar15) - ((int)uVar15 >> 0xf)) -
                                     (uint)(uVar4 - uVar15 < uVar7),(uVar4 - uVar15) - uVar7) * 10;
                    Ram00d670 = (int)lVar5;
                    Ram00d672 = (int)((ulong)lVar5 >> 0x10);
                    iVar2 = Ram00f652;
                    uVar15 = iVar2 + 0x80;
                    uVar4 = 0x24;
                    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
                       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
                      uVar4 = 3;
                    }
                    Ram00d684 = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
                    uVar15 = iVar2 + 0xf0;
                    uVar4 = 0x24;
                    if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
                       (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
                      uVar4 = 3;
                    }
                    Ram00d6ec = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff));
                    goto LAB_0dc2fc;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar15 = Ram00fd2c;
  Ram00fd2c = uVar15 & 0xfbff;
  iVar1 = Ram00d6f8;
  iVar2 = Ram00d666;
  uVar15 = Ram00d660;
  if ((iVar1 + iVar2 < (int)uVar15) && (iVar2 = Ram00d692, iVar2 == 0)) {
    Ram00d706 = uVar15;
    iVar1 = Ram00d69a;
    iVar2 = Ram00d662;
    uVar4 = (uint)(((long)iVar1 * (long)iVar2) / 1000);
    uVar7 = Ram00d6f8;
    lVar5 = CONCAT22((-(uint)(uVar15 < uVar4) - ((int)uVar4 >> 0xf)) -
                     (uint)(uVar15 - uVar4 < uVar7),(uVar15 - uVar4) - uVar7) * 10;
    Ram00d670 = (int)lVar5;
    Ram00d672 = (int)((ulong)lVar5 >> 0x10);
  }
  else {
    iVar1 = Ram00d6f8;
    iVar2 = Ram00d666;
    Ram00d706 = iVar1 + iVar2;
    uVar15 = Ram00fd2a;
    if ((uVar15 & 0x400) != 0) {
      uVar15 = Ram00fd2a;
      if ((uVar15 & 1) == 0) {
        iVar2 = Ram00f652;
        uVar15 = iVar2 + 0xf4;
        uVar4 = 0x24;
        if ((((uVar15 & 0xc000) != 0) && (uVar4 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if ((*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar15 & 0x3fff)) & 8) != 0) goto LAB_0dc2fc;
      }
      uVar8 = Ram00d68a;
      uVar9 = Ram00d68c;
      Ram00d670 = uVar8;
      Ram00d672 = uVar9;
    }
  }
LAB_0dc2fc:
  iVar2 = Ram00f652;
  uVar4 = iVar2 + 0x7c;
  uVar15 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar15 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar15 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar15 = 3;
  }
  uVar7 = Ram00d706;
  if (*(uint *)((uint3)uVar15 << 0xe | (uint3)(uVar4 & 0x3fff)) < uVar7) {
    uVar15 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar15 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar15 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar15 = 3;
    }
    Ram00d706 = *(undefined2 *)((uint3)uVar15 << 0xe | (uint3)(uVar4 & 0x3fff));
    uVar4 = Ram00d670;
    iVar2 = Ram00d672;
    uVar7 = Ram00d68a;
    iVar1 = Ram00d68c;
    uVar15 = (uint)(uVar4 < uVar7);
    if ((iVar2 - iVar1 != uVar15 || uVar4 != uVar7) &&
        (int)((iVar2 - iVar1) - uVar15) < 0 ==
        (SBORROW2(iVar2,iVar1) != SBORROW2(iVar2 - iVar1,(uint)(uVar4 < uVar7)))) {
      uVar8 = Ram00d68a;
      uVar9 = Ram00d68c;
      Ram00d670 = uVar8;
      Ram00d672 = uVar9;
    }
  }
  return;
}


