/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096f10; FLS offset 0x016f10.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096f18) */

void egs52_restart_serial_receive(void)

{
  uint uVar1;
  
  uVar1 = Ram00ff98;
  Ram00ff98 = uVar1 & 0xffbf;
  uVar1 = Ram00ffa0;
  Ram00ffa0 = uVar1 & 0xff7f;
  Ram00fcfe = 0xc142;
  Ram00fece = 0x20f;
  uVar1 = Ram00ffa0;
  Ram00ffa0 = uVar1 | 0x80;
  uVar1 = Ram00ff98;
  Ram00ff98 = uVar1 | 0x40;
  return;
}


