/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08298a; FLS offset 0x00298a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0829b8) */
/* WARNING: Removing unreachable block (ram,0x0829b2) */
/* WARNING: Removing unreachable block (ram,0x0829aa) */
/* WARNING: Removing unreachable block (ram,0x0829a6) */
/* WARNING: Removing unreachable block (ram,0x0829a2) */
/* WARNING: Removing unreachable block (ram,0x08299e) */
/* WARNING: Removing unreachable block (ram,0x08299a) */
/* WARNING: Removing unreachable block (ram,0x082994) */
/* WARNING: Removing unreachable block (ram,0x082990) */
/* WARNING: Removing unreachable block (ram,0x08298a) */

void egs52_update_near_f456_08298a(void)

{
  iRam00f456 = iRam00f464 + -1;
  iRam00f454 = iRam00f462 + -1;
  uRam00f45a = (uint)bRam00f469;
  uRam00f458 = (uint)bRam00f468;
  uRam00f40e = 0x16;
  uRam00f410 = 2;
  egs52_update_near_f40a_089ce0(0xf40e);
  return;
}


