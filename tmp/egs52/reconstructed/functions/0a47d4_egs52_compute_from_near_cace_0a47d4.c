/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a47d4; FLS offset 0x0247d4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a47e2) */

void egs52_compute_from_near_cace_0a47d4(void)

{
  byte bVar1;
  uint uVar2;
  
  egs52_transform_memory_09f3bc();
  uVar2 = egs52_get_status_c3a2();
  if ((uVar2 & 2) != 0) {
    bVar1 = UNK_00cace;
    UNK_00cace = bVar1 | 2;
  }
  return;
}


