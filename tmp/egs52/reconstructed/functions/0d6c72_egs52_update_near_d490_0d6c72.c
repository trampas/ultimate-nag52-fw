/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6c72; FLS offset 0x056c72.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6c90) */
/* WARNING: Removing unreachable block (ram,0x0d6c8c) */
/* WARNING: Removing unreachable block (ram,0x0d6c82) */
/* WARNING: Removing unreachable block (ram,0x0d6c7e) */
/* WARNING: Removing unreachable block (ram,0x0d6c7a) */
/* WARNING: Removing unreachable block (ram,0x0d6c76) */
/* WARNING: Removing unreachable block (ram,0x0d6c72) */

void egs52_update_near_d490_0d6c72(void)

{
  uint uVar1;
  undefined2 uVar2;
  
  Ram00d490 = 0;
  Ram00d4ae = 0;
  Ram00d4ac = 0;
  Ram00d4aa = 0;
  UNK_00d59b = 0;
  uVar1 = Ram00fd4c;
  Ram00fd4c = uVar1 & 0xfffe;
  uVar1 = Ram00fd34;
  Ram00fd34 = uVar1 & 0xffbf;
  uVar1 = Ram00fd34;
  Ram00fd34 = uVar1 & 0xff7f;
  uVar2 = Ram00d4d0;
  Ram00d4ca = uVar2;
  return;
}


