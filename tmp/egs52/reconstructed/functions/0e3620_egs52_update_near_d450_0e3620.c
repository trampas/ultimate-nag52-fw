/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e3620; FLS offset 0x063620.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3668) */
/* WARNING: Removing unreachable block (ram,0x0e3662) */
/* WARNING: Removing unreachable block (ram,0x0e365e) */
/* WARNING: Removing unreachable block (ram,0x0e3650) */
/* WARNING: Removing unreachable block (ram,0x0e364a) */

void egs52_update_near_d450_0e3620(byte param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (5 < param_1) {
    param_1 = 0;
  }
  if ((5 < param_2) || (param_2 == 0)) {
    param_2 = 8;
  }
  if (((param_1 != 0) || (param_2 != 8)) && (param_1 <= param_2)) {
    if ((param_1 != 0) || (bVar1 = UNK_00d450, param_2 < bVar1)) {
      UNK_00d450 = param_1;
    }
    if ((param_2 == 0) || (param_2 == 8)) {
      bVar1 = UNK_00d44d;
      bVar2 = UNK_00d450;
      if (bVar2 <= bVar1) {
        return;
      }
    }
    UNK_00d44d = param_2;
  }
  return;
}


