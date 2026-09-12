/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8846; FLS offset 0x058846.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d891c) */
/* WARNING: Removing unreachable block (ram,0x0d8912) */
/* WARNING: Removing unreachable block (ram,0x0d88fe) */
/* WARNING: Removing unreachable block (ram,0x0d88f8) */
/* WARNING: Removing unreachable block (ram,0x0d88d8) */
/* WARNING: Removing unreachable block (ram,0x0d88ce) */
/* WARNING: Removing unreachable block (ram,0x0d88bc) */
/* WARNING: Removing unreachable block (ram,0x0d88b6) */
/* WARNING: Removing unreachable block (ram,0x0d88b2) */
/* WARNING: Removing unreachable block (ram,0x0d88a2) */
/* WARNING: Removing unreachable block (ram,0x0d889c) */
/* WARNING: Removing unreachable block (ram,0x0d888c) */
/* WARNING: Removing unreachable block (ram,0x0d8886) */
/* WARNING: Removing unreachable block (ram,0x0d887c) */
/* WARNING: Removing unreachable block (ram,0x0d8876) */
/* WARNING: Removing unreachable block (ram,0x0d8872) */
/* WARNING: Removing unreachable block (ram,0x0d885e) */
/* WARNING: Removing unreachable block (ram,0x0d885a) */
/* WARNING: Removing unreachable block (ram,0x0d8854) */
/* WARNING: Removing unreachable block (ram,0x0d8850) */

uint egs52_compute_from_near_f63a_0d8846(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  iVar5 = Ram00f63a;
  uVar8 = iVar5 + 0x4c;
  uVar1 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar6 = Ram00d4d2;
  uVar2 = Ram00d46e;
  iVar5 = Ram00d54a;
  uVar8 = (int)(((ulong)uVar6 * (ulong)uVar2) /
               (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff))) + iVar5;
  uVar1 = Ram00d536;
  uVar2 = Ram00d536;
  if (uVar8 == uVar2 || uVar8 < uVar1) {
    uVar8 = 0;
  }
  else {
    iVar5 = Ram00d536;
    uVar8 = uVar8 - iVar5;
  }
  uVar1 = Ram00d552;
  if (uVar1 <= uVar8) {
    uVar8 = Ram00d552;
  }
  iVar5 = (param_1 & 0xff) * 2;
  iVar9 = Ram00f626;
  uVar1 = iVar9 + iVar5 + 10;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar2 = (uint)(((ulong)uVar8 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
                1000);
  uVar6 = Ram00d532;
  iVar9 = Ram00f626;
  uVar8 = iVar9 + iVar5 + 0x1a;
  uVar1 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  iVar9 = Ram00f63a;
  uVar4 = iVar9 + 4 + (param_1 & 0xff);
  uVar3 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar8 = (uint)(((((ulong)uVar6 * (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)))
                   / 1000 & 0xffff) *
                 (ulong)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff))) / 100);
  if (uVar8 < uVar2) {
    iVar9 = uVar2 - uVar8;
  }
  else {
    iVar9 = 0;
  }
  iVar7 = Ram00f626;
  uVar8 = iVar7 + iVar5 + 0x2a;
  uVar1 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar8 = iVar9 + *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  uVar1 = Ram00d54c;
  if (uVar1 <= uVar8) {
    uVar8 = Ram00d54c;
  }
  return uVar8;
}


