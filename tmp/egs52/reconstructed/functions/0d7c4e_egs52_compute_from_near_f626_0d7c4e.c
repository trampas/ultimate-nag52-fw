/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7c4e; FLS offset 0x057c4e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7cae) */
/* WARNING: Removing unreachable block (ram,0x0d7ca4) */
/* WARNING: Removing unreachable block (ram,0x0d7c90) */
/* WARNING: Removing unreachable block (ram,0x0d7c8a) */
/* WARNING: Removing unreachable block (ram,0x0d7c7c) */
/* WARNING: Removing unreachable block (ram,0x0d7c76) */
/* WARNING: Removing unreachable block (ram,0x0d7c68) */
/* WARNING: Removing unreachable block (ram,0x0d7c62) */

uint egs52_compute_from_near_f626_0d7c4e(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar6 = (param_1 & 0xff) * 2;
  iVar7 = Ram00f626;
  uVar8 = iVar7 + iVar6 + 10;
  uVar3 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar3 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar7 = Ram00f626;
  uVar1 = iVar7 + iVar6 + 0x1a;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar7 = Ram00f626;
  uVar2 = iVar7 + iVar6 + 0x2a;
  uVar5 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  uVar8 = (int)(((ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar8 & 0x3fff)) * (ulong)param_2) /
               1000) +
          (int)(((ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) * (ulong)param_3) /
               1000) + *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff));
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  uVar3 = Ram00d54c;
  if (uVar3 <= uVar8) {
    uVar8 = Ram00d54c;
  }
  return uVar8;
}


