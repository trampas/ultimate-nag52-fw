/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d40fe; FLS offset 0x0540fe.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4190) */
/* WARNING: Removing unreachable block (ram,0x0d4180) */
/* WARNING: Removing unreachable block (ram,0x0d4172) */
/* WARNING: Removing unreachable block (ram,0x0d416e) */
/* WARNING: Removing unreachable block (ram,0x0d4166) */
/* WARNING: Removing unreachable block (ram,0x0d41ce) */
/* WARNING: Removing unreachable block (ram,0x0d41c8) */
/* WARNING: Removing unreachable block (ram,0x0d41b8) */
/* WARNING: Removing unreachable block (ram,0x0d41b4) */
/* WARNING: Removing unreachable block (ram,0x0d41c4) */
/* WARNING: Removing unreachable block (ram,0x0d41c0) */
/* WARNING: Removing unreachable block (ram,0x0d41a6) */
/* WARNING: Removing unreachable block (ram,0x0d4158) */
/* WARNING: Removing unreachable block (ram,0x0d4152) */
/* WARNING: Removing unreachable block (ram,0x0d414a) */
/* WARNING: Removing unreachable block (ram,0x0d4144) */
/* WARNING: Removing unreachable block (ram,0x0d41e2) */
/* WARNING: Removing unreachable block (ram,0x0d413a) */
/* WARNING: Removing unreachable block (ram,0x0d4136) */
/* WARNING: Removing unreachable block (ram,0x0d412e) */
/* WARNING: Removing unreachable block (ram,0x0d4120) */
/* WARNING: Removing unreachable block (ram,0x0d411c) */
/* WARNING: Removing unreachable block (ram,0x0d4118) */
/* WARNING: Removing unreachable block (ram,0x0d4114) */
/* WARNING: Removing unreachable block (ram,0x0d40fe) */
/* WARNING: Removing unreachable block (ram,0x0d4110) */
/* WARNING: Removing unreachable block (ram,0x0d414e) */
/* WARNING: Removing unreachable block (ram,0x0d4186) */
/* WARNING: Removing unreachable block (ram,0x0d419c) */
/* WARNING: Removing unreachable block (ram,0x0d41a0) */
/* WARNING: Removing unreachable block (ram,0x0d41d4) */
/* WARNING: Removing unreachable block (ram,0x0d41da) */
/* WARNING: Removing unreachable block (ram,0x0d4196) */

void egs52_update_near_d5b0_0d40fe(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  byte bVar6;
  byte bVar7;
  
  cVar3 = UNK_00d566;
  if (cVar3 == '\0') {
    iVar5 = Ram00f648;
    uVar1 = iVar5 + 0x2a;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar3 = UNK_00d566;
    UNK_00d566 = cVar3 + '\x01';
  }
  else if (cVar3 != '\x01') {
    if (cVar3 != '\x02') {
      return;
    }
    cVar3 = UNK_00d44b;
    if ((cVar3 == 'X') || (cVar3 == '\0')) {
      cVar3 = UNK_00d5b0;
      if (cVar3 != '\0') {
        return;
      }
      UNK_00d566 = 0;
      cVar3 = UNK_00d44b;
      if (cVar3 == '\0') {
        egs52_update_near_d566_0d3638();
        return;
      }
      UNK_00d437 = 3;
      return;
    }
    cVar3 = UNK_00d44b;
    if (cVar3 == -1) {
      UNK_00d566 = 0;
      UNK_00d437 = 3;
      return;
    }
    bVar7 = UNK_00d44b;
    bVar6 = UNK_00d44a;
    if (bVar7 == bVar6) {
      cVar3 = UNK_00d5b0;
      if (cVar3 != '\0') {
        return;
      }
      if ((bVar7 == 0) || (7 < bVar7)) {
        UNK_00d454 = 3;
        UNK_00d453 = 3;
      }
      else {
        UNK_00d454 = bVar7;
        UNK_00d453 = bVar7;
      }
      UNK_00d566 = 0;
      UNK_00d437 = 2;
      return;
    }
    UNK_00d566 = 0;
    UNK_00d437 = 3;
    return;
  }
  cVar3 = UNK_00d44b;
  if ((cVar3 != 'X') && (cVar3 != '\0')) {
    uVar4 = UNK_00d44b;
    UNK_00d44a = uVar4;
    cVar3 = UNK_00d566;
    UNK_00d566 = cVar3 + '\x01';
    return;
  }
  cVar3 = UNK_00d5b0;
  if (cVar3 == '\0') {
    UNK_00d566 = 0;
    cVar3 = UNK_00d44b;
    if (cVar3 != '\0') {
      UNK_00d437 = 3;
      return;
    }
    UNK_00d437 = 2;
  }
  return;
}


