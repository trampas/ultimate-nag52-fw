/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096e0c; FLS offset 0x016e0c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096e36) */
/* WARNING: Removing unreachable block (ram,0x096e30) */
/* WARNING: Removing unreachable block (ram,0x096e2c) */
/* WARNING: Removing unreachable block (ram,0x096e12) */
/* WARNING: Removing unreachable block (ram,0x096e40) */
/* WARNING: Removing unreachable block (ram,0x096e16) */

void egs52_update_near_c138_096e0c(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x2000) == 0) {
    UNK_00c138 = 0;
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x2000;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xdfff;
  return;
}


