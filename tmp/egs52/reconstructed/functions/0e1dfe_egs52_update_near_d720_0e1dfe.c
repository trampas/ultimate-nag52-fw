/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e1dfe; FLS offset 0x061dfe.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e1fcc) */
/* WARNING: Removing unreachable block (ram,0x0e1fc8) */
/* WARNING: Removing unreachable block (ram,0x0e1fc4) */
/* WARNING: Removing unreachable block (ram,0x0e1fb8) */
/* WARNING: Removing unreachable block (ram,0x0e1fac) */
/* WARNING: Removing unreachable block (ram,0x0e1fa6) */
/* WARNING: Removing unreachable block (ram,0x0e1f9c) */
/* WARNING: Removing unreachable block (ram,0x0e1fe4) */
/* WARNING: Removing unreachable block (ram,0x0e1fde) */
/* WARNING: Removing unreachable block (ram,0x0e1fda) */
/* WARNING: Removing unreachable block (ram,0x0e1f8e) */
/* WARNING: Removing unreachable block (ram,0x0e1f8a) */
/* WARNING: Removing unreachable block (ram,0x0e1f82) */
/* WARNING: Removing unreachable block (ram,0x0e1f7e) */
/* WARNING: Removing unreachable block (ram,0x0e1f6e) */
/* WARNING: Removing unreachable block (ram,0x0e1f6a) */
/* WARNING: Removing unreachable block (ram,0x0e1f64) */
/* WARNING: Removing unreachable block (ram,0x0e1f60) */
/* WARNING: Removing unreachable block (ram,0x0e1f5c) */
/* WARNING: Removing unreachable block (ram,0x0e1f58) */
/* WARNING: Removing unreachable block (ram,0x0e1f54) */
/* WARNING: Removing unreachable block (ram,0x0e1f50) */
/* WARNING: Removing unreachable block (ram,0x0e1f4c) */
/* WARNING: Removing unreachable block (ram,0x0e1f48) */
/* WARNING: Removing unreachable block (ram,0x0e1f44) */
/* WARNING: Removing unreachable block (ram,0x0e1f3a) */
/* WARNING: Removing unreachable block (ram,0x0e1f40) */
/* WARNING: Removing unreachable block (ram,0x0e1f02) */
/* WARNING: Removing unreachable block (ram,0x0e1f24) */
/* WARNING: Removing unreachable block (ram,0x0e1f1e) */
/* WARNING: Removing unreachable block (ram,0x0e1f18) */
/* WARNING: Removing unreachable block (ram,0x0e1f10) */
/* WARNING: Removing unreachable block (ram,0x0e1f16) */
/* WARNING: Removing unreachable block (ram,0x0e1f0a) */
/* WARNING: Removing unreachable block (ram,0x0e1efa) */
/* WARNING: Removing unreachable block (ram,0x0e1ef6) */
/* WARNING: Removing unreachable block (ram,0x0e1ef2) */
/* WARNING: Removing unreachable block (ram,0x0e1ee6) */
/* WARNING: Removing unreachable block (ram,0x0e1ee2) */
/* WARNING: Removing unreachable block (ram,0x0e1ede) */
/* WARNING: Removing unreachable block (ram,0x0e1ed6) */
/* WARNING: Removing unreachable block (ram,0x0e1eca) */
/* WARNING: Removing unreachable block (ram,0x0e1ed2) */
/* WARNING: Removing unreachable block (ram,0x0e1ec2) */
/* WARNING: Removing unreachable block (ram,0x0e1ebc) */
/* WARNING: Removing unreachable block (ram,0x0e1eb0) */
/* WARNING: Removing unreachable block (ram,0x0e1eb8) */
/* WARNING: Removing unreachable block (ram,0x0e1ea0) */
/* WARNING: Removing unreachable block (ram,0x0e1e9e) */
/* WARNING: Removing unreachable block (ram,0x0e1e96) */
/* WARNING: Removing unreachable block (ram,0x0e1e88) */
/* WARNING: Removing unreachable block (ram,0x0e1e84) */
/* WARNING: Removing unreachable block (ram,0x0e1e80) */
/* WARNING: Removing unreachable block (ram,0x0e1e74) */
/* WARNING: Removing unreachable block (ram,0x0e1e6c) */
/* WARNING: Removing unreachable block (ram,0x0e1e5c) */
/* WARNING: Removing unreachable block (ram,0x0e1e54) */
/* WARNING: Removing unreachable block (ram,0x0e1e4a) */
/* WARNING: Removing unreachable block (ram,0x0e1e3a) */
/* WARNING: Removing unreachable block (ram,0x0e1e2a) */
/* WARNING: Removing unreachable block (ram,0x0e1e22) */
/* WARNING: Removing unreachable block (ram,0x0e1e12) */
/* WARNING: Removing unreachable block (ram,0x0e1e04) */
/* WARNING: Removing unreachable block (ram,0x0e1fec) */
/* WARNING: Removing unreachable block (ram,0x0e1e50) */
/* WARNING: Removing unreachable block (ram,0x0e1ea8) */
/* WARNING: Removing unreachable block (ram,0x0e1f76) */
/* WARNING: Removing unreachable block (ram,0x0e1fd6) */
/* WARNING: Removing unreachable block (ram,0x0e1fa0) */

void egs52_update_near_d720_0e1dfe(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  short *axis;
  short sVar12;
  int iVar13;
  uint uVar14;
  
  Ram00d720 = 0;
  uVar14 = Ram00fd2e;
  Ram00fd2e = uVar14 & 0xfdff;
  uVar14 = Ram00fd56;
  if (((((uVar14 & 0x1000) != 0) || (iVar13 = Ram00d7bc, iVar13 != 0)) ||
      (uVar14 = Ram00fd58, (uVar14 & 4) != 0)) ||
     (((uVar14 = Ram00fd56, (uVar14 & 1) == 0 || (bVar3 = UNK_00d75c, (bVar3 & 0x80) == 0)) &&
      ((uVar14 = Ram00fd56, (uVar14 & 1) != 0 || (bVar3 = UNK_00d75c, (bVar3 & 8) == 0)))))) {
    Ram00d716 = 0;
    uVar14 = Ram00fd2e;
    Ram00fd2e = uVar14 & 0xfbff;
    uVar14 = Ram00fd30;
    Ram00fd30 = uVar14 & 0xfeff;
    return;
  }
  iVar13 = Ram00d710;
  axis = (short *)Ram00f664;
  iVar4 = Ram00f664;
  sVar12 = Ram00d7ac;
  sVar12 = egs52_curve_s16('\x06',axis,(short *)(iVar4 + 0xc),sVar12);
  Ram00d718 = (int)(((long)iVar13 * (long)sVar12) / 100);
  uVar14 = Ram00fd54;
  if ((uVar14 & 0x20) != 0) {
    iVar13 = Ram00f662;
    uVar14 = iVar13 + 0x69;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
    bVar6 = UNK_00d570;
    bVar7 = UNK_00d570;
    if (bVar3 != bVar7 && bVar6 <= bVar3) {
      bVar3 = UNK_00d774;
      iVar4 = (uint)bVar3 * 2;
      uVar1 = iVar13 + 0x40 + iVar4;
      uVar14 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar14 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar14 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar14 = 3;
      }
      iVar13 = *(int *)((uint3)uVar14 << 0xe | (uint3)(uVar1 & 0x3fff));
      iVar9 = Ram00d718;
      iVar10 = Ram00d718;
      if (iVar13 != iVar10 && iVar9 <= iVar13) {
        iVar13 = Ram00d718;
        if (iVar13 < 0) {
          iVar13 = Ram00d718;
          uVar14 = -iVar13;
        }
        else {
          uVar14 = Ram00d718;
        }
        uVar2 = Ram00d714;
        if (uVar2 <= uVar14) {
          iVar13 = Ram00d718;
          if (iVar13 < 0) {
            iVar13 = Ram00d718;
            iVar13 = -iVar13;
          }
          else {
            iVar13 = Ram00d718;
          }
          Ram00d714 = iVar13;
        }
        uVar14 = Ram00fd48;
        if ((uVar14 & 0x10) != 0) {
          iVar13 = Ram00f65e;
          uVar14 = iVar13 + 0x82;
          uVar2 = 0x24;
          if ((((uVar14 & 0xc000) != 0) && (uVar2 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar3 = UNK_00d437;
          if ((uint)bVar3 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar14 & 0x3fff))) {
            uVar14 = Ram00fd2e;
            Ram00fd2e = uVar14 | 0x400;
            uVar14 = iVar13 + iVar4 + 0x54;
            uVar2 = 0x24;
            if ((((uVar14 & 0xc000) != 0) && (uVar2 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            Ram00d7b0 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar14 & 0x3fff));
          }
        }
        iVar13 = Ram00d7b0;
        if (iVar13 == 0) {
          uVar14 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar14 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar14 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar14 = 3;
          }
          if (*(int *)((uint3)uVar14 << 0xe | (uint3)(uVar1 & 0x3fff)) < 0) {
            uVar14 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar14 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar14 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar14 = 3;
            }
            iVar13 = -*(int *)((uint3)uVar14 << 0xe | (uint3)(uVar1 & 0x3fff));
          }
          else {
            uVar14 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar14 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar14 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar14 = 3;
            }
            iVar13 = *(int *)((uint3)uVar14 << 0xe | (uint3)(uVar1 & 0x3fff));
          }
          iVar9 = Ram00d714;
          iVar10 = Ram00f662;
          uVar14 = iVar10 + iVar4 + 0x48;
          uVar1 = 0x24;
          if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar14 = (iVar9 - iVar13) * *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
        }
        else {
          Ram00d714 = 0;
          uVar14 = 0;
        }
        if (uVar14 < 0x2711) {
          Ram00d716 = uVar14;
        }
        else {
          Ram00d716 = 10000;
        }
        iVar13 = Ram00f662;
        uVar14 = iVar13 + 0x5e;
        uVar1 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        Ram00d7b2 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
        UNK_00d75a = 0;
        iVar13 = Ram00f65a;
        uVar14 = iVar13 + 0x42;
        uVar1 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        Ram00d756 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
        uVar5 = Ram00d500;
        Ram00d78e = uVar5;
        goto LAB_0e1f6e;
      }
    }
  }
  Ram00d714 = 0;
LAB_0e1f6e:
  iVar13 = Ram00d70a;
  if (iVar13 < 0) {
    iVar13 = Ram00d70a;
    iVar13 = -iVar13;
  }
  else {
    iVar13 = Ram00d70a;
  }
  iVar4 = Ram00d70c;
  if (iVar4 < iVar13) {
    Ram00d7b2 = 0;
  }
  iVar13 = Ram00d7b2;
  if (iVar13 == 0) {
    Ram00d716 = 0;
    cVar8 = UNK_00d613;
    cVar11 = UNK_00d76f;
    if (cVar8 == cVar11) {
      Ram00d756 = 0;
      uVar14 = Ram00fd30;
      Ram00fd30 = uVar14 & 0xfeff;
    }
  }
  else {
    uVar14 = Ram00fd30;
    Ram00fd30 = uVar14 | 0x100;
    uVar2 = Ram00d716;
    bVar3 = UNK_00d774;
    iVar13 = Ram00f662;
    uVar14 = iVar13 + (uint)bVar3 * 2 + 0x50;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar13 = (int)(((ulong)uVar2 * (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff)))
                  / 10000);
    Ram00d720 = iVar13;
    if (iVar13 != 0) {
      iVar13 = Ram00f662;
      uVar14 = iVar13 + 0x60;
      uVar1 = 0x24;
      if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = Ram00d716;
      if (*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff)) < uVar2) {
        uVar14 = Ram00fd2e;
        Ram00fd2e = uVar14 | 0x200;
      }
    }
  }
  return;
}


