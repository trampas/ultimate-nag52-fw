/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c462; FLS offset 0x01c462.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_096f56_09c462(undefined1 param_1,undefined1 param_2)

{
  undefined2 uVar1;
  
  uVar1 = egs52_update_near_fd00_096f56(param_1,param_2);
  egs52_call_09c4d8_09c4aa(uVar1,param_1,0);
  return;
}


