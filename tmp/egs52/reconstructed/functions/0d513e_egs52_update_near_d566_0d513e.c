/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d513e; FLS offset 0x05513e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d5148) */
/* WARNING: Removing unreachable block (ram,0x0d5144) */

void egs52_update_near_d566_0d513e(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 | 0x10;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfffd;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfffb;
  UNK_00d566 = 0;
  UNK_00d437 = 0;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xefff;
  return;
}


