/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097b0a; FLS offset 0x017b0a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_097ad6_097b0a(void)

{
  uint uVar1;
  
  egs52_update_near_c17a_097ad6();
  Ram00ff30 = 0;
  Ram00ff32 = 0;
  uVar1 = Ram00ffd0;
  Ram00ffd0 = uVar1 | 1;
  return;
}


