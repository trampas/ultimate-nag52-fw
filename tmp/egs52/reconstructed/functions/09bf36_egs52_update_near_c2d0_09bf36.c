/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bf36; FLS offset 0x01bf36.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bf74) */
/* WARNING: Removing unreachable block (ram,0x09bf70) */
/* WARNING: Removing unreachable block (ram,0x09bf6c) */
/* WARNING: Removing unreachable block (ram,0x09bf68) */
/* WARNING: Removing unreachable block (ram,0x09bf64) */
/* WARNING: Removing unreachable block (ram,0x09bf60) */
/* WARNING: Removing unreachable block (ram,0x09bf58) */
/* WARNING: Removing unreachable block (ram,0x09bf54) */
/* WARNING: Removing unreachable block (ram,0x09bf4c) */
/* WARNING: Removing unreachable block (ram,0x09bf46) */
/* WARNING: Removing unreachable block (ram,0x09bf3e) */
/* WARNING: Removing unreachable block (ram,0x09bf3a) */

void egs52_update_near_c2d0_09bf36(void)

{
  byte bVar1;
  
  UNK_00c2d0 = 0x88;
  UNK_00c2d1 = 0;
  bVar1 = UNK_00c2ce;
  UNK_00c2ce = bVar1 & 0xf0;
  bVar1 = UNK_00c2ce;
  UNK_00c2ce = bVar1 | 1;
  bVar1 = UNK_00c2ce;
  UNK_00c2ce = bVar1 & 0x3f;
  bVar1 = UNK_00c2ce;
  UNK_00c2ce = bVar1 & 0xcf;
  UNK_00c2d3 = 0;
  UNK_00c2d2 = 0;
  UNK_00c2cf = 0;
  UNK_00c2cc = 0;
  return;
}


