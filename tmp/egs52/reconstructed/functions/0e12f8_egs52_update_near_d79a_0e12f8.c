/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e12f8; FLS offset 0x0612f8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e13d6) */
/* WARNING: Removing unreachable block (ram,0x0e13ce) */
/* WARNING: Removing unreachable block (ram,0x0e13c6) */
/* WARNING: Removing unreachable block (ram,0x0e13c2) */
/* WARNING: Removing unreachable block (ram,0x0e13b0) */
/* WARNING: Removing unreachable block (ram,0x0e13ac) */
/* WARNING: Removing unreachable block (ram,0x0e13a6) */
/* WARNING: Removing unreachable block (ram,0x0e13a2) */
/* WARNING: Removing unreachable block (ram,0x0e139e) */
/* WARNING: Removing unreachable block (ram,0x0e1396) */
/* WARNING: Removing unreachable block (ram,0x0e1390) */
/* WARNING: Removing unreachable block (ram,0x0e138c) */
/* WARNING: Removing unreachable block (ram,0x0e137c) */
/* WARNING: Removing unreachable block (ram,0x0e1378) */
/* WARNING: Removing unreachable block (ram,0x0e136e) */
/* WARNING: Removing unreachable block (ram,0x0e1366) */
/* WARNING: Removing unreachable block (ram,0x0e135c) */
/* WARNING: Removing unreachable block (ram,0x0e1352) */
/* WARNING: Removing unreachable block (ram,0x0e13e0) */
/* WARNING: Removing unreachable block (ram,0x0e134a) */
/* WARNING: Removing unreachable block (ram,0x0e1346) */
/* WARNING: Removing unreachable block (ram,0x0e1342) */
/* WARNING: Removing unreachable block (ram,0x0e133a) */
/* WARNING: Removing unreachable block (ram,0x0e1336) */
/* WARNING: Removing unreachable block (ram,0x0e132a) */
/* WARNING: Removing unreachable block (ram,0x0e1324) */
/* WARNING: Removing unreachable block (ram,0x0e1320) */
/* WARNING: Removing unreachable block (ram,0x0e131c) */
/* WARNING: Removing unreachable block (ram,0x0e1314) */
/* WARNING: Removing unreachable block (ram,0x0e130c) */
/* WARNING: Removing unreachable block (ram,0x0e1306) */
/* WARNING: Removing unreachable block (ram,0x0e1300) */
/* WARNING: Removing unreachable block (ram,0x0e12fc) */
/* WARNING: Removing unreachable block (ram,0x0e1330) */
/* WARNING: Removing unreachable block (ram,0x0e13dc) */
/* WARNING: Removing unreachable block (ram,0x0e1358) */

void egs52_update_near_d79a_0e12f8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short old;
  int iVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  short sVar10;
  uchar weight;
  
  iVar5 = Ram00f65a;
  uVar1 = iVar5 + 0x75;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = Ram00d52a;
  uVar4 = Ram00d79c;
  uVar9 = Ram00d79a;
  uVar9 = egs52_weighted_average_u16
                    (*(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                     (uVar2 >> 1) + (uVar4 >> 1),uVar9);
  Ram00d79a = uVar9;
  iVar5 = Ram00f65a;
  uVar1 = iVar5 + 0x77;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = Ram00d7cc;
  if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar2) {
    uVar1 = iVar5 + 0x74;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    weight = *(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  else {
    iVar5 = Ram00f65a;
    uVar1 = iVar5 + 0x73;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    weight = *(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar1 = Ram00fd58;
  if ((uVar1 & 4) == 0) {
    iVar5 = Ram00f65a;
    uVar1 = iVar5 + 0x6e;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = Ram00d7ce;
    if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar2) {
      iVar6 = Ram00d71e;
      iVar5 = Ram00d52a;
      iVar8 = Ram00d79c;
      sVar10 = Ram00d71e;
      sVar10 = egs52_weighted_average_s16(weight,(iVar5 - iVar8) * 5,sVar10);
      Ram00d71e = sVar10;
      iVar5 = Ram00f61e;
      uVar1 = iVar5 + 0x24;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar5 = Ram00f65a;
      uVar2 = iVar5 + 0x72;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      old = Ram00d70e;
      sVar10 = egs52_weighted_average_s16
                         (*(uchar *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),
                          (short)(((long)(sVar10 - iVar6) *
                                  (long)*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) /
                                 0x5dc),old);
      Ram00d70e = sVar10;
      iVar5 = Ram00f666;
      uVar1 = iVar5 + 0x22;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar5 = Ram00d71e;
      uVar7 = Ram00d79a;
      iVar6 = Ram00f65a;
      uVar2 = iVar6 + 0x4d;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      sVar10 = Ram00d70a;
      sVar10 = egs52_weighted_average_s16
                         (*(uchar *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),
                          (short)(((long)iVar5 * (long)(int)(uVar7 >> 1)) /
                                 (long)(int)(*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)
                                                      ) >> 1)),sVar10);
      Ram00d70a = sVar10;
      return;
    }
  }
  Ram00d71e = 0;
  Ram00d70a = 0;
  return;
}


