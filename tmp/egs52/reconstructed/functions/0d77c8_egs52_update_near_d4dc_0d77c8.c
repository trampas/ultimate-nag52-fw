/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d77c8; FLS offset 0x0577c8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d78f2) */
/* WARNING: Removing unreachable block (ram,0x0d78e0) */
/* WARNING: Removing unreachable block (ram,0x0d78d6) */
/* WARNING: Removing unreachable block (ram,0x0d78d2) */
/* WARNING: Removing unreachable block (ram,0x0d78c6) */
/* WARNING: Removing unreachable block (ram,0x0d78c2) */
/* WARNING: Removing unreachable block (ram,0x0d78ba) */
/* WARNING: Removing unreachable block (ram,0x0d78ac) */
/* WARNING: Removing unreachable block (ram,0x0d78a4) */
/* WARNING: Removing unreachable block (ram,0x0d7896) */
/* WARNING: Removing unreachable block (ram,0x0d7888) */
/* WARNING: Removing unreachable block (ram,0x0d7884) */
/* WARNING: Removing unreachable block (ram,0x0d7870) */
/* WARNING: Removing unreachable block (ram,0x0d7868) */
/* WARNING: Removing unreachable block (ram,0x0d7860) */
/* WARNING: Removing unreachable block (ram,0x0d785c) */
/* WARNING: Removing unreachable block (ram,0x0d7854) */
/* WARNING: Removing unreachable block (ram,0x0d783c) */
/* WARNING: Removing unreachable block (ram,0x0d7836) */
/* WARNING: Removing unreachable block (ram,0x0d7828) */
/* WARNING: Removing unreachable block (ram,0x0d7822) */
/* WARNING: Removing unreachable block (ram,0x0d7806) */
/* WARNING: Removing unreachable block (ram,0x0d7a40) */
/* WARNING: Removing unreachable block (ram,0x0d7a34) */
/* WARNING: Removing unreachable block (ram,0x0d7a30) */
/* WARNING: Removing unreachable block (ram,0x0d7a2c) */
/* WARNING: Removing unreachable block (ram,0x0d7a1c) */
/* WARNING: Removing unreachable block (ram,0x0d7a16) */
/* WARNING: Removing unreachable block (ram,0x0d7a0e) */
/* WARNING: Removing unreachable block (ram,0x0d79e4) */
/* WARNING: Removing unreachable block (ram,0x0d79d8) */
/* WARNING: Removing unreachable block (ram,0x0d79ce) */
/* WARNING: Removing unreachable block (ram,0x0d79c2) */
/* WARNING: Removing unreachable block (ram,0x0d79b6) */
/* WARNING: Removing unreachable block (ram,0x0d79b0) */
/* WARNING: Removing unreachable block (ram,0x0d79ac) */
/* WARNING: Removing unreachable block (ram,0x0d79a0) */
/* WARNING: Removing unreachable block (ram,0x0d7994) */
/* WARNING: Removing unreachable block (ram,0x0d798e) */
/* WARNING: Removing unreachable block (ram,0x0d798a) */
/* WARNING: Removing unreachable block (ram,0x0d7974) */
/* WARNING: Removing unreachable block (ram,0x0d7a06) */
/* WARNING: Removing unreachable block (ram,0x0d79fa) */
/* WARNING: Removing unreachable block (ram,0x0d79f4) */
/* WARNING: Removing unreachable block (ram,0x0d79f0) */
/* WARNING: Removing unreachable block (ram,0x0d796c) */
/* WARNING: Removing unreachable block (ram,0x0d7968) */
/* WARNING: Removing unreachable block (ram,0x0d795e) */
/* WARNING: Removing unreachable block (ram,0x0d7956) */
/* WARNING: Removing unreachable block (ram,0x0d7952) */
/* WARNING: Removing unreachable block (ram,0x0d793a) */
/* WARNING: Removing unreachable block (ram,0x0d7932) */
/* WARNING: Removing unreachable block (ram,0x0d7928) */
/* WARNING: Removing unreachable block (ram,0x0d791e) */
/* WARNING: Removing unreachable block (ram,0x0d790e) */
/* WARNING: Removing unreachable block (ram,0x0d77f4) */
/* WARNING: Removing unreachable block (ram,0x0d77e2) */
/* WARNING: Removing unreachable block (ram,0x0d77ce) */
/* WARNING: Removing unreachable block (ram,0x0d7902) */
/* WARNING: Removing unreachable block (ram,0x0d79d2) */
/* WARNING: Removing unreachable block (ram,0x0d7812) */
/* WARNING: Removing unreachable block (ram,0x0d7880) */
/* WARNING: Removing unreachable block (ram,0x0d78a8) */

void egs52_update_near_d4dc_0d77c8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  uchar x;
  uchar y;
  
  uVar1 = Ram00d500;
  uVar2 = Ram00d4d2;
  cVar5 = UNK_00d577;
  x = (uchar)(uVar1 / 0x1e);
  y = (uchar)(uVar2 / 5);
  if (cVar5 == '\x01') {
    bVar9 = UNK_00d579;
    iVar10 = Ram00f642;
    iVar4 = Ram00f642;
    bVar6 = UNK_00d579;
    bVar7 = UNK_00d579;
    iVar8 = Ram00f642;
    bVar9 = egs52_map_u8('\x06','\b',(uchar *)(iVar4 + -6 + (uint)bVar6 * 6),
                         (uchar *)(iVar8 + (uint)bVar7 * 8 + 0x10),
                         (uchar *)(iVar10 + (uint)bVar9 * 0x30 + 8),x,y);
    Ram00d4dc = (uint)bVar9 * 5;
    uVar1 = Ram00fd4c;
    if ((uVar1 & 0x20) == 0) {
      iVar10 = Ram00f61e;
      uVar1 = iVar10 + 0x1d;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) &&
         (cVar5 = UNK_00d60e, cVar5 == '\x03')) {
        cVar5 = UNK_00d7aa;
        if (cVar5 == '\0') {
          uVar3 = Ram00d4dc;
          iVar10 = Ram00f63a;
          uVar1 = iVar10 + 0x5c;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          Ram00d4dc = (int)(((ulong)uVar3 *
                            (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
        }
        else if (cVar5 == '\x02') {
          uVar3 = Ram00d4dc;
          iVar10 = Ram00f63a;
          uVar1 = iVar10 + 0x5d;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          Ram00d4dc = (int)(((ulong)uVar3 *
                            (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
        }
      }
    }
    iVar10 = Ram00d4dc;
    iVar4 = Ram00d47e;
    iVar10 = iVar10 - iVar4;
    if (iVar10 < 1) {
      iVar10 = 0;
    }
    Ram00d4dc = iVar10;
    iVar4 = Ram00d4d0;
    if (-1 < iVar4) {
      return;
    }
    iVar4 = Ram00d4d2;
    iVar10 = iVar10 + iVar4 * -2;
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    Ram00d4dc = iVar10;
    return;
  }
  bVar9 = UNK_00d579;
  iVar10 = Ram00f642;
  bVar6 = UNK_00d579;
  iVar4 = Ram00f642;
  bVar7 = UNK_00d579;
  iVar8 = Ram00f642;
  bVar9 = egs52_map_u8('\x03','\x04',(uchar *)(iVar4 + (uint)bVar6 * 3 + 0xe9),
                       (uchar *)(iVar8 + (uint)bVar7 * 4 + 0xf0),
                       (uchar *)(iVar10 + (uint)bVar9 * 0xc + 0xd8),x,y);
  Ram00d4dc = (uint)bVar9 * 5;
  uVar1 = Ram00fd4c;
  if ((uVar1 & 0x20) != 0) {
    cVar5 = UNK_00d60e;
    if (cVar5 == '\x03') {
      iVar10 = Ram00f61e;
      uVar1 = iVar10 + 0x1d;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) {
        cVar5 = UNK_00d7aa;
        if (cVar5 == '\x01') {
          iVar10 = Ram00f63a;
          uVar1 = iVar10 + 0x6a;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = Ram00d4dc;
          Ram00d4dc = (int)(((ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                            (ulong)uVar3) / 10);
        }
        else if (cVar5 == '\0') {
          iVar10 = Ram00f63a;
          uVar1 = iVar10 + 0x38;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = Ram00d4dc;
          Ram00d4dc = (int)(((ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                            (ulong)uVar3) / 10);
        }
        else if (cVar5 == '\x02') {
          iVar10 = Ram00f63a;
          uVar1 = iVar10 + 0x5e;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = Ram00d4dc;
          Ram00d4dc = (int)(((ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                            (ulong)uVar3) / 10);
        }
        goto LAB_0d7a0e;
      }
    }
    iVar10 = Ram00f63a;
    uVar1 = iVar10 + 0x38;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = Ram00d4dc;
    Ram00d4dc = (int)(((ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                      (ulong)uVar3) / 10);
  }
LAB_0d7a0e:
  iVar10 = Ram00d4d0;
  if (0 < iVar10) {
    iVar4 = Ram00d4d2;
    iVar10 = Ram00d4dc;
    iVar10 = iVar10 + iVar4 * -2;
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    Ram00d4dc = iVar10;
  }
  iVar10 = Ram00d4dc;
  iVar4 = Ram00d47e;
  iVar10 = iVar10 + iVar4;
  if (iVar10 < 1) {
    iVar10 = 0;
  }
  Ram00d4dc = iVar10;
  return;
}


