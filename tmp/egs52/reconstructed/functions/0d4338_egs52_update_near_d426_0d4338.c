/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d4338; FLS offset 0x054338.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d44a8) */
/* WARNING: Removing unreachable block (ram,0x0d449c) */
/* WARNING: Removing unreachable block (ram,0x0d4494) */
/* WARNING: Removing unreachable block (ram,0x0d448c) */
/* WARNING: Removing unreachable block (ram,0x0d4480) */
/* WARNING: Removing unreachable block (ram,0x0d447a) */
/* WARNING: Removing unreachable block (ram,0x0d446e) */
/* WARNING: Removing unreachable block (ram,0x0d4462) */
/* WARNING: Removing unreachable block (ram,0x0d445e) */
/* WARNING: Removing unreachable block (ram,0x0d4456) */
/* WARNING: Removing unreachable block (ram,0x0d444e) */
/* WARNING: Removing unreachable block (ram,0x0d444a) */
/* WARNING: Removing unreachable block (ram,0x0d4440) */
/* WARNING: Removing unreachable block (ram,0x0d441c) */
/* WARNING: Removing unreachable block (ram,0x0d440e) */
/* WARNING: Removing unreachable block (ram,0x0d4434) */
/* WARNING: Removing unreachable block (ram,0x0d4430) */
/* WARNING: Removing unreachable block (ram,0x0d4406) */
/* WARNING: Removing unreachable block (ram,0x0d43fe) */
/* WARNING: Removing unreachable block (ram,0x0d43ee) */
/* WARNING: Removing unreachable block (ram,0x0d43e4) */
/* WARNING: Removing unreachable block (ram,0x0d43d6) */
/* WARNING: Removing unreachable block (ram,0x0d43d2) */
/* WARNING: Removing unreachable block (ram,0x0d43ce) */
/* WARNING: Removing unreachable block (ram,0x0d43c4) */
/* WARNING: Removing unreachable block (ram,0x0d43b4) */
/* WARNING: Removing unreachable block (ram,0x0d43a2) */
/* WARNING: Removing unreachable block (ram,0x0d439a) */
/* WARNING: Removing unreachable block (ram,0x0d4386) */
/* WARNING: Removing unreachable block (ram,0x0d437e) */
/* WARNING: Removing unreachable block (ram,0x0d4372) */
/* WARNING: Removing unreachable block (ram,0x0d4368) */
/* WARNING: Removing unreachable block (ram,0x0d4364) */
/* WARNING: Removing unreachable block (ram,0x0d435e) */
/* WARNING: Removing unreachable block (ram,0x0d4358) */
/* WARNING: Removing unreachable block (ram,0x0d4346) */
/* WARNING: Removing unreachable block (ram,0x0d43fa) */
/* WARNING: Removing unreachable block (ram,0x0d4378) */
/* WARNING: Removing unreachable block (ram,0x0d4426) */
/* WARNING: Removing unreachable block (ram,0x0d4418) */
/* WARNING: Removing unreachable block (ram,0x0d4488) */
/* WARNING: Removing unreachable block (ram,0x0d447c) */

uint egs52_update_near_d426_0d4338(char param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  ushort x;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  
  if ((param_1 == '\x03') && ((cVar7 = UNK_00d579, cVar7 == '\x05' || (cVar7 == '\x06')))) {
    uVar14 = 0;
  }
  else {
    bVar8 = UNK_00d477;
    iVar12 = Ram00f636;
    uVar14 = iVar12 + (uint)bVar8 * 2 + 0x18;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar14 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
    cVar7 = UNK_00d577;
    if (cVar7 == '\x01') {
      uVar13 = Ram00d4d2;
      x = Ram00d508;
      iVar12 = Ram00f63c;
      bVar8 = UNK_00d477;
      iVar5 = Ram00f63c;
      bVar9 = UNK_00d477;
      iVar10 = Ram00f63c;
      uVar13 = egs52_map_u16(3,3,(ushort *)(iVar5 + 0x1e + (uint)bVar9 * 6),
                             (ushort *)(iVar10 + 0x3c + (uint)bVar9 * 6),
                             (ushort *)(iVar12 + 0x5a + (uint)bVar8 * 0x12),x,uVar13);
      Ram00d426 = uVar13;
      uVar14 = uVar14 + uVar13;
      uVar1 = Ram00fd4a;
      if ((uVar1 & 0x10) == 0) {
        iVar12 = Ram00f636;
        uVar1 = iVar12 + 0x5c;
        uVar6 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        iVar5 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
        iVar10 = Ram00d4d0;
        iVar11 = Ram00d4d0;
        if (((iVar5 != iVar11 && iVar10 <= iVar5) && (uVar1 = Ram00fd34, (uVar1 & 1) == 0)) &&
           (uVar1 = Ram00fd34, (uVar1 & 4) == 0)) {
          bVar8 = UNK_00d477;
          uVar1 = iVar12 + (uint)bVar8 * 2 + 0x5e;
          uVar6 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          uVar1 = *(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
          if (uVar1 < uVar14) {
            uVar14 = uVar14 - uVar1;
          }
        }
      }
    }
    else {
      Ram00d426 = 0;
    }
    uVar1 = Ram00fd4a;
    if ((uVar1 & 0x20) != 0) {
      cVar7 = UNK_00d454;
      if (cVar7 == '\x03') {
        iVar12 = Ram00f636;
        uVar6 = iVar12 + 0x36;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        puVar4 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        if (uVar14 == *puVar4 || uVar14 < *puVar4) {
          uVar14 = 0;
        }
        else {
          uVar1 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar14 = uVar14 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        }
      }
      else {
        iVar12 = Ram00f636;
        uVar6 = iVar12 + 0x16;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        puVar4 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        if (uVar14 == *puVar4 || uVar14 < *puVar4) {
          uVar14 = 0;
        }
        else {
          uVar1 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar14 = uVar14 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        }
      }
    }
    if (param_1 == '\x02') {
      iVar12 = Ram00f636;
      uVar6 = iVar12 + 0x14;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      puVar4 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
      if (uVar14 == *puVar4 || uVar14 < *puVar4) {
        uVar14 = 0;
      }
      else {
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar14 = uVar14 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
      }
      cVar7 = UNK_00d60e;
      if (cVar7 == '\x03') {
        iVar12 = Ram00f61e;
        uVar1 = iVar12 + 0x1d;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) &&
           (uVar14 != 0)) {
          cVar7 = UNK_00d7aa;
          if (cVar7 == '\0') {
            uVar1 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            uVar14 = uVar14 + *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
          }
          else if (cVar7 == '\x02') {
            uVar1 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            iVar12 = Ram00f636;
            uVar2 = iVar12 + 0x5a;
            uVar3 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            uVar14 = uVar14 + *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) +
                     *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
          }
        }
      }
    }
  }
  uVar1 = Ram00fd4a;
  if (((uVar1 & 2) != 0) && (bVar8 = UNK_00d579, 5 < bVar8)) {
    iVar12 = Ram00f636;
    uVar6 = iVar12 + 0x28 + (uint)bVar8;
    uVar1 = 0x24;
    if (((uVar6 & 0xc000) != 0) &&
       ((uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)))) {
      uVar1 = 3;
    }
    uVar14 = uVar14 + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) * 10;
    if ((int)uVar14 < 1) {
      uVar14 = 0;
    }
  }
  return uVar14;
}


