/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bf18; FLS offset 0x01bf18.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bf30) */
/* WARNING: Removing unreachable block (ram,0x09bf28) */

void egs52_compute_from_near_c2ce_09bf18(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = egs52_transform_far_memory_0a0770(0,8);
  if (iVar2 != 1) {
    bVar1 = UNK_00c2ce;
    UNK_00c2ce = bVar1 & 0xcf;
    bVar1 = UNK_00c2ce;
    UNK_00c2ce = bVar1 | 0x30;
  }
  return;
}


