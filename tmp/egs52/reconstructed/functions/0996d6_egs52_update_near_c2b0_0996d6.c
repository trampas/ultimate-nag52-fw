/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0996d6; FLS offset 0x0196d6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099702) */
/* WARNING: Removing unreachable block (ram,0x0996f6) */
/* WARNING: Removing unreachable block (ram,0x0996ea) */
/* WARNING: Removing unreachable block (ram,0x099730) */
/* WARNING: Removing unreachable block (ram,0x099724) */
/* WARNING: Removing unreachable block (ram,0x09971c) */
/* WARNING: Removing unreachable block (ram,0x099718) */
/* WARNING: Removing unreachable block (ram,0x0997ec) */
/* WARNING: Removing unreachable block (ram,0x0997e4) */
/* WARNING: Removing unreachable block (ram,0x0997dc) */
/* WARNING: Removing unreachable block (ram,0x0997d8) */
/* WARNING: Removing unreachable block (ram,0x0997a6) */
/* WARNING: Removing unreachable block (ram,0x0997d2) */
/* WARNING: Removing unreachable block (ram,0x0997ca) */
/* WARNING: Removing unreachable block (ram,0x0997c2) */
/* WARNING: Removing unreachable block (ram,0x0997b8) */
/* WARNING: Removing unreachable block (ram,0x0997b0) */
/* WARNING: Removing unreachable block (ram,0x099798) */
/* WARNING: Removing unreachable block (ram,0x099786) */
/* WARNING: Removing unreachable block (ram,0x099780) */
/* WARNING: Removing unreachable block (ram,0x099778) */
/* WARNING: Removing unreachable block (ram,0x099770) */
/* WARNING: Removing unreachable block (ram,0x099768) */
/* WARNING: Removing unreachable block (ram,0x099760) */
/* WARNING: Removing unreachable block (ram,0x09974e) */
/* WARNING: Removing unreachable block (ram,0x099748) */
/* WARNING: Removing unreachable block (ram,0x09973c) */
/* WARNING: Removing unreachable block (ram,0x0996e0) */
/* WARNING: Removing unreachable block (ram,0x0996dc) */
/* WARNING: Removing unreachable block (ram,0x0996d6) */
/* WARNING: Removing unreachable block (ram,0x09970c) */
/* WARNING: Removing unreachable block (ram,0x099758) */
/* WARNING: Removing unreachable block (ram,0x0996ee) */

void egs52_update_near_c2b0_0996d6(char param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  
  UNK_00c2b0 = 0;
  UNK_00c2b1 = 1;
  cVar2 = UNK_00c1af;
  if (cVar2 == '(') {
    UNK_00c1ad = 1;
    UNK_00c2b2 = 1;
    cVar2 = UNK_00c1af;
    UNK_00c1af = cVar2 + '@';
    egs52_update_near_d2d3_09bf7a(1);
    bVar1 = UNK_00c1ac;
    UNK_00c1ac = bVar1 | 1;
    egs52_update_near_c2b6_0999ec();
    return;
  }
  cVar2 = UNK_00c1af;
  if (cVar2 == ')') {
    UNK_00c1ad = 1;
    UNK_00c2b2 = 1;
    cVar2 = UNK_00c1af;
    UNK_00c1af = cVar2 + '@';
    egs52_compute_from_near_c2b6_0999e2();
    bVar1 = UNK_00c1ac;
    UNK_00c1ac = bVar1 & 0xfe;
    egs52_update_near_d2d3_09bf7a(1);
    return;
  }
  bVar1 = UNK_00c1ac;
  if ((bVar1 & 1) != 0) {
    bVar1 = UNK_00c2ce;
    UNK_00c2ce = bVar1 & 0x3f;
    return;
  }
  bVar1 = UNK_00c1ac;
  if ((bVar1 & 0x80) == 0) {
    cVar2 = UNK_00c1af;
    if (cVar2 == '\x10') {
      cVar2 = UNK_00c1b0;
      if (cVar2 != -0x6e) {
        bVar1 = UNK_00c2ce;
        UNK_00c2ce = bVar1 & 0x3f;
        return;
      }
    }
    else if (cVar2 != '>') {
      uVar3 = UNK_00c1af;
      UNK_00c1b0 = uVar3;
      UNK_00c1af = 0x7f;
      UNK_00c1b1 = 0x80;
      egs52_update_near_d2d3_09bf7a(3);
      return;
    }
    bVar1 = UNK_00c1ac;
    UNK_00c1ac = bVar1 | 0x80;
    UNK_00c2ae = 200;
    egs52_register_sequence_0a57f8();
    UNK_00c2af = 8;
    bVar1 = UNK_00c1ac;
    UNK_00c1ac = bVar1 & 0xbf;
    bVar1 = UNK_00c1ac;
    UNK_00c1ac = bVar1 | 0x20;
    return;
  }
  UNK_00c2af = 8;
  bVar1 = UNK_00c1ac;
  UNK_00c1ac = bVar1 & 0xbf;
  UNK_00c1ad = param_1 + -1;
  bVar1 = UNK_00c1ac;
  UNK_00c1ac = bVar1 & 0xef;
  bVar1 = UNK_00c1ac;
  UNK_00c1ac = bVar1 & 0xf7;
  bVar1 = UNK_00c1ac;
  UNK_00c1ac = bVar1 | 0x20;
  return;
}


