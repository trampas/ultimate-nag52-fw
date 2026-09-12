/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081d84; FLS offset 0x001d84.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081daa) */
/* WARNING: Removing unreachable block (ram,0x081da2) */
/* WARNING: Removing unreachable block (ram,0x081d9e) */
/* WARNING: Removing unreachable block (ram,0x081d98) */
/* WARNING: Removing unreachable block (ram,0x081d94) */
/* WARNING: Removing unreachable block (ram,0x081d8e) */
/* WARNING: Removing unreachable block (ram,0x081d84) */

void egs52_update_near_f402_081d84(void)

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


