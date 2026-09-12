/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e3494; FLS offset 0x063494.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e34c6) */
/* WARNING: Removing unreachable block (ram,0x0e34c4) */
/* WARNING: Removing unreachable block (ram,0x0e34ba) */
/* WARNING: Removing unreachable block (ram,0x0e34b8) */
/* WARNING: Removing unreachable block (ram,0x0e34b0) */
/* WARNING: Removing unreachable block (ram,0x0e34a2) */
/* WARNING: Removing unreachable block (ram,0x0e349e) */
/* WARNING: Removing unreachable block (ram,0x0e3496) */

undefined1 egs52_compute_from_near_fd26_0e3494(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = Ram00fd26;
  if ((uVar1 & 8) != 0) {
    iVar5 = Ram00f61e;
    uVar1 = iVar5 + 0x1d;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x80) != 0) {
      iVar5 = Ram00f672;
      uVar2 = iVar5 + 0x14;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar3 = Ram00d508;
      uVar4 = Ram00d508;
      if ((uVar1 == uVar4 || uVar1 < uVar3) || (uVar1 = Ram00fd60, (uVar1 & 8) != 0)) {
        uVar1 = 0x24;
        if (((uVar2 & 0xc000) != 0) &&
           ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000))
           )) {
          uVar1 = 3;
        }
        uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = Ram00d524;
        uVar3 = Ram00d524;
        if (uVar1 == uVar3 || uVar1 < uVar2) {
          return 1;
        }
        uVar1 = Ram00fd62;
        if ((uVar1 & 4) != 0) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}


