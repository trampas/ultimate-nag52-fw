/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096a1e; FLS offset 0x016a1e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096a4c) */
/* WARNING: Removing unreachable block (ram,0x096a46) */
/* WARNING: Removing unreachable block (ram,0x096a42) */
/* WARNING: Removing unreachable block (ram,0x096a34) */
/* WARNING: Removing unreachable block (ram,0x096a24) */
/* WARNING: Removing unreachable block (ram,0x096a56) */
/* WARNING: Removing unreachable block (ram,0x096a28) */

void egs52_update_near_c12e_096a1e(void)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x80) == 0) {
    cVar2 = UNK_00c12c;
    UNK_00c12c = cVar2 + '\x01';
    UNK_00c12e = 0;
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x400;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xff7f;
  return;
}


