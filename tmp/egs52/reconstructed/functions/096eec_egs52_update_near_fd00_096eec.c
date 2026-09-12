/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096eec; FLS offset 0x016eec.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096efe) */
/* WARNING: Removing unreachable block (ram,0x096ef6) */

void egs52_update_near_fd00_096eec(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0x7fff;
  Ram00ffa0 = 0xf22e;
  Ram00fcfc = 0xfea0;
  Ram00fcfe = 0xc142;
  Ram00fece = 0x20f;
  Ram00ff98 = 0x3f;
  egs52_restart_serial_receive();
  return;
}


