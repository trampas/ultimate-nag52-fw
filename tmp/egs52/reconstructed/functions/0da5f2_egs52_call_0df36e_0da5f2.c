/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da5f2; FLS offset 0x05a5f2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

int egs52_call_0df36e_0da5f2(ushort param_1,ushort param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = egs52_vector_length_estimate(param_1,param_2);
    if (param_3 < uVar1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1000 - (int)(((ulong)uVar1 * 1000) / (ulong)param_3);
    }
  }
  return iVar2;
}


