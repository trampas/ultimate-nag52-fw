/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e4db0; FLS offset 0x064db0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4e26) */
/* WARNING: Removing unreachable block (ram,0x0e4e12) */
/* WARNING: Removing unreachable block (ram,0x0e4e0e) */
/* WARNING: Removing unreachable block (ram,0x0e4e0a) */
/* WARNING: Removing unreachable block (ram,0x0e4dd4) */
/* WARNING: Removing unreachable block (ram,0x0e4e02) */
/* WARNING: Removing unreachable block (ram,0x0e4df6) */
/* WARNING: Removing unreachable block (ram,0x0e4df2) */
/* WARNING: Removing unreachable block (ram,0x0e4dc8) */
/* WARNING: Removing unreachable block (ram,0x0e4dbc) */
/* WARNING: Removing unreachable block (ram,0x0e4db8) */
/* WARNING: Removing unreachable block (ram,0x0e4db4) */
/* WARNING: Removing unreachable block (ram,0x0e4db0) */
/* WARNING: Removing unreachable block (ram,0x0e4dee) */
/* WARNING: Removing unreachable block (ram,0x0e4de0) */

void egs52_update_near_d462_0e4db0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = Ram00f61e;
  uVar1 = iVar4 + 0x1e;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar3 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  Ram00d462 = uVar3;
  uVar1 = iVar4 + 0x1d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) != 0) {
    uVar1 = Ram00fd54;
    if ((uVar1 & 0x40) == 0) {
      uVar3 = Ram00d462;
      iVar4 = Ram00f61e;
      uVar1 = iVar4 + 0x20;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d462 = (int)(((ulong)uVar3 *
                        (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 1000);
    }
    else {
      uVar1 = iVar4 + 0x22;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d462 = (int)(((ulong)uVar3 *
                        (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 1000);
    }
  }
  iVar4 = Ram00f61e;
  uVar1 = iVar4 + 0x24;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar3 = Ram00d462;
  Ram00d4e2 = (int)(((ulong)uVar3 * 0xa7) /
                   (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
  return;
}


