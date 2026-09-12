/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bed0; FLS offset 0x01bed0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bf12) */
/* WARNING: Removing unreachable block (ram,0x09bf0a) */
/* WARNING: Removing unreachable block (ram,0x09bf06) */
/* WARNING: Removing unreachable block (ram,0x09befe) */
/* WARNING: Removing unreachable block (ram,0x09befa) */
/* WARNING: Removing unreachable block (ram,0x09bef6) */
/* WARNING: Removing unreachable block (ram,0x09bef2) */
/* WARNING: Removing unreachable block (ram,0x09beee) */
/* WARNING: Removing unreachable block (ram,0x09beea) */
/* WARNING: Removing unreachable block (ram,0x09bee4) */
/* WARNING: Removing unreachable block (ram,0x09bed8) */
/* WARNING: Removing unreachable block (ram,0x09bed4) */

void egs52_update_near_d2d3_09bed0(void)

{
  byte bVar1;
  byte bVar2;
  
  UNK_00d2d3 = 0x30;
  bVar1 = UNK_00c2d1;
  UNK_00d2d4 = bVar1 >> 4;
  UNK_00d2d5 = 10;
  UNK_00d2da = 0xff;
  UNK_00d2d9 = 0xff;
  UNK_00d2d8 = 0xff;
  UNK_00d2d7 = 0xff;
  UNK_00d2d6 = 0xff;
  bVar1 = UNK_00c2d1;
  UNK_00c2d1 = bVar1 & 0xf0;
  bVar1 = UNK_00c2d1;
  bVar2 = UNK_00c2d1;
  UNK_00c2d1 = bVar2 | bVar1 >> 4;
  return;
}


