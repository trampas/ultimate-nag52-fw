/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094dd2; FLS offset 0x014dd2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094df8) */

void egs52_update_near_c086_094dd2(void)

{
  uint uVar1;
  
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x200) == 0) {
    uVar1 = Ram00ffc0;
    Ram00ffc0 = uVar1 | 0x1000;
  }
  else {
    egs52_call_0964d2_094dfe(1);
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x100) == 0) {
    uVar1 = Ram00ffc4;
    Ram00ffc4 = uVar1 | 1;
  }
  else {
    egs52_update_near_fd26_094e88(1);
  }
  Ram00c086 = 3;
  return;
}


