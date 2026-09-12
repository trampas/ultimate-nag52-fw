/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a16c8; FLS offset 0x0216c8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1706) */
/* WARNING: Removing unreachable block (ram,0x0a17b6) */
/* WARNING: Removing unreachable block (ram,0x0a16e6) */
/* WARNING: Removing unreachable block (ram,0x0a16fa) */
/* WARNING: Removing unreachable block (ram,0x0a1774) */
/* WARNING: Removing unreachable block (ram,0x0a16d2) */
/* WARNING: Removing unreachable block (ram,0x0a175e) */
/* WARNING: Removing unreachable block (ram,0x0a1780) */
/* WARNING: Removing unreachable block (ram,0x0a1762) */
/* WARNING: Removing unreachable block (ram,0x0a17c8) */
/* WARNING: Removing unreachable block (ram,0x0a1768) */
/* WARNING: Removing unreachable block (ram,0x0a179e) */

undefined2 egs52_update_near_f84e_0a16c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  undefined2 uVar8;
  byte bVar9;
  uint uVar10;
  
  iVar5 = Ram00f84e;
  if (iVar5 == 0) {
    uVar8 = 0xf8;
  }
  else {
    uVar10 = 0;
    do {
      iVar5 = uVar10 * 8;
      uVar1 = iVar5 + 0xc456;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar4 = iVar5 + -0x3bb0 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
      param_1 = param_1 & 0x7fff;
      uVar1 = uVar4 + 1;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar9 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      if (bVar9 != 0xff) {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar3 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
        if ((char)param_1 == '\x01') {
          param_1 = param_1 | 0x8000;
          cVar6 = egs52_register_arithmetic_0a233e(uVar3,uVar3);
          if (cVar6 == '\x01') {
            bVar9 = bVar9 & 0xde | 0x10;
          }
          else {
            bVar9 = bVar9 & 0xce;
          }
        }
        if (((bVar9 & 0x40) == 0) && (cVar6 = egs52_update_near_fd6c_0a4e2c(uVar10), cVar6 != '\0'))
        {
          param_1 = param_1 | 0x8000;
        }
        if ((((char)param_1 == '\x01') &&
            (iVar7 = egs52_compute_from_near_c504_0a20ea(), iVar7 != 0)) &&
           (cVar6 = egs52_transform_memory_0a4e9c(uVar10), cVar6 != '\0')) {
          param_1 = param_1 | 0x8000;
        }
        uVar1 = uVar4 + 1;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = bVar9;
        uVar1 = uVar4 + 3;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar1 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) * 0x14 + 0x9300;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) != 0) {
            uVar1 = iVar5 + 0xc456;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            egs52_transform_memory_0a1dd8
                      (uVar10,*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),0);
            param_1 = param_1 | 0x8000;
          }
        }
        if ((param_1 & 0x8000) != 0) {
          uVar2 = (uVar10 >> 4) * 2 + 0xc43c;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar4 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 1 << uVar10 % 0x10;
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x10);
    if ((char)param_1 == '\x01') {
      Ram00f84e = 2;
    }
    uVar8 = 0;
  }
  return uVar8;
}


