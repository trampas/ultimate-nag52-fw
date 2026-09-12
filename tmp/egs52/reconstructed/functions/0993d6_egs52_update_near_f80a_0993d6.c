/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0993d6; FLS offset 0x0193d6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0993de) */
/* WARNING: Removing unreachable block (ram,0x0993da) */

void egs52_update_near_f80a_0993d6(void)

{
  UNK_00f80a = 0xe7;
  UNK_00fdfb = 0xe7;
  egs52_update_operating_masks(1,6);
  egs52_update_fault_status(0x3b,3);
  return;
}


