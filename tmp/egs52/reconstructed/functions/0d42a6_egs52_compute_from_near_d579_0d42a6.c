/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d42a6; FLS offset 0x0542a6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4320) */
/* WARNING: Removing unreachable block (ram,0x0d431a) */
/* WARNING: Removing unreachable block (ram,0x0d4316) */
/* WARNING: Removing unreachable block (ram,0x0d4312) */
/* WARNING: Removing unreachable block (ram,0x0d430a) */
/* WARNING: Removing unreachable block (ram,0x0d4302) */
/* WARNING: Removing unreachable block (ram,0x0d42fc) */
/* WARNING: Removing unreachable block (ram,0x0d42f4) */
/* WARNING: Removing unreachable block (ram,0x0d42ee) */
/* WARNING: Removing unreachable block (ram,0x0d42e8) */
/* WARNING: Removing unreachable block (ram,0x0d42e2) */
/* WARNING: Removing unreachable block (ram,0x0d42da) */
/* WARNING: Removing unreachable block (ram,0x0d42d0) */
/* WARNING: Removing unreachable block (ram,0x0d42ca) */
/* WARNING: Removing unreachable block (ram,0x0d42c6) */
/* WARNING: Removing unreachable block (ram,0x0d42c2) */
/* WARNING: Removing unreachable block (ram,0x0d42b2) */

uint egs52_compute_from_near_d579_0d42a6(char param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  if ((param_1 == '\x03') && ((cVar4 = UNK_00d579, cVar4 == '\x05' || (cVar4 == '\x06')))) {
    uVar8 = 0;
  }
  else {
    iVar9 = Ram00f636;
    uVar8 = iVar9 + 0x4c;
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
    bVar5 = UNK_00d5cc;
    bVar6 = UNK_00d5cc;
    if (bVar3 == bVar6 || bVar3 < bVar5) {
      iVar9 = 0;
    }
    else {
      bVar3 = UNK_00d477;
      uVar8 = iVar9 + (uint)bVar3 * 2 + 0x4e;
      uVar1 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar9 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
    }
    bVar3 = UNK_00d477;
    iVar7 = Ram00f636;
    uVar8 = iVar7 + (uint)bVar3 * 2 + 0x3a;
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) + iVar9;
    uVar1 = Ram00d54c;
    if (uVar1 <= uVar8) {
      uVar8 = Ram00d54c;
    }
    uVar1 = Ram00fd4a;
    if (((uVar1 & 0x20) != 0) && (cVar4 = UNK_00d454, cVar4 == '\x03')) {
      iVar9 = Ram00f636;
      uVar1 = iVar9 + 0x31;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      bVar5 = UNK_00d5cc;
      bVar6 = UNK_00d5cc;
      if (bVar3 == bVar6 || bVar3 < bVar5) {
        uVar8 = iVar9 + 0x32;
        uVar1 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar8 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) * 10;
      }
    }
  }
  return uVar8;
}


