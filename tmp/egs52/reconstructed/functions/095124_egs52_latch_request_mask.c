/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095124; FLS offset 0x015124.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095124) */

void egs52_latch_request_mask(uint param_1)

{
  uint uVar1;
  
  uVar1 = Ram00c086;
  Ram00c086 = uVar1 | param_1;
  return;
}


