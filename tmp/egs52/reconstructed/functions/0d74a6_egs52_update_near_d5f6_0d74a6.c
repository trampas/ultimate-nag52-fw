/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d74a6; FLS offset 0x0574a6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d74fe) */
/* WARNING: Removing unreachable block (ram,0x0d74fa) */
/* WARNING: Removing unreachable block (ram,0x0d74f6) */
/* WARNING: Removing unreachable block (ram,0x0d74ee) */
/* WARNING: Removing unreachable block (ram,0x0d74e6) */
/* WARNING: Removing unreachable block (ram,0x0d74e2) */
/* WARNING: Removing unreachable block (ram,0x0d74d6) */
/* WARNING: Removing unreachable block (ram,0x0d74d2) */
/* WARNING: Removing unreachable block (ram,0x0d74ce) */
/* WARNING: Removing unreachable block (ram,0x0d74c8) */
/* WARNING: Removing unreachable block (ram,0x0d74c4) */
/* WARNING: Removing unreachable block (ram,0x0d74be) */
/* WARNING: Removing unreachable block (ram,0x0d74ba) */
/* WARNING: Removing unreachable block (ram,0x0d74b4) */
/* WARNING: Removing unreachable block (ram,0x0d74b0) */
/* WARNING: Removing unreachable block (ram,0x0d74aa) */
/* WARNING: Removing unreachable block (ram,0x0d74a6) */

void egs52_update_near_d5f6_0d74a6(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  
  iVar3 = Ram00f63a;
  uVar1 = iVar3 + 0x49;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x4a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x4d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x4e;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fc = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar5 = UNK_00d5cc;
  Ram00d5fe = (uint)bVar5;
  uVar6 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  UNK_00d4e1 = (char)uVar6;
  cVar4 = UNK_00d577;
  if ((cVar4 != '\x01') || (cVar4 = UNK_00d579, cVar4 != '\x01')) {
    iVar3 = Ram00f63a;
    uVar1 = iVar3 + 0x4a;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    UNK_00d4e1 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  return;
}


