/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7666; FLS offset 0x057666.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d77be) */
/* WARNING: Removing unreachable block (ram,0x0d77ba) */
/* WARNING: Removing unreachable block (ram,0x0d77b4) */
/* WARNING: Removing unreachable block (ram,0x0d77b0) */
/* WARNING: Removing unreachable block (ram,0x0d77a8) */
/* WARNING: Removing unreachable block (ram,0x0d779c) */
/* WARNING: Removing unreachable block (ram,0x0d7796) */
/* WARNING: Removing unreachable block (ram,0x0d7792) */
/* WARNING: Removing unreachable block (ram,0x0d7786) */
/* WARNING: Removing unreachable block (ram,0x0d777e) */
/* WARNING: Removing unreachable block (ram,0x0d7774) */
/* WARNING: Removing unreachable block (ram,0x0d776c) */
/* WARNING: Removing unreachable block (ram,0x0d7708) */
/* WARNING: Removing unreachable block (ram,0x0d76fc) */
/* WARNING: Removing unreachable block (ram,0x0d76f6) */
/* WARNING: Removing unreachable block (ram,0x0d76de) */
/* WARNING: Removing unreachable block (ram,0x0d76d2) */
/* WARNING: Removing unreachable block (ram,0x0d76c8) */
/* WARNING: Removing unreachable block (ram,0x0d76bc) */
/* WARNING: Removing unreachable block (ram,0x0d76a0) */
/* WARNING: Removing unreachable block (ram,0x0d7768) */
/* WARNING: Removing unreachable block (ram,0x0d7750) */
/* WARNING: Removing unreachable block (ram,0x0d7748) */
/* WARNING: Removing unreachable block (ram,0x0d7740) */
/* WARNING: Removing unreachable block (ram,0x0d7736) */
/* WARNING: Removing unreachable block (ram,0x0d7726) */
/* WARNING: Removing unreachable block (ram,0x0d7690) */
/* WARNING: Removing unreachable block (ram,0x0d767e) */
/* WARNING: Removing unreachable block (ram,0x0d766a) */
/* WARNING: Removing unreachable block (ram,0x0d771a) */
/* WARNING: Removing unreachable block (ram,0x0d76a8) */

void egs52_update_near_d490_0d7666(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  uchar x;
  uchar y;
  
  uVar1 = Ram00d500;
  uVar2 = Ram00d4d2;
  cVar5 = UNK_00d577;
  x = (uchar)(uVar1 / 0x1e);
  y = (uchar)(uVar2 / 5);
  if (cVar5 == '\x03') {
    iVar7 = Ram00f63e;
    bVar11 = UNK_00d579;
    bVar10 = UNK_00d579;
    iVar8 = Ram00f63e;
    bVar6 = UNK_00d579;
    iVar9 = Ram00f63e;
    bVar10 = egs52_map_u8('\x06','\n',(uchar *)(iVar8 + (uint)bVar10 * 6 + 0x12),
                          (uchar *)(iVar9 + (uint)bVar6 * 10 + 0x16),
                          (uchar *)(iVar7 + -0xbc + (uint)bVar11 * 0x3c),x,y);
    Ram00d490 = (uint)bVar10 * 5;
    bVar11 = UNK_00d442;
    Ram00d490 = (int)(((ulong)bVar11 * (ulong)((uint)bVar10 * 5)) / 10);
  }
  else {
    bVar11 = UNK_00d579;
    iVar7 = Ram00f63e;
    bVar10 = UNK_00d579;
    iVar8 = Ram00f63e;
    bVar6 = UNK_00d579;
    iVar9 = Ram00f63e;
    bVar11 = egs52_map_u8('\x03','\x02',(uchar *)(iVar8 + (uint)bVar10 * 3 + 1),
                          (uchar *)(iVar9 + (uint)bVar6 * 2 + 0xe),
                          (uchar *)(iVar7 + (uint)bVar11 * 6 + 0x12),x,y);
    Ram00d490 = (uint)bVar11 * 5;
  }
  uVar1 = Ram00fd4c;
  if (((uVar1 & 0x40) != 0) || (uVar1 = Ram00fd4a, (uVar1 & 2) != 0)) {
    uVar1 = Ram00fd4c;
    Ram00fd4c = uVar1 | 0x40;
    cVar5 = UNK_00d579;
    if ((cVar5 == '\a') && (cVar5 = UNK_00d777, cVar5 == '\x02')) {
      iVar7 = Ram00f630;
      uVar1 = iVar7 + 0x21;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = Ram00d490;
      Ram00d490 = (int)(((ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                        (ulong)uVar3) / 100);
    }
  }
  uVar1 = Ram00d490;
  uVar2 = Ram00d4d2;
  if (uVar2 <= uVar1) {
    uVar4 = Ram00d4d2;
    Ram00d490 = uVar4;
  }
  return;
}


