/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d4bf8; FLS offset 0x054bf8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4f44) */
/* WARNING: Removing unreachable block (ram,0x0d4f40) */
/* WARNING: Removing unreachable block (ram,0x0d4f3c) */
/* WARNING: Removing unreachable block (ram,0x0d4f32) */
/* WARNING: Removing unreachable block (ram,0x0d4f2c) */
/* WARNING: Removing unreachable block (ram,0x0d4f28) */
/* WARNING: Removing unreachable block (ram,0x0d4f24) */
/* WARNING: Removing unreachable block (ram,0x0d4f1c) */
/* WARNING: Removing unreachable block (ram,0x0d4f12) */
/* WARNING: Removing unreachable block (ram,0x0d4f0e) */
/* WARNING: Removing unreachable block (ram,0x0d4f0a) */
/* WARNING: Removing unreachable block (ram,0x0d4f00) */
/* WARNING: Removing unreachable block (ram,0x0d4efa) */
/* WARNING: Removing unreachable block (ram,0x0d4ee4) */
/* WARNING: Removing unreachable block (ram,0x0d4ede) */
/* WARNING: Removing unreachable block (ram,0x0d4eda) */
/* WARNING: Removing unreachable block (ram,0x0d4ed2) */
/* WARNING: Removing unreachable block (ram,0x0d4ecc) */
/* WARNING: Removing unreachable block (ram,0x0d4ebe) */
/* WARNING: Removing unreachable block (ram,0x0d4eb4) */
/* WARNING: Removing unreachable block (ram,0x0d4eac) */
/* WARNING: Removing unreachable block (ram,0x0d4ea4) */
/* WARNING: Removing unreachable block (ram,0x0d4e9c) */
/* WARNING: Removing unreachable block (ram,0x0d4e8e) */
/* WARNING: Removing unreachable block (ram,0x0d4e8a) */
/* WARNING: Removing unreachable block (ram,0x0d4e86) */
/* WARNING: Removing unreachable block (ram,0x0d4e82) */
/* WARNING: Removing unreachable block (ram,0x0d4e7a) */
/* WARNING: Removing unreachable block (ram,0x0d4e76) */
/* WARNING: Removing unreachable block (ram,0x0d4e6e) */
/* WARNING: Removing unreachable block (ram,0x0d4e68) */
/* WARNING: Removing unreachable block (ram,0x0d4e5a) */
/* WARNING: Removing unreachable block (ram,0x0d4e50) */
/* WARNING: Removing unreachable block (ram,0x0d4e48) */
/* WARNING: Removing unreachable block (ram,0x0d4e40) */
/* WARNING: Removing unreachable block (ram,0x0d4e3c) */
/* WARNING: Removing unreachable block (ram,0x0d4e38) */
/* WARNING: Removing unreachable block (ram,0x0d4e30) */
/* WARNING: Removing unreachable block (ram,0x0d4e18) */
/* WARNING: Removing unreachable block (ram,0x0d4e14) */
/* WARNING: Removing unreachable block (ram,0x0d4e0c) */
/* WARNING: Removing unreachable block (ram,0x0d4dfc) */
/* WARNING: Removing unreachable block (ram,0x0d4dee) */
/* WARNING: Removing unreachable block (ram,0x0d4de6) */
/* WARNING: Removing unreachable block (ram,0x0d4de2) */
/* WARNING: Removing unreachable block (ram,0x0d4dd6) */
/* WARNING: Removing unreachable block (ram,0x0d4dcc) */
/* WARNING: Removing unreachable block (ram,0x0d4dc4) */
/* WARNING: Removing unreachable block (ram,0x0d4db8) */
/* WARNING: Removing unreachable block (ram,0x0d4db4) */
/* WARNING: Removing unreachable block (ram,0x0d4db0) */
/* WARNING: Removing unreachable block (ram,0x0d4dac) */
/* WARNING: Removing unreachable block (ram,0x0d4da0) */
/* WARNING: Removing unreachable block (ram,0x0d4d94) */
/* WARNING: Removing unreachable block (ram,0x0d4d90) */
/* WARNING: Removing unreachable block (ram,0x0d4d8a) */
/* WARNING: Removing unreachable block (ram,0x0d4d86) */
/* WARNING: Removing unreachable block (ram,0x0d4d72) */
/* WARNING: Removing unreachable block (ram,0x0d4d62) */
/* WARNING: Removing unreachable block (ram,0x0d4d5c) */
/* WARNING: Removing unreachable block (ram,0x0d4d52) */
/* WARNING: Removing unreachable block (ram,0x0d4d4e) */
/* WARNING: Removing unreachable block (ram,0x0d4d3a) */
/* WARNING: Removing unreachable block (ram,0x0d4d34) */
/* WARNING: Removing unreachable block (ram,0x0d4d30) */
/* WARNING: Removing unreachable block (ram,0x0d4d2c) */
/* WARNING: Removing unreachable block (ram,0x0d4d28) */
/* WARNING: Removing unreachable block (ram,0x0d4d24) */
/* WARNING: Removing unreachable block (ram,0x0d4d20) */
/* WARNING: Removing unreachable block (ram,0x0d4d1c) */
/* WARNING: Removing unreachable block (ram,0x0d4d18) */
/* WARNING: Removing unreachable block (ram,0x0d4d14) */
/* WARNING: Removing unreachable block (ram,0x0d4d10) */
/* WARNING: Removing unreachable block (ram,0x0d4d0c) */
/* WARNING: Removing unreachable block (ram,0x0d4cfe) */
/* WARNING: Removing unreachable block (ram,0x0d4cee) */
/* WARNING: Removing unreachable block (ram,0x0d4ce2) */
/* WARNING: Removing unreachable block (ram,0x0d4cea) */
/* WARNING: Removing unreachable block (ram,0x0d4cda) */
/* WARNING: Removing unreachable block (ram,0x0d4cd2) */
/* WARNING: Removing unreachable block (ram,0x0d4cce) */
/* WARNING: Removing unreachable block (ram,0x0d4cca) */
/* WARNING: Removing unreachable block (ram,0x0d4cc2) */
/* WARNING: Removing unreachable block (ram,0x0d4cba) */
/* WARNING: Removing unreachable block (ram,0x0d4cb2) */
/* WARNING: Removing unreachable block (ram,0x0d4ca4) */
/* WARNING: Removing unreachable block (ram,0x0d4c9c) */
/* WARNING: Removing unreachable block (ram,0x0d4c96) */
/* WARNING: Removing unreachable block (ram,0x0d4c92) */
/* WARNING: Removing unreachable block (ram,0x0d4c8a) */
/* WARNING: Removing unreachable block (ram,0x0d4c84) */
/* WARNING: Removing unreachable block (ram,0x0d4c76) */
/* WARNING: Removing unreachable block (ram,0x0d4ef6) */
/* WARNING: Removing unreachable block (ram,0x0d4ef2) */
/* WARNING: Removing unreachable block (ram,0x0d4eea) */
/* WARNING: Removing unreachable block (ram,0x0d4c66) */
/* WARNING: Removing unreachable block (ram,0x0d4c62) */
/* WARNING: Removing unreachable block (ram,0x0d4c56) */
/* WARNING: Removing unreachable block (ram,0x0d4c52) */
/* WARNING: Removing unreachable block (ram,0x0d4c4a) */
/* WARNING: Removing unreachable block (ram,0x0d4c44) */
/* WARNING: Removing unreachable block (ram,0x0d4c3c) */
/* WARNING: Removing unreachable block (ram,0x0d4c38) */
/* WARNING: Removing unreachable block (ram,0x0d4c34) */
/* WARNING: Removing unreachable block (ram,0x0d4c30) */
/* WARNING: Removing unreachable block (ram,0x0d4c2c) */
/* WARNING: Removing unreachable block (ram,0x0d4c28) */
/* WARNING: Removing unreachable block (ram,0x0d4c1c) */
/* WARNING: Removing unreachable block (ram,0x0d4c14) */
/* WARNING: Removing unreachable block (ram,0x0d4c10) */
/* WARNING: Removing unreachable block (ram,0x0d4bfe) */
/* WARNING: Removing unreachable block (ram,0x0d4c42) */
/* WARNING: Removing unreachable block (ram,0x0d4c50) */
/* WARNING: Removing unreachable block (ram,0x0d4ca8) */
/* WARNING: Removing unreachable block (ram,0x0d4cbe) */
/* WARNING: Removing unreachable block (ram,0x0d4cf2) */
/* WARNING: Removing unreachable block (ram,0x0d4d02) */
/* WARNING: Removing unreachable block (ram,0x0d4dbc) */
/* WARNING: Removing unreachable block (ram,0x0d4df2) */
/* WARNING: Removing unreachable block (ram,0x0d4e10) */
/* WARNING: Removing unreachable block (ram,0x0d4e2c) */
/* WARNING: Removing unreachable block (ram,0x0d4ea0) */

void egs52_update_near_d5b1_0d4bf8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uchar uVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  int iVar12;
  ushort uVar13;
  ushort uVar14;
  int iVar15;
  
  egs52_update_near_d490_0d7666();
  bVar5 = UNK_00d567;
  if (bVar5 < 7) {
                    /* WARNING: Switch is manually overridden */
    switch((uint3)*(uint *)((uint3)((uint)bVar5 * 2 + 0x16e2) | 0x90000) | 0xd0000) {
    case 0xd4c14:
      uVar9 = UNK_00d579;
      uVar9 = egs52_compute_d42e_byte(uVar9);
      UNK_00d5b1 = uVar9;
      egs52_pid_reset((ushort *)0xd55e);
      Ram00d498 = 0;
      Ram00d49a = 0;
      UNK_00d580 = 0;
      Ram00d57e = 0;
      cVar6 = UNK_00d567;
      UNK_00d567 = cVar6 + '\x01';
    case 0xd4c3c:
      iVar15 = Ram00f636;
      uVar4 = iVar15 + 2;
      uVar2 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar1 = Ram00d4d2;
      if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) < uVar1) {
        uVar11 = Ram00d4d2;
      }
      else {
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar11 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
      }
      Ram00d49c = uVar11;
      cVar6 = UNK_00d579;
      uVar11 = egs52_compute_from_near_d54a_0d7ffa(cVar6 + -1);
      Ram00d56a = uVar11;
      cVar6 = UNK_00d5b1;
      if (cVar6 == '\0') {
        uVar10 = UNK_00d579;
        uVar10 = egs52_compute_from_near_f634_0d73e6(uVar10);
        UNK_00d5b1 = uVar10;
        cVar6 = UNK_00d567;
        UNK_00d567 = cVar6 + '\x01';
      }
      break;
    case 0xd4c72:
      egs52_update_near_d4f6_0d3124();
      cVar6 = UNK_00d579;
      uVar14 = egs52_compute_from_near_d4d2_0d8092(cVar6 + -1);
      uVar13 = Ram00d56a;
      bVar5 = UNK_00d5b1;
      uVar13 = egs52_ramp_u16(uVar13,uVar14,(uint)bVar5);
      Ram00d56a = uVar13;
      cVar6 = UNK_00d5b1;
      if (cVar6 == '\0') {
LAB_0d4cca:
        cVar6 = UNK_00d567;
        UNK_00d567 = cVar6 + '\x01';
        Ram00d4b2 = 0;
        Ram00d4b0 = 0;
      }
      else {
        cVar6 = UNK_00d579;
        iVar15 = Ram00f634;
        uVar2 = iVar15 + 1;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        iVar12 = egs52_update_near_d418_0d6f4e
                           (cVar6 + -1,
                            *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)));
        iVar15 = Ram00d41c;
        if (iVar15 <= iVar12) {
          iVar15 = Ram00f634;
          uVar2 = iVar15 + 0x20;
          uVar4 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          iVar15 = Ram00d414;
          if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar15) goto LAB_0d4cca;
        }
      }
      break;
    case 0xd4cda:
      iVar15 = Ram00d414;
      if (iVar15 < 0) {
        iVar15 = Ram00d414;
        iVar15 = -iVar15;
      }
      else {
        iVar15 = Ram00d414;
      }
      iVar12 = Ram00f634;
      uVar2 = iVar12 + 0x20;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (iVar15 <= *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) {
        iVar12 = egs52_sum_pressure_terms();
        iVar15 = Ram00f636;
        uVar2 = iVar15 + 0x34;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if (-*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar12) {
          egs52_update_near_d4f6_0d3124();
          iVar15 = Ram00f634;
          uVar2 = iVar15 + 6;
          uVar4 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          uVar1 = iVar15 + 0x3b;
          uVar3 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar8 = Ram00d4b0;
          bVar5 = UNK_00d442;
          iVar15 = Ram00d4b0;
          Ram00d4b0 = iVar15 + (int)(((ulong)bVar5 *
                                     (ulong)(uint)(*(int *)((uint3)uVar4 << 0xe |
                                                           (uint3)(uVar2 & 0x3fff)) * 2 +
                                                  (int)(((ulong)*(byte *)((uint3)uVar3 << 0xe |
                                                                         (uint3)(uVar1 & 0x3fff)) *
                                                        (ulong)uVar8) / 100))) / 10);
          uVar2 = Ram00d4b0;
          Ram00d4b2 = uVar2 >> 1;
          cVar6 = UNK_00d579;
          uVar11 = egs52_compute_from_near_d4d2_0d8104(cVar6 + -1);
          Ram00d56a = uVar11;
          break;
        }
      }
      cVar6 = UNK_00d567;
      UNK_00d567 = cVar6 + '\x01';
      uVar11 = Ram00d500;
      Ram00d4f2 = uVar11;
      uVar11 = Ram00d4c2;
      Ram00d4c0 = uVar11;
      iVar15 = Ram00d490;
      iVar12 = Ram00d4ae;
      Ram00d498 = iVar15 + iVar12;
      Ram00d49a = iVar15 + iVar12;
      uVar11 = Ram00d524;
      Ram00d522 = uVar11;
      uVar2 = Ram00fd4c;
      Ram00fd4c = uVar2 & 0xfffb;
      iVar15 = Ram00d4ec;
      if (iVar15 != 0) {
        uVar2 = Ram00fd4c;
        Ram00fd4c = uVar2 | 4;
      }
      break;
    case 0xd4da8:
      egs52_update_near_d4f6_0d3124();
      iVar15 = Ram00d490;
      iVar12 = Ram00d4ae;
      Ram00d498 = iVar15 + iVar12;
      iVar7 = Ram00f63a;
      uVar2 = iVar7 + 0x4f;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar13 = Ram00d49a;
      uVar13 = egs52_blend_percent_u16
                         (*(uchar *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),iVar15 + iVar12,
                          uVar13);
      Ram00d49a = uVar13;
      egs52_update_near_d4ac_0def12(uVar13);
      cVar6 = UNK_00d579;
      uVar11 = egs52_compute_from_near_d4d2_0d817a(cVar6 + -1);
      Ram00d56a = uVar11;
      cVar6 = UNK_00d579;
      iVar15 = Ram00f634;
      uVar2 = iVar15 + 1;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      iVar12 = egs52_update_near_d418_0d6f4e
                         (cVar6 + -1,*(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)))
      ;
      iVar15 = Ram00d41c;
      if ((iVar15 <= iVar12) && (uVar2 = Ram00fd4a, (uVar2 & 2) == 0)) {
        iVar15 = Ram00f634;
        uVar2 = iVar15 + 1;
        uVar4 = 0x24;
        if (((uVar2 & 0xc000) != 0) &&
           ((uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000))
           )) {
          uVar4 = 3;
        }
        UNK_00d5b1 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
        cVar6 = UNK_00d567;
        UNK_00d567 = cVar6 + '\x01';
      }
      break;
    case 0xd4e20:
      uVar2 = Ram00fd48;
      Ram00fd48 = uVar2 | 0x40;
      egs52_update_near_d4f6_0d3124();
      uVar14 = egs52_compute_from_near_d4e1_0d4b5e();
      uVar13 = Ram00d498;
      bVar5 = UNK_00d5b1;
      uVar13 = egs52_ramp_u16(uVar13,uVar14,(uint)bVar5);
      Ram00d498 = uVar13;
      iVar15 = Ram00f63a;
      uVar2 = iVar15 + 0x4f;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar14 = Ram00d49a;
      uVar13 = egs52_blend_percent_u16
                         (*(uchar *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),uVar13,uVar14);
      Ram00d49a = uVar13;
      egs52_update_near_d4ac_0def12(uVar13);
      cVar6 = UNK_00d579;
      uVar14 = egs52_compute_from_near_d4d2_0d81fe(cVar6 + -1);
      uVar13 = Ram00d56a;
      bVar5 = UNK_00d5b1;
      uVar13 = egs52_ramp_u16(uVar13,uVar14,(uint)bVar5);
      Ram00d56a = uVar13;
      cVar6 = UNK_00d5b1;
      if (cVar6 == '\0') {
        iVar15 = Ram00f634;
        uVar2 = iVar15 + 2;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        UNK_00d5b1 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
        cVar6 = UNK_00d567;
        UNK_00d567 = cVar6 + '\x01';
      }
      break;
    case 0xd4e94:
      egs52_update_near_d4f6_0d3124();
      uVar13 = egs52_compute_from_near_d4e1_0d4b5e();
      Ram00d498 = uVar13;
      iVar15 = Ram00f63a;
      uVar2 = iVar15 + 0x4f;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar14 = Ram00d49a;
      uVar13 = egs52_blend_percent_u16
                         (*(uchar *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),uVar13,uVar14);
      Ram00d49a = uVar13;
      egs52_update_near_d4ac_0def12(uVar13);
      cVar6 = UNK_00d579;
      uVar14 = egs52_compute_from_near_d4d2_0d81fe(cVar6 + -1);
      uVar13 = Ram00d56a;
      bVar5 = UNK_00d5b1;
      uVar13 = egs52_ramp_u16(uVar13,uVar14,(uint)bVar5);
      Ram00d56a = uVar13;
      cVar6 = UNK_00d5b1;
      if (cVar6 == '\0') {
        UNK_00d567 = 0;
      }
    }
  }
  iVar15 = Ram00d5a6;
  if ((iVar15 != 0) && (bVar5 = UNK_00d567, bVar5 != 0)) {
    if (1 < bVar5) {
      iVar15 = Ram00f634;
      uVar2 = iVar15 + 0x20;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      iVar15 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
      iVar12 = Ram00d41c;
      iVar7 = Ram00d41c;
      if ((iVar15 != iVar7 && iVar12 <= iVar15) && (uVar2 = Ram00fd4a, (uVar2 & 0x80) == 0))
      goto LAB_0d4f3a;
    }
    bVar5 = UNK_00d567;
    if (bVar5 < 2) {
      return;
    }
    iVar15 = Ram00f634;
    uVar2 = iVar15 + 0x22;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    iVar15 = *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
    iVar12 = Ram00d41c;
    iVar7 = Ram00d41c;
    if (iVar15 == iVar7 || iVar15 < iVar12) {
      return;
    }
    uVar2 = Ram00fd4a;
    if ((uVar2 & 0x80) == 0) {
      return;
    }
  }
LAB_0d4f3a:
  uVar2 = Ram00fd48;
  Ram00fd48 = uVar2 | 0x40;
  UNK_00d566 = 0;
  UNK_00d567 = 0;
  cVar6 = UNK_00d437;
  UNK_00d437 = cVar6 + '\x01';
  return;
}


