/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e03a8; FLS offset 0x0603a8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e04c2) */
/* WARNING: Removing unreachable block (ram,0x0e04ce) */
/* WARNING: Removing unreachable block (ram,0x0e0498) */
/* WARNING: Removing unreachable block (ram,0x0e0488) */
/* WARNING: Removing unreachable block (ram,0x0e0476) */
/* WARNING: Removing unreachable block (ram,0x0e0472) */
/* WARNING: Removing unreachable block (ram,0x0e041a) */
/* WARNING: Removing unreachable block (ram,0x0e0434) */
/* WARNING: Removing unreachable block (ram,0x0e042c) */
/* WARNING: Removing unreachable block (ram,0x0e0414) */
/* WARNING: Removing unreachable block (ram,0x0e0400) */
/* WARNING: Removing unreachable block (ram,0x0e03fa) */
/* WARNING: Removing unreachable block (ram,0x0e03f6) */
/* WARNING: Removing unreachable block (ram,0x0e03cc) */
/* WARNING: Removing unreachable block (ram,0x0e03c6) */
/* WARNING: Removing unreachable block (ram,0x0e03ba) */
/* WARNING: Removing unreachable block (ram,0x0e03ee) */
/* WARNING: Removing unreachable block (ram,0x0e03ea) */
/* WARNING: Removing unreachable block (ram,0x0e03e4) */
/* WARNING: Removing unreachable block (ram,0x0e03b2) */
/* WARNING: Removing unreachable block (ram,0x0e03e0) */
/* WARNING: Removing unreachable block (ram,0x0e03be) */
/* WARNING: Removing unreachable block (ram,0x0e0428) */
/* WARNING: Removing unreachable block (ram,0x0e0490) */
/* WARNING: Removing unreachable block (ram,0x0e04c8) */

void egs52_update_near_d77c_0e03a8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = Ram00fd54;
  if ((uVar7 & 0x40) == 0) {
    iVar4 = Ram00d7ac;
    if (iVar4 < 1) {
      iVar4 = Ram00f662;
      uVar7 = iVar4 + 0x72;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar7 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
    }
    else {
      iVar4 = Ram00f662;
      uVar7 = iVar4 + 0x72;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar8 = iVar4 + 1;
      uVar1 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar6 = UNK_00d7d0;
      uVar7 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) -
              (int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) * (ulong)bVar6)
                   / 100);
    }
  }
  else {
    iVar4 = Ram00f662;
    uVar7 = iVar4 + 0x70;
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
  }
  iVar4 = Ram00f662;
  uVar2 = iVar4 + 0x66;
  uVar8 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  uVar1 = iVar4 + 2;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar5 = Ram00d500;
  if ((uint)(((ulong)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff)) *
             (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100) < uVar5) {
    uVar2 = iVar4 + 0x67;
    uVar8 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    uVar7 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff)) * uVar7;
  }
  else {
    iVar4 = Ram00f662;
    uVar2 = iVar4 + 2;
    uVar8 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    uVar1 = Ram00d500;
    iVar4 = (int)(((ulong)uVar1 * 100) /
                 (ulong)*(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff)));
    uVar7 = (uint)(((ulong)uVar7 * (ulong)(10000 - iVar4 * iVar4)) / 100);
  }
  iVar4 = Ram00f662;
  uVar2 = iVar4 + 0x68;
  uVar8 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  uVar2 = (uint)(((ulong)uVar7 * (ulong)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff))) /
                100);
  iVar4 = Ram00d7ac;
  if (iVar4 < 0) {
    iVar4 = Ram00d7ac;
    uVar8 = -iVar4;
  }
  else {
    uVar8 = Ram00d7ac;
  }
  if (uVar2 < uVar8) {
    uVar7 = (uint)(((ulong)(uVar8 - uVar2) * 100) / (ulong)(uVar7 - uVar2));
    if (uVar7 < 0x65) {
      Ram00d77c = uVar7;
    }
    else {
      Ram00d77c = 100;
    }
  }
  else {
    Ram00d77c = 0;
  }
  return;
}


