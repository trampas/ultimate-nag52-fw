/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095b38; FLS offset 0x015b38.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_095b6a_095b38(undefined2 param_1,undefined1 param_2)

{
  undefined2 uVar1;
  
  uVar1 = egs52_read_channel_table_word(param_2);
  egs52_update_near_caa4_0a3b10(param_1,uVar1,param_2);
  return;
}


