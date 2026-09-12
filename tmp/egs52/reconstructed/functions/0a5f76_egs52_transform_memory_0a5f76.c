/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5f76; FLS offset 0x025f76.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5f96) */
/* WARNING: Removing unreachable block (ram,0x0a5f90) */
/* WARNING: Removing unreachable block (ram,0x0a5f8c) */
/* WARNING: Removing unreachable block (ram,0x0a5f84) */
/* WARNING: Removing unreachable block (ram,0x0a5f7e) */
/* WARNING: Removing unreachable block (ram,0x0a5f7a) */

void egs52_transform_memory_0a5f76(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = Ram00ef00;
  Ram00ef00 = uVar1 | 1;
  bVar2 = UNK_00cda2;
  UNK_00cda2 = bVar2 & 0xfd;
  uVar1 = Ram00ee00;
  Ram00ee00 = uVar1 | 1;
  bVar2 = UNK_00cda2;
  UNK_00cda2 = bVar2 & 0xf7;
  return;
}


