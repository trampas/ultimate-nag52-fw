/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0db2b4; FLS offset 0x05b2b4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0db34e) */
/* WARNING: Removing unreachable block (ram,0x0db34a) */
/* WARNING: Removing unreachable block (ram,0x0db346) */
/* WARNING: Removing unreachable block (ram,0x0db342) */
/* WARNING: Removing unreachable block (ram,0x0db33e) */
/* WARNING: Removing unreachable block (ram,0x0db338) */
/* WARNING: Removing unreachable block (ram,0x0db334) */
/* WARNING: Removing unreachable block (ram,0x0db32c) */
/* WARNING: Removing unreachable block (ram,0x0db326) */
/* WARNING: Removing unreachable block (ram,0x0db31a) */
/* WARNING: Removing unreachable block (ram,0x0db310) */
/* WARNING: Removing unreachable block (ram,0x0db30c) */
/* WARNING: Removing unreachable block (ram,0x0db308) */
/* WARNING: Removing unreachable block (ram,0x0db2fc) */
/* WARNING: Removing unreachable block (ram,0x0db2f4) */
/* WARNING: Removing unreachable block (ram,0x0db2ee) */
/* WARNING: Removing unreachable block (ram,0x0db2ea) */
/* WARNING: Removing unreachable block (ram,0x0db2e4) */
/* WARNING: Removing unreachable block (ram,0x0db2de) */
/* WARNING: Removing unreachable block (ram,0x0db2da) */
/* WARNING: Removing unreachable block (ram,0x0db2d6) */
/* WARNING: Removing unreachable block (ram,0x0db2d0) */
/* WARNING: Removing unreachable block (ram,0x0db2ca) */
/* WARNING: Removing unreachable block (ram,0x0db2c4) */
/* WARNING: Removing unreachable block (ram,0x0db2bc) */
/* WARNING: Removing unreachable block (ram,0x0db404) */
/* WARNING: Removing unreachable block (ram,0x0db3fe) */
/* WARNING: Removing unreachable block (ram,0x0db3fa) */
/* WARNING: Removing unreachable block (ram,0x0db3f4) */
/* WARNING: Removing unreachable block (ram,0x0db3f0) */
/* WARNING: Removing unreachable block (ram,0x0db3ec) */
/* WARNING: Removing unreachable block (ram,0x0db3e4) */
/* WARNING: Removing unreachable block (ram,0x0db3e0) */
/* WARNING: Removing unreachable block (ram,0x0db3dc) */
/* WARNING: Removing unreachable block (ram,0x0db3d8) */
/* WARNING: Removing unreachable block (ram,0x0db3d2) */
/* WARNING: Removing unreachable block (ram,0x0db3ce) */
/* WARNING: Removing unreachable block (ram,0x0db3ca) */
/* WARNING: Removing unreachable block (ram,0x0db3c6) */
/* WARNING: Removing unreachable block (ram,0x0db3b4) */
/* WARNING: Removing unreachable block (ram,0x0db3b0) */
/* WARNING: Removing unreachable block (ram,0x0db3ac) */
/* WARNING: Removing unreachable block (ram,0x0db3a4) */
/* WARNING: Removing unreachable block (ram,0x0db3a0) */
/* WARNING: Removing unreachable block (ram,0x0db39a) */
/* WARNING: Removing unreachable block (ram,0x0db396) */
/* WARNING: Removing unreachable block (ram,0x0db392) */
/* WARNING: Removing unreachable block (ram,0x0db388) */
/* WARNING: Removing unreachable block (ram,0x0db384) */
/* WARNING: Removing unreachable block (ram,0x0db380) */
/* WARNING: Removing unreachable block (ram,0x0db374) */
/* WARNING: Removing unreachable block (ram,0x0db36c) */
/* WARNING: Removing unreachable block (ram,0x0db366) */
/* WARNING: Removing unreachable block (ram,0x0db35e) */
/* WARNING: Removing unreachable block (ram,0x0db358) */
/* WARNING: Removing unreachable block (ram,0x0db2b4) */
/* WARNING: Removing unreachable block (ram,0x0db354) */
/* WARNING: Removing unreachable block (ram,0x0db2c0) */
/* WARNING: Removing unreachable block (ram,0x0db322) */
/* WARNING: Removing unreachable block (ram,0x0db330) */

void egs52_update_near_d692_0db2b4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  undefined2 uVar11;
  
  uVar1 = Ram00fd2a;
  if ((uVar1 & 1) != 0) {
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0xd4;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar7 = Ram00d644;
    if ((*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar7) &&
       (cVar10 = UNK_00d650, cVar10 == '\0')) {
      uVar1 = iVar6 + 0x4c;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      Ram00d692 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0x4e;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar7 = Ram00d6be;
    if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar7) {
      uVar1 = iVar6 + 0xe5;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      bVar5 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      bVar8 = UNK_00d648;
      bVar9 = UNK_00d648;
      if (bVar5 == bVar9 || bVar5 < bVar8) {
        uVar1 = Ram00fd2c;
        if ((uVar1 & 0x10) != 0) goto LAB_0db322;
        uVar1 = iVar6 + 5;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) != 0) goto LAB_0db322;
      }
    }
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0x4d;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    bVar5 = UNK_00d648;
    if (((bVar5 <= *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) ||
        (uVar1 = Ram00fd2c, (uVar1 & 0x10) != 0)) && (iVar6 = Ram00d644, iVar6 < 1)) {
      uVar11 = Ram00d660;
      Ram00d706 = uVar11;
      Ram00d670 = 0;
      Ram00d672 = 0;
      uVar1 = Ram00fd2a;
      Ram00fd2a = uVar1 & 0xfffe;
      iVar6 = Ram00f652;
      uVar1 = iVar6 + 0x80;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      Ram00d684 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = iVar6 + 0xf0;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      Ram00d6ec = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      return;
    }
LAB_0db322:
    uVar11 = Ram00d670;
    Ram00d6ac = uVar11;
    return;
  }
  iVar6 = Ram00f652;
  uVar1 = iVar6 + 0x4e;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = iVar6 + 0x4a;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar7 = Ram00d6be;
  if ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) +
      (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar7) {
    uVar1 = Ram00fd2c;
    if ((uVar1 & 0x10) != 0) goto LAB_0db3a0;
    uVar1 = iVar6 + 5;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) != 0) goto LAB_0db3a0;
  }
  iVar6 = Ram00f652;
  uVar1 = iVar6 + 0x4d;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar5 = UNK_00d648;
  if ((bVar5 <= *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) ||
     (uVar1 = Ram00fd2c, (uVar1 & 0x10) != 0)) {
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0xde;
    uVar3 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar3 = 3;
    }
    iVar6 = Ram00d644;
    if (iVar6 <= *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      return;
    }
  }
LAB_0db3a0:
  uVar11 = Ram00d660;
  Ram00d706 = uVar11;
  iVar6 = Ram00d6ac;
  iVar7 = Ram00f652;
  uVar1 = iVar7 + 0x4b;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar6 = (int)(((long)iVar6 *
                (long)(int)(uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
  Ram00d670 = iVar6;
  Ram00d672 = iVar6 >> 0xf;
  Ram00d68a = iVar6;
  Ram00d68c = iVar6 >> 0xf;
  uVar1 = Ram00fd2a;
  Ram00fd2a = uVar1 | 1;
  uVar1 = iVar7 + 0x80;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d684 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar7 + 0xf0;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d6ec = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  egs52_update_near_d6b4_0dbe10();
  uVar11 = Ram00d678;
  Ram00d6f8 = uVar11;
  cVar10 = UNK_00d650;
  if (cVar10 == '\0') {
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0x4c;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d692 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  return;
}


