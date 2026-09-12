/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7010; FLS offset 0x057010.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d70f2) */
/* WARNING: Removing unreachable block (ram,0x0d70d6) */
/* WARNING: Removing unreachable block (ram,0x0d70c0) */
/* WARNING: Removing unreachable block (ram,0x0d70b8) */
/* WARNING: Removing unreachable block (ram,0x0d70b0) */
/* WARNING: Removing unreachable block (ram,0x0d70ac) */
/* WARNING: Removing unreachable block (ram,0x0d709a) */
/* WARNING: Removing unreachable block (ram,0x0d7096) */
/* WARNING: Removing unreachable block (ram,0x0d7092) */
/* WARNING: Removing unreachable block (ram,0x0d708e) */
/* WARNING: Removing unreachable block (ram,0x0d708a) */
/* WARNING: Removing unreachable block (ram,0x0d7086) */
/* WARNING: Removing unreachable block (ram,0x0d7082) */
/* WARNING: Removing unreachable block (ram,0x0d707c) */
/* WARNING: Removing unreachable block (ram,0x0d7078) */
/* WARNING: Removing unreachable block (ram,0x0d7072) */
/* WARNING: Removing unreachable block (ram,0x0d706e) */
/* WARNING: Removing unreachable block (ram,0x0d7060) */
/* WARNING: Removing unreachable block (ram,0x0d705c) */
/* WARNING: Removing unreachable block (ram,0x0d7058) */
/* WARNING: Removing unreachable block (ram,0x0d7054) */
/* WARNING: Removing unreachable block (ram,0x0d7050) */
/* WARNING: Removing unreachable block (ram,0x0d704c) */
/* WARNING: Removing unreachable block (ram,0x0d7048) */
/* WARNING: Removing unreachable block (ram,0x0d7044) */
/* WARNING: Removing unreachable block (ram,0x0d703e) */
/* WARNING: Removing unreachable block (ram,0x0d703a) */
/* WARNING: Removing unreachable block (ram,0x0d7034) */
/* WARNING: Removing unreachable block (ram,0x0d7030) */
/* WARNING: Removing unreachable block (ram,0x0d7028) */
/* WARNING: Removing unreachable block (ram,0x0d7024) */
/* WARNING: Removing unreachable block (ram,0x0d701e) */
/* WARNING: Removing unreachable block (ram,0x0d701a) */
/* WARNING: Removing unreachable block (ram,0x0d7016) */
/* WARNING: Removing unreachable block (ram,0x0d7012) */
/* WARNING: Removing unreachable block (ram,0x0d70d2) */
/* WARNING: Removing unreachable block (ram,0x0d70f6) */

byte egs52_update_near_d5f6_0d7010(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  byte bVar9;
  
  uVar1 = Ram00f63a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = uVar1 + 1;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  cVar4 = UNK_00d579;
  if (cVar4 == '\x01') {
    iVar6 = Ram00f634;
    uVar1 = iVar6 + 0x46;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar5 = Ram00d5f6;
    Ram00d5f6 = iVar5 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = iVar6 + 0x47;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar6 = Ram00d5f8;
    Ram00d5f8 = iVar6 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar6 = Ram00f63a;
  uVar1 = iVar6 + 0x1a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0x1c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fc = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar3 = Ram00d4d2;
  Ram00d5fe = uVar3;
  uVar7 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  iVar6 = Ram00f63a;
  uVar1 = iVar6 + 0x54;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0x55;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0x56;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0x58;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fc = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar3 = Ram00d524;
  Ram00d5fe = uVar3;
  uVar8 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  bVar9 = (char)uVar7 + (char)uVar8;
  uVar1 = Ram00fd4c;
  if ((uVar1 & 0x20) == 0) {
    iVar6 = Ram00f61e;
    uVar1 = iVar6 + 0x1d;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) &&
       (cVar4 = UNK_00d60e, cVar4 == '\x03')) {
      cVar4 = UNK_00d7aa;
      if (cVar4 == '\0') {
        iVar6 = Ram00f63a;
        uVar1 = iVar6 + 0x5a;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar9 = (byte)(((ulong)(uint)bVar9 *
                       (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
      }
      else if (cVar4 == '\x02') {
        iVar6 = Ram00f63a;
        uVar1 = iVar6 + 0x5b;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar9 = (byte)(((ulong)(uint)bVar9 *
                       (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
      }
    }
  }
  return bVar9;
}


