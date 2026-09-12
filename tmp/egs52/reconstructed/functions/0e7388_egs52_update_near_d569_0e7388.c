/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e7388; FLS offset 0x067388.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e73ae) */
/* WARNING: Removing unreachable block (ram,0x0e73a0) */
/* WARNING: Removing unreachable block (ram,0x0e739c) */
/* WARNING: Removing unreachable block (ram,0x0e7414) */
/* WARNING: Removing unreachable block (ram,0x0e7406) */
/* WARNING: Removing unreachable block (ram,0x0e7400) */
/* WARNING: Removing unreachable block (ram,0x0e7462) */
/* WARNING: Removing unreachable block (ram,0x0e7454) */
/* WARNING: Removing unreachable block (ram,0x0e744e) */
/* WARNING: Removing unreachable block (ram,0x0e7438) */
/* WARNING: Removing unreachable block (ram,0x0e7430) */
/* WARNING: Removing unreachable block (ram,0x0e744a) */
/* WARNING: Removing unreachable block (ram,0x0e7446) */
/* WARNING: Removing unreachable block (ram,0x0e7442) */
/* WARNING: Removing unreachable block (ram,0x0e743e) */
/* WARNING: Removing unreachable block (ram,0x0e7420) */
/* WARNING: Removing unreachable block (ram,0x0e741a) */
/* WARNING: Removing unreachable block (ram,0x0e73f8) */
/* WARNING: Removing unreachable block (ram,0x0e738c) */
/* WARNING: Removing unreachable block (ram,0x0e7388) */
/* WARNING: Removing unreachable block (ram,0x0e7394) */
/* WARNING: Removing unreachable block (ram,0x0e73b4) */
/* WARNING: Removing unreachable block (ram,0x0e73b8) */
/* WARNING: Removing unreachable block (ram,0x0e73c2) */
/* WARNING: Removing unreachable block (ram,0x0e73ca) */
/* WARNING: Removing unreachable block (ram,0x0e73e4) */
/* WARNING: Removing unreachable block (ram,0x0e73a4) */
/* WARNING: Removing unreachable block (ram,0x0e73f2) */
/* WARNING: Removing unreachable block (ram,0x0e73e8) */
/* WARNING: Removing unreachable block (ram,0x0e73e0) */
/* WARNING: Removing unreachable block (ram,0x0e73dc) */
/* WARNING: Removing unreachable block (ram,0x0e73d8) */
/* WARNING: Removing unreachable block (ram,0x0e73d4) */
/* WARNING: Removing unreachable block (ram,0x0e73bc) */
/* WARNING: Removing unreachable block (ram,0x0e73d0) */

void egs52_update_near_d569_0e7388(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  
  iVar3 = Ram00f61e;
  uVar1 = iVar3 + 0x1a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) == 0) {
    cVar6 = UNK_00d569;
    if (cVar6 == '\x02') {
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar5 = egs52_compute_from_near_d50e_0e735e
                        (*(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
      if (bVar5 < 2) {
        UNK_00d569 = 1;
        return;
      }
    }
    else {
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      cVar6 = egs52_compute_from_near_d50e_0e735e
                        (*(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
      if ((cVar6 == '\x04') && (uVar1 = Ram00fd58, (uVar1 & 0x80) == 0)) {
        cVar6 = UNK_00d5b6;
        if (cVar6 == '\0') {
          UNK_00d569 = 1;
        }
      }
      else {
        iVar3 = Ram00f676;
        uVar1 = iVar3 + 0x1c;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d5b6 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        UNK_00d569 = 0;
      }
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      cVar6 = egs52_compute_from_near_d50e_0e735e
                        (*(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
      if (cVar6 == '\x04') {
        UNK_00d569 = 2;
      }
    }
  }
  else {
    cVar6 = UNK_00d569;
    if (cVar6 == '\x02') {
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar4 = Ram00d4fa;
      if (uVar4 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        UNK_00d569 = 1;
        return;
      }
    }
    else {
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar4 = Ram00d4fa;
      if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar4) {
        cVar6 = UNK_00d5b6;
        if (cVar6 == '\0') {
          UNK_00d569 = 1;
        }
      }
      else {
        iVar3 = Ram00f676;
        uVar1 = iVar3 + 0x1c;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d5b6 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        UNK_00d569 = 0;
      }
      iVar3 = Ram00f678;
      uVar1 = iVar3 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar4 = Ram00d4fa;
      if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar4) {
        UNK_00d569 = 2;
        return;
      }
    }
  }
  return;
}


