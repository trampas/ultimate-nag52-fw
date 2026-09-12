/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2a92; FLS offset 0x022a92.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2b2e) */
/* WARNING: Removing unreachable block (ram,0x0a2b2c) */
/* WARNING: Removing unreachable block (ram,0x0a2b26) */
/* WARNING: Removing unreachable block (ram,0x0a2b12) */
/* WARNING: Removing unreachable block (ram,0x0a2af8) */
/* WARNING: Removing unreachable block (ram,0x0a2ab6) */
/* WARNING: Removing unreachable block (ram,0x0a2aae) */
/* WARNING: Removing unreachable block (ram,0x0a2aa0) */
/* WARNING: Removing unreachable block (ram,0x0a2b36) */

undefined1 egs52_transform_memory_0a2a92(byte param_1,uint param_2)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar2;
  
  uVar3 = param_2 + 0x25;
  uVar8 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  if (*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) < 3) {
    uVar8 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar8 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    if (*(byte *)((uint3)uVar8 << 0xe | (uint3)(param_2 & 0x3fff)) < 0x80) {
      uVar8 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar8 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      if (*(char *)((uint3)uVar8 << 0xe | (uint3)(param_2 & 0x3fff)) != '\0') {
        if (param_1 == 0xff) {
          param_1 = egs52_update_near_fd6c_0a2b70(0,0);
        }
        if (param_1 != 0xfe) {
          iVar4 = (uint)param_1 * 0x38;
          uVar6 = iVar4 + 0xc608;
          uVar8 = 0x24;
          if ((((param_2 & 0xc000) != 0) && (uVar8 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(param_2 & 0x3fff));
          uVar8 = 0;
          do {
            uVar6 = param_2 + 1 + uVar8 * 0x12;
            uVar5 = iVar4 + -0x39f7 + uVar8 * 0x12;
            uVar7 = 0;
            do {
              uVar1 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              uVar2 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
              uVar6 = uVar6 + 1;
              uVar5 = uVar5 + 1;
              uVar7 = uVar7 + 1;
            } while (uVar7 < 0x12);
            uVar8 = uVar8 + 1;
          } while (uVar8 < 2);
          uVar8 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          if (*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) < 2) {
            uVar8 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar8 = 3;
            }
            uVar6 = iVar4 + 0xc63f;
            uVar5 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff));
          }
          else {
            uVar8 = iVar4 + 0xc63f;
            uVar3 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar3 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar8 & 0x3fff)) = 1;
          }
          return 0;
        }
        return 0xfd;
      }
    }
  }
  return 0xf9;
}


