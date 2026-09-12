/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0969a2; FLS offset 0x0169a2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0969ac) */
/* WARNING: Removing unreachable block (ram,0x0969a6) */

void egs52_update_near_c13e_0969a2(void)

{
  egs52_update_near_cda0_0a56f0();
  Ram00fdf0 = 0;
  UNK_00c13e = 3;
  egs52_update_operating_masks(0x100,7);
  egs52_call_0d02e2_096490();
  return;
}


