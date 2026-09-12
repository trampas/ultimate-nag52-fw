/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09945a; FLS offset 0x01945a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099494) */
/* WARNING: Removing unreachable block (ram,0x09949c) */
/* WARNING: Removing unreachable block (ram,0x09945a) */
/* WARNING: Removing unreachable block (ram,0x099486) */

void egs52_update_near_c1aa_09945a(void)

{
  uint uVar1;
  
  uVar1 = Ram00c1aa;
  if (((uVar1 & 1) != 0) && ((uVar1 & 6) == 0)) {
    uVar1 = egs52_compute_from_near_f80a_09941e(0);
    if ((uVar1 & 2) == 0) {
      uVar1 = egs52_compute_from_near_f80a_09941e();
      if ((uVar1 & 0x10) != 0) {
        uVar1 = Ram00c1aa;
        Ram00c1aa = uVar1 | 0x10;
        return;
      }
      egs52_update_operating_masks(0x100,6);
      egs52_set_watchdog_marker_96();
      uVar1 = Ram00c1aa;
      Ram00c1aa = uVar1 | 0xc;
      egs52_update_near_c1aa_0994da();
      return;
    }
    uVar1 = Ram00c1aa;
    Ram00c1aa = uVar1 | 2;
    egs52_update_near_c1aa_0994da();
    egs52_update_near_f80a_099400();
  }
  return;
}


