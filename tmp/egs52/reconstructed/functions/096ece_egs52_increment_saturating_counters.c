/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096ece; FLS offset 0x016ece.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096ee6) */
/* WARNING: Removing unreachable block (ram,0x096edc) */
/* WARNING: Removing unreachable block (ram,0x096ed8) */
/* WARNING: Removing unreachable block (ram,0x096ece) */

void egs52_increment_saturating_counters(void)

{
  if (uRam00f45e < 0xfffc) {
    uRam00f45e = uRam00f45e + 1;
  }
  if (uRam00f572 < 0xfffc) {
    uRam00f572 = uRam00f572 + 1;
  }
  return;
}


