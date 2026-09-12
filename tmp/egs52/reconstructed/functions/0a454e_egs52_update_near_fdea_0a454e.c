/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a454e; FLS offset 0x02454e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4572) */
/* WARNING: Removing unreachable block (ram,0x0a4564) */
/* WARNING: Removing unreachable block (ram,0x0a455e) */
/* WARNING: Removing unreachable block (ram,0x0a4558) */
/* WARNING: Removing unreachable block (ram,0x0a4552) */
/* WARNING: Removing unreachable block (ram,0x0a456a) */

void egs52_update_near_fdea_0a454e(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 0x100;
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 | 0x400;
  if ((uRam00f572 <= iRam00f576 + 1U) && (uRam00f578 <= uRam00f572 + 1)) {
    Ram00f878 = 0;
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


