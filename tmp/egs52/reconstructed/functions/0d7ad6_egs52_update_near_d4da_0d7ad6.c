/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7ad6; FLS offset 0x057ad6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7b34) */
/* WARNING: Removing unreachable block (ram,0x0d7b30) */
/* WARNING: Removing unreachable block (ram,0x0d7b28) */
/* WARNING: Removing unreachable block (ram,0x0d7b26) */
/* WARNING: Removing unreachable block (ram,0x0d7b1a) */
/* WARNING: Removing unreachable block (ram,0x0d7b18) */
/* WARNING: Removing unreachable block (ram,0x0d7b10) */
/* WARNING: Removing unreachable block (ram,0x0d7b06) */
/* WARNING: Removing unreachable block (ram,0x0d7b00) */
/* WARNING: Removing unreachable block (ram,0x0d7af8) */
/* WARNING: Removing unreachable block (ram,0x0d7ae8) */
/* WARNING: Removing unreachable block (ram,0x0d7ae4) */
/* WARNING: Removing unreachable block (ram,0x0d7ade) */
/* WARNING: Removing unreachable block (ram,0x0d7ada) */
/* WARNING: Removing unreachable block (ram,0x0d7b0c) */
/* WARNING: Removing unreachable block (ram,0x0d7b20) */

void egs52_update_near_d4da_0d7ad6(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar2 = Ram00f63a;
  uVar6 = iVar2 + 0x4c;
  uVar1 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  bVar5 = UNK_00d4e1;
  uVar3 = Ram00d4d2;
  uVar6 = (uint)(((ulong)bVar5 * (ulong)uVar3) /
                (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)));
  Ram00d4da = uVar6;
  uVar1 = Ram00d4d2;
  uVar4 = Ram00d4d2;
  if (uVar6 == uVar4 || uVar6 < uVar1) {
    Ram00d4da = 0;
  }
  else {
    iVar2 = Ram00d4da;
    Ram00d4da = iVar2 - uVar3;
  }
  iVar2 = Ram00f63a;
  uVar1 = iVar2 + 0x18;
  uVar6 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  uVar3 = Ram00d4da;
  if (*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar3) {
    uVar6 = Ram00d4da;
  }
  else {
    uVar6 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar6 = *(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar1 = Ram00d4dc;
  if (uVar1 <= uVar6) {
    uVar6 = Ram00d4dc;
  }
  Ram00d4da = uVar6;
  return;
}


