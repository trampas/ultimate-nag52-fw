/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a00c6; FLS offset 0x0200c6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a00ca) */

void egs52_update_near_c34e_0a00c6(void)

{
  uint uVar1;
  
  uVar1 = Ram00c34e;
  Ram00c34e = uVar1 & 0xfffd;
  egs52_transform_memory_0a5f76();
  return;
}


