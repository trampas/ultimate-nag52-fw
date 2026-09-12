/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097634; FLS offset 0x017634.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097670) */
/* WARNING: Removing unreachable block (ram,0x097668) */
/* WARNING: Removing unreachable block (ram,0x09765a) */
/* WARNING: Removing unreachable block (ram,0x097634) */
/* WARNING: Removing unreachable block (ram,0x097654) */

void egs52_update_near_c170_097634(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram00c170;
  if (((uVar1 & 1) != 0) && ((uVar1 & 4) == 0)) {
    if ((param_1 == 0x100) && ((uVar1 & 0x10) == 0)) {
      if ((uVar1 & 0x100) == 0) {
        uVar1 = Ram00ffc4;
        Ram00ffc4 = uVar1 | 2;
        uVar1 = Ram00c170;
        Ram00c170 = uVar1 | 0x500;
        return;
      }
    }
    else {
      uVar1 = Ram00c170;
      if ((uVar1 & 0x100) != 0) {
        uVar2 = Ram00ffc4;
        Ram00ffc4 = uVar2 & 0xfffd;
        Ram00c172 = 0x2a8;
        Ram00c170 = uVar1 & 0xfeff | 0x400;
      }
    }
  }
  return;
}


