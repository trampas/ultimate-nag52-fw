/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093e10; FLS offset 0x013e10.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093ebc) */
/* WARNING: Removing unreachable block (ram,0x093e9c) */
/* WARNING: Removing unreachable block (ram,0x093e68) */
/* WARNING: Removing unreachable block (ram,0x093ef0) */
/* WARNING: Removing unreachable block (ram,0x093ec8) */
/* WARNING: Removing unreachable block (ram,0x093ec4) */
/* WARNING: Removing unreachable block (ram,0x093e38) */
/* WARNING: Removing unreachable block (ram,0x093e34) */
/* WARNING: Removing unreachable block (ram,0x093e20) */
/* WARNING: Removing unreachable block (ram,0x093e16) */
/* WARNING: Removing unreachable block (ram,0x093e46) */
/* WARNING: Removing unreachable block (ram,0x093e64) */
/* WARNING: Removing unreachable block (ram,0x093e8a) */

uchar egs52_update_near_c043_093e10(ushort param_1,ushort param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  byte bVar6;
  uchar uVar7;
  byte bVar8;
  
  bVar8 = UNK_00c064;
  if ((bVar8 & 4) == 0) {
    bVar8 = UNK_00c064;
    UNK_00c064 = bVar8 | 4;
    bVar8 = 0;
    bVar5 = false;
    while ((bVar8 < 0x10 && (!bVar5))) {
      iVar4 = (uint)bVar8 * 6;
      uVar1 = iVar4 - 0x900;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = iVar4 - 0x8fe;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if (param_2 - *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) ==
          (uint)(param_1 < uVar2) && param_1 == uVar2) {
        uVar1 = iVar4 - 0x8fc;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (param_3 == *(ushort *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          bVar5 = true;
        }
      }
      bVar8 = bVar8 + 1;
    }
    if (bVar5) {
      bVar8 = bVar8 - 1;
      UNK_00c043 = bVar8;
      bVar6 = UNK_00c040;
      if (((uint)bVar6 & 1 << (bVar8 & 0xf)) == 0) {
        uVar3 = (uint)bVar8 * 2 + 0xc044;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
        uVar7 = egs52_stage_request_words(param_1,param_2,param_3,uVar3);
        if (uVar7 != '\0') {
          bVar8 = UNK_00c064;
          UNK_00c064 = bVar8 & 0xfb;
        }
      }
      else {
        uVar7 = '\0';
        bVar8 = UNK_00c064;
        UNK_00c064 = bVar8 & 0xfb;
      }
    }
    else {
      UNK_00c043 = 0xf;
      Ram00c062 = 0;
      uVar7 = egs52_stage_request_words(param_1,param_2,param_3,0xc062);
      if (uVar7 != '\0') {
        bVar8 = UNK_00c064;
        UNK_00c064 = bVar8 & 0xfb;
      }
    }
  }
  else {
    uVar7 = '!';
  }
  return uVar7;
}


