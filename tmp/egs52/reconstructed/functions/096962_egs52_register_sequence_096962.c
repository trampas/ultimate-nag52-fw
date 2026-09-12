/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096962; FLS offset 0x016962.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096966) */
/* WARNING: Removing unreachable block (ram,0x096962) */

undefined1 egs52_register_sequence_096962(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0904d4 + 8;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  if (uVar1 < 0x1a4) {
    return 0x5e;
  }
  if (0x208 < uVar1) {
    return 0x3f;
  }
  return 0x4f;
}


