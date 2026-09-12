/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7efc; FLS offset 0x057efc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7f32) */
/* WARNING: Removing unreachable block (ram,0x0d7f2c) */
/* WARNING: Removing unreachable block (ram,0x0d7f28) */
/* WARNING: Removing unreachable block (ram,0x0d7f14) */
/* WARNING: Removing unreachable block (ram,0x0d7f10) */
/* WARNING: Removing unreachable block (ram,0x0d7f0a) */
/* WARNING: Removing unreachable block (ram,0x0d7f06) */

void egs52_compute_from_near_f63a_0d7efc(undefined1 param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = Ram00f63a;
  uVar1 = iVar6 + 0x4c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar5 = Ram00d49c;
  uVar4 = Ram00d46a;
  uVar3 = (uint)((ulong)uVar5 * (ulong)uVar4 >> 0x10);
  iVar6 = Ram00d546;
  uVar1 = (int)(((ulong)uVar5 * (ulong)uVar4 & 0xffff | (ulong)uVar3 << 0x10) /
               (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) + iVar6;
  uVar2 = Ram00d532;
  uVar4 = Ram00d532;
  if (uVar1 == uVar4 || uVar1 < uVar2) {
    iVar6 = 0;
  }
  else {
    iVar6 = Ram00d532;
    iVar6 = uVar1 - iVar6;
  }
  egs52_compute_from_near_f626_0d7c4e(param_1,param_2,iVar6,uVar3);
  return;
}


