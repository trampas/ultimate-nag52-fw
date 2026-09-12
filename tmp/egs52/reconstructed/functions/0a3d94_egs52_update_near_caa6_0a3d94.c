/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3d94; FLS offset 0x023d94.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3d9e) */
/* WARNING: Removing unreachable block (ram,0x0a3df0) */
/* WARNING: Removing unreachable block (ram,0x0a3df6) */
/* WARNING: Removing unreachable block (ram,0x0a3dec) */
/* WARNING: Removing unreachable block (ram,0x0a3dd0) */
/* WARNING: Removing unreachable block (ram,0x0a3dc4) */
/* WARNING: Removing unreachable block (ram,0x0a3d94) */
/* WARNING: Removing unreachable block (ram,0x0a3dba) */
/* WARNING: Removing unreachable block (ram,0x0a3de0) */
/* WARNING: Removing unreachable block (ram,0x0a3db2) */
/* WARNING: Removing unreachable block (ram,0x0a3e00) */

undefined2 egs52_update_near_caa6_0a3d94(void)

{
  uint uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  
  uVar1 = Ram00caa6;
  if (0xffe < uVar1) {
    uVar2 = Ram00caa8;
    cVar3 = egs52_update_near_caa4_0a3d02(uVar2,0,0);
    if (cVar3 == '\x03') {
      Ram00caa6 = 0;
      return 2;
    }
    return 1;
  }
  cVar3 = UNK_00caa4;
  if (cVar3 == '\0') {
    UNK_00caa4 = 1;
    do {
      uVar2 = Ram00caa6;
      iVar4 = egs52_update_near_c166_097172(0xf856,uVar2,0x20,0,0);
      Ram00caa8 = iVar4;
      if (iVar4 != 0) {
        iVar4 = Ram00caa6;
        Ram00caa6 = iVar4 + 0x20;
      }
      iVar4 = Ram00caa8;
    } while ((iVar4 != 0) && (uVar1 = Ram00caa6, uVar1 < 0xfff));
    UNK_00caa4 = 0;
    return 1;
  }
  return 1;
}


