/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c016; FLS offset 0x01c016.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09c026) */
/* WARNING: Removing unreachable block (ram,0x09c016) */

undefined1 egs52_update_near_d2d3_09c016(undefined1 param_1)

{
  byte bVar1;
  
  bVar1 = UNK_00c2ce;
  if ((bVar1 & 0x30) == 0) {
    UNK_00d2d3 = param_1;
    egs52_compute_from_near_c2ce_09bf18(bVar1 & 0x30);
    return 0;
  }
  return 3;
}


