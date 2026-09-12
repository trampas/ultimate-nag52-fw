/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09ff9a; FLS offset 0x01ff9a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09ffc0) */
/* WARNING: Removing unreachable block (ram,0x09ffb8) */
/* WARNING: Removing unreachable block (ram,0x09ffb4) */
/* WARNING: Removing unreachable block (ram,0x09ffae) */
/* WARNING: Removing unreachable block (ram,0x09ffaa) */
/* WARNING: Removing unreachable block (ram,0x09ffa4) */
/* WARNING: Removing unreachable block (ram,0x09ff9a) */

void egs52_update_near_f402_09ff9a(void)

{
  if ((bRam00f402 & 1) != 0) {
    bRam00f402 = 2;
    iRam00f5b4 = 9;
  }
  if ((iRam00f5b4 != 0) && (iRam00f5b4 = iRam00f5b4 + -1, iRam00f5b4 == 0)) {
    bRam00f402 = 4;
  }
  return;
}


