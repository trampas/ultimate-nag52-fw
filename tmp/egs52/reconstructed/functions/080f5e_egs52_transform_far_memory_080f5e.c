/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x080f5e; FLS offset 0x000f5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x080f7c) */
/* WARNING: Removing unreachable block (ram,0x080f78) */
/* WARNING: Removing unreachable block (ram,0x080f68) */
/* WARNING: Removing unreachable block (ram,0x080f62) */
/* WARNING: Removing unreachable block (ram,0x080f70) */
/* WARNING: Removing unreachable block (ram,0x080f80) */

void egs52_transform_far_memory_080f5e(undefined2 param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)CONCAT12(param_2,param_1);
  uVar4 = 0;
  do {
    uVar1 = 0x24;
    if ((((param_3 & 0xc000) != 0) && (uVar1 = 0x21, (param_3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (((*(uint *)((uint3)uVar1 << 0xe | (uint3)(param_3 & 0x3fff)) ^ uVar3) & 1) == 0) {
      uVar1 = 0x24;
      if ((((param_3 & 0xc000) != 0) && (uVar1 = 0x21, (param_3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (param_3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((param_3 & 0xc000) != 0) && (uVar2 = 0x21, (param_3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(param_3 & 0x3fff)) =
           *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_3 & 0x3fff)) >> 1;
    }
    else {
      uVar1 = 0x24;
      if ((((param_3 & 0xc000) != 0) && (uVar1 = 0x21, (param_3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (param_3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((param_3 & 0xc000) != 0) && (uVar2 = 0x21, (param_3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(param_3 & 0x3fff)) =
           *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_3 & 0x3fff)) >> 1 ^ 0xa001;
    }
    uVar3 = (int)uVar3 >> 1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  return;
}


