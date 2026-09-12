/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09ceaa; FLS offset 0x01ceaa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x09d848) */
/* WARNING: Removing unreachable block (ram,0x09d83a) */
/* WARNING: Removing unreachable block (ram,0x09d82c) */
/* WARNING: Removing unreachable block (ram,0x09d81e) */
/* WARNING: Removing unreachable block (ram,0x09d80a) */
/* WARNING: Removing unreachable block (ram,0x09d7fe) */
/* WARNING: Removing unreachable block (ram,0x09d99c) */
/* WARNING: Removing unreachable block (ram,0x09d998) */
/* WARNING: Removing unreachable block (ram,0x09d992) */
/* WARNING: Removing unreachable block (ram,0x09d990) */
/* WARNING: Removing unreachable block (ram,0x09d966) */
/* WARNING: Removing unreachable block (ram,0x09d962) */
/* WARNING: Removing unreachable block (ram,0x09d900) */
/* WARNING: Removing unreachable block (ram,0x09d92a) */
/* WARNING: Removing unreachable block (ram,0x09d94c) */
/* WARNING: Removing unreachable block (ram,0x09d918) */
/* WARNING: Removing unreachable block (ram,0x09d8f6) */
/* WARNING: Removing unreachable block (ram,0x09d8e8) */
/* WARNING: Removing unreachable block (ram,0x09d8cc) */
/* WARNING: Removing unreachable block (ram,0x09d876) */
/* WARNING: Removing unreachable block (ram,0x09d8c2) */
/* WARNING: Removing unreachable block (ram,0x09d7c2) */
/* WARNING: Removing unreachable block (ram,0x09d728) */
/* WARNING: Removing unreachable block (ram,0x09d752) */
/* WARNING: Removing unreachable block (ram,0x09d7e2) */
/* WARNING: Removing unreachable block (ram,0x09d746) */
/* WARNING: Removing unreachable block (ram,0x09d7e8) */
/* WARNING: Removing unreachable block (ram,0x09d702) */
/* WARNING: Removing unreachable block (ram,0x09d6ee) */
/* WARNING: Removing unreachable block (ram,0x09d5e0) */
/* WARNING: Removing unreachable block (ram,0x09d616) */
/* WARNING: Removing unreachable block (ram,0x09d522) */
/* WARNING: Removing unreachable block (ram,0x09d64a) */
/* WARNING: Removing unreachable block (ram,0x09d5dc) */
/* WARNING: Removing unreachable block (ram,0x09d6c2) */
/* WARNING: Removing unreachable block (ram,0x09d672) */
/* WARNING: Removing unreachable block (ram,0x09d612) */
/* WARNING: Removing unreachable block (ram,0x09d558) */
/* WARNING: Removing unreachable block (ram,0x09d402) */
/* WARNING: Removing unreachable block (ram,0x09d432) */
/* WARNING: Removing unreachable block (ram,0x09d4fe) */
/* WARNING: Removing unreachable block (ram,0x09d1d8) */
/* WARNING: Removing unreachable block (ram,0x09d2a8) */
/* WARNING: Removing unreachable block (ram,0x09d468) */
/* WARNING: Removing unreachable block (ram,0x09d38a) */
/* WARNING: Removing unreachable block (ram,0x09d1a0) */
/* WARNING: Removing unreachable block (ram,0x09d406) */
/* WARNING: Removing unreachable block (ram,0x09d292) */
/* WARNING: Removing unreachable block (ram,0x09d180) */
/* WARNING: Removing unreachable block (ram,0x09d4e6) */
/* WARNING: Removing unreachable block (ram,0x09d2fe) */
/* WARNING: Removing unreachable block (ram,0x09d21a) */
/* WARNING: Removing unreachable block (ram,0x09d17c) */
/* WARNING: Removing unreachable block (ram,0x09d12c) */
/* WARNING: Removing unreachable block (ram,0x09d0d6) */
/* WARNING: Removing unreachable block (ram,0x09d0ba) */
/* WARNING: Removing unreachable block (ram,0x09d0b6) */
/* WARNING: Removing unreachable block (ram,0x09d076) */
/* WARNING: Removing unreachable block (ram,0x09d062) */
/* WARNING: Removing unreachable block (ram,0x09d050) */
/* WARNING: Removing unreachable block (ram,0x09d030) */
/* WARNING: Removing unreachable block (ram,0x09d4f8) */
/* WARNING: Removing unreachable block (ram,0x09d016) */
/* WARNING: Removing unreachable block (ram,0x09d006) */
/* WARNING: Removing unreachable block (ram,0x09d002) */
/* WARNING: Removing unreachable block (ram,0x09cffe) */
/* WARNING: Removing unreachable block (ram,0x09cffa) */
/* WARNING: Removing unreachable block (ram,0x09cff6) */
/* WARNING: Removing unreachable block (ram,0x09cff2) */
/* WARNING: Removing unreachable block (ram,0x09cfca) */
/* WARNING: Removing unreachable block (ram,0x09cfac) */
/* WARNING: Removing unreachable block (ram,0x09da38) */
/* WARNING: Removing unreachable block (ram,0x09cf2c) */
/* WARNING: Removing unreachable block (ram,0x09cf5c) */
/* WARNING: Removing unreachable block (ram,0x09cf28) */
/* WARNING: Removing unreachable block (ram,0x09cf8a) */
/* WARNING: Removing unreachable block (ram,0x09cf58) */
/* WARNING: Removing unreachable block (ram,0x09cf92) */
/* WARNING: Removing unreachable block (ram,0x09cf1a) */
/* WARNING: Removing unreachable block (ram,0x09cf12) */
/* WARNING: Removing unreachable block (ram,0x09cefc) */
/* WARNING: Removing unreachable block (ram,0x09cede) */
/* WARNING: Removing unreachable block (ram,0x09ced8) */
/* WARNING: Removing unreachable block (ram,0x09d034) */
/* WARNING: Removing unreachable block (ram,0x09d054) */
/* WARNING: Removing unreachable block (ram,0x09d072) */
/* WARNING: Removing unreachable block (ram,0x09d092) */
/* WARNING: Removing unreachable block (ram,0x09d126) */
/* WARNING: Removing unreachable block (ram,0x09d1c8) */
/* WARNING: Removing unreachable block (ram,0x09d288) */
/* WARNING: Removing unreachable block (ram,0x09d1ea) */
/* WARNING: Removing unreachable block (ram,0x09d1dc) */
/* WARNING: Removing unreachable block (ram,0x09d386) */
/* WARNING: Removing unreachable block (ram,0x09d436) */
/* WARNING: Removing unreachable block (ram,0x09d2f4) */
/* WARNING: Removing unreachable block (ram,0x09d21e) */
/* WARNING: Removing unreachable block (ram,0x09d542) */
/* WARNING: Removing unreachable block (ram,0x09d646) */
/* WARNING: Removing unreachable block (ram,0x09d6bc) */
/* WARNING: Removing unreachable block (ram,0x09d676) */
/* WARNING: Removing unreachable block (ram,0x09d6fc) */
/* WARNING: Removing unreachable block (ram,0x09d70e) */
/* WARNING: Removing unreachable block (ram,0x09d738) */
/* WARNING: Removing unreachable block (ram,0x09d78e) */
/* WARNING: Removing unreachable block (ram,0x09d792) */
/* WARNING: Removing unreachable block (ram,0x09d87a) */
/* WARNING: Removing unreachable block (ram,0x09d898) */
/* WARNING: Removing unreachable block (ram,0x09d946) */
/* WARNING: Removing unreachable block (ram,0x09d8ec) */
/* WARNING: Removing unreachable block (ram,0x09d984) */
/* WARNING: Removing unreachable block (ram,0x09d804) */
/* WARNING: Removing unreachable block (ram,0x09d7ae) */
/* WARNING: Removing unreachable block (ram,0x09d3c6) */
/* WARNING: Removing unreachable block (ram,0x09d240) */
/* WARNING: Removing unreachable block (ram,0x09d4a2) */
/* WARNING: Removing unreachable block (ram,0x09cf48) */
/* WARNING: Removing unreachable block (ram,0x09d25a) */
/* WARNING: Removing unreachable block (ram,0x09d3ca) */
/* WARNING: Removing unreachable block (ram,0x09d2a4) */
/* WARNING: Removing unreachable block (ram,0x09d46c) */
/* WARNING: Removing unreachable block (ram,0x09d2b8) */
/* WARNING: Removing unreachable block (ram,0x09d764) */
/* WARNING: Removing unreachable block (ram,0x09d250) */
/* WARNING: Removing unreachable block (ram,0x09cf78) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x090782 : 0x09d3c6 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

char egs52_register_sequence_09ceaa
               (undefined2 param_1,undefined2 param_2,undefined1 param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined1 *puVar14;
  char cVar15;
  uchar uVar16;
  uchar uVar17;
  ushort uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  ushort uVar25;
  int iVar26;
  char cVar27;
  byte bVar28;
  uint uStack_38;
  uchar uStack_36;
  int iStack_34;
  ushort uStack_30;
  undefined4 uStack_2e;
  undefined1 auStack_2a [2];
  uint uStack_28;
  
  uVar20 = param_4 - 4;
  uVar2 = 0x24;
  if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar18 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,0x28,0);
  uVar20 = param_4 + 0x24;
  uVar2 = 0x24;
  if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar19 = param_4 + 0x25;
  uVar3 = 0x24;
  if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if (((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
       (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff)) * 0x100 != uVar18) ||
     (cVar15 = egs52_call_092248_0e32e6(param_4 + -4), cVar15 == '\0')) {
    return '1';
  }
  bVar28 = UNK_00c32a;
  if (((bVar28 & 1) == 0) && ((bVar28 & 0x10) == 0)) {
    return '!';
  }
  cVar15 = '\0';
  uVar13 = Ram00c32e;
  Ram00c32e = param_4;
  uStack_38 = 0;
  while ((bVar28 = UNK_00c32c, uStack_38 < bVar28 && (cVar15 == '\0'))) {
    uVar2 = Ram00f682;
    uVar12 = Ram00f684;
    uVar20 = (uint)((ulong)uStack_38 * 0xc);
    cVar27 = (char)uVar12 + (0xfff9 < uVar2) + (char)((ulong)uStack_38 * 0xc >> 0x10) +
             CARRY2(uVar2 + 6,uVar20);
    if (*(char *)CONCAT12(cVar27,uVar2 + 6 + uVar20) != '\0') {
      uVar19 = egs52_compute_from_near_c32e_09f018(uStack_38);
      uVar2 = Ram00f682;
      uVar12 = Ram00f684;
      uVar20 = (uint)((ulong)uStack_38 * 0xc);
      cVar27 = (char)uVar12 + (0xfff8 < uVar2) + (char)((ulong)uStack_38 * 0xc >> 0x10) +
               CARRY2(uVar2 + 7,uVar20);
      if (*(byte *)CONCAT12(cVar27,uVar2 + 7 + uVar20) <= uVar19) {
        cVar15 = '1';
      }
    }
    uStack_38 = *(int *)CONCAT12(cVar27,&uStack_38) + 1;
  }
  if (cVar15 != '\0') {
    Ram00c32e = uVar13;
    return cVar15;
  }
  UNK_00c32a = 0x10;
  uVar20 = egs52_compute_from_near_c06e_094d98();
  if ((uVar20 & 0x100) == 0) {
    egs52_update_operating_masks(0x40,2);
  }
  uVar16 = egs52_disable_interrupts_save();
  uVar20 = 0x24;
  if ((((uRam090782 & 0xc000) != 0) && (uVar20 = 0x21, (uRam090782 & 0xc000) != 0x4000)) &&
     (uVar20 = 0x2c, (uRam090782 & 0xc000) != 0x8000)) {
    uVar20 = 3;
  }
  uStack_36 = egs52_boot_request_65(uRam090782 & 0x3fff | uVar20 << 0xe,uVar20 >> 2);
  if (uStack_36 == '\0') {
    egs52_update_fault_status(0x30,3);
    return 'B';
  }
  Ram00f682 = param_1;
  Ram00f684 = param_2;
  Ram00c330 = *(undefined2 *)((uint3)((uint)&stack0x0000 & 0x3fff) | 0xc000);
  UNK_00c32c = param_3;
  UNK_00c32b = 0xff;
  uStack_30 = 0;
  iStack_34 = 0;
  cVar15 = '\0';
  uVar20 = uRam090782;
  for (uStack_38 = 0; bVar28 = UNK_00c32c, uStack_38 < bVar28; uStack_38 = uStack_38 + 1) {
    uVar2 = iStack_34 * 4 + 0x784;
    uVar19 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar19 = 3;
    }
    if (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
    uVar2 = iStack_34 * 4 + 0x782;
    uVar19 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar19 = 3;
    }
    if (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
    lVar8 = (ulong)uStack_38 * 0xc;
    uVar13 = Ram00f682;
    uVar12 = Ram00f684;
    lVar11 = lVar8 + CONCAT22(uVar12,uVar13);
    uVar19 = *(uint *)((uint3)(uint)((ulong)lVar11 >> 0x10) << 0x10 | (uint3)(uint)lVar11);
    iVar26 = *(int *)((uint3)(uint)((ulong)(lVar11 + 2) >> 0x10) << 0x10 | (uint3)(uint)(lVar11 + 2)
                     );
    uStack_2e = CONCAT22(iVar26,uVar19);
    uVar2 = Ram00f682;
    uVar13 = Ram00f684;
    bVar28 = (char)uVar13 + (0xfff9 < uVar2) + (char)((ulong)lVar8 >> 0x10) +
             CARRY2(uVar2 + 6,(uint)lVar8);
    if (*(char *)CONCAT12(bVar28,uVar2 + 6 + (uint)lVar8) != '\0') {
      iVar21 = egs52_compute_from_near_c32e_09f018(uStack_38);
      uVar3 = Ram00f682;
      uVar13 = Ram00f684;
      uVar2 = (uint)((ulong)uStack_38 * 0xc);
      bVar28 = (char)uVar13 + (0xfffb < uVar3) + (char)((ulong)uStack_38 * 0xc >> 0x10) +
               CARRY2(uVar3 + 4,uVar2);
      uVar2 = iVar21 * *(int *)CONCAT12(bVar28,uVar3 + 4 + uVar2);
      uStack_2e = CONCAT22(iVar26 + (uint)CARRY2(uVar19,uVar2),uVar19 + uVar2);
    }
    uVar2 = *(uint *)((uint3)bVar28 << 0x10 | 0x3682);
    uVar19 = uVar2 + 4;
    uVar3 = (uint)((ulong)uStack_38 * 0xc);
    uVar2 = *(uint *)CONCAT12((char)*(undefined2 *)((uint3)bVar28 << 0x10 | 0x3684) +
                              (0xfffb < uVar2) + (char)((ulong)uStack_38 * 0xc >> 0x10) +
                              CARRY2(uVar19,uVar3),uVar19 + uVar3);
    uStack_30 = egs52_crc16_a001_far((uint)uStack_2e,uStack_2e._2_2_,uVar2,uStack_30);
    if (uVar2 < 0x401) {
      uVar19 = 0xe400;
      for (uStack_28 = 0; uStack_28 < uVar2; uStack_28 = uStack_28 + 1) {
        puVar14 = (undefined1 *)uStack_2e;
        uStack_2e = CONCAT22(uStack_2e._2_2_ + (0xfffe < (uint)uStack_2e),(uint)uStack_2e + 1);
        uVar3 = 0x24;
        if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff)) = *puVar14;
        uVar19 = uVar19 + 1;
      }
      uVar19 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar19 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar19 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar19 = 3;
      }
      uStack_36 = egs52_boot_request_53(uVar20 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,0xe400,uVar2);
    }
    else {
      cVar15 = 'C';
    }
    if (uStack_36 == '\0') {
      cVar15 = 'B';
    }
    uVar2 = Ram00f682;
    uVar13 = Ram00f684;
    uVar19 = (uint)((ulong)uStack_38 * 0xc);
    cVar27 = (char)((ulong)uStack_38 * 0xc >> 0x10);
    uVar2 = *(uint *)CONCAT12((char)uVar13 + (0xfff7 < uVar2) + cVar27 + CARRY2(uVar2 + 8,uVar19),
                              uVar2 + 8 + uVar19);
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar22 = uVar2 & 0x3fff | uVar3 << 0xe;
    if ((uVar3 >> 2 == 0 && uVar22 < 0xf5d8) || (uVar3 >> 2 != 0 || 0xf6ac < uVar22)) {
      cVar15 = '\"';
    }
    else {
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar20;
    }
    uVar2 = Ram00f682;
    uVar13 = Ram00f684;
    uVar20 = uVar20 + *(int *)CONCAT12((char)uVar13 + (0xfffb < uVar2) + cVar27 +
                                       CARRY2(uVar2 + 4,uVar19),uVar2 + 4 + uVar19);
    if ((uVar20 & 1) != 0) {
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uStack_30 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,1,uStack_30);
      uVar20 = uVar20 + 1;
    }
    uVar19 = Ram00f682;
    uVar13 = Ram00f684;
    uVar3 = uStack_38 + 1;
    uVar2 = (uint)((ulong)uVar3 * 0xc);
    uVar19 = *(uint *)CONCAT12((char)uVar13 + (0xfffb < uVar19) + (char)((ulong)uVar3 * 0xc >> 0x10)
                               + CARRY2(uVar19 + 4,uVar2),uVar19 + 4 + uVar2);
    iVar26 = iStack_34 * 4;
    uVar22 = iVar26 + 0x784;
    uVar2 = 0x24;
    if ((((uVar22 & 0xc000) != 0) && (uVar2 = 0x21, (uVar22 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar22 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar22 & 0x3fff));
    uVar5 = iVar26 + 0x782;
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff));
    uVar9 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    uVar23 = uVar2 & 0x3fff | uVar9 << 0xe;
    uVar2 = uVar23 + uVar4;
    uVar10 = 0x24;
    if ((((uVar20 & 0xc000) != 0) && (uVar10 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    uVar24 = uVar20 & 0x3fff | uVar10 << 0xe;
    uVar6 = uVar2 - uVar24;
    uVar7 = uVar6 - 10;
    iVar21 = ((((uVar9 >> 2) + (uint)CARRY2(uVar23,uVar4)) - (uVar10 >> 2)) - (uint)(uVar2 < uVar24)
             ) - (uint)(uVar6 < 10);
    if (((-iVar21 != (uint)(uVar19 < uVar7) || uVar19 != uVar7) &&
         (iVar21 == 0 && (iVar21 != 0 || uVar19 >= uVar7))) ||
       (bVar28 = UNK_00c32c, uVar3 == bVar28)) {
      bVar28 = UNK_00c32c;
      if (uVar3 != bVar28) {
        uVar19 = iVar26 + 0x786;
        uVar2 = 0x24;
        if ((((uVar19 & 0xc000) != 0) && (uVar2 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar19 & 0x3fff)) != 0) {
          uVar2 = iVar26 + 0x788;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) != 0) {
            uVar2 = 0x24;
            if ((((uVar19 & 0xc000) != 0) && (uVar2 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar19 & 0x3fff));
            uVar19 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar19 = 3;
            }
            uStack_36 = egs52_boot_request_65(uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2);
            if (uStack_36 == '\0') {
              cVar15 = 'B';
            }
            goto LAB_09d2ea;
          }
        }
        cVar15 = 'C';
      }
LAB_09d2ea:
      if (cVar15 == '\0') {
        uVar2 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff));
        iVar26 = 0;
        if ((((uVar2 & 0xc000) != 0) && (iVar26 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (iVar26 = 0, (uVar2 & 0xc000) != 0x8000)) {
          iVar26 = 3;
        }
        uVar19 = 0x24;
        if ((((uVar22 & 0xc000) != 0) && (uVar19 = 0x21, (uVar22 & 0xc000) != 0x4000)) &&
           (uVar19 = 0x2c, (uVar22 & 0xc000) != 0x8000)) {
          uVar19 = 3;
        }
        uVar18 = (((uVar2 & 0x3fff | iVar26 << 0xe) +
                  *(int *)((uint3)uVar19 << 0xe | (uint3)(uVar22 & 0x3fff))) - uVar24) - 10;
        while (uVar18 != 0) {
          if (uVar18 < 0x401) {
            uVar2 = 0x24;
            if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uStack_30 = egs52_crc16_a001_far
                                  (uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,uVar18,uStack_30);
            uVar18 = 0;
          }
          else {
            uVar2 = 0x24;
            if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar25 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,0x400,uStack_30)
            ;
            uVar18 = uVar18 - 0x400;
            uVar20 = uVar20 + 0x400;
            egs52_service_watchdog(0xc001);
            egs52_update_near_c1aa_0994da(uVar18);
            uStack_30 = uVar25;
          }
        }
        iVar26 = iStack_34 * 4;
        uVar2 = iVar26 + 0x782;
        uVar19 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar19 = 3;
        }
        uVar3 = iVar26 + 0x784;
        uVar22 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar22 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar22 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar22 = 3;
        }
        uVar2 = (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                *(int *)((uint3)uVar22 << 0xe | (uint3)(uVar3 & 0x3fff))) - 2;
        uVar19 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar19 = 3;
        }
        uStack_36 = egs52_boot_request_53
                              (uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,(ushort)&uStack_30,2);
        if (uStack_36 != '\0') {
          if (iStack_34 == 0) {
            uVar2 = (uRam090782 + iRam090784) - 8;
            uVar19 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar19 = 3;
            }
            uStack_36 = egs52_boot_request_53
                                  (uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,(ushort)auStack_2a,2);
          }
          if (uStack_36 != '\0') {
            uVar2 = iVar26 + 0x782;
            uVar19 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar19 = 3;
            }
            uVar3 = iVar26 + 0x784;
            uVar22 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar22 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar22 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar22 = 3;
            }
            uVar2 = (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                    *(int *)((uint3)uVar22 << 0xe | (uint3)(uVar3 & 0x3fff))) - 6;
            uVar19 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar19 = 3;
            }
            uVar17 = egs52_boot_request_53
                               (uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,(ushort)auStack_2a,2);
            if (uVar17 == '\0') {
              uStack_36 = '\0';
            }
            else {
              uVar2 = iVar26 + 0x782;
              uVar19 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar19 = 3;
              }
              uVar3 = iVar26 + 0x784;
              uVar22 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar22 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar22 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar22 = 3;
              }
              uVar2 = (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                      *(int *)((uint3)uVar22 << 0xe | (uint3)(uVar3 & 0x3fff))) - 4;
              uVar19 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar19 = 3;
              }
              uVar17 = egs52_boot_request_53
                                 (uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,(ushort)&uStack_38,2);
              if (uVar17 == '\0') {
                uStack_36 = '\0';
              }
              else {
                uVar2 = iVar26 + 0x782;
                uVar19 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar19 = 3;
                }
                uVar3 = iVar26 + 0x784;
                uVar22 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar22 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar22 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar22 = 3;
                }
                uVar2 = (*(int *)((uint3)uVar19 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                        *(int *)((uint3)uVar22 << 0xe | (uint3)(uVar3 & 0x3fff))) - 10;
                uVar19 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar19 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar19 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar19 = 3;
                }
                uStack_36 = egs52_boot_request_53
                                      (uVar2 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,(ushort)auStack_2a
                                       ,2);
              }
            }
          }
        }
      }
      iStack_34 = iStack_34 + 1;
      if (uStack_36 == '\0') {
        cVar15 = 'B';
      }
      else {
        uVar20 = iStack_34 * 4 + 0x782;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar20 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff));
        uStack_30 = 0;
      }
      if ((uVar20 & 1) != 0) {
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uStack_30 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,1,uStack_30);
        uVar20 = uVar20 + 1;
      }
    }
  }
  do {
    uVar20 = iStack_34 * 4 + 0x782;
    uVar2 = 0x24;
    if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) break;
    uVar20 = iStack_34 * 4 + 0x784;
    uVar2 = 0x24;
    if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) break;
    if (cVar15 == '\0') {
      iVar26 = iStack_34 * 4;
      uVar20 = iVar26 + 0x782;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar20 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff));
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar17 = egs52_boot_request_65(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2);
      if (uVar17 == '\0') {
        cVar15 = 'B';
        uStack_36 = '\0';
      }
      else {
        uVar20 = iVar26 + 0x782;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar20 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar19 = iVar26 + 0x784;
        uVar3 = 0x24;
        if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar18 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff)) - 10;
        uStack_2e._0_2_ = uVar20 & 0x3fff | uVar2 << 0xe;
        uStack_2e._2_2_ = uVar2 >> 2;
        while (uVar18 != 0) {
          if (uVar18 < 0x401) {
            uStack_30 = egs52_crc16_a001_far((uint)uStack_2e,uStack_2e._2_2_,uVar18,uStack_30);
            uVar18 = 0;
          }
          else {
            uVar25 = egs52_crc16_a001_far((uint)uStack_2e,uStack_2e._2_2_,0x400,uStack_30);
            uVar18 = uVar18 - 0x400;
            bVar1 = 0xfbff < (uint)uStack_2e;
            egs52_service_watchdog(0xc001);
            egs52_update_near_c1aa_0994da();
            uStack_30 = uVar25;
            uStack_2e._0_2_ = (uint)uStack_2e + 0x400;
            uStack_2e._2_2_ = uStack_2e._2_2_ + bVar1;
          }
        }
        iVar26 = iStack_34 * 4;
        uVar20 = iVar26 + 0x782;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar19 = iVar26 + 0x784;
        uVar3 = 0x24;
        if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar20 = (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
                 *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff))) - 2;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar17 = egs52_boot_request_53
                           (uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,(ushort)&uStack_30,2);
        if (uVar17 == '\0') {
          uStack_36 = '\0';
        }
        else {
          uVar20 = iVar26 + 0x782;
          uVar2 = 0x24;
          if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar19 = iVar26 + 0x784;
          uVar3 = 0x24;
          if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar20 = (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
                   *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff))) - 10;
          uVar2 = 0x24;
          if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar17 = egs52_boot_request_53
                             (uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,(ushort)auStack_2a,2);
          if (uVar17 == '\0') {
            uStack_36 = '\0';
          }
          else {
            uVar20 = iVar26 + 0x782;
            uVar2 = 0x24;
            if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar19 = iVar26 + 0x784;
            uVar3 = 0x24;
            if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            uVar20 = (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
                     *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff))) - 6;
            uVar2 = 0x24;
            if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar17 = egs52_boot_request_53
                               (uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,(ushort)auStack_2a,2);
            if (uVar17 == '\0') {
              uStack_36 = '\0';
            }
            else {
              uVar20 = iVar26 + 0x782;
              uVar2 = 0x24;
              if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              uVar19 = iVar26 + 0x784;
              uVar3 = 0x24;
              if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              uVar20 = (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
                       *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff))) - 4;
              uVar2 = 0x24;
              if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              uStack_36 = egs52_boot_request_53
                                    (uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,(ushort)&uStack_38,2)
              ;
            }
          }
        }
      }
    }
    if (uStack_36 == '\0') {
      cVar15 = 'B';
    }
    iStack_34 = iStack_34 + 1;
  } while( true );
  iVar26 = egs52_call_092118_09f05e();
  if (iVar26 != 0) {
    iStack_34 = 0;
    while( true ) {
      uVar20 = iStack_34 * 4 + 0x782;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) break;
      uVar20 = iStack_34 * 4 + 0x784;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) break;
      uVar2 = iStack_34 * 4 + 0x782;
      uVar20 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      uVar3 = iStack_34 * 4 + 0x784;
      uVar19 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar19 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar19 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar19 = 3;
      }
      uVar19 = (*(int *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) +
               *(int *)((uint3)uVar19 << 0xe | (uint3)(uVar3 & 0x3fff))) - 8;
      uVar20 = 0x24;
      if ((((uVar19 & 0xc000) != 0) && (uVar20 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      if (*(int *)((uint3)uVar20 << 0xe | (uint3)(uVar19 & 0x3fff)) == 0x6309) {
        uVar20 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar20 = 3;
        }
        uVar20 = *(uint *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar19 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar19 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar19 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar19 = 3;
        }
        uVar18 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,0x28,0);
        uVar20 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar20 = 3;
        }
        uVar20 = *(int *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) + 0x28;
        uVar19 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar19 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar19 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar19 = 3;
        }
        if (*(ushort *)CONCAT12((char)(uVar19 >> 2),uVar20 & 0x3fff | uVar19 << 0xe) == uVar18) {
          uVar20 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar20 = 3;
          }
          egs52_memcpy_near((uchar *)0xf474,
                            *(uchar **)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)),0x2e);
          uVar20 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar20 = 3;
          }
          uVar20 = *(uint *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar19 = 0x24;
          if ((((uVar20 & 0xc000) != 0) && (uVar19 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
             (uVar19 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
            uVar19 = 3;
          }
          egs52_boot_request_65(uVar20 & 0x3fff | uVar19 << 0xe,uVar19 >> 2);
          uVar20 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar20 = 3;
          }
          uVar20 = *(uint *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar19 = 0x24;
          if ((((uVar20 & 0xc000) != 0) && (uVar19 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
             (uVar19 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
            uVar19 = 3;
          }
          uVar17 = egs52_boot_request_53(uVar20 & 0x3fff | uVar19 << 0xe,uVar19 >> 2,0xf474,0x2e);
          if (uVar17 != '\0') {
            uVar20 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar20 = 3;
            }
            uVar19 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar19 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar19 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar19 = 3;
            }
            uVar20 = (*(int *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                     *(int *)((uint3)uVar19 << 0xe | (uint3)(uVar3 & 0x3fff))) - 8;
            uVar2 = 0x24;
            if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            egs52_boot_request_53(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,(ushort)&uStack_38,2);
          }
        }
        else {
          uVar20 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar20 = 3;
          }
          uVar20 = *(uint *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar2 = 0x24;
          if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          egs52_boot_request_65(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2);
        }
      }
      else {
        uVar20 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar20 = 3;
        }
        uVar20 = *(uint *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        egs52_boot_request_65(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2);
      }
      iStack_34 = iStack_34 + 1;
    }
    cVar15 = 'B';
  }
  if (cVar15 == '\0') {
    Ram00c32e = uRam090782 + 4;
    UNK_00c32a = 1;
    egs52_update_fault_status(0x30,2);
    uVar2 = param_4 - 4;
    uVar20 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar20 = 3;
    }
    if (*(char *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) != '@') {
      uVar2 = param_4 - 3;
      uVar20 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      if (*(char *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) != '@') {
        uVar2 = param_4 - 2;
        uVar20 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar20 = 3;
        }
        if (*(char *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) != '@') {
          uVar2 = param_4 - 1;
          uVar20 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar20 = 3;
          }
          if (*(char *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) != '@') {
            egs52_update_fault_status(0x2f,2);
            goto LAB_09da18;
          }
        }
      }
    }
    egs52_update_fault_status(0x2f,3);
  }
  else {
    for (uStack_38 = 0; bVar28 = UNK_00c32c, uStack_38 < bVar28; uStack_38 = uStack_38 + 1) {
      uVar2 = Ram00f682;
      uVar13 = Ram00f684;
      uVar20 = (uint)((ulong)uStack_38 * 0xc);
      uVar20 = *(uint *)CONCAT12((char)uVar13 + (0xfff7 < uVar2) +
                                 (char)((ulong)uStack_38 * 0xc >> 0x10) + CARRY2(uVar2 + 8,uVar20),
                                 uVar2 + 8 + uVar20);
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar19 = uVar20 & 0x3fff | uVar2 << 0xe;
      if ((uVar2 >> 2 != 0 || 0xf5d7 < uVar19) && (uVar2 >> 2 == 0 && uVar19 < 0xf6ad)) {
        uVar2 = 0x24;
        if (((uVar20 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000 &&
            (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)))) {
          uVar2 = 3;
        }
        *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) = 0;
      }
    }
    iStack_34 = 0;
    bVar1 = true;
    while( true ) {
      iVar26 = iStack_34 * 4;
      uVar20 = iVar26 + 0x782;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) break;
      uVar20 = iVar26 + 0x784;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) == 0) || (!bVar1)) break;
      iVar26 = iStack_34 * 4;
      uVar20 = iVar26 + 0x782;
      uVar2 = 0x24;
      if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar19 = iVar26 + 0x784;
      uVar3 = 0x24;
      if ((((uVar19 & 0xc000) != 0) && (uVar3 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) +
              *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar19 & 0x3fff))) - 8;
      uVar20 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar20 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      if (*(int *)((uint3)uVar20 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0x6309) {
        uVar20 = iVar26 + 0x782;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar20 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar18 = egs52_crc16_a001_far(uVar20 & 0x3fff | uVar2 << 0xe,uVar2 >> 2,0x28,0);
        uVar20 = iVar26 + 0x782;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar20 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar20 & 0x3fff)) + 0x28;
        uVar2 = 0x24;
        if ((((uVar20 & 0xc000) != 0) && (uVar2 = 0x21, (uVar20 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar20 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(ushort *)CONCAT12((char)(uVar2 >> 2),uVar20 & 0x3fff | uVar2 << 0xe) == uVar18) {
          bVar1 = false;
        }
      }
      iStack_34 = iStack_34 + 1;
    }
    if (!bVar1) {
      uVar2 = Ram00f682;
      uVar13 = Ram00f684;
      uVar20 = (uint)((ulong)uStack_38 * 0xc);
      uVar2 = *(uint *)CONCAT12((char)uVar13 + (0xfff7 < uVar2) +
                                (char)((ulong)uStack_38 * 0xc >> 0x10) + CARRY2(uVar2 + 8,uVar20),
                                uVar2 + 8 + uVar20);
      uVar19 = iVar26 + 0x77e;
      uVar20 = 0x24;
      if ((((uVar19 & 0xc000) != 0) && (uVar20 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(undefined2 *)((uint3)uVar20 << 0xe | (uint3)(uVar19 & 0x3fff));
      uVar20 = 0x24;
      if ((((uVar19 & 0xc000) != 0) && (uVar20 = 0x21, (uVar19 & 0xc000) != 0x4000)) &&
         (uVar20 = 0x2c, (uVar19 & 0xc000) != 0x8000)) {
        uVar20 = 3;
      }
      Ram00c32e = *(int *)((uint3)uVar20 << 0xe | (uint3)(uVar19 & 0x3fff)) + 4;
    }
    egs52_update_fault_status(0x30,3);
    egs52_update_fault_status(0x2f,2);
  }
LAB_09da18:
  if (uVar16 != '\0') {
    egs52_enable_interrupts();
  }
  return cVar15;
}


