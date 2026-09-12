/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a474e; FLS offset 0x02474e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4758) */

void egs52_update_near_caca_0a474e(void)

{
  egs52_call_096eec_09c448();
  egs52_update_near_c31a_09c710();
  Ram00caca = 3;
  return;
}


