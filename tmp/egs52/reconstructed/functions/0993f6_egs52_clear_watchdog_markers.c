/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0993f6; FLS offset 0x0193f6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0993fa) */
/* WARNING: Removing unreachable block (ram,0x0993f6) */

void egs52_clear_watchdog_markers(void)

{
  UNK_00f80a = 0;
  UNK_00fdfb = 0;
  return;
}


