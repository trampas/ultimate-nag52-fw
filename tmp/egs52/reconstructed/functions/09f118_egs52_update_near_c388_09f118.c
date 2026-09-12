/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f118; FLS offset 0x01f118.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f348) */
/* WARNING: Removing unreachable block (ram,0x09f340) */
/* WARNING: Removing unreachable block (ram,0x09f2ee) */
/* WARNING: Removing unreachable block (ram,0x09f2a8) */
/* WARNING: Removing unreachable block (ram,0x09f2a4) */
/* WARNING: Removing unreachable block (ram,0x09f278) */
/* WARNING: Removing unreachable block (ram,0x09f21c) */
/* WARNING: Removing unreachable block (ram,0x09f1d8) */
/* WARNING: Removing unreachable block (ram,0x09f1d4) */
/* WARNING: Removing unreachable block (ram,0x09f1aa) */
/* WARNING: Removing unreachable block (ram,0x09f156) */
/* WARNING: Removing unreachable block (ram,0x09f152) */
/* WARNING: Removing unreachable block (ram,0x09f12c) */
/* WARNING: Removing unreachable block (ram,0x09f128) */

void egs52_update_near_c388_09f118(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  bool bVar7;
  char cVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  uVar1 = uRam0904e2 + 4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar6 = (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 1000;
  uVar1 = (uint)(uVar6 >> 0x10);
  uVar2 = (uint)((uVar6 & 0xffff | (ulong)uVar1 << 0x10) / 0x59c);
  iVar10 = egs52_update_near_fd00_096f56(10,0,uVar1);
  uVar1 = 0x24;
  if ((((uRam0904e2 & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904e2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam0904e2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar1 = (uint)(((ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uRam0904e2 & 0x3fff)) * 1000) /
                0x59c);
  iVar11 = egs52_update_near_fd00_096f56(9,0);
  uVar12 = egs52_update_near_c170_097904();
  if (((uVar12 & 0x100) == 0) || (uVar12 = egs52_update_near_c170_097904(), (uVar12 & 0x200) == 0))
  {
    egs52_update_fault_status(7,0);
    egs52_update_fault_status(6,0);
    goto LAB_09f340;
  }
  uVar12 = egs52_compute_from_near_c189_0981ca(1);
  iVar13 = Ram00c38a;
  iVar13 = uVar2 - iVar13;
  if (iVar13 < 0) {
    iVar13 = -iVar13;
  }
  uVar14 = uVar2 - iVar10;
  if ((int)uVar14 < 0) {
    uVar14 = -uVar14;
  }
  if (6 < iVar13) {
    UNK_00c388 = (char)((int)uVar14 / 6) + '\x01';
  }
  cVar8 = UNK_00c388;
  if (cVar8 == '\0') {
    if (0x2fd < uVar2) {
      uVar3 = uVar2 - 0x2b8;
      uVar4 = (uint)(uVar2 < 0x2b8);
      if ((int)(uint)(uVar3 < 0x8b) <= (int)-uVar4) {
        iVar10 = (int)uVar14 >> 0xf;
        uVar5 = (uint)(uVar14 < uVar3);
        if (iVar10 + uVar4 == uVar5 && uVar14 == uVar3 ||
            (int)((iVar10 + uVar4) - uVar5) < 0 !=
            (SBORROW2(iVar10,-uVar4) != SBORROW2(iVar10 + uVar4,(uint)(uVar14 < uVar3)))) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        goto LAB_09f220;
      }
    }
    if ((int)uVar14 < 0x8c) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
  }
  else {
    bVar7 = false;
    cVar8 = UNK_00c388;
    UNK_00c388 = cVar8 + -1;
  }
LAB_09f220:
  if ((bVar7) || ((uVar12 & 0xff) >> 6 != 3)) {
    egs52_update_fault_status(7,3);
  }
  else {
    bVar9 = egs52_compute_from_near_f03c_097116(2);
    if ((bVar9 < 0x19) || (bVar9 = egs52_compute_from_near_f03c_097116(2), 0x4b < bVar9)) {
      egs52_update_fault_status(7,0);
    }
    else {
      egs52_update_fault_status(7,2);
    }
  }
  uVar12 = egs52_compute_from_near_c189_0981ca(1);
  iVar10 = Ram00c38c;
  iVar10 = uVar1 - iVar10;
  if (iVar10 < 0) {
    iVar10 = -iVar10;
  }
  uVar14 = uVar1 - iVar11;
  if ((int)uVar14 < 0) {
    uVar14 = -uVar14;
  }
  if (6 < iVar10) {
    UNK_00c389 = (char)((int)uVar14 / 6) + '\x01';
  }
  cVar8 = UNK_00c389;
  if (cVar8 == '\0') {
    if (0x2fd < uVar1) {
      uVar3 = uVar1 - 0x2b8;
      uVar4 = (uint)(uVar1 < 0x2b8);
      if ((int)(uint)(uVar3 < 0x8b) <= (int)-uVar4) {
        iVar10 = (int)uVar14 >> 0xf;
        uVar5 = (uint)(uVar14 < uVar3);
        if (iVar10 + uVar4 == uVar5 && uVar14 == uVar3 ||
            (int)((iVar10 + uVar4) - uVar5) < 0 !=
            (SBORROW2(iVar10,-uVar4) != SBORROW2(iVar10 + uVar4,(uint)(uVar14 < uVar3)))) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        goto LAB_09f2f2;
      }
    }
    if ((int)uVar14 < 0x8c) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
  }
  else {
    bVar7 = false;
    cVar8 = UNK_00c389;
    UNK_00c389 = cVar8 + -1;
  }
LAB_09f2f2:
  if ((bVar7) || (((uVar12 & 0xff) >> 4 & 3) != 3)) {
    egs52_update_fault_status(6,3);
  }
  else {
    bVar9 = egs52_compute_from_near_f03c_097116(3);
    if ((bVar9 < 0x19) || (bVar9 = egs52_compute_from_near_f03c_097116(3), 0x4b < bVar9)) {
      egs52_update_fault_status(6,0);
    }
    else {
      egs52_update_fault_status(6,2);
    }
  }
LAB_09f340:
  Ram00c38a = uVar2;
  Ram00c38c = uVar1;
  return;
}


