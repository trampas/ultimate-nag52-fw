/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2418; FLS offset 0x022418.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2430) */
/* WARNING: Removing unreachable block (ram,0x0a2420) */
/* WARNING: Removing unreachable block (ram,0x0a2428) */

undefined1 egs52_transform_memory_0a2418(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  Ram00c606 = 0;
  uVar2 = 0xc506;
  do {
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
    uVar2 = uVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return 0;
}


