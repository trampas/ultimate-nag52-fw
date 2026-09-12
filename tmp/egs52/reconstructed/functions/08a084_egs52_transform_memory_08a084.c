/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08a084; FLS offset 0x00a084.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08a08e) */

uint egs52_transform_memory_08a084(uint param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1;
  while (param_3 != 0) {
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = param_2;
    param_3 = param_3 + -1;
    uVar2 = uVar2 + 1;
  }
  return param_1;
}


