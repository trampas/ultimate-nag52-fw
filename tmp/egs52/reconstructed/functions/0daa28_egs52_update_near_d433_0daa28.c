/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0daa28; FLS offset 0x05aa28.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0daad4) */
/* WARNING: Removing unreachable block (ram,0x0daad0) */
/* WARNING: Removing unreachable block (ram,0x0daac2) */
/* WARNING: Removing unreachable block (ram,0x0daae2) */
/* WARNING: Removing unreachable block (ram,0x0daade) */
/* WARNING: Removing unreachable block (ram,0x0daab6) */
/* WARNING: Removing unreachable block (ram,0x0daab0) */
/* WARNING: Removing unreachable block (ram,0x0daaac) */
/* WARNING: Removing unreachable block (ram,0x0daa90) */
/* WARNING: Removing unreachable block (ram,0x0daa8c) */
/* WARNING: Removing unreachable block (ram,0x0daa88) */
/* WARNING: Removing unreachable block (ram,0x0daa78) */
/* WARNING: Removing unreachable block (ram,0x0daa70) */
/* WARNING: Removing unreachable block (ram,0x0daa6a) */
/* WARNING: Removing unreachable block (ram,0x0daa62) */
/* WARNING: Removing unreachable block (ram,0x0daa5e) */
/* WARNING: Removing unreachable block (ram,0x0daa52) */
/* WARNING: Removing unreachable block (ram,0x0daa4a) */
/* WARNING: Removing unreachable block (ram,0x0daa44) */
/* WARNING: Removing unreachable block (ram,0x0daa5a) */
/* WARNING: Removing unreachable block (ram,0x0daa80) */
/* WARNING: Removing unreachable block (ram,0x0daada) */
/* WARNING: Removing unreachable block (ram,0x0daacc) */

void egs52_update_near_d433_0daa28(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  
  uVar1 = Ram00fd2a;
  if (((((uVar1 & 0x10) == 0) && (uVar1 = Ram00fd2a, (uVar1 & 0x20) == 0)) &&
      (uVar1 = Ram00fd2c, (uVar1 & 1) == 0)) &&
     ((cVar4 = egs52_match_fault_status_mask(0x34,1), cVar4 == '\0' &&
      (cVar4 = UNK_00d704, cVar4 == '\0')))) {
    iVar6 = Ram00d6be;
    if (iVar6 < 0) {
      iVar6 = Ram00d6be;
      iVar6 = -iVar6;
    }
    else {
      iVar6 = Ram00d6be;
    }
    iVar3 = Ram00f652;
    uVar1 = iVar3 + 0x98;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar6) &&
        (cVar4 = UNK_00d650, cVar4 == '\0')) && (uVar1 = Ram00fd2c, (uVar1 & 2) != 0)) {
      iVar6 = Ram00d69e;
      if (iVar6 < 0) {
        iVar6 = Ram00d69e;
        iVar6 = -iVar6;
      }
      else {
        iVar6 = Ram00d69e;
      }
      iVar3 = Ram00f652;
      uVar1 = iVar3 + 0x96;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (iVar6 < *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        uVar5 = 3;
      }
      else {
        uVar5 = 2;
      }
      goto LAB_0daaa2;
    }
  }
  uVar5 = 0;
LAB_0daaa2:
  uVar5 = egs52_update_fault_status(0x34,uVar5);
  UNK_00d433 = uVar5;
  cVar4 = UNK_00d647;
  if (((cVar4 == '\0') && (uVar1 = Ram00fd2c, (uVar1 & 2) != 0)) &&
     (uVar1 = Ram00fd2c, (uVar1 & 8) == 0)) {
    iVar6 = Ram00d6a4;
    if (iVar6 == 0) {
      uVar1 = Ram00fd2c;
      Ram00fd2c = uVar1 | 8;
    }
    else {
      iVar6 = Ram00f652;
      uVar1 = iVar6 + 0x7c;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d706 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
  else {
    iVar6 = Ram00f652;
    uVar1 = iVar6 + 0xb4;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6a4 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  return;
}


