/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0def12; FLS offset 0x05ef12.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0df160) */
/* WARNING: Removing unreachable block (ram,0x0df138) */
/* WARNING: Removing unreachable block (ram,0x0df134) */
/* WARNING: Removing unreachable block (ram,0x0df128) */
/* WARNING: Removing unreachable block (ram,0x0df124) */
/* WARNING: Removing unreachable block (ram,0x0df120) */
/* WARNING: Removing unreachable block (ram,0x0df118) */
/* WARNING: Removing unreachable block (ram,0x0df114) */
/* WARNING: Removing unreachable block (ram,0x0df110) */
/* WARNING: Removing unreachable block (ram,0x0df108) */
/* WARNING: Removing unreachable block (ram,0x0df104) */
/* WARNING: Removing unreachable block (ram,0x0df0f6) */
/* WARNING: Removing unreachable block (ram,0x0df0f0) */
/* WARNING: Removing unreachable block (ram,0x0df0e8) */
/* WARNING: Removing unreachable block (ram,0x0df0e2) */
/* WARNING: Removing unreachable block (ram,0x0df1b6) */
/* WARNING: Removing unreachable block (ram,0x0df1b2) */
/* WARNING: Removing unreachable block (ram,0x0df1aa) */
/* WARNING: Removing unreachable block (ram,0x0df178) */
/* WARNING: Removing unreachable block (ram,0x0df182) */
/* WARNING: Removing unreachable block (ram,0x0df17e) */
/* WARNING: Removing unreachable block (ram,0x0df172) */
/* WARNING: Removing unreachable block (ram,0x0df16e) */
/* WARNING: Removing unreachable block (ram,0x0df16a) */
/* WARNING: Removing unreachable block (ram,0x0df166) */
/* WARNING: Removing unreachable block (ram,0x0df0ce) */
/* WARNING: Removing unreachable block (ram,0x0df0c0) */
/* WARNING: Removing unreachable block (ram,0x0df0bc) */
/* WARNING: Removing unreachable block (ram,0x0df0ae) */
/* WARNING: Removing unreachable block (ram,0x0df0a6) */
/* WARNING: Removing unreachable block (ram,0x0df0a2) */
/* WARNING: Removing unreachable block (ram,0x0df09e) */
/* WARNING: Removing unreachable block (ram,0x0df096) */
/* WARNING: Removing unreachable block (ram,0x0df074) */
/* WARNING: Removing unreachable block (ram,0x0df066) */
/* WARNING: Removing unreachable block (ram,0x0df05e) */
/* WARNING: Removing unreachable block (ram,0x0df05a) */
/* WARNING: Removing unreachable block (ram,0x0df056) */
/* WARNING: Removing unreachable block (ram,0x0df036) */
/* WARNING: Removing unreachable block (ram,0x0df028) */
/* WARNING: Removing unreachable block (ram,0x0df020) */
/* WARNING: Removing unreachable block (ram,0x0df01c) */
/* WARNING: Removing unreachable block (ram,0x0df018) */
/* WARNING: Removing unreachable block (ram,0x0deff8) */
/* WARNING: Removing unreachable block (ram,0x0defea) */
/* WARNING: Removing unreachable block (ram,0x0defe2) */
/* WARNING: Removing unreachable block (ram,0x0defde) */
/* WARNING: Removing unreachable block (ram,0x0defda) */
/* WARNING: Removing unreachable block (ram,0x0defd2) */
/* WARNING: Removing unreachable block (ram,0x0defce) */
/* WARNING: Removing unreachable block (ram,0x0def94) */
/* WARNING: Removing unreachable block (ram,0x0defae) */
/* WARNING: Removing unreachable block (ram,0x0defa0) */
/* WARNING: Removing unreachable block (ram,0x0def80) */
/* WARNING: Removing unreachable block (ram,0x0def7c) */
/* WARNING: Removing unreachable block (ram,0x0def78) */
/* WARNING: Removing unreachable block (ram,0x0def70) */
/* WARNING: Removing unreachable block (ram,0x0def6a) */
/* WARNING: Removing unreachable block (ram,0x0def66) */
/* WARNING: Removing unreachable block (ram,0x0def62) */
/* WARNING: Removing unreachable block (ram,0x0def5e) */
/* WARNING: Removing unreachable block (ram,0x0def5a) */
/* WARNING: Removing unreachable block (ram,0x0def56) */
/* WARNING: Removing unreachable block (ram,0x0def4e) */
/* WARNING: Removing unreachable block (ram,0x0def4a) */
/* WARNING: Removing unreachable block (ram,0x0def2e) */
/* WARNING: Removing unreachable block (ram,0x0def1a) */
/* WARNING: Removing unreachable block (ram,0x0def14) */
/* WARNING: Removing unreachable block (ram,0x0df092) */
/* WARNING: Removing unreachable block (ram,0x0df0de) */
/* WARNING: Removing unreachable block (ram,0x0df12e) */

void egs52_update_near_d4ac_0def12(uint param_1)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  short sVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  
  Ram00d4ac = 0;
  iVar13 = 0;
  cVar7 = UNK_00d577;
  if ((byte)(cVar7 - 1U) < 6) {
                    /* WARNING: Switch is manually overridden */
    switch((uint3)*(uint *)((uint3)((uint)(byte)(cVar7 - 1U) * 2 + 0x1754) | 0x90000) | 0xd0000) {
    case 0xdef32:
      uVar11 = egs52_lookup_and_offset_d467();
      iVar13 = Ram00d522;
      Ram00d522 = iVar13 - (int)(((ulong)param_1 * 0x14) / (ulong)(uVar11 & 0xff));
      iVar13 = Ram00d522;
      if (iVar13 < 0) {
        Ram00d522 = 0;
      }
      iVar13 = Ram00d524;
      iVar12 = Ram00d522;
      iVar13 = iVar13 - iVar12;
      iVar12 = Ram00f634;
      uVar11 = iVar12 + 0x20;
      uVar1 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar12 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
      iVar4 = Ram00d414;
      iVar5 = Ram00d414;
      if ((iVar12 != iVar5 && iVar4 <= iVar12) && (cVar7 = UNK_00d579, cVar7 == '\x01')) {
        iVar12 = Ram00f63a;
        uVar11 = iVar12 + 0x73;
        uVar1 = 0x24;
        if (((uVar11 & 0xc000) != 0) &&
           ((uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000 &&
            (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)))) {
          uVar1 = 3;
        }
        bVar2 = UNK_00d5cc;
        if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) < bVar2) {
          sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 0x6c),iVar13);
          Ram00d4ac = sVar10;
          break;
        }
      }
      iVar12 = Ram00f63a;
      sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 0xc),iVar13);
      Ram00d4ac = sVar10;
      break;
    case 0xdefb6:
      uVar11 = egs52_lookup_and_offset_d467();
      iVar13 = Ram00d522;
      Ram00d522 = iVar13 - (int)(((ulong)param_1 * 0x14) / (ulong)(uVar11 & 0xff));
      iVar13 = Ram00d522;
      if (iVar13 < 0) {
        Ram00d522 = 0;
      }
      iVar13 = Ram00d524;
      iVar12 = Ram00d522;
      iVar13 = iVar13 - iVar12;
      iVar12 = Ram00f634;
      sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 0x10),iVar13);
      Ram00d4ac = sVar10;
      break;
    case 0xdf000:
      uVar11 = egs52_lookup_and_offset_d467();
      iVar13 = Ram00d522;
      Ram00d522 = iVar13 + (int)(((ulong)param_1 * 0x14) / (ulong)(uVar11 & 0xff));
      iVar13 = Ram00d524;
      iVar12 = Ram00d522;
      iVar13 = iVar13 - iVar12;
      iVar12 = Ram00f634;
      sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 10),iVar13);
      Ram00d4ac = sVar10;
      break;
    case 0xdf03e:
      uVar11 = egs52_lookup_and_offset_d467();
      iVar13 = Ram00d522;
      Ram00d522 = iVar13 + (int)(((ulong)param_1 * 0x14) / (ulong)(uVar11 & 0xff));
      iVar13 = Ram00d524;
      iVar12 = Ram00d522;
      iVar13 = iVar13 - iVar12;
      iVar12 = Ram00f63a;
      sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 0x12),iVar13);
      Ram00d4ac = sVar10;
      break;
    case 0xdf07a:
      uVar11 = egs52_lookup_and_offset_d467();
      iVar13 = Ram00d522;
      Ram00d522 = iVar13 - (int)(((ulong)param_1 * 0x14) / (ulong)(uVar11 & 0xff));
      iVar13 = Ram00d522;
      if (iVar13 < 0) {
        Ram00d522 = 0;
      }
      iVar13 = Ram00d524;
      iVar12 = Ram00d522;
      iVar13 = iVar13 - iVar12;
      iVar12 = Ram00f64a;
      sVar10 = egs52_pid_step((ushort *)0xd55e,(short *)(iVar12 + 0x36),iVar13);
      Ram00d4ac = sVar10;
    }
  }
  iVar12 = Ram00d4ec;
  if ((iVar12 != 0) && (uVar11 = Ram00fd4c, (uVar11 & 4) == 0)) {
    uVar11 = Ram00fd4c;
    Ram00fd4c = uVar11 | 4;
  }
  uVar11 = Ram00fd4c;
  if ((uVar11 & 4) != 0) {
    uVar11 = Ram00fd48;
    if ((uVar11 & 0x20) == 0) {
      uVar11 = Ram00d550;
      uVar1 = Ram00d536;
      uVar6 = Ram00d536;
      if (uVar11 == uVar6 || uVar11 < uVar1) {
        uVar11 = 0;
      }
      else {
        iVar12 = Ram00d536;
        uVar11 = uVar11 - iVar12;
      }
      uVar1 = Ram00d556;
      if (uVar1 <= uVar11) {
        uVar11 = Ram00fd34;
        if ((uVar11 & 0x80) == 0) {
          uVar11 = Ram00fd34;
          Ram00fd34 = uVar11 | 0x80;
        }
        else {
          uVar11 = Ram00fd34;
          Ram00fd34 = uVar11 | 0x40;
        }
      }
      uVar1 = Ram00d556;
      uVar11 = Ram00d552;
      if (uVar1 < uVar11) {
        iVar12 = Ram00f62e;
        uVar11 = iVar12 + 0x23;
        uVar1 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
        bVar8 = UNK_00d580;
        bVar9 = UNK_00d580;
        if (bVar2 != bVar9 && bVar8 <= bVar2) {
          cVar7 = UNK_00d580;
          UNK_00d580 = cVar7 + '\x01';
          uVar11 = iVar12 + 0x22;
          uVar1 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          bVar2 = UNK_00d580;
          if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) < bVar2) {
            bVar2 = UNK_00d580;
          }
          else {
            iVar12 = Ram00f62e;
            uVar11 = iVar12 + 0x22;
            uVar1 = 0x24;
            if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            bVar2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
          }
          uVar11 = egs52_lookup_and_offset_d467();
          iVar12 = Ram00d57e;
          Ram00d57e = iVar12 + (int)(((long)(int)(uVar11 & 0xff) * (long)iVar13) /
                                    (long)(int)((uint)bVar2 * 0x14));
        }
      }
    }
    else {
      cVar7 = UNK_00d580;
      UNK_00d580 = cVar7 + '\x01';
      iVar12 = Ram00f62e;
      uVar11 = iVar12 + 0x22;
      uVar1 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar2 = UNK_00d580;
      if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) < bVar2) {
        bVar2 = UNK_00d580;
      }
      else {
        iVar12 = Ram00f62e;
        uVar11 = iVar12 + 0x22;
        uVar1 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        bVar2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
      }
      uVar11 = egs52_lookup_and_offset_d467();
      uVar3 = (long)(int)(uVar11 & 0xff) * (long)iVar13;
      uVar11 = (uint)(uVar3 >> 0x10);
      iVar13 = Ram00d57e;
      Ram00d57e = iVar13 + (int)((long)(uVar3 & 0xffff | (ulong)uVar11 << 0x10) /
                                (long)(int)((uint)bVar2 * 0x14));
      iVar12 = egs52_sum_pressure_terms((int)uVar3,uVar11);
      iVar13 = Ram00f636;
      uVar11 = iVar13 + 0x34;
      uVar1 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (iVar12 <= -*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff))) {
        uVar11 = Ram00fd34;
        Ram00fd34 = uVar11 | 0x40;
      }
    }
  }
  return;
}


