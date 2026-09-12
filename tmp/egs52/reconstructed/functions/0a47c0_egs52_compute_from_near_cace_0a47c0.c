/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a47c0; FLS offset 0x0247c0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a47ce) */

void egs52_compute_from_near_cace_0a47c0(void)

{
  byte bVar1;
  uint uVar2;
  
  egs52_update_near_c3a2_09f35a();
  uVar2 = egs52_get_status_c3a2();
  if ((uVar2 & 1) != 0) {
    bVar1 = UNK_00cace;
    UNK_00cace = bVar1 | 1;
  }
  return;
}


