/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3b10; FLS offset 0x023b10.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3c8a) */
/* WARNING: Removing unreachable block (ram,0x0a3ba8) */
/* WARNING: Removing unreachable block (ram,0x0a3b96) */
/* WARNING: Removing unreachable block (ram,0x0a3c72) */
/* WARNING: Removing unreachable block (ram,0x0a3c68) */
/* WARNING: Removing unreachable block (ram,0x0a3c64) */
/* WARNING: Removing unreachable block (ram,0x0a3c5c) */
/* WARNING: Removing unreachable block (ram,0x0a3c56) */
/* WARNING: Removing unreachable block (ram,0x0a3c70) */
/* WARNING: Removing unreachable block (ram,0x0a3c6c) */
/* WARNING: Removing unreachable block (ram,0x0a3c50) */
/* WARNING: Removing unreachable block (ram,0x0a3c44) */
/* WARNING: Removing unreachable block (ram,0x0a3c42) */
/* WARNING: Removing unreachable block (ram,0x0a3c3e) */
/* WARNING: Removing unreachable block (ram,0x0a3c38) */
/* WARNING: Removing unreachable block (ram,0x0a3c2a) */
/* WARNING: Removing unreachable block (ram,0x0a3bfe) */
/* WARNING: Removing unreachable block (ram,0x0a3c08) */
/* WARNING: Removing unreachable block (ram,0x0a3be4) */
/* WARNING: Removing unreachable block (ram,0x0a3bd6) */
/* WARNING: Removing unreachable block (ram,0x0a3bd4) */
/* WARNING: Removing unreachable block (ram,0x0a3bc8) */
/* WARNING: Removing unreachable block (ram,0x0a3bb2) */
/* WARNING: Removing unreachable block (ram,0x0a3b7c) */
/* WARNING: Removing unreachable block (ram,0x0a3b6e) */
/* WARNING: Removing unreachable block (ram,0x0a3b6c) */
/* WARNING: Removing unreachable block (ram,0x0a3b62) */
/* WARNING: Removing unreachable block (ram,0x0a3b5a) */
/* WARNING: Removing unreachable block (ram,0x0a3c82) */
/* WARNING: Removing unreachable block (ram,0x0a3b2a) */
/* WARNING: Removing unreachable block (ram,0x0a3b1e) */
/* WARNING: Removing unreachable block (ram,0x0a3c12) */
/* WARNING: Removing unreachable block (ram,0x0a3c7a) */
/* WARNING: Removing unreachable block (ram,0x0a3c92) */

uchar * egs52_update_near_caa4_0a3b10(undefined2 param_1,uchar *param_2,byte param_3)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  uchar *puVar10;
  uint uVar11;
  int iVar12;
  
  cVar9 = UNK_00caa4;
  if (cVar9 == '\0') {
    UNK_00caa4 = 1;
    puVar10 = (uchar *)egs52_update_near_c168_09729a();
    cVar9 = (char)puVar10;
    if (cVar9 == '\x01') {
      uVar11 = egs52_update_near_c168_0972dc(param_1);
      if (uVar11 == 0) {
        UNK_00caa4 = 0;
        puVar10 = (uchar *)0x3;
      }
      else {
        uVar5 = uVar11 + 2;
        uVar1 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
        uVar6 = uVar11 + 3;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        uVar1 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 0;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
        iVar7 = (uint)param_3 * 8;
        iVar12 = egs52_call_092118_0a3d74(uVar11,*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000));
        if ((uint)bVar2 + (uint)bVar3 * 0x100 == iVar12) {
          egs52_memcpy_near(param_2,(uchar *)(uVar11 + 4),
                            *(int *)((uint3)(iVar7 + 0x7f4) | 0x90000) - 4);
          egs52_free_small_heap_block(uVar11,uVar11);
          UNK_00caa4 = 0;
          puVar10 = (uchar *)0x1;
        }
        else {
          uVar1 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          cVar9 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
          puVar10 = (uchar *)egs52_free_small_heap_block(uVar11);
          if (*(int *)((uint3)(iVar7 + 0x7f6U) | 0x90000) != 0) {
            puVar10 = egs52_memcpy_near(param_2,*(uchar **)((uint3)(iVar7 + 0x7f6U) | 0x90000),
                                        *(int *)((uint3)(iVar7 + 0x7f4) | 0x90000) - 4);
          }
          cVar4 = *(char *)((uint3)(iVar7 + 0x7f2) | 0x90000);
          if (cVar4 == '\x01') {
            if (cVar9 == 'U') {
              UNK_00caa4 = 0;
              puVar10 = (uchar *)0x6;
            }
            else {
              UNK_00caa4 = 0;
              puVar10 = (uchar *)0x4;
            }
          }
          else if (cVar4 == '\x02') {
            UNK_00caa4 = 0;
            puVar10 = (uchar *)0x4;
          }
          else if (cVar4 == '\x03') {
            iVar12 = 0;
            while( true ) {
              iVar8 = iVar12 * 6;
              uVar11 = iVar8 + 0xca80;
              uVar1 = 0x24;
              if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) == param_3) break;
              iVar12 = iVar12 + 1;
            }
            uVar1 = iVar8 + 0xca85;
            uVar11 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar11 = 3;
            }
            if (*(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) != '\0') {
              uVar11 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar11 = 3;
              }
              uVar5 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar5 = 3;
              }
              *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                   *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) + -1;
            }
            uVar11 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar11 = 3;
            }
            if (*(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
              UNK_00caa4 = 0;
              puVar10 = (uchar *)0x4;
            }
            else {
              uVar1 = iVar8 + 0xca84;
              uVar11 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar11 = 3;
              }
              if (*(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
                uVar11 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar11 = 3;
                }
                *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                     *(char *)((uint3)(iVar7 + 0x7f3) | 0x90000) + -1;
                uVar1 = iVar8 + 0xca82;
                uVar11 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar11 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                     *(int *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) + -1;
              }
              else {
                uVar11 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar11 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                     *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) + -1;
              }
              UNK_00caa4 = 0;
              puVar10 = (uchar *)0x5;
            }
          }
        }
      }
    }
    else if (cVar9 == '\x02') {
      UNK_00caa4 = 0;
      puVar10 = (uchar *)0x2;
    }
    else if (cVar9 == '\x03') {
      UNK_00caa4 = 0;
      puVar10 = (uchar *)0x3;
    }
  }
  else {
    puVar10 = (uchar *)0x2;
  }
  return puVar10;
}


