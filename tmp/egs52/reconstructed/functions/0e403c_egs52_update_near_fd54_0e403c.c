/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e403c; FLS offset 0x06403c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4082) */
/* WARNING: Removing unreachable block (ram,0x0e407e) */
/* WARNING: Removing unreachable block (ram,0x0e407a) */
/* WARNING: Removing unreachable block (ram,0x0e4072) */
/* WARNING: Removing unreachable block (ram,0x0e406c) */
/* WARNING: Removing unreachable block (ram,0x0e4064) */
/* WARNING: Removing unreachable block (ram,0x0e405a) */
/* WARNING: Removing unreachable block (ram,0x0e4048) */
/* WARNING: Removing unreachable block (ram,0x0e4096) */
/* WARNING: Removing unreachable block (ram,0x0e4092) */
/* WARNING: Removing unreachable block (ram,0x0e4040) */
/* WARNING: Removing unreachable block (ram,0x0e403c) */
/* WARNING: Removing unreachable block (ram,0x0e408e) */
/* WARNING: Removing unreachable block (ram,0x0e4050) */

void egs52_update_near_fd54_0e403c(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = Ram00f61e;
  uVar1 = iVar4 + 0x1d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x80) == 0) {
    uVar7 = Ram00fd16;
    uVar2 = Ram00fd0c;
    uVar1 = Ram00d3be;
    uVar8 = Ram00fd54;
    Ram00fd54 = uVar8 & 0xfeff | (uVar7 >> 5 & 1 | uVar2 >> 2 & 1 | uVar1 >> 3 & 1) << 8;
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xff7f;
    uVar1 = Ram00fd54;
    if ((uVar1 & 0x100) != 0) {
      iVar4 = Ram00f66c;
      uVar1 = iVar4 + 5;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      bVar5 = UNK_00d56f;
      bVar6 = UNK_00d56f;
      if (bVar3 == bVar6 || bVar3 < bVar5) {
        uVar1 = Ram00fd54;
        Ram00fd54 = uVar1 | 0x80;
        return;
      }
    }
  }
  else {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xff7f;
    iVar4 = Ram00f66c;
    uVar1 = iVar4 + 5;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar5 = UNK_00d56f;
    bVar6 = UNK_00d56f;
    if (bVar3 == bVar6 || bVar3 < bVar5) {
      uVar1 = Ram00fd54;
      Ram00fd54 = uVar1 | 0x80;
    }
  }
  return;
}


