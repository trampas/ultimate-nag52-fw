/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a47a8; FLS offset 0x0247a8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_09cb22_0a47a8(void)

{
  uchar uVar1;
  
  uVar1 = egs52_get_status_c31b();
  if (uVar1 != '\x01') {
    __write_psw_bits(0x40,0);
    return;
  }
  __write_psw_bits(0x40,0x40);
  return;
}


