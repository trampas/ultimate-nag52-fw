/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bf7a; FLS offset 0x01bf7a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bfb2) */
/* WARNING: Removing unreachable block (ram,0x09bf92) */
/* WARNING: Removing unreachable block (ram,0x09c004) */
/* WARNING: Removing unreachable block (ram,0x09bffc) */
/* WARNING: Removing unreachable block (ram,0x09bff4) */
/* WARNING: Removing unreachable block (ram,0x09bfee) */
/* WARNING: Removing unreachable block (ram,0x09bfd2) */
/* WARNING: Removing unreachable block (ram,0x09bfce) */
/* WARNING: Removing unreachable block (ram,0x09bf7e) */
/* WARNING: Removing unreachable block (ram,0x09bfc6) */
/* WARNING: Removing unreachable block (ram,0x09bfae) */

undefined1 egs52_update_near_d2d3_09bf7a(byte param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  
  bVar1 = UNK_00c2ce;
  if ((bVar1 & 0x30) == 0) {
    if (param_1 < 8) {
      UNK_00d2d3 = param_1;
      cVar3 = egs52_update_near_c2b4_099570(1,param_1);
      if (cVar3 != '\0') {
        egs52_update_near_c2d0_09bf36();
        return 4;
      }
      bVar1 = UNK_00c2ce;
      UNK_00c2ce = bVar1 & 0x3f;
    }
    else {
      UNK_00c2cf = param_1 / 7;
      UNK_00d2d3 = 0x10;
      UNK_00d2d4 = param_1;
      cVar3 = egs52_update_near_c2b4_099570(2,6);
      if (cVar3 != '\0') {
        egs52_update_near_c2d0_09bf36();
        return 4;
      }
      bVar1 = UNK_00c2d0;
      UNK_00c2d0 = bVar1 & 0xf0;
      UNK_00c2d3 = 2;
      bVar1 = UNK_00c2ce;
      UNK_00c2ce = bVar1 & 0xcf;
      bVar1 = UNK_00c2ce;
      UNK_00c2ce = bVar1 | 0x10;
      egs52_register_sequence_0997f8();
    }
    egs52_compute_from_near_c2ce_09bf18();
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}


