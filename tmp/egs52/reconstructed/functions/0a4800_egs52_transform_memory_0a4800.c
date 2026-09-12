/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4800; FLS offset 0x024800.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a483a) */
/* WARNING: Removing unreachable block (ram,0x0a4848) */
/* WARNING: Removing unreachable block (ram,0x0a4846) */
/* WARNING: Removing unreachable block (ram,0x0a4834) */
/* WARNING: Removing unreachable block (ram,0x0a481c) */
/* WARNING: Removing unreachable block (ram,0x0a4874) */
/* WARNING: Removing unreachable block (ram,0x0a4882) */
/* WARNING: Removing unreachable block (ram,0x0a4880) */
/* WARNING: Removing unreachable block (ram,0x0a487c) */
/* WARNING: Removing unreachable block (ram,0x0a486e) */
/* WARNING: Removing unreachable block (ram,0x0a485a) */
/* WARNING: Removing unreachable block (ram,0x0a4826) */
/* WARNING: Removing unreachable block (ram,0x0a4842) */

uint egs52_transform_memory_0a4800(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if ((param_2 & 1) == 0) {
    uVar6 = (param_1 & 0xff) * 2 + 0xcad0;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar4 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
    uVar7 = (param_1 & 0xff) * 0x14 + 0x930e;
    uVar1 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    puVar3 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff));
    if (uVar4 == *puVar3 || uVar4 < *puVar3) {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      param_2 = 0x28;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar4 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) =
           *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) -
           *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar7 & 0x3fff));
      param_2 = param_2 & 0xff04;
    }
  }
  else {
    iVar8 = (param_1 & 0xff) * 0x14;
    uVar6 = iVar8 + 0x930a;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar7 = (int)&LAB_09930c + iVar8;
    uVar4 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar4 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar5 = (param_1 & 0xff) * 2 + 0xcad0;
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) <
        (uint)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) -
              *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar7 & 0x3fff)))) {
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar6 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar6 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) +
           *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar7 & 0x3fff));
      param_2 = param_2 & 0xff04;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
      param_2 = 0x24;
    }
  }
  return param_2;
}


