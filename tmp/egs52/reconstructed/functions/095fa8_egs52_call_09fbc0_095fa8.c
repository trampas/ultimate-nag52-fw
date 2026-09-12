/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095fa8; FLS offset 0x015fa8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095fc0) */
/* WARNING: Removing unreachable block (ram,0x095fb4) */
/* WARNING: Removing unreachable block (ram,0x095fac) */
/* WARNING: Removing unreachable block (ram,0x095fb0) */
/* WARNING: Removing unreachable block (ram,0x095fb8) */

void egs52_call_09fbc0_095fa8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam0b0088 - uRam0b0084;
  uVar2 = (iRam0b008a - iRam0b0086) - (uint)(uRam0b0088 < uRam0b0084);
  if (cRam0b2032 == 's') {
    if (uVar2 == uVar1 < 2 && uVar1 == 2 ||
        iRam0b008a - iRam0b0086 == (uint)(uRam0b0088 < uRam0b0084) && uVar1 < 2) {
      egs52_update_fault_status(0x2e,3);
    }
    else {
      egs52_update_fault_status(0x2e,2);
    }
  }
  else if (uVar2 == uVar1 < 2 && uVar1 == 2) {
    egs52_update_fault_status(0x2e,2);
  }
  else {
    egs52_update_fault_status(0x2e,3);
  }
  return;
}


