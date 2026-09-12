/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096e76; FLS offset 0x016e76.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096e7e) */
/* WARNING: Removing unreachable block (ram,0x096e7a) */
/* WARNING: Removing unreachable block (ram,0x096e76) */

void egs52_reset_receive_counters(void)

{
  Ram00fdf2 = 0;
  Ram00fdf4 = 0;
  UNK_00c140 = 0;
  return;
}


