/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082392; FLS offset 0x002392.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x082432) */
/* WARNING: Removing unreachable block (ram,0x08242c) */
/* WARNING: Removing unreachable block (ram,0x082428) */
/* WARNING: Removing unreachable block (ram,0x082424) */
/* WARNING: Removing unreachable block (ram,0x082420) */
/* WARNING: Removing unreachable block (ram,0x08241c) */
/* WARNING: Removing unreachable block (ram,0x082414) */
/* WARNING: Removing unreachable block (ram,0x082410) */
/* WARNING: Removing unreachable block (ram,0x08240a) */
/* WARNING: Removing unreachable block (ram,0x082406) */
/* WARNING: Removing unreachable block (ram,0x082402) */
/* WARNING: Removing unreachable block (ram,0x0823fa) */
/* WARNING: Removing unreachable block (ram,0x0823f2) */
/* WARNING: Removing unreachable block (ram,0x0823ea) */
/* WARNING: Removing unreachable block (ram,0x0823e6) */
/* WARNING: Removing unreachable block (ram,0x0823e2) */
/* WARNING: Removing unreachable block (ram,0x0823d8) */
/* WARNING: Removing unreachable block (ram,0x0823d0) */
/* WARNING: Removing unreachable block (ram,0x0823c8) */
/* WARNING: Removing unreachable block (ram,0x0823b6) */
/* WARNING: Removing unreachable block (ram,0x0823ae) */
/* WARNING: Removing unreachable block (ram,0x08239a) */
/* WARNING: Removing unreachable block (ram,0x082440) */
/* WARNING: Removing unreachable block (ram,0x08243c) */
/* WARNING: Removing unreachable block (ram,0x0823a6) */

void egs52_update_near_f57f_082392(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdee;
  if ((uVar1 & 1) != 0) {
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
    egs52_update_near_f594_082472();
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
    uRam00f5b2 = 0;
    uRam00f57e = 0;
    uVar1 = Ram00fde8;
    Ram00fde8 = uVar1 & 0xfffe;
    uRam00f5a0 = 0;
    egs52_update_near_f3e0_089fc6();
    return;
  }
  (*(code *)((uint3)uRam090098 << 0x10 | (uint3)uRam090096))();
  return;
}


