/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095abc; FLS offset 0x015abc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_095b6a_095abc(undefined1 param_1)

{
  undefined2 uVar1;
  
  uVar1 = egs52_read_channel_table_word(param_1);
  egs52_update_near_caa4_0a2fba(param_1,uVar1);
  return;
}


