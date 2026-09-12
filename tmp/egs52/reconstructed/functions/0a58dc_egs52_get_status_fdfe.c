/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a58dc; FLS offset 0x0258dc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a58dc) */
/* WARNING: Unknown calling convention */

ushort egs52_get_status_fdfe(void)

{
  ushort uVar1;
  
  uVar1 = Ram00fdfe;
  return uVar1;
}


