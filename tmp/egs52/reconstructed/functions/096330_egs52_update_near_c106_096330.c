/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096330; FLS offset 0x016330.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096380) */
/* WARNING: Removing unreachable block (ram,0x09637a) */
/* WARNING: Removing unreachable block (ram,0x096376) */
/* WARNING: Removing unreachable block (ram,0x096370) */
/* WARNING: Removing unreachable block (ram,0x09636c) */
/* WARNING: Removing unreachable block (ram,0x096364) */
/* WARNING: Removing unreachable block (ram,0x096360) */
/* WARNING: Removing unreachable block (ram,0x09635e) */
/* WARNING: Removing unreachable block (ram,0x09635a) */
/* WARNING: Removing unreachable block (ram,0x09634e) */
/* WARNING: Removing unreachable block (ram,0x0963c4) */
/* WARNING: Removing unreachable block (ram,0x0963be) */
/* WARNING: Removing unreachable block (ram,0x0963ba) */
/* WARNING: Removing unreachable block (ram,0x0963b6) */
/* WARNING: Removing unreachable block (ram,0x0963b2) */
/* WARNING: Removing unreachable block (ram,0x0963ae) */
/* WARNING: Removing unreachable block (ram,0x0963aa) */
/* WARNING: Removing unreachable block (ram,0x0963a6) */
/* WARNING: Removing unreachable block (ram,0x0963a2) */
/* WARNING: Removing unreachable block (ram,0x0963a0) */
/* WARNING: Removing unreachable block (ram,0x09639c) */
/* WARNING: Removing unreachable block (ram,0x09638e) */
/* WARNING: Removing unreachable block (ram,0x0963de) */
/* WARNING: Removing unreachable block (ram,0x0963d0) */
/* WARNING: Removing unreachable block (ram,0x0963cc) */
/* WARNING: Removing unreachable block (ram,0x09645e) */
/* WARNING: Removing unreachable block (ram,0x096334) */
/* WARNING: Removing unreachable block (ram,0x09638a) */
/* WARNING: Removing unreachable block (ram,0x096352) */

undefined1 egs52_update_near_c106_096330(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  char cVar6;
  undefined1 uVar7;
  
  uVar7 = 0;
  cVar6 = UNK_00c108;
  if (cVar6 == '\0') {
    uVar4 = Ram00fdf2;
    Ram00c106 = uVar4;
    uVar1 = 0x24;
    if ((((uRam0904e2 & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904e2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam0904e2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uRam0904e2 & 0x3fff)) = 500;
    uVar1 = uRam0904e2 + 4;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 500;
    uVar1 = uRam0904e2 + 8;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0x7f7f;
    uVar1 = uRam0904e2 + 0xe;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 7;
    UNK_00c108 = 1;
    uVar7 = 0;
  }
  else if (cVar6 == '\x01') {
    iVar5 = Ram00fdf2;
    iVar3 = Ram00c106;
    if (399 < (uint)(iVar5 - iVar3)) {
      uVar1 = 0x24;
      if ((((uRam0904e2 & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904e2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam0904e2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uRam0904e2 & 0x3fff)) = 0;
      uVar1 = uRam0904e2 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
      uVar1 = uRam0904e2 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
      uVar1 = uRam0904e2 + 0xe;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
      uVar4 = Ram00fdf2;
      Ram00c106 = uVar4;
      UNK_00c108 = 2;
    }
  }
  else if (cVar6 == '\x02') {
    iVar5 = Ram00fdf2;
    iVar3 = Ram00c106;
    if (399 < (uint)(iVar5 - iVar3)) {
      UNK_00c108 = 3;
    }
  }
  else if (cVar6 == '\x03') {
    cVar6 = egs52_match_fault_status_mask(2,1);
    if (((cVar6 == '\0') && (cVar6 = egs52_match_fault_status_mask(3,1), cVar6 == '\0')) &&
       (((cVar6 = egs52_match_fault_status_mask(4,1), cVar6 == '\0' &&
         ((((cVar6 = egs52_match_fault_status_mask(0x47,1), cVar6 == '\0' &&
            (cVar6 = egs52_match_fault_status_mask(0x48,1), cVar6 == '\0')) &&
           (cVar6 = egs52_match_fault_status_mask(0x49,1), cVar6 == '\0')) &&
          ((cVar6 = egs52_match_fault_status_mask(5,1), cVar6 == '\0' &&
           (cVar6 = egs52_match_fault_status_mask(6,1), cVar6 == '\0')))))) &&
        (cVar6 = egs52_match_fault_status_mask(7,1), cVar6 == '\0')))) {
      uVar7 = 2;
    }
    else {
      uVar7 = 1;
    }
    UNK_00c108 = 0;
  }
  return uVar7;
}


