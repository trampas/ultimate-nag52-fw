/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e13ea; FLS offset 0x0613ea.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e1490) */
/* WARNING: Removing unreachable block (ram,0x0e147c) */
/* WARNING: Removing unreachable block (ram,0x0e1478) */
/* WARNING: Removing unreachable block (ram,0x0e1474) */
/* WARNING: Removing unreachable block (ram,0x0e1468) */
/* WARNING: Removing unreachable block (ram,0x0e1460) */
/* WARNING: Removing unreachable block (ram,0x0e1454) */
/* WARNING: Removing unreachable block (ram,0x0e144c) */
/* WARNING: Removing unreachable block (ram,0x0e1446) */
/* WARNING: Removing unreachable block (ram,0x0e1440) */
/* WARNING: Removing unreachable block (ram,0x0e143c) */
/* WARNING: Removing unreachable block (ram,0x0e1436) */
/* WARNING: Removing unreachable block (ram,0x0e1432) */
/* WARNING: Removing unreachable block (ram,0x0e142e) */
/* WARNING: Removing unreachable block (ram,0x0e1426) */
/* WARNING: Removing unreachable block (ram,0x0e141c) */
/* WARNING: Removing unreachable block (ram,0x0e1416) */
/* WARNING: Removing unreachable block (ram,0x0e1412) */
/* WARNING: Removing unreachable block (ram,0x0e140e) */
/* WARNING: Removing unreachable block (ram,0x0e1408) */
/* WARNING: Removing unreachable block (ram,0x0e1402) */
/* WARNING: Removing unreachable block (ram,0x0e13fe) */
/* WARNING: Removing unreachable block (ram,0x0e13f8) */
/* WARNING: Removing unreachable block (ram,0x0e13f2) */
/* WARNING: Removing unreachable block (ram,0x0e13ee) */
/* WARNING: Removing unreachable block (ram,0x0e13ea) */
/* WARNING: Removing unreachable block (ram,0x0e149a) */
/* WARNING: Removing unreachable block (ram,0x0e146e) */

void egs52_update_near_d7ba_0e13ea(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  
  iVar7 = Ram00f666;
  uVar1 = iVar7 + 0x32;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar5 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar11 = Ram00d7a6;
  iVar12 = Ram00d7a6;
  if ((iVar5 != iVar12 && iVar11 <= iVar5) && (iVar5 = Ram00d7ba, iVar5 == 0)) {
    uVar1 = iVar7 + 0x36;
    uVar3 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar3 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar3 = Ram00d508;
    uVar2 = Ram00d508;
    if ((uVar1 != uVar2 && uVar3 <= uVar1) && (cVar8 = UNK_00d577, cVar8 == '\0')) {
      uVar1 = iVar7 + 0x34;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      Ram00d7ba = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
  iVar7 = Ram00f65a;
  uVar3 = iVar7 + 4;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 2) != 0) {
    iVar7 = Ram00d7ba;
    if (iVar7 != 0) goto LAB_0e1468;
    iVar7 = Ram00f666;
    uVar1 = iVar7 + 0x31;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar6 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar9 = UNK_00d570;
    bVar10 = UNK_00d570;
    if (bVar6 != bVar10 && bVar9 <= bVar6) {
      uVar1 = iVar7 + 0x38;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar7 = Ram00d4ce;
      if ((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar7) &&
         (cVar8 = UNK_00d577, cVar8 == '\0')) goto LAB_0e1468;
    }
  }
  cVar8 = UNK_00d474;
  if (cVar8 == '\x01') {
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 8) != 0) &&
       (uVar1 = Ram00fd46, (uVar1 & 8) != 0)) {
LAB_0e1468:
      bVar6 = UNK_00d454;
      iVar7 = Ram00f624;
      uVar1 = iVar7 + (uint)bVar6 * 2 + 6;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      iVar7 = Ram00f65e;
      uVar2 = iVar7 + 4;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      Ram00d72e = (int)(((ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) * 1000) /
                       (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
      return;
    }
  }
  Ram00d72e = 0;
  return;
}


