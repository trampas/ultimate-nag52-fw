/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097610; FLS offset 0x017610.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097626) */
/* WARNING: Removing unreachable block (ram,0x097618) */
/* WARNING: Removing unreachable block (ram,0x09762e) */

void egs52_update_near_c172_097610(void)

{
  uint uVar1;
  
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 & 0xfffd;
  Ram00c172 = 0x2a8;
  uVar1 = egs52_compute_from_near_f80a_09941e();
  if ((uVar1 & 2) != 0) {
    Ram00c170 = 3;
    return;
  }
  Ram00c170 = 5;
  return;
}


