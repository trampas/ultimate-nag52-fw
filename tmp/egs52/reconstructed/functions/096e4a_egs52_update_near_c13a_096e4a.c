/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096e4a; FLS offset 0x016e4a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096e64) */
/* WARNING: Removing unreachable block (ram,0x096e5e) */
/* WARNING: Removing unreachable block (ram,0x096e4e) */
/* WARNING: Removing unreachable block (ram,0x096e6e) */
/* WARNING: Removing unreachable block (ram,0x096e5a) */

void egs52_update_near_c13a_096e4a(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x4000) == 0) {
    Ram00c13a = 0;
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x2000;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xbfff;
  return;
}


