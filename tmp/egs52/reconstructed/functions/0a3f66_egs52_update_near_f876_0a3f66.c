/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3f66; FLS offset 0x023f66.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3fd0) */
/* WARNING: Removing unreachable block (ram,0x0a4052) */
/* WARNING: Removing unreachable block (ram,0x0a404e) */
/* WARNING: Removing unreachable block (ram,0x0a4046) */
/* WARNING: Removing unreachable block (ram,0x0a4044) */
/* WARNING: Removing unreachable block (ram,0x0a403e) */
/* WARNING: Removing unreachable block (ram,0x0a403a) */
/* WARNING: Removing unreachable block (ram,0x0a4034) */
/* WARNING: Removing unreachable block (ram,0x0a402e) */
/* WARNING: Removing unreachable block (ram,0x0a402a) */
/* WARNING: Removing unreachable block (ram,0x0a401a) */
/* WARNING: Removing unreachable block (ram,0x0a406a) */
/* WARNING: Removing unreachable block (ram,0x0a4066) */
/* WARNING: Removing unreachable block (ram,0x0a4064) */
/* WARNING: Removing unreachable block (ram,0x0a40ba) */
/* WARNING: Removing unreachable block (ram,0x0a40b6) */
/* WARNING: Removing unreachable block (ram,0x0a40b2) */
/* WARNING: Removing unreachable block (ram,0x0a407c) */
/* WARNING: Removing unreachable block (ram,0x0a4094) */
/* WARNING: Removing unreachable block (ram,0x0a4002) */
/* WARNING: Removing unreachable block (ram,0x0a408c) */
/* WARNING: Removing unreachable block (ram,0x0a4076) */
/* WARNING: Removing unreachable block (ram,0x0a3ff8) */
/* WARNING: Removing unreachable block (ram,0x0a3fea) */
/* WARNING: Removing unreachable block (ram,0x0a3fe6) */
/* WARNING: Removing unreachable block (ram,0x0a3fca) */
/* WARNING: Removing unreachable block (ram,0x0a3fc6) */
/* WARNING: Removing unreachable block (ram,0x0a3fde) */
/* WARNING: Removing unreachable block (ram,0x0a3fc0) */
/* WARNING: Removing unreachable block (ram,0x0a3fae) */
/* WARNING: Removing unreachable block (ram,0x0a3faa) */
/* WARNING: Removing unreachable block (ram,0x0a3fa6) */
/* WARNING: Removing unreachable block (ram,0x0a3f9e) */
/* WARNING: Removing unreachable block (ram,0x0a3f98) */
/* WARNING: Removing unreachable block (ram,0x0a3f94) */
/* WARNING: Removing unreachable block (ram,0x0a3f90) */
/* WARNING: Removing unreachable block (ram,0x0a3f8c) */
/* WARNING: Removing unreachable block (ram,0x0a3f84) */
/* WARNING: Removing unreachable block (ram,0x0a3f7e) */
/* WARNING: Removing unreachable block (ram,0x0a3f7a) */
/* WARNING: Removing unreachable block (ram,0x0a3f6a) */
/* WARNING: Removing unreachable block (ram,0x0a3fb6) */
/* WARNING: Removing unreachable block (ram,0x0a4080) */
/* WARNING: Removing unreachable block (ram,0x0a4084) */
/* WARNING: Removing unreachable block (ram,0x0a4098) */
/* WARNING: Removing unreachable block (ram,0x0a409c) */
/* WARNING: Removing unreachable block (ram,0x0a40a2) */

int egs52_update_near_f876_0a3f66(uint param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  cVar6 = UNK_00f876;
  if (cVar6 == '\0') {
    UNK_00f876 = 1;
    cVar6 = UNK_00e101;
    if (cVar6 == '\0') {
      UNK_00e100 = 0;
      UNK_00e101 = 0xfc;
      UNK_00e102 = 1;
      UNK_00e1fc = 0;
      UNK_00e1fd = 0xfc;
      UNK_00e1fe = 2;
      Ram00e200 = 0xf8;
      Ram00e202 = 0;
      Ram00e204 = 0;
    }
    if (param_1 == 0) {
      UNK_00f876 = 0;
    }
    else {
      uVar10 = Ram00e200;
      uVar11 = Ram00e200;
      if (param_1 == uVar11 || param_1 < uVar10) {
        uVar10 = Ram00e202;
      }
      else {
        iVar9 = Ram00e204;
        iVar7 = Ram00e202;
        if (iVar9 == iVar7) {
          UNK_00f876 = 0;
          return 0;
        }
        uVar10 = 0;
      }
      Ram00e204 = 0xfc;
      Ram00e200 = 0;
      while (uVar11 = uVar10, uVar11 < 0xfc) {
        uVar4 = uVar11 + 0xe101;
        uVar10 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar10 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        bVar3 = *(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar4 & 0x3fff));
        uVar10 = (uint)bVar3;
        uVar5 = uVar11 + 0xe102;
        uVar1 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) == '\x01') {
          uVar1 = (uVar10 - uVar11) - 4;
          if (param_1 + 5 < uVar1) {
            uVar1 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 2;
            uVar12 = uVar11 + param_1 + 5 & 0xfffe;
            uVar5 = uVar12 + 0xe102;
            uVar1 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 2;
            uVar1 = uVar12 + 0xe100;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)uVar11;
            uVar1 = uVar12 + 0xe101;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = bVar3;
            uVar1 = 0x24;
            if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = (char)uVar12;
            uVar4 = uVar10 + 0xe100;
            uVar1 = 0x24;
            if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = (char)uVar12;
            uVar4 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) = 1;
            Ram00e202 = uVar12;
            Ram00e200 = (uVar10 - uVar12) + -4;
            UNK_00f876 = 0;
            return uVar11 + 0xe104;
          }
          if (param_1 <= uVar1) {
            uVar10 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar10 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar5 & 0x3fff)) = 2;
            Ram00e202 = 0;
            UNK_00f876 = 0;
            return uVar11 + 0xe104;
          }
          uVar12 = Ram00e200;
          if (uVar12 <= uVar1) {
            Ram00e202 = uVar11;
            Ram00e200 = uVar1;
          }
          uVar1 = uVar10 + 0xe102;
          uVar12 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar12 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar12 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar12 = 3;
          }
          if (*(char *)((uint3)uVar12 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
            uVar10 = uVar10 + 0xe101;
            uVar1 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff));
            uVar10 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar10 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar5 & 0x3fff)) = 2;
            uVar10 = 0x24;
            if ((((uVar4 & 0xc000) != 0) && (uVar10 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            *(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar4 & 0x3fff)) = bVar3;
            uVar10 = bVar3 + 0xe100;
            uVar4 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar4 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar10 & 0x3fff)) = (char)uVar11;
            uVar10 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar10 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar5 & 0x3fff)) = 1;
            uVar10 = uVar11;
          }
        }
      }
      uVar8 = Ram00e202;
      Ram00e204 = uVar8;
      UNK_00f876 = 0;
    }
  }
  return 0;
}


