/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x083040; FLS offset 0x003040.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0830fa) */
/* WARNING: Removing unreachable block (ram,0x0830f6) */
/* WARNING: Removing unreachable block (ram,0x0830ea) */
/* WARNING: Removing unreachable block (ram,0x0830e8) */
/* WARNING: Removing unreachable block (ram,0x0830a6) */
/* WARNING: Removing unreachable block (ram,0x0830a2) */
/* WARNING: Removing unreachable block (ram,0x083094) */
/* WARNING: Removing unreachable block (ram,0x083084) */
/* WARNING: Removing unreachable block (ram,0x083060) */
/* WARNING: Removing unreachable block (ram,0x083064) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 egs52_compute_from_near_fdee_083040(void)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  uint uStack_a;
  
  cVar6 = '\0';
  uVar3 = 0x3fe8;
  cVar4 = '\b';
  uStack_a = 0;
  uVar7 = 62000;
  do {
    uVar5 = uVar7;
    if (*(char *)CONCAT12(cVar4,uVar3) != *(char *)CONCAT12(cVar6,uVar5)) {
      return 2;
    }
    bVar1 = 0xfffe < uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = cVar4 + bVar1;
    uVar7 = uVar5 + 1;
    cVar6 = cVar6 + (0xfffe < uVar5);
    uStack_a = uStack_a + 1;
  } while (uStack_a < 6);
  if ((*(char *)CONCAT12(cVar6,uVar7) == 'M') &&
     (*(char *)CONCAT12(cVar6 + (0xfffe < uVar7),uVar5 + 2) == 'T')) {
    *(undefined2 *)((uint3)((uint)&uStack_a & 0x3fff) | 0xc000) = uRam00f236;
    uVar3 = uRam00f228;
    for (uVar7 = uRam00f22a;
        uVar7 - uRam00f22e == (uint)(uVar3 < uRam00f22c) && uVar3 == uRam00f22c ||
        (uVar7 < uRam00f22e || uVar7 == uRam00f22e && uVar3 < uRam00f22c); uVar7 = uVar7 + bVar1) {
      egs52_transform_far_memory_080f5e(uVar3,uVar7,&uStack_a);
      bVar1 = 0xfffe < uVar3;
      uVar3 = uVar3 + 1;
    }
    if (*(int *)ZEXT23(&uStack_a) == _SUB_00f224) {
      uVar3 = Ram00fdee;
      if ((uVar3 & 1) == 0) {
        (*(code *)((uint3)uRam090028 << 0x10 | (uint3)uRam090026))();
      }
      func_0x00f238();
      uVar2 = 0;
    }
    else {
      uVar2 = 0xf201;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


