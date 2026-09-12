/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098bca; FLS offset 0x018bca.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_097904_098bca(void)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = egs52_update_near_c170_097904();
  if (((uVar2 & 0x100) == 0) || (uVar2 = egs52_update_near_c170_097904(), (uVar2 & 0x200) == 0)) {
    egs52_update_fault_status(2,0);
    egs52_update_fault_status(3,0);
    egs52_update_fault_status(4,0);
    egs52_update_fault_status(0x47,0);
    egs52_update_fault_status(0x48,0);
    egs52_update_fault_status(0x49,0);
  }
  else {
    bVar1 = egs52_compute_from_near_c189_0981ca(2);
    uVar2 = egs52_compute_from_near_c19f_0990f6();
    if ((uVar2 >> 8 & 3) == 3) {
      egs52_update_fault_status(2,0);
    }
    else {
      uVar2 = egs52_compute_from_near_c19f_0990f6();
      if ((uVar2 >> 8 & 1) == 0) {
        if ((bVar1 >> 2 & 3) == 3) {
          egs52_update_fault_status(2,0);
        }
        else {
          egs52_update_fault_status(2,3);
        }
      }
      else if ((bVar1 >> 2 & 3) == 3) {
        egs52_update_fault_status(2,2);
      }
      else {
        egs52_update_fault_status(2,3);
      }
    }
    uVar2 = egs52_compute_from_near_c19f_0990f6();
    if ((uVar2 >> 10 & 3) == 3) {
      egs52_update_fault_status(3,0);
    }
    else {
      uVar2 = egs52_compute_from_near_c19f_0990f6();
      if ((uVar2 >> 10 & 1) == 0) {
        if (bVar1 >> 6 == 3) {
          egs52_update_fault_status(3,0);
        }
        else {
          egs52_update_fault_status(3,3);
        }
      }
      else if (bVar1 >> 6 == 3) {
        egs52_update_fault_status(3,2);
      }
      else {
        egs52_update_fault_status(3,3);
      }
    }
    uVar2 = egs52_compute_from_near_c19f_0990f6();
    if ((uVar2 >> 0xc & 3) == 3) {
      egs52_update_fault_status(4,0);
    }
    else {
      uVar2 = egs52_compute_from_near_c19f_0990f6();
      if ((uVar2 >> 0xc & 1) == 0) {
        if ((bVar1 >> 4 & 3) == 3) {
          egs52_update_fault_status(4,0);
        }
        else {
          egs52_update_fault_status(4,3);
        }
      }
      else if ((bVar1 >> 4 & 3) == 3) {
        egs52_update_fault_status(4,2);
      }
      else {
        egs52_update_fault_status(4,3);
      }
    }
  }
  return;
}


