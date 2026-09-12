/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097904; FLS offset 0x017904.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097922) */
/* WARNING: Removing unreachable block (ram,0x09791e) */
/* WARNING: Removing unreachable block (ram,0x097916) */
/* WARNING: Removing unreachable block (ram,0x09790c) */

undefined2 egs52_update_near_c170_097904(void)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = Ram00ffc4;
  if ((uVar1 & 2) == 0) {
    uVar1 = Ram00c170;
    Ram00c170 = uVar1 & 0xfeff;
  }
  else {
    uVar1 = Ram00c170;
    Ram00c170 = uVar1 | 0x100;
  }
  uVar1 = Ram00c170;
  Ram00c170 = uVar1 | 0x200;
  uVar2 = Ram00c170;
  return uVar2;
}


