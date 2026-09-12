/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a08ee; FLS offset 0x0208ee.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a0976) */
/* WARNING: Removing unreachable block (ram,0x0a096e) */
/* WARNING: Removing unreachable block (ram,0x0a0966) */
/* WARNING: Removing unreachable block (ram,0x0a095c) */
/* WARNING: Removing unreachable block (ram,0x0a0952) */
/* WARNING: Removing unreachable block (ram,0x0a094a) */
/* WARNING: Removing unreachable block (ram,0x0a0942) */
/* WARNING: Removing unreachable block (ram,0x0a093a) */
/* WARNING: Removing unreachable block (ram,0x0a0936) */
/* WARNING: Removing unreachable block (ram,0x0a092c) */
/* WARNING: Removing unreachable block (ram,0x0a0928) */
/* WARNING: Removing unreachable block (ram,0x0a0918) */
/* WARNING: Removing unreachable block (ram,0x0a0914) */
/* WARNING: Removing unreachable block (ram,0x0a0902) */
/* WARNING: Removing unreachable block (ram,0x0a08fa) */
/* WARNING: Removing unreachable block (ram,0x0a08f2) */
/* WARNING: Removing unreachable block (ram,0x0a0908) */
/* WARNING: Removing unreachable block (ram,0x0a0962) */

void egs52_update_near_c34e_0a08ee(byte param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  
  if (param_1 < bRam0b044a) {
    uVar1 = Ram00c34e;
    if (((uVar1 & 2) == 0) && (bVar9 = UNK_00f842, param_1 != bVar9)) {
      uVar1 = Ram00c34e;
      Ram00c34e = uVar1 & 0xfffe;
      uVar1 = Ram00c34e;
      Ram00c34e = uVar1 | 2;
      UNK_00f842 = param_1;
      uVar1 = Ram00c34e;
      Ram00c34e = uVar1 & 0xfff;
      uVar1 = Ram00c34e;
      Ram00c34e = uVar1 | (uint)param_1 << 0xc;
    }
    else {
      bVar9 = UNK_00f842;
      iVar7 = (uint)bVar9 * 0x1c;
      uVar1 = iVar7 + 0x83be;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar5 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = iVar7 + 0x83c0;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar8 = (uint)param_1 * 0x1c;
      uVar2 = iVar8 + 0x83be;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar6 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar2 = iVar8 + 0x83c0;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) -
          *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == (uint)(uVar5 < uVar6) &&
          uVar5 == uVar6) {
        uVar1 = iVar7 + 0x83c2;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar5 = iVar8 + 0x83c2;
        uVar2 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) ==
            *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff))) {
          UNK_00f842 = param_1;
          uVar1 = Ram00c34e;
          Ram00c34e = uVar1 & 0xfff;
          uVar1 = Ram00c34e;
          Ram00c34e = uVar1 | (uint)param_1 << 0xc;
        }
      }
    }
  }
  return;
}


