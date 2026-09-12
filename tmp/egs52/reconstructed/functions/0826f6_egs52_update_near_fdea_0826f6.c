/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0826f6; FLS offset 0x0026f6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08271a) */
/* WARNING: Removing unreachable block (ram,0x08270c) */
/* WARNING: Removing unreachable block (ram,0x082706) */
/* WARNING: Removing unreachable block (ram,0x082700) */
/* WARNING: Removing unreachable block (ram,0x0826fa) */
/* WARNING: Removing unreachable block (ram,0x082712) */

void egs52_update_near_fdea_0826f6(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 0x100;
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 | 0x400;
  if ((uRam00f572 <= iRam00f576 + 1U) && (uRam00f578 <= uRam00f572 + 1)) {
    uRam00f5b2 = 0;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfeff;
    return;
  }
  if (iRam00f576 + 1U < uRam00f572) {
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 0x800;
  }
  return;
}


