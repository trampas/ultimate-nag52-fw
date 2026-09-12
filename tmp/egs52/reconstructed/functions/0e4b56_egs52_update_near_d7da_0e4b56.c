/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e4b56; FLS offset 0x064b56.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4c3c) */
/* WARNING: Removing unreachable block (ram,0x0e4c38) */
/* WARNING: Removing unreachable block (ram,0x0e4c34) */
/* WARNING: Removing unreachable block (ram,0x0e4c30) */
/* WARNING: Removing unreachable block (ram,0x0e4c2c) */
/* WARNING: Removing unreachable block (ram,0x0e4bec) */
/* WARNING: Removing unreachable block (ram,0x0e4be4) */
/* WARNING: Removing unreachable block (ram,0x0e4bb4) */
/* WARNING: Removing unreachable block (ram,0x0e4ba6) */
/* WARNING: Removing unreachable block (ram,0x0e4ba2) */
/* WARNING: Removing unreachable block (ram,0x0e4bd2) */
/* WARNING: Removing unreachable block (ram,0x0e4bca) */
/* WARNING: Removing unreachable block (ram,0x0e4bdc) */
/* WARNING: Removing unreachable block (ram,0x0e4bc0) */
/* WARNING: Removing unreachable block (ram,0x0e4bbc) */
/* WARNING: Removing unreachable block (ram,0x0e4b8e) */
/* WARNING: Removing unreachable block (ram,0x0e4b56) */
/* WARNING: Removing unreachable block (ram,0x0e4b88) */
/* WARNING: Removing unreachable block (ram,0x0e4b98) */
/* WARNING: Removing unreachable block (ram,0x0e4b9c) */
/* WARNING: Removing unreachable block (ram,0x0e4bae) */

void egs52_update_near_d7da_0e4b56(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  char cVar7;
  
  bVar3 = UNK_00d2be;
  if (((((bVar3 & 1) == 0) || (cVar7 = egs52_match_fault_status_mask(0x25,5), cVar7 == '\x01')) ||
      (cVar7 = egs52_match_fault_status_mask(0x24,5), cVar7 == '\x01')) ||
     (cVar7 = egs52_match_fault_status_mask(0x53,5), cVar7 == '\x01')) {
    UNK_00d7da = 0;
  }
  else {
    cVar7 = UNK_00d2bf;
    if (cVar7 == -1) {
      iVar4 = Ram00f67a;
      uVar1 = iVar4 + 0x1c;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar5 = Ram00fdf2;
      iVar4 = Ram00fdf4;
      if (iVar4 == 0 &&
          (iVar4 != 0 || uVar5 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))) {
        UNK_00d7da = 0;
      }
      else {
        UNK_00d7da = 3;
      }
    }
    else {
      UNK_00d7da = 2;
      bVar3 = UNK_00d2bf;
      if (bVar3 < 0xd8) {
        cVar7 = UNK_00d2bf;
        UNK_00d5cd = cVar7 + '\n';
      }
      else {
        UNK_00d5cd = 0xe1;
      }
    }
  }
  uVar6 = UNK_00d7da;
  uVar6 = egs52_update_fault_status(0x2b,uVar6);
  UNK_00d433 = uVar6;
  uVar1 = Ram00fd60;
  Ram00fd60 = uVar1 & 0xfffb;
  cVar7 = egs52_match_fault_status_mask(0x25,1);
  if (((cVar7 == '\x01') || (cVar7 = egs52_match_fault_status_mask(0x24,1), cVar7 == '\x01')) ||
     ((cVar7 = egs52_match_fault_status_mask(0x2b,1), cVar7 == '\x01' ||
      (cVar7 = egs52_match_fault_status_mask(0x53,1), cVar7 == '\x01')))) {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 | 4;
    iVar4 = Ram00f67a;
    uVar1 = iVar4 + 10;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5cd = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar6 = UNK_00d5cd;
  UNK_00d3d5 = uVar6;
  return;
}


