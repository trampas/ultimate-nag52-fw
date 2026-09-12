/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7ffa; FLS offset 0x057ffa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8074) */
/* WARNING: Removing unreachable block (ram,0x0d806e) */
/* WARNING: Removing unreachable block (ram,0x0d806a) */
/* WARNING: Removing unreachable block (ram,0x0d8056) */
/* WARNING: Removing unreachable block (ram,0x0d8052) */
/* WARNING: Removing unreachable block (ram,0x0d804c) */
/* WARNING: Removing unreachable block (ram,0x0d8048) */
/* WARNING: Removing unreachable block (ram,0x0d802e) */
/* WARNING: Removing unreachable block (ram,0x0d8024) */
/* WARNING: Removing unreachable block (ram,0x0d8018) */
/* WARNING: Removing unreachable block (ram,0x0d8014) */
/* WARNING: Removing unreachable block (ram,0x0d8010) */
/* WARNING: Removing unreachable block (ram,0x0d8006) */
/* WARNING: Removing unreachable block (ram,0x0d8002) */

void egs52_compute_from_near_d54a_0d7ffa(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = Ram00d54a;
  uVar5 = Ram00d536;
  uVar3 = Ram00d536;
  if (uVar2 == uVar3 || uVar2 < uVar5) {
    iVar7 = 0;
  }
  else {
    iVar7 = Ram00f634;
    uVar5 = iVar7 + 8;
    uVar3 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar6 = Ram00d556;
    uVar1 = iVar7 + 8;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    iVar7 = Ram00d536;
    iVar7 = (int)(((ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) * (ulong)uVar6) /
                 1000) +
            (int)(((ulong)(1000 - *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) *
                  (ulong)(uVar2 - iVar7)) / 1000);
  }
  iVar8 = Ram00f63a;
  uVar2 = iVar8 + 0x4c;
  uVar5 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  uVar4 = Ram00d49c;
  uVar1 = Ram00d46a;
  uVar3 = (uint)((ulong)uVar4 * (ulong)uVar1 >> 0x10);
  iVar8 = Ram00d546;
  uVar2 = (int)(((ulong)uVar4 * (ulong)uVar1 & 0xffff | (ulong)uVar3 << 0x10) /
               (ulong)*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff))) + iVar8;
  uVar5 = Ram00d532;
  uVar1 = Ram00d532;
  if (uVar2 == uVar1 || uVar2 < uVar5) {
    iVar8 = 0;
  }
  else {
    iVar8 = Ram00d532;
    iVar8 = uVar2 - iVar8;
  }
  egs52_compute_from_near_f626_0d7c4e(param_1,iVar7,iVar8,uVar3);
  return;
}


