/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0de11a; FLS offset 0x05e11a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0de1de) */
/* WARNING: Removing unreachable block (ram,0x0de1d6) */
/* WARNING: Removing unreachable block (ram,0x0de1d0) */
/* WARNING: Removing unreachable block (ram,0x0de1ca) */
/* WARNING: Removing unreachable block (ram,0x0de1c6) */
/* WARNING: Removing unreachable block (ram,0x0de1c2) */
/* WARNING: Removing unreachable block (ram,0x0de1be) */
/* WARNING: Removing unreachable block (ram,0x0de1a8) */
/* WARNING: Removing unreachable block (ram,0x0de1a2) */
/* WARNING: Removing unreachable block (ram,0x0de194) */
/* WARNING: Removing unreachable block (ram,0x0de190) */
/* WARNING: Removing unreachable block (ram,0x0de18c) */
/* WARNING: Removing unreachable block (ram,0x0de17e) */
/* WARNING: Removing unreachable block (ram,0x0de170) */
/* WARNING: Removing unreachable block (ram,0x0de16c) */
/* WARNING: Removing unreachable block (ram,0x0de160) */
/* WARNING: Removing unreachable block (ram,0x0de15a) */
/* WARNING: Removing unreachable block (ram,0x0de152) */
/* WARNING: Removing unreachable block (ram,0x0de14c) */
/* WARNING: Removing unreachable block (ram,0x0de148) */
/* WARNING: Removing unreachable block (ram,0x0de140) */
/* WARNING: Removing unreachable block (ram,0x0de12a) */
/* WARNING: Removing unreachable block (ram,0x0de124) */
/* WARNING: Removing unreachable block (ram,0x0de120) */
/* WARNING: Removing unreachable block (ram,0x0de11a) */

void egs52_update_near_d5a6_0de11a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  char cVar10;
  
  cVar6 = UNK_00d577;
  if (cVar6 == '\0') {
    cVar10 = UNK_00d777;
    cVar6 = UNK_00d454;
    if (cVar10 != cVar6) goto LAB_0de12a;
  }
  else {
LAB_0de12a:
    cVar6 = UNK_00d577;
    if ((cVar6 != '\x06') && (cVar6 != '\b')) {
      uVar1 = Ram00fd2e;
      if ((uVar1 & 4) == 0) {
        bVar8 = UNK_00d777;
        bVar5 = UNK_00d454;
        bVar7 = UNK_00d454;
        if (((bVar8 == bVar7 || bVar8 < bVar5) && (uVar1 = Ram00fd48, (uVar1 & 8) == 0)) &&
           (bVar5 = UNK_00d613, bVar8 < bVar5)) {
          uVar1 = Ram00fd4a;
          if ((uVar1 & 0x20) != 0) {
            iVar9 = Ram00f634;
            uVar1 = iVar9 + 0x34;
            uVar3 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            bVar5 = UNK_00d570;
            if ((uint)(((ulong)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) * 0xf) / 10)
                <= (uint)bVar5) goto LAB_0de186;
          }
          iVar9 = Ram00f634;
          uVar1 = iVar9 + 0x34;
          uVar3 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          bVar5 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
          bVar7 = UNK_00d570;
          bVar8 = UNK_00d570;
          if ((((bVar5 != bVar8 && bVar7 <= bVar5) && (uVar1 = Ram00fd4a, (uVar1 & 0x40) == 0)) &&
              (uVar1 = Ram00fd4a, (uVar1 & 0x20) == 0)) && (cVar6 = UNK_00d437, cVar6 == '\0')) {
            cVar6 = UNK_00d777;
            if ((cVar6 == '\x03') || (cVar6 == '\x04')) {
              uVar1 = Ram00fd4a;
              Ram00fd4a = uVar1 & 0xffbf;
              uVar1 = Ram00fd4a;
              Ram00fd4a = uVar1 | 0x20;
            }
            else {
              uVar1 = Ram00fd4a;
              Ram00fd4a = uVar1 | 0x40;
              uVar1 = Ram00fd4a;
              Ram00fd4a = uVar1 & 0xffdf;
              iVar9 = Ram00f63a;
              uVar1 = iVar9 + 0x40;
              uVar3 = 0x24;
              if (((uVar1 & 0xc000) != 0) &&
                 ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 &&
                  (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
                uVar3 = 3;
              }
              uVar2 = iVar9 + 0x3e;
              uVar4 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              iVar9 = Ram00d5a6;
              Ram00d5a6 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) -
                          (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) - iVar9);
            }
          }
          goto LAB_0de1d4;
        }
      }
LAB_0de186:
      uVar1 = Ram00fd4a;
      Ram00fd4a = uVar1 & 0xffbf;
      uVar1 = Ram00fd4a;
      Ram00fd4a = uVar1 & 0xffdf;
      goto LAB_0de1d4;
    }
  }
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xffbf;
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xffdf;
LAB_0de1d4:
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 & 0xff7f;
  uVar1 = Ram00fd4a;
  if (((uVar1 & 0x40) != 0) && ((cVar6 = UNK_00d579, cVar6 == '\x05' || (cVar6 == '\x06')))) {
    uVar1 = Ram00fd4a;
    Ram00fd4a = uVar1 | 0x80;
  }
  return;
}


