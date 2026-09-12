/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098170; FLS offset 0x018170.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0981b2) */
/* WARNING: Removing unreachable block (ram,0x098182) */
/* WARNING: Removing unreachable block (ram,0x0981be) */

undefined1 egs52_update_near_c18b_098170(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 uVar3;
  
  __write_psw_bits(0x40,0x40);
  uVar1 = Ram00fd02;
  uVar2 = Ram00fd02;
  if ((uVar2 & 1) == 1) {
    __write_psw_bits(0x40,0);
    UNK_00c18b = 1;
    uVar3 = 0;
  }
  else {
    uVar2 = Ram00fd02;
    Ram00fd02 = uVar2 | 1;
    UNK_00c18b = 0;
    uVar2 = Ram00ffc0;
    if ((uVar2 & 0x1000) == 0) {
      uVar2 = Ram00ffc0;
      Ram00ffc0 = uVar2 | 0x1000;
      uVar2 = Ram00ffc0;
      Ram00ffc0 = uVar2 & 0xefff;
    }
    uVar2 = Ram00ffc0;
    if ((uVar2 & 8) == 0) {
      uVar2 = Ram00ffc0;
      Ram00ffc0 = uVar2 | 8;
      uVar2 = Ram00ffc0;
      Ram00ffc0 = uVar2 & 0xfff7;
    }
    uVar2 = Ram00ffb2;
    Ram00ffb2 = uVar2 & 0x7fff;
    uVar2 = Ram00ffb2;
    Ram00ffb2 = uVar2 & 0xffdf;
    uVar2 = Ram00ffb2;
    Ram00ffb2 = uVar2 & 0xffef;
    uVar2 = Ram00ffb2;
    Ram00ffb2 = uVar2 | 0x8000;
    UNK_00c17e = 0;
    uVar2 = Ram00ff74;
    Ram00ff74 = uVar2 | 0x80;
    uVar3 = 1;
  }
  return uVar3;
}


