/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094194; FLS offset 0x014194.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Unknown calling convention */

ushort egs52_read_c34e_forwarder(void)

{
  ushort uVar1;
  
  uVar1 = egs52_get_status_c34e();
  return uVar1;
}


