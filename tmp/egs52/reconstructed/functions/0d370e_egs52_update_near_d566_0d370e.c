/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d370e; FLS offset 0x05370e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d3784) */
/* WARNING: Removing unreachable block (ram,0x0d377c) */
/* WARNING: Removing unreachable block (ram,0x0d3856) */
/* WARNING: Removing unreachable block (ram,0x0d3850) */
/* WARNING: Removing unreachable block (ram,0x0d3846) */
/* WARNING: Removing unreachable block (ram,0x0d383e) */
/* WARNING: Removing unreachable block (ram,0x0d3836) */
/* WARNING: Removing unreachable block (ram,0x0d3832) */
/* WARNING: Removing unreachable block (ram,0x0d3824) */
/* WARNING: Removing unreachable block (ram,0x0d3820) */
/* WARNING: Removing unreachable block (ram,0x0d3816) */
/* WARNING: Removing unreachable block (ram,0x0d3806) */
/* WARNING: Removing unreachable block (ram,0x0d3802) */
/* WARNING: Removing unreachable block (ram,0x0d37fe) */
/* WARNING: Removing unreachable block (ram,0x0d37fa) */
/* WARNING: Removing unreachable block (ram,0x0d37f2) */
/* WARNING: Removing unreachable block (ram,0x0d37ee) */
/* WARNING: Removing unreachable block (ram,0x0d37e6) */
/* WARNING: Removing unreachable block (ram,0x0d37e2) */
/* WARNING: Removing unreachable block (ram,0x0d37de) */
/* WARNING: Removing unreachable block (ram,0x0d37d8) */
/* WARNING: Removing unreachable block (ram,0x0d37d4) */
/* WARNING: Removing unreachable block (ram,0x0d37ca) */
/* WARNING: Removing unreachable block (ram,0x0d37ba) */
/* WARNING: Removing unreachable block (ram,0x0d37b4) */
/* WARNING: Removing unreachable block (ram,0x0d37b0) */
/* WARNING: Removing unreachable block (ram,0x0d37ac) */
/* WARNING: Removing unreachable block (ram,0x0d37a6) */
/* WARNING: Removing unreachable block (ram,0x0d37a0) */
/* WARNING: Removing unreachable block (ram,0x0d379c) */
/* WARNING: Removing unreachable block (ram,0x0d3796) */
/* WARNING: Removing unreachable block (ram,0x0d3776) */
/* WARNING: Removing unreachable block (ram,0x0d3772) */
/* WARNING: Removing unreachable block (ram,0x0d376e) */
/* WARNING: Removing unreachable block (ram,0x0d3766) */
/* WARNING: Removing unreachable block (ram,0x0d375e) */
/* WARNING: Removing unreachable block (ram,0x0d3756) */
/* WARNING: Removing unreachable block (ram,0x0d3752) */
/* WARNING: Removing unreachable block (ram,0x0d374e) */
/* WARNING: Removing unreachable block (ram,0x0d374a) */
/* WARNING: Removing unreachable block (ram,0x0d3746) */
/* WARNING: Removing unreachable block (ram,0x0d3742) */
/* WARNING: Removing unreachable block (ram,0x0d373e) */
/* WARNING: Removing unreachable block (ram,0x0d373a) */
/* WARNING: Removing unreachable block (ram,0x0d3736) */
/* WARNING: Removing unreachable block (ram,0x0d3728) */
/* WARNING: Removing unreachable block (ram,0x0d3718) */
/* WARNING: Removing unreachable block (ram,0x0d3714) */
/* WARNING: Removing unreachable block (ram,0x0d3710) */
/* WARNING: Removing unreachable block (ram,0x0d3790) */
/* WARNING: Removing unreachable block (ram,0x0d3780) */

void egs52_update_near_d566_0d370e(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  
  iVar5 = Ram00f648;
  uVar1 = iVar5 + 0x28;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = Ram00d500;
  if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar2) {
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 | 0x20;
  }
  else {
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 & 0xffdf;
  }
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xfffd;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 | 0x20;
  bVar6 = UNK_00d613;
  if (bVar6 < 6) {
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 | 0x800;
  }
  else {
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 & 0xf7ff;
  }
  UNK_00d566 = 0;
  UNK_00d567 = 0;
  UNK_00d5b0 = 0;
  UNK_00d5b1 = 0;
  UNK_00d5b2 = 0;
  iVar5 = Ram00f648;
  uVar1 = iVar5 + 0x3c;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  UNK_00d618 = *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  cVar7 = UNK_00d613;
  if ((cVar7 == '\a') && (uVar1 = Ram00fd30, (uVar1 & 1) != 0)) {
LAB_0d377c:
    Ram00d56a = 0;
    Ram00d556 = 0;
    Ram00d56c = 0;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 2;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 4;
  }
  else {
    uVar1 = Ram00fd3a;
    if ((uVar1 & 4) != 0) {
      iVar5 = Ram00f648;
      uVar1 = iVar5 + 0x34;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar3 = Ram00d500;
      uVar2 = Ram00d500;
      if (uVar1 == uVar2 || uVar1 < uVar3) goto LAB_0d377c;
    }
    iVar5 = Ram00f622;
    bVar6 = UNK_00d454;
    uVar3 = iVar5 + 4 + (uint)bVar6;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    UNK_00d477 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    bVar6 = UNK_00d454;
    iVar5 = Ram00f64a;
    uVar1 = iVar5 + (uint)bVar6 * 2 + 8;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d43c = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar9 = UNK_00d477;
    bVar6 = UNK_00d454;
    iVar5 = Ram00f624;
    uVar3 = iVar5 + 0x26 + (uint)bVar9 * 2 + (uint)bVar6 * 0xc;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d46e = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    iVar5 = Ram00f624;
    uVar1 = iVar5 + (uint)bVar9 * 2 + 0x96;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d54a = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar10 = UNK_00d477;
    uVar11 = egs52_compute_from_near_f624_0d41e8(uVar10);
    Ram00d536 = uVar11;
    cVar7 = UNK_00d454;
    if (cVar7 == '\a') {
      iVar5 = Ram00f624;
      uVar1 = iVar5 + 0x3a;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar8 = Ram00d46e;
      uVar2 = iVar5 + 0x46;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      Ram00d46e = (int)(((ulong)uVar8 *
                        (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) /
                       (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
    }
    UNK_00d579 = 3;
    bVar6 = UNK_00d454;
    if ((bVar6 < 3) || (5 < bVar6)) {
      UNK_00d579 = 1;
    }
    uVar1 = Ram00fd3a;
    if (((uVar1 & 4) != 0) &&
       ((uVar1 = Ram00fd56, (uVar1 & 0x20) != 0 || (cVar7 = UNK_00d616, cVar7 == '\x06')))) {
      UNK_00d579 = 1;
    }
    UNK_00d437 = 1;
  }
  return;
}


