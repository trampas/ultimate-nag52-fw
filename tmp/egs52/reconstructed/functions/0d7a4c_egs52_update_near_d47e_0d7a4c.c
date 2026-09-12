/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7a4c; FLS offset 0x057a4c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7abc) */
/* WARNING: Removing unreachable block (ram,0x0d7ace) */
/* WARNING: Removing unreachable block (ram,0x0d7ab4) */
/* WARNING: Removing unreachable block (ram,0x0d7aac) */
/* WARNING: Removing unreachable block (ram,0x0d7aa0) */
/* WARNING: Removing unreachable block (ram,0x0d7a9c) */
/* WARNING: Removing unreachable block (ram,0x0d7a98) */
/* WARNING: Removing unreachable block (ram,0x0d7a90) */
/* WARNING: Removing unreachable block (ram,0x0d7a88) */
/* WARNING: Removing unreachable block (ram,0x0d7a80) */
/* WARNING: Removing unreachable block (ram,0x0d7a6a) */
/* WARNING: Removing unreachable block (ram,0x0d7a64) */
/* WARNING: Removing unreachable block (ram,0x0d7a5e) */
/* WARNING: Removing unreachable block (ram,0x0d7a4e) */
/* WARNING: Removing unreachable block (ram,0x0d7ac8) */
/* WARNING: Removing unreachable block (ram,0x0d7ac2) */

void egs52_update_near_d47e_0d7a4c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  
  iVar4 = Ram00d47e;
  bVar7 = egs52_lookup_and_offset_d467();
  bVar5 = UNK_00d454;
  iVar3 = Ram00f624;
  uVar1 = iVar3 + (uint)bVar5 * 2 + 6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = (int)(((ulong)bVar7 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
               1000) * 6;
  Ram00d47e = uVar1;
  uVar2 = Ram00d462;
  iVar3 = (int)(((ulong)uVar1 * (ulong)uVar2) / 10000);
  Ram00d47e = iVar3;
  iVar6 = Ram00f61e;
  uVar1 = iVar6 + 0x24;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar6 = Ram00d710;
  Ram00d47e = (int)(((long)iVar3 * (long)iVar6) /
                   (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
  uVar1 = Ram00fd48;
  if ((uVar1 & 0x10) == 0) {
    iVar3 = Ram00d47e;
    iVar6 = Ram00d47e;
    if (iVar4 == iVar6 || iVar4 < iVar3) {
      Ram00d47e = iVar4;
    }
  }
  else {
    iVar3 = Ram00d47e;
    if (iVar3 <= iVar4) {
      Ram00d47e = iVar4;
    }
  }
  return;
}


