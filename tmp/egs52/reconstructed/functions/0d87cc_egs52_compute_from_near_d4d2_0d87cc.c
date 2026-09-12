/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d87cc; FLS offset 0x0587cc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d883c) */
/* WARNING: Removing unreachable block (ram,0x0d8836) */
/* WARNING: Removing unreachable block (ram,0x0d8822) */
/* WARNING: Removing unreachable block (ram,0x0d881c) */
/* WARNING: Removing unreachable block (ram,0x0d8818) */
/* WARNING: Removing unreachable block (ram,0x0d8814) */
/* WARNING: Removing unreachable block (ram,0x0d880c) */
/* WARNING: Removing unreachable block (ram,0x0d8802) */
/* WARNING: Removing unreachable block (ram,0x0d87f2) */
/* WARNING: Removing unreachable block (ram,0x0d87ec) */
/* WARNING: Removing unreachable block (ram,0x0d87de) */
/* WARNING: Removing unreachable block (ram,0x0d87da) */
/* WARNING: Removing unreachable block (ram,0x0d87d6) */
/* WARNING: Removing unreachable block (ram,0x0d87d2) */
/* WARNING: Removing unreachable block (ram,0x0d87ce) */

uint egs52_compute_from_near_d4d2_0d87cc(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uStack_2;
  
  iVar2 = Ram00d4d2;
  iVar6 = Ram00d4da;
  iVar5 = Ram00d4ac;
  iVar3 = Ram00d47c;
  iVar4 = Ram00d4aa;
  uStack_2 = (iVar2 + iVar6 + iVar5 + iVar3) - iVar4;
  if ((int)uStack_2 < 0) {
    uStack_2 = 0;
  }
  bVar7 = UNK_00d4e1;
  uVar1 = Ram00d46e;
  iVar2 = Ram00d54a;
  uVar1 = (int)(((ulong)uStack_2 * (ulong)uVar1) / (ulong)bVar7) + iVar2;
  uVar10 = 0;
  uVar8 = Ram00d536;
  uVar9 = Ram00d536;
  if (uVar1 != uVar9 && uVar8 <= uVar1) {
    iVar2 = Ram00d536;
    uVar10 = uVar1 - iVar2;
  }
  uStack_2 = Ram00d550;
  uVar1 = Ram00d536;
  uVar8 = Ram00d536;
  if (uStack_2 == uVar8 || uStack_2 < uVar1) {
    uStack_2 = 0;
  }
  else {
    iVar2 = Ram00d536;
    uStack_2 = uStack_2 - iVar2;
  }
  if (uStack_2 <= uVar10) {
    uStack_2 = uVar10;
  }
  uVar1 = Ram00d552;
  uVar10 = Ram00d552;
  if (uStack_2 != uVar10 && uVar1 <= uStack_2) {
    uStack_2 = Ram00d552;
  }
  return uStack_2;
}


