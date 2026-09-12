/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6e94; FLS offset 0x056e94.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6ea8) */
/* WARNING: Removing unreachable block (ram,0x0d6ea4) */
/* WARNING: Removing unreachable block (ram,0x0d6ea2) */
/* WARNING: Removing unreachable block (ram,0x0d6e9c) */
/* WARNING: Removing unreachable block (ram,0x0d6e94) */

char egs52_lookup_and_offset_d467(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  iVar4 = Ram00f624;
  bVar5 = UNK_00d579;
  uVar3 = iVar4 + 0xa1 + (uint)bVar5;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  cVar2 = UNK_00d468;
  cVar2 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) + cVar2;
  UNK_00d467 = cVar2;
  return cVar2;
}


