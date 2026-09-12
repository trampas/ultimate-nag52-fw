/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0999ec; FLS offset 0x0199ec.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0999f6) */

void egs52_update_near_c2b6_0999ec(void)

{
  ushort uVar1;
  
  uVar1 = egs52_get_status_c34e();
  UNK_00c2b6 = (byte)(uVar1 >> 0xc);
  egs52_update_near_c34e_0a08ee(1);
  return;
}


