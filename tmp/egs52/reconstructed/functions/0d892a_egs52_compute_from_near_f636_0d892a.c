/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d892a; FLS offset 0x05892a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8aba) */
/* WARNING: Removing unreachable block (ram,0x0d8ab0) */
/* WARNING: Removing unreachable block (ram,0x0d89de) */
/* WARNING: Removing unreachable block (ram,0x0d89da) */
/* WARNING: Removing unreachable block (ram,0x0d89c8) */
/* WARNING: Removing unreachable block (ram,0x0d89c2) */
/* WARNING: Removing unreachable block (ram,0x0d89bc) */
/* WARNING: Removing unreachable block (ram,0x0d89b2) */
/* WARNING: Removing unreachable block (ram,0x0d89ac) */
/* WARNING: Removing unreachable block (ram,0x0d89a6) */
/* WARNING: Removing unreachable block (ram,0x0d898e) */
/* WARNING: Removing unreachable block (ram,0x0d8988) */
/* WARNING: Removing unreachable block (ram,0x0d896c) */
/* WARNING: Removing unreachable block (ram,0x0d8968) */
/* WARNING: Removing unreachable block (ram,0x0d8956) */
/* WARNING: Removing unreachable block (ram,0x0d8952) */
/* WARNING: Removing unreachable block (ram,0x0d894a) */
/* WARNING: Removing unreachable block (ram,0x0d8a9c) */
/* WARNING: Removing unreachable block (ram,0x0d8a96) */
/* WARNING: Removing unreachable block (ram,0x0d8a76) */
/* WARNING: Removing unreachable block (ram,0x0d8a70) */
/* WARNING: Removing unreachable block (ram,0x0d8a6a) */
/* WARNING: Removing unreachable block (ram,0x0d8a64) */
/* WARNING: Removing unreachable block (ram,0x0d8a60) */
/* WARNING: Removing unreachable block (ram,0x0d8a50) */
/* WARNING: Removing unreachable block (ram,0x0d8a4a) */
/* WARNING: Removing unreachable block (ram,0x0d8a38) */
/* WARNING: Removing unreachable block (ram,0x0d8a32) */
/* WARNING: Removing unreachable block (ram,0x0d8a28) */
/* WARNING: Removing unreachable block (ram,0x0d8a22) */
/* WARNING: Removing unreachable block (ram,0x0d8a1e) */
/* WARNING: Removing unreachable block (ram,0x0d8a0a) */
/* WARNING: Removing unreachable block (ram,0x0d8a06) */
/* WARNING: Removing unreachable block (ram,0x0d8a00) */
/* WARNING: Removing unreachable block (ram,0x0d8944) */
/* WARNING: Removing unreachable block (ram,0x0d8940) */
/* WARNING: Removing unreachable block (ram,0x0d89fc) */
/* WARNING: Removing unreachable block (ram,0x0d894e) */

uint egs52_compute_from_near_f636_0d892a(byte param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uStack_a;
  
  if ((param_1 == 4) || (param_1 == 5)) {
    uVar2 = Ram00f636;
    uVar11 = 0x24;
    if (((uVar2 & 0xc000) != 0) &&
       ((uVar11 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar11 = 0x2c, (uVar2 & 0xc000) != 0x8000))))
    {
      uVar11 = 3;
    }
    if ((*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0x80) != 0) {
      iVar7 = Ram00d4d2;
      iVar10 = Ram00d47c;
      iVar5 = Ram00d4ac;
      iVar6 = Ram00d4b2;
      uStack_a = (iVar7 + iVar10 + iVar5) - iVar6;
      if ((int)uStack_a < 0) {
        uStack_a = 0;
      }
      bVar8 = UNK_00d4df;
      uVar11 = Ram00d4bc;
      uVar11 = (uint)(((ulong)bVar8 * (ulong)uVar11) / 100);
      if (uStack_a < uVar11) {
        iVar10 = 0;
      }
      else {
        bVar8 = UNK_00d4e1;
        uVar2 = Ram00d46a;
        iVar10 = (int)(((ulong)(uStack_a - uVar11) * (ulong)uVar2) / (ulong)bVar8);
      }
      iVar5 = Ram00d546;
      uVar11 = Ram00d532;
      if ((uint)(iVar10 + iVar5) < uVar11) {
        uVar11 = 0;
      }
      else {
        iVar6 = Ram00d532;
        uVar11 = (iVar10 + iVar5) - iVar6;
      }
      uStack_a = Ram00d54a;
      uVar2 = Ram00d536;
      if (uStack_a < uVar2) {
        uStack_a = 0;
      }
      else {
        iVar10 = Ram00d536;
        uStack_a = uStack_a - iVar10;
      }
      iVar10 = Ram00f634;
      uVar2 = iVar10 + 0x1f;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar11 = egs52_compute_from_near_f626_0d7c4e
                         (param_1,uStack_a,
                          (int)(((ulong)uVar11 *
                                (ulong)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))) /
                               100));
      goto LAB_0d8ab0;
    }
  }
  iVar10 = Ram00f63a;
  uVar11 = iVar10 + 0x4c;
  uVar2 = 0x24;
  if ((((uVar11 & 0xc000) != 0) && (uVar2 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = Ram00d4d2;
  uVar3 = Ram00d46e;
  iVar10 = Ram00d54a;
  uVar11 = (int)(((ulong)uVar1 * (ulong)uVar3) /
                (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar11 & 0x3fff))) + iVar10;
  uVar2 = Ram00d536;
  uVar3 = Ram00d536;
  if (uVar11 == uVar3 || uVar11 < uVar2) {
    uVar11 = 0;
  }
  else {
    iVar10 = Ram00d536;
    uVar11 = uVar11 - iVar10;
  }
  uVar2 = Ram00d552;
  if (uVar2 <= uVar11) {
    uVar11 = Ram00d552;
  }
  iVar10 = (uint)param_1 * 2;
  iVar5 = Ram00f626;
  uVar2 = iVar5 + iVar10 + 10;
  uVar3 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar9 = Ram00d546;
  uVar1 = Ram00d532;
  uVar4 = Ram00d532;
  if (uVar9 == uVar4 || uVar9 < uVar1) {
    uStack_a = 0;
  }
  else {
    iVar5 = Ram00d532;
    iVar6 = Ram00f626;
    uVar1 = iVar6 + iVar10 + 0x1a;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uStack_a = (uint)(((ulong)(uVar9 - iVar5) *
                      (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) / 1000);
  }
  iVar5 = Ram00f626;
  uVar1 = iVar5 + iVar10 + 0x2a;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  uVar11 = (int)(((ulong)uVar11 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))) /
                1000) + uStack_a + *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
  if ((int)uVar11 < 0) {
    uVar11 = 0;
  }
LAB_0d8ab0:
  uVar2 = Ram00d54c;
  if (uVar2 <= uVar11) {
    uVar11 = Ram00d54c;
  }
  return uVar11;
}


