/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1b8c; FLS offset 0x021b8c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined1 egs52_match_fault_status_mask(uchar param_1,uint param_2)

{
  byte bVar1;
  uchar uVar2;
  undefined1 uVar3;
  
  if (((param_2 & 1) != 0) && (uVar2 = egs52_test_fault_status_bit2(param_1), uVar2 == '\x01')) {
    return 1;
  }
  if (((param_2 & 0x12) != 0) && (bVar1 = egs52_update_near_fd6c_0a1220(param_1), bVar1 != 0xff)) {
    if (((param_2 & 2) != 0) && ((bVar1 & 0x40) == 0)) {
      return 1;
    }
    if (((param_2 & 0x10) != 0) && ((bVar1 & 0x20) != 0)) {
      return 1;
    }
  }
  if ((((param_2 & 4) == 0) || (uVar2 = egs52_test_fault_status_bit3(param_1), uVar2 != '\0')) ||
     (uVar2 = egs52_test_fault_status_bit2(param_1), uVar2 != '\0')) {
    if (((param_2 & 0x20) == 0) || (uVar2 = egs52_test_fault_bitmap(param_1), uVar2 != '\0')) {
      if (((param_2 & 0x40) == 0) || (uVar2 = egs52_test_fault_status_bit7(param_1), uVar2 != '\0'))
      {
        if (((param_2 & 8) == 0) || (uVar2 = egs52_test_fault_status_bit4(param_1), uVar2 == '\0'))
        {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


