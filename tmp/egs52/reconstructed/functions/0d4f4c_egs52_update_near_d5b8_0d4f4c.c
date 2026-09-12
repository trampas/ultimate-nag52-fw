/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d4f4c; FLS offset 0x054f4c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d5082) */
/* WARNING: Removing unreachable block (ram,0x0d507a) */
/* WARNING: Removing unreachable block (ram,0x0d5076) */
/* WARNING: Removing unreachable block (ram,0x0d5070) */
/* WARNING: Removing unreachable block (ram,0x0d506c) */
/* WARNING: Removing unreachable block (ram,0x0d5064) */
/* WARNING: Removing unreachable block (ram,0x0d505a) */
/* WARNING: Removing unreachable block (ram,0x0d502e) */
/* WARNING: Removing unreachable block (ram,0x0d5028) */
/* WARNING: Removing unreachable block (ram,0x0d5050) */
/* WARNING: Removing unreachable block (ram,0x0d5048) */
/* WARNING: Removing unreachable block (ram,0x0d5044) */
/* WARNING: Removing unreachable block (ram,0x0d5040) */
/* WARNING: Removing unreachable block (ram,0x0d501c) */
/* WARNING: Removing unreachable block (ram,0x0d5010) */
/* WARNING: Removing unreachable block (ram,0x0d500c) */
/* WARNING: Removing unreachable block (ram,0x0d5006) */
/* WARNING: Removing unreachable block (ram,0x0d5002) */
/* WARNING: Removing unreachable block (ram,0x0d4ffe) */
/* WARNING: Removing unreachable block (ram,0x0d4ff4) */
/* WARNING: Removing unreachable block (ram,0x0d4fea) */
/* WARNING: Removing unreachable block (ram,0x0d4fde) */
/* WARNING: Removing unreachable block (ram,0x0d4fd0) */
/* WARNING: Removing unreachable block (ram,0x0d4fc6) */
/* WARNING: Removing unreachable block (ram,0x0d4fb2) */
/* WARNING: Removing unreachable block (ram,0x0d4f94) */
/* WARNING: Removing unreachable block (ram,0x0d4f90) */
/* WARNING: Removing unreachable block (ram,0x0d4f7a) */
/* WARNING: Removing unreachable block (ram,0x0d4f76) */
/* WARNING: Removing unreachable block (ram,0x0d4f72) */
/* WARNING: Removing unreachable block (ram,0x0d4f66) */
/* WARNING: Removing unreachable block (ram,0x0d4f62) */
/* WARNING: Removing unreachable block (ram,0x0d4f5c) */
/* WARNING: Removing unreachable block (ram,0x0d4f58) */
/* WARNING: Removing unreachable block (ram,0x0d4f50) */
/* WARNING: Removing unreachable block (ram,0x0d4fae) */
/* WARNING: Removing unreachable block (ram,0x0d5020) */
/* WARNING: Removing unreachable block (ram,0x0d5038) */

ushort egs52_update_near_d5b8_0d4f4c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort old;
  byte bVar11;
  byte bVar12;
  int iVar13;
  uint uStack_4;
  
  cVar7 = UNK_00d454;
  if (cVar7 == '\0') {
    uStack_4 = 0;
  }
  else {
    iVar10 = Ram00f63a;
    uVar3 = iVar10 + 0x4b;
    uVar6 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar9 = Ram00d4d2;
    uVar8 = Ram00d46e;
    iVar10 = Ram00d54a;
    iVar13 = Ram00f626;
    uVar1 = iVar13 + 0x54;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = (int)(((ulong)uVar9 * (ulong)uVar8) /
                 (ulong)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff))) + iVar10 +
            *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    if ((cVar7 == '\x01') || (cVar7 == '\x06')) {
      iVar10 = Ram00f626;
      uVar6 = iVar10 + 4;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uStack_4 = (uint)(((ulong)uVar3 *
                        (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff))) / 1000);
    }
    else {
      iVar10 = Ram00f626;
      uVar6 = iVar10 + 6;
      uVar1 = 0x24;
      if (((uVar6 & 0xc000) != 0) &&
         ((uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000))))
      {
        uVar1 = 3;
      }
      uStack_4 = (uint)(((ulong)uVar3 *
                        (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff))) / 1000);
    }
    iVar10 = Ram00f626;
    uVar6 = iVar10 + 8;
    uVar3 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (uStack_4 < *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff))) {
      uStack_4 = 0;
    }
    else {
      uVar3 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_4 = uStack_4 - *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff));
    }
  }
  uVar3 = Ram00d54c;
  if (uVar3 <= uStack_4) {
    uStack_4 = Ram00d54c;
  }
  if (uStack_4 == 0) {
    iVar10 = Ram00f626;
    uVar3 = iVar10 + 0x4c;
    uVar6 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar1 = Ram00d56a;
    if (uVar1 <= *(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff))) {
      uVar3 = iVar10 + 0x4f;
      uVar6 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      bVar5 = *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff));
      bVar11 = UNK_00d5cc;
      bVar12 = UNK_00d5cc;
      if (bVar5 == bVar12 || bVar5 < bVar11) {
        uVar6 = iVar10 + 0x50;
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) != 0) {
          uVar3 = Ram00fd4c;
          if ((uVar3 & 8) == 0) {
            iVar10 = Ram00d5b8;
            if (iVar10 == 0) {
              uVar3 = Ram00fd4c;
              Ram00fd4c = uVar3 | 8;
              iVar10 = Ram00f626;
              uVar3 = iVar10 + 0x52;
              uVar6 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar6 = 3;
              }
              Ram00d5b8 = *(undefined2 *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff));
            }
          }
          else {
            iVar10 = Ram00d5b8;
            if (iVar10 == 0) {
              uVar3 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              Ram00d5b8 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff));
              uVar3 = Ram00fd4c;
              Ram00fd4c = uVar3 & 0xfff7;
              uVar3 = Ram00fd4c;
              Ram00fd4c = uVar3 | 0x10;
            }
          }
          goto LAB_0d5054;
        }
      }
    }
  }
  uVar3 = Ram00fd4c;
  Ram00fd4c = uVar3 & 0xfff7;
  Ram00d5b8 = 0;
LAB_0d5054:
  uVar3 = Ram00fd4c;
  if ((uVar3 & 8) == 0) {
    iVar10 = Ram00f626;
    uVar6 = iVar10 + 0x4c;
    uVar3 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    puVar4 = (uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff));
    if (uStack_4 == *puVar4 || uStack_4 < *puVar4) {
      uVar3 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_4 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff));
    }
    uVar3 = Ram00d56a;
    if (uStack_4 < uVar3) {
      iVar10 = Ram00f626;
      uVar3 = iVar10 + 0x4e;
      uVar6 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      old = Ram00d56a;
      uStack_4 = egs52_weighted_average_u16
                           (*(uchar *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff)),uStack_4,old);
    }
  }
  return uStack_4;
}


