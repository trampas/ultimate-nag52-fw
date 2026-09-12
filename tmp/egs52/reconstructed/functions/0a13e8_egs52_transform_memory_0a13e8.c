/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a13e8; FLS offset 0x0213e8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a145a) */
/* WARNING: Removing unreachable block (ram,0x0a1454) */
/* WARNING: Removing unreachable block (ram,0x0a1470) */
/* WARNING: Removing unreachable block (ram,0x0a1418) */
/* WARNING: Removing unreachable block (ram,0x0a13f2) */
/* WARNING: Removing unreachable block (ram,0x0a1406) */
/* WARNING: Removing unreachable block (ram,0x0a148c) */
/* WARNING: Removing unreachable block (ram,0x0a1466) */
/* WARNING: Removing unreachable block (ram,0x0a14a4) */

undefined1 egs52_transform_memory_0a13e8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = Ram00f84e;
  if (iVar3 == 0) {
    uVar5 = 0xf8;
  }
  else {
    uVar7 = 0;
    do {
      iVar3 = uVar7 * 8;
      uVar1 = iVar3 + 0xc456;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = iVar3 + -0x3bb0 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
        uVar6 = param_1 & 0x7fff;
        uVar1 = param_1 & 8;
        param_1 = uVar6;
        if ((uVar1 != 0) && (cVar4 = egs52_transform_memory_0a4e9c(uVar7), cVar4 != '\0')) {
          param_1 = uVar6 | 0x8000;
        }
        if (((param_1 & 0x10) != 0) && (cVar4 = egs52_update_near_fd6c_0a4e2c(uVar7), cVar4 != '\0')
           ) {
          param_1 = param_1 | 0x8000;
        }
        uVar1 = uVar2 + 3;
        uVar6 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        if (*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar1 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) * 0x14 + 0x9300;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) != 0) {
            uVar1 = iVar3 + 0xc456;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            egs52_transform_memory_0a1dd8
                      (uVar7,*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),0);
          }
        }
        if ((param_1 & 0x8000) != 0) {
          uVar2 = (uVar7 >> 4) * 2 + 0xc43c;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar6 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          *(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 1 << uVar7 % 0x10;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x10);
    uVar5 = 0;
  }
  return uVar5;
}


