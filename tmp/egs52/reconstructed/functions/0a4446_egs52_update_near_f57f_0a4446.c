/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4446; FLS offset 0x024446.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a44e2) */
/* WARNING: Removing unreachable block (ram,0x0a44dc) */
/* WARNING: Removing unreachable block (ram,0x0a44d8) */
/* WARNING: Removing unreachable block (ram,0x0a44d4) */
/* WARNING: Removing unreachable block (ram,0x0a44d0) */
/* WARNING: Removing unreachable block (ram,0x0a44cc) */
/* WARNING: Removing unreachable block (ram,0x0a44c4) */
/* WARNING: Removing unreachable block (ram,0x0a44c0) */
/* WARNING: Removing unreachable block (ram,0x0a44ba) */
/* WARNING: Removing unreachable block (ram,0x0a44b6) */
/* WARNING: Removing unreachable block (ram,0x0a44b2) */
/* WARNING: Removing unreachable block (ram,0x0a44aa) */
/* WARNING: Removing unreachable block (ram,0x0a44a2) */
/* WARNING: Removing unreachable block (ram,0x0a449a) */
/* WARNING: Removing unreachable block (ram,0x0a4496) */
/* WARNING: Removing unreachable block (ram,0x0a4492) */
/* WARNING: Removing unreachable block (ram,0x0a4488) */
/* WARNING: Removing unreachable block (ram,0x0a4480) */
/* WARNING: Removing unreachable block (ram,0x0a4478) */
/* WARNING: Removing unreachable block (ram,0x0a4466) */
/* WARNING: Removing unreachable block (ram,0x0a445e) */
/* WARNING: Removing unreachable block (ram,0x0a444a) */
/* WARNING: Removing unreachable block (ram,0x0a4456) */

void egs52_update_near_f57f_0a4446(void)

{
  uint uVar1;
  
  if (cRam083fcc == -1) {
    bRam00f57f = 3;
  }
  else {
    bRam00f57f = 1;
  }
  if ((cRam083e7c == -1) || (cRam083e7c == -4)) {
    bRam00f57f = bRam00f57f | 0xc;
  }
  uRam00f594 = 0x20;
  uRam00f595 = 0x10;
  egs52_update_near_f594_0a44ec();
  uRam00f580 = 1;
  Ram00fdea = 0;
  Ram00fdec = 0;
  uRam00f460 = 0xf46d;
  uRam00f462 = 0xf472;
  uRam00f464 = 0xf472;
  uRam00f468 = 0xff;
  uRam00f572 = 0;
  uRam00f5b0 = 1;
  uRam00f574 = 0;
  uRam00f576 = 0xfffd;
  uRam00f578 = 0;
  uRam00f57c = 0;
  Ram00f878 = 0;
  uRam00f57e = 0;
  uVar1 = Ram00fde8;
  Ram00fde8 = uVar1 & 0xfffe;
  uRam00f5a0 = 0;
  egs52_update_near_f878_09492a();
  return;
}


