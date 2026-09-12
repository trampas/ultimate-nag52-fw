/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a0302; FLS offset 0x020302.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x0a06fc) */
/* WARNING: Removing unreachable block (ram,0x0a06a8) */
/* WARNING: Removing unreachable block (ram,0x0a071a) */
/* WARNING: Removing unreachable block (ram,0x0a0708) */
/* WARNING: Removing unreachable block (ram,0x0a0688) */
/* WARNING: Removing unreachable block (ram,0x0a066e) */
/* WARNING: Removing unreachable block (ram,0x0a0654) */
/* WARNING: Removing unreachable block (ram,0x0a05ce) */
/* WARNING: Removing unreachable block (ram,0x0a05c2) */
/* WARNING: Removing unreachable block (ram,0x0a0640) */
/* WARNING: Removing unreachable block (ram,0x0a05f8) */
/* WARNING: Removing unreachable block (ram,0x0a06b8) */
/* WARNING: Removing unreachable block (ram,0x0a05ec) */
/* WARNING: Removing unreachable block (ram,0x0a059c) */
/* WARNING: Removing unreachable block (ram,0x0a05a8) */
/* WARNING: Removing unreachable block (ram,0x0a0660) */
/* WARNING: Removing unreachable block (ram,0x0a05e0) */
/* WARNING: Removing unreachable block (ram,0x0a074e) */
/* WARNING: Removing unreachable block (ram,0x0a05a4) */
/* WARNING: Removing unreachable block (ram,0x0a068c) */
/* WARNING: Removing unreachable block (ram,0x0a052e) */
/* WARNING: Removing unreachable block (ram,0x0a063c) */
/* WARNING: Removing unreachable block (ram,0x0a0598) */
/* WARNING: Removing unreachable block (ram,0x0a075a) */
/* WARNING: Removing unreachable block (ram,0x0a0650) */
/* WARNING: Removing unreachable block (ram,0x0a0622) */
/* WARNING: Removing unreachable block (ram,0x0a0584) */
/* WARNING: Removing unreachable block (ram,0x0a0566) */
/* WARNING: Removing unreachable block (ram,0x0a054e) */
/* WARNING: Removing unreachable block (ram,0x0a0532) */
/* WARNING: Removing unreachable block (ram,0x0a04fe) */
/* WARNING: Removing unreachable block (ram,0x0a04e4) */
/* WARNING: Removing unreachable block (ram,0x0a04fa) */
/* WARNING: Removing unreachable block (ram,0x0a04c4) */
/* WARNING: Removing unreachable block (ram,0x0a04f2) */
/* WARNING: Removing unreachable block (ram,0x0a04d8) */
/* WARNING: Removing unreachable block (ram,0x0a042c) */
/* WARNING: Removing unreachable block (ram,0x0a0440) */
/* WARNING: Removing unreachable block (ram,0x0a0468) */
/* WARNING: Removing unreachable block (ram,0x0a047a) */
/* WARNING: Removing unreachable block (ram,0x0a049e) */
/* WARNING: Removing unreachable block (ram,0x0a0406) */
/* WARNING: Removing unreachable block (ram,0x0a0486) */
/* WARNING: Removing unreachable block (ram,0x0a03fa) */
/* WARNING: Removing unreachable block (ram,0x0a0462) */
/* WARNING: Removing unreachable block (ram,0x0a03b8) */
/* WARNING: Removing unreachable block (ram,0x0a0456) */
/* WARNING: Removing unreachable block (ram,0x0a040a) */
/* WARNING: Removing unreachable block (ram,0x0a0394) */
/* WARNING: Removing unreachable block (ram,0x0a0392) */
/* WARNING: Removing unreachable block (ram,0x0a03e0) */
/* WARNING: Removing unreachable block (ram,0x0a041c) */
/* WARNING: Removing unreachable block (ram,0x0a0362) */
/* WARNING: Removing unreachable block (ram,0x0a03e2) */
/* WARNING: Removing unreachable block (ram,0x0a034e) */
/* WARNING: Removing unreachable block (ram,0x0a0382) */
/* WARNING: Removing unreachable block (ram,0x0a0416) */
/* WARNING: Removing unreachable block (ram,0x0a03c4) */
/* WARNING: Removing unreachable block (ram,0x0a0352) */
/* WARNING: Removing unreachable block (ram,0x0a0412) */
/* WARNING: Removing unreachable block (ram,0x0a03ce) */
/* WARNING: Removing unreachable block (ram,0x0a0380) */
/* WARNING: Removing unreachable block (ram,0x0a050c) */
/* WARNING: Removing unreachable block (ram,0x0a03ee) */
/* WARNING: Removing unreachable block (ram,0x0a03d0) */
/* WARNING: Removing unreachable block (ram,0x0a039e) */
/* WARNING: Removing unreachable block (ram,0x0a038c) */
/* WARNING: Removing unreachable block (ram,0x0a0374) */
/* WARNING: Removing unreachable block (ram,0x0a0330) */
/* WARNING: Removing unreachable block (ram,0x0a0324) */
/* WARNING: Removing unreachable block (ram,0x0a0320) */
/* WARNING: Removing unreachable block (ram,0x0a031c) */
/* WARNING: Removing unreachable block (ram,0x0a0518) */
/* WARNING: Removing unreachable block (ram,0x0a038e) */
/* WARNING: Removing unreachable block (ram,0x0a0438) */
/* WARNING: Removing unreachable block (ram,0x0a03da) */
/* WARNING: Removing unreachable block (ram,0x0a03dc) */
/* WARNING: Removing unreachable block (ram,0x0a046e) */
/* WARNING: Removing unreachable block (ram,0x0a0458) */
/* WARNING: Removing unreachable block (ram,0x0a0464) */
/* WARNING: Removing unreachable block (ram,0x0a0490) */
/* WARNING: Removing unreachable block (ram,0x0a044c) */
/* WARNING: Removing unreachable block (ram,0x0a04b0) */
/* WARNING: Removing unreachable block (ram,0x0a04c0) */
/* WARNING: Removing unreachable block (ram,0x0a04f6) */
/* WARNING: Removing unreachable block (ram,0x0a04cc) */
/* WARNING: Removing unreachable block (ram,0x0a0544) */
/* WARNING: Removing unreachable block (ram,0x0a055a) */
/* WARNING: Removing unreachable block (ram,0x0a056a) */
/* WARNING: Removing unreachable block (ram,0x0a0588) */
/* WARNING: Removing unreachable block (ram,0x0a05b6) */
/* WARNING: Removing unreachable block (ram,0x0a065c) */
/* WARNING: Removing unreachable block (ram,0x0a060a) */
/* WARNING: Removing unreachable block (ram,0x0a067c) */
/* WARNING: Removing unreachable block (ram,0x0a06b4) */
/* WARNING: Removing unreachable block (ram,0x0a06c6) */
/* WARNING: Removing unreachable block (ram,0x0a06d4) */
/* WARNING: Removing unreachable block (ram,0x0a06e0) */
/* WARNING: Removing unreachable block (ram,0x0a06f2) */
/* WARNING: Removing unreachable block (ram,0x0a069a) */
/* WARNING: Removing unreachable block (ram,0x0a0724) */
/* WARNING: Removing unreachable block (ram,0x0a070c) */
/* WARNING: Removing unreachable block (ram,0x0a06e4) */
/* WARNING: Removing unreachable block (ram,0x0a05fc) */
/* WARNING: Removing unreachable block (ram,0x0a05d2) */
/* WARNING: Removing unreachable block (ram,0x0a0502) */
/* WARNING: Removing unreachable block (ram,0x0a04bc) */
/* WARNING: Removing unreachable block (ram,0x0a0428) */
/* WARNING: Removing unreachable block (ram,0x0a046a) */
/* WARNING: Removing unreachable block (ram,0x0a0420) */
/* WARNING: Removing unreachable block (ram,0x0a0626) */
/* WARNING: Removing unreachable block (ram,0x0a0506) */
/* WARNING: Removing unreachable block (ram,0x0a0492) */
/* WARNING: Removing unreachable block (ram,0x0a0434) */
/* WARNING: Removing unreachable block (ram,0x0a0616) */
/* WARNING: Removing unreachable block (ram,0x0a0730) */
/* WARNING: Removing unreachable block (ram,0x0a049c) */
/* WARNING: Removing unreachable block (ram,0x0a0742) */
/* WARNING: Removing unreachable block (ram,0x0a0734) */
/* WARNING: Removing unreachable block (ram,0x0a04b6) */

void egs52_update_near_c350_0a0302(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar6 = egs52_get_operating_mask();
  if ((uVar6 & 0x400) == 0) {
    egs52_update_near_c068_093f90();
    Ram00c350 = 0;
    Ram00c352 = 0;
    bVar7 = UNK_00f842;
    uVar11 = (uint)bVar7 * 0x1c + 0x83c7;
    uVar10 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    uVar11 = (uint)*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
    while( true ) {
      bVar7 = UNK_00f842;
      uVar10 = (uint)bVar7 * 0x1c + 0x83c8;
      uVar12 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar12 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      if (*(byte *)((uint3)uVar12 << 0xe | (uint3)(uVar10 & 0x3fff)) < uVar11) break;
      uVar12 = 1;
      uVar10 = 0;
      uVar8 = uVar11;
      while (bVar1 = uVar8 != 0, uVar8 = uVar8 - 1, bVar1) {
        bVar1 = CARRY2(uVar12,uVar12);
        uVar12 = uVar12 * 2;
        uVar10 = uVar10 * 2 + (uint)bVar1;
      }
      uVar8 = Ram00c068;
      uVar2 = Ram00c06a;
      if ((uVar12 & uVar8) == 0 && (uVar10 & uVar2) == 0) {
        uVar12 = ~uVar12;
        uVar10 = ~uVar10;
        uVar8 = Ram00c350;
        Ram00c350 = uVar8 & uVar12;
        uVar8 = Ram00c352;
        Ram00c352 = uVar8 & uVar10;
        uVar8 = Ram00c354;
        Ram00c354 = uVar8 & uVar12;
        uVar8 = Ram00c356;
        Ram00c356 = uVar8 & uVar10;
        uVar8 = Ram00c358;
        Ram00c358 = uVar8 & uVar12;
        uVar12 = Ram00c35a;
        Ram00c35a = uVar12 & uVar10;
      }
      else {
        bVar7 = UNK_00f842;
        uVar2 = (uint)bVar7 * 0x1c + 0x83c2;
        uVar8 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        iVar3 = uVar11 * 4;
        uVar9 = *(int *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar3;
        uVar8 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar8 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        uVar13 = uVar9 + 2;
        uVar9 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar9 & 0x3fff));
        uVar8 = 0x24;
        if ((((uVar13 & 0xc000) != 0) && (uVar8 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        cVar5 = (char)*(undefined2 *)((uint3)uVar8 << 0xe | (uint3)(uVar13 & 0x3fff)) +
                (0xfff1 < uVar9);
        uVar13 = *(int *)CONCAT12(cVar5,uVar2) + iVar3;
        uVar8 = 0x24;
        if ((((uVar13 & 0xc000) != 0) && (uVar8 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        uVar14 = uVar13 + 2;
        uVar13 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar13 & 0x3fff));
        uVar8 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar8 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
        uVar8 = egs52_transform_far_memory_0a612e
                          (uVar11,*(undefined2 *)CONCAT12(cVar5,uVar9 + 0xe),
                           *(undefined1 *)
                            CONCAT12((char)*(undefined2 *)
                                            ((uint3)uVar8 << 0xe | (uint3)(uVar14 & 0x3fff)) +
                                     (0xfff3 < uVar13),uVar13 + 0xc),uVar2);
        if (uVar8 == 0) {
          bVar7 = UNK_00f842;
          uVar8 = (uint)bVar7 * 0x1c + 0x83c2;
          uVar2 = 0x24;
          if ((((uVar8 & 0xc000) != 0) && (uVar2 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar8 & 0x3fff)) + iVar3;
          uVar8 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          uVar9 = uVar2 + 2;
          uVar2 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar8 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar8 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          cVar5 = (char)*(undefined2 *)((uint3)uVar8 << 0xe | (uint3)(uVar9 & 0x3fff)) +
                  (0xffef < uVar2);
          uVar2 = *(uint *)CONCAT12(cVar5,uVar2 + 0x10);
          uVar8 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(byte *)CONCAT12(cVar5,uVar2) & 0xfd;
          uVar8 = Ram00fdf2;
          uVar2 = Ram00fdf4;
          if (uVar2 == uVar8 < 200 && uVar8 == 200 || uVar2 == 0 && uVar8 < 200) {
            bVar7 = UNK_00f842;
            uVar10 = (uint)bVar7 * 0x1c + 0x83c7;
            uVar12 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar12 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            uVar10 = (uVar11 - *(byte *)((uint3)uVar12 << 0xe | (uint3)(uVar10 & 0x3fff))) * 2 +
                     0xc364;
            uVar12 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar12 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar12 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar12 = 3;
            }
            *(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar10 & 0x3fff)) = 0;
          }
          else {
            bVar7 = UNK_00f842;
            uVar8 = (uint)bVar7 * 0x1c + 0x83c2;
            uVar2 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar2 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar8 & 0x3fff)) + iVar3;
            uVar8 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar8 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar8 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar8 = 3;
            }
            uVar9 = uVar2 + 2;
            uVar2 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar2 & 0x3fff));
            uVar8 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar8 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar8 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar8 = 3;
            }
            cVar5 = (char)*(undefined2 *)((uint3)uVar8 << 0xe | (uint3)(uVar9 & 0x3fff)) +
                    (0xfff5 < uVar2);
            uVar9 = (uVar11 - *(byte *)CONCAT12(cVar5,(uint)bVar7 * 0x1c + -0x7c39)) * 2 + 0xc364;
            uVar8 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar8 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar8 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar8 = 3;
            }
            if (*(uint *)CONCAT12(cVar5,uVar2 + 10) <
                *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar9 & 0x3fff))) {
              uVar8 = Ram00c350;
              Ram00c350 = uVar8 | uVar12;
              uVar12 = Ram00c352;
              Ram00c352 = uVar12 | uVar10;
            }
            else {
              uVar10 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar10 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar10 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar10 = 3;
              }
              uVar12 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar12 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar12 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar12 = 3;
              }
              *(int *)((uint3)uVar12 << 0xe | (uint3)(uVar9 & 0x3fff)) =
                   *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar9 & 0x3fff)) + 0x14;
            }
          }
        }
        else {
          bVar7 = UNK_00f842;
          uVar2 = (uint)bVar7 * 0x1c + 0x83c2;
          uVar9 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar9 = 3;
          }
          uVar9 = *(int *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar3;
          uVar2 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar13 = uVar9 + 2;
          uVar9 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
          uVar2 = 0x24;
          if ((((uVar13 & 0xc000) != 0) && (uVar2 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          cVar5 = (char)*(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar13 & 0x3fff)) +
                  (0xffef < uVar9);
          uVar9 = *(uint *)CONCAT12(cVar5,uVar9 + 0x10);
          uVar2 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) =
               *(byte *)CONCAT12(cVar5,uVar9) | 3;
          bVar7 = UNK_00f842;
          uVar2 = (uint)bVar7 * 0x1c + 0x83c7;
          uVar9 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar9 = 3;
          }
          uVar2 = (uVar11 - *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff))) * 2 + 0xc364;
          uVar9 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar9 = 3;
          }
          *(undefined2 *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
          uVar2 = ~uVar12;
          uVar9 = ~uVar10;
          uVar13 = Ram00c350;
          Ram00c350 = uVar13 & uVar2;
          uVar13 = Ram00c352;
          Ram00c352 = uVar13 & uVar9;
          if ((uVar8 & 0x10) == 0) {
            uVar13 = Ram00c354;
            Ram00c354 = uVar13 & uVar2;
            uVar13 = Ram00c356;
            Ram00c356 = uVar13 & uVar9;
          }
          else {
            uVar13 = Ram00c354;
            Ram00c354 = uVar13 | uVar12;
            uVar13 = Ram00c356;
            Ram00c356 = uVar13 | uVar10;
          }
          if ((uVar8 & 0x20) == 0) {
            uVar10 = Ram00c358;
            Ram00c358 = uVar10 & uVar2;
            uVar10 = Ram00c35a;
            Ram00c35a = uVar10 & uVar9;
          }
          else {
            uVar8 = Ram00c358;
            Ram00c358 = uVar8 | uVar12;
            uVar12 = Ram00c35a;
            Ram00c35a = uVar12 | uVar10;
          }
        }
      }
      uVar11 = uVar11 + 1;
    }
    egs52_update_near_c34e_0a0984();
    bVar7 = 0;
    while( true ) {
      bVar4 = UNK_00f842;
      uVar11 = (uint)bVar4 * 0x1c + 0x83c9;
      uVar10 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      if (*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) <= bVar7) break;
      uVar11 = Ram00fdf2;
      uVar10 = Ram00fdf4;
      if (((uVar10 == uVar11 < 200 && uVar11 == 200 || uVar10 == 0 && uVar11 < 200) ||
          (uVar11 = Ram00ef00, (uVar11 & 0x8000) != 0)) ||
         (uVar11 = Ram00c34e, (uVar11 & 0x10) != 0)) {
        bVar4 = UNK_00f842;
        uVar11 = (uint)bVar4 * 0x1c + 0x83ce;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
        uVar11 = (uint)bVar4 * 0x1c + 0x83d0;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        egs52_update_fault_status
                  (*(undefined1 *)
                    CONCAT12((char)*(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff))
                             + CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),0);
        bVar4 = UNK_00f842;
        uVar11 = (uint)bVar4 * 0x1c + 0x83d2;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
        uVar11 = (uint)bVar4 * 0x1c + 0x83d4;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        egs52_update_fault_status
                  (*(undefined1 *)
                    CONCAT12((char)*(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff))
                             + CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),0);
        bVar4 = UNK_00f842;
        uVar11 = (uint)bVar4 * 0x1c + 0x83ca;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
        uVar11 = (uint)bVar4 * 0x1c + 0x83cc;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        egs52_update_fault_status
                  (*(undefined1 *)
                    CONCAT12((char)*(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff))
                             + CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),0);
      }
      else {
        bVar4 = UNK_00f842;
        iVar3 = (uint)bVar4 * 0x1c;
        uVar11 = iVar3 + 0x83d6;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
        uVar11 = iVar3 + 0x83d8;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar2 = (uint)bVar7 * 4;
        uVar8 = uVar12 + uVar2;
        uVar11 = *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                 (uint)CARRY2(uVar12,uVar2);
        uVar10 = Ram00c068;
        uVar12 = Ram00c06a;
        if ((*(uint *)((uint3)uVar11 << 0x10 | (uint3)uVar8) & uVar10) == 0 &&
            (*(uint *)((uint3)(uVar11 + (0xfffd < uVar8)) << 0x10 | (uint3)(uVar8 + 2)) & uVar12) ==
            0) {
          bVar4 = UNK_00f842;
          uVar11 = (uint)bVar4 * 0x1c + 0x83ce;
          uVar10 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
          uVar11 = (uint)bVar4 * 0x1c + 0x83d0;
          uVar10 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          egs52_update_fault_status
                    (*(undefined1 *)
                      CONCAT12((char)*(undefined2 *)
                                      ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                               CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),0x40);
        }
        else {
          uVar10 = Ram00c354;
          uVar12 = Ram00c356;
          if ((*(uint *)((uint3)uVar11 << 0x10 | (uint3)uVar8) & uVar10) == 0 &&
              (*(uint *)((uint3)(uVar11 + (0xfffd < uVar8)) << 0x10 | (uint3)(uVar8 + 2)) & uVar12)
              == 0) {
            bVar4 = UNK_00f842;
            uVar11 = (uint)bVar4 * 0x1c + 0x83ce;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
            uVar11 = (uint)bVar4 * 0x1c + 0x83d0;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            egs52_update_fault_status
                      (*(undefined1 *)
                        CONCAT12((char)*(undefined2 *)
                                        ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                                 CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),2);
          }
          else {
            uVar11 = iVar3 + 0x83ce;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
            uVar11 = iVar3 + 0x83d0;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            egs52_update_fault_status
                      (*(undefined1 *)
                        CONCAT12((char)*(undefined2 *)
                                        ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                                 CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),3);
          }
        }
        bVar4 = UNK_00f842;
        iVar3 = (uint)bVar4 * 0x1c;
        uVar11 = iVar3 + 0x83d6;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
        uVar11 = iVar3 + 0x83d8;
        uVar10 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        uVar8 = uVar12 + uVar2;
        uVar11 = *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                 (uint)CARRY2(uVar12,uVar2);
        uVar10 = Ram00c068;
        uVar12 = Ram00c06a;
        if ((*(uint *)((uint3)uVar11 << 0x10 | (uint3)uVar8) & uVar10) == 0 &&
            (*(uint *)((uint3)(uVar11 + (0xfffd < uVar8)) << 0x10 | (uint3)(uVar8 + 2)) & uVar12) ==
            0) {
          bVar4 = UNK_00f842;
          uVar11 = (uint)bVar4 * 0x1c + 0x83ca;
          uVar10 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
          uVar11 = (uint)bVar4 * 0x1c + 0x83cc;
          uVar10 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          egs52_update_fault_status
                    (*(undefined1 *)
                      CONCAT12((char)*(undefined2 *)
                                      ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                               CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),0x40);
        }
        else {
          uVar10 = Ram00c350;
          uVar12 = Ram00c352;
          if ((*(uint *)((uint3)uVar11 << 0x10 | (uint3)uVar8) & uVar10) == 0 &&
              (*(uint *)((uint3)(uVar11 + (0xfffd < uVar8)) << 0x10 | (uint3)(uVar8 + 2)) & uVar12)
              == 0) {
            bVar4 = UNK_00f842;
            uVar11 = (uint)bVar4 * 0x1c + 0x83ca;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
            uVar11 = (uint)bVar4 * 0x1c + 0x83cc;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            egs52_update_fault_status
                      (*(undefined1 *)
                        CONCAT12((char)*(undefined2 *)
                                        ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                                 CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),2);
          }
          else {
            uVar11 = iVar3 + 0x83ca;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar12 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
            uVar11 = iVar3 + 0x83cc;
            uVar10 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            egs52_update_fault_status
                      (*(undefined1 *)
                        CONCAT12((char)*(undefined2 *)
                                        ((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) +
                                 CARRY2(uVar12,(uint)bVar7),uVar12 + bVar7),3);
          }
        }
      }
      bVar7 = bVar7 + 1;
    }
  }
  return;
}


