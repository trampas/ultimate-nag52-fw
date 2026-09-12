/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094e18; FLS offset 0x014e18.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_0964d2_094e18(void)

{
  uint uVar1;
  
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x200) == 0) {
    egs52_update_fault_status(8,0x40);
    return;
  }
  uVar1 = egs52_compute_from_near_c189_0981ca(1);
  if (((uVar1 & 0xff) >> 2 & 3) == 3) {
    egs52_update_fault_status(8,2);
    return;
  }
  egs52_update_fault_status(8,3);
  return;
}


