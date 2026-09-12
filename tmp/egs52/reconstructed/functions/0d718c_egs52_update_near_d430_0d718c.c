/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d718c; FLS offset 0x05718c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7280) */
/* WARNING: Removing unreachable block (ram,0x0d727c) */
/* WARNING: Removing unreachable block (ram,0x0d7274) */
/* WARNING: Removing unreachable block (ram,0x0d71d8) */
/* WARNING: Removing unreachable block (ram,0x0d7270) */
/* WARNING: Removing unreachable block (ram,0x0d7260) */
/* WARNING: Removing unreachable block (ram,0x0d725c) */
/* WARNING: Removing unreachable block (ram,0x0d7258) */
/* WARNING: Removing unreachable block (ram,0x0d7254) */
/* WARNING: Removing unreachable block (ram,0x0d724c) */
/* WARNING: Removing unreachable block (ram,0x0d7248) */
/* WARNING: Removing unreachable block (ram,0x0d723c) */
/* WARNING: Removing unreachable block (ram,0x0d7238) */
/* WARNING: Removing unreachable block (ram,0x0d7232) */
/* WARNING: Removing unreachable block (ram,0x0d722e) */
/* WARNING: Removing unreachable block (ram,0x0d7228) */
/* WARNING: Removing unreachable block (ram,0x0d7218) */
/* WARNING: Removing unreachable block (ram,0x0d720a) */
/* WARNING: Removing unreachable block (ram,0x0d71fe) */
/* WARNING: Removing unreachable block (ram,0x0d71fc) */
/* WARNING: Removing unreachable block (ram,0x0d71f4) */
/* WARNING: Removing unreachable block (ram,0x0d71c6) */
/* WARNING: Removing unreachable block (ram,0x0d71c2) */
/* WARNING: Removing unreachable block (ram,0x0d71be) */
/* WARNING: Removing unreachable block (ram,0x0d71b2) */
/* WARNING: Removing unreachable block (ram,0x0d71ae) */
/* WARNING: Removing unreachable block (ram,0x0d71a0) */
/* WARNING: Removing unreachable block (ram,0x0d719a) */
/* WARNING: Removing unreachable block (ram,0x0d7194) */
/* WARNING: Removing unreachable block (ram,0x0d71ce) */
/* WARNING: Removing unreachable block (ram,0x0d71e4) */
/* WARNING: Removing unreachable block (ram,0x0d71e8) */
/* WARNING: Removing unreachable block (ram,0x0d71ec) */
/* WARNING: Removing unreachable block (ram,0x0d71dc) */

undefined1 egs52_update_near_d430_0d718c(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  undefined1 uVar7;
  uchar x;
  uchar *xs;
  int iVar8;
  char cVar9;
  uchar uVar10;
  ushort uVar11;
  byte bVar12;
  
  uVar10 = UNK_00d5cc;
  x = UNK_00d477;
  iVar5 = Ram00f63c;
  xs = (uchar *)Ram00f63c;
  iVar8 = Ram00f63c;
  uVar10 = egs52_map_u8('\x05','\x04',xs,(uchar *)(iVar8 + 5),(uchar *)(iVar5 + 9),x,uVar10);
  UNK_00d430 = uVar10;
  iVar5 = Ram00f632;
  uVar2 = iVar5 + 0x10;
  uVar3 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) & 2) == 0) {
    cVar6 = UNK_00d579;
    if (cVar6 == '\b') {
      cVar6 = UNK_00d356;
      cVar9 = UNK_00d430;
      UNK_00d430 = cVar9 + cVar6;
    }
    else {
      bVar12 = UNK_00d477;
      uVar2 = bVar12 + 0xd351;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      cVar6 = UNK_00d430;
      UNK_00d430 = cVar6 + *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
  }
  else {
    iVar5 = Ram00f632;
    uVar3 = iVar5 + 0x12;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar12 = UNK_00d5cc;
    bVar1 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) < bVar12;
    cVar6 = UNK_00d579;
    if (cVar6 == '\b') {
      bVar12 = 5;
    }
    else {
      bVar12 = UNK_00d477;
    }
    iVar5 = (uint)bVar12 + (uint)bVar1 * 9;
    uVar2 = iVar5 + 0xd351;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d600 = (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar2 = iVar5 + 0xd35a;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d602 = (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
    iVar5 = Ram00f632;
    uVar4 = iVar5 + 0x11 + (uint)bVar1;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d604 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
    uVar3 = uVar3 + bVar1;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d606 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
    bVar12 = UNK_00d5cc;
    Ram00d608 = (uint)bVar12;
    uVar11 = egs52_lerp_signed_axis((ushort *)0xd600);
    cVar6 = UNK_00d430;
    UNK_00d430 = cVar6 + (char)uVar11;
  }
  cVar6 = UNK_00d430;
  if (cVar6 < '\0') {
    UNK_00d430 = 0;
  }
  uVar7 = UNK_00d430;
  return uVar7;
}


