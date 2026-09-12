/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f874; FLS offset 0x01f874.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x09fb56) */
/* WARNING: Removing unreachable block (ram,0x09fb30) */
/* WARNING: Removing unreachable block (ram,0x09fad8) */
/* WARNING: Removing unreachable block (ram,0x09fafc) */
/* WARNING: Removing unreachable block (ram,0x09fa8c) */
/* WARNING: Removing unreachable block (ram,0x09faaa) */
/* WARNING: Removing unreachable block (ram,0x09fadc) */
/* WARNING: Removing unreachable block (ram,0x09facc) */
/* WARNING: Removing unreachable block (ram,0x09fa50) */
/* WARNING: Removing unreachable block (ram,0x09f982) */
/* WARNING: Removing unreachable block (ram,0x09f992) */
/* WARNING: Removing unreachable block (ram,0x09f976) */
/* WARNING: Removing unreachable block (ram,0x09f978) */
/* WARNING: Removing unreachable block (ram,0x09f956) */
/* WARNING: Removing unreachable block (ram,0x09f972) */
/* WARNING: Removing unreachable block (ram,0x09f95e) */
/* WARNING: Removing unreachable block (ram,0x09f9f4) */
/* WARNING: Removing unreachable block (ram,0x09f91e) */
/* WARNING: Removing unreachable block (ram,0x09fa2c) */
/* WARNING: Removing unreachable block (ram,0x09f8f8) */
/* WARNING: Removing unreachable block (ram,0x09f97e) */
/* WARNING: Removing unreachable block (ram,0x09f8dc) */
/* WARNING: Removing unreachable block (ram,0x09f962) */
/* WARNING: Removing unreachable block (ram,0x09f8d0) */
/* WARNING: Removing unreachable block (ram,0x09f95c) */
/* WARNING: Removing unreachable block (ram,0x09f8ca) */
/* WARNING: Removing unreachable block (ram,0x09f97c) */
/* WARNING: Removing unreachable block (ram,0x09f922) */
/* WARNING: Removing unreachable block (ram,0x09f8c2) */
/* WARNING: Removing unreachable block (ram,0x09f9b2) */
/* WARNING: Removing unreachable block (ram,0x09f9bc) */
/* WARNING: Removing unreachable block (ram,0x09f8ae) */
/* WARNING: Removing unreachable block (ram,0x09f9de) */
/* WARNING: Removing unreachable block (ram,0x09f9ca) */
/* WARNING: Removing unreachable block (ram,0x09f9b8) */
/* WARNING: Removing unreachable block (ram,0x09f9b6) */
/* WARNING: Removing unreachable block (ram,0x09f9da) */
/* WARNING: Removing unreachable block (ram,0x09f996) */
/* WARNING: Removing unreachable block (ram,0x09f8fc) */
/* WARNING: Removing unreachable block (ram,0x09f9a2) */
/* WARNING: Removing unreachable block (ram,0x09f958) */
/* WARNING: Removing unreachable block (ram,0x09f952) */
/* WARNING: Removing unreachable block (ram,0x09fa4a) */
/* WARNING: Removing unreachable block (ram,0x09fb20) */
/* WARNING: Removing unreachable block (ram,0x09fad2) */
/* WARNING: Removing unreachable block (ram,0x09f99c) */
/* WARNING: Removing unreachable block (ram,0x09fa30) */
/* WARNING: Removing unreachable block (ram,0x09f998) */
/* WARNING: Removing unreachable block (ram,0x09f99e) */

uint egs52_update_near_f84c_09f874(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 uVar9;
  uint uVar10;
  byte abStack_c [4];
  
  uVar10 = 0;
  do {
    uVar8 = egs52_update_near_fd6c_0a1288(uVar10,0xff,0xff,abStack_c);
    if ((char)uVar8 != -1) {
      if ((uVar8 & 0x40) == 0) {
        uVar8 = egs52_call_0a1c96_0a514a(uVar10);
      }
      else {
        uVar8 = (uint)abStack_c[0] * 0x14 + 0x9300;
        uVar6 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        if ((*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff)) & 0x20) == 0) {
          uVar6 = abStack_c[0] + 0xc3ac;
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          bVar2 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff));
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          bVar3 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff));
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          if (((*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff)) & 4) == 0) ||
             ((bVar2 & 8) == 0)) {
            uVar8 = (uint)abStack_c[0] * 0x14 + 0x9309;
            uVar6 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar6 = 3;
            }
            iVar7 = (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff)) * 4;
            uVar8 = (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                              (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))
                              (abStack_c[0],0xff);
            if (((bVar3 & 2) == 0) || ((bVar2 & 8) == 0)) {
              uVar5 = abStack_c[0] + 0xc3ac;
              uVar6 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar6 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                   *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) | 4;
              uVar6 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar6 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                   *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xf7;
              uVar6 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar6 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                   *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) | 0x20;
            }
            else {
              uVar8 = (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa04) | 0x90000) << 0x10 |
                                (uint3)*(uint *)((uint3)(iVar7 + 0xa02) | 0x90000)))
                                (abStack_c[0],0x26,bVar3 & 2);
              if (((uVar8 & 4) == 0) && ((uVar8 & 8) != 0)) {
                egs52_update_near_fd6c_0a2200(abStack_c[0]);
                uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],2);
                uVar5 = abStack_c[0] + 0xc3ac;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xfb;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) | 0x20;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) | 8;
              }
              else {
                uVar5 = abStack_c[0] + 0xc3ac;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) | 4;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xf7;
                uVar6 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar6 = 3;
                }
                uVar1 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                     *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xdf;
              }
            }
          }
          else {
            egs52_update_near_fd6c_0a2200(abStack_c[0]);
            uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],2);
            uVar5 = abStack_c[0] + 0xc3ac;
            uVar6 = 0x24;
            if (((uVar5 & 0xc000) != 0) &&
               ((uVar6 = 0x21, (uVar5 & 0xc000) != 0x4000 &&
                (uVar6 = 0x2c, (uVar5 & 0xc000) != 0x8000)))) {
              uVar6 = 3;
            }
            uVar1 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                 *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xfb;
          }
        }
        else {
          uVar6 = abStack_c[0] + 0xc3ac;
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xfb;
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff)) | 8;
          uVar8 = (uint)abStack_c[0] * 0x14 + 0x9309;
          uVar6 = 0x24;
          if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          iVar7 = (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff)) * 4;
          (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                    (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))(abStack_c[0],0);
          egs52_update_near_fd6c_0a2200(abStack_c[0]);
          uVar8 = abStack_c[0] + 0xc3ac;
          uVar6 = 0x24;
          if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          egs52_update_near_c44e_0a18cc
                    (abStack_c[0],*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff)));
          uVar8 = egs52_call_0a1c96_0a514a(uVar10);
        }
      }
    }
    uVar10 = uVar10 + 1;
  } while (uVar10 < 0x10);
  abStack_c[0] = 0;
  do {
    uVar6 = abStack_c[0] + 0xc3ac;
    uVar10 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    cVar4 = *(char *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff));
    uVar10 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    if ((*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) & 4) == 0) {
      uVar10 = abStack_c[0] + 0xc3ac;
      uVar6 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      if ((*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) & 8) == 0) {
        if (-1 < cVar4) {
          uVar8 = egs52_transform_far_memory_0a290e(abStack_c[0]);
        }
        uVar6 = (uint)abStack_c[0] * 0x14 + 0x9300;
        uVar10 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        if ((*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) & 8) == 0) {
          uVar8 = egs52_update_near_fd6c_0a2120(abStack_c[0]);
        }
      }
      uVar10 = abStack_c[0] + 0xc3ac;
      uVar6 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      if (((*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) & 0x10) != 0) && (-1 < cVar4))
      {
        uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],0x10);
      }
    }
    else {
      uVar8 = egs52_update_near_fd6c_0a1220(abStack_c[0]);
      if (((char)uVar8 == -1) || ((uVar8 & 0x40) == 0)) {
        if (-1 < cVar4) {
          egs52_transform_far_memory_0a290e(abStack_c[0]);
          egs52_update_near_fd6c_0a2728(abStack_c[0]);
        }
        uVar8 = egs52_update_near_fd6c_0a2120(abStack_c[0]);
        if (-1 < cVar4) {
          uVar10 = abStack_c[0] + 0xc3ac;
          uVar8 = 0x24;
          if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          if ((*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff)) & 0x10) == 0) {
            uVar9 = 5;
          }
          else {
            uVar9 = 7;
          }
          uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],uVar9);
        }
      }
      else {
        uVar10 = abStack_c[0] + 0xc3ac;
        uVar6 = 0x24;
        if (((uVar10 & 0xc000) != 0) &&
           ((uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000 &&
            (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)))) {
          uVar6 = 3;
        }
        if (((*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) & 0x10) != 0) &&
           (-1 < cVar4)) {
          uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],7);
        }
      }
      uVar6 = abStack_c[0] + 0xc3ac;
      uVar10 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      if ((*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) & 8) != 0) {
        uVar10 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        if ((*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0x10) != 0) {
          uVar10 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          uVar8 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar8 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xfb;
          uVar8 = egs52_update_near_fd6c_0a2200(abStack_c[0]);
          if (-1 < cVar4) {
            uVar8 = egs52_update_near_c44e_0a18cc(abStack_c[0],2);
          }
        }
      }
    }
    abStack_c[0] = abStack_c[0] + 1;
  } while (abStack_c[0] < 0x80);
  Ram00f84c = 2;
  return uVar8 & 0xff00;
}


