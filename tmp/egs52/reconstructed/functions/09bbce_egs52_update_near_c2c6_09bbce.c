/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bbce; FLS offset 0x01bbce.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bc9a) */
/* WARNING: Removing unreachable block (ram,0x09bc8c) */
/* WARNING: Removing unreachable block (ram,0x09bc82) */
/* WARNING: Removing unreachable block (ram,0x09bc6a) */
/* WARNING: Removing unreachable block (ram,0x09bc54) */
/* WARNING: Removing unreachable block (ram,0x09bc52) */
/* WARNING: Removing unreachable block (ram,0x09bc58) */
/* WARNING: Removing unreachable block (ram,0x09bc46) */
/* WARNING: Removing unreachable block (ram,0x09bc42) */
/* WARNING: Removing unreachable block (ram,0x09bc3e) */
/* WARNING: Removing unreachable block (ram,0x09bc00) */
/* WARNING: Removing unreachable block (ram,0x09bc1a) */
/* WARNING: Removing unreachable block (ram,0x09bbf6) */
/* WARNING: Removing unreachable block (ram,0x09bbee) */
/* WARNING: Removing unreachable block (ram,0x09bbe8) */
/* WARNING: Removing unreachable block (ram,0x09bbd8) */
/* WARNING: Removing unreachable block (ram,0x09bc16) */
/* WARNING: Removing unreachable block (ram,0x09bc5e) */
/* WARNING: Removing unreachable block (ram,0x09bc6e) */
/* WARNING: Removing unreachable block (ram,0x09bc94) */

void egs52_update_near_c2c6_09bbce(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  undefined1 uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  
  bVar11 = UNK_00c2c6;
  iVar6 = (uint)bVar11 * 0x34;
  uVar5 = iVar6 + 0xe000;
  uVar12 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar12 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar12 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar12 = 3;
  }
  *(undefined1 *)((uint3)uVar12 << 0xe | (uint3)(uVar5 & 0x3fff)) = 0;
  uVar12 = 0;
  bVar11 = 0;
  cVar7 = UNK_00c2b8;
  if (cVar7 == cRam0cf85e) {
    bVar11 = UNK_00e300;
    uVar12 = (uint)egs52_update_near_c34a_09e304;
  }
  else {
    bVar10 = 0;
    while ((bVar10 < 4 && (uVar12 == 0))) {
      uVar1 = (uint)bVar10 * 0xc2 + 0x1760;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      bVar8 = UNK_00c2b8;
      if ((uint)bVar8 == *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        uVar12 = (uint)bVar10 * 0xc2 + 0x1762;
        bVar11 = 0x30;
      }
      bVar10 = bVar10 + 1;
    }
  }
  if (uVar12 != 0) {
    uVar1 = iVar6 + 0xe001;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = bVar11 + 1;
    uVar9 = UNK_00c2b8;
    uVar1 = iVar6 + 0xe002;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar9;
    for (bVar10 = 1; bVar10 <= bVar11; bVar10 = bVar10 + 1) {
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar13 = uVar12 + 2;
      uVar3 = 0x24;
      if ((((uVar13 & 0xc000) != 0) && (uVar3 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = (uint)bVar10 + iVar6 + 0xe002;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(undefined1 *)
            CONCAT12((char)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar13 & 0x3fff)),
                     *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)));
      uVar12 = uVar12 + 4;
    }
    uVar12 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar12 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar12 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar12 = 3;
    }
    *(undefined1 *)((uint3)uVar12 << 0xe | (uint3)(uVar5 & 0x3fff)) = 1;
    bVar11 = 0;
    do {
      bVar10 = UNK_00c2c6;
      if (bVar11 != bVar10) {
        uVar12 = (uint)bVar11 * 0x34 + 0xe000;
        uVar5 = 0x24;
        if ((((uVar12 & 0xc000) != 0) && (uVar5 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar12 & 0x3fff)) = 0;
      }
      bVar11 = bVar11 + 1;
    } while (bVar11 < 2);
    cVar7 = UNK_00c2c6;
    if (cVar7 == '\x01') {
      UNK_00c2c6 = 0;
    }
    else {
      cVar7 = UNK_00c2c6;
      UNK_00c2c6 = cVar7 + '\x01';
    }
  }
  return;
}


