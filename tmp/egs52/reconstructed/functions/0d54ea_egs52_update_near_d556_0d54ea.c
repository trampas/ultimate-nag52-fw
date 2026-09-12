/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d54ea; FLS offset 0x0554ea.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d54f6) */
/* WARNING: Removing unreachable block (ram,0x0d54ee) */
/* WARNING: Removing unreachable block (ram,0x0d54ea) */

void egs52_update_near_d556_0d54ea(void)

{
  uint uVar1;
  
  Ram00d556 = 0;
  Ram00d56c = 0;
  uVar1 = Ram00fd5a;
  if ((uVar1 & 0x20) == 0) {
    UNK_00d437 = 0;
  }
  return;
}


