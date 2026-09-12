/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097350; FLS offset 0x017350.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097602) */
/* WARNING: Removing unreachable block (ram,0x0975f2) */
/* WARNING: Removing unreachable block (ram,0x0975f8) */
/* WARNING: Removing unreachable block (ram,0x0975ea) */
/* WARNING: Removing unreachable block (ram,0x0975d0) */
/* WARNING: Removing unreachable block (ram,0x0975d6) */
/* WARNING: Removing unreachable block (ram,0x0975c8) */
/* WARNING: Removing unreachable block (ram,0x0975a8) */
/* WARNING: Removing unreachable block (ram,0x0975a4) */
/* WARNING: Removing unreachable block (ram,0x09759a) */
/* WARNING: Removing unreachable block (ram,0x097594) */
/* WARNING: Removing unreachable block (ram,0x09758e) */
/* WARNING: Removing unreachable block (ram,0x09757a) */
/* WARNING: Removing unreachable block (ram,0x097576) */
/* WARNING: Removing unreachable block (ram,0x097568) */
/* WARNING: Removing unreachable block (ram,0x0974c6) */
/* WARNING: Removing unreachable block (ram,0x0974c2) */
/* WARNING: Removing unreachable block (ram,0x0974be) */
/* WARNING: Removing unreachable block (ram,0x097540) */
/* WARNING: Removing unreachable block (ram,0x097538) */
/* WARNING: Removing unreachable block (ram,0x097530) */
/* WARNING: Removing unreachable block (ram,0x097528) */
/* WARNING: Removing unreachable block (ram,0x097524) */
/* WARNING: Removing unreachable block (ram,0x09750e) */
/* WARNING: Removing unreachable block (ram,0x09750c) */
/* WARNING: Removing unreachable block (ram,0x097508) */
/* WARNING: Removing unreachable block (ram,0x097518) */
/* WARNING: Removing unreachable block (ram,0x097516) */
/* WARNING: Removing unreachable block (ram,0x097512) */
/* WARNING: Removing unreachable block (ram,0x0974fc) */
/* WARNING: Removing unreachable block (ram,0x0974ee) */
/* WARNING: Removing unreachable block (ram,0x0974e8) */
/* WARNING: Removing unreachable block (ram,0x0974dc) */
/* WARNING: Removing unreachable block (ram,0x0974d8) */
/* WARNING: Removing unreachable block (ram,0x0974aa) */
/* WARNING: Removing unreachable block (ram,0x0974a6) */
/* WARNING: Removing unreachable block (ram,0x097448) */
/* WARNING: Removing unreachable block (ram,0x097438) */
/* WARNING: Removing unreachable block (ram,0x097432) */
/* WARNING: Removing unreachable block (ram,0x09742e) */
/* WARNING: Removing unreachable block (ram,0x097474) */
/* WARNING: Removing unreachable block (ram,0x097464) */
/* WARNING: Removing unreachable block (ram,0x09745e) */
/* WARNING: Removing unreachable block (ram,0x09745a) */
/* WARNING: Removing unreachable block (ram,0x097454) */
/* WARNING: Removing unreachable block (ram,0x097450) */
/* WARNING: Removing unreachable block (ram,0x09741e) */
/* WARNING: Removing unreachable block (ram,0x09741a) */
/* WARNING: Removing unreachable block (ram,0x0973ee) */
/* WARNING: Removing unreachable block (ram,0x0973de) */
/* WARNING: Removing unreachable block (ram,0x0973d8) */
/* WARNING: Removing unreachable block (ram,0x0973d4) */
/* WARNING: Removing unreachable block (ram,0x09747e) */
/* WARNING: Removing unreachable block (ram,0x09740a) */
/* WARNING: Removing unreachable block (ram,0x097404) */
/* WARNING: Removing unreachable block (ram,0x097400) */
/* WARNING: Removing unreachable block (ram,0x0973fa) */
/* WARNING: Removing unreachable block (ram,0x0973f6) */
/* WARNING: Removing unreachable block (ram,0x0973c4) */
/* WARNING: Removing unreachable block (ram,0x0973c0) */
/* WARNING: Removing unreachable block (ram,0x0973ae) */
/* WARNING: Removing unreachable block (ram,0x09739e) */
/* WARNING: Removing unreachable block (ram,0x097486) */
/* WARNING: Removing unreachable block (ram,0x097498) */
/* WARNING: Removing unreachable block (ram,0x097490) */
/* WARNING: Removing unreachable block (ram,0x097390) */
/* WARNING: Removing unreachable block (ram,0x09738c) */
/* WARNING: Removing unreachable block (ram,0x097388) */
/* WARNING: Removing unreachable block (ram,0x097372) */
/* WARNING: Removing unreachable block (ram,0x09736e) */
/* WARNING: Removing unreachable block (ram,0x097362) */
/* WARNING: Removing unreachable block (ram,0x097358) */
/* WARNING: Removing unreachable block (ram,0x097398) */
/* WARNING: Removing unreachable block (ram,0x0973a4) */
/* WARNING: Removing unreachable block (ram,0x097560) */
/* WARNING: Removing unreachable block (ram,0x097564) */
/* WARNING: Removing unreachable block (ram,0x0975fe) */
/* WARNING: Removing unreachable block (ram,0x0974e6) */
/* WARNING: Removing unreachable block (ram,0x09748a) */
/* WARNING: Removing unreachable block (ram,0x09748c) */

void egs52_update_near_c16e_097350(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  byte bVar8;
  char cVar9;
  uchar uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  cVar9 = UNK_00c16e;
  if ((cVar9 != '\x01') && (cVar9 = UNK_00c168, cVar9 != '\x01')) {
    UNK_00c16e = 1;
    cVar9 = UNK_00f804;
    if (cVar9 == '\0') {
      UNK_00c169 = 0;
      uVar6 = Ram00c164;
      Ram00c16c = uVar6;
      while( true ) {
        iVar5 = Ram00c16c;
        if ((iVar5 == 0) || (cVar9 = UNK_00c169, cVar9 != '\0')) goto LAB_097602;
        iVar5 = Ram00c16c;
        uVar13 = iVar5 + 2;
        uVar2 = 0x24;
        if (((uVar13 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar13 & 0xc000) != 0x4000 &&
            (uVar2 = 0x2c, (uVar13 & 0xc000) != 0x8000)))) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar13 & 0x3fff)) != '\0') break;
        uVar13 = Ram00c16c;
        uVar2 = 0x24;
        if ((((uVar13 & 0xc000) != 0) && (uVar2 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        Ram00c16c = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar13 & 0x3fff));
      }
      cVar9 = UNK_00c169;
      if (cVar9 == '\0') {
        uVar2 = 0x24;
        if ((((uVar13 & 0xc000) != 0) && (uVar2 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cVar9 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar13 & 0x3fff));
        if (cVar9 == '\x03') {
          iVar5 = Ram00c16c;
          uVar2 = iVar5 + 8;
          uVar13 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar13 = 3;
          }
          if (*(uint *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xff) {
            iVar5 = Ram00c16c;
            uVar2 = iVar5 + 8;
            uVar13 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar13 = 3;
            }
            UNK_00c16a = 0;
            uVar11 = iVar5 + 6;
            uVar12 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            uVar1 = iVar5 + 4;
            uVar3 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            cVar9 = egs52_update_near_c180_0981ec
                              (*(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)),
                               *(uint *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xff,
                               *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
            if (cVar9 != '\0') {
              UNK_00f804 = 1;
            }
          }
          else {
            UNK_00c16a = 1;
            uVar2 = iVar5 + 6;
            uVar13 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar13 = 3;
            }
            uVar11 = iVar5 + 4;
            uVar12 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            cVar9 = egs52_update_near_c180_0981ec
                              (*(undefined2 *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)),0xfe,
                               *(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)));
            if (cVar9 != '\0') {
              UNK_00f804 = 2;
            }
          }
        }
        else if ((cVar9 == '\x01') || (cVar9 == '\x02')) {
          iVar5 = Ram00c16c;
          uVar2 = iVar5 + 8;
          uVar13 = 0x24;
          if (((uVar2 & 0xc000) != 0) &&
             ((uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
              (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
            uVar13 = 3;
          }
          if (*(uint *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xff) {
            iVar5 = Ram00c16c;
            uVar2 = iVar5 + 8;
            uVar13 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar13 = 3;
            }
            UNK_00c16a = 0;
            uVar11 = iVar5 + 6;
            uVar12 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            uVar1 = iVar5 + 4;
            uVar3 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            cVar9 = egs52_update_near_c180_098220
                              (*(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)),
                               *(uint *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xff,
                               *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
            if (cVar9 != '\0') {
              UNK_00f804 = 1;
            }
          }
          else {
            UNK_00c16a = 1;
            uVar2 = iVar5 + 6;
            uVar13 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar13 = 3;
            }
            uVar11 = iVar5 + 4;
            uVar12 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            cVar9 = egs52_update_near_c180_098220
                              (*(undefined2 *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)),0xfe,
                               *(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)));
            if (cVar9 != '\0') {
              UNK_00f804 = 2;
            }
          }
        }
      }
    }
    else if (cVar9 == '\x01') {
      iVar5 = Ram00c16c;
      uVar2 = iVar5 + 2;
      uVar13 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar13 = 3;
      }
      if (*(char *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) == '\x03') {
        uVar10 = egs52_test_fd02_bit0_clear();
        if (uVar10 != '\0') {
          iVar5 = Ram00c16c;
          uVar2 = iVar5 + 2;
          uVar13 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar13 = 3;
          }
          *(undefined1 *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
          UNK_00f804 = 0;
        }
      }
      else {
        uVar10 = egs52_test_fd02_bit0_clear();
        if (uVar10 != '\0') {
          UNK_00c169 = 0;
          uVar2 = Ram00c164;
          uVar13 = 0;
          while( true ) {
            uVar12 = uVar2;
            uVar2 = uVar12 + 2;
            uVar11 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar11 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar11 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar11 = 3;
            }
            if ((*(char *)((uint3)uVar11 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') ||
               (cVar9 = UNK_00c169, cVar9 != '\0')) break;
            uVar2 = 0x24;
            if ((((uVar12 & 0xc000) != 0) && (uVar2 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar12 & 0x3fff));
            uVar13 = uVar12;
          }
          uVar10 = egs52_disable_interrupts_save();
          cVar9 = UNK_00c169;
          if (cVar9 == '\0') {
            if (uVar13 == 0) {
              uVar13 = Ram00c16c;
              uVar2 = 0x24;
              if ((((uVar13 & 0xc000) != 0) && (uVar2 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              Ram00c164 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar13 & 0x3fff));
            }
            else {
              uVar11 = Ram00c16c;
              uVar2 = 0x24;
              if ((((uVar11 & 0xc000) != 0) && (uVar2 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              uVar12 = 0x24;
              if ((((uVar13 & 0xc000) != 0) && (uVar12 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
                 (uVar12 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
                uVar12 = 3;
              }
              *(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar13 & 0x3fff)) =
                   *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar11 & 0x3fff));
            }
            if (uVar10 != '\0') {
              egs52_enable_interrupts();
            }
            iVar5 = Ram00c16c;
            uVar2 = iVar5 + 2;
            uVar13 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar13 = 3;
            }
            if (*(char *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) == '\x01') {
              uVar2 = iVar5 + 4;
              uVar13 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar13 = 3;
              }
              egs52_free_small_heap_block
                        (*(undefined2 *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)));
            }
            uVar6 = Ram00c16c;
            egs52_free_small_heap_block(uVar6);
            UNK_00f804 = 0;
          }
          else if (uVar10 != '\0') {
            egs52_enable_interrupts();
          }
        }
      }
    }
    else if ((cVar9 == '\x02') && (uVar10 = egs52_test_fd02_bit0_clear(), uVar10 != '\0')) {
      iVar5 = Ram00c16c;
      uVar2 = iVar5 + 6;
      uVar13 = 0x24;
      if (((uVar2 & 0xc000) != 0) &&
         ((uVar13 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar13 = 0x2c, (uVar2 & 0xc000) != 0x8000))
         )) {
        uVar13 = 3;
      }
      bVar8 = UNK_00c16a;
      iVar5 = (uint)bVar8 * 0xfe;
      iVar7 = Ram00c16c;
      uVar11 = iVar7 + 4;
      uVar12 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      iVar4 = *(int *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)) + iVar5;
      uVar12 = iVar7 + 8;
      uVar11 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar11 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      if (iVar5 + 0xfeU < *(uint *)((uint3)uVar11 << 0xe | (uint3)(uVar12 & 0x3fff))) {
        uVar11 = 0xfe;
      }
      else {
        uVar11 = 0x24;
        if ((((uVar12 & 0xc000) != 0) && (uVar11 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
           (uVar11 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
          uVar11 = 3;
        }
        uVar11 = *(int *)((uint3)uVar11 << 0xe | (uint3)(uVar12 & 0x3fff)) + (uint)bVar8 * -0xfe &
                 0xff;
        UNK_00c16a = 0;
      }
      iVar7 = Ram00c16c;
      uVar12 = iVar7 + 2;
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cVar9 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff));
      if (cVar9 == '\x03') {
        cVar9 = egs52_update_near_c180_0981ec(uVar11,iVar4);
        if (cVar9 != '\0') {
          cVar9 = UNK_00c16a;
          if (cVar9 == '\0') {
            UNK_00f804 = 1;
          }
          else {
            cVar9 = UNK_00c16a;
            UNK_00c16a = cVar9 + '\x01';
          }
        }
      }
      else if ((cVar9 == '\x01') || (cVar9 == '\x02')) {
        cVar9 = egs52_update_near_c180_098220
                          (*(int *)((uint3)uVar13 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar5,uVar11,
                           iVar4);
        if (cVar9 != '\0') {
          cVar9 = UNK_00c16a;
          if (cVar9 == '\0') {
            UNK_00f804 = 1;
          }
          else {
            cVar9 = UNK_00c16a;
            UNK_00c16a = cVar9 + '\x01';
          }
        }
      }
      else {
        UNK_00f804 = 0;
      }
    }
LAB_097602:
    UNK_00c16e = 0;
  }
  return;
}


