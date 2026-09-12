/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0994ba; FLS offset 0x0194ba.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0994c2) */

void egs52_update_near_c1aa_0994ba(void)

{
  uint uVar1;
  
  egs52_clear_watchdog_markers();
  uVar1 = Ram00c1aa;
  Ram00c1aa = uVar1 & 0xfffd;
  return;
}


