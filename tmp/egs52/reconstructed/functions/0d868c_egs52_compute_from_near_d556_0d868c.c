/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d868c; FLS offset 0x05868c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8740) */
/* WARNING: Removing unreachable block (ram,0x0d8736) */
/* WARNING: Removing unreachable block (ram,0x0d8722) */
/* WARNING: Removing unreachable block (ram,0x0d871c) */
/* WARNING: Removing unreachable block (ram,0x0d86fe) */
/* WARNING: Removing unreachable block (ram,0x0d86f8) */
/* WARNING: Removing unreachable block (ram,0x0d86f4) */
/* WARNING: Removing unreachable block (ram,0x0d86f0) */
/* WARNING: Removing unreachable block (ram,0x0d86e0) */
/* WARNING: Removing unreachable block (ram,0x0d86d6) */
/* WARNING: Removing unreachable block (ram,0x0d86c4) */
/* WARNING: Removing unreachable block (ram,0x0d86be) */
/* WARNING: Removing unreachable block (ram,0x0d86ba) */
/* WARNING: Removing unreachable block (ram,0x0d86aa) */
/* WARNING: Removing unreachable block (ram,0x0d86a4) */
/* WARNING: Removing unreachable block (ram,0x0d869a) */

uint egs52_compute_from_near_d556_0d868c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  uVar9 = Ram00d556;
  iVar8 = (param_1 & 0xff) * 2;
  iVar12 = Ram00f626;
  uVar13 = iVar12 + iVar8 + 10;
  uVar3 = 0x24;
  if ((((uVar13 & 0xc000) != 0) && (uVar3 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar9 = (uint)(((ulong)uVar9 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar13 & 0x3fff))) /
                1000);
  uVar10 = Ram00d532;
  iVar12 = Ram00f626;
  uVar13 = iVar12 + iVar8 + 0x1a;
  uVar3 = 0x24;
  if ((((uVar13 & 0xc000) != 0) && (uVar3 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar12 = Ram00f63a;
  uVar7 = iVar12 + 4 + (param_1 & 0xff);
  uVar4 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar4 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar12 = Ram00f63a;
  uVar1 = iVar12 + 0x20;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  iVar12 = Ram00f626;
  uVar2 = iVar12 + iVar8 + 0x1a;
  uVar6 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  uVar13 = (int)(((((ulong)uVar10 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar13 & 0x3fff))
                   ) / 1000 & 0xffff) *
                 (ulong)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar7 & 0x3fff))) / 100) +
           (int)(((ulong)*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                 (ulong)*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff))) / 1000);
  if (uVar13 < uVar9) {
    iVar12 = uVar9 - uVar13;
  }
  else {
    iVar12 = 0;
  }
  iVar11 = Ram00f626;
  uVar13 = iVar11 + iVar8 + 0x2a;
  uVar3 = 0x24;
  if ((((uVar13 & 0xc000) != 0) && (uVar3 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar13 = iVar12 + *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar13 & 0x3fff));
  if ((int)uVar13 < 0) {
    uVar13 = 0;
  }
  uVar3 = Ram00d54c;
  if (uVar3 <= uVar13) {
    uVar13 = Ram00d54c;
  }
  return uVar13;
}


