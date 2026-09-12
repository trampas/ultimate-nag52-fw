/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5f9c; FLS offset 0x025f9c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5ff0) */
/* WARNING: Removing unreachable block (ram,0x0a5fd6) */
/* WARNING: Removing unreachable block (ram,0x0a5fbc) */
/* WARNING: Removing unreachable block (ram,0x0a5fb0) */
/* WARNING: Removing unreachable block (ram,0x0a5fa0) */

byte egs52_compute_from_near_cda2_0a5f9c(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = Ram00ef00;
  bVar2 = UNK_00cda2;
  uVar5 = Ram00ef00;
  uVar3 = Ram00ee00;
  uVar4 = Ram00ee00;
  return bVar2 | ((uVar1 & 0x8000) != 0) << 4 | ((uVar5 & 0x4000) != 0) << 5 |
         ((uVar3 & 0x8000) != 0) << 6 | ((uVar4 & 0x4000) != 0) << 7;
}


