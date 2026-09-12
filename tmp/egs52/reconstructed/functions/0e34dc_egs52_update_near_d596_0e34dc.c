/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e34dc; FLS offset 0x0634dc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3516) */
/* WARNING: Removing unreachable block (ram,0x0e3512) */
/* WARNING: Removing unreachable block (ram,0x0e350e) */
/* WARNING: Removing unreachable block (ram,0x0e34f4) */
/* WARNING: Removing unreachable block (ram,0x0e34f2) */
/* WARNING: Removing unreachable block (ram,0x0e34e8) */
/* WARNING: Removing unreachable block (ram,0x0e34e6) */
/* WARNING: Removing unreachable block (ram,0x0e34de) */
/* WARNING: Removing unreachable block (ram,0x0e34fe) */

bool egs52_update_near_d596_0e34dc(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = Ram00f672;
  uVar2 = iVar3 + 8;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar4 = Ram00d508;
  if ((uVar4 <= *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) ||
     (uVar1 = Ram00fd60, (uVar1 & 8) != 0)) {
    uVar1 = 0x24;
    if (((uVar2 & 0xc000) != 0) &&
       ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
      uVar1 = 3;
    }
    uVar4 = Ram00d524;
    if ((uVar4 <= *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) ||
       (uVar1 = Ram00fd62, (uVar1 & 4) != 0)) {
      iVar3 = Ram00f672;
      uVar1 = iVar3 + 10;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      Ram00d596 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      return false;
    }
  }
  iVar3 = Ram00d596;
  return iVar3 == 0;
}


