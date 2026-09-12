/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8360; FLS offset 0x058360.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d83d6) */
/* WARNING: Removing unreachable block (ram,0x0d83d0) */
/* WARNING: Removing unreachable block (ram,0x0d83bc) */
/* WARNING: Removing unreachable block (ram,0x0d83b6) */
/* WARNING: Removing unreachable block (ram,0x0d83b2) */
/* WARNING: Removing unreachable block (ram,0x0d83a6) */
/* WARNING: Removing unreachable block (ram,0x0d83a0) */
/* WARNING: Removing unreachable block (ram,0x0d839a) */
/* WARNING: Removing unreachable block (ram,0x0d8384) */
/* WARNING: Removing unreachable block (ram,0x0d8380) */
/* WARNING: Removing unreachable block (ram,0x0d8370) */
/* WARNING: Removing unreachable block (ram,0x0d836c) */
/* WARNING: Removing unreachable block (ram,0x0d8368) */

uint egs52_compute_from_near_d4d2_0d8360(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uStack_4;
  
  iVar7 = egs52_update_near_d3fc_0d7be2();
  iVar1 = Ram00d4d2;
  iVar2 = Ram00d47c;
  iVar3 = Ram00d4aa;
  uStack_4 = ((iVar1 + iVar2) - iVar3) - iVar7;
  if ((int)uStack_4 < 0) {
    uStack_4 = 0;
  }
  bVar4 = UNK_00d4e1;
  uVar8 = Ram00d46e;
  iVar1 = Ram00d54a;
  uStack_4 = (int)(((ulong)uVar8 * (ulong)uStack_4) / (ulong)bVar4) + iVar1;
  uVar8 = Ram00d536;
  uVar5 = Ram00d536;
  if (uStack_4 == uVar5 || uStack_4 < uVar8) {
    uStack_4 = 0;
  }
  else {
    iVar1 = Ram00d536;
    uStack_4 = uStack_4 - iVar1;
  }
  uVar8 = Ram00d550;
  uVar5 = Ram00d536;
  uVar6 = Ram00d536;
  if (uVar8 == uVar6 || uVar8 < uVar5) {
    uVar8 = 0;
  }
  else {
    iVar1 = Ram00d536;
    uVar8 = uVar8 - iVar1;
  }
  if (uVar8 <= uStack_4) {
    uVar8 = uStack_4;
  }
  uVar5 = Ram00d552;
  uVar6 = Ram00d552;
  if (uVar8 != uVar6 && uVar5 <= uVar8) {
    uVar8 = Ram00d552;
  }
  return uVar8;
}


