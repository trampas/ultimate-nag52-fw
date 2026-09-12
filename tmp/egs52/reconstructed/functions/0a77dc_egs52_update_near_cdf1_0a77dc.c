/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a77dc; FLS offset 0x0277dc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a7814) */
/* WARNING: Removing unreachable block (ram,0x0a77f0) */
/* WARNING: Removing unreachable block (ram,0x0a7940) */
/* WARNING: Removing unreachable block (ram,0x0a7934) */
/* WARNING: Removing unreachable block (ram,0x0a7930) */
/* WARNING: Removing unreachable block (ram,0x0a7926) */
/* WARNING: Removing unreachable block (ram,0x0a793e) */
/* WARNING: Removing unreachable block (ram,0x0a7938) */
/* WARNING: Removing unreachable block (ram,0x0a7912) */
/* WARNING: Removing unreachable block (ram,0x0a7910) */
/* WARNING: Removing unreachable block (ram,0x0a790c) */
/* WARNING: Removing unreachable block (ram,0x0a78fe) */
/* WARNING: Removing unreachable block (ram,0x0a78fc) */
/* WARNING: Removing unreachable block (ram,0x0a78f4) */
/* WARNING: Removing unreachable block (ram,0x0a78bc) */
/* WARNING: Removing unreachable block (ram,0x0a78c0) */
/* WARNING: Removing unreachable block (ram,0x0a78e6) */
/* WARNING: Removing unreachable block (ram,0x0a78d8) */
/* WARNING: Removing unreachable block (ram,0x0a78b4) */
/* WARNING: Removing unreachable block (ram,0x0a78a8) */
/* WARNING: Removing unreachable block (ram,0x0a79dc) */
/* WARNING: Removing unreachable block (ram,0x0a79d8) */
/* WARNING: Removing unreachable block (ram,0x0a7988) */
/* WARNING: Removing unreachable block (ram,0x0a79b8) */
/* WARNING: Removing unreachable block (ram,0x0a7990) */
/* WARNING: Removing unreachable block (ram,0x0a7984) */
/* WARNING: Removing unreachable block (ram,0x0a794c) */
/* WARNING: Removing unreachable block (ram,0x0a79e4) */
/* WARNING: Removing unreachable block (ram,0x0a79e0) */
/* WARNING: Removing unreachable block (ram,0x0a789e) */
/* WARNING: Removing unreachable block (ram,0x0a7898) */
/* WARNING: Removing unreachable block (ram,0x0a7892) */
/* WARNING: Removing unreachable block (ram,0x0a79c8) */
/* WARNING: Removing unreachable block (ram,0x0a77f6) */
/* WARNING: Removing unreachable block (ram,0x0a78cc) */
/* WARNING: Removing unreachable block (ram,0x0a79ae) */
/* WARNING: Removing unreachable block (ram,0x0a79c2) */

char egs52_update_near_cdf1_0a77dc(uint param_1,char param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  uchar uVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  int iStack_c;
  char acStack_a [2];
  
  if (param_3 == -1) {
    UNK_00cdf1 = 0xff;
    UNK_00cdf0 = 1;
    if (param_2 == '\x03') {
      cVar8 = '\0';
      uVar9 = 0;
      do {
        uVar2 = uVar9 * 0x14 + 0x9302;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if ((*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) != 0) &&
           (uVar6 = egs52_test_fault_bitmap((uchar)uVar9), uVar6 == '\0')) {
          cVar8 = cVar8 + '\x01';
        }
        bVar7 = (uchar)uVar9 + 1;
        uVar9 = (uint)bVar7;
      } while (bVar7 < 0x80);
    }
    else {
      cVar8 = '\0';
      bVar7 = 0;
      do {
        bVar5 = egs52_update_near_fd6c_0a1288(bVar7,0xff,0xff,acStack_a);
        if (bVar5 != 0xff) {
          if ((bVar5 & 0x40) == 0) {
            if (acStack_a[0] != '\x12') {
              cVar8 = cVar8 + '\x01';
            }
          }
          else {
            cVar8 = cVar8 + '\x01';
          }
        }
        bVar7 = bVar7 + 1;
      } while (bVar7 < 0x10);
    }
  }
  else {
    uVar9 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar9 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(param_1 & 0x3fff)) = 0;
    uVar2 = param_1 + 1;
    uVar9 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
    uVar3 = param_1 + 2;
    uVar9 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    if (param_2 == '\x03') {
      bVar7 = UNK_00cdf0;
      uVar9 = (uint)bVar7 * 0x14 + 0x9302;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iStack_c = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff));
      do {
        if (iStack_c != 0) {
          uVar6 = UNK_00cdf0;
          uVar6 = egs52_test_fault_bitmap(uVar6);
          if (uVar6 == '\0') {
LAB_0a78f0:
            uVar9 = 0x24;
            if ((((param_1 & 0xc000) != 0) && (uVar9 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
               (uVar9 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
              uVar9 = 3;
            }
            *(char *)((uint3)uVar9 << 0xe | (uint3)(param_1 & 0x3fff)) = (char)((uint)iStack_c >> 8)
            ;
            uVar9 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar9 = 3;
            }
            *(char *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) = (char)iStack_c;
            uVar4 = UNK_00cdf0;
            cVar8 = egs52_match_fault_status_mask(uVar4,8);
            if (cVar8 == '\0') {
              uVar9 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar9 = 3;
              }
              uVar2 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                   *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) | 0x10;
            }
            uVar4 = UNK_00cdf0;
            bVar7 = egs52_update_near_fd6c_0a1220(uVar4);
            if (bVar7 != 0xff) {
              if ((bVar7 & 0x40) == 0) {
                cVar8 = UNK_00cdf0;
                if (cVar8 != '\x12') {
                  uVar9 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar9 = 3;
                  }
                  uVar2 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar2 = 3;
                  }
                  *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                       *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) | 0x20;
                }
              }
              else {
                uVar9 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar9 = 3;
                }
                uVar2 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                     *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) | 0x60;
              }
            }
            cVar8 = UNK_00cdf0;
            UNK_00cdf0 = cVar8 + '\x01';
            return '\0';
          }
        }
        bVar7 = UNK_00cdf0;
        if (0x7f < bVar7) goto LAB_0a78f0;
        cVar8 = UNK_00cdf0;
        UNK_00cdf0 = cVar8 + '\x01';
        bVar7 = UNK_00cdf0;
        uVar9 = (uint)bVar7 * 0x14 + 0x9302;
        uVar1 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iStack_c = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff));
      } while( true );
    }
    do {
      do {
        do {
          cVar8 = UNK_00cdf1;
          UNK_00cdf1 = cVar8 + '\x01';
          cVar8 = UNK_00cdf1;
          if ('\x0f' < cVar8) goto LAB_0a79ee;
          cVar8 = UNK_00cdf1;
          bVar7 = egs52_update_near_fd6c_0a1288((int)cVar8,0xff,0xff,acStack_a);
        } while (bVar7 == 0xff);
        cVar8 = egs52_match_fault_status_mask(acStack_a[0],8);
        if (cVar8 == '\0') {
          uVar2 = param_1 + 2;
          uVar9 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar9 = 3;
          }
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) | 0x10;
        }
        cVar8 = UNK_00cdf1;
        cVar8 = egs52_update_near_fd6c_0a1522((int)cVar8,0,&iStack_c,0,0);
      } while (cVar8 != '\0');
      uVar9 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar9 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      *(char *)((uint3)uVar9 << 0xe | (uint3)(param_1 & 0x3fff)) = (char)((uint)iStack_c >> 8);
      uVar9 = param_1 + 1;
      uVar2 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) = (char)iStack_c;
      if ((bVar7 & 0x40) != 0) {
        param_1 = param_1 + 2;
        uVar9 = 0x24;
        if ((((param_1 & 0xc000) != 0) && (uVar9 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        uVar2 = 0x24;
        if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) =
             *(byte *)((uint3)uVar9 << 0xe | (uint3)(param_1 & 0x3fff)) | 0x60;
        goto LAB_0a79ee;
      }
    } while (acStack_a[0] == '\x12');
    param_1 = param_1 + 2;
    uVar9 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar9 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    uVar2 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(byte *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) =
         *(byte *)((uint3)uVar9 << 0xe | (uint3)(param_1 & 0x3fff)) | 0x20;
LAB_0a79ee:
    cVar8 = '\0';
  }
  return cVar8;
}


