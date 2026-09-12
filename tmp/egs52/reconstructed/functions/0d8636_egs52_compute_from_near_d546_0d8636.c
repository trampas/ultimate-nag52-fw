/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8636; FLS offset 0x058636.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8660) */
/* WARNING: Removing unreachable block (ram,0x0d8656) */
/* WARNING: Removing unreachable block (ram,0x0d864a) */
/* WARNING: Removing unreachable block (ram,0x0d8644) */
/* WARNING: Removing unreachable block (ram,0x0d8640) */

void egs52_compute_from_near_d546_0d8636(byte param_1,undefined2 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  
  uVar4 = Ram00d546;
  uVar1 = Ram00d532;
  if (uVar4 < uVar1) {
    uVar7 = 0;
  }
  else {
    iVar5 = Ram00d532;
    iVar6 = Ram00f63a;
    uVar2 = iVar6 + 4 + (uint)param_1;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = (ulong)(uVar4 - iVar5) * (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))
    ;
    param_3 = (uint)(uVar3 >> 0x10);
    uVar7 = (undefined2)((uVar3 & 0xffff | (ulong)param_3 << 0x10) / 100);
  }
  egs52_compute_from_near_f626_0d7c4e(param_1,param_2,uVar7,param_3);
  return;
}


