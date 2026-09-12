/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f592; FLS offset 0x01f592.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Removing unreachable block (ram,0x09f6d8) */
/* WARNING: Removing unreachable block (ram,0x09f6d6) */
/* WARNING: Removing unreachable block (ram,0x09f6a4) */
/* WARNING: Removing unreachable block (ram,0x09f6c4) */
/* WARNING: Removing unreachable block (ram,0x09f6c8) */
/* WARNING: Removing unreachable block (ram,0x09f6bc) */
/* WARNING: Removing unreachable block (ram,0x09f6b8) */
/* WARNING: Removing unreachable block (ram,0x09f69c) */
/* WARNING: Removing unreachable block (ram,0x09f698) */
/* WARNING: Removing unreachable block (ram,0x09f684) */
/* WARNING: Removing unreachable block (ram,0x09f680) */
/* WARNING: Removing unreachable block (ram,0x09f672) */
/* WARNING: Removing unreachable block (ram,0x09f66e) */
/* WARNING: Removing unreachable block (ram,0x09f66a) */
/* WARNING: Removing unreachable block (ram,0x09f666) */
/* WARNING: Removing unreachable block (ram,0x09f628) */
/* WARNING: Removing unreachable block (ram,0x09f624) */
/* WARNING: Removing unreachable block (ram,0x09f654) */
/* WARNING: Removing unreachable block (ram,0x09f650) */
/* WARNING: Removing unreachable block (ram,0x09f664) */
/* WARNING: Removing unreachable block (ram,0x09f660) */
/* WARNING: Removing unreachable block (ram,0x09f65c) */
/* WARNING: Removing unreachable block (ram,0x09f658) */
/* WARNING: Removing unreachable block (ram,0x09f642) */
/* WARNING: Removing unreachable block (ram,0x09f63e) */
/* WARNING: Removing unreachable block (ram,0x09f616) */
/* WARNING: Removing unreachable block (ram,0x09f612) */
/* WARNING: Removing unreachable block (ram,0x09f5fe) */
/* WARNING: Removing unreachable block (ram,0x09f5fa) */
/* WARNING: Removing unreachable block (ram,0x09f5f2) */
/* WARNING: Removing unreachable block (ram,0x09f5f0) */
/* WARNING: Removing unreachable block (ram,0x09f5e4) */
/* WARNING: Removing unreachable block (ram,0x09f5e0) */
/* WARNING: Removing unreachable block (ram,0x09f5cc) */
/* WARNING: Removing unreachable block (ram,0x09f5c8) */
/* WARNING: Removing unreachable block (ram,0x09f5ba) */
/* WARNING: Removing unreachable block (ram,0x09f5b4) */
/* WARNING: Removing unreachable block (ram,0x09f5b0) */
/* WARNING: Removing unreachable block (ram,0x09f5a8) */
/* WARNING: Removing unreachable block (ram,0x09f5a2) */
/* WARNING: Removing unreachable block (ram,0x09f596) */
/* WARNING: Removing unreachable block (ram,0x09f5da) */
/* WARNING: Removing unreachable block (ram,0x09f694) */
/* WARNING: Removing unreachable block (ram,0x09f6b4) */

undefined2 egs52_update_near_c3a8_09f592(uint param_1,uint param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  byte bVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  
  bVar9 = UNK_00c3a2;
  if ((bVar9 & 2) == 0) {
    uVar12 = *(undefined2 *)CONCAT12(param_3 + (0xfff1 < param_2),param_2 + 0xe);
  }
  else {
    uVar2 = param_1 + 2;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar4 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar2 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff));
    iVar7 = uVar4 - uVar2;
    iVar13 = -(uint)(uVar4 < uVar2);
    Ram00c3a8 = iVar7;
    Ram00c3aa = iVar13;
    lVar8 = (ulong)*(uint *)CONCAT12(param_3,param_2) * CONCAT22(iVar13,iVar7);
    Ram00c3a4 = (int)lVar8;
    Ram00c3a6 = (int)((ulong)lVar8 >> 0x10);
    uVar12 = Ram00c3a8;
    uVar10 = Ram00c3aa;
    uVar4 = param_1 + 4;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = param_1 + 6;
    uVar5 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    lVar8 = (ulong)*(uint *)CONCAT12(param_3 + (0xfffd < param_2),param_2 + 2) *
            CONCAT22(uVar10,uVar12) +
            CONCAT22(*(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff)),
                     *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)));
    Ram00c3a8 = (int)lVar8;
    Ram00c3aa = (int)((ulong)lVar8 >> 0x10);
    uVar2 = param_2 + 4;
    cVar6 = param_3 + (0xfffb < param_2);
    iVar13 = *(int *)CONCAT12(cVar6 + (0xfffd < uVar2),param_2 + 6);
    uVar3 = Ram00c3a8;
    bVar1 = *(uint *)CONCAT12(cVar6,uVar2) < uVar3;
    iVar7 = Ram00c3aa;
    if ((int)((iVar13 - iVar7) - (uint)bVar1) < 0 ==
        (SBORROW2(iVar13,iVar7) != SBORROW2(iVar13 - iVar7,(uint)bVar1))) {
      uVar2 = param_2 + 8;
      cVar6 = param_3 + (0xfff7 < param_2);
      uVar11 = *(uint *)CONCAT12(cVar6,uVar2);
      iVar13 = *(int *)CONCAT12(cVar6 + (0xfffd < uVar2),param_2 + 10);
      uVar5 = Ram00c3a8;
      iVar7 = Ram00c3aa;
      uVar3 = (uint)(uVar11 < uVar5);
      if (iVar13 - iVar7 == uVar3 && uVar11 == uVar5 ||
          (int)((iVar13 - iVar7) - uVar3) < 0 !=
          (SBORROW2(iVar13,iVar7) != SBORROW2(iVar13 - iVar7,(uint)(uVar11 < uVar5)))) {
        uVar12 = Ram00c3a8;
        uVar10 = Ram00c3aa;
        param_1 = param_1 + 6;
        uVar2 = 0x24;
        if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) = uVar10;
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar12;
      }
      else {
        uVar12 = *(undefined2 *)CONCAT12(cVar6,uVar2);
        param_1 = param_1 + 6;
        uVar3 = 0x24;
        if ((((param_1 & 0xc000) != 0) && (uVar3 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(param_1 & 0x3fff)) =
             *(undefined2 *)CONCAT12(cVar6 + (0xfffd < uVar2),param_2 + 10);
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar12;
      }
    }
    else {
      uVar12 = *(undefined2 *)CONCAT12(cVar6,uVar2);
      param_1 = param_1 + 6;
      uVar3 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar3 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(param_1 & 0x3fff)) =
           *(undefined2 *)CONCAT12(cVar6 + (0xfffd < uVar2),param_2 + 6);
      uVar2 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar12;
    }
    uVar2 = Ram00c3a4;
    iVar7 = Ram00c3a6;
    uVar4 = Ram00c3a8;
    iVar13 = Ram00c3aa;
    lVar8 = CONCAT22(iVar7 + iVar13 + (uint)CARRY2(uVar2,uVar4),uVar2 + uVar4) / 0x10;
    Ram00c3a8 = (int)lVar8;
    Ram00c3aa = (int)((ulong)lVar8 >> 0x10);
    cVar6 = param_3 + (0xfff3 < param_2);
    uVar2 = Ram00c3a8;
    bVar1 = *(uint *)CONCAT12(cVar6,param_2 + 0xc) < uVar2;
    iVar7 = Ram00c3aa;
    if ((int)(-(uint)bVar1 - iVar7) < 0 == (SBORROW2(0,iVar7) != SBORROW2(-iVar7,(uint)bVar1))) {
      param_3 = param_3 + (0xfff1 < param_2);
      uVar2 = *(uint *)CONCAT12(param_3,param_2 + 0xe);
      uVar3 = Ram00c3a8;
      iVar7 = Ram00c3aa;
      uVar4 = (uint)(uVar2 < uVar3);
      if (-iVar7 == uVar4 && uVar2 == uVar3 ||
          (int)(-iVar7 - uVar4) < 0 != (SBORROW2(0,iVar7) != SBORROW2(-iVar7,(uint)(uVar2 < uVar3)))
         ) {
        uVar12 = Ram00c3a8;
      }
      else {
        uVar12 = *(undefined2 *)CONCAT12(param_3,param_2 + 0xe);
      }
    }
    else {
      uVar12 = *(undefined2 *)CONCAT12(cVar6,param_2 + 0xc);
    }
  }
  return uVar12;
}


