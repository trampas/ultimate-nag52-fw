/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08836c; FLS offset 0x00836c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08838c) */
/* WARNING: Removing unreachable block (ram,0x088388) */
/* WARNING: Removing unreachable block (ram,0x088378) */
/* WARNING: Removing unreachable block (ram,0x0883de) */
/* WARNING: Removing unreachable block (ram,0x0883ba) */
/* WARNING: Removing unreachable block (ram,0x0883b2) */
/* WARNING: Removing unreachable block (ram,0x0883d4) */
/* WARNING: Removing unreachable block (ram,0x0883d0) */
/* WARNING: Removing unreachable block (ram,0x0883c8) */
/* WARNING: Removing unreachable block (ram,0x0883c4) */
/* WARNING: Removing unreachable block (ram,0x0883a2) */
/* WARNING: Removing unreachable block (ram,0x088380) */

void egs52_boot_service_20(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdea;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) == 0)) {
    uRam00f57c = 0x19;
    uRam00f574 = 0x1f5;
    uRam00f57a = 0x47;
    Ram00feb4 = 0x47;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 & 0xfff7;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 & 0xffef;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfffb;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfff7;
    return;
  }
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xfffb;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xfff7;
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 & 0xffdf;
  uRam00f580 = 1;
  egs52_update_near_f57f_088f1e();
  uVar1 = Ram00fde8;
  if ((uVar1 & 1) == 0) {
    uRam00f57c = 0;
    uRam00f578 = 0;
    uRam00f576 = 0xfffd;
    uRam00f574 = 0;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 & 0xfff7;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 & 0xffef;
    uVar1 = Ram00fdec;
    Ram00fdec = uVar1 & 0xf7ff;
  }
  else {
    uRam00f578 = 0x37;
    uRam00f576 = 5000;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 4;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfff7;
  }
  uRam00f581 = 0;
  return;
}


