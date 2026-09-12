/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09e304; FLS offset 0x01e304.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09e47e) */
/* WARNING: Removing unreachable block (ram,0x09e4aa) */
/* WARNING: Removing unreachable block (ram,0x09e49c) */
/* WARNING: Removing unreachable block (ram,0x09e468) */
/* WARNING: Removing unreachable block (ram,0x09e438) */
/* WARNING: Removing unreachable block (ram,0x09e458) */
/* WARNING: Removing unreachable block (ram,0x09e422) */
/* WARNING: Removing unreachable block (ram,0x09e32a) */
/* WARNING: Removing unreachable block (ram,0x09e35c) */
/* WARNING: Removing unreachable block (ram,0x09e326) */
/* WARNING: Removing unreachable block (ram,0x09e340) */
/* WARNING: Removing unreachable block (ram,0x09e358) */
/* WARNING: Removing unreachable block (ram,0x09e33c) */
/* WARNING: Removing unreachable block (ram,0x09e45c) */
/* WARNING: Removing unreachable block (ram,0x09e426) */
/* WARNING: Removing unreachable block (ram,0x09e43c) */
/* WARNING: Removing unreachable block (ram,0x09e36a) */

undefined1 egs52_update_near_c34a_09e304(uint param_1,uint param_2,uchar *param_3,byte param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  byte bVar11;
  uchar *puStack_14;
  uint uStack_12;
  ushort uStack_10;
  uint uStack_a;
  
  bVar7 = false;
  bVar11 = 0;
  while (!bVar7) {
    uVar1 = (uint)bVar11 * 4 - 0x7e6;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = (uint)bVar11 * 4 - 0x7e4;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
    iVar10 = (uint)bVar11 * 4;
    uVar1 = iVar10 - 0x7e6;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = iVar10 - 0x7e4;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    if (param_2 - uVar1 == (uint)(param_1 < uVar2) && param_1 == uVar2 ||
        (param_2 < uVar1 || param_2 == uVar1 && param_1 < uVar2)) {
      uVar2 = param_2 + CARRY2(param_1,(uint)param_4);
      uVar1 = iVar10 - 0x7ea;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar4 = iVar10 - 0x7e8;
      uVar5 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      uVar4 = *(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff));
      if (uVar2 < uVar4 ||
          uVar2 == uVar4 &&
          param_1 + param_4 < *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)))
      goto LAB_09e34e;
      bVar7 = true;
    }
    else {
LAB_09e34e:
      bVar11 = bVar11 + 2;
    }
  }
  if (bVar7) {
    bVar11 = UNK_00c32a;
    if ((bVar11 & 1) == 0) {
      uVar8 = 0xff;
    }
    else {
      uStack_a = (uint)param_4;
      do {
        egs52_copy_words_registers(&puStack_14);
        egs52_transform_far_memory_09e4c8();
        if (uStack_12 == (puStack_14 != (uchar *)0xffff) && puStack_14 == (uchar *)0xffff ||
            uStack_12 == 0 && puStack_14 != (uchar *)0xffff) {
          egs52_memcpy_near(param_3,puStack_14,uStack_10);
        }
        else {
          egs52_transform_memory_09efe6(param_3,puStack_14,uStack_12,uStack_10);
        }
        uStack_a = uStack_a - uStack_10;
        param_3 = param_3 + uStack_10;
      } while (uStack_a != 0);
      uVar8 = 0;
    }
  }
  else {
    bVar11 = 0;
    bVar7 = false;
    while (!bVar7) {
      uVar1 = (uint)bVar11 * 4 - 0x7d6;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = (uint)bVar11 * 4 - 0x7d4;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0 &&
          *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
      iVar10 = (uint)bVar11 * 4;
      uVar1 = iVar10 - 0x7da;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = (int)egs52_test_fault_bitmap + iVar10;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (param_2 < uVar2 ||
          param_2 == uVar2 && param_1 < *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
LAB_09e44e:
        bVar11 = bVar11 + 2;
      }
      else {
        uVar2 = param_1 + param_4;
        uVar4 = param_2 + CARRY2(param_1,(uint)param_4);
        uVar1 = iVar10 - 0x7d6;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar5 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
        uVar1 = iVar10 - 0x7d4;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar6 = uVar5 + 1;
        uVar1 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) + (uint)(0xfffe < uVar5);
        if ((uVar4 - uVar1 != (uint)(uVar2 < uVar6) || uVar2 != uVar6) &&
            (uVar1 <= uVar4 && (uVar4 != uVar1 || uVar2 >= uVar6))) goto LAB_09e44e;
        bVar7 = true;
      }
    }
    if (bVar7) {
      iVar10 = Ram00c34a;
      if (iVar10 == 0) {
        iVar10 = egs52_update_near_caa4_0a3ca8(param_1,param_4);
        Ram00c34a = iVar10;
        if (iVar10 == 0) {
          Ram00c34a = 0;
          uVar8 = 0x21;
        }
        else {
          uVar8 = 0x78;
        }
      }
      else {
        cVar9 = egs52_update_near_caa4_0a3d02(iVar10,param_3,param_4);
        if (cVar9 == '\x01') {
          Ram00c34a = 0;
          uVar8 = 0;
        }
        else {
          uVar8 = 0x78;
        }
      }
    }
    else {
      uVar8 = 0xff;
    }
  }
  return uVar8;
}


