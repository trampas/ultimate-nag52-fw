/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089e76; FLS offset 0x009e76.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x089e72) */

void egs52_transform_memory_089e76(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    uVar2 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar2 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = param_2 & 0x3fff;
    param_2 = param_2 + 1;
    uVar3 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar3 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(param_1 & 0x3fff)) =
         *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)uVar4);
    param_1 = param_1 + 1;
  }
  return;
}


