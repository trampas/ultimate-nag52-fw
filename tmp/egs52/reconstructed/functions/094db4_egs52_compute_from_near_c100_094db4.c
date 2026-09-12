/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094db4; FLS offset 0x014db4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094db6) */

void egs52_compute_from_near_c100_094db4(void)

{
  uint uVar1;
  
  uVar1 = Ram00c100;
  if ((uVar1 & 0x208) != 0) {
    egs52_update_operating_masks(uVar1 & 0x208,4);
  }
  return;
}


