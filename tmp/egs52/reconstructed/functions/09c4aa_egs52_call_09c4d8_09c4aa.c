/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c4aa; FLS offset 0x01c4aa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined2 egs52_call_09c4d8_09c4aa(undefined2 param_1,undefined1 param_2,char param_3)

{
  undefined2 uVar1;
  
  uVar1 = egs52_call_0a1b8c_09c4d8(param_1,param_2);
  if (param_3 != '\x01') {
    uVar1 = egs52_transform_memory_09c670(uVar1,param_2);
  }
  return uVar1;
}


