/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d728e; FLS offset 0x05728e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d73d8) */
/* WARNING: Removing unreachable block (ram,0x0d73d2) */
/* WARNING: Removing unreachable block (ram,0x0d73cc) */
/* WARNING: Removing unreachable block (ram,0x0d73c6) */
/* WARNING: Removing unreachable block (ram,0x0d73c2) */
/* WARNING: Removing unreachable block (ram,0x0d73be) */
/* WARNING: Removing unreachable block (ram,0x0d73a0) */
/* WARNING: Removing unreachable block (ram,0x0d7398) */
/* WARNING: Removing unreachable block (ram,0x0d7390) */
/* WARNING: Removing unreachable block (ram,0x0d7386) */
/* WARNING: Removing unreachable block (ram,0x0d737e) */
/* WARNING: Removing unreachable block (ram,0x0d7376) */
/* WARNING: Removing unreachable block (ram,0x0d7372) */
/* WARNING: Removing unreachable block (ram,0x0d736a) */
/* WARNING: Removing unreachable block (ram,0x0d72e4) */
/* WARNING: Removing unreachable block (ram,0x0d72d4) */
/* WARNING: Removing unreachable block (ram,0x0d72d0) */
/* WARNING: Removing unreachable block (ram,0x0d7324) */
/* WARNING: Removing unreachable block (ram,0x0d732c) */
/* WARNING: Removing unreachable block (ram,0x0d731c) */
/* WARNING: Removing unreachable block (ram,0x0d7318) */
/* WARNING: Removing unreachable block (ram,0x0d7312) */
/* WARNING: Removing unreachable block (ram,0x0d72c0) */
/* WARNING: Removing unreachable block (ram,0x0d72be) */
/* WARNING: Removing unreachable block (ram,0x0d72ba) */
/* WARNING: Removing unreachable block (ram,0x0d72b6) */
/* WARNING: Removing unreachable block (ram,0x0d72b2) */
/* WARNING: Removing unreachable block (ram,0x0d72ac) */
/* WARNING: Removing unreachable block (ram,0x0d72a4) */
/* WARNING: Removing unreachable block (ram,0x0d72ca) */
/* WARNING: Removing unreachable block (ram,0x0d72dc) */
/* WARNING: Unknown calling convention */

uchar egs52_compute_d42e_byte(uchar mode)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  
  if ((mode == '\x05') || (mode == '\x06')) {
    uVar11 = 0;
  }
  else {
    iVar2 = Ram00f636;
    bVar1 = UNK_00d477;
    uVar8 = iVar2 + 0x23 + (uint)bVar1;
    iVar2 = Ram00f636;
    uVar11 = iVar2 + 0x22;
    uVar10 = 0x24;
    if (((uVar11 & 0xc000) != 0) &&
       ((uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000 && (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000))
       )) {
      uVar10 = 3;
    }
    cVar4 = UNK_00d430;
    uVar7 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    bVar1 = *(char *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) + cVar4 +
            *(char *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar11 = Ram00d490;
    if (uVar11 == 0) {
      iVar2 = Ram00f624;
      uVar11 = iVar2 + (uint)mode * 2 + 0xb0;
      uVar10 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      uVar11 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
      iVar2 = Ram00d41c;
      if (iVar2 < 0) {
        iVar2 = Ram00d41c;
        uVar10 = -iVar2;
      }
      else {
        uVar10 = Ram00d41c;
      }
      uVar8 = egs52_lookup_and_offset_d467(0);
      uVar10 = (uint)(((ulong)uVar10 * (ulong)(uVar8 & 0xff)) / (ulong)uVar11);
    }
    else {
      iVar2 = Ram00f624;
      uVar10 = iVar2 + (uint)mode * 2 + 0xb0;
      uVar8 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      uVar10 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
      iVar2 = Ram00d41c;
      if (iVar2 < 0) {
        iVar3 = Ram00d41c;
        uVar8 = -iVar3;
      }
      else {
        uVar8 = Ram00d41c;
      }
      uVar7 = egs52_lookup_and_offset_d467(iVar2);
      uVar10 = (uint)(((ulong)uVar8 * (ulong)(uVar7 & 0xff)) / (ulong)uVar11) / uVar10;
    }
    if (0xff < uVar10) {
      uVar10 = 0xff;
    }
    if ((byte)uVar10 < bVar1) {
      uVar11 = (uint)(byte)(bVar1 - (byte)uVar10);
    }
    else {
      uVar11 = 0;
    }
    cVar4 = UNK_00d60e;
    if (cVar4 == '\x03') {
      iVar2 = Ram00f61e;
      uVar10 = iVar2 + 0x1d;
      uVar8 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      if ((((*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff)) & 0x40) != 0) &&
          (cVar4 = UNK_00d7aa, cVar4 == '\x02')) && (cVar4 = UNK_00d577, cVar4 == '\x03')) {
        iVar2 = Ram00f63e;
        iVar3 = Ram00f63e;
        uVar9 = Ram00d524;
        uVar9 = egs52_curve_u16(2,(ushort *)(iVar2 + 0x160),(ushort *)(iVar3 + 0x164),uVar9);
        uVar11 = (uint)(((ulong)uVar9 * (ulong)uVar11) / 100);
      }
    }
    iVar2 = Ram00f634;
    uVar10 = iVar2 + 0x3c;
    uVar8 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    bVar1 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
    bVar5 = UNK_00d5cc;
    bVar6 = UNK_00d5cc;
    if (bVar1 != bVar6 && bVar5 <= bVar1) {
      bVar1 = UNK_00d430;
      bVar5 = UNK_00d430;
      if ((byte)uVar11 == bVar5 || (byte)uVar11 < bVar1) {
        bVar1 = UNK_00d430;
        uVar11 = (uint)bVar1;
      }
    }
  }
  Ram00d42e = uVar11 & 0xff;
  return (uchar)uVar11;
}


