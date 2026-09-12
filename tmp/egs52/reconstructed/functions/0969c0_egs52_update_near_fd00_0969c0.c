/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0969c0; FLS offset 0x0169c0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_update_near_fd00_0969c0(void)

{
  uint uVar1;
  ushort uVar2;
  
  egs52_update_near_c10a_0965d2();
  uVar2 = egs52_get_operating_mask();
  if (uVar2 != 0x100) {
    egs52_update_near_c16e_097350();
  }
  egs52_update_near_c1aa_0994da();
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 | 0x40;
  return;
}


