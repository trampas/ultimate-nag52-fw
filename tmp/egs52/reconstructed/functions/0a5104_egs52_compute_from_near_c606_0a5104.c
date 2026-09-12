/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5104; FLS offset 0x025104.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5104) */

undefined1 egs52_compute_from_near_c606_0a5104(void)

{
  ushort mask;
  
  mask = Ram00c606;
  egs52_update_operating_masks(mask,0);
  return 0;
}


