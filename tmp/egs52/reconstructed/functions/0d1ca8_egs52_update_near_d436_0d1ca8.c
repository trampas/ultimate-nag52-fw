/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1ca8; FLS offset 0x051ca8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1d88) */
/* WARNING: Removing unreachable block (ram,0x0d1d84) */
/* WARNING: Removing unreachable block (ram,0x0d1d80) */
/* WARNING: Removing unreachable block (ram,0x0d1d78) */
/* WARNING: Removing unreachable block (ram,0x0d1cf8) */
/* WARNING: Removing unreachable block (ram,0x0d1cec) */
/* WARNING: Removing unreachable block (ram,0x0d1ce0) */
/* WARNING: Removing unreachable block (ram,0x0d1d48) */
/* WARNING: Removing unreachable block (ram,0x0d1d3c) */
/* WARNING: Removing unreachable block (ram,0x0d1d38) */
/* WARNING: Removing unreachable block (ram,0x0d1d32) */
/* WARNING: Removing unreachable block (ram,0x0d1d2e) */
/* WARNING: Removing unreachable block (ram,0x0d1d26) */
/* WARNING: Removing unreachable block (ram,0x0d1d20) */
/* WARNING: Removing unreachable block (ram,0x0d1d18) */
/* WARNING: Removing unreachable block (ram,0x0d1d14) */
/* WARNING: Removing unreachable block (ram,0x0d1d10) */
/* WARNING: Removing unreachable block (ram,0x0d1d08) */
/* WARNING: Removing unreachable block (ram,0x0d1d70) */
/* WARNING: Removing unreachable block (ram,0x0d1d68) */
/* WARNING: Removing unreachable block (ram,0x0d1d64) */
/* WARNING: Removing unreachable block (ram,0x0d1d60) */
/* WARNING: Removing unreachable block (ram,0x0d1d58) */
/* WARNING: Removing unreachable block (ram,0x0d1d4e) */
/* WARNING: Removing unreachable block (ram,0x0d1cd8) */
/* WARNING: Removing unreachable block (ram,0x0d1cce) */
/* WARNING: Removing unreachable block (ram,0x0d1cc4) */
/* WARNING: Removing unreachable block (ram,0x0d1cb0) */
/* WARNING: Removing unreachable block (ram,0x0d1cac) */
/* WARNING: Removing unreachable block (ram,0x0d1ca8) */
/* WARNING: Removing unreachable block (ram,0x0d1d00) */
/* WARNING: Removing unreachable block (ram,0x0d1ce4) */

void egs52_update_near_d436_0d1ca8(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  
  uVar1 = Ram00f638;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar3 = UNK_00d579;
  if (((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1 << (bVar3 - 1 & 0xf)) == 0
     ) {
    uVar1 = Ram00fd4e;
    Ram00fd4e = uVar1 & 0xfffe;
  }
  else {
    uVar2 = Ram00fd4e;
    if ((((uVar2 & 1) == 0) && (cVar5 = UNK_00d577, cVar5 == '\x01')) &&
       (iVar4 = Ram00d4c2, -1 < iVar4)) {
      cVar5 = UNK_00d437;
      if (cVar5 == '\x02') {
        uVar1 = uVar1 + 0x15;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        bVar6 = UNK_00d5b0;
        bVar7 = UNK_00d5b0;
        if ((bVar3 != bVar7 && bVar6 <= bVar3) && (cVar5 = UNK_00d566, cVar5 == '\x01')) {
          uVar1 = Ram00fd4e;
          Ram00fd4e = uVar1 | 1;
          UNK_00d436 = 0;
        }
      }
      else {
        cVar5 = UNK_00d437;
        if (cVar5 == '\x03') {
          bVar3 = UNK_00d566;
          if (bVar3 < 2) {
            iVar4 = Ram00f634;
            uVar1 = iVar4 + 0x20;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            iVar4 = Ram00d414;
            if (iVar4 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
              cVar5 = UNK_00d566;
              if (cVar5 == '\x01') {
                bVar3 = UNK_00d432;
                bVar6 = UNK_00d5b0;
                iVar4 = Ram00f638;
                uVar1 = iVar4 + 0xc;
                uVar2 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                if ((int)(uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) <=
                    (int)((uint)bVar3 - (uint)bVar6)) {
                  uVar1 = Ram00fd4e;
                  Ram00fd4e = uVar1 | 1;
                  UNK_00d436 = 0;
                }
              }
              goto LAB_0d1d78;
            }
          }
          uVar1 = Ram00fd4e;
          Ram00fd4e = uVar1 | 1;
          UNK_00d436 = 0;
        }
        else {
          cVar5 = UNK_00d437;
          if (cVar5 == '\b') {
            cVar5 = UNK_00d566;
            if (cVar5 != '\x02') {
              iVar4 = Ram00f634;
              uVar1 = iVar4 + 0x20;
              uVar2 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              iVar4 = Ram00d414;
              if (iVar4 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) goto LAB_0d1d78;
            }
            uVar1 = Ram00fd4e;
            Ram00fd4e = uVar1 | 1;
            UNK_00d436 = 0;
          }
        }
      }
    }
  }
LAB_0d1d78:
  uVar1 = Ram00fd4e;
  if ((uVar1 & 1) != 0) {
    iVar4 = Ram00f638;
    uVar1 = iVar4 + 0x16;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar3 = UNK_00d570;
    if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < bVar3) {
      uVar1 = Ram00fd4e;
      Ram00fd4e = uVar1 | 2;
    }
  }
  return;
}


