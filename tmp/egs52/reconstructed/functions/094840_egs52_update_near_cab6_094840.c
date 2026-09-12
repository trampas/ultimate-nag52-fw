/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094840; FLS offset 0x014840.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094874) */
/* WARNING: Removing unreachable block (ram,0x09486c) */
/* WARNING: Removing unreachable block (ram,0x094852) */
/* WARNING: Removing unreachable block (ram,0x09484c) */
/* WARNING: Removing unreachable block (ram,0x094846) */
/* WARNING: Removing unreachable block (ram,0x09485e) */

void egs52_update_near_cab6_094840(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  UNK_00f7b5 = 0x30;
  UNK_00f7b6 = 8;
  UNK_00f7b7 = 2;
  bVar3 = 3;
  do {
    uVar1 = bVar3 - 0x84b;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);
  uRam00f45e = 0;
  Ram00cab6 = 0x7e;
  egs52_transform_far_memory_0a0770(2,8);
  return;
}


