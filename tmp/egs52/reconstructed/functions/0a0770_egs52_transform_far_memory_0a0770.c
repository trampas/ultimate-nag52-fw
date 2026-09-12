/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a0770; FLS offset 0x020770.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a0806) */
/* WARNING: Removing unreachable block (ram,0x0a0802) */
/* WARNING: Removing unreachable block (ram,0x0a0800) */
/* WARNING: Removing unreachable block (ram,0x0a07f6) */
/* WARNING: Removing unreachable block (ram,0x0a07f4) */
/* WARNING: Removing unreachable block (ram,0x0a07ec) */
/* WARNING: Removing unreachable block (ram,0x0a07e0) */
/* WARNING: Removing unreachable block (ram,0x0a07d8) */
/* WARNING: Removing unreachable block (ram,0x0a07ce) */
/* WARNING: Removing unreachable block (ram,0x0a07cc) */
/* WARNING: Removing unreachable block (ram,0x0a07c0) */
/* WARNING: Removing unreachable block (ram,0x0a07b4) */
/* WARNING: Removing unreachable block (ram,0x0a0796) */
/* WARNING: Removing unreachable block (ram,0x0a0792) */

undefined2 egs52_transform_far_memory_0a0770(byte param_1,undefined1 param_2)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  undefined2 uVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  
  uVar4 = egs52_get_operating_mask();
  if ((uVar4 & 0x400) == 0) {
    uVar6 = (uint)param_1;
    uVar8 = 1;
    uVar9 = 0;
    while (bVar1 = uVar6 != 0, uVar6 = uVar6 - 1, bVar1) {
      bVar1 = CARRY2(uVar8,uVar8);
      uVar8 = uVar8 * 2;
      uVar9 = uVar9 * 2 + (uint)bVar1;
    }
    uVar6 = Ram00c068;
    uVar2 = Ram00c06a;
    if ((uVar8 & uVar6) == 0 && (uVar9 & uVar2) == 0) {
      uVar5 = 0;
    }
    else {
      uVar4 = egs52_read_indexed_record_word('\x02');
      if ((uVar4 & 0x300) == 0x200) {
        uVar5 = 0;
      }
      else {
        bVar3 = UNK_00f842;
        uVar9 = (uint)bVar3 * 0x1c + 0x83c2;
        uVar6 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar6 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) + (uint)param_1 * 4;
        uVar9 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar9 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        uVar8 = uVar6 + 2;
        uVar6 = *(uint *)((uint3)uVar9 << 0xe | (uint3)(uVar6 & 0x3fff));
        uVar9 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar9 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        egs52_transform_far_memory_0a6006
                  (param_1,*(undefined2 *)
                            CONCAT12((char)*(undefined2 *)
                                            ((uint3)uVar9 << 0xe | (uint3)(uVar8 & 0x3fff)) +
                                     (0xfff1 < uVar6),uVar6 + 0xe),param_2);
        bVar3 = UNK_00f842;
        uVar9 = (uint)bVar3 * 0x1c + 0x83c2;
        uVar6 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar6 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) + (uint)param_1 * 4;
        uVar9 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar9 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        uVar8 = uVar6 + 2;
        uVar6 = *(uint *)((uint3)uVar9 << 0xe | (uint3)(uVar6 & 0x3fff));
        uVar9 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar9 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        cVar7 = (char)*(undefined2 *)((uint3)uVar9 << 0xe | (uint3)(uVar8 & 0x3fff)) +
                (0xffef < uVar6);
        uVar6 = *(uint *)CONCAT12(cVar7,uVar6 + 0x10);
        uVar9 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar9 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)CONCAT12(cVar7,uVar6) | 1;
        uVar5 = 1;
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


