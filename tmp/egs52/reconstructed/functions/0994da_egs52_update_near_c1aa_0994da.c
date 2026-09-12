/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0994da; FLS offset 0x0194da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099500) */
/* WARNING: Removing unreachable block (ram,0x0994f6) */
/* WARNING: Removing unreachable block (ram,0x0994f2) */
/* WARNING: Removing unreachable block (ram,0x0994e6) */
/* WARNING: Removing unreachable block (ram,0x0994da) */

void egs52_update_near_c1aa_0994da(void)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = Ram00c1aa;
  if ((((uVar1 & 4) != 0) && ((uVar1 & 8) != 0)) || (uVar1 = Ram00c1aa, (uVar1 & 2) != 0)) {
    __atomic(4);
    uVar1 = Ram00ffcc;
    Ram00ffcc = uVar1 | 0x20;
    uVar2 = UNK_00fdf2;
    UNK_00fdfd = uVar2;
    uVar1 = Ram00ffcc;
    Ram00ffcc = uVar1 & 0xffdf;
    uVar1 = Ram00c1aa;
    Ram00c1aa = uVar1 & 0xfff7;
    egs52_update_operating_masks(1,6);
  }
  return;
}


