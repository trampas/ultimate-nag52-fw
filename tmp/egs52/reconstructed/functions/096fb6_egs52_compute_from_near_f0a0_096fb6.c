/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096fb6; FLS offset 0x016fb6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096fe8) */

uint egs52_compute_from_near_f0a0_096fb6(undefined1 param_1)

{
  uint uVar1;
  char cVar2;
  
  egs52_update_near_f0a0_096f96(param_1);
  cVar2 = -0x80;
  while (uVar1 = Ram00ffa0, (uVar1 & 0x800) != 0) {
    if (cVar2 == '\0') {
      uVar1 = Ram00ffa0;
      Ram00ffa0 = uVar1 & 0xf7ff;
      egs52_update_fault_status(0x44,3);
    }
    else {
      cVar2 = cVar2 + -1;
    }
  }
  uVar1 = Ram00f0a0;
  return uVar1 & 0x3ff;
}


