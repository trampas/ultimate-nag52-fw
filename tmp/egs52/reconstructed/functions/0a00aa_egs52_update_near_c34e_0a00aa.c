/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a00aa; FLS offset 0x0200aa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a00c0) */
/* WARNING: Removing unreachable block (ram,0x0a00aa) */

void egs52_update_near_c34e_0a00aa(void)

{
  uint uVar1;
  
  uVar1 = Ram00c34e;
  if ((uVar1 & 1) != 0) {
    egs52_update_near_f186_0a5f28();
    uVar1 = egs52_compute_from_near_cda2_0a5f9c();
    if ((uVar1 & 2) != 0) {
      uVar1 = Ram00c34e;
      Ram00c34e = uVar1 | 2;
    }
  }
  return;
}


