/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1eac; FLS offset 0x051eac.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1f3c) */
/* WARNING: Removing unreachable block (ram,0x0d1f36) */
/* WARNING: Removing unreachable block (ram,0x0d1f2a) */
/* WARNING: Removing unreachable block (ram,0x0d1f22) */
/* WARNING: Removing unreachable block (ram,0x0d1f10) */
/* WARNING: Removing unreachable block (ram,0x0d1f0a) */
/* WARNING: Removing unreachable block (ram,0x0d1f00) */
/* WARNING: Removing unreachable block (ram,0x0d1ef0) */
/* WARNING: Removing unreachable block (ram,0x0d1eec) */
/* WARNING: Removing unreachable block (ram,0x0d1ee6) */
/* WARNING: Removing unreachable block (ram,0x0d1ede) */
/* WARNING: Removing unreachable block (ram,0x0d1ed8) */
/* WARNING: Removing unreachable block (ram,0x0d1ed4) */
/* WARNING: Removing unreachable block (ram,0x0d1ece) */
/* WARNING: Removing unreachable block (ram,0x0d1ec8) */
/* WARNING: Removing unreachable block (ram,0x0d1eb6) */
/* WARNING: Removing unreachable block (ram,0x0d1eae) */
/* WARNING: Removing unreachable block (ram,0x0d1f48) */
/* WARNING: Removing unreachable block (ram,0x0d1ee2) */

void egs52_update_near_fd4e_0d1eac(void)

{
  uint uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  int iStack_2;
  
  uVar1 = Ram00fd4e;
  if ((uVar1 & 1) != 0) {
    cVar10 = UNK_00d577;
    if (((cVar10 == '\x03') && (uVar1 = Ram00fd4a, (uVar1 & 1) == 0)) &&
       (uVar1 = Ram00fd4a, (uVar1 & 4) == 0)) {
      bVar3 = UNK_00d579;
      iVar4 = Ram00f624;
      uVar1 = iVar4 + (uint)bVar3 * 2 + 0x84;
      uVar11 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar11 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      uVar8 = Ram00d4d2;
      if (*(uint *)((uint3)uVar11 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar8) {
        bVar3 = UNK_00d437;
        if (3 < bVar3) {
          uVar1 = Ram00fd4e;
          Ram00fd4e = uVar1 & 0xfffe;
        }
      }
      else {
        iVar5 = Ram00d47c;
        iVar6 = Ram00d4ac;
        iVar7 = Ram00d4b2;
        bVar3 = UNK_00d4e1;
        iVar4 = Ram00d46a;
        iVar9 = Ram00d546;
        uVar1 = (int)(((long)((iVar5 + iVar6) - iVar7) * (long)iVar4) / (long)(int)(uint)bVar3) +
                iVar9;
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
        uVar2 = Ram00d556;
        uVar11 = egs52_compute_from_near_f626_0d7c4e(cVar10 + -1,uVar2,iStack_2);
        uVar1 = Ram00d56a;
        if ((uVar1 <= uVar11) || (bVar3 = UNK_00d437, 2 < bVar3)) {
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
  uVar2 = Ram00fd4e;
  uVar1 = Ram00fd4e;
  uVar11 = Ram00fd4e;
  Ram00fd4e = uVar11 & 0xfffd | (uVar1 & 1) << 1;
  return;
}


