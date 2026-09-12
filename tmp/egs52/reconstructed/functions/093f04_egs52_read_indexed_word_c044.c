/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093f04; FLS offset 0x013f04.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093f7c) */
/* WARNING: Removing unreachable block (ram,0x093f76) */
/* WARNING: Removing unreachable block (ram,0x093f6a) */
/* WARNING: Removing unreachable block (ram,0x093f64) */
/* WARNING: Removing unreachable block (ram,0x093f60) */
/* WARNING: Removing unreachable block (ram,0x093f56) */
/* WARNING: Removing unreachable block (ram,0x093f50) */
/* WARNING: Removing unreachable block (ram,0x093f3e) */
/* WARNING: Removing unreachable block (ram,0x093f30) */
/* WARNING: Removing unreachable block (ram,0x093f4c) */
/* WARNING: Removing unreachable block (ram,0x093f44) */
/* WARNING: Removing unreachable block (ram,0x093f10) */
/* WARNING: Removing unreachable block (ram,0x093f2a) */
/* WARNING: Unknown calling convention */

uchar egs52_read_indexed_word_c044(uchar *destination)

{
  uint uVar1;
  uchar *puVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  
  bVar7 = egs52_get_status_c32a();
  if ((bVar7 & 4) != 0) {
    return 'x';
  }
  bVar7 = UNK_00c043;
  if (bVar7 < 8) {
    bVar7 = UNK_00c043;
    bVar5 = UNK_00c040;
    UNK_00c040 = bVar5 | (byte)(1 << (bVar7 & 0xf));
  }
  else if (bVar7 < 0x10) {
    cVar6 = UNK_00c043;
    bVar7 = UNK_00c041;
    UNK_00c041 = bVar7 | (byte)(1 << ((byte)(cVar6 - 8) & 0xf));
  }
  else {
    bVar5 = UNK_00c042;
    UNK_00c042 = bVar5 | (byte)(1 << ((byte)(bVar7 - 0x10) & 0xf));
  }
  bVar7 = UNK_00c043;
  uVar1 = (uint)bVar7 * 2 + 0xc044;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  puVar2 = destination + 1;
  uVar4 = 0x24;
  if (((((uint)puVar2 & 0xc000) != 0) && (uVar4 = 0x21, ((uint)puVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, ((uint)puVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  *(char *)((uint3)uVar4 << 0xe | (uint3)((uint)puVar2 & 0x3fff)) =
       (char)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar7 = UNK_00c043;
  uVar1 = (uint)bVar7 * 2 + 0xc044;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar4 = 0x24;
  if (((((uint)destination & 0xc000) != 0) && (uVar4 = 0x21, ((uint)destination & 0xc000) != 0x4000)
      ) && (uVar4 = 0x2c, ((uint)destination & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  *(char *)((uint3)uVar4 << 0xe | (uint3)((uint)destination & 0x3fff)) =
       (char)((uint)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) >> 8);
  bVar7 = UNK_00c064;
  UNK_00c064 = bVar7 & 0xfb;
  return '\0';
}


