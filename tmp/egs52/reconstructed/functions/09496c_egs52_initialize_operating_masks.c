/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09496c; FLS offset 0x01496c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09497a) */
/* WARNING: Removing unreachable block (ram,0x094976) */
/* WARNING: Removing unreachable block (ram,0x09496e) */

void egs52_initialize_operating_masks(void)

{
  Ram00c06c = 3;
  Ram00c06e = 0x100;
  Ram00c070 = 0x100;
  return;
}


