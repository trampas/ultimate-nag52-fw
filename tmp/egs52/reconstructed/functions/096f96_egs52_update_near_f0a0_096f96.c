/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096f96; FLS offset 0x016f96.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096fa4) */

void egs52_update_near_f0a0_096f96(int param_1)

{
  uint uVar1;
  
  uVar1 = Ram00ffa0;
  if ((uVar1 & 0x800) == 0) {
    Ram00f0a0 = param_1 << 0xc;
    uVar1 = Ram00ffa0;
    Ram00ffa0 = uVar1 | 0x200;
    uVar1 = Ram00ffa0;
    Ram00ffa0 = uVar1 | 0x400;
    uVar1 = Ram00ffa0;
    Ram00ffa0 = uVar1 | 0x800;
    __write_psw_bits(0x40,0x40);
    return;
  }
  __write_psw_bits(0x40,0);
  return;
}


