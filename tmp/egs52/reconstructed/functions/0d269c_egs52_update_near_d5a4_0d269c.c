/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d269c; FLS offset 0x05269c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d2808) */
/* WARNING: Removing unreachable block (ram,0x0d281c) */
/* WARNING: Removing unreachable block (ram,0x0d2816) */
/* WARNING: Removing unreachable block (ram,0x0d27ea) */
/* WARNING: Removing unreachable block (ram,0x0d27e6) */
/* WARNING: Removing unreachable block (ram,0x0d27de) */
/* WARNING: Removing unreachable block (ram,0x0d27ce) */
/* WARNING: Removing unreachable block (ram,0x0d2824) */
/* WARNING: Removing unreachable block (ram,0x0d27c8) */
/* WARNING: Removing unreachable block (ram,0x0d27c4) */
/* WARNING: Removing unreachable block (ram,0x0d27c0) */
/* WARNING: Removing unreachable block (ram,0x0d27bc) */
/* WARNING: Removing unreachable block (ram,0x0d27b0) */
/* WARNING: Removing unreachable block (ram,0x0d27a6) */
/* WARNING: Removing unreachable block (ram,0x0d279a) */
/* WARNING: Removing unreachable block (ram,0x0d2790) */
/* WARNING: Removing unreachable block (ram,0x0d278a) */
/* WARNING: Removing unreachable block (ram,0x0d2786) */
/* WARNING: Removing unreachable block (ram,0x0d2782) */
/* WARNING: Removing unreachable block (ram,0x0d277c) */
/* WARNING: Removing unreachable block (ram,0x0d276e) */
/* WARNING: Removing unreachable block (ram,0x0d2766) */
/* WARNING: Removing unreachable block (ram,0x0d2762) */
/* WARNING: Removing unreachable block (ram,0x0d2752) */
/* WARNING: Removing unreachable block (ram,0x0d2746) */
/* WARNING: Removing unreachable block (ram,0x0d273a) */
/* WARNING: Removing unreachable block (ram,0x0d2730) */
/* WARNING: Removing unreachable block (ram,0x0d2800) */
/* WARNING: Removing unreachable block (ram,0x0d27f8) */
/* WARNING: Removing unreachable block (ram,0x0d27f4) */
/* WARNING: Removing unreachable block (ram,0x0d2728) */
/* WARNING: Removing unreachable block (ram,0x0d2724) */
/* WARNING: Removing unreachable block (ram,0x0d271c) */
/* WARNING: Removing unreachable block (ram,0x0d2710) */
/* WARNING: Removing unreachable block (ram,0x0d270a) */
/* WARNING: Removing unreachable block (ram,0x0d2706) */
/* WARNING: Removing unreachable block (ram,0x0d2700) */
/* WARNING: Removing unreachable block (ram,0x0d26fc) */
/* WARNING: Removing unreachable block (ram,0x0d26f8) */
/* WARNING: Removing unreachable block (ram,0x0d26f0) */
/* WARNING: Removing unreachable block (ram,0x0d26ec) */
/* WARNING: Removing unreachable block (ram,0x0d26c6) */
/* WARNING: Removing unreachable block (ram,0x0d26b4) */
/* WARNING: Removing unreachable block (ram,0x0d26ae) */
/* WARNING: Removing unreachable block (ram,0x0d26aa) */
/* WARNING: Removing unreachable block (ram,0x0d26a2) */
/* WARNING: Removing unreachable block (ram,0x0d26d2) */
/* WARNING: Removing unreachable block (ram,0x0d26f4) */
/* WARNING: Removing unreachable block (ram,0x0d2718) */
/* WARNING: Removing unreachable block (ram,0x0d27fc) */
/* WARNING: Removing unreachable block (ram,0x0d276a) */
/* WARNING: Removing unreachable block (ram,0x0d2776) */
/* WARNING: Removing unreachable block (ram,0x0d27d8) */
/* WARNING: Removing unreachable block (ram,0x0d2812) */
/* WARNING: Removing unreachable block (ram,0x0d280c) */

void egs52_update_near_d5a4_0d269c(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  char cVar5;
  int iVar6;
  ushort old;
  ushort uVar7;
  
  egs52_clamp_d488_when_fd4e_bit5_set();
  uVar1 = Ram00fd4e;
  if ((uVar1 & 0x20) == 0) {
    iVar6 = Ram00f638;
    uVar1 = iVar6 + 0x23;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar3 = UNK_00d579;
    if ((((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1 << (bVar3 - 1 & 0xf))
         == 0) || (uVar1 = Ram00fd4a, (uVar1 & 4) == 0)) {
      uVar1 = Ram00fd4e;
      Ram00fd4e = uVar1 & 0xffdf;
      UNK_00d565 = 0;
      return;
    }
  }
  cVar5 = UNK_00d565;
  if (cVar5 == '\0') {
    cVar5 = UNK_00d565;
    UNK_00d565 = cVar5 + '\x01';
    iVar6 = Ram00f638;
    uVar1 = iVar6 + 0x20;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5a4 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar4 = Ram00d496;
    Ram00d480 = uVar4;
    uVar1 = Ram00fd4e;
    Ram00fd4e = uVar1 | 0x20;
  }
  else if (cVar5 != '\x01') {
    if (cVar5 == '\x02') {
      bVar3 = UNK_00d579;
      iVar6 = Ram00f638;
      uVar1 = iVar6 + (uint)bVar3 * 2 + 0x22;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d480 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      cVar5 = UNK_00d5a4;
      if (((cVar5 == '\0') ||
          ((bVar3 = UNK_00d437, 10 < bVar3 &&
           ((cVar5 = UNK_00d577, cVar5 == '\x03' || (cVar5 == '\x02')))))) ||
         ((bVar3 = UNK_00d437, 8 < bVar3 &&
          ((cVar5 = UNK_00d577, cVar5 == '\x04' || (cVar5 == '\x01')))))) {
        cVar5 = UNK_00d565;
        UNK_00d565 = cVar5 + '\x01';
        iVar6 = Ram00f638;
        uVar1 = iVar6 + 0x22;
        uVar2 = 0x24;
        if (((uVar1 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))
           )) {
          uVar2 = 3;
        }
        UNK_00d5a4 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
    }
    else if (cVar5 == '\x03') {
      uVar7 = Ram00d488;
      if ((int)uVar7 < 0) {
        uVar7 = 0;
      }
      old = Ram00d480;
      bVar3 = UNK_00d5a4;
      uVar7 = egs52_ramp_u16(old,uVar7,(uint)bVar3);
      Ram00d480 = uVar7;
      cVar5 = UNK_00d5a4;
      if (cVar5 == '\0') {
        uVar1 = Ram00fd4e;
        Ram00fd4e = uVar1 & 0xffdf;
      }
    }
    goto LAB_0d2804;
  }
  uVar7 = Ram00d480;
  bVar3 = UNK_00d579;
  iVar6 = Ram00f638;
  uVar1 = iVar6 + (uint)bVar3 * 2 + 0x22;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar3 = UNK_00d5a4;
  uVar7 = egs52_ramp_u16(uVar7,*(ushort *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),
                         (uint)bVar3);
  Ram00d480 = uVar7;
  cVar5 = UNK_00d5a4;
  if (cVar5 == '\0') {
    cVar5 = UNK_00d565;
    UNK_00d565 = cVar5 + '\x01';
    iVar6 = Ram00f638;
    uVar1 = iVar6 + 0x21;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5a4 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  else {
    bVar3 = UNK_00d437;
    if (((10 < bVar3) && ((cVar5 = UNK_00d577, cVar5 == '\x03' || (cVar5 == '\x02')))) ||
       ((bVar3 = UNK_00d437, 8 < bVar3 &&
        ((cVar5 = UNK_00d577, cVar5 == '\x04' || (cVar5 == '\x01')))))) {
      cVar5 = UNK_00d565;
      UNK_00d565 = cVar5 + '\x02';
      iVar6 = Ram00f638;
      uVar1 = iVar6 + 0x22;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      UNK_00d5a4 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
LAB_0d2804:
  uVar1 = Ram00fd4e;
  if ((uVar1 & 8) == 0) {
    uVar4 = Ram00d480;
    Ram00d4b8 = uVar4;
  }
  else {
    uVar1 = Ram00d480;
    uVar2 = Ram00d4b8;
    if (uVar1 < uVar2) {
      Ram00d4b8 = uVar1;
    }
  }
  return;
}


