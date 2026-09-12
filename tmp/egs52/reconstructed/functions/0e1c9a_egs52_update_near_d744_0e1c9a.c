/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e1c9a; FLS offset 0x061c9a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e1de2) */
/* WARNING: Removing unreachable block (ram,0x0e1dde) */
/* WARNING: Removing unreachable block (ram,0x0e1dd8) */
/* WARNING: Removing unreachable block (ram,0x0e1dd6) */
/* WARNING: Removing unreachable block (ram,0x0e1dce) */
/* WARNING: Removing unreachable block (ram,0x0e1dc8) */
/* WARNING: Removing unreachable block (ram,0x0e1dc4) */
/* WARNING: Removing unreachable block (ram,0x0e1dc0) */
/* WARNING: Removing unreachable block (ram,0x0e1db8) */
/* WARNING: Removing unreachable block (ram,0x0e1db0) */
/* WARNING: Removing unreachable block (ram,0x0e1da8) */
/* WARNING: Removing unreachable block (ram,0x0e1da2) */
/* WARNING: Removing unreachable block (ram,0x0e1d9c) */
/* WARNING: Removing unreachable block (ram,0x0e1d94) */
/* WARNING: Removing unreachable block (ram,0x0e1d90) */
/* WARNING: Removing unreachable block (ram,0x0e1d70) */
/* WARNING: Removing unreachable block (ram,0x0e1d6c) */
/* WARNING: Removing unreachable block (ram,0x0e1d62) */
/* WARNING: Removing unreachable block (ram,0x0e1d5c) */
/* WARNING: Removing unreachable block (ram,0x0e1d56) */
/* WARNING: Removing unreachable block (ram,0x0e1d54) */
/* WARNING: Removing unreachable block (ram,0x0e1d4c) */
/* WARNING: Removing unreachable block (ram,0x0e1d46) */
/* WARNING: Removing unreachable block (ram,0x0e1d44) */
/* WARNING: Removing unreachable block (ram,0x0e1d3c) */
/* WARNING: Removing unreachable block (ram,0x0e1d32) */
/* WARNING: Removing unreachable block (ram,0x0e1d2a) */
/* WARNING: Removing unreachable block (ram,0x0e1d22) */
/* WARNING: Removing unreachable block (ram,0x0e1d1e) */
/* WARNING: Removing unreachable block (ram,0x0e1d0c) */
/* WARNING: Removing unreachable block (ram,0x0e1d08) */
/* WARNING: Removing unreachable block (ram,0x0e1d00) */
/* WARNING: Removing unreachable block (ram,0x0e1cfc) */
/* WARNING: Removing unreachable block (ram,0x0e1cf2) */
/* WARNING: Removing unreachable block (ram,0x0e1cea) */
/* WARNING: Removing unreachable block (ram,0x0e1ce4) */
/* WARNING: Removing unreachable block (ram,0x0e1cde) */
/* WARNING: Removing unreachable block (ram,0x0e1cda) */
/* WARNING: Removing unreachable block (ram,0x0e1cd6) */
/* WARNING: Removing unreachable block (ram,0x0e1cd0) */
/* WARNING: Removing unreachable block (ram,0x0e1df2) */
/* WARNING: Removing unreachable block (ram,0x0e1dee) */
/* WARNING: Removing unreachable block (ram,0x0e1cc0) */
/* WARNING: Removing unreachable block (ram,0x0e1cbc) */
/* WARNING: Removing unreachable block (ram,0x0e1cac) */
/* WARNING: Removing unreachable block (ram,0x0e1ca8) */
/* WARNING: Removing unreachable block (ram,0x0e1ca0) */
/* WARNING: Removing unreachable block (ram,0x0e1ccc) */
/* WARNING: Removing unreachable block (ram,0x0e1d38) */

void egs52_update_near_d744_0e1c9a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  undefined2 uVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  
  uVar15 = Ram00fd56;
  if ((uVar15 & 1) == 0) {
LAB_0e1cb4:
    uVar15 = Ram00fd56;
    if ((uVar15 & 1) != 0) {
LAB_0e1dee:
      Ram00d744 = 0;
      Ram00d734 = 0;
      return;
    }
    iVar12 = Ram00f65a;
    uVar15 = iVar12 + 1;
    uVar1 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar1 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar15 & 0x3fff)) & 1) == 0) goto LAB_0e1dee;
  }
  else {
    iVar12 = Ram00f65a;
    uVar15 = iVar12 + 1;
    uVar1 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar1 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar15 & 0x3fff)) & 0x10) == 0) goto LAB_0e1cb4;
  }
  uVar4 = Ram00d796;
  uVar15 = Ram00d794;
  uVar1 = Ram00d794;
  if (uVar4 != uVar1 && uVar15 <= uVar4) {
    iVar12 = Ram00f65a;
    uVar15 = iVar12 + 0x32;
    uVar1 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar1 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar6 = UNK_00d570;
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar15 & 0x3fff)) < bVar6) &&
       (cVar7 = UNK_00d577, cVar7 == '\0')) {
      iVar12 = Ram00f65e;
      bVar6 = UNK_00d772;
      uVar1 = iVar12 + 0x94 + (uint)bVar6 * 2;
      iVar12 = Ram00d7c2;
      uVar15 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar15 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar15 = 0x2c, (uVar1 & 0xc000) != 0x8000))
         )) {
        uVar15 = 3;
      }
      piVar5 = (int *)((uint3)uVar15 << 0xe | (uint3)(uVar1 & 0x3fff));
      if (iVar12 != *piVar5 && *piVar5 <= iVar12) {
        uVar15 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar15 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar15 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar15 = 3;
        }
        iVar10 = Ram00d794;
        iVar13 = Ram00f65e;
        uVar2 = iVar13 + 0x6a;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar14 = Ram00d744;
        uVar14 = egs52_weighted_average_u16
                           (*(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)),
                            (ushort)(((ulong)(uVar4 - iVar10) *
                                     (ulong)(uint)(iVar12 - *(int *)((uint3)uVar15 << 0xe |
                                                                    (uint3)(uVar1 & 0x3fff)))) / 8),
                            uVar14);
        Ram00d744 = uVar14;
        goto LAB_0e1d3c;
      }
    }
  }
  Ram00d744 = 0;
LAB_0e1d3c:
  iVar12 = Ram00f65a;
  uVar1 = iVar12 + 8;
  uVar15 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar15 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar15 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar15 = 3;
  }
  bVar6 = UNK_00d5cc;
  if (*(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar1 & 0x3fff)) < bVar6) {
    iVar12 = Ram00f65a;
    uVar4 = iVar12 + 9;
    uVar15 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar15 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar15 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar15 = 3;
    }
    bVar6 = *(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar4 & 0x3fff));
    bVar8 = UNK_00d5cc;
    bVar9 = UNK_00d5cc;
    if (bVar6 == bVar9 || bVar6 < bVar8) {
      uVar15 = 0;
    }
    else {
      uVar15 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar15 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar15 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar15 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      bVar6 = UNK_00d5cc;
      uVar15 = (uint)(((ulong)((uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff)) -
                              (uint)bVar6) * 100) /
                     (ulong)((uint)*(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar4 & 0x3fff)) -
                            (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))) & 0xff;
    }
  }
  else {
    uVar15 = 100;
  }
  uVar11 = Ram00d796;
  Ram00d794 = uVar11;
  bVar6 = UNK_00d774;
  iVar12 = Ram00f65e;
  uVar1 = iVar12 + (uint)bVar6 * 2 + 0x34;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  Ram00d734 = (int)(((ulong)uVar15 * (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))
                    ) / 100);
  uVar15 = Ram00fd32;
  if ((uVar15 & 0x40) != 0) {
    iVar12 = Ram00f65a;
    uVar15 = iVar12 + 0x35;
    uVar1 = 0x24;
    if ((((uVar15 & 0xc000) != 0) && (uVar1 = 0x21, (uVar15 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar15 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar6 = UNK_00d570;
    if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar15 & 0x3fff)) < bVar6) {
      iVar12 = Ram00f666;
      uVar1 = iVar12 + 0x2c;
      uVar15 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar15 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar15 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar15 = 3;
      }
      uVar15 = *(uint *)((uint3)uVar15 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar4 = Ram00d744;
      uVar2 = Ram00d744;
      if (uVar15 != uVar2 && uVar4 <= uVar15) {
        uVar15 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar15 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar15 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar15 = 3;
        }
        Ram00d744 = *(undefined2 *)((uint3)uVar15 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
    }
  }
  uVar15 = Ram00fd48;
  if ((uVar15 & 0x10) == 0) {
    uVar15 = Ram00fd32;
    Ram00fd32 = uVar15 & 0xffbf;
  }
  return;
}


