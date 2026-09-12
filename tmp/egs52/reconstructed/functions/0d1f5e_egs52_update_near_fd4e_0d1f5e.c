/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1f5e; FLS offset 0x051f5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1fe6) */
/* WARNING: Removing unreachable block (ram,0x0d1fe0) */
/* WARNING: Removing unreachable block (ram,0x0d1fd4) */
/* WARNING: Removing unreachable block (ram,0x0d1fcc) */
/* WARNING: Removing unreachable block (ram,0x0d1fba) */
/* WARNING: Removing unreachable block (ram,0x0d1fb4) */
/* WARNING: Removing unreachable block (ram,0x0d1faa) */
/* WARNING: Removing unreachable block (ram,0x0d1f9a) */
/* WARNING: Removing unreachable block (ram,0x0d1f96) */
/* WARNING: Removing unreachable block (ram,0x0d1f90) */
/* WARNING: Removing unreachable block (ram,0x0d1f88) */
/* WARNING: Removing unreachable block (ram,0x0d1f82) */
/* WARNING: Removing unreachable block (ram,0x0d1f7e) */
/* WARNING: Removing unreachable block (ram,0x0d1f78) */
/* WARNING: Removing unreachable block (ram,0x0d1f72) */
/* WARNING: Removing unreachable block (ram,0x0d1f68) */
/* WARNING: Removing unreachable block (ram,0x0d1f60) */
/* WARNING: Removing unreachable block (ram,0x0d1ff4) */
/* WARNING: Removing unreachable block (ram,0x0d1f8c) */

void egs52_update_near_fd4e_0d1f5e(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  char cVar10;
  uint uVar11;
  int iStack_2;
  
  uVar1 = Ram00fd4e;
  if ((uVar1 & 1) != 0) {
    cVar10 = UNK_00d577;
    if (cVar10 == '\x03') {
      bVar2 = UNK_00d579;
      iVar3 = Ram00f624;
      uVar1 = iVar3 + (uint)bVar2 * 2 + 0x84;
      uVar11 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      uVar7 = Ram00d4d2;
      if (*(uint *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar7) {
        bVar2 = UNK_00d437;
        if (0xb < bVar2) {
          uVar1 = Ram00fd4e;
          Ram00fd4e = uVar1 & 0xfffe;
        }
      }
      else {
        iVar4 = Ram00d47c;
        iVar5 = Ram00d4ac;
        iVar6 = Ram00d4b2;
        bVar2 = UNK_00d4e1;
        iVar3 = Ram00d46a;
        iVar8 = Ram00d546;
        uVar1 = (int)(((long)((iVar4 + iVar5) - iVar6) * (long)iVar3) / (long)(int)(uint)bVar2) +
                iVar8;
        if ((int)uVar1 < 1) {
          iStack_2 = 0;
        }
        else {
          uVar11 = Ram00d532;
          if (uVar1 < uVar11) {
            iStack_2 = 0;
          }
          else {
            iStack_2 = Ram00d532;
            iStack_2 = uVar1 - iStack_2;
          }
        }
        cVar10 = UNK_00d579;
        uVar9 = Ram00d556;
        uVar11 = egs52_compute_from_near_f626_0d7c4e(cVar10 + -1,uVar9,iStack_2);
        uVar1 = Ram00d56a;
        if ((uVar1 <= uVar11) || (bVar2 = UNK_00d437, 10 < bVar2)) {
          uVar1 = Ram00fd4e;
          Ram00fd4e = uVar1 & 0xfffe;
        }
      }
    }
    else {
      uVar1 = Ram00fd4e;
      Ram00fd4e = uVar1 & 0xfffe;
    }
  }
  return;
}


