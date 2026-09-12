/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0964cc; FLS offset 0x0164cc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Unknown calling convention */

uchar egs52_call_0a1dd2_0964cc(void)

{
  uchar uVar1;
  
  uVar1 = egs52_get_status_c44f();
  return uVar1;
}


