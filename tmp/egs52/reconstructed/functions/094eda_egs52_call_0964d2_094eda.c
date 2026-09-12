/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094eda; FLS offset 0x014eda.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094ef6) */
/* WARNING: Removing unreachable block (ram,0x094eee) */
/* WARNING: Removing unreachable block (ram,0x094ee8) */

void egs52_call_0964d2_094eda(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar2 & 0x100) == 0) {
    egs52_update_fault_status(9,0x40);
    return;
  }
  uVar2 = Ram00ffc4;
  if ((uVar2 & 1) == 0) {
    uVar1 = iRam0904d6 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) != '\a') {
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) != '\r') goto LAB_094f2a;
    }
    uVar2 = egs52_compute_from_near_c06e_094d98();
    if ((uVar2 & 0x200) == 0) {
      uVar2 = egs52_call_096f56_09c462(0xd,0);
      if (uVar2 < 0x134) {
        egs52_update_fault_status(9,2);
        return;
      }
      egs52_update_fault_status(9,3);
      return;
    }
  }
LAB_094f2a:
  egs52_update_fault_status(9,0);
  return;
}


