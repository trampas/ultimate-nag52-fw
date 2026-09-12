/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f6de; FLS offset 0x01f6de.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f702) */
/* WARNING: Removing unreachable block (ram,0x09f7ca) */
/* WARNING: Removing unreachable block (ram,0x09f7c6) */
/* WARNING: Removing unreachable block (ram,0x09f74c) */
/* WARNING: Removing unreachable block (ram,0x09f76c) */
/* WARNING: Removing unreachable block (ram,0x09f794) */
/* WARNING: Removing unreachable block (ram,0x09f7b0) */
/* WARNING: Removing unreachable block (ram,0x09f6f0) */
/* WARNING: Removing unreachable block (ram,0x09f72a) */
/* WARNING: Removing unreachable block (ram,0x09f706) */

undefined1 egs52_transform_memory_09f6de(byte param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  byte bVar8;
  
  uVar4 = param_1 + 0xc3ac;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
  if (param_2 == '\0') {
    __atomic(2);
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) | 0x80;
  }
  else if (param_2 == '\x03') {
    bVar6 = bVar3 >> 3;
    iVar5 = (uint)(bVar3 >> 4) << 0xf;
    iVar7 = Ram00f84c;
    if (iVar7 == 2) {
      bVar8 = egs52_update_near_fd6c_0a1220(param_1);
      if ((bVar8 == 0xff) || ((bVar8 & 0x40) == 0)) {
        if ((bVar6 & 1) == 0) {
          egs52_transform_far_memory_0a290e(param_1);
        }
        if (((bVar6 & 1) == 0) && ((bVar3 >> 2 & 1) != 0)) {
          egs52_update_near_fd6c_0a2728(param_1);
          uVar1 = 0x24;
          if (((uVar4 & 0xc000) != 0) &&
             ((uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000 &&
              (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)))) {
            uVar1 = 3;
          }
          egs52_update_near_c44e_0a18cc
                    (param_1,*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) | 1);
        }
        else if (((iVar5 != 0) && ((bVar8 & 1) == 0)) && (bVar8 != 0xff)) {
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          egs52_update_near_c44e_0a18cc
                    (param_1,*(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)));
        }
      }
      else if ((bVar3 >> 2 & 1) == 0) {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        egs52_update_near_c44e_0a18cc
                  (param_1,*(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)));
        if ((bVar6 & 1) == 0) {
          egs52_transform_far_memory_0a290e(param_1);
        }
      }
      else if ((iVar5 != 0) && ((bVar8 & 1) == 0)) {
        uVar1 = 0x24;
        if (((uVar4 & 0xc000) != 0) &&
           ((uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000))
           )) {
          uVar1 = 3;
        }
        egs52_update_near_c44e_0a18cc
                  (param_1,*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) | 1);
      }
      if ((bVar6 & 1) != 0) {
        egs52_update_near_fd6c_0a2550(param_1,1);
      }
    }
    __atomic(3);
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) & 0x7f;
  }
  return 0;
}


