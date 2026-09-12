/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089090; FLS offset 0x009090.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0894a6) */
/* WARNING: Removing unreachable block (ram,0x089324) */
/* WARNING: Removing unreachable block (ram,0x089368) */
/* WARNING: Removing unreachable block (ram,0x08937c) */
/* WARNING: Removing unreachable block (ram,0x089406) */
/* WARNING: Removing unreachable block (ram,0x08931c) */
/* WARNING: Removing unreachable block (ram,0x08939c) */
/* WARNING: Removing unreachable block (ram,0x089422) */
/* WARNING: Removing unreachable block (ram,0x08941a) */
/* WARNING: Removing unreachable block (ram,0x08936e) */
/* WARNING: Removing unreachable block (ram,0x089464) */
/* WARNING: Removing unreachable block (ram,0x089386) */
/* WARNING: Removing unreachable block (ram,0x089332) */
/* WARNING: Removing unreachable block (ram,0x089380) */
/* WARNING: Removing unreachable block (ram,0x08933e) */
/* WARNING: Removing unreachable block (ram,0x08947e) */
/* WARNING: Removing unreachable block (ram,0x08942e) */
/* WARNING: Removing unreachable block (ram,0x0893f4) */
/* WARNING: Removing unreachable block (ram,0x0893a0) */
/* WARNING: Removing unreachable block (ram,0x08934a) */
/* WARNING: Removing unreachable block (ram,0x089318) */
/* WARNING: Removing unreachable block (ram,0x089474) */
/* WARNING: Removing unreachable block (ram,0x0892ee) */
/* WARNING: Removing unreachable block (ram,0x0892e6) */
/* WARNING: Removing unreachable block (ram,0x0892dc) */
/* WARNING: Removing unreachable block (ram,0x0892d6) */
/* WARNING: Removing unreachable block (ram,0x0892d0) */
/* WARNING: Removing unreachable block (ram,0x0892c6) */
/* WARNING: Removing unreachable block (ram,0x0892bc) */
/* WARNING: Removing unreachable block (ram,0x0892b2) */
/* WARNING: Removing unreachable block (ram,0x0892a0) */
/* WARNING: Removing unreachable block (ram,0x08929c) */
/* WARNING: Removing unreachable block (ram,0x089164) */
/* WARNING: Removing unreachable block (ram,0x0891d8) */
/* WARNING: Removing unreachable block (ram,0x089128) */
/* WARNING: Removing unreachable block (ram,0x08923c) */
/* WARNING: Removing unreachable block (ram,0x0891ea) */
/* WARNING: Removing unreachable block (ram,0x0891d0) */
/* WARNING: Removing unreachable block (ram,0x089224) */
/* WARNING: Removing unreachable block (ram,0x089196) */
/* WARNING: Removing unreachable block (ram,0x089210) */
/* WARNING: Removing unreachable block (ram,0x08911a) */
/* WARNING: Removing unreachable block (ram,0x089180) */
/* WARNING: Removing unreachable block (ram,0x08910e) */
/* WARNING: Removing unreachable block (ram,0x08911e) */
/* WARNING: Removing unreachable block (ram,0x089176) */
/* WARNING: Removing unreachable block (ram,0x089134) */
/* WARNING: Removing unreachable block (ram,0x08926a) */
/* WARNING: Removing unreachable block (ram,0x089264) */
/* WARNING: Removing unreachable block (ram,0x08926e) */
/* WARNING: Removing unreachable block (ram,0x0890e4) */
/* WARNING: Removing unreachable block (ram,0x0890dc) */
/* WARNING: Removing unreachable block (ram,0x0890d2) */
/* WARNING: Removing unreachable block (ram,0x0890cc) */
/* WARNING: Removing unreachable block (ram,0x0890c6) */
/* WARNING: Removing unreachable block (ram,0x0890bc) */
/* WARNING: Removing unreachable block (ram,0x0890b2) */
/* WARNING: Removing unreachable block (ram,0x0890a8) */
/* WARNING: Removing unreachable block (ram,0x089274) */
/* WARNING: Removing unreachable block (ram,0x089168) */
/* WARNING: Removing unreachable block (ram,0x08915e) */
/* WARNING: Removing unreachable block (ram,0x089218) */
/* WARNING: Removing unreachable block (ram,0x089172) */
/* WARNING: Removing unreachable block (ram,0x089140) */
/* WARNING: Removing unreachable block (ram,0x089112) */
/* WARNING: Removing unreachable block (ram,0x08923a) */
/* WARNING: Removing unreachable block (ram,0x089192) */
/* WARNING: Removing unreachable block (ram,0x08946e) */
/* WARNING: Removing unreachable block (ram,0x089478) */
/* WARNING: Removing unreachable block (ram,0x089444) */
/* WARNING: Removing unreachable block (ram,0x08934e) */
/* WARNING: Removing unreachable block (ram,0x0893f8) */
/* WARNING: Removing unreachable block (ram,0x0893e6) */
/* WARNING: Removing unreachable block (ram,0x0893c2) */
/* WARNING: Removing unreachable block (ram,0x089402) */
/* WARNING: Removing unreachable block (ram,0x0893da) */
/* WARNING: Removing unreachable block (ram,0x0894aa) */
/* WARNING: Removing unreachable block (ram,0x0893e2) */
/* WARNING: Removing unreachable block (ram,0x089372) */
/* WARNING: Removing unreachable block (ram,0x0893c6) */
/* WARNING: Removing unreachable block (ram,0x089328) */
/* WARNING: Removing unreachable block (ram,0x08917c) */
/* WARNING: Removing unreachable block (ram,0x0891b8) */
/* WARNING: Removing unreachable block (ram,0x089144) */
/* WARNING: Removing unreachable block (ram,0x0891dc) */
/* WARNING: Removing unreachable block (ram,0x0891ee) */
/* WARNING: Removing unreachable block (ram,0x0891bc) */
/* WARNING: Removing unreachable block (ram,0x089446) */
/* WARNING: Removing unreachable block (ram,0x08938a) */
/* WARNING: Removing unreachable block (ram,0x08925a) */
/* WARNING: Removing unreachable block (ram,0x0891f8) */
/* WARNING: Removing unreachable block (ram,0x0891fc) */

void egs52_update_near_f186_089090(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  uint uVar10;
  
  Ram00ffca = 0x4f;
  Ram00ef00 = 0x74b;
  Ram00ef02 = 0x100;
  Ram00ef04 = 0x2701;
  Ram00ef06 = 0xffff;
  Ram00ef08 = 0xffff;
  Ram00ef0a = 0xffff;
  Ram00ef0c = 0xe0ff;
  Ram00ef0e = 0;
  uVar8 = 0xef10;
  uVar7 = 1;
  while (bVar6 = (byte)uVar7, bVar6 < 0x10) {
    if ((7U >> ((byte)(bVar6 - 1) & 0xf) & 1) == 0) {
      uVar7 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      *(undefined2 *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff)) = 0x5555;
      uVar7 = uVar8 + 2;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0xffff;
      uVar7 = uVar8 + 4;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0xffff;
      uVar7 = uVar8 + 6;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0;
    }
    else {
      uVar3 = *(uint *)((uint3)(uVar7 * 4 + 0x1026) | 0x88000);
      uVar7 = *(uint *)((uint3)(uVar7 * 4 + 0x1028) | 0x88000);
      iVar4 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 6 & 0x3fff));
      uVar5 = *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 8 & 0x3fff));
      if ((*(byte *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 1U & 0x3fff)) & 2) == 0) {
        uVar9 = 0x5599;
      }
      else if ((*(char *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 10 & 0x3fff)) == '\0') &&
              (*(int *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff)) == 0 &&
               *(int *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 10U & 0x3fff)) == 0)) {
        uVar9 = 0x5595;
      }
      else {
        uVar9 = 0x55a5;
      }
      uVar10 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar10 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      *(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar8 & 0x3fff)) = uVar9;
      if ((*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) & 0x8000) == 0) {
        uVar10 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) << 0xd |
                 *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) >> 3 |
                 *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) << 0xd;
      }
      else {
        uVar10 = *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff));
        uVar10 = (uVar10 & 0x1fff) >> 5 | uVar10 << 0xb |
                 (*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xe000) >> 5;
      }
      uVar1 = uVar8 + 2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar10;
      if ((*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) & 0x8000) == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) << 0xb |
                 (*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) & 0x1fff) >> 5;
      }
      uVar1 = uVar8 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar10;
      uVar10 = uVar8 + 6;
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) =
           (*(char *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 2U & 0x3fff)) << 2 |
            *(byte *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 1U & 0x3fff)) & 0xfe |
           (byte)((uint)*(undefined2 *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff))
                 >> 0xf)) << 2;
    }
    egs52_transform_memory_08a084(uVar8 + 7,0xff,8);
    uVar8 = uVar8 + 0x10;
    uVar7 = (uint)(byte)(bVar6 + 1);
  }
  uVar8 = Ram00ef00;
  Ram00ef00 = uVar8 & 0xfffe;
  Ram00f186 = 7;
  uVar8 = Ram00f186;
  Ram00f186 = uVar8 | 0x40;
  Ram00ee00 = 0x74b;
  Ram00ee02 = 0x100;
  Ram00ee04 = 0x2701;
  Ram00ee06 = 0xffff;
  Ram00ee08 = 0xffff;
  Ram00ee0a = 0xffff;
  Ram00ee0c = 0xe0ff;
  Ram00ee0e = 0;
  uVar8 = 0xee10;
  uVar7 = 1;
  while (bVar6 = (byte)uVar7, bVar6 < 0x10) {
    if ((7U >> ((byte)(bVar6 - 1) & 0xf) & 1) == 0) {
      uVar7 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      *(undefined2 *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff)) = 0x5555;
      uVar7 = uVar8 + 2;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0xffff;
      uVar7 = uVar8 + 4;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0xffff;
      uVar7 = uVar8 + 6;
      uVar3 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0;
    }
    else {
      uVar3 = *(uint *)((uint3)(uVar7 * 4 + 0x1026) | 0x88000);
      uVar7 = *(uint *)((uint3)(uVar7 * 4 + 0x1028) | 0x88000);
      iVar4 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 6 & 0x3fff));
      uVar5 = *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 8 & 0x3fff));
      if ((*(byte *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 1U & 0x3fff)) & 2) == 0) {
        uVar9 = 0x5599;
      }
      else if ((*(char *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 10 & 0x3fff)) == '\0') &&
              (*(int *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff)) == 0 &&
               *(int *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 10U & 0x3fff)) == 0)) {
        uVar9 = 0x5595;
      }
      else {
        uVar9 = 0x55a5;
      }
      uVar10 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar10 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      *(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar8 & 0x3fff)) = uVar9;
      if ((*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) & 0x8000) == 0) {
        uVar10 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) << 0xd |
                 *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) >> 3 |
                 *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) << 0xd;
      }
      else {
        uVar10 = *(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff));
        uVar10 = (uVar10 & 0x1fff) >> 5 | uVar10 << 0xb |
                 (*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xe000) >> 5;
      }
      uVar1 = uVar8 + 2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar10;
      if ((*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff)) & 0x8000) == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = *(int *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) << 0xb |
                 (*(uint *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 & 0x3fff)) & 0x1fff) >> 5;
      }
      uVar1 = uVar8 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar10;
      uVar10 = uVar8 + 6;
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) =
           (*(char *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 2U & 0x3fff)) << 2 |
            *(byte *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(iVar4 + 1U & 0x3fff)) & 0xfe |
           (byte)((uint)*(undefined2 *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar3 + 2 & 0x3fff))
                 >> 0xf)) << 2;
    }
    egs52_transform_memory_08a084(uVar8 + 7,0xff,8);
    uVar8 = uVar8 + 0x10;
    uVar7 = (uint)(byte)(bVar6 + 1);
  }
  uVar8 = Ram00ee00;
  Ram00ee00 = uVar8 & 0xfffe;
  Ram00f18e = 7;
  uVar8 = Ram00f18e;
  Ram00f18e = uVar8 | 0x40;
  uVar8 = Ram00fde8;
  if ((uVar8 & 0x10) == 0) {
    egs52_update_near_f3e0_089fc6();
  }
  return;
}


