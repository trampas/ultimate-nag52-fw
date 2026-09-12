/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d92e2; FLS offset 0x0592e2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9422) */
/* WARNING: Removing unreachable block (ram,0x0d941e) */
/* WARNING: Removing unreachable block (ram,0x0d9414) */
/* WARNING: Removing unreachable block (ram,0x0d9412) */
/* WARNING: Removing unreachable block (ram,0x0d940e) */
/* WARNING: Removing unreachable block (ram,0x0d9404) */
/* WARNING: Removing unreachable block (ram,0x0d93ee) */
/* WARNING: Removing unreachable block (ram,0x0d93ea) */
/* WARNING: Removing unreachable block (ram,0x0d9400) */
/* WARNING: Removing unreachable block (ram,0x0d93fc) */
/* WARNING: Removing unreachable block (ram,0x0d93e4) */
/* WARNING: Removing unreachable block (ram,0x0d93dc) */
/* WARNING: Removing unreachable block (ram,0x0d93c4) */
/* WARNING: Removing unreachable block (ram,0x0d93b2) */
/* WARNING: Removing unreachable block (ram,0x0d93ae) */
/* WARNING: Removing unreachable block (ram,0x0d93aa) */
/* WARNING: Removing unreachable block (ram,0x0d93a6) */
/* WARNING: Removing unreachable block (ram,0x0d93a2) */
/* WARNING: Removing unreachable block (ram,0x0d939e) */
/* WARNING: Removing unreachable block (ram,0x0d939a) */
/* WARNING: Removing unreachable block (ram,0x0d9392) */
/* WARNING: Removing unreachable block (ram,0x0d9382) */
/* WARNING: Removing unreachable block (ram,0x0d936c) */
/* WARNING: Removing unreachable block (ram,0x0d9360) */
/* WARNING: Removing unreachable block (ram,0x0d934a) */
/* WARNING: Removing unreachable block (ram,0x0d9346) */
/* WARNING: Removing unreachable block (ram,0x0d9342) */
/* WARNING: Removing unreachable block (ram,0x0d932c) */
/* WARNING: Removing unreachable block (ram,0x0d933a) */
/* WARNING: Removing unreachable block (ram,0x0d9322) */
/* WARNING: Removing unreachable block (ram,0x0d9310) */
/* WARNING: Removing unreachable block (ram,0x0d931e) */
/* WARNING: Removing unreachable block (ram,0x0d9306) */
/* WARNING: Removing unreachable block (ram,0x0d92fc) */
/* WARNING: Removing unreachable block (ram,0x0d92ee) */
/* WARNING: Removing unreachable block (ram,0x0d92e6) */
/* WARNING: Removing unreachable block (ram,0x0d931a) */
/* WARNING: Removing unreachable block (ram,0x0d9314) */
/* WARNING: Removing unreachable block (ram,0x0d9336) */
/* WARNING: Removing unreachable block (ram,0x0d9330) */
/* WARNING: Removing unreachable block (ram,0x0d93f8) */
/* WARNING: Removing unreachable block (ram,0x0d93f2) */

int egs52_update_near_d540_0d92e2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  short sVar12;
  int iVar13;
  
  iVar13 = Ram00f63a;
  uVar6 = iVar13 + 0x39;
  uVar1 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0x80) == 0) ||
     (cVar11 = UNK_00d579, cVar11 != '\x01')) {
    iVar13 = 0;
  }
  else {
    uVar1 = 0x24;
    if (((uVar6 & 0xc000) != 0) &&
       ((uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)))) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) & 1) == 0) {
      uVar8 = Ram00d524;
      Ram00d540 = uVar8;
    }
    else {
      uVar8 = Ram00d522;
      Ram00d540 = uVar8;
    }
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) & 2) == 0) {
      uVar8 = Ram00d500;
      Ram00d53e = uVar8;
    }
    else {
      uVar8 = Ram00d4fa;
      Ram00d53e = uVar8;
    }
    uVar9 = Ram00d53e;
    iVar13 = Ram00f624;
    uVar1 = iVar13 + 10;
    uVar6 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar7 = iVar13 + 0x18;
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar10 = Ram00d540;
    uVar3 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d4ee = (int)(((ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) *
                       (((ulong)uVar9 *
                        (ulong)*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff))) / 1000 &
                       0xffff) + (ulong)uVar10 * -1000) /
                     (ulong)(*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) - 1000));
    iVar5 = Ram00d4f0;
    iVar13 = Ram00d4ee;
    Ram00d3ec = iVar5 - iVar13;
    uVar8 = Ram00d3f2;
    Ram00d3f0 = uVar8;
    iVar13 = Ram00f63a;
    uVar1 = iVar13 + 0x3a;
    uVar6 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    iVar5 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
    sVar12 = Ram00d3ec;
    sVar12 = egs52_pid_step((ushort *)0xd558,(short *)(iVar13 + 0x22),sVar12);
    iVar13 = (int)(((long)iVar5 * (long)sVar12) / 1000);
    Ram00d3f2 = iVar13;
    iVar5 = Ram00d3f0;
    if (iVar13 < iVar5) {
      iVar13 = Ram00f63a;
      uVar1 = iVar13 + 0x52;
      uVar6 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      iVar13 = Ram00d3f2;
      iVar13 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar13;
    }
    else {
      iVar13 = Ram00f63a;
      uVar1 = iVar13 + 0x50;
      uVar6 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      iVar13 = Ram00d3f2;
      iVar13 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar13;
    }
    iVar5 = Ram00f63a;
    uVar6 = iVar5 + 0x28;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    piVar4 = (int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
    if (iVar13 == *piVar4 || iVar13 < *piVar4) {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
    }
    iVar5 = Ram00f63a;
    uVar6 = iVar5 + 0x2a;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) <= iVar13) {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
    }
  }
  return iVar13;
}


