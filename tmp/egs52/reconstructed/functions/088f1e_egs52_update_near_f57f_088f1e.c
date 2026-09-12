/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088f1e; FLS offset 0x008f1e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088f50) */
/* WARNING: Removing unreachable block (ram,0x088f3e) */
/* WARNING: Removing unreachable block (ram,0x088f36) */
/* WARNING: Removing unreachable block (ram,0x088f22) */
/* WARNING: Removing unreachable block (ram,0x088f2e) */

void egs52_update_near_f57f_088f1e(void)

{
  if (cRam083fcc == -1) {
    bRam00f57f = 3;
  }
  else {
    bRam00f57f = 1;
  }
  if ((cRam083e7c == -1) || (cRam083e7c == -4)) {
    bRam00f57f = bRam00f57f | 0xc;
  }
  return;
}


