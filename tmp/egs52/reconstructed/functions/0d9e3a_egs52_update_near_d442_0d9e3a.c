/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9e3a; FLS offset 0x059e3a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9efc) */
/* WARNING: Removing unreachable block (ram,0x0d9ec0) */
/* WARNING: Removing unreachable block (ram,0x0d9e9e) */
/* WARNING: Removing unreachable block (ram,0x0d9e94) */
/* WARNING: Removing unreachable block (ram,0x0d9e8e) */
/* WARNING: Removing unreachable block (ram,0x0d9e8a) */
/* WARNING: Removing unreachable block (ram,0x0d9e86) */
/* WARNING: Removing unreachable block (ram,0x0d9e5a) */
/* WARNING: Removing unreachable block (ram,0x0d9e56) */
/* WARNING: Removing unreachable block (ram,0x0d9e74) */
/* WARNING: Removing unreachable block (ram,0x0d9e70) */
/* WARNING: Removing unreachable block (ram,0x0d9e6c) */
/* WARNING: Removing unreachable block (ram,0x0d9e82) */
/* WARNING: Removing unreachable block (ram,0x0d9e7e) */
/* WARNING: Removing unreachable block (ram,0x0d9e7a) */
/* WARNING: Removing unreachable block (ram,0x0d9e4e) */
/* WARNING: Removing unreachable block (ram,0x0d9e4a) */
/* WARNING: Removing unreachable block (ram,0x0d9e46) */
/* WARNING: Removing unreachable block (ram,0x0d9e42) */
/* WARNING: Removing unreachable block (ram,0x0d9e64) */
/* WARNING: Removing unreachable block (ram,0x0d9e5e) */
/* WARNING: Removing unreachable block (ram,0x0d9f02) */
/* WARNING: Removing unreachable block (ram,0x0d9ece) */

void egs52_update_near_d442_0d9e3a(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  
  egs52_update_near_d579_0d6c96();
  iVar1 = Ram00f634;
  uVar10 = iVar1 + 3;
  uVar8 = 0x24;
  if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  UNK_00d442 = *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
  cVar2 = UNK_00d454;
  if (cVar2 == '\x01') {
    iVar1 = Ram00f630;
    uVar10 = iVar1 + 0x11;
    uVar8 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
  }
  else {
    cVar2 = UNK_00d454;
    if (cVar2 == '\x03') {
      iVar1 = Ram00f630;
      uVar10 = iVar1 + 0x1d;
      uVar8 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
    }
    else {
      iVar1 = Ram00f630;
      uVar10 = iVar1 + 0x1c;
      uVar8 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff));
    }
  }
  iVar4 = Ram00d556;
  iVar1 = Ram00d536;
  uVar10 = iVar4 + iVar1;
  uVar8 = Ram00d54a;
  uVar3 = Ram00d54a;
  if (uVar10 == uVar3 || uVar10 < uVar8) {
    uVar10 = 0;
  }
  else {
    iVar1 = Ram00d54a;
    uVar10 = uVar10 - iVar1;
  }
  uVar5 = UNK_00d577;
  uVar8 = egs52_compute_from_near_d579_0d42a6(uVar5);
  if (uVar8 == 0) {
    UNK_00d590 = 0xff;
  }
  else {
    uVar9 = egs52_sqrt_estimate_u16((ushort)(((ulong)uVar10 * 10000) / (ulong)uVar8));
    bVar6 = UNK_00d590;
    bVar7 = UNK_00d5b0;
    uVar10 = (bVar6 * uVar9 + ((uVar9 + 100) * (uint)bVar7 >> 1)) / 100;
    if (0xff < uVar10) {
      uVar10 = 0xff;
    }
    UNK_00d590 = (char)uVar10;
  }
  return;
}


