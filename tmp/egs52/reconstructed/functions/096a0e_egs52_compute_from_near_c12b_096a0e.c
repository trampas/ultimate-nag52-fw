/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096a0e; FLS offset 0x016a0e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096a18) */

void egs52_compute_from_near_c12b_096a0e(void)

{
  char cVar1;
  
  egs52_transform_far_memory_09f3f8();
  egs52_transform_memory_0a4678(0);
  cVar1 = UNK_00c12b;
  UNK_00c12b = cVar1 + '\x01';
  return;
}


