/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d874e; FLS offset 0x05874e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d87c2) */
/* WARNING: Removing unreachable block (ram,0x0d87bc) */
/* WARNING: Removing unreachable block (ram,0x0d87a8) */
/* WARNING: Removing unreachable block (ram,0x0d87a2) */
/* WARNING: Removing unreachable block (ram,0x0d879e) */
/* WARNING: Removing unreachable block (ram,0x0d879a) */
/* WARNING: Removing unreachable block (ram,0x0d8792) */
/* WARNING: Removing unreachable block (ram,0x0d8788) */
/* WARNING: Removing unreachable block (ram,0x0d8778) */
/* WARNING: Removing unreachable block (ram,0x0d8772) */
/* WARNING: Removing unreachable block (ram,0x0d8764) */
/* WARNING: Removing unreachable block (ram,0x0d8760) */
/* WARNING: Removing unreachable block (ram,0x0d875c) */
/* WARNING: Removing unreachable block (ram,0x0d8758) */
/* WARNING: Removing unreachable block (ram,0x0d8754) */
/* WARNING: Removing unreachable block (ram,0x0d8750) */

uint egs52_compute_from_near_d4d2_0d874e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uStack_2;
  
  iVar2 = Ram00d4d2;
  iVar7 = Ram00d4dc;
  iVar3 = Ram00d47c;
  iVar6 = Ram00d4ac;
  iVar4 = Ram00d492;
  iVar5 = Ram00d4aa;
  uStack_2 = (iVar2 + iVar7 + iVar3 + iVar6 + iVar4) - iVar5;
  if ((int)uStack_2 < 0) {
    uStack_2 = 0;
  }
  bVar8 = UNK_00d4e1;
  uVar1 = Ram00d46e;
  iVar2 = Ram00d54a;
  uVar1 = (int)(((ulong)uStack_2 * (ulong)uVar1) / (ulong)bVar8) + iVar2;
  uVar11 = 0;
  uVar9 = Ram00d536;
  uVar10 = Ram00d536;
  if (uVar1 != uVar10 && uVar9 <= uVar1) {
    iVar2 = Ram00d536;
    uVar11 = uVar1 - iVar2;
  }
  uStack_2 = Ram00d550;
  uVar1 = Ram00d536;
  uVar9 = Ram00d536;
  if (uStack_2 == uVar9 || uStack_2 < uVar1) {
    uStack_2 = 0;
  }
  else {
    iVar2 = Ram00d536;
    uStack_2 = uStack_2 - iVar2;
  }
  if (uStack_2 <= uVar11) {
    uStack_2 = uVar11;
  }
  uVar1 = Ram00d552;
  uVar11 = Ram00d552;
  if (uStack_2 != uVar11 && uVar1 <= uStack_2) {
    uStack_2 = Ram00d552;
  }
  return uStack_2;
}


