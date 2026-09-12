/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8166; FLS offset 0x058166.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8172) */
/* WARNING: Removing unreachable block (ram,0x0d816e) */
/* WARNING: Removing unreachable block (ram,0x0d816a) */
/* WARNING: Removing unreachable block (ram,0x0d8166) */

int egs52_sum_pressure_terms(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = Ram00d4d2;
  iVar2 = Ram00d47c;
  iVar3 = Ram00d490;
  iVar4 = Ram00d4b2;
  return ((iVar1 + iVar2) - iVar3) - iVar4;
}


