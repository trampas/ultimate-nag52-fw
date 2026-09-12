/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e813e; FLS offset 0x06813e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_select_client3_operating_mask(void)

{
  uint uVar1;
  ushort mask;
  
  mask = 1;
  uVar1 = Ram00fd62;
  if ((uVar1 & 1) != 0) {
    mask = 0x800;
  }
  egs52_update_operating_masks(mask,3);
  return;
}


