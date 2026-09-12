/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096786; FLS offset 0x016786.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09678e) */

void egs52_compute_from_near_c116_096786(void)

{
  byte bVar1;
  
  egs52_call_0987a2_09885c();
  bVar1 = UNK_00c116;
  UNK_00c116 = bVar1 & 0xfc;
  return;
}


