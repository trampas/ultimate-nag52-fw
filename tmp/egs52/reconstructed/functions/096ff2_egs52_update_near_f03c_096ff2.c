/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096ff2; FLS offset 0x016ff2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097030) */

void egs52_update_near_f03c_096ff2(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xfffb;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xffbf;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xfbff;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 | 4;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0xffbf;
  Ram00f03c = 24000;
  Ram00fe34 = 24000;
  Ram00f034 = 0;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0xbfff;
  uVar1 = Ram00ffd0;
  Ram00ffd0 = uVar1 | 4;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xfff7;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xff7f;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xf7ff;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 | 8;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0xff7f;
  Ram00f03e = 24000;
  Ram00fe36 = 24000;
  Ram00f036 = 0;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0x7fff;
  uVar1 = Ram00ffd0;
  Ram00ffd0 = uVar1 | 8;
  bVar2 = UNK_00c160;
  UNK_00c160 = bVar2 | 1;
  return;
}


