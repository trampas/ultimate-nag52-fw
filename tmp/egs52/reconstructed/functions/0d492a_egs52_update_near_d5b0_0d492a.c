/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d492a; FLS offset 0x05492a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4b54) */
/* WARNING: Removing unreachable block (ram,0x0d4b4c) */
/* WARNING: Removing unreachable block (ram,0x0d4b44) */
/* WARNING: Removing unreachable block (ram,0x0d4b2e) */
/* WARNING: Removing unreachable block (ram,0x0d4b2a) */
/* WARNING: Removing unreachable block (ram,0x0d4b24) */
/* WARNING: Removing unreachable block (ram,0x0d4b20) */
/* WARNING: Removing unreachable block (ram,0x0d4b1c) */
/* WARNING: Removing unreachable block (ram,0x0d4b18) */
/* WARNING: Removing unreachable block (ram,0x0d4b14) */
/* WARNING: Removing unreachable block (ram,0x0d4b10) */
/* WARNING: Removing unreachable block (ram,0x0d4b0a) */
/* WARNING: Removing unreachable block (ram,0x0d4b04) */
/* WARNING: Removing unreachable block (ram,0x0d4afa) */
/* WARNING: Removing unreachable block (ram,0x0d4af6) */
/* WARNING: Removing unreachable block (ram,0x0d4aea) */
/* WARNING: Removing unreachable block (ram,0x0d4ae0) */
/* WARNING: Removing unreachable block (ram,0x0d4ad4) */
/* WARNING: Removing unreachable block (ram,0x0d4ace) */
/* WARNING: Removing unreachable block (ram,0x0d4ac4) */
/* WARNING: Removing unreachable block (ram,0x0d4ac0) */
/* WARNING: Removing unreachable block (ram,0x0d4ab8) */
/* WARNING: Removing unreachable block (ram,0x0d4aac) */
/* WARNING: Removing unreachable block (ram,0x0d4aa8) */
/* WARNING: Removing unreachable block (ram,0x0d4a9c) */
/* WARNING: Removing unreachable block (ram,0x0d4aa4) */
/* WARNING: Removing unreachable block (ram,0x0d4a94) */
/* WARNING: Removing unreachable block (ram,0x0d4a8c) */
/* WARNING: Removing unreachable block (ram,0x0d4a88) */
/* WARNING: Removing unreachable block (ram,0x0d4a84) */
/* WARNING: Removing unreachable block (ram,0x0d4a80) */
/* WARNING: Removing unreachable block (ram,0x0d4a7a) */
/* WARNING: Removing unreachable block (ram,0x0d4a76) */
/* WARNING: Removing unreachable block (ram,0x0d4a72) */
/* WARNING: Removing unreachable block (ram,0x0d4a68) */
/* WARNING: Removing unreachable block (ram,0x0d4a64) */
/* WARNING: Removing unreachable block (ram,0x0d4a5e) */
/* WARNING: Removing unreachable block (ram,0x0d4a5a) */
/* WARNING: Removing unreachable block (ram,0x0d4a56) */
/* WARNING: Removing unreachable block (ram,0x0d4a52) */
/* WARNING: Removing unreachable block (ram,0x0d4a46) */
/* WARNING: Removing unreachable block (ram,0x0d4a42) */
/* WARNING: Removing unreachable block (ram,0x0d4a36) */
/* WARNING: Removing unreachable block (ram,0x0d4a32) */
/* WARNING: Removing unreachable block (ram,0x0d4a24) */
/* WARNING: Removing unreachable block (ram,0x0d4a2c) */
/* WARNING: Removing unreachable block (ram,0x0d4a1c) */
/* WARNING: Removing unreachable block (ram,0x0d4a16) */
/* WARNING: Removing unreachable block (ram,0x0d4a0c) */
/* WARNING: Removing unreachable block (ram,0x0d4a04) */
/* WARNING: Removing unreachable block (ram,0x0d49fe) */
/* WARNING: Removing unreachable block (ram,0x0d49f0) */
/* WARNING: Removing unreachable block (ram,0x0d49e8) */
/* WARNING: Removing unreachable block (ram,0x0d49e4) */
/* WARNING: Removing unreachable block (ram,0x0d49da) */
/* WARNING: Removing unreachable block (ram,0x0d49d2) */
/* WARNING: Removing unreachable block (ram,0x0d49ce) */
/* WARNING: Removing unreachable block (ram,0x0d49c8) */
/* WARNING: Removing unreachable block (ram,0x0d49c0) */
/* WARNING: Removing unreachable block (ram,0x0d49b8) */
/* WARNING: Removing unreachable block (ram,0x0d49b4) */
/* WARNING: Removing unreachable block (ram,0x0d49ac) */
/* WARNING: Removing unreachable block (ram,0x0d49a6) */
/* WARNING: Removing unreachable block (ram,0x0d499a) */
/* WARNING: Removing unreachable block (ram,0x0d4b40) */
/* WARNING: Removing unreachable block (ram,0x0d4b3c) */
/* WARNING: Removing unreachable block (ram,0x0d4b34) */
/* WARNING: Removing unreachable block (ram,0x0d498e) */
/* WARNING: Removing unreachable block (ram,0x0d498a) */
/* WARNING: Removing unreachable block (ram,0x0d4980) */
/* WARNING: Removing unreachable block (ram,0x0d497c) */
/* WARNING: Removing unreachable block (ram,0x0d4978) */
/* WARNING: Removing unreachable block (ram,0x0d4974) */
/* WARNING: Removing unreachable block (ram,0x0d496a) */
/* WARNING: Removing unreachable block (ram,0x0d4966) */
/* WARNING: Removing unreachable block (ram,0x0d4970) */
/* WARNING: Removing unreachable block (ram,0x0d4960) */
/* WARNING: Removing unreachable block (ram,0x0d495c) */
/* WARNING: Removing unreachable block (ram,0x0d4954) */
/* WARNING: Removing unreachable block (ram,0x0d4942) */
/* WARNING: Removing unreachable block (ram,0x0d4938) */
/* WARNING: Removing unreachable block (ram,0x0d492e) */
/* WARNING: Removing unreachable block (ram,0x0d4b38) */
/* WARNING: Removing unreachable block (ram,0x0d4a14) */
/* WARNING: Removing unreachable block (ram,0x0d4a4e) */
/* WARNING: Removing unreachable block (ram,0x0d4ae4) */

void egs52_update_near_d5b0_0d492a(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort target;
  ushort uVar11;
  int iVar12;
  int iVar13;
  
  uVar4 = UNK_00d577;
  uVar9 = egs52_update_near_d426_0d4338(uVar4);
  uVar4 = UNK_00d577;
  uVar10 = egs52_compute_from_near_d579_0d42a6(uVar4);
  bVar5 = UNK_00d566;
  if (bVar5 < 7) {
                    /* WARNING: Switch is manually overridden */
    switch((uint3)*(uint *)((uint3)((uint)bVar5 * 2 + 0x16d4) | 0x90000) | 0xd0000) {
    case 0xd4958:
      bVar8 = egs52_update_near_d430_0d718c();
      UNK_00d5b0 = bVar8;
      bVar5 = UNK_00d590;
      if (bVar8 < bVar5) {
        UNK_00d5b0 = 0;
      }
      else {
        cVar3 = UNK_00d590;
        cVar7 = UNK_00d5b0;
        UNK_00d5b0 = cVar7 - cVar3;
      }
      UNK_00d590 = 0;
      Ram00d542 = 0;
      cVar3 = UNK_00d566;
      UNK_00d566 = cVar3 + '\x01';
    case 0xd4980:
      Ram00d4ae = 0;
      uVar9 = egs52_compute_from_near_d54a_0d7e30(uVar10);
      Ram00d556 = uVar9;
      cVar3 = UNK_00d5b0;
      if (cVar3 == '\0') {
        iVar13 = Ram00f636;
        uVar1 = iVar13 + 0x22;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        cVar3 = UNK_00d566;
        UNK_00d566 = cVar3 + '\x01';
      }
      break;
    case 0xd499a:
      Ram00d4ae = 0;
      target = egs52_compute_from_near_d54a_0d7e30(uVar9);
      uVar11 = Ram00d556;
      bVar5 = UNK_00d5b0;
      uVar11 = egs52_ramp_u16(uVar11,target,(uint)bVar5);
      Ram00d556 = uVar11;
      cVar3 = UNK_00d5b0;
      if (cVar3 == '\0') {
        iVar13 = Ram00f636;
        bVar5 = UNK_00d477;
        uVar2 = iVar13 + 0x23 + (uint)bVar5;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        UNK_00d5b0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
        cVar3 = UNK_00d566;
        UNK_00d566 = cVar3 + '\x01';
      }
      break;
    case 0xd49da:
      Ram00d4ae = 0;
      uVar9 = egs52_compute_from_near_d54a_0d7e30(uVar9);
      Ram00d556 = uVar9;
      cVar3 = UNK_00d5b0;
      if (cVar3 == '\0') {
        cVar3 = UNK_00d566;
        UNK_00d566 = cVar3 + '\x01';
      }
      break;
    case 0xd49f8:
      uVar9 = egs52_compute_from_near_d54a_0d7e30(uVar9);
      Ram00d556 = uVar9;
      uVar4 = UNK_00d4e1;
      egs52_update_near_d4ae_0d7b3e(uVar9,uVar4);
      iVar13 = Ram00f634;
      uVar2 = iVar13 + 0x20;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      iVar12 = Ram00d41c;
      iVar6 = Ram00d41c;
      if (iVar13 == iVar6 || iVar13 < iVar12) {
        iVar13 = Ram00d414;
        if (iVar13 < 0) {
          iVar13 = Ram00d414;
          iVar13 = -iVar13;
        }
        else {
          iVar13 = Ram00d414;
        }
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if ((*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) <= iVar13) &&
           (uVar1 = Ram00fd4a, (uVar1 & 0x80) == 0)) break;
      }
      Ram00d53c = 0;
      cVar3 = UNK_00d566;
      UNK_00d566 = cVar3 + '\x01';
      break;
    case 0xd4a4e:
      iVar13 = Ram00f634;
      uVar1 = iVar13 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar13 = Ram00d53c;
      Ram00d53c = iVar13 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = Ram00d53c;
      uVar2 = Ram00d552;
      if (uVar2 <= uVar1) {
        uVar10 = Ram00d552;
        Ram00d53c = uVar10;
      }
      iVar12 = egs52_compute_from_near_d54a_0d7e30(uVar9);
      iVar13 = Ram00d53c;
      Ram00d556 = iVar12 + iVar13;
      uVar1 = Ram00d552;
      if (uVar1 <= (uint)(iVar12 + iVar13)) {
        uVar9 = Ram00d552;
        Ram00d556 = uVar9;
      }
      uVar9 = Ram00d556;
      uVar4 = UNK_00d4e1;
      egs52_update_near_d4ae_0d7b3e(uVar9,uVar4);
      iVar13 = Ram00d414;
      if (iVar13 < 0) {
        iVar13 = Ram00d414;
        iVar13 = -iVar13;
      }
      else {
        iVar13 = Ram00d414;
      }
      iVar12 = Ram00f634;
      uVar1 = iVar12 + 0x20;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((iVar13 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) ||
         (uVar1 = Ram00fd4a, (uVar1 & 0x80) != 0)) {
        cVar3 = UNK_00d579;
        iVar13 = Ram00f634;
        uVar1 = iVar13 + 1;
        uVar2 = 0x24;
        if (((uVar1 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))
           )) {
          uVar2 = 3;
        }
        iVar12 = egs52_update_near_d418_0d6f4e
                           (cVar3 + -1,
                            *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
        iVar13 = Ram00d41c;
        if (iVar12 < iVar13) break;
      }
      cVar3 = UNK_00d566;
      UNK_00d566 = cVar3 + '\x01';
      break;
    case 0xd4ada:
      iVar12 = egs52_compute_from_near_d54a_0d7e30(uVar9);
      iVar13 = Ram00d53c;
      Ram00d556 = iVar12 + iVar13;
      uVar4 = UNK_00d4e1;
      egs52_update_near_d4ae_0d7b3e(iVar12 + iVar13,uVar4);
      iVar12 = egs52_sum_pressure_terms();
      iVar13 = Ram00f636;
      uVar1 = iVar13 + 0x34;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (iVar12 <= -*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        bVar5 = UNK_00d477;
        iVar13 = Ram00f634;
        uVar1 = iVar13 + (uint)bVar5 * 2 + 0x4e;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar13 = Ram00d542;
        Ram00d542 = iVar13 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
      iVar13 = Ram00d542;
      iVar12 = Ram00d556;
      Ram00d556 = iVar12 + iVar13;
      uVar2 = Ram00d556;
      uVar1 = Ram00d552;
      if (uVar1 <= uVar2) {
        uVar9 = Ram00d552;
        Ram00d556 = uVar9;
      }
    }
  }
  cVar3 = UNK_00d579;
  uVar9 = Ram00d556;
  uVar9 = egs52_update_near_d600_0d7cb8(cVar3 + -1,uVar9);
  Ram00d56c = uVar9;
  return;
}


