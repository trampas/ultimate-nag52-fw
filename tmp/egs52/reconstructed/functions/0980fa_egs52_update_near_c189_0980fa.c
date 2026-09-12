/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0980fa; FLS offset 0x0180fa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09815a) */
/* WARNING: Removing unreachable block (ram,0x098156) */
/* WARNING: Removing unreachable block (ram,0x098152) */

void egs52_update_near_c189_0980fa(void)

{
  uint uVar1;
  
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x200;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xfdff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x200;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x100;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xfeff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 & 0xfeff;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x2000;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xdfff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x2000;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 8;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xfff7;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 8;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x10;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xffef;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x10;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x8000;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0x7fff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x8000;
  uVar1 = Ram00ffb2;
  Ram00ffb2 = uVar1 & 0x7fff;
  Ram00ffb2 = 0x4237;
  Ram00f0b4 = 0xb;
  uVar1 = Ram00ffb2;
  Ram00ffb2 = uVar1 | 0x8000;
  Ram00ff74 = 0x79;
  Ram00ff72 = 0x38;
  Ram00ff76 = 0x3a;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 & 0xffdf;
  UNK_00c189 = 0xff;
  UNK_00c18a = 0xff;
  UNK_00c18b = 0;
  uVar1 = Ram00fd02;
  Ram00fd02 = uVar1 & 0xfffe;
  uVar1 = Ram00fd02;
  Ram00fd02 = uVar1 & 0xfffd;
  return;
}


