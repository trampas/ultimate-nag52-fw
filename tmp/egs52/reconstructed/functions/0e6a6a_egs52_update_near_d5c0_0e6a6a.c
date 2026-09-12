/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e6a6a; FLS offset 0x066a6a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e6a72) */
/* WARNING: Removing unreachable block (ram,0x0e6a6a) */
/* WARNING: Removing unreachable block (ram,0x0e6a8c) */

void egs52_update_near_d5c0_0e6a6a(void)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = UNK_00d5c0;
  if (cVar2 != '\0') {
    UNK_00d5c0 = 0;
    return;
  }
  UNK_00d5c0 = 1;
  uVar1 = Ram00fd12;
  if ((uVar1 & 0x8000) == 0) {
    uVar1 = Ram00fd12;
    Ram00fd12 = uVar1 | 0x8000;
  }
  else {
    uVar1 = Ram00fd12;
    Ram00fd12 = uVar1 & 0x7fff;
  }
  uVar1 = Ram00fd20;
  if ((uVar1 & 0x4000) != 0) {
    uVar1 = Ram00fd20;
    Ram00fd20 = uVar1 & 0xbfff;
    return;
  }
  uVar1 = Ram00fd20;
  Ram00fd20 = uVar1 | 0x4000;
  return;
}


