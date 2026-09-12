/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09fbc0; FLS offset 0x01fbc0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x09fef4) */
/* WARNING: Removing unreachable block (ram,0x09fee0) */
/* WARNING: Removing unreachable block (ram,0x09fe8e) */
/* WARNING: Removing unreachable block (ram,0x09fe8a) */
/* WARNING: Removing unreachable block (ram,0x09fe60) */
/* WARNING: Removing unreachable block (ram,0x09fe5c) */
/* WARNING: Removing unreachable block (ram,0x09fe54) */
/* WARNING: Removing unreachable block (ram,0x09fe88) */
/* WARNING: Removing unreachable block (ram,0x09fe84) */
/* WARNING: Removing unreachable block (ram,0x09fe7c) */
/* WARNING: Removing unreachable block (ram,0x09fe78) */
/* WARNING: Removing unreachable block (ram,0x09fe70) */
/* WARNING: Removing unreachable block (ram,0x09fe42) */
/* WARNING: Removing unreachable block (ram,0x09fe40) */
/* WARNING: Removing unreachable block (ram,0x09fe3c) */
/* WARNING: Removing unreachable block (ram,0x09fe1c) */
/* WARNING: Removing unreachable block (ram,0x09fe08) */
/* WARNING: Removing unreachable block (ram,0x09fdbe) */
/* WARNING: Removing unreachable block (ram,0x09fd88) */
/* WARNING: Removing unreachable block (ram,0x09fd84) */
/* WARNING: Removing unreachable block (ram,0x09fd74) */
/* WARNING: Removing unreachable block (ram,0x09fdae) */
/* WARNING: Removing unreachable block (ram,0x09fdaa) */
/* WARNING: Removing unreachable block (ram,0x09fd9a) */
/* WARNING: Removing unreachable block (ram,0x09fd40) */
/* WARNING: Removing unreachable block (ram,0x09fd3c) */
/* WARNING: Removing unreachable block (ram,0x09fd2c) */
/* WARNING: Removing unreachable block (ram,0x09fd66) */
/* WARNING: Removing unreachable block (ram,0x09fd62) */
/* WARNING: Removing unreachable block (ram,0x09fd52) */
/* WARNING: Removing unreachable block (ram,0x09fdf4) */
/* WARNING: Removing unreachable block (ram,0x09fdf0) */
/* WARNING: Removing unreachable block (ram,0x09fdfe) */
/* WARNING: Removing unreachable block (ram,0x09fdfa) */
/* WARNING: Removing unreachable block (ram,0x09fdea) */
/* WARNING: Removing unreachable block (ram,0x09fd08) */
/* WARNING: Removing unreachable block (ram,0x09fcfe) */
/* WARNING: Removing unreachable block (ram,0x09fcfa) */
/* WARNING: Removing unreachable block (ram,0x09fd06) */
/* WARNING: Removing unreachable block (ram,0x09fd02) */
/* WARNING: Removing unreachable block (ram,0x09fcd6) */
/* WARNING: Removing unreachable block (ram,0x09fcd2) */
/* WARNING: Removing unreachable block (ram,0x09fcca) */
/* WARNING: Removing unreachable block (ram,0x09fc94) */
/* WARNING: Removing unreachable block (ram,0x09fc90) */
/* WARNING: Removing unreachable block (ram,0x09fc8a) */
/* WARNING: Removing unreachable block (ram,0x09fc86) */
/* WARNING: Removing unreachable block (ram,0x09fc72) */
/* WARNING: Removing unreachable block (ram,0x09fc6e) */
/* WARNING: Removing unreachable block (ram,0x09fc66) */
/* WARNING: Removing unreachable block (ram,0x09fede) */
/* WARNING: Removing unreachable block (ram,0x09feda) */
/* WARNING: Removing unreachable block (ram,0x09feba) */
/* WARNING: Removing unreachable block (ram,0x09feb6) */
/* WARNING: Removing unreachable block (ram,0x09feae) */
/* WARNING: Removing unreachable block (ram,0x09feaa) */
/* WARNING: Removing unreachable block (ram,0x09fea2) */
/* WARNING: Removing unreachable block (ram,0x09fed2) */
/* WARNING: Removing unreachable block (ram,0x09fece) */
/* WARNING: Removing unreachable block (ram,0x09fec6) */
/* WARNING: Removing unreachable block (ram,0x09fe96) */
/* WARNING: Removing unreachable block (ram,0x09fe92) */
/* WARNING: Removing unreachable block (ram,0x09fc3a) */
/* WARNING: Removing unreachable block (ram,0x09fbce) */
/* WARNING: Removing unreachable block (ram,0x09fbec) */
/* WARNING: Removing unreachable block (ram,0x09fde6) */
/* WARNING: Removing unreachable block (ram,0x09ff0c) */

byte egs52_update_fault_status(byte param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  char cVar13;
  ushort uVar14;
  uint uVar15;
  byte bVar16;
  char cStack_a;
  
  iVar7 = Ram00f84c;
  if (iVar7 == 0) {
    bVar16 = 0xff;
  }
  else {
    bVar16 = (byte)param_2;
    if (bVar16 == 0x40) {
      uVar6 = (uint)(param_1 >> 4) * 2 + 0xc42c;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
           *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 1 << (uint)param_1 % 0x10;
      bVar16 = 0x40;
    }
    else {
      uVar6 = param_1 + 0xc3ac;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar4 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff));
      iVar7 = (uint)param_1 * 0x14;
      uVar5 = iVar7 + 0x9300;
      bVar9 = bVar4 >> 2;
      uVar14 = egs52_get_operating_mask();
      uVar2 = iVar7 + 0x9312;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if ((uVar14 & *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))) == 0) {
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 0x20;
        if ((bVar9 & 1) == 0) {
          uVar2 = iVar7 + 0x9309;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          iVar7 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
          (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                    (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))(param_1,0);
          uVar2 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 8;
        }
        else {
          uVar2 = iVar7 + 0x9309;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          iVar7 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
          (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                    (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))(param_1,0xff);
        }
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xfd;
      }
      else if (((param_2 & 0xff) >> 1 & 1) == 0) {
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 0x20;
        uVar2 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0x10) == 0) {
          if ((bVar9 & 1) == 0) {
            uVar2 = iVar7 + 0x9309;
            uVar3 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            iVar7 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
            (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                      (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))(param_1,0);
            uVar2 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar3 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 8;
          }
          else {
            uVar2 = iVar7 + 0x9309;
            uVar3 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            iVar7 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
            (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa2c) | 0x90000) << 0x10 |
                      (uint3)*(uint *)((uint3)(iVar7 + 0xa2a) | 0x90000)))(param_1,0xff);
          }
        }
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xfd;
      }
      else {
        bVar10 = false;
        cStack_a = '\x0f';
        if ((bVar4 >> 4 & 1) == 0) {
          uVar2 = iVar7 + 0x9309;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          iVar8 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
          cVar13 = (*(code *)((uint3)*(uint *)((uint3)(iVar8 + 0xa18) | 0x90000) << 0x10 |
                             (uint3)*(uint *)((uint3)(iVar8 + 0xa16) | 0x90000)))(param_1);
          bVar10 = false;
          if (cVar13 == '\0') {
            uVar2 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar3 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 0x10;
            cStack_a = '\0';
            bVar10 = true;
          }
        }
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 2;
        bVar12 = true;
        bVar11 = bVar12;
        if (((bVar4 & 0x20) != 0) &&
           (((((param_2 & 1) != 0 || (bVar11 = false, (bVar4 >> 3 & 1) == 0)) &&
             (bVar11 = bVar12, (param_2 & 1) != 0)) && (bVar11 = false, (bVar9 & 1) == 0)))) {
          bVar11 = bVar12;
        }
        if (bVar11) {
          uVar2 = iVar7 + 0x9309;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          iVar7 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4;
          uVar15 = (*(code *)((uint3)*(uint *)((uint3)(iVar7 + 0xa04) | 0x90000) << 0x10 |
                             (uint3)*(uint *)((uint3)(iVar7 + 0xa02) | 0x90000)))
                             (param_1,param_2 & 0xff | bVar4 & 0x2c);
          uVar2 = (uVar15 & 0xff) >> 2 & 1;
          uVar3 = (uVar15 & 0xff) >> 3 & 1;
          if ((uVar15 & 0x20) == 0) {
            uVar15 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar15 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar15 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar15 = 3;
            }
            uVar1 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xdf;
          }
          else {
            uVar15 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar15 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar15 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar15 = 3;
            }
            uVar1 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar6 & 0x3fff)) | 0x20;
          }
          iVar7 = Ram00f84c;
          if (iVar7 == 2) {
            if ((bool)((byte)((uVar3 << 0xe) >> 0xe) ^ bVar4 >> 3 & 1)) {
              if (uVar3 == 0) {
                if (-1 < (char)bVar4) {
                  egs52_transform_far_memory_0a290e(param_1);
                }
                uVar3 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) & 8) == 0) {
                  egs52_update_near_fd6c_0a2120(param_1);
                }
                uVar3 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                uVar15 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar15 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar15 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar15 = 3;
                }
                *(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                     *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xf7;
              }
              else {
                if (-1 < (char)bVar4) {
                  egs52_update_near_fd6c_0a2550(param_1,1);
                }
                uVar3 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) & 8) == 0) {
                  egs52_update_near_fd6c_0a2200(param_1);
                }
                uVar3 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                uVar15 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar15 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar15 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar15 = 3;
                }
                *(byte *)((uint3)uVar15 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                     *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) | 8;
              }
            }
            if ((bool)((byte)((uVar2 << 9) >> 9) ^ (byte)(((bVar9 & 1) << 0xb) >> 0xb))) {
              bVar10 = true;
              if (uVar2 == 0) {
                uVar2 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) & 8) != 0) {
                  egs52_update_near_fd6c_0a2200(param_1);
                  cStack_a = '\0';
                }
                uVar2 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                uVar3 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                     *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xfb;
              }
              else {
                if (-1 < (char)bVar4) {
                  egs52_update_near_fd6c_0a2728(param_1);
                }
                uVar2 = 0x24;
                if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) & 8) != 0) {
                  egs52_update_near_fd6c_0a2120(param_1);
                  cStack_a = '\x01';
                }
                uVar2 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                uVar3 = 0x24;
                if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                     *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 4;
              }
            }
            if ((bVar10) && (-1 < (char)bVar4)) {
              uVar2 = 0x24;
              if (((uVar6 & 0xc000) != 0) &&
                 ((uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000 &&
                  (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)))) {
                uVar2 = 3;
              }
              egs52_update_near_c44e_0a18cc
                        (param_1,bVar16 & 1 |
                                 *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)));
            }
            if (cStack_a != '\x0f') {
              egs52_update_near_cce8_0a4fc0(param_1,cStack_a);
            }
          }
          else {
            if (((bVar9 & 1) == 0) && (uVar2 != 0)) {
              uVar2 = 0x24;
              if (((uVar6 & 0xc000) != 0) &&
                 ((uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000 &&
                  (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)))) {
                uVar2 = 3;
              }
              uVar5 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar5 = 3;
              }
              *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                   *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 4;
            }
            if (uVar3 == 0) {
              uVar2 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              uVar3 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                   *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) & 0xf7;
            }
            else {
              uVar2 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              uVar3 = 0x24;
              if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                   *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) | 8;
            }
          }
        }
        else if ((bVar10) && (iVar7 = Ram00f84c, iVar7 == 2)) {
          if (-1 < (char)bVar4) {
            uVar2 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            egs52_update_near_c44e_0a18cc
                      (param_1,bVar16 & 1 | *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff))
                      );
          }
          if (cStack_a != '\x0f') {
            egs52_update_near_cce8_0a4fc0(param_1,cStack_a);
          }
        }
      }
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar16 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) & 7;
    }
  }
  return bVar16;
}


