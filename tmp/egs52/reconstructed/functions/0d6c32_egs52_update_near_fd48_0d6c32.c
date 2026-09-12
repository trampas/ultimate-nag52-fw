/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6c32; FLS offset 0x056c32.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_update_near_fd48_0d6c32(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfff7;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xffef;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xffdf;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xffbf;
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xfffe;
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xfffd;
  uVar1 = Ram00fd4c;
  Ram00fd4c = uVar1 & 0xffbf;
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xfffb;
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xfff7;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xfffd;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xfffb;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xffef;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xffdf;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 | 8;
  uVar1 = Ram00fd3c;
  Ram00fd3c = uVar1 & 0xff7f;
  return;
}


