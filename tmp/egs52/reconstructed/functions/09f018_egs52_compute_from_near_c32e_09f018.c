/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f018; FLS offset 0x01f018.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f050) */
/* WARNING: Removing unreachable block (ram,0x09f048) */
/* WARNING: Removing unreachable block (ram,0x09f044) */
/* WARNING: Removing unreachable block (ram,0x09f03e) */
/* WARNING: Removing unreachable block (ram,0x09f020) */
/* WARNING: Removing unreachable block (ram,0x09f01c) */

undefined1 egs52_compute_from_near_c32e_09f018(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined1 uVar6;
  char cVar7;
  
  uVar2 = Ram00f682;
  uVar4 = Ram00f684;
  uVar3 = (param_1 & 0xff) * 0xc;
  iVar1 = uVar2 + 6 + uVar3;
  cVar7 = (char)uVar4 + (0xfff9 < uVar2) + CARRY2(uVar2 + 6,uVar3);
  if (*(char *)CONCAT12(cVar7,iVar1) == '\0') {
    uVar6 = 0;
  }
  else {
    iVar5 = Ram00c32e;
    uVar2 = iVar5 + -1 + (uint)*(byte *)CONCAT12(cVar7,iVar1);
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar6 = *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  return uVar6;
}


