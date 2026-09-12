/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9be4; FLS offset 0x059be4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9d92) */
/* WARNING: Removing unreachable block (ram,0x0d9d78) */
/* WARNING: Removing unreachable block (ram,0x0d9d74) */
/* WARNING: Removing unreachable block (ram,0x0d9d66) */
/* WARNING: Removing unreachable block (ram,0x0d9d5a) */
/* WARNING: Removing unreachable block (ram,0x0d9d56) */
/* WARNING: Removing unreachable block (ram,0x0d9d52) */
/* WARNING: Removing unreachable block (ram,0x0d9d4e) */
/* WARNING: Removing unreachable block (ram,0x0d9d4a) */
/* WARNING: Removing unreachable block (ram,0x0d9d44) */
/* WARNING: Removing unreachable block (ram,0x0d9d3c) */
/* WARNING: Removing unreachable block (ram,0x0d9d38) */
/* WARNING: Removing unreachable block (ram,0x0d9d2c) */
/* WARNING: Removing unreachable block (ram,0x0d9d24) */
/* WARNING: Removing unreachable block (ram,0x0d9d1e) */
/* WARNING: Removing unreachable block (ram,0x0d9d18) */
/* WARNING: Removing unreachable block (ram,0x0d9d14) */
/* WARNING: Removing unreachable block (ram,0x0d9d0e) */
/* WARNING: Removing unreachable block (ram,0x0d9d0c) */
/* WARNING: Removing unreachable block (ram,0x0d9d04) */
/* WARNING: Removing unreachable block (ram,0x0d9cfc) */
/* WARNING: Removing unreachable block (ram,0x0d9cf4) */
/* WARNING: Removing unreachable block (ram,0x0d9cf0) */
/* WARNING: Removing unreachable block (ram,0x0d9cec) */
/* WARNING: Removing unreachable block (ram,0x0d9ce8) */
/* WARNING: Removing unreachable block (ram,0x0d9ce4) */
/* WARNING: Removing unreachable block (ram,0x0d9cdc) */
/* WARNING: Removing unreachable block (ram,0x0d9cd4) */
/* WARNING: Removing unreachable block (ram,0x0d9ccc) */
/* WARNING: Removing unreachable block (ram,0x0d9cc8) */
/* WARNING: Removing unreachable block (ram,0x0d9cc0) */
/* WARNING: Removing unreachable block (ram,0x0d9c8e) */
/* WARNING: Removing unreachable block (ram,0x0d9c82) */
/* WARNING: Removing unreachable block (ram,0x0d9c7e) */
/* WARNING: Removing unreachable block (ram,0x0d9c7a) */
/* WARNING: Removing unreachable block (ram,0x0d9c74) */
/* WARNING: Removing unreachable block (ram,0x0d9c70) */
/* WARNING: Removing unreachable block (ram,0x0d9c6a) */
/* WARNING: Removing unreachable block (ram,0x0d9c66) */
/* WARNING: Removing unreachable block (ram,0x0d9c60) */
/* WARNING: Removing unreachable block (ram,0x0d9c56) */
/* WARNING: Removing unreachable block (ram,0x0d9c52) */
/* WARNING: Removing unreachable block (ram,0x0d9cae) */
/* WARNING: Removing unreachable block (ram,0x0d9caa) */
/* WARNING: Removing unreachable block (ram,0x0d9cbc) */
/* WARNING: Removing unreachable block (ram,0x0d9cb8) */
/* WARNING: Removing unreachable block (ram,0x0d9cb4) */
/* WARNING: Removing unreachable block (ram,0x0d9ca4) */
/* WARNING: Removing unreachable block (ram,0x0d9ca0) */
/* WARNING: Removing unreachable block (ram,0x0d9c9c) */
/* WARNING: Removing unreachable block (ram,0x0d9c4a) */
/* WARNING: Removing unreachable block (ram,0x0d9c34) */
/* WARNING: Removing unreachable block (ram,0x0d9c30) */
/* WARNING: Removing unreachable block (ram,0x0d9c46) */
/* WARNING: Removing unreachable block (ram,0x0d9c42) */
/* WARNING: Removing unreachable block (ram,0x0d9c18) */
/* WARNING: Removing unreachable block (ram,0x0d9c10) */
/* WARNING: Removing unreachable block (ram,0x0d9bfe) */
/* WARNING: Removing unreachable block (ram,0x0d9bf4) */
/* WARNING: Removing unreachable block (ram,0x0d9bea) */
/* WARNING: Removing unreachable block (ram,0x0d9c3e) */
/* WARNING: Removing unreachable block (ram,0x0d9c38) */
/* WARNING: Removing unreachable block (ram,0x0d9c94) */
/* WARNING: Removing unreachable block (ram,0x0d9c5c) */
/* WARNING: Removing unreachable block (ram,0x0d9dc0) */

void egs52_update_near_d5a6_0d9be4(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  ushort target;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  
  cVar2 = UNK_00d579;
  bVar12 = cVar2 - 1;
  egs52_update_near_d490_0d7666();
  uVar3 = UNK_00d577;
  uVar8 = egs52_update_near_d426_0d4338(uVar3);
  uVar3 = UNK_00d577;
  uVar8 = egs52_compute_from_near_d579_0d42a6(uVar3,uVar8);
  target = egs52_compute_from_near_d54a_0d7e30(uVar8);
  cVar2 = UNK_00d5b2;
  if (cVar2 != '\0') {
    return;
  }
  cVar2 = UNK_00d566;
  if (cVar2 == '\0') {
    egs52_update_near_d579_0d6c96();
    uVar10 = Ram00fd4a;
    if ((uVar10 & 0x40) == 0) {
      iVar7 = Ram00f63a;
      uVar10 = iVar7 + 0x3e;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5a6 = *(undefined2 *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
    }
    else {
      iVar7 = Ram00f63a;
      uVar10 = iVar7 + 0x40;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5a6 = *(undefined2 *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
    }
    cVar2 = UNK_00d577;
    if (cVar2 == '\x03') {
      iVar7 = Ram00f63a;
      uVar10 = iVar7 + 0x43;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5f6 = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
      uVar10 = iVar7 + 0x42;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5f8 = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
      uVar10 = iVar7 + 0x47;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5fa = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
      uVar10 = iVar7 + 0x48;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      Ram00d5fc = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
      bVar12 = UNK_00d5cc;
      Ram00d5fe = (uint)bVar12;
      uVar9 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
      UNK_00d5b0 = (char)uVar9;
    }
    else {
      cVar2 = UNK_00d704;
      if (cVar2 == '\x03') {
        iVar7 = Ram00f63a;
        uVar10 = iVar7 + 0x60;
        uVar11 = 0x24;
        if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
           (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
          uVar11 = 3;
        }
        iVar1 = *(int *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
        iVar5 = Ram00d7a6;
        iVar6 = Ram00d7a6;
        if (iVar1 != iVar6 && iVar5 <= iVar1) {
          uVar10 = iVar7 + 0x44;
          uVar11 = 0x24;
          if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
             (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
            uVar11 = 3;
          }
          UNK_00d5b0 = *(undefined1 *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
          goto LAB_0d9cc0;
        }
      }
      iVar7 = Ram00f63a;
      uVar10 = iVar7 + 0x43;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
    }
LAB_0d9cc0:
    cVar2 = UNK_00d60e;
    if (cVar2 == '\x03') {
      iVar7 = Ram00f61e;
      uVar10 = iVar7 + 0x1d;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      if ((((*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff)) & 0x40) != 0) &&
          (cVar2 = UNK_00d7aa, cVar2 == '\x01')) && (cVar2 = UNK_00d577, cVar2 == '\x01')) {
        iVar7 = Ram00f63a;
        uVar10 = iVar7 + 0x6b;
        uVar11 = 0x24;
        if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
           (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
          uVar11 = 3;
        }
        cVar2 = UNK_00d5b0;
        UNK_00d5b0 = cVar2 + *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
      }
    }
    cVar2 = UNK_00d566;
    UNK_00d566 = cVar2 + '\x01';
  }
  else if (cVar2 != '\x01') goto LAB_0d9d5a;
  uVar10 = Ram00fd4a;
  if (((uVar10 & 8) != 0) && (uVar10 = Ram00fd48, (uVar10 & 0x20) != 0)) {
    iVar7 = Ram00f63a;
    uVar11 = iVar7 + 0x42;
    uVar10 = 0x24;
    if (((uVar11 & 0xc000) != 0) &&
       ((uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000 && (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000))
       )) {
      uVar10 = 3;
    }
    bVar12 = UNK_00d5b0;
    if (*(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) < bVar12) {
      uVar10 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff));
    }
  }
  cVar2 = UNK_00d579;
  bVar12 = cVar2 - 1;
  uVar9 = Ram00d556;
  bVar4 = UNK_00d5b0;
  uVar9 = egs52_ramp_u16(uVar9,target,(uint)bVar4);
  Ram00d556 = uVar9;
  uVar8 = egs52_update_near_d600_0d7cb8(bVar12,uVar9);
  Ram00d56c = uVar8;
  cVar2 = UNK_00d5b0;
  if (cVar2 == '\0') {
    uVar10 = Ram00fd48;
    Ram00fd48 = uVar10 | *(byte *)((uint3)(bVar12 + 0x172e) | 0x90000);
    UNK_00d566 = 0;
    UNK_00d567 = 0;
    cVar2 = UNK_00d437;
    UNK_00d437 = cVar2 + '\x01';
  }
LAB_0d9d5a:
  cVar2 = UNK_00d577;
  if ((cVar2 == '\x03') || (cVar2 == '\x02')) {
    cVar2 = UNK_00d579;
    if (cVar2 == '\x02') {
      iVar7 = Ram00f626;
      uVar10 = iVar7 + 0x3c;
      uVar11 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      target = (ushort)(((ulong)target *
                        (ulong)*(uint *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff))) / 1000);
    }
    uVar8 = egs52_compute_from_near_f63a_0d7efc(bVar12,target);
    Ram00d56a = uVar8;
  }
  else {
    uVar10 = egs52_compute_from_near_f63a_0d7e88(bVar12,target);
    uVar11 = egs52_compute_from_near_d4e1_0d7f50(bVar12,target);
    if (uVar11 < uVar10) {
      uVar8 = egs52_compute_from_near_f63a_0d7e88(bVar12,target);
    }
    else {
      uVar8 = egs52_compute_from_near_d4e1_0d7f50(bVar12,target);
    }
    Ram00d56a = uVar8;
  }
  return;
}


