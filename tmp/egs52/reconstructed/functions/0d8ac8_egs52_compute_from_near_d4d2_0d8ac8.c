/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8ac8; FLS offset 0x058ac8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8b40) */
/* WARNING: Removing unreachable block (ram,0x0d8b3a) */
/* WARNING: Removing unreachable block (ram,0x0d8b26) */
/* WARNING: Removing unreachable block (ram,0x0d8b20) */
/* WARNING: Removing unreachable block (ram,0x0d8b1c) */
/* WARNING: Removing unreachable block (ram,0x0d8b18) */
/* WARNING: Removing unreachable block (ram,0x0d8b10) */
/* WARNING: Removing unreachable block (ram,0x0d8b08) */
/* WARNING: Removing unreachable block (ram,0x0d8af4) */
/* WARNING: Removing unreachable block (ram,0x0d8aec) */
/* WARNING: Removing unreachable block (ram,0x0d8ae8) */
/* WARNING: Removing unreachable block (ram,0x0d8ada) */
/* WARNING: Removing unreachable block (ram,0x0d8ad6) */
/* WARNING: Removing unreachable block (ram,0x0d8ad2) */
/* WARNING: Removing unreachable block (ram,0x0d8ace) */
/* WARNING: Removing unreachable block (ram,0x0d8aca) */

uint egs52_compute_from_near_d4d2_0d8ac8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_2;
  
  iVar2 = Ram00d4d2;
  iVar7 = Ram00d4da;
  iVar6 = Ram00d4ac;
  iVar4 = Ram00d47c;
  iVar5 = Ram00d4aa;
  uStack_2 = (iVar2 + iVar7 + iVar6 + iVar4) - iVar5;
  if ((int)uStack_2 < 0) {
    uStack_2 = 0;
  }
  iVar2 = Ram00f63a;
  uVar1 = iVar2 + 0x4b;
  uVar9 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar9 = 3;
  }
  uVar3 = Ram00d46e;
  iVar2 = Ram00d54a;
  uVar1 = (int)(((ulong)uStack_2 * (ulong)uVar3) /
               (ulong)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff))) + iVar2;
  uVar9 = 0;
  uVar3 = Ram00d536;
  uVar8 = Ram00d536;
  if (uVar1 != uVar8 && uVar3 <= uVar1) {
    iVar2 = Ram00d536;
    uVar9 = uVar1 - iVar2;
  }
  uStack_2 = Ram00d550;
  uVar1 = Ram00d536;
  uVar3 = Ram00d536;
  if (uStack_2 == uVar3 || uStack_2 < uVar1) {
    uStack_2 = 0;
  }
  else {
    iVar2 = Ram00d536;
    uStack_2 = uStack_2 - iVar2;
  }
  if (uStack_2 <= uVar9) {
    uStack_2 = uVar9;
  }
  uVar1 = Ram00d552;
  uVar9 = Ram00d552;
  if (uStack_2 != uVar9 && uVar1 <= uStack_2) {
    uStack_2 = Ram00d552;
  }
  return uStack_2;
}


