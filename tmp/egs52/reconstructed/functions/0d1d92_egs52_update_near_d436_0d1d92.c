/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1d92; FLS offset 0x051d92.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1e36) */
/* WARNING: Removing unreachable block (ram,0x0d1e4e) */
/* WARNING: Removing unreachable block (ram,0x0d1e44) */
/* WARNING: Removing unreachable block (ram,0x0d1e40) */
/* WARNING: Removing unreachable block (ram,0x0d1e3c) */
/* WARNING: Removing unreachable block (ram,0x0d1e2c) */
/* WARNING: Removing unreachable block (ram,0x0d1e28) */
/* WARNING: Removing unreachable block (ram,0x0d1e24) */
/* WARNING: Removing unreachable block (ram,0x0d1e1e) */
/* WARNING: Removing unreachable block (ram,0x0d1e14) */
/* WARNING: Removing unreachable block (ram,0x0d1e10) */
/* WARNING: Removing unreachable block (ram,0x0d1e08) */
/* WARNING: Removing unreachable block (ram,0x0d1df6) */
/* WARNING: Removing unreachable block (ram,0x0d1df2) */
/* WARNING: Removing unreachable block (ram,0x0d1dec) */
/* WARNING: Removing unreachable block (ram,0x0d1de6) */
/* WARNING: Removing unreachable block (ram,0x0d1dde) */
/* WARNING: Removing unreachable block (ram,0x0d1dda) */
/* WARNING: Removing unreachable block (ram,0x0d1dd2) */
/* WARNING: Removing unreachable block (ram,0x0d1dce) */
/* WARNING: Removing unreachable block (ram,0x0d1dc6) */
/* WARNING: Removing unreachable block (ram,0x0d1dc2) */
/* WARNING: Removing unreachable block (ram,0x0d1db8) */
/* WARNING: Removing unreachable block (ram,0x0d1dae) */
/* WARNING: Removing unreachable block (ram,0x0d1d9a) */
/* WARNING: Removing unreachable block (ram,0x0d1d96) */
/* WARNING: Removing unreachable block (ram,0x0d1d92) */
/* WARNING: Removing unreachable block (ram,0x0d1dfe) */

void egs52_update_near_d436_0d1d92(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  int iVar12;
  
  uVar1 = Ram00f638;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar5 = UNK_00d579;
  if (((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1 << (bVar5 - 1 & 0xf)) == 0
     ) {
    uVar1 = Ram00fd4e;
    Ram00fd4e = uVar1 & 0xfffe;
  }
  else {
    uVar2 = Ram00fd4e;
    if ((((uVar2 & 1) == 0) && (cVar11 = UNK_00d577, cVar11 == '\x03')) &&
       (iVar4 = Ram00d4c2, -1 < iVar4)) {
      uVar2 = uVar1 + 4;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar3 = Ram00d496;
      uVar8 = Ram00d496;
      if (uVar2 == uVar8 || uVar2 < uVar3) {
        uVar2 = uVar1 + 2;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar8 = Ram00d508;
        if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) < uVar8) {
          uVar1 = uVar1 + 1;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar5 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
          bVar9 = UNK_00d570;
          bVar10 = UNK_00d570;
          if (bVar5 == bVar10 || bVar5 < bVar9) {
            bVar5 = UNK_00d579;
            iVar4 = Ram00f624;
            uVar1 = iVar4 + (uint)bVar5 * 2 + 0x7c;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar3 = Ram00d4d2;
            if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar3) {
              uVar1 = Ram00fd4e;
              Ram00fd4e = uVar1 | 1;
              UNK_00d436 = 0;
            }
            else {
              uVar1 = Ram00fd4a;
              if ((uVar1 & 2) == 0) {
                cVar11 = UNK_00d579;
                iVar4 = Ram00f634;
                uVar1 = iVar4 + 1;
                uVar2 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                iVar12 = egs52_update_near_d418_0d6f4e
                                   (cVar11 + -1,
                                    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
                iVar4 = Ram00d41c;
                if (iVar4 <= iVar12) {
                  iVar4 = Ram00f634;
                  uVar1 = iVar4 + 0x20;
                  uVar2 = 0x24;
                  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                    uVar2 = 3;
                  }
                  iVar4 = Ram00d414;
                  if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar4) {
                    uVar1 = Ram00fd4e;
                    Ram00fd4e = uVar1 | 1;
                    UNK_00d436 = 3;
                    goto LAB_0d1e56;
                  }
                }
                iVar4 = Ram00f634;
                uVar1 = iVar4 + 0x20;
                uVar2 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                iVar4 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
                iVar12 = Ram00d41c;
                iVar7 = Ram00d41c;
                if (iVar4 != iVar7 && iVar12 <= iVar4) {
                  uVar1 = Ram00fd4e;
                  Ram00fd4e = uVar1 | 1;
                  UNK_00d436 = 3;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0d1e56:
  uVar6 = Ram00fd4e;
  uVar1 = Ram00fd4e;
  uVar2 = Ram00fd4e;
  Ram00fd4e = uVar2 & 0xfffd | (uVar1 & 1) << 1;
  return;
}


