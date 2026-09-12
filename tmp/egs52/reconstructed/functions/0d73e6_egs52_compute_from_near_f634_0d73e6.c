/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d73e6; FLS offset 0x0573e6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7488) */
/* WARNING: Removing unreachable block (ram,0x0d7484) */
/* WARNING: Removing unreachable block (ram,0x0d747c) */
/* WARNING: Removing unreachable block (ram,0x0d7472) */
/* WARNING: Removing unreachable block (ram,0x0d749c) */
/* WARNING: Removing unreachable block (ram,0x0d746c) */
/* WARNING: Removing unreachable block (ram,0x0d7466) */
/* WARNING: Removing unreachable block (ram,0x0d745e) */
/* WARNING: Removing unreachable block (ram,0x0d743e) */
/* WARNING: Removing unreachable block (ram,0x0d7436) */
/* WARNING: Removing unreachable block (ram,0x0d742e) */
/* WARNING: Removing unreachable block (ram,0x0d7424) */
/* WARNING: Removing unreachable block (ram,0x0d741a) */
/* WARNING: Removing unreachable block (ram,0x0d7412) */
/* WARNING: Removing unreachable block (ram,0x0d740e) */
/* WARNING: Removing unreachable block (ram,0x0d7404) */
/* WARNING: Removing unreachable block (ram,0x0d7402) */
/* WARNING: Removing unreachable block (ram,0x0d73fe) */
/* WARNING: Removing unreachable block (ram,0x0d7462) */
/* WARNING: Removing unreachable block (ram,0x0d7498) */
/* WARNING: Removing unreachable block (ram,0x0d7476) */

byte egs52_compute_from_near_f634_0d73e6(char param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  byte bVar7;
  uint uVar8;
  
  if ((((param_1 == '\x05') || (param_1 == '\x06')) || (param_1 == '\a')) || (param_1 == '\b')) {
    uVar2 = Ram00f634;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar7 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    cVar3 = UNK_00d60e;
    if (cVar3 == '\x03') {
      iVar4 = Ram00f61e;
      uVar1 = iVar4 + 0x1d;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) &&
          (cVar3 = UNK_00d7aa, cVar3 == '\x02')) && (cVar3 = UNK_00d577, cVar3 == '\x03')) {
        iVar4 = Ram00f63e;
        iVar5 = Ram00f63e;
        uVar6 = Ram00d524;
        uVar6 = egs52_curve_u16(2,(ushort *)(iVar4 + 0x160),(ushort *)(iVar5 + 0x164),uVar6);
        bVar7 = (byte)(((ulong)uVar6 * (ulong)bVar7) / 100);
      }
    }
  }
  else {
    iVar4 = Ram00f636;
    uVar1 = iVar4 + 0x22;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar3 = UNK_00d430;
    bVar7 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + cVar3;
    uVar1 = Ram00d42e;
    uVar2 = Ram00d42e;
    if (bVar7 == uVar2 || bVar7 < uVar1) {
      uVar2 = Ram00f634;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar7 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
    else {
      uVar2 = Ram00f634;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar4 = Ram00d42e;
      uVar8 = (uint)bVar7 - iVar4;
      if (uVar8 < *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) {
        uVar2 = Ram00f634;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar8 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      bVar7 = (byte)uVar8;
    }
  }
  return bVar7;
}


