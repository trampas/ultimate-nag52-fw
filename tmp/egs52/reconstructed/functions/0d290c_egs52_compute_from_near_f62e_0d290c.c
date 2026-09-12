/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d290c; FLS offset 0x05290c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d2912) */
/* WARNING: Removing unreachable block (ram,0x0d290e) */

char egs52_compute_from_near_f62e_0d290c(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = Ram00f62e;
  uVar1 = iVar4 + 0x24;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  cVar3 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar4 = param_1;
  if (param_1 < 0) {
    iVar4 = -param_1;
  }
  if (iVar4 < cVar3) {
    cVar3 = (char)param_1;
  }
  else if (param_1 < 0) {
    cVar3 = -cVar3;
  }
  return cVar3;
}


