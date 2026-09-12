/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0977f4; FLS offset 0x0177f4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09789c) */
/* WARNING: Removing unreachable block (ram,0x097894) */
/* WARNING: Removing unreachable block (ram,0x09787e) */
/* WARNING: Removing unreachable block (ram,0x0978ba) */
/* WARNING: Removing unreachable block (ram,0x0978b2) */
/* WARNING: Removing unreachable block (ram,0x0978d4) */
/* WARNING: Removing unreachable block (ram,0x097840) */
/* WARNING: Removing unreachable block (ram,0x097830) */
/* WARNING: Removing unreachable block (ram,0x097824) */
/* WARNING: Removing unreachable block (ram,0x0978ec) */
/* WARNING: Removing unreachable block (ram,0x097806) */
/* WARNING: Removing unreachable block (ram,0x0978e4) */
/* WARNING: Removing unreachable block (ram,0x097828) */
/* WARNING: Removing unreachable block (ram,0x097868) */
/* WARNING: Removing unreachable block (ram,0x097870) */
/* WARNING: Removing unreachable block (ram,0x0978ca) */
/* WARNING: Removing unreachable block (ram,0x097886) */

void egs52_update_near_c170_0977f4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = egs52_compute_from_near_f80a_09941e();
  if (((uVar3 & 2) == 0) || (uVar3 = Ram00c170, (uVar3 & 4) == 0)) {
    egs52_update_fault_status(0x38,0);
  }
  else {
    uVar3 = egs52_compute_from_near_c06e_094d98();
    if ((uVar3 & 0x60) == 0) {
      uVar3 = Ram00ffc4;
      Ram00ffc4 = uVar3 | 2;
      uVar3 = Ram00c170;
      Ram00c170 = uVar3 | 0x500;
      iVar5 = Ram00fe42;
      uVar3 = Ram00fe40;
      uVar3 = (iVar5 + 600U) % uVar3;
      do {
        uVar4 = Ram00fe42;
      } while (uVar3 != uVar4 && -1 < (int)(uVar3 - uVar4));
      uVar3 = egs52_compute_from_near_f0a0_096fb6(0xe);
      iVar5 = 2;
      do {
        uVar4 = egs52_compute_from_near_f0a0_096fb6(0xe);
        if (uVar3 <= uVar4) {
          uVar4 = uVar3;
        }
        iVar5 = iVar5 + -1;
        uVar3 = uVar4;
      } while (iVar5 != 0);
      uVar3 = Ram00ffc0;
      uVar1 = Ram00c172;
      uVar2 = Ram00c172;
      if ((uVar4 == uVar2 || uVar4 < uVar1) || ((uVar3 | 0xff8f) != 0xffff)) {
        if ((uVar3 & 0x70) == 0) {
          egs52_update_fault_status(0x38,2);
          uVar3 = Ram00c170;
          Ram00c170 = uVar3 & 0xfffb | 10;
        }
        else {
          egs52_update_fault_status(0x38,0);
          uVar3 = Ram00c170;
          Ram00c170 = uVar3 & 0xfffb | 2;
        }
      }
      else {
        uVar3 = Ram00ffc4;
        Ram00ffc4 = uVar3 & 0xfffd;
        uVar3 = Ram00c170;
        Ram00c170 = uVar3 & 0xfeff | 0x400;
        egs52_update_fault_status(0x38,3);
        uVar3 = Ram00c170;
        Ram00c170 = uVar3 & 0xfffb | 0x20;
      }
    }
    else {
      egs52_update_fault_status(0x38,0);
      uVar3 = Ram00c170;
      Ram00c170 = uVar3 & 0xfffb | 2;
    }
  }
  return;
}


