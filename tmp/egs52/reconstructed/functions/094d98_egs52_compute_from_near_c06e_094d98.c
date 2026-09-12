/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094d98; FLS offset 0x014d98.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094da8) */

uint egs52_compute_from_near_c06e_094d98(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = egs52_update_near_c170_097904();
  if ((uVar2 & 0x100) == 0) {
    uVar2 = 0x4000;
  }
  else {
    uVar2 = 0;
  }
  uVar1 = Ram00c06e;
  return uVar2 | uVar1;
}


