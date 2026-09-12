/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d50d2; FLS offset 0x0550d2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d512a) */
/* WARNING: Removing unreachable block (ram,0x0d5126) */
/* WARNING: Removing unreachable block (ram,0x0d5122) */
/* WARNING: Removing unreachable block (ram,0x0d511c) */
/* WARNING: Removing unreachable block (ram,0x0d5118) */
/* WARNING: Removing unreachable block (ram,0x0d5112) */
/* WARNING: Removing unreachable block (ram,0x0d510e) */
/* WARNING: Removing unreachable block (ram,0x0d5108) */
/* WARNING: Removing unreachable block (ram,0x0d5104) */
/* WARNING: Removing unreachable block (ram,0x0d50fe) */
/* WARNING: Removing unreachable block (ram,0x0d50fa) */
/* WARNING: Removing unreachable block (ram,0x0d50ee) */
/* WARNING: Removing unreachable block (ram,0x0d50ea) */
/* WARNING: Removing unreachable block (ram,0x0d50e6) */
/* WARNING: Removing unreachable block (ram,0x0d50e0) */
/* WARNING: Removing unreachable block (ram,0x0d50dc) */
/* WARNING: Removing unreachable block (ram,0x0d50d8) */
/* WARNING: Removing unreachable block (ram,0x0d50f4) */

undefined1 egs52_update_near_d5f6_0d50d2(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  ushort uVar7;
  
  uVar1 = Ram00fd3a;
  if ((uVar1 & 8) != 0) {
    iVar3 = Ram00f648;
    uVar1 = iVar3 + 0x28;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d500;
    uVar4 = Ram00d500;
    if (uVar1 == uVar4 || uVar1 < uVar2) {
      iVar6 = Ram00f65a;
      uVar1 = iVar6 + 0xc;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar4 = Ram00d504;
      if (uVar4 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        uVar1 = iVar3 + 0x2b;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        return *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
    }
  }
  iVar3 = Ram00f648;
  uVar1 = iVar3 + 5;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x1f;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x20;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fc = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar5 = UNK_00d5cc;
  Ram00d5fe = (uint)bVar5;
  uVar7 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  return (char)uVar7;
}


