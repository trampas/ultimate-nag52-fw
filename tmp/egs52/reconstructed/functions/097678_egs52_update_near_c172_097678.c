/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097678; FLS offset 0x017678.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_u32_registers replaced with injection: egs52_udiv32_registers */
/* WARNING: Removing unreachable block (ram,0x0977d8) */
/* WARNING: Removing unreachable block (ram,0x0977c8) */
/* WARNING: Removing unreachable block (ram,0x0977bc) */
/* WARNING: Removing unreachable block (ram,0x0977b4) */
/* WARNING: Removing unreachable block (ram,0x0977ac) */
/* WARNING: Removing unreachable block (ram,0x09772e) */
/* WARNING: Removing unreachable block (ram,0x097734) */
/* WARNING: Removing unreachable block (ram,0x0976f8) */
/* WARNING: Removing unreachable block (ram,0x0976c4) */
/* WARNING: Removing unreachable block (ram,0x097764) */
/* WARNING: Removing unreachable block (ram,0x097754) */
/* WARNING: Removing unreachable block (ram,0x09767a) */
/* WARNING: Removing unreachable block (ram,0x0977e2) */

void egs52_update_near_c172_097678(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = Ram00c170;
  if ((uVar4 & 1) != 0) {
    uVar4 = uVar4 & 0x510;
    if (uVar4 == 0) {
      uVar4 = Ram00ffc4;
      if ((uVar4 & 2) == 0) {
        uVar3 = egs52_update_near_fd00_096f56(0xb,0);
        uVar4 = Ram00c172;
        uVar1 = Ram00c172;
        if (uVar3 == uVar1 || uVar3 < uVar4) {
          uVar4 = Ram00c172;
          if (uVar4 < 0xf1) {
            egs52_update_fault_status(10,2);
          }
          else {
            uVar4 = egs52_update_near_fd00_096f56(0xb,0);
            uVar4 = (uint)(((ulong)uVar4 * 0x62) / 100);
            if (uVar4 < 0xf0) {
              Ram00c172 = 0xf0;
            }
            else {
              Ram00c172 = uVar4;
            }
            egs52_update_fault_status(10,0);
          }
        }
        else {
          cVar2 = egs52_match_fault_status_mask(2,1);
          if (((cVar2 == '\0') && (cVar2 = egs52_match_fault_status_mask(3,1), cVar2 == '\0')) &&
             (cVar2 = egs52_match_fault_status_mask(4,1), cVar2 == '\0')) {
            egs52_update_fault_status(10,3);
          }
        }
      }
      else {
        uVar4 = Ram00c170;
        Ram00c170 = uVar4 | 0x2100;
        uVar4 = Ram00ffc4;
        if ((uVar4 & 0x40) != 0) {
          uVar4 = Ram00c170;
          Ram00c170 = uVar4 | 0x4200;
        }
      }
    }
    else if (uVar4 == 0x100) {
      uVar5 = egs52_get_status_c1aa();
      if (((uVar5 & 2) == 0) || (uVar4 = Ram00ffc4, (uVar4 & 2) == 0)) {
        uVar4 = Ram00ffc4;
        Ram00ffc4 = uVar4 & 0xfffd;
        uVar4 = Ram00c170;
        Ram00c170 = uVar4 & 0xfeff | 0x400;
        Ram00c172 = 0x2a8;
      }
      else {
        iVar6 = egs52_update_near_fd00_096f56(0,0);
        iVar7 = egs52_update_near_fd00_096f56(0xb,0);
        if (iVar6 - iVar7 < 0x8d) {
          egs52_update_fault_status(10,2);
        }
        else {
          egs52_update_fault_status(10,3);
        }
      }
    }
    else if ((uVar4 == 0x500) || (uVar4 == 0x400)) {
      uVar4 = Ram00c170;
      Ram00c170 = uVar4 & 0xfbff;
    }
    else if ((uVar4 == 0x10) || (uVar4 == 0x110)) {
      uVar4 = Ram00ffc4;
      Ram00ffc4 = uVar4 & 0xfffd;
      uVar4 = Ram00c170;
      Ram00c170 = uVar4 & 0xfcff;
    }
    else {
      Ram00c170 = 0x10;
    }
  }
  return;
}


