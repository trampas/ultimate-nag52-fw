/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e04da; FLS offset 0x0604da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e0724) */
/* WARNING: Removing unreachable block (ram,0x0e071e) */
/* WARNING: Removing unreachable block (ram,0x0e071a) */
/* WARNING: Removing unreachable block (ram,0x0e070e) */
/* WARNING: Removing unreachable block (ram,0x0e06fe) */
/* WARNING: Removing unreachable block (ram,0x0e06f8) */
/* WARNING: Removing unreachable block (ram,0x0e06f2) */
/* WARNING: Removing unreachable block (ram,0x0e06ee) */
/* WARNING: Removing unreachable block (ram,0x0e06e6) */
/* WARNING: Removing unreachable block (ram,0x0e06de) */
/* WARNING: Removing unreachable block (ram,0x0e06d8) */
/* WARNING: Removing unreachable block (ram,0x0e06d2) */
/* WARNING: Removing unreachable block (ram,0x0e06c6) */
/* WARNING: Removing unreachable block (ram,0x0e073a) */
/* WARNING: Removing unreachable block (ram,0x0e0736) */
/* WARNING: Removing unreachable block (ram,0x0e0732) */
/* WARNING: Removing unreachable block (ram,0x0e06b8) */
/* WARNING: Removing unreachable block (ram,0x0e06a8) */
/* WARNING: Removing unreachable block (ram,0x0e06a4) */
/* WARNING: Removing unreachable block (ram,0x0e069e) */
/* WARNING: Removing unreachable block (ram,0x0e068c) */
/* WARNING: Removing unreachable block (ram,0x0e0684) */
/* WARNING: Removing unreachable block (ram,0x0e0680) */
/* WARNING: Removing unreachable block (ram,0x0e067a) */
/* WARNING: Removing unreachable block (ram,0x0e0670) */
/* WARNING: Removing unreachable block (ram,0x0e066c) */
/* WARNING: Removing unreachable block (ram,0x0e0652) */
/* WARNING: Removing unreachable block (ram,0x0e064c) */
/* WARNING: Removing unreachable block (ram,0x0e063a) */
/* WARNING: Removing unreachable block (ram,0x0e0614) */
/* WARNING: Removing unreachable block (ram,0x0e05f4) */
/* WARNING: Removing unreachable block (ram,0x0e0632) */
/* WARNING: Removing unreachable block (ram,0x0e062e) */
/* WARNING: Removing unreachable block (ram,0x0e0620) */
/* WARNING: Removing unreachable block (ram,0x0e05e4) */
/* WARNING: Removing unreachable block (ram,0x0e05e0) */
/* WARNING: Removing unreachable block (ram,0x0e05c6) */
/* WARNING: Removing unreachable block (ram,0x0e05be) */
/* WARNING: Removing unreachable block (ram,0x0e05ae) */
/* WARNING: Removing unreachable block (ram,0x0e05a6) */
/* WARNING: Removing unreachable block (ram,0x0e058e) */
/* WARNING: Removing unreachable block (ram,0x0e058a) */
/* WARNING: Removing unreachable block (ram,0x0e057a) */
/* WARNING: Removing unreachable block (ram,0x0e0572) */
/* WARNING: Removing unreachable block (ram,0x0e056a) */
/* WARNING: Removing unreachable block (ram,0x0e055c) */
/* WARNING: Removing unreachable block (ram,0x0e0552) */
/* WARNING: Removing unreachable block (ram,0x0e0544) */
/* WARNING: Removing unreachable block (ram,0x0e053c) */
/* WARNING: Removing unreachable block (ram,0x0e051e) */
/* WARNING: Removing unreachable block (ram,0x0e051a) */
/* WARNING: Removing unreachable block (ram,0x0e0532) */
/* WARNING: Removing unreachable block (ram,0x0e04f4) */
/* WARNING: Removing unreachable block (ram,0x0e04e4) */
/* WARNING: Removing unreachable block (ram,0x0e04dc) */
/* WARNING: Removing unreachable block (ram,0x0e0500) */
/* WARNING: Removing unreachable block (ram,0x0e050a) */
/* WARNING: Removing unreachable block (ram,0x0e050e) */
/* WARNING: Removing unreachable block (ram,0x0e054a) */
/* WARNING: Removing unreachable block (ram,0x0e0564) */
/* WARNING: Removing unreachable block (ram,0x0e0580) */
/* WARNING: Removing unreachable block (ram,0x0e0586) */
/* WARNING: Removing unreachable block (ram,0x0e05b4) */
/* WARNING: Removing unreachable block (ram,0x0e05cc) */
/* WARNING: Removing unreachable block (ram,0x0e05ee) */
/* WARNING: Removing unreachable block (ram,0x0e05fa) */
/* WARNING: Removing unreachable block (ram,0x0e061a) */
/* WARNING: Removing unreachable block (ram,0x0e0628) */
/* WARNING: Removing unreachable block (ram,0x0e0642) */
/* WARNING: Removing unreachable block (ram,0x0e0646) */
/* WARNING: Removing unreachable block (ram,0x0e0674) */
/* WARNING: Removing unreachable block (ram,0x0e0694) */
/* WARNING: Removing unreachable block (ram,0x0e0698) */
/* WARNING: Removing unreachable block (ram,0x0e06ce) */

void egs52_update_near_d73c_0e04da(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  byte bVar10;
  uint uStack_4;
  
  uVar2 = Ram00fd56;
  if ((((uVar2 & 1) == 0) || (bVar8 = UNK_00d75c, (bVar8 & 0x40) == 0)) &&
     ((uVar2 = Ram00fd56, (uVar2 & 1) != 0 || (bVar8 = UNK_00d75c, (bVar8 & 4) == 0)))) {
    UNK_00d71c = 0;
    Ram00d738 = 0;
    Ram00d73a = 0;
    return;
  }
  iVar6 = Ram00d7ac;
  if (iVar6 < 1) {
    UNK_00d71c = 0;
    uVar1 = Ram00d77c;
    bVar8 = UNK_00d772;
    iVar6 = Ram00f662;
    uVar2 = iVar6 + (uint)bVar8 * 2 + 0x20;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d738 = (int)(((ulong)uVar1 *
                      (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) / 100);
    uVar1 = Ram00d77c;
    bVar8 = UNK_00d774;
    iVar6 = Ram00f662;
    uVar2 = iVar6 + (uint)bVar8 * 2 + 0x18;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    iVar6 = (int)(((ulong)uVar1 * (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) /
                 100);
    Ram00d73a = iVar6;
    if (iVar6 != 0) {
      iVar6 = Ram00f662;
      uVar2 = iVar6 + 0x88;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar1 = Ram00d77c;
      if (*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) < uVar1) {
        uVar2 = Ram00fd2e;
        Ram00fd2e = uVar2 | 1;
        return;
      }
    }
    uVar2 = Ram00fd2e;
    Ram00fd2e = uVar2 & 0xfffe;
    return;
  }
  iVar6 = Ram00f65a;
  uVar2 = iVar6 + 4;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  if ((*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
    bVar8 = UNK_00d7d0;
    uStack_4 = (uint)bVar8;
  }
  else {
    bVar8 = UNK_00d7d0;
    bVar10 = UNK_00d7d0;
    uStack_4 = (uint)(((ulong)bVar8 * (ulong)bVar10) / 100);
  }
  iVar6 = Ram00f662;
  bVar8 = UNK_00d772;
  uVar4 = iVar6 + 0x30 + (uint)bVar8;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d73c = (int)(((ulong)uStack_4 *
                    (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff))) / 10);
  iVar6 = Ram00f662;
  bVar8 = UNK_00d774;
  uVar4 = iVar6 + 0x34 + (uint)bVar8;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d73e = (int)(((ulong)uStack_4 *
                    (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff))) / 10);
  bVar8 = UNK_00d76f;
  iVar6 = Ram00f624;
  uVar2 = iVar6 + (uint)bVar8 * 2 + 6;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar6 = Ram00f65e;
  uVar1 = iVar6 + 4;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar1 = (uint)(((ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) * 1000) /
                (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)));
  iVar6 = Ram00f662;
  bVar8 = UNK_00d772;
  uVar4 = iVar6 + 0x38 + (uint)bVar8;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar6 = Ram00f662;
  bVar8 = UNK_00d772;
  uVar5 = iVar6 + 0x3c + (uint)bVar8;
  uVar3 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) +
          (int)(((ulong)uStack_4 * (ulong)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)))
               / 100);
  uVar2 = Ram00d500;
  uVar4 = Ram00d786;
  uVar3 = Ram00d786;
  if (uVar2 != uVar3 && uVar4 <= uVar2) {
    uVar4 = Ram00d786;
    uVar3 = Ram00d786;
    if (uVar1 != uVar3 && uVar4 <= uVar1) {
      iVar9 = Ram00d786;
      iVar7 = Ram00d786;
      iVar6 = (int)(((long)(100 - iVar6) * (long)(int)(uVar2 - iVar7)) / (long)(int)(uVar1 - iVar9))
              + iVar6;
      if (iVar6 < 1) {
        Ram00d77a = 0;
      }
      else {
        Ram00d77a = iVar6;
      }
      goto LAB_0e0636;
    }
  }
  iVar6 = Ram00f662;
  bVar8 = UNK_00d772;
  uVar4 = iVar6 + 0x3c + (uint)bVar8;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d77a = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
LAB_0e0636:
  uVar3 = Ram00d77c;
  uVar1 = Ram00d77a;
  iVar6 = Ram00f662;
  bVar8 = UNK_00d772;
  uVar4 = iVar6 + 4 + (uint)bVar8;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  UNK_00d71c = (char)(((ulong)uVar3 *
                      (((ulong)uVar1 *
                       (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff))) / 100 &
                      0xffff)) / 100);
  uVar1 = Ram00d77c;
  bVar8 = UNK_00d772;
  iVar6 = Ram00f662;
  uVar2 = iVar6 + (uint)bVar8 * 2 + 0x10;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar6 = Ram00d73c;
  Ram00d738 = (int)(((ulong)uVar1 *
                    (ulong)(uint)(*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar6))
                   / 100);
  uVar1 = Ram00d77c;
  bVar8 = UNK_00d774;
  iVar6 = Ram00f662;
  uVar2 = iVar6 + (uint)bVar8 * 2 + 8;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar6 = Ram00d73e;
  Ram00d73a = (int)(((ulong)uVar1 *
                    (ulong)(uint)(*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar6))
                   / 100);
  uVar2 = Ram00fd2e;
  Ram00fd2e = uVar2 & 0xfffe;
  return;
}


