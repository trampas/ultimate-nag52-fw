/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09de7a; FLS offset 0x01de7a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Removing unreachable block (ram,0x09def0) */
/* WARNING: Removing unreachable block (ram,0x09dec0) */
/* WARNING: Removing unreachable block (ram,0x09deec) */
/* WARNING: Removing unreachable block (ram,0x09dee6) */
/* WARNING: Removing unreachable block (ram,0x09df04) */
/* WARNING: Removing unreachable block (ram,0x09debc) */
/* WARNING: Removing unreachable block (ram,0x09df10) */
/* WARNING: Removing unreachable block (ram,0x09dee4) */
/* WARNING: Removing unreachable block (ram,0x09df3a) */
/* WARNING: Removing unreachable block (ram,0x09df30) */
/* WARNING: Removing unreachable block (ram,0x09dea8) */
/* WARNING: Removing unreachable block (ram,0x09de92) */
/* WARNING: Removing unreachable block (ram,0x09de8a) */
/* WARNING: Removing unreachable block (ram,0x09de82) */
/* WARNING: Removing unreachable block (ram,0x09df4c) */
/* WARNING: Removing unreachable block (ram,0x09df14) */
/* WARNING: Removing unreachable block (ram,0x09df32) */
/* WARNING: Removing unreachable block (ram,0x09defe) */

void egs52_update_near_c32b_09de7a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  undefined2 uVar6;
  char cVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  bVar4 = UNK_00c32a;
  if ((bVar4 & 1) != 0) {
    UNK_00c32b = 0xff;
    bVar4 = UNK_00c32a;
    UNK_00c32a = bVar4 & 0xfd;
    iVar11 = 0;
    uVar10 = 0;
    while( true ) {
      uVar9 = iVar11 * 4 + 0x784;
      uVar2 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) == 0) break;
      uVar2 = iVar11 * 4 + 0x782;
      uVar9 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      uVar9 = *(uint *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff));
      for (; bVar4 = UNK_00c32c, uVar10 < bVar4; uVar10 = uVar10 + 1) {
        uVar5 = Ram00f682;
        uVar6 = Ram00f684;
        uVar3 = (uint)((ulong)uVar10 * 0xc);
        cVar8 = (char)uVar6 + (0xfffb < uVar5) + (char)((ulong)uVar10 * 0xc >> 0x10) +
                CARRY2(uVar5 + 4,uVar3);
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if ((*(int *)CONCAT12(cVar8,iVar11 * 4 + 0x784) -
            (uVar9 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)))) - 10 <=
            *(uint *)CONCAT12(cVar8,uVar5 + 4 + uVar3)) break;
        if ((uVar9 & 1) != 0) {
          uVar9 = uVar9 + 1;
        }
        uVar3 = Ram00f682;
        uVar6 = Ram00f684;
        uVar1 = (uint)((ulong)uVar10 * 0xc);
        cVar8 = (char)((ulong)uVar10 * 0xc >> 0x10);
        cVar7 = (char)uVar6 + (0xfff7 < uVar3) + cVar8 + CARRY2(uVar3 + 8,uVar1);
        *(uint *)CONCAT12(cVar7,*(undefined2 *)CONCAT12(cVar7,uVar3 + 8 + uVar1)) = uVar9;
        uVar3 = Ram00f682;
        uVar6 = Ram00f684;
        uVar9 = uVar9 + *(int *)CONCAT12((char)uVar6 + (0xfffb < uVar3) + cVar8 +
                                         CARRY2(uVar3 + 4,uVar1),uVar3 + 4 + uVar1);
      }
      iVar11 = iVar11 + 1;
    }
  }
  return;
}


