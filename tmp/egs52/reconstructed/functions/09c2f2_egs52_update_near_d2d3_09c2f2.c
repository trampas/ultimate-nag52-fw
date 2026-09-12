/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c2f2; FLS offset 0x01c2f2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09c3f8) */
/* WARNING: Removing unreachable block (ram,0x09c3f4) */
/* WARNING: Removing unreachable block (ram,0x09c3e8) */
/* WARNING: Removing unreachable block (ram,0x09c438) */
/* WARNING: Removing unreachable block (ram,0x09c430) */
/* WARNING: Removing unreachable block (ram,0x09c42c) */
/* WARNING: Removing unreachable block (ram,0x09c420) */
/* WARNING: Removing unreachable block (ram,0x09c41c) */
/* WARNING: Removing unreachable block (ram,0x09c414) */
/* WARNING: Removing unreachable block (ram,0x09c410) */
/* WARNING: Removing unreachable block (ram,0x09c408) */
/* WARNING: Removing unreachable block (ram,0x09c3dc) */
/* WARNING: Removing unreachable block (ram,0x09c3c6) */
/* WARNING: Removing unreachable block (ram,0x09c3ae) */
/* WARNING: Removing unreachable block (ram,0x09c3aa) */
/* WARNING: Removing unreachable block (ram,0x09c38c) */
/* WARNING: Removing unreachable block (ram,0x09c382) */
/* WARNING: Removing unreachable block (ram,0x09c37e) */
/* WARNING: Removing unreachable block (ram,0x09c374) */
/* WARNING: Removing unreachable block (ram,0x09c342) */
/* WARNING: Removing unreachable block (ram,0x09c35e) */
/* WARNING: Removing unreachable block (ram,0x09c356) */
/* WARNING: Removing unreachable block (ram,0x09c370) */
/* WARNING: Removing unreachable block (ram,0x09c368) */
/* WARNING: Removing unreachable block (ram,0x09c348) */
/* WARNING: Removing unreachable block (ram,0x09c332) */
/* WARNING: Removing unreachable block (ram,0x09c312) */
/* WARNING: Removing unreachable block (ram,0x09c30e) */
/* WARNING: Removing unreachable block (ram,0x09c30a) */
/* WARNING: Removing unreachable block (ram,0x09c2fe) */
/* WARNING: Removing unreachable block (ram,0x09c2fa) */
/* WARNING: Removing unreachable block (ram,0x09c2f2) */
/* WARNING: Removing unreachable block (ram,0x09c33e) */
/* WARNING: Removing unreachable block (ram,0x09c3bc) */
/* WARNING: Removing unreachable block (ram,0x09c400) */
/* WARNING: Removing unreachable block (ram,0x09c3ec) */

void egs52_update_near_d2d3_09c2f2(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = UNK_00c2d2;
  if (cVar2 != '\0') {
    cVar2 = UNK_00c2d2;
    UNK_00c2d2 = cVar2 + -1;
    cVar2 = UNK_00c2d2;
    if (cVar2 == '\0') {
      bVar1 = UNK_00c2ce;
      UNK_00c2ce = bVar1 & 0x3f;
    }
  }
  bVar1 = UNK_00c2ce;
  if ((bVar1 & 0x30) == 0x30) {
    iVar3 = egs52_transform_far_memory_0a0770(0,8);
    if (iVar3 == 1) {
      cVar2 = UNK_00c2cf;
      if (cVar2 == '\0') {
        bVar1 = UNK_00c2ce;
        UNK_00c2ce = bVar1 & 0xcf;
      }
      else {
        bVar1 = UNK_00c2d1;
        if ((bVar1 & 0xf) == 0) {
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 & 0xcf;
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 | 0x10;
        }
        else {
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 & 0xcf;
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 | 0x20;
        }
      }
    }
    else {
      egs52_update_near_c2d0_09bf36();
    }
  }
  cVar2 = UNK_00c2d3;
  if (cVar2 != '\0') {
    cVar2 = UNK_00c2d3;
    UNK_00c2d3 = cVar2 + -1;
    cVar2 = UNK_00c2d3;
    if (cVar2 == '\0') {
      bVar1 = UNK_00c2ce;
      if ((bVar1 & 0x30) == 0x10) {
        egs52_update_near_c2d0_09bf36();
        return;
      }
      if ((bVar1 & 0x30) == 0x20) {
        cVar2 = UNK_00c2cf;
        UNK_00c2cf = cVar2 + -1;
        bVar1 = UNK_00d2d3;
        if ((bVar1 & 0xf) < 0xf) {
          cVar2 = UNK_00d2d3;
          UNK_00d2d3 = cVar2 + '\x01';
        }
        else {
          UNK_00d2d3 = 0x20;
        }
        cVar2 = egs52_update_near_c2b4_099570(1,7);
        if (cVar2 != '\0') {
          egs52_update_near_c2d0_09bf36();
          return;
        }
        cVar2 = UNK_00c2cf;
        if (cVar2 == '\0') {
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 & 0xcf;
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 & 0x3f;
        }
        else {
          UNK_00c2d3 = 2;
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 & 0xcf;
          bVar1 = UNK_00c2ce;
          UNK_00c2ce = bVar1 | 0x20;
          cVar2 = UNK_00c2d0;
          if (cVar2 != '\0') {
            cVar2 = UNK_00c2d0;
            UNK_00c2d0 = cVar2 + -1;
            bVar1 = UNK_00c2d0;
            if ((bVar1 & 0xf) == 0) {
              UNK_00c2d3 = 1;
              bVar1 = UNK_00c2ce;
              UNK_00c2ce = bVar1 & 0xcf;
              bVar1 = UNK_00c2ce;
              UNK_00c2ce = bVar1 | 0x10;
            }
          }
          egs52_register_sequence_0997f8();
        }
        egs52_compute_from_near_c2ce_09bf18();
      }
    }
  }
  return;
}


