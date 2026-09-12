/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d33ec; FLS offset 0x0533ec.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d3418) */
/* WARNING: Removing unreachable block (ram,0x0d3414) */
/* WARNING: Removing unreachable block (ram,0x0d3410) */
/* WARNING: Removing unreachable block (ram,0x0d340a) */
/* WARNING: Removing unreachable block (ram,0x0d3406) */
/* WARNING: Removing unreachable block (ram,0x0d3400) */
/* WARNING: Removing unreachable block (ram,0x0d33fc) */
/* WARNING: Removing unreachable block (ram,0x0d33f8) */
/* WARNING: Removing unreachable block (ram,0x0d33f4) */
/* WARNING: Removing unreachable block (ram,0x0d33f0) */
/* WARNING: Removing unreachable block (ram,0x0d33ec) */

void egs52_update_near_d5f6_0d33ec(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = Ram00f648;
  uVar1 = iVar3 + 0x24;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f6 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x26;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5f8 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x1f;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d5fa = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar3 + 0x20;
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


