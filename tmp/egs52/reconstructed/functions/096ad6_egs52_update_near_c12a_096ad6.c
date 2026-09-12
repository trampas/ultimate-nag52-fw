/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096ad6; FLS offset 0x016ad6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096d52) */
/* WARNING: Removing unreachable block (ram,0x096d4c) */
/* WARNING: Removing unreachable block (ram,0x096d48) */
/* WARNING: Removing unreachable block (ram,0x096d34) */
/* WARNING: Removing unreachable block (ram,0x096d30) */
/* WARNING: Removing unreachable block (ram,0x096cfc) */
/* WARNING: Removing unreachable block (ram,0x096cec) */
/* WARNING: Removing unreachable block (ram,0x096ce4) */
/* WARNING: Removing unreachable block (ram,0x096c9c) */
/* WARNING: Removing unreachable block (ram,0x096c98) */
/* WARNING: Removing unreachable block (ram,0x096c5a) */
/* WARNING: Removing unreachable block (ram,0x096c56) */
/* WARNING: Removing unreachable block (ram,0x096c4c) */
/* WARNING: Removing unreachable block (ram,0x096c48) */
/* WARNING: Removing unreachable block (ram,0x096c44) */
/* WARNING: Removing unreachable block (ram,0x096c36) */
/* WARNING: Removing unreachable block (ram,0x096c06) */
/* WARNING: Removing unreachable block (ram,0x096c02) */
/* WARNING: Removing unreachable block (ram,0x096b68) */
/* WARNING: Removing unreachable block (ram,0x096b64) */
/* WARNING: Removing unreachable block (ram,0x096b60) */
/* WARNING: Removing unreachable block (ram,0x096b5c) */
/* WARNING: Removing unreachable block (ram,0x096bfa) */
/* WARNING: Removing unreachable block (ram,0x096bee) */
/* WARNING: Removing unreachable block (ram,0x096bea) */
/* WARNING: Removing unreachable block (ram,0x096bde) */
/* WARNING: Removing unreachable block (ram,0x096bda) */
/* WARNING: Removing unreachable block (ram,0x096bd0) */
/* WARNING: Removing unreachable block (ram,0x096bcc) */
/* WARNING: Removing unreachable block (ram,0x096bc2) */
/* WARNING: Removing unreachable block (ram,0x096bbe) */
/* WARNING: Removing unreachable block (ram,0x096bb2) */
/* WARNING: Removing unreachable block (ram,0x096baa) */
/* WARNING: Removing unreachable block (ram,0x096bae) */
/* WARNING: Removing unreachable block (ram,0x096ba2) */
/* WARNING: Removing unreachable block (ram,0x096b9e) */
/* WARNING: Removing unreachable block (ram,0x096b92) */
/* WARNING: Removing unreachable block (ram,0x096b8e) */
/* WARNING: Removing unreachable block (ram,0x096b82) */
/* WARNING: Removing unreachable block (ram,0x096b7e) */
/* WARNING: Removing unreachable block (ram,0x096b70) */
/* WARNING: Removing unreachable block (ram,0x096b36) */
/* WARNING: Removing unreachable block (ram,0x096b32) */
/* WARNING: Removing unreachable block (ram,0x096b28) */
/* WARNING: Removing unreachable block (ram,0x096b1c) */
/* WARNING: Removing unreachable block (ram,0x096b10) */
/* WARNING: Removing unreachable block (ram,0x096b04) */
/* WARNING: Removing unreachable block (ram,0x096af4) */
/* WARNING: Removing unreachable block (ram,0x096af0) */
/* WARNING: Removing unreachable block (ram,0x096d5c) */
/* WARNING: Removing unreachable block (ram,0x096b16) */

void egs52_update_near_c12a_096ad6(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  
  uVar8 = Ram00fd00;
  if ((uVar8 & 0x400) != 0) {
    uVar8 = Ram00fdf0;
    Ram00fdf0 = uVar8 | 0x1000;
    goto LAB_096d60;
  }
  uVar8 = Ram00fd00;
  Ram00fd00 = uVar8 | 0x400;
  uVar8 = Ram00fd00;
  if ((uVar8 & 0x40) == 0) {
    uVar8 = Ram00fdf0;
    Ram00fdf0 = uVar8 | 0x4000;
  }
  else {
    uVar8 = Ram00fd00;
    Ram00fd00 = uVar8 & 0xffbf;
  }
  bVar2 = UNK_00c12a;
  if ((((bVar2 < 8) || (0xc < bVar2)) || (bVar2 = UNK_00c12b, bVar2 < 4)) ||
     (((7 < bVar2 || (bVar2 = UNK_00c12c, 5 < bVar2)) ||
      ((bVar2 = UNK_00c12d, bVar2 == 0 || ((3 < bVar2 || (uVar8 = Ram00feae, uVar8 < 0xf001))))))))
  {
    uVar8 = Ram00fdf2;
    iVar9 = Ram00fdf4;
    if (((iVar9 == 0 && uVar8 < 100) &&
        (uVar8 = egs52_compute_from_near_c06e_094d98(), (uVar8 & 0x100) != 0)) ||
       (uVar8 = egs52_compute_from_near_c06e_094d98(), (uVar8 & 0x60) != 0)) goto LAB_096b54;
    uVar8 = Ram00feae;
    if (uVar8 < 0xf001) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 0x8000;
    }
    cVar4 = UNK_00c12d;
    if (cVar4 == '\0') {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 0x40;
    }
    bVar2 = UNK_00c12d;
    if (3 < bVar2) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 0x80;
    }
    bVar2 = UNK_00c12c;
    if (5 < bVar2) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 0x20;
    }
    bVar2 = UNK_00c12b;
    if (bVar2 < 4) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 4;
    }
    bVar2 = UNK_00c12b;
    if (7 < bVar2) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 8;
    }
    bVar2 = UNK_00c12a;
    if (bVar2 < 8) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 1;
    }
    bVar2 = UNK_00c12a;
    if (0xc < bVar2) {
      uVar8 = Ram00fdf0;
      Ram00fdf0 = uVar8 | 2;
    }
    __software_reset();
  }
  else {
LAB_096b54:
    egs52_service_watchdog(0xe801);
    UNK_00c12a = 0;
    UNK_00c12b = 0;
    UNK_00c12c = 0;
    UNK_00c12d = 0;
  }
  uVar5 = Ram00fdf2;
  egs52_update_near_cd64_0a556c(0);
  egs52_call_0a0302_094178();
  egs52_transform_memory_0a51f2();
  egs52_update_near_c388_09f118();
  egs52_update_near_d2ae_09613e();
  egs52_update_near_fd26_094f42();
  egs52_call_0964d2_094e52();
  egs52_update_near_d588_0d01aa();
  egs52_transform_memory_09600a();
  bVar2 = UNK_00c13f;
  if (bVar2 < 2) {
    cVar4 = UNK_00c13f;
    UNK_00c13f = cVar4 + '\x01';
  }
  else {
    egs52_call_0a01a8_094172();
  }
  uVar8 = uRam0904e2 + 4;
  uVar1 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  egs52_call_09f47c_0a47f0(*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)),0);
  uVar8 = 0x24;
  if ((((uRam0904e2 & 0xc000) != 0) && (uVar8 = 0x21, (uRam0904e2 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uRam0904e2 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  egs52_call_09f47c_0a47f0(*(undefined2 *)((uint3)uVar8 << 0xe | (uint3)(uRam0904e2 & 0x3fff)),1);
  egs52_call_097e9e_09652c();
  egs52_update_near_d3e8_096794();
  egs52_call_0a00d4_094168();
  egs52_update_near_c18b_098170();
  egs52_call_097904_098bca();
  egs52_compute_from_near_c0eb_098002();
  egs52_update_near_c172_097678();
  egs52_call_0964d2_094eda();
  egs52_call_0964d2_094e18();
  iVar9 = egs52_compute_from_near_f7be_095b96();
  if (iVar9 == 3) {
    uVar8 = Ram00fd00;
    if ((uVar8 & 0x200) == 0) {
      uVar8 = Ram00fdf2;
      iVar6 = Ram00fdf4;
      iVar9 = iVar6 - (uint)(uVar8 < 100);
      if ((iVar9 != 0 || uVar8 != 100) && (iVar6 != 0 || uVar8 >= 100)) {
        uVar8 = Ram00fd00;
        Ram00fd00 = uVar8 | 0x200;
        egs52_update_near_c1aa_09950e(iVar9);
        egs52_call_0a13da_0a2504();
        egs52_update_near_c086_0950e0();
        egs52_compute_from_near_f3e4_0a58e2();
        egs52_call_09fbc0_095fa8();
        uVar8 = egs52_compute_from_near_c06e_094d98();
        if ((uVar8 & 0x60) == 0) {
          egs52_update_near_c170_0977f4();
          uVar8 = egs52_compute_from_near_c06e_094d98();
          if ((uVar8 & 0x60) == 0) {
            egs52_update_near_c1aa_0994aa();
            egs52_update_near_c1aa_0994da();
            iVar9 = Ram00fe42;
            uVar8 = Ram00fe40;
            uVar8 = (iVar9 + 600U) % uVar8;
            do {
              uVar1 = Ram00fe42;
            } while (uVar8 != uVar1 && -1 < (int)(uVar8 - uVar1));
          }
        }
        egs52_update_near_f808_097b1a();
        egs52_compute_from_near_cace_0a47d4();
        egs52_update_near_c2b8_09b222();
        egs52_compute_from_near_c100_094db4();
        egs52_update_operating_masks(1,7);
        goto LAB_096d28;
      }
    }
    uVar8 = Ram00fd00;
    if ((uVar8 & 0x200) != 0) {
      egs52_update_near_c0c6_095bbc();
    }
  }
LAB_096d28:
  egs52_update_near_d3da_09629a();
  egs52_update_near_c2c6_09bbce();
  uVar7 = Ram00fdf2;
  bVar10 = (char)uVar7 - (char)uVar5;
  UNK_00c132 = bVar10;
  bVar2 = UNK_00c133;
  bVar3 = UNK_00c133;
  if (bVar10 != bVar3 && bVar2 <= bVar10) {
    UNK_00c133 = bVar10;
  }
LAB_096d60:
  uVar8 = Ram00fd00;
  Ram00fd00 = uVar8 & 0xfbff;
  return;
}


