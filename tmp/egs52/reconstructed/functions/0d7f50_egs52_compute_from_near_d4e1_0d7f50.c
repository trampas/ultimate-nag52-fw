/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7f50; FLS offset 0x057f50.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7fce) */
/* WARNING: Removing unreachable block (ram,0x0d7fc4) */
/* WARNING: Removing unreachable block (ram,0x0d7fba) */
/* WARNING: Removing unreachable block (ram,0x0d7fb4) */
/* WARNING: Removing unreachable block (ram,0x0d7fb0) */
/* WARNING: Removing unreachable block (ram,0x0d7fac) */
/* WARNING: Removing unreachable block (ram,0x0d7fa6) */
/* WARNING: Removing unreachable block (ram,0x0d7f96) */
/* WARNING: Removing unreachable block (ram,0x0d7f90) */
/* WARNING: Removing unreachable block (ram,0x0d7f8a) */
/* WARNING: Removing unreachable block (ram,0x0d7f80) */
/* WARNING: Removing unreachable block (ram,0x0d7f7a) */
/* WARNING: Removing unreachable block (ram,0x0d7f76) */
/* WARNING: Removing unreachable block (ram,0x0d7f62) */
/* WARNING: Removing unreachable block (ram,0x0d7f5e) */
/* WARNING: Removing unreachable block (ram,0x0d7f5a) */

void egs52_compute_from_near_d4e1_0d7f50(byte param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  
  bVar2 = UNK_00d4e1;
  uVar7 = Ram00d46e;
  uVar6 = Ram00d4d2;
  iVar3 = Ram00d54a;
  uVar7 = (int)(((ulong)uVar7 * (ulong)uVar6) / (ulong)bVar2) + iVar3;
  uVar6 = Ram00d536;
  uVar1 = Ram00d536;
  if (uVar7 == uVar1 || uVar7 < uVar6) {
    uVar7 = 0;
  }
  else {
    iVar3 = Ram00d536;
    uVar7 = uVar7 - iVar3;
  }
  iVar3 = Ram00d54a;
  uVar6 = param_2 + iVar3;
  uVar1 = Ram00d536;
  uVar4 = Ram00d536;
  if (uVar6 == uVar4 || uVar6 < uVar1) {
    uVar6 = 0;
  }
  else {
    iVar3 = Ram00d536;
    uVar6 = uVar6 - iVar3;
  }
  if (uVar7 < uVar6) {
    uVar7 = uVar6;
  }
  uVar6 = Ram00d552;
  uVar1 = Ram00d552;
  if (uVar7 != uVar1 && uVar6 <= uVar7) {
    uVar7 = Ram00d552;
  }
  uVar4 = Ram00d546;
  uVar6 = Ram00d532;
  uVar1 = Ram00d532;
  if (uVar4 == uVar1 || uVar4 < uVar6) {
    uVar8 = 0;
  }
  else {
    iVar3 = Ram00d532;
    iVar5 = Ram00f63a;
    uVar1 = iVar5 + 4 + (uint)param_1;
    uVar6 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar8 = (undefined2)
            (((ulong)(uVar4 - iVar3) *
             (ulong)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
  }
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar7,uVar8);
  return;
}


