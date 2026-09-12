/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a69a6; FLS offset 0x0269a6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a69d0) */
/* WARNING: Removing unreachable block (ram,0x0a69da) */
/* WARNING: Removing unreachable block (ram,0x0a69c8) */
/* WARNING: Removing unreachable block (ram,0x0a69a8) */
/* WARNING: Removing unreachable block (ram,0x0a69c0) */

void egs52_update_near_f581_0a69a6(uint param_1)

{
  param_1 = param_1 >> (((byte)(cRam00f580 - 1) & 3) << 2);
  if ((param_1 & 0xf) == 0) {
    uRam00f581 = 0x80;
  }
  else if (((byte)param_1 & 0xf & bRam00f57f) == 0) {
    uRam00f581 = 0x33;
  }
  else {
    uRam00f581 = 0;
  }
  return;
}


