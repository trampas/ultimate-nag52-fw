/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4f28; FLS offset 0x024f28.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4f4e) */
/* WARNING: Removing unreachable block (ram,0x0a4f42) */
/* WARNING: Removing unreachable block (ram,0x0a4f3e) */
/* WARNING: Removing unreachable block (ram,0x0a4f38) */
/* WARNING: Removing unreachable block (ram,0x0a4f34) */
/* WARNING: Removing unreachable block (ram,0x0a4f30) */
/* WARNING: Removing unreachable block (ram,0x0a4f2c) */

undefined1 egs52_update_near_ccd4_0a4f28(byte param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  
  uVar2 = Ram00fdf2;
  uVar3 = Ram00fdf4;
  Ram00ccd4 = uVar2;
  Ram00ccd6 = uVar3;
  bVar4 = UNK_00c504;
  bVar1 = UNK_00c504;
  bVar1 = param_1 | bVar1 & 0x1b;
  UNK_00c504 = bVar1;
  bVar1 = (param_1 ^ bVar4) & bVar1;
  if ((bVar1 & 8) == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = 8;
  }
  if ((bVar1 & 0x10) != 0) {
    bVar4 = bVar4 | 0x10;
  }
  if (bVar4 != 0) {
    egs52_transform_memory_0a13e8(bVar4);
  }
  return 0;
}


