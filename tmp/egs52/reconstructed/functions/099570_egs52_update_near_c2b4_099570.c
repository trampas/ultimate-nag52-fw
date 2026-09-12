/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099570; FLS offset 0x019570.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0995a4) */
/* WARNING: Removing unreachable block (ram,0x09959c) */
/* WARNING: Removing unreachable block (ram,0x09963c) */
/* WARNING: Removing unreachable block (ram,0x099632) */
/* WARNING: Removing unreachable block (ram,0x09964a) */
/* WARNING: Removing unreachable block (ram,0x09962c) */
/* WARNING: Removing unreachable block (ram,0x099626) */
/* WARNING: Removing unreachable block (ram,0x099620) */
/* WARNING: Removing unreachable block (ram,0x0995f4) */
/* WARNING: Removing unreachable block (ram,0x0995fe) */
/* WARNING: Removing unreachable block (ram,0x0995f0) */
/* WARNING: Removing unreachable block (ram,0x099618) */
/* WARNING: Removing unreachable block (ram,0x09960e) */
/* WARNING: Removing unreachable block (ram,0x0995ea) */
/* WARNING: Removing unreachable block (ram,0x09967c) */
/* WARNING: Removing unreachable block (ram,0x09965c) */
/* WARNING: Removing unreachable block (ram,0x09966e) */
/* WARNING: Removing unreachable block (ram,0x099662) */
/* WARNING: Removing unreachable block (ram,0x099658) */
/* WARNING: Removing unreachable block (ram,0x099676) */
/* WARNING: Removing unreachable block (ram,0x099652) */
/* WARNING: Removing unreachable block (ram,0x0995e2) */
/* WARNING: Removing unreachable block (ram,0x09958c) */
/* WARNING: Removing unreachable block (ram,0x0995d0) */
/* WARNING: Removing unreachable block (ram,0x0995c8) */
/* WARNING: Removing unreachable block (ram,0x0995b8) */
/* WARNING: Removing unreachable block (ram,0x099586) */
/* WARNING: Removing unreachable block (ram,0x099582) */
/* WARNING: Removing unreachable block (ram,0x09957c) */
/* WARNING: Removing unreachable block (ram,0x099578) */
/* WARNING: Removing unreachable block (ram,0x0995ae) */
/* WARNING: Removing unreachable block (ram,0x099590) */
/* WARNING: Removing unreachable block (ram,0x0995da) */
/* WARNING: Removing unreachable block (ram,0x099672) */
/* WARNING: Removing unreachable block (ram,0x099668) */
/* WARNING: Removing unreachable block (ram,0x099612) */
/* WARNING: Removing unreachable block (ram,0x099606) */
/* WARNING: Removing unreachable block (ram,0x099646) */
/* WARNING: Removing unreachable block (ram,0x099636) */
/* WARNING: Removing unreachable block (ram,0x099642) */
/* WARNING: Removing unreachable block (ram,0x0995fa) */
/* WARNING: Removing unreachable block (ram,0x09960a) */

undefined1 egs52_update_near_c2b4_099570(byte param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  
  bVar5 = UNK_00c2b2;
  bVar7 = UNK_00c1ad;
  if (bVar5 < bVar7) {
    bVar5 = UNK_00c2b0;
    bVar7 = UNK_00c2b1;
    if (bVar5 < bVar7) {
      cVar9 = UNK_00c2b1;
      cVar6 = UNK_00c2b0;
      if ((byte)(cVar9 - cVar6) < param_2) {
        bVar5 = UNK_00c1ac;
        UNK_00c1ac = bVar5 & 0xfd;
        bVar5 = UNK_00c1ac;
        UNK_00c1ac = bVar5 & 0xfb;
        return 1;
      }
    }
    else {
      cVar6 = UNK_00c2b0;
      cVar9 = UNK_00c2b1;
      if ((byte)((-8 - cVar6) + cVar9) < param_2) {
        bVar5 = UNK_00c1ac;
        UNK_00c1ac = bVar5 & 0xfd;
        bVar5 = UNK_00c1ac;
        UNK_00c1ac = bVar5 & 0xfb;
        return 1;
      }
    }
  }
  bVar5 = UNK_00c2b0;
  bVar7 = UNK_00c2b3;
  if ((uint)bVar7 < (uint)bVar5 + (uint)param_2) {
    UNK_00c2b4 = 0;
    while( true ) {
      bVar5 = UNK_00c2b3;
      bVar8 = UNK_00c2b0;
      bVar7 = UNK_00c2b4;
      if ((int)((uint)bVar5 - (uint)bVar8) <= (int)(uint)bVar7) break;
      bVar5 = UNK_00c2b0;
      bVar7 = UNK_00c2b4;
      uVar1 = (uint)bVar5 + (uint)bVar7 + 0xc1af;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      cVar6 = UNK_00c2b4;
      uVar2 = (byte)(cVar6 + param_1) + 0xd2d3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      cVar6 = UNK_00c2b4;
      UNK_00c2b4 = cVar6 + '\x01';
    }
    cVar6 = UNK_00c2b4;
    param_2 = param_2 - cVar6;
    UNK_00c2b0 = param_2;
    UNK_00c2b4 = 0;
    while( true ) {
      bVar5 = UNK_00c2b4;
      bVar7 = UNK_00c2b4;
      if (param_2 == bVar7 || param_2 < bVar5) break;
      bVar5 = UNK_00c2b4;
      uVar1 = bVar5 + 0xc1af;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      bVar5 = UNK_00c2b4;
      uVar2 = (uint)(byte)(param_1 + cVar6) + (uint)bVar5 + 0xd2d3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      cVar9 = UNK_00c2b4;
      UNK_00c2b4 = cVar9 + '\x01';
    }
  }
  else {
    UNK_00c2b4 = 0;
    while( true ) {
      bVar5 = UNK_00c2b4;
      bVar7 = UNK_00c2b4;
      if (param_2 == bVar7 || param_2 < bVar5) break;
      cVar6 = UNK_00c2b0;
      cVar9 = UNK_00c2b4;
      uVar1 = (byte)(cVar6 + cVar9) + 0xc1af;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      bVar5 = UNK_00c2b4;
      uVar2 = (uint)param_1 + (uint)bVar5 + 0xd2d3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      cVar6 = UNK_00c2b4;
      UNK_00c2b4 = cVar6 + '\x01';
    }
    cVar6 = UNK_00c2b0;
    UNK_00c2b0 = cVar6 + param_2;
  }
  return 0;
}


