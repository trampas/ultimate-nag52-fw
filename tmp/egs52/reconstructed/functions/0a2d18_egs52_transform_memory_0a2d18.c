/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2d18; FLS offset 0x022d18.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2f7c) */
/* WARNING: Removing unreachable block (ram,0x0a2f56) */
/* WARNING: Removing unreachable block (ram,0x0a2f52) */
/* WARNING: Removing unreachable block (ram,0x0a2f46) */
/* WARNING: Removing unreachable block (ram,0x0a2f38) */
/* WARNING: Removing unreachable block (ram,0x0a2f06) */
/* WARNING: Removing unreachable block (ram,0x0a2f00) */
/* WARNING: Removing unreachable block (ram,0x0a2ef6) */
/* WARNING: Removing unreachable block (ram,0x0a2eda) */
/* WARNING: Removing unreachable block (ram,0x0a2ec8) */
/* WARNING: Removing unreachable block (ram,0x0a2ec6) */
/* WARNING: Removing unreachable block (ram,0x0a2ebc) */
/* WARNING: Removing unreachable block (ram,0x0a2eb4) */
/* WARNING: Removing unreachable block (ram,0x0a2eac) */
/* WARNING: Removing unreachable block (ram,0x0a2ea2) */
/* WARNING: Removing unreachable block (ram,0x0a2e76) */
/* WARNING: Removing unreachable block (ram,0x0a2e70) */
/* WARNING: Removing unreachable block (ram,0x0a2e62) */
/* WARNING: Removing unreachable block (ram,0x0a2dc0) */
/* WARNING: Removing unreachable block (ram,0x0a2de4) */
/* WARNING: Removing unreachable block (ram,0x0a2d58) */
/* WARNING: Removing unreachable block (ram,0x0a2de6) */
/* WARNING: Removing unreachable block (ram,0x0a2d7c) */
/* WARNING: Removing unreachable block (ram,0x0a2e44) */
/* WARNING: Removing unreachable block (ram,0x0a2d2e) */
/* WARNING: Removing unreachable block (ram,0x0a2d5e) */
/* WARNING: Removing unreachable block (ram,0x0a2d52) */
/* WARNING: Removing unreachable block (ram,0x0a2d44) */
/* WARNING: Removing unreachable block (ram,0x0a2d4a) */
/* WARNING: Removing unreachable block (ram,0x0a2dda) */
/* WARNING: Removing unreachable block (ram,0x0a2d80) */
/* WARNING: Removing unreachable block (ram,0x0a2e18) */
/* WARNING: Removing unreachable block (ram,0x0a2e3a) */
/* WARNING: Removing unreachable block (ram,0x0a2d94) */
/* WARNING: Removing unreachable block (ram,0x0a2df2) */
/* WARNING: Removing unreachable block (ram,0x0a2e1a) */
/* WARNING: Removing unreachable block (ram,0x0a2e2a) */
/* WARNING: Removing unreachable block (ram,0x0a2dd2) */
/* WARNING: Removing unreachable block (ram,0x0a2e14) */
/* WARNING: Removing unreachable block (ram,0x0a2e26) */
/* WARNING: Removing unreachable block (ram,0x0a2dc4) */

undefined2 egs52_transform_memory_0a2d18(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 uVar11;
  int iVar12;
  byte bVar13;
  byte bVar14;
  byte bStack_e;
  
  egs52_clear_state_c164();
  bVar13 = 0;
  bStack_e = 0;
  do {
    if (*(char *)((uint3)((uint)bVar13 * 8 + 0x7f2) | 0x90000) == '\x03') {
      iVar10 = (uint)bStack_e * 6;
      uVar9 = iVar10 + 0xca80;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = bVar13;
      uVar9 = iVar10 + 0xca82;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 1;
      uVar9 = iVar10 + 0xca84;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0xff;
      uVar9 = iVar10 + 0xca85;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0;
      uVar9 = egs52_update_near_f876_0a3f66
                        (*(undefined2 *)((uint3)((uint)bVar13 * 8 + 0x7f4) | 0x90000));
      if (uVar9 == 0) {
        return 0;
      }
      for (bVar14 = 0; bVar14 < *(byte *)((uint3)((uint)bVar13 * 8 + 0x7f3) | 0x90000);
          bVar14 = bVar14 + 1) {
        iVar10 = (uint)bVar13 * 8;
        iVar8 = egs52_update_near_c166_0971e8
                          (*(int *)((uint3)(iVar10 + 0x7f0) | 0x90000) +
                           *(int *)((uint3)(iVar10 + 0x7f4) | 0x90000) * (uint)bVar14,uVar9,
                           *(undefined2 *)((uint3)(iVar10 + 0x7f4) | 0x90000));
        if (iVar8 == 0) {
          egs52_free_small_heap_block(uVar9);
          return 0;
        }
        do {
          egs52_update_near_c16e_097350();
          cVar7 = egs52_update_near_c168_09729a(iVar8);
        } while (cVar7 == '\x02');
        egs52_update_near_c168_0972dc(iVar8);
        uVar1 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = uVar9 + 1;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar2 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) +
                (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 0x100;
        uVar3 = uVar9 + 2;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar4 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
        uVar6 = uVar9 + 3;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar5 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
        iVar8 = egs52_call_092118_0a3d74(uVar9,*(undefined2 *)((uint3)(iVar10 + 0x7f4) | 0x90000));
        if ((uint)bVar4 + (uint)bVar5 * 0x100 == iVar8) {
          iVar8 = (uint)bStack_e * 6;
          uVar3 = iVar8 + 0xca82;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          if (*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) <= uVar2) {
            uVar1 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar2;
            uVar1 = iVar8 + 0xca84;
            uVar3 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = bVar14;
            if (uVar2 == 1) {
              uVar1 = iVar8 + 0xca85;
              uVar2 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = bVar14 + 1;
            }
            else {
              uVar1 = iVar8 + 0xca85;
              uVar2 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                   *(undefined1 *)((uint3)(iVar10 + 0x7f3) | 0x90000);
            }
          }
        }
      }
      egs52_free_small_heap_block(uVar9);
      bStack_e = bStack_e + 1;
    }
    bVar13 = bVar13 + 1;
  } while (bVar13 < 0x35);
  uVar9 = egs52_update_near_f876_0a3f66(uRam0907f4);
  if (uVar9 == 0) {
    uVar11 = 0;
  }
  else {
    iVar10 = egs52_update_near_c166_0971e8(uRam0907f0,uVar9,uRam0907f4);
    if (iVar10 == 0) {
      egs52_free_small_heap_block(uVar9);
      uVar11 = 0;
    }
    else {
      do {
        egs52_update_near_c16e_097350();
        cVar7 = egs52_update_near_c168_09729a(iVar10);
      } while (cVar7 == '\x02');
      egs52_update_near_c168_0972dc(iVar10);
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) == -0x56) {
        uVar1 = uVar9 + 1;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar13 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        uVar2 = uVar9 + 2;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar6 = uVar9 + 3;
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        iVar10 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                 (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) * 0x100;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
        iVar8 = (uint)bVar13 * 8;
        iVar12 = egs52_call_092118_0a3d74(uVar9,*(undefined2 *)((uint3)(iVar8 + 0x7f4) | 0x90000));
        if (iVar10 == iVar12) {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = (char)iVar10;
          uVar1 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = (char)((uint)iVar10 >> 8);
          iVar10 = egs52_update_near_c166_0971e8
                             (*(undefined2 *)((uint3)(iVar8 + 0x7f0) | 0x90000),0xcaa5,1);
          if (iVar10 == 0) {
            egs52_free_small_heap_block(uVar9);
            return 0;
          }
          do {
            egs52_update_near_c16e_097350();
            cVar7 = egs52_update_near_c168_09729a(iVar10);
          } while (cVar7 == '\x02');
          egs52_update_near_c168_0972dc(iVar10);
          cVar7 = UNK_00caa5;
          if (cVar7 == -0x56) {
            egs52_free_small_heap_block(uVar9);
          }
          else {
            uVar1 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0x55;
            iVar10 = egs52_update_near_c166_097172
                               (uVar9,*(undefined2 *)((uint3)(iVar8 + 0x7f0) | 0x90000),
                                *(undefined2 *)((uint3)(iVar8 + 0x7f4) | 0x90000),1,0);
            if (iVar10 == 0) {
              egs52_free_small_heap_block(uVar9);
              return 0;
            }
            iVar10 = egs52_update_near_c166_097172
                               (0xf852,*(undefined2 *)((uint3)(iVar8 + 0x7f0) | 0x90000),1,0,0);
            if (iVar10 == 0) {
              return 0;
            }
          }
        }
        else {
          egs52_free_small_heap_block(uVar9);
        }
      }
      else {
        egs52_free_small_heap_block(uVar9);
      }
      uVar11 = 1;
    }
  }
  return uVar11;
}


