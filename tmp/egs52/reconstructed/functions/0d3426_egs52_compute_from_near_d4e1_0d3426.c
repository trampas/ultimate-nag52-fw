/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d3426; FLS offset 0x053426.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d345c) */
/* WARNING: Removing unreachable block (ram,0x0d3456) */
/* WARNING: Removing unreachable block (ram,0x0d3452) */
/* WARNING: Removing unreachable block (ram,0x0d343e) */
/* WARNING: Removing unreachable block (ram,0x0d342a) */
/* WARNING: Removing unreachable block (ram,0x0d3426) */

uint egs52_compute_from_near_d4e1_0d3426(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = UNK_00d4e1;
  uVar2 = Ram00d46e;
  uVar4 = Ram00d43c;
  iVar3 = Ram00d54a;
  uVar4 = (int)(((((ulong)uVar2 * (ulong)param_1) / (ulong)bVar1 & 0xffff) * (ulong)uVar4) / 1000) +
          iVar3;
  uVar2 = Ram00d552;
  if (uVar2 <= uVar4) {
    uVar4 = Ram00d552;
  }
  return uVar4;
}


