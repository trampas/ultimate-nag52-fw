/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a488e; FLS offset 0x02488e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a48c4) */
/* WARNING: Removing unreachable block (ram,0x0a48c2) */
/* WARNING: Removing unreachable block (ram,0x0a48be) */
/* WARNING: Removing unreachable block (ram,0x0a48b4) */
/* WARNING: Removing unreachable block (ram,0x0a48a6) */
/* WARNING: Removing unreachable block (ram,0x0a489a) */

undefined1 egs52_transform_memory_0a488e(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = (param_1 & 0xff) * 0x14;
  uVar1 = iVar7 + 0x930a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar5 = (int)&LAB_09930c + iVar7;
  uVar3 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar6 = (param_1 & 0xff) * 2 + 0xcbd0;
  uVar4 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar4 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  if ((uint)(*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) -
            *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff))) <=
      *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar6 & 0x3fff))) {
    return 0;
  }
  uVar1 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar2 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar3 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
       *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) +
       *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff));
  return 1;
}


