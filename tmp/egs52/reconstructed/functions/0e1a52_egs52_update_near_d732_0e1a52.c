/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e1a52; FLS offset 0x061a52.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e1c88) */
/* WARNING: Removing unreachable block (ram,0x0e1c82) */
/* WARNING: Removing unreachable block (ram,0x0e1c7e) */
/* WARNING: Removing unreachable block (ram,0x0e1c74) */
/* WARNING: Removing unreachable block (ram,0x0e1c6e) */
/* WARNING: Removing unreachable block (ram,0x0e1c6a) */
/* WARNING: Removing unreachable block (ram,0x0e1c66) */
/* WARNING: Removing unreachable block (ram,0x0e1c60) */
/* WARNING: Removing unreachable block (ram,0x0e1c58) */
/* WARNING: Removing unreachable block (ram,0x0e1c4c) */
/* WARNING: Removing unreachable block (ram,0x0e1c3e) */
/* WARNING: Removing unreachable block (ram,0x0e1c38) */
/* WARNING: Removing unreachable block (ram,0x0e1c30) */
/* WARNING: Removing unreachable block (ram,0x0e1c24) */
/* WARNING: Removing unreachable block (ram,0x0e1c1e) */
/* WARNING: Removing unreachable block (ram,0x0e1c16) */
/* WARNING: Removing unreachable block (ram,0x0e1bfc) */
/* WARNING: Removing unreachable block (ram,0x0e1bf6) */
/* WARNING: Removing unreachable block (ram,0x0e1bee) */
/* WARNING: Removing unreachable block (ram,0x0e1bd6) */
/* WARNING: Removing unreachable block (ram,0x0e1bd0) */
/* WARNING: Removing unreachable block (ram,0x0e1bc8) */
/* WARNING: Removing unreachable block (ram,0x0e1bbc) */
/* WARNING: Removing unreachable block (ram,0x0e1bae) */
/* WARNING: Removing unreachable block (ram,0x0e1ba8) */
/* WARNING: Removing unreachable block (ram,0x0e1ba0) */
/* WARNING: Removing unreachable block (ram,0x0e1b94) */
/* WARNING: Removing unreachable block (ram,0x0e1b8e) */
/* WARNING: Removing unreachable block (ram,0x0e1b86) */
/* WARNING: Removing unreachable block (ram,0x0e1b6c) */
/* WARNING: Removing unreachable block (ram,0x0e1b66) */
/* WARNING: Removing unreachable block (ram,0x0e1b5e) */
/* WARNING: Removing unreachable block (ram,0x0e1b50) */
/* WARNING: Removing unreachable block (ram,0x0e1b4a) */
/* WARNING: Removing unreachable block (ram,0x0e1b42) */
/* WARNING: Removing unreachable block (ram,0x0e1b3e) */
/* WARNING: Removing unreachable block (ram,0x0e1b3a) */
/* WARNING: Removing unreachable block (ram,0x0e1b34) */
/* WARNING: Removing unreachable block (ram,0x0e1b26) */
/* WARNING: Removing unreachable block (ram,0x0e1b22) */
/* WARNING: Removing unreachable block (ram,0x0e1b1e) */
/* WARNING: Removing unreachable block (ram,0x0e1b1a) */
/* WARNING: Removing unreachable block (ram,0x0e1b14) */
/* WARNING: Removing unreachable block (ram,0x0e1b0c) */
/* WARNING: Removing unreachable block (ram,0x0e1b06) */
/* WARNING: Removing unreachable block (ram,0x0e1b04) */
/* WARNING: Removing unreachable block (ram,0x0e1afc) */
/* WARNING: Removing unreachable block (ram,0x0e1a98) */
/* WARNING: Removing unreachable block (ram,0x0e1a90) */
/* WARNING: Removing unreachable block (ram,0x0e1aac) */
/* WARNING: Removing unreachable block (ram,0x0e1ac4) */
/* WARNING: Removing unreachable block (ram,0x0e1af8) */
/* WARNING: Removing unreachable block (ram,0x0e1ae0) */
/* WARNING: Removing unreachable block (ram,0x0e1adc) */
/* WARNING: Removing unreachable block (ram,0x0e1ad0) */
/* WARNING: Removing unreachable block (ram,0x0e1aca) */
/* WARNING: Removing unreachable block (ram,0x0e1aba) */
/* WARNING: Removing unreachable block (ram,0x0e1ab8) */
/* WARNING: Removing unreachable block (ram,0x0e1ab2) */
/* WARNING: Removing unreachable block (ram,0x0e1aa6) */
/* WARNING: Removing unreachable block (ram,0x0e1aa4) */
/* WARNING: Removing unreachable block (ram,0x0e1a88) */
/* WARNING: Removing unreachable block (ram,0x0e1a7c) */
/* WARNING: Removing unreachable block (ram,0x0e1a78) */
/* WARNING: Removing unreachable block (ram,0x0e1a68) */
/* WARNING: Removing unreachable block (ram,0x0e1a64) */
/* WARNING: Removing unreachable block (ram,0x0e1a5c) */
/* WARNING: Removing unreachable block (ram,0x0e1a58) */
/* WARNING: Removing unreachable block (ram,0x0e1a54) */
/* WARNING: Removing unreachable block (ram,0x0e1a9e) */
/* WARNING: Removing unreachable block (ram,0x0e1a94) */
/* WARNING: Removing unreachable block (ram,0x0e1be0) */
/* WARNING: Removing unreachable block (ram,0x0e1bda) */
/* WARNING: Removing unreachable block (ram,0x0e1c92) */
/* WARNING: Removing unreachable block (ram,0x0e1c8c) */

void egs52_update_near_d732_0e1a52(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  undefined1 uVar13;
  byte bVar14;
  
  Ram00d732 = 0;
  Ram00d730 = 0;
  uVar1 = Ram00fd56;
  if ((uVar1 & 1) != 0) {
    iVar10 = Ram00f65a;
    uVar1 = iVar10 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x80) != 0) goto LAB_0e1a88;
  }
  uVar1 = Ram00fd56;
  if ((uVar1 & 1) != 0) {
    return;
  }
  iVar10 = Ram00f65a;
  uVar1 = iVar10 + 1;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) == 0) {
    return;
  }
LAB_0e1a88:
  uVar1 = Ram00fd60;
  if ((uVar1 & 2) == 0) {
    iVar10 = Ram00f65a;
    uVar2 = iVar10 + 6;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar14 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    bVar8 = UNK_00d5cc;
    bVar9 = UNK_00d5cc;
    if (bVar14 == bVar9 || bVar14 < bVar8) {
      iVar10 = Ram00f65a;
      uVar5 = iVar10 + 7;
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar14 = UNK_00d5cc;
      if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) < bVar14) {
        UNK_00d7ca = 0x96;
      }
      else {
        uVar1 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        bVar14 = UNK_00d5cc;
        UNK_00d7ca = (char)(((ulong)((uint)bVar14 -
                                    (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)))
                            * 0x96) /
                           (ulong)((uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) -
                                  (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))));
      }
    }
    else {
      UNK_00d7ca = 0;
    }
  }
  else {
    iVar10 = Ram00f65a;
    uVar1 = iVar10 + 0x31;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d7ca = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar10 = Ram00f666;
  uVar2 = iVar10 + 0x2b;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  bVar14 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  bVar8 = UNK_00d7ca;
  bVar9 = UNK_00d7ca;
  if (((bVar14 != bVar9 && bVar8 <= bVar14) && (uVar1 = Ram00fd5c, (uVar1 & 1) != 0)) &&
     (iVar10 = Ram00d78c, iVar10 == 0)) {
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    UNK_00d7ca = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  uVar13 = UNK_00d7ca;
  UNK_00d77e = uVar13;
  cVar12 = UNK_00d7ab;
  bVar14 = UNK_00d77e;
  if (bVar14 <= (byte)(cVar12 * '\n')) {
    UNK_00d77e = cVar12 * '\n';
  }
  bVar14 = UNK_00d7ca;
  uVar1 = Ram00fd58;
  if ((uVar1 & 8) != 0) {
    bVar14 = UNK_00d77e;
  }
  uVar1 = Ram00fd2e;
  Ram00fd2e = uVar1 & 0xfffd;
  bVar8 = UNK_00d77e;
  if (bVar8 != 0) {
    iVar10 = Ram00f65a;
    bVar9 = UNK_00d772;
    uVar2 = iVar10 + 0x26 + (uint)bVar9;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar10 = Ram00f65a;
    bVar9 = UNK_00d772;
    uVar3 = iVar10 + 0x1e + (uint)bVar9;
    uVar5 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    iVar10 = Ram00f65a;
    bVar9 = UNK_00d772;
    uVar6 = iVar10 + 0x16 + (uint)bVar9;
    uVar4 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar4 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar7 = Ram00d4e2;
    uVar1 = (uint)(((ulong)((int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) *
                                  (ulong)((uint)bVar8 * (uint)bVar8)) / 100) +
                            (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar6 & 0x3fff)) * 100 +
                           (uint)*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff)) *
                           (uint)bVar8) * (ulong)uVar7) / 1000);
    Ram00d730 = uVar1;
    uVar2 = Ram00d786;
    uVar5 = Ram00d786;
    if (uVar1 == uVar5 || uVar1 < uVar2) {
      Ram00d730 = 0;
    }
    else {
      iVar11 = Ram00d786;
      iVar10 = Ram00d730;
      Ram00d730 = iVar10 - iVar11;
    }
    if (bVar14 != 0) {
      iVar10 = Ram00f65a;
      bVar8 = UNK_00d774;
      uVar2 = iVar10 + 0x2a + (uint)bVar8;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar10 = Ram00f65a;
      bVar8 = UNK_00d774;
      uVar3 = iVar10 + 0x22 + (uint)bVar8;
      uVar5 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      iVar10 = Ram00f65a;
      bVar8 = UNK_00d774;
      uVar6 = iVar10 + 0x1a + (uint)bVar8;
      uVar4 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar4 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar7 = Ram00d4e2;
      uVar1 = (uint)(((ulong)((int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))
                                    * (ulong)((uint)bVar14 * (uint)bVar14)) / 100) +
                              (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar6 & 0x3fff)) * 100 +
                             (uint)*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff)) *
                             (uint)bVar14) * (ulong)uVar7) / 1000);
      Ram00d732 = uVar1;
      uVar2 = Ram00d500;
      uVar5 = Ram00d500;
      if (uVar1 != uVar5 && uVar2 <= uVar1) {
        iVar10 = Ram00f662;
        uVar1 = iVar10 + 0x6e;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar10 = Ram00d7ac;
        if ((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar10) ||
           (uVar1 = Ram00fd58, (uVar1 & 8) != 0)) {
          uVar1 = Ram00fd2e;
          Ram00fd2e = uVar1 | 2;
        }
      }
      uVar1 = Ram00d732;
      uVar2 = Ram00d78c;
      uVar5 = Ram00d78c;
      if (uVar1 == uVar5 || uVar1 < uVar2) {
        Ram00d732 = 0;
      }
      else {
        iVar11 = Ram00d78c;
        iVar10 = Ram00d732;
        Ram00d732 = iVar10 - iVar11;
      }
    }
  }
  return;
}


