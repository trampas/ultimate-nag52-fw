/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09950e; FLS offset 0x01950e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099546) */
/* WARNING: Removing unreachable block (ram,0x099536) */
/* WARNING: Removing unreachable block (ram,0x09950e) */
/* WARNING: Removing unreachable block (ram,0x09952e) */
/* WARNING: Removing unreachable block (ram,0x09954e) */

void egs52_update_near_c1aa_09950e(void)

{
  uint uVar1;
  
  uVar1 = Ram00c1aa;
  if (((uVar1 & 4) != 0) && ((uVar1 & 8) == 0)) {
    egs52_update_operating_masks(1,6);
    uVar1 = egs52_compute_from_near_f80a_09941e();
    if ((uVar1 & 4) == 0) {
      uVar1 = Ram00c1aa;
      Ram00c1aa = uVar1 & 0xfffb | 0x100;
      egs52_update_fault_status(0x3b,2);
      return;
    }
    egs52_update_near_f80a_0993d6();
    uVar1 = Ram00c1aa;
    Ram00c1aa = uVar1 & 0xfffb | 0x10;
    egs52_update_fault_status(0x3b,3);
    return;
  }
  egs52_update_fault_status(0x3b,0);
  return;
}


