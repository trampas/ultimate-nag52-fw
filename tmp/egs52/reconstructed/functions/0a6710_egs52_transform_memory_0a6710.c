/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6710; FLS offset 0x026710.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a675e) */
/* WARNING: Removing unreachable block (ram,0x0a675a) */
/* WARNING: Removing unreachable block (ram,0x0a6728) */
/* WARNING: Removing unreachable block (ram,0x0a6716) */

undefined2 egs52_transform_memory_0a6710(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uStack_4;
  
  uVar2 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar2 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = param_2 + 2;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uStack_4 = (ulong)param_3 * (ulong)param_1 +
             (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) * (ulong)-param_1 +
             ((ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(param_2 & 0x3fff)) * (ulong)-param_1 >>
             0x10);
  iVar4 = (int)((ulong)uStack_4 >> 0x10);
  uVar2 = param_2 + 2;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = iVar4;
  uVar2 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar2 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(uint *)((uint3)uVar2 << 0xe | (uint3)(param_2 & 0x3fff)) = (uint)uStack_4;
  if (iVar4 != -1) {
    uStack_4 = (ulong)(iVar4 + (uint)(0x7fff < (uint)uStack_4)) << 0x10;
  }
  return uStack_4._2_2_;
}


