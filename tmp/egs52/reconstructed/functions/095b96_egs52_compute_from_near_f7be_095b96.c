/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095b96; FLS offset 0x015b96.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095ba8) */
/* WARNING: Removing unreachable block (ram,0x095b96) */

uint egs52_compute_from_near_f7be_095b96(void)

{
  byte bVar1;
  
  bVar1 = UNK_00f7be;
  if (0x34 < bVar1) {
    return 3;
  }
  if (bVar1 != 0) {
    bVar1 = UNK_00f7be;
    return (uint)bVar1 << 8 | 2;
  }
  return 0;
}


