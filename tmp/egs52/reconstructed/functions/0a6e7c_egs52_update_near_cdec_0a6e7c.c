/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6e7c; FLS offset 0x026e7c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a6f36) */
/* WARNING: Removing unreachable block (ram,0x0a6f3e) */
/* WARNING: Removing unreachable block (ram,0x0a6f2a) */
/* WARNING: Removing unreachable block (ram,0x0a6f26) */
/* WARNING: Removing unreachable block (ram,0x0a6f90) */
/* WARNING: Removing unreachable block (ram,0x0a6f8c) */
/* WARNING: Removing unreachable block (ram,0x0a6f84) */
/* WARNING: Removing unreachable block (ram,0x0a6f7e) */
/* WARNING: Removing unreachable block (ram,0x0a6f7a) */
/* WARNING: Removing unreachable block (ram,0x0a6f08) */
/* WARNING: Removing unreachable block (ram,0x0a6f9c) */
/* WARNING: Removing unreachable block (ram,0x0a6ef0) */
/* WARNING: Removing unreachable block (ram,0x0a6fc4) */
/* WARNING: Removing unreachable block (ram,0x0a6fde) */
/* WARNING: Removing unreachable block (ram,0x0a6fd8) */
/* WARNING: Removing unreachable block (ram,0x0a6fea) */
/* WARNING: Removing unreachable block (ram,0x0a7082) */
/* WARNING: Removing unreachable block (ram,0x0a706a) */
/* WARNING: Removing unreachable block (ram,0x0a7062) */
/* WARNING: Removing unreachable block (ram,0x0a705e) */
/* WARNING: Removing unreachable block (ram,0x0a705a) */
/* WARNING: Removing unreachable block (ram,0x0a7056) */
/* WARNING: Removing unreachable block (ram,0x0a703c) */
/* WARNING: Removing unreachable block (ram,0x0a7036) */
/* WARNING: Removing unreachable block (ram,0x0a7026) */
/* WARNING: Removing unreachable block (ram,0x0a7010) */
/* WARNING: Removing unreachable block (ram,0x0a7004) */
/* WARNING: Removing unreachable block (ram,0x0a7000) */
/* WARNING: Removing unreachable block (ram,0x0a6ff2) */
/* WARNING: Removing unreachable block (ram,0x0a71b8) */
/* WARNING: Removing unreachable block (ram,0x0a718c) */
/* WARNING: Removing unreachable block (ram,0x0a717e) */
/* WARNING: Removing unreachable block (ram,0x0a717a) */
/* WARNING: Removing unreachable block (ram,0x0a7170) */
/* WARNING: Removing unreachable block (ram,0x0a716c) */
/* WARNING: Removing unreachable block (ram,0x0a7168) */
/* WARNING: Removing unreachable block (ram,0x0a7164) */
/* WARNING: Removing unreachable block (ram,0x0a715c) */
/* WARNING: Removing unreachable block (ram,0x0a7156) */
/* WARNING: Removing unreachable block (ram,0x0a7152) */
/* WARNING: Removing unreachable block (ram,0x0a714e) */
/* WARNING: Removing unreachable block (ram,0x0a71a6) */
/* WARNING: Removing unreachable block (ram,0x0a71a0) */
/* WARNING: Removing unreachable block (ram,0x0a7130) */
/* WARNING: Removing unreachable block (ram,0x0a7128) */
/* WARNING: Removing unreachable block (ram,0x0a711a) */
/* WARNING: Removing unreachable block (ram,0x0a7116) */
/* WARNING: Removing unreachable block (ram,0x0a710c) */
/* WARNING: Removing unreachable block (ram,0x0a7108) */
/* WARNING: Removing unreachable block (ram,0x0a7124) */
/* WARNING: Removing unreachable block (ram,0x0a7120) */
/* WARNING: Removing unreachable block (ram,0x0a7102) */
/* WARNING: Removing unreachable block (ram,0x0a70fe) */
/* WARNING: Removing unreachable block (ram,0x0a70fa) */
/* WARNING: Removing unreachable block (ram,0x0a70f6) */
/* WARNING: Removing unreachable block (ram,0x0a70dc) */
/* WARNING: Removing unreachable block (ram,0x0a70d6) */
/* WARNING: Removing unreachable block (ram,0x0a70c6) */
/* WARNING: Removing unreachable block (ram,0x0a70b0) */
/* WARNING: Removing unreachable block (ram,0x0a70a4) */
/* WARNING: Removing unreachable block (ram,0x0a70a0) */
/* WARNING: Removing unreachable block (ram,0x0a76c8) */
/* WARNING: Removing unreachable block (ram,0x0a766e) */
/* WARNING: Removing unreachable block (ram,0x0a7660) */
/* WARNING: Removing unreachable block (ram,0x0a76b4) */
/* WARNING: Removing unreachable block (ram,0x0a76aa) */
/* WARNING: Removing unreachable block (ram,0x0a76a4) */
/* WARNING: Removing unreachable block (ram,0x0a769e) */
/* WARNING: Removing unreachable block (ram,0x0a7694) */
/* WARNING: Removing unreachable block (ram,0x0a7690) */
/* WARNING: Removing unreachable block (ram,0x0a76be) */
/* WARNING: Removing unreachable block (ram,0x0a7638) */
/* WARNING: Removing unreachable block (ram,0x0a7592) */
/* WARNING: Removing unreachable block (ram,0x0a75a0) */
/* WARNING: Removing unreachable block (ram,0x0a759c) */
/* WARNING: Removing unreachable block (ram,0x0a758a) */
/* WARNING: Removing unreachable block (ram,0x0a7586) */
/* WARNING: Removing unreachable block (ram,0x0a75b8) */
/* WARNING: Removing unreachable block (ram,0x0a75b4) */
/* WARNING: Removing unreachable block (ram,0x0a757a) */
/* WARNING: Removing unreachable block (ram,0x0a7576) */
/* WARNING: Removing unreachable block (ram,0x0a75f6) */
/* WARNING: Removing unreachable block (ram,0x0a75f2) */
/* WARNING: Removing unreachable block (ram,0x0a75e2) */
/* WARNING: Removing unreachable block (ram,0x0a75de) */
/* WARNING: Removing unreachable block (ram,0x0a75da) */
/* WARNING: Removing unreachable block (ram,0x0a7570) */
/* WARNING: Removing unreachable block (ram,0x0a7624) */
/* WARNING: Removing unreachable block (ram,0x0a7620) */
/* WARNING: Removing unreachable block (ram,0x0a7618) */
/* WARNING: Removing unreachable block (ram,0x0a7612) */
/* WARNING: Removing unreachable block (ram,0x0a760e) */
/* WARNING: Removing unreachable block (ram,0x0a760a) */
/* WARNING: Removing unreachable block (ram,0x0a7630) */
/* WARNING: Removing unreachable block (ram,0x0a755e) */
/* WARNING: Removing unreachable block (ram,0x0a74b2) */
/* WARNING: Removing unreachable block (ram,0x0a74a6) */
/* WARNING: Removing unreachable block (ram,0x0a74d8) */
/* WARNING: Removing unreachable block (ram,0x0a74d2) */
/* WARNING: Removing unreachable block (ram,0x0a74a0) */
/* WARNING: Removing unreachable block (ram,0x0a754a) */
/* WARNING: Removing unreachable block (ram,0x0a7520) */
/* WARNING: Removing unreachable block (ram,0x0a751a) */
/* WARNING: Removing unreachable block (ram,0x0a753e) */
/* WARNING: Removing unreachable block (ram,0x0a7538) */
/* WARNING: Removing unreachable block (ram,0x0a7530) */
/* WARNING: Removing unreachable block (ram,0x0a7514) */
/* WARNING: Removing unreachable block (ram,0x0a750c) */
/* WARNING: Removing unreachable block (ram,0x0a74fa) */
/* WARNING: Removing unreachable block (ram,0x0a74ec) */
/* WARNING: Removing unreachable block (ram,0x0a74e8) */
/* WARNING: Removing unreachable block (ram,0x0a74e4) */
/* WARNING: Removing unreachable block (ram,0x0a7556) */
/* WARNING: Removing unreachable block (ram,0x0a748e) */
/* WARNING: Removing unreachable block (ram,0x0a742e) */
/* WARNING: Removing unreachable block (ram,0x0a741e) */
/* WARNING: Removing unreachable block (ram,0x0a747a) */
/* WARNING: Removing unreachable block (ram,0x0a746e) */
/* WARNING: Removing unreachable block (ram,0x0a7468) */
/* WARNING: Removing unreachable block (ram,0x0a7460) */
/* WARNING: Removing unreachable block (ram,0x0a7456) */
/* WARNING: Removing unreachable block (ram,0x0a7452) */
/* WARNING: Removing unreachable block (ram,0x0a7396) */
/* WARNING: Removing unreachable block (ram,0x0a73e2) */
/* WARNING: Removing unreachable block (ram,0x0a73c8) */
/* WARNING: Removing unreachable block (ram,0x0a73c2) */
/* WARNING: Removing unreachable block (ram,0x0a73be) */
/* WARNING: Removing unreachable block (ram,0x0a73ba) */
/* WARNING: Removing unreachable block (ram,0x0a735e) */
/* WARNING: Removing unreachable block (ram,0x0a72fe) */
/* WARNING: Removing unreachable block (ram,0x0a734a) */
/* WARNING: Removing unreachable block (ram,0x0a733e) */
/* WARNING: Removing unreachable block (ram,0x0a7338) */
/* WARNING: Removing unreachable block (ram,0x0a7326) */
/* WARNING: Removing unreachable block (ram,0x0a7322) */
/* WARNING: Removing unreachable block (ram,0x0a7356) */
/* WARNING: Removing unreachable block (ram,0x0a72be) */
/* WARNING: Removing unreachable block (ram,0x0a72b2) */
/* WARNING: Removing unreachable block (ram,0x0a72ae) */
/* WARNING: Removing unreachable block (ram,0x0a72aa) */
/* WARNING: Removing unreachable block (ram,0x0a72a6) */
/* WARNING: Removing unreachable block (ram,0x0a727a) */
/* WARNING: Removing unreachable block (ram,0x0a7274) */
/* WARNING: Removing unreachable block (ram,0x0a7284) */
/* WARNING: Removing unreachable block (ram,0x0a725e) */
/* WARNING: Removing unreachable block (ram,0x0a724e) */
/* WARNING: Removing unreachable block (ram,0x0a724a) */
/* WARNING: Removing unreachable block (ram,0x0a723c) */
/* WARNING: Removing unreachable block (ram,0x0a7234) */
/* WARNING: Removing unreachable block (ram,0x0a722e) */
/* WARNING: Removing unreachable block (ram,0x0a722a) */
/* WARNING: Removing unreachable block (ram,0x0a7226) */
/* WARNING: Removing unreachable block (ram,0x0a721c) */
/* WARNING: Removing unreachable block (ram,0x0a7210) */
/* WARNING: Removing unreachable block (ram,0x0a720c) */
/* WARNING: Removing unreachable block (ram,0x0a7204) */
/* WARNING: Removing unreachable block (ram,0x0a728e) */
/* WARNING: Removing unreachable block (ram,0x0a71ec) */
/* WARNING: Removing unreachable block (ram,0x0a71e4) */
/* WARNING: Removing unreachable block (ram,0x0a7298) */
/* WARNING: Removing unreachable block (ram,0x0a71d6) */
/* WARNING: Removing unreachable block (ram,0x0a72a2) */
/* WARNING: Removing unreachable block (ram,0x0a71ca) */
/* WARNING: Removing unreachable block (ram,0x0a6e8c) */
/* WARNING: Removing unreachable block (ram,0x0a6e88) */
/* WARNING: Removing unreachable block (ram,0x0a6e84) */
/* WARNING: Removing unreachable block (ram,0x0a71c0) */
/* WARNING: Removing unreachable block (ram,0x0a71f4) */
/* WARNING: Removing unreachable block (ram,0x0a7266) */
/* WARNING: Removing unreachable block (ram,0x0a72c6) */
/* WARNING: Removing unreachable block (ram,0x0a732a) */
/* WARNING: Removing unreachable block (ram,0x0a72ee) */
/* WARNING: Removing unreachable block (ram,0x0a73ee) */
/* WARNING: Removing unreachable block (ram,0x0a73d6) */
/* WARNING: Removing unreachable block (ram,0x0a7386) */
/* WARNING: Removing unreachable block (ram,0x0a73f6) */
/* WARNING: Removing unreachable block (ram,0x0a7486) */
/* WARNING: Removing unreachable block (ram,0x0a745a) */
/* WARNING: Removing unreachable block (ram,0x0a7534) */
/* WARNING: Removing unreachable block (ram,0x0a74bc) */
/* WARNING: Removing unreachable block (ram,0x0a7698) */
/* WARNING: Removing unreachable block (ram,0x0a708a) */
/* WARNING: Removing unreachable block (ram,0x0a7188) */
/* WARNING: Removing unreachable block (ram,0x0a7072) */
/* WARNING: Removing unreachable block (ram,0x0a7076) */
/* WARNING: Removing unreachable block (ram,0x0a6fcc) */
/* WARNING: Removing unreachable block (ram,0x0a6fb0) */
/* WARNING: Removing unreachable block (ram,0x0a6fa8) */
/* WARNING: Removing unreachable block (ram,0x0a7330) */
/* WARNING: Removing unreachable block (ram,0x0a73d0) */
/* WARNING: Removing unreachable block (ram,0x0a6f30) */
/* WARNING: Removing unreachable block (ram,0x0a6f42) */
/* WARNING: Removing unreachable block (ram,0x0a6f5a) */
/* WARNING: Removing unreachable block (ram,0x0a6f56) */
/* WARNING: Removing unreachable block (ram,0x0a6f4a) */
/* WARNING: Removing unreachable block (ram,0x0a6f16) */
/* WARNING: Removing unreachable block (ram,0x0a6f12) */
/* WARNING: Removing unreachable block (ram,0x0a6f76) */
/* WARNING: Removing unreachable block (ram,0x0a6efc) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f469 : 0x0a6ef0 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_cdec_0a6e7c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar10;
  int iVar11;
  uchar uVar12;
  char cVar13;
  uint uVar14;
  undefined2 uVar15;
  int iVar16;
  
  cRam00f581 = '\0';
  uVar14 = 0x24;
  if ((((uRam00f462 & 0xc000) != 0) && (uVar14 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
     (uVar14 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
    uVar14 = 3;
  }
  cVar13 = *(char *)((uint3)uVar14 << 0xe | (uint3)(uRam00f462 & 0x3fff));
  if (cVar13 == ' ') {
    if ((bRam00f469 == 3) || (uVar14 = Ram00fdea, (uVar14 & 4) != 0)) {
      if ((bRam00f57f & 10) == 0) {
        cRam00f581 = '3';
      }
      else {
        uVar14 = uRam00f462 + 1;
        uVar5 = Ram00fdea;
        if ((uVar5 & 4) == 0) {
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 4;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
          cRam00f581 = 'x';
          iRam00f464 = iRam00f464 + (uint)bRam00f469;
          Ram00cdec = 0x78;
          Ram00cdee = 0;
        }
        else {
          uVar5 = Ram00cdec;
          uVar1 = Ram00cdee;
          if (uVar1 == uVar5 < 0x78 && uVar5 == 0x78) {
            uVar5 = 0x24;
            if ((((uVar14 & 0xc000) != 0) && (uVar5 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            uVar14 = egs52_update_near_c346_09db38
                               (*(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar14 & 0x3fff)));
            Ram00cdec = uVar14 & 0xff;
            Ram00cdee = 0;
            if ((uVar14 & 0xff) != 0x78) {
              uVar14 = Ram00fdea;
              Ram00fdea = uVar14 | 8;
            }
          }
          else {
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfffb;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
            iVar11 = Ram00cdee;
            iVar16 = Ram00cdec;
            if (iVar11 == 0 && iVar16 == 0) {
              cRam00f581 = '\0';
              bRam00f469 = 2;
            }
            else {
              cRam00f581 = UNK_00cdec;
            }
          }
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '!') {
    if (bRam00f469 == 2) {
      egs52_transform_far_memory_09df5c();
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '#') {
    if (bRam00f469 == 2) {
      egs52_update_near_c32b_09de7a();
      cRam00f581 = '\0';
      bRam00f469 = 2;
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '$') {
    if ((bRam00f469 == 8) || (uVar14 = Ram00fdea, (uVar14 & 4) != 0)) {
      uVar14 = uRam00f462 + 4;
      uVar5 = 0x24;
      if ((((uVar14 & 0xc000) != 0) && (uVar5 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      uVar1 = uRam00f462 + 3;
      uVar6 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      uVar2 = uRam00f462 + 2;
      uVar7 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar3 = uRam00f462 + 6;
      uVar8 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      uVar4 = uRam00f462 + 5;
      uVar9 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar9 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      uVar14 = egs52_update_near_c043_093e10
                         (CONCAT11(*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)),
                                   *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar14 & 0x3fff))),
                          *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)),
                          (uint)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                          (uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar4 & 0x3fff)) * 0x100);
      Ram00cdec = uVar14 & 0xff;
      Ram00cdee = 0;
      iVar16 = Ram00cdee;
      iVar11 = Ram00cdec;
      if (iVar16 == 0 && iVar11 == 0) {
        bRam00f469 = 2;
      }
      else {
        cRam00f581 = UNK_00cdec;
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '\"') {
    if ((bRam00f469 == 8) || (uVar14 = Ram00fdea, (uVar14 & 4) != 0)) {
      uVar14 = Ram00fdea;
      if ((uVar14 & 4) == 0) {
        uVar14 = uRam00f462 + 4;
        uVar5 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar5 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar1 = uRam00f462 + 3;
        uVar6 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar2 = uRam00f462 + 2;
        uVar7 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar7 = 3;
        }
        uVar3 = uRam00f462 + 6;
        uVar8 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        uVar4 = uRam00f462 + 5;
        uVar9 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar9 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        uVar14 = egs52_update_near_c043_093e10
                           (CONCAT11(*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)),
                                     *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar14 & 0x3fff))
                                    ),*(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff))
                            ,(uint)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                             (uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar4 & 0x3fff)) * 0x100)
        ;
        Ram00cdec = uVar14 & 0xff;
        Ram00cdee = 0;
        iVar11 = Ram00cdee;
        iVar16 = Ram00cdec;
        if (iVar11 == 0 && iVar16 == 0) {
          uVar14 = Ram00fdf2;
          iVar16 = Ram00fdf4;
          Ram00cdec = uVar14 + 0x1194;
          Ram00cdee = iVar16 + (uint)(0xee6b < uVar14);
        }
        else {
          cRam00f581 = UNK_00cdec;
        }
      }
      if (cRam00f581 == '\0') {
        uVar12 = egs52_read_indexed_word_c044((uchar *)(iRam00f464 + 1));
        if (uVar12 == '\0') {
          uVar14 = Ram00fdea;
          if (((uVar14 & 8) == 0) && (uVar14 = Ram00fdea, (uVar14 & 4) != 0)) {
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 | 8;
          }
          else {
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfffb;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
            cRam00f581 = '\0';
            bRam00f469 = 4;
          }
        }
        else {
          uVar14 = Ram00fdea;
          if (((uVar14 & 8) == 0) && (uVar14 = Ram00fdea, (uVar14 & 4) != 0)) {
            uVar14 = Ram00fdf2;
            uVar6 = Ram00fdf4;
            uVar5 = Ram00cdec;
            uVar1 = Ram00cdee;
            if ((uVar6 - uVar1 != (uint)(uVar14 < uVar5) || uVar14 != uVar5) &&
                (uVar1 <= uVar6 && (uVar6 != uVar1 || uVar14 >= uVar5))) {
              uVar14 = Ram00fdea;
              Ram00fdea = uVar14 | 8;
              uVar14 = Ram00fdf2;
              iVar16 = Ram00fdf4;
              Ram00cdec = uVar14 + 0x1194;
              Ram00cdee = iVar16 + (uint)(0xee6b < uVar14);
            }
          }
          else {
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 | 4;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
            cRam00f581 = 'x';
            iRam00f464 = iRam00f464 + (uint)bRam00f469;
          }
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == -5) {
    if (bRam00f469 == 2) {
      if ((bRam00f57f & 10) == 0) {
        cRam00f581 = '3';
      }
      else if (cRam00f580 == '\x01') {
        uRam00f3fe = 0x65;
        uRam00f3ff = 0xac;
        if (cRam083e7c == -2) {
          uRam00f400 = 0xca;
          uRam00f401 = 0x35;
          uRam00f3ea = uRam00f462 + 0x10;
          uVar14 = 0x24;
          if ((((uRam00f3ea & 0xc000) != 0) && (uVar14 = 0x21, (uRam00f3ea & 0xc000) != 0x4000)) &&
             (uVar14 = 0x2c, (uRam00f3ea & 0xc000) != 0x8000)) {
            uVar14 = 3;
          }
          *(undefined1 *)((uint3)uVar14 << 0xe | (uint3)(uRam00f3ea & 0x3fff)) = 0xfc;
          uRam00f3e6 = 0x3e7c;
          uRam00f3e8 = 8;
          uRam00f3ec = 1;
          UNK_00f615 = 0x21;
          uVar12 = egs52_disable_interrupts_save();
          (*(code *)((uint3)uRam08020e << 0x10 | (uint3)uRam08020c))();
          if (uVar12 != '\0') {
            egs52_enable_interrupts();
          }
          UNK_00f615 = 0;
          if ((cRam083e7c == -4) && (uVar14 = Ram00fdee, (uVar14 & 2) != 0)) {
            cRam00f581 = '\0';
            bRam00f469 = 2;
          }
          else {
            cRam00f581 = '\"';
          }
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        cRam00f581 = -0x80;
      }
      uRam00f401 = 0;
      uRam00f400 = 0;
      uRam00f3ff = 0;
      uRam00f3fe = 0;
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '0') {
    if (bRam00f469 == 2) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        cVar13 = egs52_update_near_caa6_0a3d94();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 4;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 8;
          cRam00f581 = 'x';
          iRam00f464 = iRam00f464 + (uint)bRam00f469;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          bRam00f469 = 2;
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        cVar13 = egs52_update_near_caa6_0a3d94();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdec;
          Ram00fdec = uVar14 | 4;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
        else {
          cRam00f581 = '\"';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '1') {
    if (bRam00f469 == 2) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        cVar13 = egs52_update_near_caaa_0a3e0c();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 4;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 8;
          cRam00f581 = 'x';
          iRam00f464 = iRam00f464 + (uint)bRam00f469;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          bRam00f469 = 2;
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        cVar13 = egs52_update_near_caaa_0a3e0c();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdec;
          Ram00fdec = uVar14 | 4;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
        else {
          cRam00f581 = '\"';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '2') {
    if (bRam00f469 == 2) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        cVar13 = egs52_update_near_c0d4_095f04();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 4;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 8;
          cRam00f581 = 'x';
          iRam00f464 = iRam00f464 + (uint)bRam00f469;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          bRam00f469 = 2;
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        cVar13 = egs52_update_near_c0d4_095f04();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdec;
          Ram00fdec = uVar14 | 4;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
        else {
          cRam00f581 = '\"';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '3') {
    if (bRam00f469 == 3) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        uVar14 = uRam00f462 + 1;
        uVar5 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar5 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar10 = *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar14 & 0x3fff));
        UNK_00cde8 = uVar10;
        iVar16 = egs52_update_near_d447_0d0000(uVar10,0xcde6);
        Ram00cdea = iVar16;
        if (iVar16 == 0) {
          cRam00f581 = '\"';
        }
        else if (iVar16 == 1) {
          cVar13 = UNK_00cde8;
          if (cVar13 == '\0') {
            cRam00f581 = '\0';
            bRam00f469 = 2;
          }
          else {
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 | 4;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 | 8;
            cRam00f581 = 'x';
            iRam00f464 = iRam00f464 + (uint)bRam00f469;
          }
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        iVar16 = Ram00cde6;
        if (iVar16 == 0) {
          uVar10 = UNK_00cde8;
          uVar15 = egs52_update_near_d447_0d0000(uVar10,0xcde6);
          Ram00cdea = uVar15;
          uVar14 = Ram00fdec;
          Ram00fdec = uVar14 | 4;
        }
        else {
          uVar15 = Ram00cde6;
          cVar13 = egs52_update_near_caa4_0a3d02(uVar15,0,0);
          if (cVar13 == '\x03') {
            cRam00f581 = '\0';
            bRam00f469 = 2;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfffb;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
          }
          else {
            uVar14 = Ram00fdec;
            Ram00fdec = uVar14 | 4;
          }
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '4') {
    if (bRam00f469 == 2) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        uVar14 = Ram00fdea;
        Ram00fdea = uVar14 | 4;
        uVar14 = Ram00fdea;
        Ram00fdea = uVar14 | 8;
        cRam00f581 = 'x';
        iRam00f464 = iRam00f464 + 2;
        Ram00cdec = 0x78;
        Ram00cdee = 0;
      }
      else {
        iVar16 = Ram00cde4;
        if (iVar16 == 0) {
          uVar14 = Ram00cdec;
          uVar5 = Ram00cdee;
          if (uVar5 == uVar14 < 0x78 && uVar14 == 0x78) {
            uVar14 = egs52_update_near_c32a_09da5e();
            Ram00cdec = uVar14 & 0xff;
            Ram00cdee = 0;
            uVar14 = Ram00fdec;
            Ram00fdec = uVar14 | 4;
          }
          else {
            iVar11 = Ram00cdee;
            iVar16 = Ram00cdec;
            if (iVar11 == 0 && iVar16 == 0) {
              Ram00cde4 = 1;
              uVar14 = Ram00fdec;
              Ram00fdec = uVar14 | 4;
            }
            else {
              cRam00f581 = UNK_00cdec;
              uVar14 = Ram00fdea;
              Ram00fdea = uVar14 & 0xfffb;
              uVar14 = Ram00fdea;
              Ram00fdea = uVar14 & 0xfff7;
            }
          }
        }
        else {
          cVar13 = egs52_update_near_caa6_0a3d94();
          if (cVar13 == '\x01') {
            uVar14 = Ram00fdec;
            Ram00fdec = uVar14 | 4;
          }
          else if (cVar13 == '\x02') {
            bRam00f469 = 2;
            cRam00f581 = '\0';
            Ram00cde4 = 0;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfffb;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
          }
          else {
            cRam00f581 = '\"';
            Ram00cde4 = 0;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfffb;
            uVar14 = Ram00fdea;
            Ram00fdea = uVar14 & 0xfff7;
          }
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else if (cVar13 == '5') {
    if (bRam00f469 == 2) {
      uVar14 = Ram00fdea;
      if (((uVar14 & 4) == 0) || (uVar14 = Ram00fdea, (uVar14 & 8) == 0)) {
        cVar13 = egs52_update_near_caaf_0a3eba();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 4;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 | 8;
          cRam00f581 = 'x';
          iRam00f464 = iRam00f464 + (uint)bRam00f469;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          bRam00f469 = 2;
        }
        else {
          cRam00f581 = '\"';
        }
      }
      else {
        cVar13 = egs52_update_near_caaf_0a3eba();
        if (cVar13 == '\x01') {
          uVar14 = Ram00fdec;
          Ram00fdec = uVar14 | 4;
        }
        else if (cVar13 == '\x02') {
          cRam00f581 = '\0';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
        else {
          cRam00f581 = '\"';
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfffb;
          uVar14 = Ram00fdea;
          Ram00fdea = uVar14 & 0xfff7;
        }
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else {
    cRam00f581 = '\x12';
    uVar14 = Ram00fdec;
    Ram00fdec = uVar14 & 0xfffe;
  }
  return;
}


