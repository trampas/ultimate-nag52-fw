/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0965d2; FLS offset 0x0165d2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x096774) */
/* WARNING: Removing unreachable block (ram,0x096760) */
/* WARNING: Removing unreachable block (ram,0x09669c) */
/* WARNING: Removing unreachable block (ram,0x096698) */
/* WARNING: Removing unreachable block (ram,0x096694) */
/* WARNING: Removing unreachable block (ram,0x096690) */
/* WARNING: Removing unreachable block (ram,0x09666e) */
/* WARNING: Removing unreachable block (ram,0x09664c) */
/* WARNING: Removing unreachable block (ram,0x096616) */
/* WARNING: Removing unreachable block (ram,0x09660e) */
/* WARNING: Removing unreachable block (ram,0x09660a) */
/* WARNING: Removing unreachable block (ram,0x0965fa) */
/* WARNING: Removing unreachable block (ram,0x0965f6) */
/* WARNING: Removing unreachable block (ram,0x0965f0) */
/* WARNING: Removing unreachable block (ram,0x0965e6) */
/* WARNING: Removing unreachable block (ram,0x0966fa) */
/* WARNING: Removing unreachable block (ram,0x0966f8) */
/* WARNING: Removing unreachable block (ram,0x09671a) */
/* WARNING: Removing unreachable block (ram,0x096718) */
/* WARNING: Removing unreachable block (ram,0x0966e8) */
/* WARNING: Removing unreachable block (ram,0x0966d2) */
/* WARNING: Removing unreachable block (ram,0x0966dc) */

void egs52_update_near_c10a_0965d2(void)

{
  int iVar1;
  byte bVar2;
  uchar uVar3;
  char cVar4;
  uint uVar5;
  
  bVar2 = egs52_get_status_c32a();
  if ((bVar2 & 4) == 0) {
    uVar5 = Ram00fd00;
    if ((uVar5 & 0x10) == 0) {
      cVar4 = UNK_00f803;
      if (cVar4 == '\0') {
        uRam00f3f8 = uRam00f3f8 | 0x1084;
        UNK_00f803 = 1;
      }
      if (((((uRam00f3f8 & 0xc6) != 0) &&
           ((*(code *)((uint3)uRam080206 << 0x10 | (uint3)uRam080204))(uRam00f3f8 & 0xc6),
           (uRam00f3f8 & 0x100) != 0)) && ((uRam00f3f8 & 8) != 0)) && ((uRam00f3f8 & 0x2000) != 0))
      {
        if ((uRam00f3f8 & 0x400) == 0) {
          egs52_update_fault_status(0x3f,3);
        }
        else {
          egs52_update_fault_status(0x3f,2);
        }
        if (((uRam00f3f8 & 0x20) == 0) || ((uRam00f3f8 & 0x200) != 0)) {
          egs52_update_fault_status(0x3f,3);
        }
        else {
          egs52_update_fault_status(0x3f,2);
        }
        if (((uRam00f3f8 & 1) == 0) || ((uRam00f3f8 & 0x10) != 0)) {
          egs52_update_fault_status(0x3f,3);
        }
        else {
          egs52_update_fault_status(0x3f,2);
        }
        Ram00c10a = iRam00f5ba + iRam00f5bc + iRam00f5be;
        uVar5 = Ram00fd00;
        Ram00fd00 = uVar5 | 0x10;
      }
    }
    else {
      bVar2 = egs52_get_status_c32a();
      if (((bVar2 & 1) == 0) || (uVar5 = egs52_compute_from_near_c06e_094d98(), (uVar5 & 0x40) != 0)
         ) {
        uVar5 = Ram00fd00;
        Ram00fd00 = uVar5 & 0xffef;
      }
      else {
        uVar5 = egs52_compute_from_near_c064_093f8a();
        if (((uVar5 & 4) == 0) || (uVar5 = Ram00fd00, (uVar5 & 8) == 0)) {
          cVar4 = egs52_update_near_c043_093e10(0x4000,8,0x1ff6);
          if (cVar4 == '\0') {
            uVar5 = Ram00fd00;
            Ram00fd00 = uVar5 & 0xffdf;
            uVar5 = Ram00fd00;
            Ram00fd00 = uVar5 | 8;
          }
        }
        else {
          uVar3 = egs52_read_indexed_word_c044((uchar *)0xc114);
          if (uVar3 == '\0') {
            uVar5 = Ram00fd00;
            Ram00fd00 = uVar5 & 0xfff7;
            iVar1 = Ram00c114;
            uVar5 = Ram00c114;
            Ram00c114 = iVar1 << 8 | uVar5 >> 8;
            uVar5 = Ram00fd00;
            if ((uVar5 & 0x20) == 0) {
              iVar1 = Ram00c114;
              if (iRam085ffe == iVar1) {
                cVar4 = egs52_update_near_c043_093e10(0x6000,8,0x1ff6);
                if (cVar4 == '\0') {
                  uVar5 = Ram00fd00;
                  Ram00fd00 = uVar5 | 0x20;
                  uVar5 = Ram00fd00;
                  Ram00fd00 = uVar5 | 8;
                }
              }
              else {
                egs52_update_fault_status(0x3f,3);
                uVar5 = Ram00fd00;
                Ram00fd00 = uVar5 & 0xffef;
              }
            }
            else {
              iVar1 = Ram00c114;
              if (iRam087ffe != iVar1) {
                egs52_update_fault_status(0x3f,3);
              }
              uVar5 = Ram00fd00;
              Ram00fd00 = uVar5 & 0xffef;
              uVar5 = Ram00fd00;
              Ram00fd00 = uVar5 & 0xffdf;
            }
          }
        }
      }
    }
  }
  else {
    egs52_update_near_c332_09ef1e();
  }
  if ((((uRam00f3f8 & 0x100) != 0) && ((uRam00f3f8 & 8) != 0)) && ((uRam00f3f8 & 0x2000) != 0)) {
    uRam00f3f8 = uRam00f3f8 | 0x1084;
  }
  return;
}


