#include "egs52_hw.h"
#include "egs52_math.h"
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


/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093f04; FLS offset 0x013f04.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093f7c) */
/* WARNING: Removing unreachable block (ram,0x093f76) */
/* WARNING: Removing unreachable block (ram,0x093f6a) */
/* WARNING: Removing unreachable block (ram,0x093f64) */
/* WARNING: Removing unreachable block (ram,0x093f60) */
/* WARNING: Removing unreachable block (ram,0x093f56) */
/* WARNING: Removing unreachable block (ram,0x093f50) */
/* WARNING: Removing unreachable block (ram,0x093f3e) */
/* WARNING: Removing unreachable block (ram,0x093f30) */
/* WARNING: Removing unreachable block (ram,0x093f4c) */
/* WARNING: Removing unreachable block (ram,0x093f44) */
/* WARNING: Removing unreachable block (ram,0x093f10) */
/* WARNING: Removing unreachable block (ram,0x093f2a) */
/* WARNING: Unknown calling convention */

uchar egs52_read_indexed_word_c044(uchar *destination)

{
  uint uVar1;
  uchar *puVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  
  bVar7 = egs52_get_status_c32a();
  if ((bVar7 & 4) != 0) {
    return 'x';
  }
  bVar7 = UNK_00c043;
  if (bVar7 < 8) {
    bVar7 = UNK_00c043;
    bVar5 = UNK_00c040;
    UNK_00c040 = bVar5 | (byte)(1 << (bVar7 & 0xf));
  }
  else if (bVar7 < 0x10) {
    cVar6 = UNK_00c043;
    bVar7 = UNK_00c041;
    UNK_00c041 = bVar7 | (byte)(1 << ((byte)(cVar6 - 8) & 0xf));
  }
  else {
    bVar5 = UNK_00c042;
    UNK_00c042 = bVar5 | (byte)(1 << ((byte)(bVar7 - 0x10) & 0xf));
  }
  bVar7 = UNK_00c043;
  uVar1 = (uint)bVar7 * 2 + 0xc044;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  puVar2 = destination + 1;
  uVar4 = 0x24;
  if (((((uint)puVar2 & 0xc000) != 0) && (uVar4 = 0x21, ((uint)puVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, ((uint)puVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  *(char *)((uint3)uVar4 << 0xe | (uint3)((uint)puVar2 & 0x3fff)) =
       (char)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar7 = UNK_00c043;
  uVar1 = (uint)bVar7 * 2 + 0xc044;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar4 = 0x24;
  if (((((uint)destination & 0xc000) != 0) && (uVar4 = 0x21, ((uint)destination & 0xc000) != 0x4000)
      ) && (uVar4 = 0x2c, ((uint)destination & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  *(char *)((uint3)uVar4 << 0xe | (uint3)((uint)destination & 0x3fff)) =
       (char)((uint)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) >> 8);
  bVar7 = UNK_00c064;
  UNK_00c064 = bVar7 & 0xfb;
  return '\0';
}


/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d5b66; FLS offset 0x055b66.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d63a0) */
/* WARNING: Removing unreachable block (ram,0x0d6398) */
/* WARNING: Removing unreachable block (ram,0x0d6390) */
/* WARNING: Removing unreachable block (ram,0x0d637a) */
/* WARNING: Removing unreachable block (ram,0x0d6376) */
/* WARNING: Removing unreachable block (ram,0x0d636e) */
/* WARNING: Removing unreachable block (ram,0x0d636a) */
/* WARNING: Removing unreachable block (ram,0x0d6368) */
/* WARNING: Removing unreachable block (ram,0x0d635c) */
/* WARNING: Removing unreachable block (ram,0x0d6352) */
/* WARNING: Removing unreachable block (ram,0x0d634e) */
/* WARNING: Removing unreachable block (ram,0x0d634c) */
/* WARNING: Removing unreachable block (ram,0x0d6348) */
/* WARNING: Removing unreachable block (ram,0x0d633c) */
/* WARNING: Removing unreachable block (ram,0x0d6338) */
/* WARNING: Removing unreachable block (ram,0x0d6334) */
/* WARNING: Removing unreachable block (ram,0x0d6328) */
/* WARNING: Removing unreachable block (ram,0x0d631e) */
/* WARNING: Removing unreachable block (ram,0x0d631a) */
/* WARNING: Removing unreachable block (ram,0x0d6312) */
/* WARNING: Removing unreachable block (ram,0x0d630c) */
/* WARNING: Removing unreachable block (ram,0x0d6308) */
/* WARNING: Removing unreachable block (ram,0x0d62fa) */
/* WARNING: Removing unreachable block (ram,0x0d62f6) */
/* WARNING: Removing unreachable block (ram,0x0d62f2) */
/* WARNING: Removing unreachable block (ram,0x0d62e6) */
/* WARNING: Removing unreachable block (ram,0x0d62da) */
/* WARNING: Removing unreachable block (ram,0x0d62d6) */
/* WARNING: Removing unreachable block (ram,0x0d62ce) */
/* WARNING: Removing unreachable block (ram,0x0d62ca) */
/* WARNING: Removing unreachable block (ram,0x0d638e) */
/* WARNING: Removing unreachable block (ram,0x0d637e) */
/* WARNING: Removing unreachable block (ram,0x0d62b8) */
/* WARNING: Removing unreachable block (ram,0x0d62ae) */
/* WARNING: Removing unreachable block (ram,0x0d62a2) */
/* WARNING: Removing unreachable block (ram,0x0d629a) */
/* WARNING: Removing unreachable block (ram,0x0d6284) */
/* WARNING: Removing unreachable block (ram,0x0d6276) */
/* WARNING: Removing unreachable block (ram,0x0d626e) */
/* WARNING: Removing unreachable block (ram,0x0d6268) */
/* WARNING: Removing unreachable block (ram,0x0d625c) */
/* WARNING: Removing unreachable block (ram,0x0d6258) */
/* WARNING: Removing unreachable block (ram,0x0d6254) */
/* WARNING: Removing unreachable block (ram,0x0d6244) */
/* WARNING: Removing unreachable block (ram,0x0d6236) */
/* WARNING: Removing unreachable block (ram,0x0d622e) */
/* WARNING: Removing unreachable block (ram,0x0d6226) */
/* WARNING: Removing unreachable block (ram,0x0d6220) */
/* WARNING: Removing unreachable block (ram,0x0d6212) */
/* WARNING: Removing unreachable block (ram,0x0d620a) */
/* WARNING: Removing unreachable block (ram,0x0d6204) */
/* WARNING: Removing unreachable block (ram,0x0d6200) */
/* WARNING: Removing unreachable block (ram,0x0d61fc) */
/* WARNING: Removing unreachable block (ram,0x0d61f8) */
/* WARNING: Removing unreachable block (ram,0x0d61f4) */
/* WARNING: Removing unreachable block (ram,0x0d61ec) */
/* WARNING: Removing unreachable block (ram,0x0d61e8) */
/* WARNING: Removing unreachable block (ram,0x0d61dc) */
/* WARNING: Removing unreachable block (ram,0x0d61d8) */
/* WARNING: Removing unreachable block (ram,0x0d61d0) */
/* WARNING: Removing unreachable block (ram,0x0d61cc) */
/* WARNING: Removing unreachable block (ram,0x0d61c8) */
/* WARNING: Removing unreachable block (ram,0x0d61c4) */
/* WARNING: Removing unreachable block (ram,0x0d61be) */
/* WARNING: Removing unreachable block (ram,0x0d61ba) */
/* WARNING: Removing unreachable block (ram,0x0d61b6) */
/* WARNING: Removing unreachable block (ram,0x0d61ae) */
/* WARNING: Removing unreachable block (ram,0x0d61a6) */
/* WARNING: Removing unreachable block (ram,0x0d619e) */
/* WARNING: Removing unreachable block (ram,0x0d6148) */
/* WARNING: Removing unreachable block (ram,0x0d6140) */
/* WARNING: Removing unreachable block (ram,0x0d60f2) */
/* WARNING: Removing unreachable block (ram,0x0d60ee) */
/* WARNING: Removing unreachable block (ram,0x0d60ea) */
/* WARNING: Removing unreachable block (ram,0x0d60e4) */
/* WARNING: Removing unreachable block (ram,0x0d60dc) */
/* WARNING: Removing unreachable block (ram,0x0d60d8) */
/* WARNING: Removing unreachable block (ram,0x0d60d6) */
/* WARNING: Removing unreachable block (ram,0x0d60b8) */
/* WARNING: Removing unreachable block (ram,0x0d613e) */
/* WARNING: Removing unreachable block (ram,0x0d613a) */
/* WARNING: Removing unreachable block (ram,0x0d6136) */
/* WARNING: Removing unreachable block (ram,0x0d6130) */
/* WARNING: Removing unreachable block (ram,0x0d6124) */
/* WARNING: Removing unreachable block (ram,0x0d6120) */
/* WARNING: Removing unreachable block (ram,0x0d611c) */
/* WARNING: Removing unreachable block (ram,0x0d6110) */
/* WARNING: Removing unreachable block (ram,0x0d6100) */
/* WARNING: Removing unreachable block (ram,0x0d60fa) */
/* WARNING: Removing unreachable block (ram,0x0d60b2) */
/* WARNING: Removing unreachable block (ram,0x0d60b0) */
/* WARNING: Removing unreachable block (ram,0x0d60a2) */
/* WARNING: Removing unreachable block (ram,0x0d609e) */
/* WARNING: Removing unreachable block (ram,0x0d609a) */
/* WARNING: Removing unreachable block (ram,0x0d6096) */
/* WARNING: Removing unreachable block (ram,0x0d6092) */
/* WARNING: Removing unreachable block (ram,0x0d608e) */
/* WARNING: Removing unreachable block (ram,0x0d6082) */
/* WARNING: Removing unreachable block (ram,0x0d607a) */
/* WARNING: Removing unreachable block (ram,0x0d6076) */
/* WARNING: Removing unreachable block (ram,0x0d6072) */
/* WARNING: Removing unreachable block (ram,0x0d606a) */
/* WARNING: Removing unreachable block (ram,0x0d6064) */
/* WARNING: Removing unreachable block (ram,0x0d603c) */
/* WARNING: Removing unreachable block (ram,0x0d6038) */
/* WARNING: Removing unreachable block (ram,0x0d6030) */
/* WARNING: Removing unreachable block (ram,0x0d6060) */
/* WARNING: Removing unreachable block (ram,0x0d605c) */
/* WARNING: Removing unreachable block (ram,0x0d6056) */
/* WARNING: Removing unreachable block (ram,0x0d604e) */
/* WARNING: Removing unreachable block (ram,0x0d6046) */
/* WARNING: Removing unreachable block (ram,0x0d602a) */
/* WARNING: Removing unreachable block (ram,0x0d6026) */
/* WARNING: Removing unreachable block (ram,0x0d6022) */
/* WARNING: Removing unreachable block (ram,0x0d6018) */
/* WARNING: Removing unreachable block (ram,0x0d6014) */
/* WARNING: Removing unreachable block (ram,0x0d5fc4) */
/* WARNING: Removing unreachable block (ram,0x0d5fc0) */
/* WARNING: Removing unreachable block (ram,0x0d5fbc) */
/* WARNING: Removing unreachable block (ram,0x0d5fb8) */
/* WARNING: Removing unreachable block (ram,0x0d5fb0) */
/* WARNING: Removing unreachable block (ram,0x0d5fac) */
/* WARNING: Removing unreachable block (ram,0x0d5fa6) */
/* WARNING: Removing unreachable block (ram,0x0d5fa4) */
/* WARNING: Removing unreachable block (ram,0x0d5f9a) */
/* WARNING: Removing unreachable block (ram,0x0d5f8e) */
/* WARNING: Removing unreachable block (ram,0x0d5f8a) */
/* WARNING: Removing unreachable block (ram,0x0d5f82) */
/* WARNING: Removing unreachable block (ram,0x0d6010) */
/* WARNING: Removing unreachable block (ram,0x0d600c) */
/* WARNING: Removing unreachable block (ram,0x0d6006) */
/* WARNING: Removing unreachable block (ram,0x0d6002) */
/* WARNING: Removing unreachable block (ram,0x0d5ffa) */
/* WARNING: Removing unreachable block (ram,0x0d5ff6) */
/* WARNING: Removing unreachable block (ram,0x0d5ff0) */
/* WARNING: Removing unreachable block (ram,0x0d5fea) */
/* WARNING: Removing unreachable block (ram,0x0d5fe2) */
/* WARNING: Removing unreachable block (ram,0x0d5fda) */
/* WARNING: Removing unreachable block (ram,0x0d5fd6) */
/* WARNING: Removing unreachable block (ram,0x0d5fd2) */
/* WARNING: Removing unreachable block (ram,0x0d5f78) */
/* WARNING: Removing unreachable block (ram,0x0d5f74) */
/* WARNING: Removing unreachable block (ram,0x0d5f6c) */
/* WARNING: Removing unreachable block (ram,0x0d5f60) */
/* WARNING: Removing unreachable block (ram,0x0d5f50) */
/* WARNING: Removing unreachable block (ram,0x0d601e) */
/* WARNING: Removing unreachable block (ram,0x0d5f3e) */
/* WARNING: Removing unreachable block (ram,0x0d5f3a) */
/* WARNING: Removing unreachable block (ram,0x0d5f34) */
/* WARNING: Removing unreachable block (ram,0x0d5f30) */
/* WARNING: Removing unreachable block (ram,0x0d5f2c) */
/* WARNING: Removing unreachable block (ram,0x0d5f22) */
/* WARNING: Removing unreachable block (ram,0x0d5f1e) */
/* WARNING: Removing unreachable block (ram,0x0d5ed4) */
/* WARNING: Removing unreachable block (ram,0x0d5ece) */
/* WARNING: Removing unreachable block (ram,0x0d5ec6) */
/* WARNING: Removing unreachable block (ram,0x0d5ec2) */
/* WARNING: Removing unreachable block (ram,0x0d5ebe) */
/* WARNING: Removing unreachable block (ram,0x0d5eba) */
/* WARNING: Removing unreachable block (ram,0x0d5eb6) */
/* WARNING: Removing unreachable block (ram,0x0d5f1a) */
/* WARNING: Removing unreachable block (ram,0x0d5f10) */
/* WARNING: Removing unreachable block (ram,0x0d5ef8) */
/* WARNING: Removing unreachable block (ram,0x0d5ee6) */
/* WARNING: Removing unreachable block (ram,0x0d5ee0) */
/* WARNING: Removing unreachable block (ram,0x0d5eac) */
/* WARNING: Removing unreachable block (ram,0x0d5ea0) */
/* WARNING: Removing unreachable block (ram,0x0d5e9c) */
/* WARNING: Removing unreachable block (ram,0x0d5e98) */
/* WARNING: Removing unreachable block (ram,0x0d5e8c) */
/* WARNING: Removing unreachable block (ram,0x0d5e88) */
/* WARNING: Removing unreachable block (ram,0x0d5e7c) */
/* WARNING: Removing unreachable block (ram,0x0d5e84) */
/* WARNING: Removing unreachable block (ram,0x0d5e74) */
/* WARNING: Removing unreachable block (ram,0x0d5e6e) */
/* WARNING: Removing unreachable block (ram,0x0d5e6a) */
/* WARNING: Removing unreachable block (ram,0x0d5e66) */
/* WARNING: Removing unreachable block (ram,0x0d5e58) */
/* WARNING: Removing unreachable block (ram,0x0d5e56) */
/* WARNING: Removing unreachable block (ram,0x0d5e4e) */
/* WARNING: Removing unreachable block (ram,0x0d5e4a) */
/* WARNING: Removing unreachable block (ram,0x0d5e38) */
/* WARNING: Removing unreachable block (ram,0x0d5e34) */
/* WARNING: Removing unreachable block (ram,0x0d5e2e) */
/* WARNING: Removing unreachable block (ram,0x0d5e28) */
/* WARNING: Removing unreachable block (ram,0x0d5e24) */
/* WARNING: Removing unreachable block (ram,0x0d5e20) */
/* WARNING: Removing unreachable block (ram,0x0d5e1c) */
/* WARNING: Removing unreachable block (ram,0x0d5e06) */
/* WARNING: Removing unreachable block (ram,0x0d5e10) */
/* WARNING: Removing unreachable block (ram,0x0d5dfe) */
/* WARNING: Removing unreachable block (ram,0x0d5dfa) */
/* WARNING: Removing unreachable block (ram,0x0d5df6) */
/* WARNING: Removing unreachable block (ram,0x0d5df2) */
/* WARNING: Removing unreachable block (ram,0x0d5da4) */
/* WARNING: Removing unreachable block (ram,0x0d5da0) */
/* WARNING: Removing unreachable block (ram,0x0d5d92) */
/* WARNING: Removing unreachable block (ram,0x0d5d8e) */
/* WARNING: Removing unreachable block (ram,0x0d5d8a) */
/* WARNING: Removing unreachable block (ram,0x0d5d78) */
/* WARNING: Removing unreachable block (ram,0x0d5d74) */
/* WARNING: Removing unreachable block (ram,0x0d5d70) */
/* WARNING: Removing unreachable block (ram,0x0d5d68) */
/* WARNING: Removing unreachable block (ram,0x0d5d64) */
/* WARNING: Removing unreachable block (ram,0x0d5d5a) */
/* WARNING: Removing unreachable block (ram,0x0d5d54) */
/* WARNING: Removing unreachable block (ram,0x0d5d4c) */
/* WARNING: Removing unreachable block (ram,0x0d5d44) */
/* WARNING: Removing unreachable block (ram,0x0d5d3c) */
/* WARNING: Removing unreachable block (ram,0x0d5d36) */
/* WARNING: Removing unreachable block (ram,0x0d5d2c) */
/* WARNING: Removing unreachable block (ram,0x0d5d20) */
/* WARNING: Removing unreachable block (ram,0x0d5d12) */
/* WARNING: Removing unreachable block (ram,0x0d5d02) */
/* WARNING: Removing unreachable block (ram,0x0d5dea) */
/* WARNING: Removing unreachable block (ram,0x0d5de0) */
/* WARNING: Removing unreachable block (ram,0x0d5dd8) */
/* WARNING: Removing unreachable block (ram,0x0d5dd0) */
/* WARNING: Removing unreachable block (ram,0x0d5dcc) */
/* WARNING: Removing unreachable block (ram,0x0d5dc6) */
/* WARNING: Removing unreachable block (ram,0x0d5dbe) */
/* WARNING: Removing unreachable block (ram,0x0d5db2) */
/* WARNING: Removing unreachable block (ram,0x0d5dae) */
/* WARNING: Removing unreachable block (ram,0x0d5cf8) */
/* WARNING: Removing unreachable block (ram,0x0d6198) */
/* WARNING: Removing unreachable block (ram,0x0d6194) */
/* WARNING: Removing unreachable block (ram,0x0d617e) */
/* WARNING: Removing unreachable block (ram,0x0d6178) */
/* WARNING: Removing unreachable block (ram,0x0d616e) */
/* WARNING: Removing unreachable block (ram,0x0d6164) */
/* WARNING: Removing unreachable block (ram,0x0d615a) */
/* WARNING: Removing unreachable block (ram,0x0d6150) */
/* WARNING: Removing unreachable block (ram,0x0d5c9c) */
/* WARNING: Removing unreachable block (ram,0x0d5c92) */
/* WARNING: Removing unreachable block (ram,0x0d5c88) */
/* WARNING: Removing unreachable block (ram,0x0d5c80) */
/* WARNING: Removing unreachable block (ram,0x0d5c70) */
/* WARNING: Removing unreachable block (ram,0x0d5ce8) */
/* WARNING: Removing unreachable block (ram,0x0d5cde) */
/* WARNING: Removing unreachable block (ram,0x0d5cd6) */
/* WARNING: Removing unreachable block (ram,0x0d5cce) */
/* WARNING: Removing unreachable block (ram,0x0d5cc4) */
/* WARNING: Removing unreachable block (ram,0x0d5cbc) */
/* WARNING: Removing unreachable block (ram,0x0d5cb0) */
/* WARNING: Removing unreachable block (ram,0x0d5cac) */
/* WARNING: Removing unreachable block (ram,0x0d5c68) */
/* WARNING: Removing unreachable block (ram,0x0d5c64) */
/* WARNING: Removing unreachable block (ram,0x0d5c60) */
/* WARNING: Removing unreachable block (ram,0x0d5c54) */
/* WARNING: Removing unreachable block (ram,0x0d5c42) */
/* WARNING: Removing unreachable block (ram,0x0d5c3e) */
/* WARNING: Removing unreachable block (ram,0x0d5c38) */
/* WARNING: Removing unreachable block (ram,0x0d5c2e) */
/* WARNING: Removing unreachable block (ram,0x0d5c26) */
/* WARNING: Removing unreachable block (ram,0x0d5c1e) */
/* WARNING: Removing unreachable block (ram,0x0d5c18) */
/* WARNING: Removing unreachable block (ram,0x0d5c0a) */
/* WARNING: Removing unreachable block (ram,0x0d5c06) */
/* WARNING: Removing unreachable block (ram,0x0d5c02) */
/* WARNING: Removing unreachable block (ram,0x0d5bfe) */
/* WARNING: Removing unreachable block (ram,0x0d5bf6) */
/* WARNING: Removing unreachable block (ram,0x0d5bec) */
/* WARNING: Removing unreachable block (ram,0x0d5be6) */
/* WARNING: Removing unreachable block (ram,0x0d5be2) */
/* WARNING: Removing unreachable block (ram,0x0d5bdc) */
/* WARNING: Removing unreachable block (ram,0x0d5bd8) */
/* WARNING: Removing unreachable block (ram,0x0d5bd2) */
/* WARNING: Removing unreachable block (ram,0x0d5bce) */
/* WARNING: Removing unreachable block (ram,0x0d5bbe) */
/* WARNING: Removing unreachable block (ram,0x0d5bba) */
/* WARNING: Removing unreachable block (ram,0x0d5bb4) */
/* WARNING: Removing unreachable block (ram,0x0d5bae) */
/* WARNING: Removing unreachable block (ram,0x0d5b9e) */
/* WARNING: Removing unreachable block (ram,0x0d5b92) */
/* WARNING: Removing unreachable block (ram,0x0d5b8e) */
/* WARNING: Removing unreachable block (ram,0x0d5b8a) */
/* WARNING: Removing unreachable block (ram,0x0d5b86) */
/* WARNING: Removing unreachable block (ram,0x0d5b7e) */
/* WARNING: Removing unreachable block (ram,0x0d5b7a) */
/* WARNING: Removing unreachable block (ram,0x0d5b74) */
/* WARNING: Removing unreachable block (ram,0x0d5b70) */
/* WARNING: Removing unreachable block (ram,0x0d5cca) */
/* WARNING: Removing unreachable block (ram,0x0d5ce4) */
/* WARNING: Removing unreachable block (ram,0x0d6184) */
/* WARNING: Removing unreachable block (ram,0x0d5de6) */
/* WARNING: Removing unreachable block (ram,0x0d5d18) */
/* WARNING: Removing unreachable block (ram,0x0d5d24) */
/* WARNING: Removing unreachable block (ram,0x0d5d60) */
/* WARNING: Removing unreachable block (ram,0x0d5d7c) */
/* WARNING: Removing unreachable block (ram,0x0d5d96) */
/* WARNING: Removing unreachable block (ram,0x0d5e18) */
/* WARNING: Removing unreachable block (ram,0x0d5eb2) */
/* WARNING: Removing unreachable block (ram,0x0d5f46) */
/* WARNING: Removing unreachable block (ram,0x0d5f4a) */
/* WARNING: Removing unreachable block (ram,0x0d5f58) */
/* WARNING: Removing unreachable block (ram,0x0d5fce) */
/* WARNING: Removing unreachable block (ram,0x0d5f86) */
/* WARNING: Removing unreachable block (ram,0x0d6042) */
/* WARNING: Removing unreachable block (ram,0x0d6034) */
/* WARNING: Removing unreachable block (ram,0x0d60f6) */
/* WARNING: Removing unreachable block (ram,0x0d60ca) */
/* WARNING: Removing unreachable block (ram,0x0d61e4) */
/* WARNING: Removing unreachable block (ram,0x0d6272) */
/* WARNING: Removing unreachable block (ram,0x0d629e) */
/* WARNING: Removing unreachable block (ram,0x0d62b4) */
/* WARNING: Removing unreachable block (ram,0x0d638a) */
/* WARNING: Removing unreachable block (ram,0x0d62c6) */
/* WARNING: Removing unreachable block (ram,0x0d6316) */
/* WARNING: Removing unreachable block (ram,0x0d5f0c) */
/* WARNING: Removing unreachable block (ram,0x0d5efc) */
/* WARNING: Removing unreachable block (ram,0x0d5eee) */
/* WARNING: Removing unreachable block (ram,0x0d5edc) */
/* WARNING: Removing unreachable block (ram,0x0d5eea) */
/* WARNING: Removing unreachable block (ram,0x0d5ef4) */

void egs52_update_near_d408_0d5b66(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  short a;
  int iVar7;
  byte bVar8;
  byte bVar9;
  ushort old;
  uchar uVar10;
  uchar *axis;
  byte bVar11;
  short sVar12;
  ushort uVar13;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  
  iVar18 = Ram00f644;
  uVar16 = iVar18 + 0x8e;
  uVar2 = 0x24;
  if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  a = Ram00d40e;
  sVar12 = Ram00d408;
  sVar12 = egs52_blend_percent_s16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)),a,sVar12);
  Ram00d408 = sVar12;
  iVar18 = Ram00f644;
  uVar16 = iVar18 + 0xac;
  uVar2 = 0x24;
  if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar11 = UNK_00d5cc;
  bVar1 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) < bVar11;
  cVar6 = UNK_00d454;
  if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
    bVar11 = UNK_00d454;
    uVar16 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36f;
    uVar2 = 0x24;
    if (((uVar16 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000))))
    {
      uVar2 = 3;
    }
    iVar18 = Ram00f644;
    uVar17 = iVar18 + 100;
    uVar3 = 0x24;
    if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar18 = (int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) *
             (int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff));
  }
  else {
    iVar18 = 0;
  }
  uVar2 = Ram00d440;
  uVar16 = Ram00d43e;
  if (uVar2 < uVar16) {
    uVar14 = Ram00d43e;
    Ram00d440 = uVar14;
  }
  axis = (uchar *)Ram00f646;
  iVar15 = Ram00f646;
  uVar10 = UNK_00d5cc;
  bVar11 = egs52_curve_u8('\a',axis,(uchar *)(iVar15 + 7),uVar10);
  iVar15 = Ram00d424;
  iVar5 = Ram00d440;
  iVar4 = Ram00d43e;
  iVar7 = Ram00f644;
  uVar16 = iVar7 + 0x8c;
  uVar2 = 0x24;
  if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d41e = (uint)bVar11 + iVar15 +
              (int)(((long)(iVar5 - iVar4) *
                    (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) / 10000);
  iVar15 = Ram00f646;
  iVar4 = Ram00f646;
  uVar10 = UNK_00d5cc;
  bVar11 = egs52_curve_u8('\a',(uchar *)(iVar15 + 0xc6),(uchar *)(iVar4 + 0xcd),uVar10);
  uVar16 = (uint)bVar11;
  iVar15 = Ram00d41e;
  uVar2 = Ram00d41e;
  if (uVar16 != uVar2 && iVar15 <= (int)uVar16) {
    Ram00d41e = uVar16;
  }
  bVar11 = UNK_00d566;
  if (bVar11 < 5) {
                    /* WARNING: Switch is manually overridden */
    switch((uint3)*(uint *)((uint3)((uint)bVar11 * 2 + 0x1704) | 0x90000) | 0xd0000) {
    case 0xd5c58:
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 & 0xfffe;
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 & 0xfffd;
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 | 4;
      uVar16 = Ram00fd44;
      Ram00fd44 = uVar16 | 0x20;
      uVar14 = Ram00d40e;
      Ram00d408 = uVar14;
      iVar18 = Ram00d594;
      if (iVar18 == 0) {
        UNK_00d566 = 1;
        cVar6 = UNK_00d454;
        if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
          iVar18 = Ram00f644;
          bVar11 = UNK_00d454;
          uVar2 = iVar18 + 0x27 + (uint)bVar11;
          uVar16 = 0x24;
          if (((uVar2 & 0xc000) != 0) &&
             ((uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
              (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
            uVar16 = 3;
          }
          Ram00d594 = (uint)*(byte *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
        else {
          iVar18 = Ram00f644;
          bVar11 = UNK_00d454;
          uVar2 = iVar18 + 0x24 + (uint)bVar11;
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          Ram00d594 = (uint)*(byte *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
      }
      else {
        cVar6 = UNK_00d454;
        if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
          bVar11 = UNK_00d454;
          iVar18 = Ram00f646;
          iVar15 = Ram00f646;
          bVar8 = UNK_00d5cc;
          uVar13 = egs52_curve_u16(4,(ushort *)(iVar18 + (uint)bVar11 * 8 + 0x22),
                                   (ushort *)(iVar15 + (uint)bVar11 * 8 + 0x42),(uint)bVar8);
        }
        else {
          bVar11 = UNK_00d454;
          iVar15 = Ram00f646;
          iVar18 = Ram00f646;
          bVar8 = UNK_00d5cc;
          uVar13 = egs52_curve_u16(4,(ushort *)(iVar15 + (uint)bVar11 * 8 + 10),
                                   (ushort *)(iVar18 + (uint)bVar11 * 8 + 0x2a),(uint)bVar8);
        }
        bVar11 = UNK_00d454;
        iVar18 = Ram00f624;
        uVar16 = iVar18 + (uint)bVar11 * 2 + 0x94;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar18 = uVar13 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
        if (iVar18 == 0) {
          iVar18 = 0;
        }
        Ram00d556 = iVar18;
        iVar18 = Ram00d594;
        Ram00d594 = iVar18 + -1;
      }
      break;
    case 0xd5cf0:
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 & 0xfffe;
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 & 0xfffd;
      uVar16 = Ram00fd48;
      Ram00fd48 = uVar16 | 4;
      uVar16 = Ram00fd44;
      Ram00fd44 = uVar16 | 8;
      iVar18 = Ram00d594;
      if (iVar18 == 0) {
        UNK_00d566 = 2;
        cVar6 = UNK_00d454;
        if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
          iVar18 = Ram00f644;
          bVar11 = UNK_00d454;
          uVar2 = iVar18 + 0x2b + (uint)bVar11;
          uVar16 = 0x24;
          if (((uVar2 & 0xc000) != 0) &&
             ((uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
              (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
            uVar16 = 3;
          }
          Ram00d594 = (uint)*(byte *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
        else {
          iVar18 = Ram00f644;
          bVar11 = UNK_00d454;
          uVar2 = iVar18 + 0x28 + (uint)bVar11;
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          Ram00d594 = (uint)*(byte *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
      }
      else {
        cVar6 = UNK_00d454;
        if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
          bVar11 = UNK_00d454;
          uVar16 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
          uVar2 = 0x24;
          if (((uVar16 & 0xc000) != 0) &&
             ((uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000 &&
              (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)))) {
            uVar2 = 3;
          }
          iVar18 = Ram00f644;
          uVar17 = iVar18 + 100;
          uVar3 = 0x24;
          if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          Ram00d428 = -(int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) *
                      (int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff));
        }
        else {
          Ram00d428 = 0;
        }
        iVar15 = Ram00f646;
        iVar18 = Ram00f646;
        bVar11 = UNK_00d5cc;
        sVar12 = egs52_curve_s16('\a',(short *)(iVar15 + 0xe),(short *)(iVar18 + 0x1c),(uint)bVar11)
        ;
        bVar11 = UNK_00d454;
        iVar18 = Ram00f624;
        uVar16 = iVar18 + (uint)bVar11 * 2 + 0x94;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar15 = Ram00d556;
        iVar18 = Ram00d428;
        iVar18 = ((iVar15 + iVar18) - *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) -
                 sVar12;
        Ram00d428 = iVar18;
        uVar13 = Ram00d594;
        iVar15 = Ram00f644;
        uVar16 = iVar15 + 0x7b;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar15 = Ram00d556;
        Ram00d556 = iVar15 - (int)(((long)iVar18 *
                                   (long)(int)(uint)*(byte *)((uint3)uVar2 << 0xe |
                                                             (uint3)(uVar16 & 0x3fff))) /
                                  (long)(int)uVar13);
        old = Ram00d56a;
        iVar18 = Ram00f644;
        uVar16 = iVar18 + 0x90;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar13 = egs52_ramp_u16(old,*(ushort *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)),
                                uVar13);
        Ram00d56a = uVar13;
        iVar18 = Ram00d594;
        Ram00d594 = iVar18 + -1;
      }
      break;
    case 0xd5df2:
      iVar18 = Ram00f644;
      uVar16 = iVar18 + 0x90;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d56a = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      iVar18 = Ram00d594;
      if (iVar18 == 0) {
        UNK_00d566 = 3;
      }
      else {
        iVar18 = Ram00d594;
        Ram00d594 = iVar18 + -1;
      }
      break;
    case 0xd5e18:
      iVar15 = Ram00f644;
      uVar16 = iVar15 + 0x90;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d56a = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      iVar4 = Ram00d594;
      Ram00d594 = iVar4 + 1;
      bVar11 = UNK_00d454;
      iVar4 = Ram00f624;
      uVar16 = iVar4 + (uint)bVar11 * 2 + 0x94;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar17 = iVar15 + 0x3c;
      uVar3 = 0x24;
      if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar18 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) +
               *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff)) + iVar18;
      if (iVar18 < 1) {
        iVar18 = 0;
      }
      iVar4 = Ram00d556;
      iVar15 = Ram00f644;
      uVar2 = iVar15 + 0x30;
      uVar16 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar16 = 3;
      }
      iVar5 = Ram00d594;
      iVar15 = Ram00d556;
      Ram00d556 = iVar15 + (iVar18 - iVar4) /
                           (*(int *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) - iVar5);
      uVar16 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar16 = 3;
      }
      iVar18 = Ram00d594;
      if (*(int *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1 != iVar18) {
        iVar18 = Ram00d408;
        if (iVar18 < 0) {
          iVar18 = Ram00d408;
          uVar16 = -iVar18;
        }
        else {
          uVar16 = Ram00d408;
        }
        iVar18 = Ram00f644;
        uVar2 = iVar18 + 0x56;
        uVar17 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar17 = 3;
        }
        if (*(uint *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) <= uVar16) break;
      }
      UNK_00d566 = 4;
      Ram00d594 = 0;
      Ram00d544 = 0;
      break;
    case 0xd5ea8:
      uVar16 = Ram00fd44;
      if (((uVar16 & 1) == 0) && (iVar15 = Ram00d5b4, iVar15 != 0)) {
        iVar4 = Ram00d408;
        iVar15 = Ram00d40c;
        if (iVar4 < iVar15) {
          Ram00d40c = iVar4;
        }
        iVar15 = Ram00d408;
        iVar4 = Ram00d40a;
        iVar5 = Ram00d40a;
        if (iVar15 != iVar5 && iVar4 <= iVar15) {
          Ram00d40a = iVar15;
        }
        iVar15 = Ram00d40a;
        iVar4 = Ram00d40c;
        iVar15 = iVar15 - iVar4;
        if (iVar15 < 0) {
          iVar15 = -iVar15;
        }
        iVar4 = Ram00f644;
        uVar16 = iVar4 + 0x74;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) < iVar15) {
          uVar16 = Ram00fd44;
          Ram00fd44 = uVar16 | 1;
        }
        iVar15 = Ram00d5b4;
        Ram00d5b4 = iVar15 + -1;
      }
      else {
        uVar14 = Ram00d408;
        Ram00d40a = uVar14;
        Ram00d40c = uVar14;
        iVar15 = Ram00f644;
        uVar16 = iVar15 + 0x6e;
        uVar2 = 0x24;
        if (((uVar16 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000 &&
            (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)))) {
          uVar2 = 3;
        }
        Ram00d5b4 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
        uVar16 = Ram00fd44;
        if ((uVar16 & 1) != 0) {
          uVar16 = iVar15 + 0x71;
          uVar2 = 0x24;
          if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          iVar15 = Ram00d424;
          Ram00d424 = iVar15 - (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
          uVar16 = Ram00fd44;
          Ram00fd44 = uVar16 & 0xfffe;
        }
      }
      iVar15 = Ram00d408;
      iVar4 = Ram00d41e;
      iVar5 = Ram00d41e;
      if ((iVar15 != iVar5 && iVar4 <= iVar15) && (uVar16 = Ram00fd44, (uVar16 & 2) == 0)) {
        Ram00d594 = 0;
        iVar15 = Ram00f644;
        uVar16 = iVar15 + 0x70;
        uVar2 = 0x24;
        if (((uVar16 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000 &&
            (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)))) {
          uVar2 = 3;
        }
        UNK_00d617 = -*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      }
      iVar15 = Ram00d594;
      if (iVar15 == 0) {
        iVar15 = Ram00f644;
        uVar16 = iVar15 + 0x35;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cVar6 = UNK_00d617;
        if (cVar6 < '\0') {
          cVar6 = UNK_00d617;
          uVar17 = -(int)cVar6;
        }
        else {
          cVar6 = UNK_00d617;
          uVar17 = (uint)cVar6;
        }
        Ram00d594 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) *
                    ((uVar17 & 0xff) + 1);
        iVar15 = Ram00d408;
        iVar4 = Ram00d41e;
        if (iVar15 < iVar4) {
          uVar16 = Ram00fd44;
          Ram00fd44 = uVar16 & 0xfffd;
          iVar4 = Ram00d41e;
          iVar15 = Ram00d408;
          iVar5 = Ram00f644;
          uVar16 = iVar5 + 0x46;
          uVar2 = 0x24;
          if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          Ram00d428 = (int)(((long)(iVar4 - iVar15) *
                            (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) / 10);
          uVar2 = iVar5 + 0x48;
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          iVar15 = Ram00d428;
          if (*(int *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar15) {
            uVar16 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar16 = 3;
            }
            Ram00d428 = *(undefined2 *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
          }
          cVar6 = UNK_00d617;
          if (cVar6 < '\0') {
            iVar15 = Ram00f644;
            uVar16 = iVar15 + 0x70;
            uVar2 = 0x24;
            if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            UNK_00d617 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
          }
          cVar6 = UNK_00d617;
          UNK_00d617 = cVar6 + '\x01';
        }
        else {
          uVar16 = Ram00fd44;
          Ram00fd44 = uVar16 | 2;
          iVar4 = Ram00d41e;
          iVar15 = Ram00d408;
          iVar5 = Ram00f644;
          uVar16 = iVar5 + 0x44;
          uVar2 = 0x24;
          if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          Ram00d428 = (int)(((long)(iVar4 - iVar15) *
                            (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) / 10);
          uVar16 = iVar5 + 0x48;
          uVar2 = 0x24;
          if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          iVar15 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
          iVar4 = -iVar15;
          iVar5 = Ram00d428;
          iVar7 = Ram00d428;
          if (-iVar7 != iVar15 && iVar5 <= iVar4) {
            Ram00d428 = iVar4;
          }
          cVar6 = UNK_00d617;
          if ('\0' < cVar6) {
            iVar15 = Ram00f644;
            uVar16 = iVar15 + 0x70;
            uVar2 = 0x24;
            if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            UNK_00d617 = -*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
          }
          cVar6 = UNK_00d617;
          UNK_00d617 = cVar6 + -1;
        }
        iVar15 = Ram00d428;
        iVar4 = Ram00d544;
        Ram00d544 = iVar4 + iVar15;
      }
      else {
        iVar15 = Ram00d594;
        Ram00d594 = iVar15 + -1;
      }
      iVar15 = Ram00f644;
      uVar16 = iVar15 + 0x5c;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      cVar6 = UNK_00d617;
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) < cVar6) {
        uVar16 = iVar15 + 0x70;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d617 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
        uVar16 = iVar15 + 0x52;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar15 = Ram00d424;
        Ram00d424 = iVar15 - *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      }
      else {
        iVar15 = Ram00f644;
        uVar16 = iVar15 + 0x5d;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cVar6 = UNK_00d617;
        if ((int)cVar6 < -(int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) {
          uVar16 = iVar15 + 0x70;
          uVar2 = 0x24;
          if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          UNK_00d617 = -*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
          iVar15 = Ram00d424;
          Ram00d424 = iVar15 + 1;
        }
      }
      bVar11 = UNK_00d454;
      iVar15 = Ram00f624;
      uVar16 = iVar15 + (uint)bVar11 * 2 + 0x94;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar15 = Ram00f644;
      uVar17 = iVar15 + 0x3c;
      uVar3 = 0x24;
      if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar15 = Ram00d544;
      iVar15 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) +
               *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff)) + iVar18 + iVar15;
      if (iVar15 < 1) {
        iVar15 = 0;
      }
      Ram00d556 = iVar15;
      iVar18 = Ram00f644;
      uVar16 = iVar18 + 0x90;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d56a = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      uVar16 = iVar18 + 0xad;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar11 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      bVar8 = UNK_00d5cc;
      bVar9 = UNK_00d5cc;
      if (bVar11 != bVar9 && bVar8 <= bVar11) {
        uVar2 = iVar18 + 0x68;
        uVar16 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar16 = 3;
        }
        iVar18 = Ram00d544;
        if (*(int *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar18) {
          cVar6 = UNK_00d454;
          if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
            bVar11 = UNK_00d454;
            uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36f;
            uVar16 = 0x24;
            if (((uVar2 & 0xc000) != 0) &&
               ((uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
                (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
              uVar16 = 3;
            }
            iVar18 = Ram00f644;
            uVar17 = iVar18 + 0x6a;
            uVar3 = 0x24;
            if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            if (*(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) <
                *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff))) {
              uVar16 = iVar18 + 100;
              uVar17 = 0x24;
              if ((((uVar16 & 0xc000) != 0) && (uVar17 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
                 (uVar17 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
                uVar17 = 3;
              }
              iVar18 = Ram00d544;
              Ram00d544 = iVar18 - *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar16 & 0x3fff));
              uVar16 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar16 = 3;
              }
              uVar17 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar17 = 3;
              }
              *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                   *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + '\x01';
            }
          }
        }
        else {
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          iVar18 = *(int *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff));
          iVar15 = Ram00d544;
          iVar4 = Ram00d544;
          if ((-iVar4 != iVar18 && iVar15 <= -iVar18) &&
             ((cVar6 = UNK_00d454, cVar6 == '\x01' || (cVar6 == '\x02')))) {
            bVar11 = UNK_00d454;
            uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36f;
            uVar16 = 0x24;
            if (((uVar2 & 0xc000) != 0) &&
               ((uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
                (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
              uVar16 = 3;
            }
            iVar18 = Ram00f644;
            uVar17 = iVar18 + 0x6a;
            uVar3 = 0x24;
            if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            if (-(int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff)) <
                (int)*(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff))) {
              uVar16 = iVar18 + 100;
              uVar17 = 0x24;
              if ((((uVar16 & 0xc000) != 0) && (uVar17 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
                 (uVar17 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
                uVar17 = 3;
              }
              iVar18 = Ram00d544;
              Ram00d544 = iVar18 + *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar16 & 0x3fff));
              uVar16 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar16 = 3;
              }
              uVar17 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar17 = 3;
              }
              *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                   *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
            }
          }
        }
      }
      iVar18 = Ram00d424;
      if (0 < iVar18) {
        Ram00d424 = 0;
      }
    }
  }
  iVar18 = Ram00f646;
  iVar15 = Ram00f646;
  bVar11 = UNK_00d5cc;
  uVar13 = egs52_curve_u16(7,(ushort *)(iVar18 + 0xd4),(ushort *)(iVar15 + 0xe2),(uint)bVar11);
  Ram00d554 = uVar13;
  uVar17 = Ram00d556;
  uVar16 = Ram00d554;
  uVar2 = Ram00d554;
  if (uVar17 == uVar2 || uVar17 < uVar16) {
    Ram00d556 = uVar13;
  }
  iVar18 = Ram00f644;
  uVar16 = iVar18 + 0xae;
  uVar2 = 0x24;
  if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar11 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
  bVar8 = UNK_00d566;
  bVar9 = UNK_00d566;
  if (bVar11 == bVar9 || bVar11 < bVar8) {
    uVar16 = iVar18 + 0xaf;
    uVar2 = 0x24;
    if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar11 = UNK_00d566;
    if (bVar11 <= *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff))) {
      uVar16 = iVar18 + 0x78;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar15 = Ram00d41e;
      iVar4 = Ram00d528;
      if (iVar4 < *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) - iVar15) {
        uVar16 = iVar18 + 0x4e;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar18 = Ram00d528;
        Ram00d528 = iVar18 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      }
      iVar15 = Ram00d528;
      iVar18 = Ram00d524;
      Ram00d41e = iVar15 - iVar18;
      iVar4 = Ram00f646;
      iVar5 = Ram00f646;
      sVar12 = egs52_curve_s16('\b',(short *)(iVar4 + 0xa6),(short *)(iVar5 + 0xb6),iVar15 - iVar18)
      ;
      Ram00d428 = sVar12;
      iVar18 = Ram00f646;
      iVar15 = Ram00f646;
      sVar12 = Ram00d528;
      sVar12 = egs52_curve_s16('\x03',(short *)(iVar18 + 0xf0),(short *)(iVar15 + 0xf6),sVar12);
      iVar18 = Ram00d428;
      Ram00d428 = (int)(((long)iVar18 * (long)sVar12) / 100);
      iVar18 = Ram00d556;
      iVar15 = Ram00d428;
      iVar18 = iVar18 + iVar15;
      if (iVar18 < 1) {
        iVar18 = 0;
      }
      Ram00d556 = iVar18;
      goto LAB_0d6276;
    }
  }
  uVar14 = Ram00d524;
  Ram00d528 = uVar14;
LAB_0d6276:
  cVar6 = UNK_00d454;
  if ((cVar6 == '\x01') || (cVar6 == '\x02')) {
    cVar6 = UNK_00d566;
    if ((cVar6 == '\0') || (cVar6 == '\x01')) {
      iVar18 = Ram00f644;
      uVar16 = iVar18 + 0xc0;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar16 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      uVar2 = Ram00d526;
      uVar17 = Ram00d526;
      if (uVar16 == uVar17 || uVar16 < uVar2) {
        bVar11 = UNK_00d454;
        uVar16 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar17 = iVar18 + 0xb1;
        uVar3 = 0x24;
        if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) <
            *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff))) {
          bVar11 = UNK_00d454;
          uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          uVar17 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar17 = 3;
          }
          *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + '\x01';
        }
      }
    }
    else if (cVar6 == '\x02') {
      iVar18 = Ram00f644;
      uVar16 = iVar18 + 0xc2;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar16 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
      uVar2 = Ram00d594;
      uVar17 = Ram00d594;
      if (uVar16 == uVar17 || uVar16 < uVar2) {
        uVar16 = iVar18 + 0xc4;
        uVar2 = 0x24;
        if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar18 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff));
        iVar15 = Ram00d428;
        iVar4 = Ram00d428;
        if (iVar18 != iVar4 && iVar15 <= iVar18) {
          bVar11 = UNK_00d454;
          uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          iVar18 = Ram00f644;
          uVar17 = iVar18 + 0xb1;
          uVar3 = 0x24;
          if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          if (-(int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff)) <
              (int)*(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff))) {
            uVar16 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar16 = 3;
            }
            uVar17 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar17 = 3;
            }
            *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                 *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
          }
        }
      }
    }
    else if (cVar6 == '\x03') {
      iVar18 = Ram00f644;
      uVar16 = iVar18 + 0x72;
      uVar2 = 0x24;
      if ((((uVar16 & 0xc000) != 0) && (uVar2 = 0x21, (uVar16 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar16 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar15 = Ram00d41e;
      iVar18 = Ram00d408;
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar16 & 0x3fff)) + iVar15 < iVar18) {
        bVar11 = UNK_00d454;
        uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
        uVar16 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar16 = 3;
        }
        iVar18 = Ram00f644;
        uVar17 = iVar18 + 0xb1;
        uVar3 = 0x24;
        if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (-(int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff)) <
            (int)*(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff))) {
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          uVar17 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar17 = 3;
          }
          *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
        }
      }
      iVar18 = Ram00d408;
      iVar15 = Ram00d41e;
      if (iVar18 < iVar15) {
        bVar11 = UNK_00d454;
        uVar2 = (uint)bVar11 + (uint)bVar1 * 2 + 0xd36b;
        uVar16 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar16 = 3;
        }
        iVar18 = Ram00f644;
        uVar17 = iVar18 + 0xb1;
        uVar3 = 0x24;
        if ((((uVar17 & 0xc000) != 0) && (uVar3 = 0x21, (uVar17 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar17 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (*(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) <
            *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar17 & 0x3fff))) {
          uVar16 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar16 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar16 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar16 = 3;
          }
          uVar17 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar17 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar17 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar17 = 3;
          }
          *(char *)((uint3)uVar17 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar16 << 0xe | (uint3)(uVar2 & 0x3fff)) + '\x01';
        }
      }
    }
  }
  cVar6 = UNK_00d579;
  uVar14 = Ram00d556;
  uVar14 = egs52_update_near_d600_0d7cb8(cVar6 + -1,uVar14);
  Ram00d56c = uVar14;
  return;
}


