/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e0d52; FLS offset 0x060d52.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e0e74) */
/* WARNING: Removing unreachable block (ram,0x0e0e70) */
/* WARNING: Removing unreachable block (ram,0x0e0e6e) */
/* WARNING: Removing unreachable block (ram,0x0e0e68) */
/* WARNING: Removing unreachable block (ram,0x0e0e66) */
/* WARNING: Removing unreachable block (ram,0x0e0e5e) */
/* WARNING: Removing unreachable block (ram,0x0e0e56) */
/* WARNING: Removing unreachable block (ram,0x0e0e50) */
/* WARNING: Removing unreachable block (ram,0x0e0e4c) */
/* WARNING: Removing unreachable block (ram,0x0e0e46) */
/* WARNING: Removing unreachable block (ram,0x0e0e42) */
/* WARNING: Removing unreachable block (ram,0x0e0e3c) */
/* WARNING: Removing unreachable block (ram,0x0e0e38) */
/* WARNING: Removing unreachable block (ram,0x0e0e34) */
/* WARNING: Removing unreachable block (ram,0x0e0e2c) */
/* WARNING: Removing unreachable block (ram,0x0e0e24) */
/* WARNING: Removing unreachable block (ram,0x0e0e1e) */
/* WARNING: Removing unreachable block (ram,0x0e0e18) */
/* WARNING: Removing unreachable block (ram,0x0e0e14) */
/* WARNING: Removing unreachable block (ram,0x0e0e0c) */
/* WARNING: Removing unreachable block (ram,0x0e0e00) */
/* WARNING: Removing unreachable block (ram,0x0e0dfa) */
/* WARNING: Removing unreachable block (ram,0x0e0df4) */
/* WARNING: Removing unreachable block (ram,0x0e0df0) */
/* WARNING: Removing unreachable block (ram,0x0e0de8) */
/* WARNING: Removing unreachable block (ram,0x0e0dda) */
/* WARNING: Removing unreachable block (ram,0x0e0dcc) */
/* WARNING: Removing unreachable block (ram,0x0e0dc4) */
/* WARNING: Removing unreachable block (ram,0x0e0dbc) */
/* WARNING: Removing unreachable block (ram,0x0e0db6) */
/* WARNING: Removing unreachable block (ram,0x0e0dae) */
/* WARNING: Removing unreachable block (ram,0x0e0daa) */
/* WARNING: Removing unreachable block (ram,0x0e0da0) */
/* WARNING: Removing unreachable block (ram,0x0e0d98) */
/* WARNING: Removing unreachable block (ram,0x0e0d92) */
/* WARNING: Removing unreachable block (ram,0x0e0d8e) */
/* WARNING: Removing unreachable block (ram,0x0e0d80) */
/* WARNING: Removing unreachable block (ram,0x0e0d7c) */
/* WARNING: Removing unreachable block (ram,0x0e0d6c) */
/* WARNING: Removing unreachable block (ram,0x0e0d68) */
/* WARNING: Removing unreachable block (ram,0x0e0d60) */
/* WARNING: Removing unreachable block (ram,0x0e0d5c) */
/* WARNING: Removing unreachable block (ram,0x0e0d58) */
/* WARNING: Removing unreachable block (ram,0x0e0d54) */

void egs52_update_near_d71b_0e0d52(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uchar input;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uchar *axis;
  byte bVar10;
  short sVar11;
  
  UNK_00d71b = 0;
  Ram00d72c = 0;
  Ram00d742 = 0;
  uVar1 = Ram00fd56;
  if ((uVar1 & 1) != 0) {
    iVar6 = Ram00f65a;
    uVar1 = iVar6 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) goto LAB_0e0d8c;
  }
  uVar1 = Ram00fd56;
  if ((uVar1 & 1) != 0) {
    return;
  }
  iVar6 = Ram00f65a;
  uVar1 = iVar6 + 1;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) == 0) {
    return;
  }
LAB_0e0d8c:
  axis = (uchar *)Ram00f65c;
  iVar6 = Ram00f65c;
  input = UNK_00d443;
  bVar10 = egs52_curve_u8('\x06',axis,(uchar *)(iVar6 + 6),input);
  UNK_00d7d0 = bVar10;
  iVar6 = Ram00f65e;
  uVar1 = iVar6 + 0x4a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d742 = (int)(((ulong)bVar10 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))
                    ) / 100);
  iVar6 = Ram00f664;
  iVar3 = Ram00f664;
  bVar10 = UNK_00d570;
  sVar11 = egs52_curve_s16('\x04',(short *)(iVar6 + 0x18),(short *)(iVar3 + 0x20),(uint)bVar10);
  bVar10 = UNK_00d7d0;
  UNK_00d71b = (char)(((long)(int)(uint)bVar10 * (long)sVar11) / 1000);
  bVar9 = UNK_00d7d0;
  bVar10 = UNK_00d774;
  iVar6 = Ram00f662;
  uVar1 = iVar6 + (uint)bVar10 * 2 + 0x76;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d72a = (int)(((ulong)bVar9 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 100);
  bVar9 = UNK_00d7d0;
  bVar10 = UNK_00d772;
  iVar6 = Ram00f662;
  uVar1 = iVar6 + (uint)bVar10 * 2 + 0x7e;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d728 = (int)(((ulong)bVar9 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 100);
  iVar6 = Ram00f66a;
  uVar1 = iVar6 + 6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar3 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar7 = Ram00d7ac;
  iVar8 = Ram00d7ac;
  if (iVar3 != iVar8 && iVar7 <= iVar3) {
    uVar1 = iVar6 + 9;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    bVar10 = UNK_00d443;
    if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < bVar10) {
      return;
    }
  }
  bVar10 = UNK_00d570;
  uVar1 = Ram00d7d2;
  if (uVar1 <= bVar10) {
    iVar6 = Ram00f662;
    bVar10 = UNK_00d774;
    uVar2 = iVar6 + 0x28 + (uint)bVar10 * 2;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar4 = Ram00d78c;
    uVar5 = Ram00d78c;
    if (uVar1 != uVar5 && uVar4 <= uVar1) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar6 = Ram00d78c;
      Ram00d72c = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) - iVar6;
    }
  }
  return;
}


