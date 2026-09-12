/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08278c; FLS offset 0x00278c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0827e0) */
/* WARNING: Removing unreachable block (ram,0x0827dc) */
/* WARNING: Removing unreachable block (ram,0x0827d8) */
/* WARNING: Removing unreachable block (ram,0x0827d4) */
/* WARNING: Removing unreachable block (ram,0x0827d0) */
/* WARNING: Removing unreachable block (ram,0x0827c6) */
/* WARNING: Removing unreachable block (ram,0x0827c2) */
/* WARNING: Removing unreachable block (ram,0x0827b0) */
/* WARNING: Removing unreachable block (ram,0x0827ac) */
/* WARNING: Removing unreachable block (ram,0x0827a4) */
/* WARNING: Removing unreachable block (ram,0x082796) */
/* WARNING: Removing unreachable block (ram,0x082792) */
/* WARNING: Removing unreachable block (ram,0x08278c) */
/* WARNING: Removing unreachable block (ram,0x0827ba) */

void egs52_update_near_f471_08278c(void)

{
  uint uVar1;
  
  bRam00f471 = bRam00f582 | 0x40;
  if ((bRam00f46d & 0xc0) != 0) {
    bRam00f46d = 0x80;
  }
  bRam00f46d = bRam00f46d & 0xc0;
  if (bRam00f469 < 0x40) {
    bRam00f46d = bRam00f46d | bRam00f469;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfdff;
  }
  else {
    bRam00f470 = bRam00f469;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 0x200;
  }
  uRam00f460 = 0xf46d;
  uRam00f46e = uRam00f46f;
  uRam00f46f = uRam00f594;
  return;
}


