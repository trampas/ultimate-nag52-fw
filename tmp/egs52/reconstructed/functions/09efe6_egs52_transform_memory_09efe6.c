/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09efe6; FLS offset 0x01efe6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f004) */
/* WARNING: Removing unreachable block (ram,0x09f00e) */

void egs52_transform_memory_09efe6(uint param_1,uint param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  
  for (; param_4 != 0; param_4 = param_4 + -1) {
    bVar1 = 0xfffe < param_2;
    uVar2 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) =
         *(undefined1 *)
          ((uint3)((param_3 & 0xff) << 2 | (param_2 & 0x4000) >> 0xe | (param_2 >> 0xf) << 1) << 0xe
          | (uint3)(param_2 & 0x3fff));
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + bVar1;
  }
  return;
}


