/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09629a; FLS offset 0x01629a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096322) */
/* WARNING: Removing unreachable block (ram,0x096314) */
/* WARNING: Removing unreachable block (ram,0x09630a) */
/* WARNING: Removing unreachable block (ram,0x0962f2) */
/* WARNING: Removing unreachable block (ram,0x0962e4) */
/* WARNING: Removing unreachable block (ram,0x0962da) */
/* WARNING: Removing unreachable block (ram,0x0962c4) */
/* WARNING: Removing unreachable block (ram,0x0962b4) */
/* WARNING: Removing unreachable block (ram,0x0962ac) */
/* WARNING: Removing unreachable block (ram,0x0962a6) */
/* WARNING: Removing unreachable block (ram,0x0962a2) */
/* WARNING: Removing unreachable block (ram,0x09629e) */

void egs52_update_near_d3da_09629a(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar3 = Ram00fd26;
  Ram00fd26 = uVar3 & 0xfffd;
  uVar3 = 0x24;
  if ((((uRam0904e0 & 0xc000) != 0) && (uVar3 = 0x21, (uRam0904e0 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uRam0904e0 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar1 = Ram00fd26;
  Ram00fd26 = uVar1 | (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uRam0904e0 & 0x3fff)) & 1) << 1;
  uVar3 = Ram00fd26;
  Ram00fd26 = uVar3 & 0xfffb;
  uVar3 = Ram00ffc0;
  uVar3 = uVar3 >> 0xc & 1 ^ 1;
  __write_psw_bits(0x40,uVar3 << 6);
  uVar1 = Ram00fd26;
  Ram00fd26 = uVar1 | uVar3 << 2;
  uVar2 = egs52_update_near_fd00_096f56(9,0);
  uVar3 = egs52_compute_from_near_c3a2_09f510(uVar2,uRam083f28,uRam083f2a);
  Ram00d3da = uVar3 / 10;
  uVar2 = egs52_update_near_fd00_096f56(0);
  uVar3 = egs52_compute_from_near_c3a2_09f510(uVar2,uRam083f2c,uRam083f2e);
  Ram00d3de = uVar3 / 10;
  egs52_update_near_d3e2_09653c();
  return;
}


