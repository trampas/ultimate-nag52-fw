/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097b1a; FLS offset 0x017b1a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097b3a) */
/* WARNING: Removing unreachable block (ram,0x097b30) */
/* WARNING: Removing unreachable block (ram,0x097b28) */
/* WARNING: Removing unreachable block (ram,0x097b24) */
/* WARNING: Removing unreachable block (ram,0x097b1a) */

void egs52_update_near_f808_097b1a(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Ram00f806;
  if ((uVar1 & 1) != 0) {
    UNK_00f808 = 1;
    iVar2 = Ram00f052;
    Ram00fe7c = iVar2 + 3000;
    uVar1 = Ram00f18c;
    Ram00f18c = uVar1 | 0x40;
    uVar1 = Ram00f806;
    Ram00f806 = uVar1 | 2;
  }
  return;
}


