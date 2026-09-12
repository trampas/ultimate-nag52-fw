/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a7d0e; FLS offset 0x027d0e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a7d32) */
/* WARNING: Removing unreachable block (ram,0x0a7d28) */
/* WARNING: Removing unreachable block (ram,0x0a7d24) */
/* WARNING: Removing unreachable block (ram,0x0a7d1e) */
/* WARNING: Removing unreachable block (ram,0x0a7d1a) */
/* WARNING: Removing unreachable block (ram,0x0a7d14) */
/* WARNING: Removing unreachable block (ram,0x0a7d10) */

void egs52_update_near_f8c0_0a7d0e(void)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (((iRam090abc == 0 && iRam090aba == 0) && (iRam090ac0 == 0 && iRam090abe == 0)) &&
     (iRam090ac8 == 0 && iRam090ac6 == 0)) {
    uVar1 = 0;
  }
  UNK_00f8c0 = uVar1;
  return;
}


