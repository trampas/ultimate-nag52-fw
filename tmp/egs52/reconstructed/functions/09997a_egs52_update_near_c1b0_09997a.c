/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09997a; FLS offset 0x01997a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0999a8) */
/* WARNING: Removing unreachable block (ram,0x09999e) */
/* WARNING: Removing unreachable block (ram,0x09999a) */
/* WARNING: Removing unreachable block (ram,0x099996) */
/* WARNING: Removing unreachable block (ram,0x099990) */
/* WARNING: Removing unreachable block (ram,0x09998a) */
/* WARNING: Removing unreachable block (ram,0x099986) */
/* WARNING: Removing unreachable block (ram,0x09997e) */
/* WARNING: Removing unreachable block (ram,0x09997a) */

void egs52_update_near_c1b0_09997a(void)

{
  undefined1 uVar1;
  
  uVar1 = UNK_00c1af;
  UNK_00c1b0 = uVar1;
  UNK_00c1af = 0x7f;
  UNK_00c2b0 = 0;
  UNK_00c2b1 = 1;
  UNK_00c1ad = 3;
  UNK_00c2b2 = 3;
  UNK_00c2b3 = 0xff;
  egs52_update_near_d2d3_09bf7a(3);
  UNK_00c2af = 0;
  return;
}


