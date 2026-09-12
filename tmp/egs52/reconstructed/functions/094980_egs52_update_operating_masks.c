/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094980; FLS offset 0x014980.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094d6e) */
/* WARNING: Removing unreachable block (ram,0x094d60) */
/* WARNING: Removing unreachable block (ram,0x094d4c) */
/* WARNING: Removing unreachable block (ram,0x094d46) */
/* WARNING: Removing unreachable block (ram,0x094d42) */
/* WARNING: Removing unreachable block (ram,0x094d56) */
/* WARNING: Removing unreachable block (ram,0x094d04) */
/* WARNING: Removing unreachable block (ram,0x094cc6) */
/* WARNING: Removing unreachable block (ram,0x094cf0) */
/* WARNING: Removing unreachable block (ram,0x094cea) */
/* WARNING: Removing unreachable block (ram,0x094cfa) */
/* WARNING: Removing unreachable block (ram,0x094cb0) */
/* WARNING: Removing unreachable block (ram,0x094c3e) */
/* WARNING: Removing unreachable block (ram,0x094c88) */
/* WARNING: Removing unreachable block (ram,0x094c82) */
/* WARNING: Removing unreachable block (ram,0x094c9e) */
/* WARNING: Removing unreachable block (ram,0x094c92) */
/* WARNING: Removing unreachable block (ram,0x094c28) */
/* WARNING: Removing unreachable block (ram,0x094c1e) */
/* WARNING: Removing unreachable block (ram,0x094be6) */
/* WARNING: Removing unreachable block (ram,0x094bac) */
/* WARNING: Removing unreachable block (ram,0x094bd2) */
/* WARNING: Removing unreachable block (ram,0x094bcc) */
/* WARNING: Removing unreachable block (ram,0x094bdc) */
/* WARNING: Removing unreachable block (ram,0x094b94) */
/* WARNING: Removing unreachable block (ram,0x094b8a) */
/* WARNING: Removing unreachable block (ram,0x094b56) */
/* WARNING: Removing unreachable block (ram,0x094b18) */
/* WARNING: Removing unreachable block (ram,0x094b42) */
/* WARNING: Removing unreachable block (ram,0x094b3c) */
/* WARNING: Removing unreachable block (ram,0x094b4c) */
/* WARNING: Removing unreachable block (ram,0x094b00) */
/* WARNING: Removing unreachable block (ram,0x094af6) */
/* WARNING: Removing unreachable block (ram,0x094ac6) */
/* WARNING: Removing unreachable block (ram,0x094a80) */
/* WARNING: Removing unreachable block (ram,0x094a7c) */
/* WARNING: Removing unreachable block (ram,0x094ab4) */
/* WARNING: Removing unreachable block (ram,0x094aa8) */
/* WARNING: Removing unreachable block (ram,0x094a52) */
/* WARNING: Removing unreachable block (ram,0x094a24) */
/* WARNING: Removing unreachable block (ram,0x094a14) */
/* WARNING: Removing unreachable block (ram,0x094a0a) */
/* WARNING: Removing unreachable block (ram,0x0949f2) */
/* WARNING: Removing unreachable block (ram,0x0949e0) */
/* WARNING: Removing unreachable block (ram,0x0949b4) */
/* WARNING: Removing unreachable block (ram,0x0949b8) */
/* WARNING: Removing unreachable block (ram,0x0949aa) */
/* WARNING: Removing unreachable block (ram,0x0949a0) */
/* WARNING: Removing unreachable block (ram,0x09499c) */
/* WARNING: Removing unreachable block (ram,0x094998) */
/* WARNING: Removing unreachable block (ram,0x09498a) */
/* WARNING: Removing unreachable block (ram,0x0949dc) */
/* WARNING: Removing unreachable block (ram,0x0949fe) */
/* WARNING: Removing unreachable block (ram,0x094a48) */
/* WARNING: Removing unreachable block (ram,0x094a62) */
/* WARNING: Removing unreachable block (ram,0x094ad6) */
/* WARNING: Removing unreachable block (ram,0x094b38) */
/* WARNING: Removing unreachable block (ram,0x094b66) */
/* WARNING: Removing unreachable block (ram,0x094bc8) */
/* WARNING: Removing unreachable block (ram,0x094bf6) */
/* WARNING: Removing unreachable block (ram,0x094c7e) */
/* WARNING: Removing unreachable block (ram,0x094c58) */
/* WARNING: Removing unreachable block (ram,0x094ce6) */
/* WARNING: Removing unreachable block (ram,0x094d1a) */
/* WARNING: Unknown calling convention */

void egs52_update_operating_masks(ushort mask,ushort client)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  uchar uVar9;
  char cVar10;
  ushort uVar11;
  byte bVar12;
  
  uVar6 = Ram00c06e;
  uVar3 = client * 2 + 0xc072;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(ushort *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = mask;
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 | 1;
  Ram00c084 = 0;
  uVar1 = Ram00c06e;
  if ((uVar1 & 0x60) != 0) {
    Ram00c084 = uVar1 & 0x60;
  }
  bVar12 = 0;
  do {
    uVar1 = (uint)bVar12 * 2 + 0xc072;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = Ram00c084;
    Ram00c084 = uVar7 | *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar12 = bVar12 + 1;
  } while (bVar12 < 8);
  uVar9 = egs52_disable_interrupts_save();
  uVar1 = Ram00fd00;
  if ((uVar1 & 1) == 0) {
    if (uVar9 != '\0') {
      egs52_enable_interrupts();
    }
  }
  else {
    uVar8 = Ram00c084;
    Ram00c06e = uVar8;
    if (uVar9 != '\0') {
      egs52_enable_interrupts();
    }
    uVar1 = Ram00fd00;
    Ram00fd00 = uVar1 & 0xfffe;
    bVar4 = false;
    bVar5 = false;
    uVar1 = Ram00c06e;
    if ((uVar1 & 0x100) == 0) {
      if (((uVar6 & 0x100) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x100) == 0)) {
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x100;
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x400) == 0) || (bVar4)) {
      if (((uVar6 & 0x400) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x400) == 0)) {
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x400;
      if (((uVar6 & 0x400) == 0) || (bVar5)) {
        egs52_update_near_c170_097634(0x100);
        egs52_register_sequence_097676(0x200);
      }
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x200) == 0) || (bVar4)) {
      if (((uVar6 & 0x200) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x200) == 0)) {
        egs52_call_0a00c6_094162();
        uVar9 = UNK_00c082;
        egs52_forward_byte_to_0a08ee(uVar9);
        egs52_call_0a0000_094156();
        egs52_call_0a00aa_09415c();
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x200;
      if (((uVar6 & 0x200) == 0) || (bVar5)) {
        egs52_call_0a00c6_094162();
        uVar11 = egs52_read_c34e_forwarder();
        UNK_00c082 = (byte)(uVar11 >> 0xc);
        uVar9 = UNK_00c104;
        egs52_forward_byte_to_0a08ee(uVar9);
        egs52_call_0a0000_094156();
        egs52_call_0a00aa_09415c();
        egs52_update_near_c170_097634(0x100);
        egs52_register_sequence_097676(0x200);
      }
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x80) == 0) || (bVar4)) {
      if (((uVar6 & 0x80) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x80) == 0)) {
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x80;
      if (((uVar6 & 0x80) == 0) || (bVar5)) {
        egs52_update_near_c170_097634(0);
        egs52_register_sequence_097676(0);
      }
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x40) == 0) || (bVar4)) {
      if (((uVar6 & 0x40) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x40) == 0)) {
        bVar5 = true;
      }
    }
    else if (((uVar1 & 8) == 0) && ((uVar1 & 0x200) == 0)) {
      Ram00c070 = 0x40;
      if (((uVar6 & 0x40) == 0) || (bVar5)) {
        egs52_update_near_c170_097634(0);
        egs52_register_sequence_097676(0);
        egs52_update_near_c1aa_0994ba();
      }
      bVar4 = true;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xffbf;
      uVar1 = Ram00c06e;
      Ram00c06e = uVar1 & 0xffbf;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x20) == 0) || (bVar4)) {
      if (((uVar6 & 0x20) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x20) == 0)) {
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x20;
      if (((uVar6 & 0x20) == 0) || (bVar5)) {
        egs52_update_near_c170_097634(0);
        egs52_register_sequence_097676(0);
        egs52_update_near_c1aa_0994ba();
      }
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x10) == 0) || (bVar4)) {
      if (((uVar6 & 0x10) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x10) == 0)) {
        bVar5 = true;
      }
    }
    else if (((uVar1 & 8) == 0) && ((uVar1 & 0x200) == 0)) {
      Ram00c070 = 0x10;
      if (((uVar6 & 0x10) == 0) || (bVar5)) {
        egs52_update_near_c170_097634(0);
        egs52_register_sequence_097676(0);
      }
      bVar4 = true;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xffef;
      uVar1 = Ram00c06e;
      Ram00c06e = uVar1 & 0xffef;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 0x800) == 0) || (bVar4)) {
      if (((uVar6 & 0x800) != 0) && (uVar1 = Ram00c06e, (uVar1 & 0x800) == 0)) {
        bVar5 = true;
      }
    }
    else {
      Ram00c070 = 0x800;
      if ((((uVar6 & 0x800) == 0) || (bVar5)) &&
         (cVar10 = egs52_compute_from_near_f672_0e352c(), cVar10 == '\0')) {
        egs52_update_near_c170_097634(0);
        egs52_register_sequence_097676(0);
      }
      bVar4 = true;
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 8) == 0) || (bVar4)) {
      if (((uVar6 & 8) != 0) && (uVar1 = Ram00c06e, (uVar1 & 8) == 0)) {
        egs52_call_0a00c6_094162();
        uVar9 = UNK_00c082;
        egs52_forward_byte_to_0a08ee(uVar9);
        egs52_call_0a0000_094156();
        egs52_call_0a00aa_09415c();
        bVar5 = true;
      }
    }
    else {
      uVar9 = egs52_return_true_0e347a();
      if (uVar9 == '\0') {
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
             *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xfff7;
        uVar1 = Ram00c06e;
        Ram00c06e = uVar1 & 0xfff7;
      }
      else {
        Ram00c070 = 8;
        if (((uVar6 & 8) == 0) || (bVar5)) {
          egs52_call_0a00c6_094162();
          uVar11 = egs52_read_c34e_forwarder();
          UNK_00c082 = (byte)(uVar11 >> 0xc);
          egs52_forward_byte_to_0a08ee('\x02');
          egs52_call_0a0000_094156();
          egs52_call_0a00aa_09415c();
          egs52_update_near_c170_097634(0x100);
          egs52_register_sequence_097676(0x200);
        }
        bVar4 = true;
      }
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 4) == 0) || (bVar4)) {
      if (((uVar6 & 4) != 0) && (uVar1 = Ram00c06e, (uVar1 & 4) == 0)) {
        bVar5 = true;
      }
    }
    else {
      uVar9 = egs52_return_true_0e3476();
      if (uVar9 == '\0') {
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
             *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xfffb;
        uVar1 = Ram00c06e;
        Ram00c06e = uVar1 & 0xfffb;
      }
      else {
        Ram00c070 = 4;
        if (((uVar6 & 4) == 0) || (bVar5)) {
          egs52_update_near_c170_097634(0x100);
          egs52_register_sequence_097676(0x200);
        }
        bVar4 = true;
      }
    }
    uVar1 = Ram00c06e;
    if (((uVar1 & 2) == 0) || (bVar4)) {
      if (((uVar6 & 2) != 0) && (uVar1 = Ram00c06e, (uVar1 & 2) == 0)) {
        bVar5 = true;
      }
    }
    else {
      cVar10 = egs52_compute_from_near_d508_0e3436();
      if (cVar10 == '\0') {
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
             *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xfffd;
        uVar1 = Ram00c06e;
        Ram00c06e = uVar1 & 0xfffd;
      }
      else {
        Ram00c070 = 2;
        if (((uVar6 & 2) == 0) || (bVar5)) {
          egs52_update_near_c170_097634(0x100);
          egs52_register_sequence_097676(0x200);
          egs52_latch_request_mask(0x800);
        }
        bVar4 = true;
      }
    }
    uVar1 = Ram00c06e;
    if ((((uVar1 & 1) != 0) && (!bVar4)) && ((Ram00c070 = 1, (uVar6 & 1) == 0 || (bVar5)))) {
      egs52_update_near_c170_097634(0x100);
      egs52_register_sequence_097676(0x200);
      egs52_clear_status_c118();
    }
  }
  return;
}


