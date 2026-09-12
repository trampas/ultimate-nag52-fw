/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d714e; FLS offset 0x05714e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d717e) */
/* WARNING: Removing unreachable block (ram,0x0d717a) */
/* WARNING: Removing unreachable block (ram,0x0d7176) */
/* WARNING: Removing unreachable block (ram,0x0d7170) */
/* WARNING: Removing unreachable block (ram,0x0d716c) */
/* WARNING: Removing unreachable block (ram,0x0d7166) */
/* WARNING: Removing unreachable block (ram,0x0d7162) */
/* WARNING: Removing unreachable block (ram,0x0d715c) */
/* WARNING: Removing unreachable block (ram,0x0d7158) */
/* WARNING: Removing unreachable block (ram,0x0d7152) */
/* WARNING: Removing unreachable block (ram,0x0d714e) */

void egs52_update_near_d5f6_0d714e(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = Ram00f63a;
  uVar1 = iVar3 + 0x2c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x2d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x45;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x46;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fc = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar4 = UNK_00d5cc;
  Ram00d5fe = (uint)bVar4;
  egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  return;
}


