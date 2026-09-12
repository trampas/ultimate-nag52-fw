/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e120a; FLS offset 0x06120a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e12ee) */
/* WARNING: Removing unreachable block (ram,0x0e12e2) */
/* WARNING: Removing unreachable block (ram,0x0e12de) */
/* WARNING: Removing unreachable block (ram,0x0e12c0) */
/* WARNING: Removing unreachable block (ram,0x0e12d6) */
/* WARNING: Removing unreachable block (ram,0x0e12d2) */
/* WARNING: Removing unreachable block (ram,0x0e12cc) */
/* WARNING: Removing unreachable block (ram,0x0e12ba) */
/* WARNING: Removing unreachable block (ram,0x0e12b6) */
/* WARNING: Removing unreachable block (ram,0x0e12ae) */
/* WARNING: Removing unreachable block (ram,0x0e12a4) */
/* WARNING: Removing unreachable block (ram,0x0e1294) */
/* WARNING: Removing unreachable block (ram,0x0e128c) */
/* WARNING: Removing unreachable block (ram,0x0e1284) */
/* WARNING: Removing unreachable block (ram,0x0e126a) */
/* WARNING: Removing unreachable block (ram,0x0e127e) */
/* WARNING: Removing unreachable block (ram,0x0e1278) */
/* WARNING: Removing unreachable block (ram,0x0e1254) */
/* WARNING: Removing unreachable block (ram,0x0e1250) */
/* WARNING: Removing unreachable block (ram,0x0e1248) */
/* WARNING: Removing unreachable block (ram,0x0e1244) */
/* WARNING: Removing unreachable block (ram,0x0e1238) */
/* WARNING: Removing unreachable block (ram,0x0e1230) */
/* WARNING: Removing unreachable block (ram,0x0e1226) */
/* WARNING: Removing unreachable block (ram,0x0e1222) */
/* WARNING: Removing unreachable block (ram,0x0e121e) */
/* WARNING: Removing unreachable block (ram,0x0e120e) */
/* WARNING: Removing unreachable block (ram,0x0e1216) */
/* WARNING: Removing unreachable block (ram,0x0e1240) */
/* WARNING: Removing unreachable block (ram,0x0e1262) */
/* WARNING: Removing unreachable block (ram,0x0e1270) */
/* WARNING: Removing unreachable block (ram,0x0e129c) */
/* WARNING: Removing unreachable block (ram,0x0e12ca) */
/* WARNING: Removing unreachable block (ram,0x0e12c4) */

void egs52_update_near_d74e_0e120a(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  
  iVar3 = Ram00d70e;
  if (iVar3 < 0) {
    iVar3 = Ram00d70e;
    uVar7 = -iVar3;
  }
  else {
    uVar7 = Ram00d70e;
  }
  iVar3 = Ram00f65a;
  uVar1 = iVar3 + 0x53;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (uVar7 < *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
    iVar3 = Ram00d750;
    if (iVar3 < 0) {
      iVar3 = Ram00d750;
      uVar7 = -iVar3;
    }
    else {
      uVar7 = Ram00d750;
    }
    iVar3 = Ram00f65a;
    uVar1 = iVar3 + 0x6c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (uVar7 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      uVar7 = iVar3 + 0x6e;
      uVar1 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = Ram00d7ce;
      if (((*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff)) < uVar2) &&
          (uVar7 = Ram00fd54, (uVar7 & 0x20) == 0)) && (uVar7 = Ram00fd58, (uVar7 & 4) == 0)) {
        iVar3 = Ram00d71e;
        if (iVar3 < 1) {
          iVar3 = Ram00d71e;
          if (iVar3 < 0) {
            iVar3 = Ram00d74e;
            Ram00d74e = iVar3 + 1;
          }
        }
        else {
          iVar3 = Ram00d74e;
          Ram00d74e = iVar3 + -1;
        }
        goto LAB_0e1282;
      }
    }
  }
  Ram00d74e = 0;
LAB_0e1282:
  iVar4 = Ram00f65c;
  iVar5 = Ram00f65c;
  iVar3 = Ram00d71e;
  if (iVar3 < 0) {
    iVar3 = Ram00d71e;
    uVar6 = -iVar3;
  }
  else {
    uVar6 = Ram00d71e;
  }
  uVar6 = egs52_curve_u16(2,(ushort *)(iVar4 + 0x7c),(ushort *)(iVar5 + 0x80),uVar6);
  iVar3 = Ram00f65a;
  uVar1 = iVar3 + 0x70;
  uVar7 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar7 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar7 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar7 = 3;
  }
  iVar3 = Ram00d74e;
  if (-*(int *)((uint3)uVar7 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar3) {
    uVar7 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar7 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar3 = *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar4 = Ram00d74e;
    iVar5 = Ram00d74e;
    if (iVar3 == iVar5 || iVar3 < iVar4) {
      iVar3 = Ram00d74c;
      Ram00d74c = iVar3 - uVar6;
      Ram00d74e = 0;
    }
  }
  else {
    iVar3 = Ram00d74c;
    Ram00d74c = iVar3 + uVar6;
    Ram00d74e = 0;
  }
  uVar7 = Ram00d52c;
  uVar1 = Ram00d74c;
  Ram00d79c = (int)(((ulong)uVar7 * (ulong)uVar1) / 10000);
  return;
}


