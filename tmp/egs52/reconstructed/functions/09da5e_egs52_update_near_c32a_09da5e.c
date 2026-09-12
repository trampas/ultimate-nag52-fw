/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09da5e; FLS offset 0x01da5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Removing unreachable block (ram,0x09db0e) */
/* WARNING: Removing unreachable block (ram,0x09daca) */
/* WARNING: Removing unreachable block (ram,0x09dabc) */
/* WARNING: Removing unreachable block (ram,0x09da92) */
/* WARNING: Removing unreachable block (ram,0x09dab6) */
/* WARNING: Removing unreachable block (ram,0x09da6a) */
/* WARNING: Removing unreachable block (ram,0x09db12) */
/* WARNING: Removing unreachable block (ram,0x09daec) */
/* WARNING: Removing unreachable block (ram,0x09dace) */

undefined1 egs52_update_near_c32a_09da5e(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  uchar uVar5;
  uchar uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 uVar9;
  int iVar10;
  
  UNK_00c32a = 0x10;
  uVar7 = egs52_compute_from_near_c06e_094d98();
  if ((uVar7 & 0x100) == 0) {
    egs52_update_operating_masks(0x40,2);
  }
  uVar5 = egs52_disable_interrupts_save();
  uVar9 = 0;
  iVar10 = 0;
  while( true ) {
    uVar7 = iVar10 * 4 + 0x782;
    uVar1 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff)) == 0) break;
    uVar7 = iVar10 * 4 + 0x784;
    uVar1 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff)) == 0) break;
    uVar7 = iVar10 * 4 + 0x782;
    uVar1 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar7 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar6 = egs52_boot_request_65(uVar7 & 0x3fff | uVar1 << 0xe,uVar1 >> 2);
    if (uVar6 == '\0') {
      uVar9 = 0x42;
    }
    iVar10 = iVar10 + 1;
  }
  for (uVar7 = 0; bVar3 = UNK_00c32c, uVar7 < bVar3; uVar7 = uVar7 + 1) {
    uVar2 = Ram00f682;
    uVar4 = Ram00f684;
    uVar1 = (uint)((ulong)uVar7 * 0xc);
    uVar1 = *(uint *)CONCAT12((char)uVar4 + (0xfff7 < uVar2) + (char)((ulong)uVar7 * 0xc >> 0x10) +
                              CARRY2(uVar2 + 8,uVar1),uVar2 + 8 + uVar1);
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar8 = uVar1 & 0x3fff | uVar2 << 0xe;
    if ((uVar2 >> 2 != 0 || 0xf5d7 < uVar8) && (uVar2 >> 2 == 0 && uVar8 < 0xf6ad)) {
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    }
  }
  if (uVar5 != '\0') {
    egs52_enable_interrupts();
  }
  egs52_update_fault_status(0x30,3);
  return uVar9;
}


