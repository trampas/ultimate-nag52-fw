/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d289a; FLS offset 0x05289a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d28ba) */
/* WARNING: Removing unreachable block (ram,0x0d28e2) */
/* WARNING: Removing unreachable block (ram,0x0d28de) */
/* WARNING: Removing unreachable block (ram,0x0d2902) */
/* WARNING: Removing unreachable block (ram,0x0d2906) */
/* WARNING: Removing unreachable block (ram,0x0d28d4) */

void egs52_update_near_d3f6_0d289a(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_4;
  if (param_1 < param_4) {
    iVar1 = param_1;
  }
  iVar2 = param_3;
  if (param_3 < iVar1) {
    iVar2 = iVar1;
  }
  if ((param_3 + param_4) / 2 <= iVar2) {
    if (param_3 != param_4) {
      Ram00d3f6 = (int)(((long)param_2 * (long)(param_4 - iVar2)) / (long)(param_4 - param_3)) << 1;
      Ram00d3f4 = param_2;
      return;
    }
    Ram00d3f6 = param_2;
    Ram00d3f4 = param_2;
    return;
  }
  Ram00d3f6 = param_2;
  Ram00d3f4 = (int)(((long)param_2 * (long)(iVar2 - param_3)) / (long)(param_4 - param_3)) << 1;
  return;
}


