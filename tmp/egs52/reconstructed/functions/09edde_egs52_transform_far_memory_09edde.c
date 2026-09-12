/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09edde; FLS offset 0x01edde.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x09eec2) */
/* WARNING: Removing unreachable block (ram,0x09eec0) */
/* WARNING: Removing unreachable block (ram,0x09eeb0) */
/* WARNING: Removing unreachable block (ram,0x09eeac) */
/* WARNING: Removing unreachable block (ram,0x09eed0) */
/* WARNING: Removing unreachable block (ram,0x09eece) */
/* WARNING: Removing unreachable block (ram,0x09eea2) */
/* WARNING: Removing unreachable block (ram,0x09ee9e) */
/* WARNING: Removing unreachable block (ram,0x09ee96) */
/* WARNING: Removing unreachable block (ram,0x09ee90) */
/* WARNING: Removing unreachable block (ram,0x09ee86) */
/* WARNING: Removing unreachable block (ram,0x09ee80) */
/* WARNING: Removing unreachable block (ram,0x09ee74) */
/* WARNING: Removing unreachable block (ram,0x09ee62) */
/* WARNING: Removing unreachable block (ram,0x09ee3a) */
/* WARNING: Removing unreachable block (ram,0x09ee36) */
/* WARNING: Removing unreachable block (ram,0x09ee26) */
/* WARNING: Removing unreachable block (ram,0x09ee04) */
/* WARNING: Removing unreachable block (ram,0x09ee00) */
/* WARNING: Removing unreachable block (ram,0x09ede6) */
/* WARNING: Removing unreachable block (ram,0x09eec8) */

void egs52_transform_far_memory_09edde(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  byte bVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  char cVar12;
  
  bVar6 = UNK_00c32c;
  if (param_1 < bVar6) {
    iVar9 = egs52_compute_from_near_c32e_09f018();
    uVar1 = Ram00f682;
    uVar7 = Ram00f684;
    lVar5 = (ulong)param_1 * 0xc;
    uVar3 = (uint)lVar5;
    iVar4 = uVar1 + 4 + uVar3;
    cVar12 = (char)((ulong)lVar5 >> 0x10);
    cVar10 = (char)uVar7 + (0xfffb < uVar1) + cVar12 + CARRY2(uVar1 + 4,uVar3);
    uVar2 = iVar9 * *(int *)CONCAT12(cVar10,iVar4);
    uVar7 = Ram00f682;
    uVar8 = Ram00f684;
    lVar5 = lVar5 + CONCAT22(uVar8,uVar7);
    uVar11 = *(uint *)((uint3)(uint)((ulong)lVar5 >> 0x10) << 0x10 | (uint3)(uint)lVar5);
    iVar9 = uVar11 + uVar2;
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(char *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) =
         (char)*(undefined2 *)
                ((uint3)(uint)((ulong)(lVar5 + 2) >> 0x10) << 0x10 | (uint3)(uint)(lVar5 + 2)) +
         CARRY2(uVar11,uVar2);
    uVar1 = param_2 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)((uint)iVar9 >> 8);
    uVar1 = param_2 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)iVar9;
    uVar1 = param_2 + 3;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) =
         (char)((uint)*(undefined2 *)CONCAT12(cVar10,iVar4) >> 8);
    uVar1 = param_2 + 4;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) =
         (char)*(undefined2 *)CONCAT12(cVar10,iVar4);
    iVar4 = Ram00c330;
    if (iVar4 == 0) {
      uVar1 = Ram00f682;
      uVar7 = Ram00f684;
      cVar12 = (char)uVar7 + (0xfff5 < uVar1) + cVar12 + CARRY2(uVar1 + 10,uVar3);
      *(undefined1 *)CONCAT12(cVar12,param_2 + 5) =
           *(undefined1 *)CONCAT12(cVar12,uVar1 + 10 + uVar3);
    }
    else {
      iVar4 = Ram00c330;
      param_1 = iVar4 + param_1;
      uVar1 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      param_2 = param_2 + 5;
      uVar3 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar3 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(param_2 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
    }
  }
  return;
}


