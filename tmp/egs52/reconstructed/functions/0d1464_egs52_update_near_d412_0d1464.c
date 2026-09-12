/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1464; FLS offset 0x051464.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d148a) */
/* WARNING: Removing unreachable block (ram,0x0d1486) */
/* WARNING: Removing unreachable block (ram,0x0d1482) */
/* WARNING: Removing unreachable block (ram,0x0d147c) */
/* WARNING: Removing unreachable block (ram,0x0d1476) */
/* WARNING: Removing unreachable block (ram,0x0d1472) */
/* WARNING: Removing unreachable block (ram,0x0d146e) */
/* WARNING: Removing unreachable block (ram,0x0d1468) */
/* WARNING: Removing unreachable block (ram,0x0d1464) */

int egs52_update_near_d412_0d1464(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = Ram00d414;
  iVar3 = Ram00d412;
  if (iVar4 < iVar3) {
    Ram00d412 = iVar4;
  }
  iVar4 = Ram00f62c;
  uVar1 = iVar4 + 0x18;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar4 = Ram00d412;
  if (-*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar4) {
    Ram00d412 = 0;
  }
  iVar4 = Ram00d414;
  iVar3 = Ram00d412;
  iVar4 = iVar4 - iVar3;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  return iVar4;
}


