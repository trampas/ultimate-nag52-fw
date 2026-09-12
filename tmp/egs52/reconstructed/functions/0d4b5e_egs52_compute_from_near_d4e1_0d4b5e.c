/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d4b5e; FLS offset 0x054b5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4bd6) */
/* WARNING: Removing unreachable block (ram,0x0d4bd2) */
/* WARNING: Removing unreachable block (ram,0x0d4bc8) */
/* WARNING: Removing unreachable block (ram,0x0d4bc4) */
/* WARNING: Removing unreachable block (ram,0x0d4bbe) */
/* WARNING: Removing unreachable block (ram,0x0d4ba8) */
/* WARNING: Removing unreachable block (ram,0x0d4ba2) */
/* WARNING: Removing unreachable block (ram,0x0d4b9a) */
/* WARNING: Removing unreachable block (ram,0x0d4b96) */
/* WARNING: Removing unreachable block (ram,0x0d4b92) */
/* WARNING: Removing unreachable block (ram,0x0d4b84) */
/* WARNING: Removing unreachable block (ram,0x0d4b80) */
/* WARNING: Removing unreachable block (ram,0x0d4b6c) */
/* WARNING: Removing unreachable block (ram,0x0d4b66) */
/* WARNING: Removing unreachable block (ram,0x0d4b62) */
/* WARNING: Removing unreachable block (ram,0x0d4b5e) */

int egs52_compute_from_near_d4e1_0d4b5e(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  bVar4 = UNK_00d4e1;
  iVar12 = Ram00f63a;
  uVar11 = iVar12 + 0x4c;
  uVar1 = 0x24;
  if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar7 = Ram00d4ae;
  bVar8 = UNK_00d4df;
  uVar6 = Ram00d492;
  iVar12 = Ram00d490;
  uVar5 = Ram00d490;
  iVar10 = Ram00f634;
  bVar9 = UNK_00d579;
  uVar3 = iVar10 + 0x16 + (uint)bVar9;
  uVar2 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar11 = ((int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) * (ulong)uVar7)
                 / (ulong)bVar4) + (int)(((ulong)bVar8 * (ulong)uVar6) / 100) + iVar12) -
           (int)(((ulong)uVar5 * (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff))) /
                100);
  uVar1 = Ram00d490;
  uVar2 = Ram00d490;
  if (uVar11 != uVar2 && uVar1 <= uVar11) {
    uVar11 = Ram00d490;
  }
  iVar12 = Ram00d4ae;
  bVar4 = UNK_00d4df;
  uVar1 = Ram00d4bc;
  uVar1 = (uint)(((ulong)bVar4 * (ulong)uVar1) / 100);
  if (uVar1 < uVar11 + iVar12) {
    iVar12 = (uVar11 + iVar12) - uVar1;
  }
  else {
    iVar12 = 0;
  }
  return iVar12;
}


