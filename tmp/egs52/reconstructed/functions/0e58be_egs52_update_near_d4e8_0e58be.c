/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e58be; FLS offset 0x0658be.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e5ad6) */
/* WARNING: Removing unreachable block (ram,0x0e5ad2) */
/* WARNING: Removing unreachable block (ram,0x0e5ace) */
/* WARNING: Removing unreachable block (ram,0x0e5940) */
/* WARNING: Removing unreachable block (ram,0x0e5934) */
/* WARNING: Removing unreachable block (ram,0x0e5928) */
/* WARNING: Removing unreachable block (ram,0x0e591c) */
/* WARNING: Removing unreachable block (ram,0x0e5918) */
/* WARNING: Removing unreachable block (ram,0x0e5912) */
/* WARNING: Removing unreachable block (ram,0x0e5ac6) */
/* WARNING: Removing unreachable block (ram,0x0e5ac2) */
/* WARNING: Removing unreachable block (ram,0x0e5aaa) */
/* WARNING: Removing unreachable block (ram,0x0e5a8e) */
/* WARNING: Removing unreachable block (ram,0x0e5a9c) */
/* WARNING: Removing unreachable block (ram,0x0e5a7e) */
/* WARNING: Removing unreachable block (ram,0x0e5a7a) */
/* WARNING: Removing unreachable block (ram,0x0e5a6a) */
/* WARNING: Removing unreachable block (ram,0x0e5a66) */
/* WARNING: Removing unreachable block (ram,0x0e5a5e) */
/* WARNING: Removing unreachable block (ram,0x0e5a58) */
/* WARNING: Removing unreachable block (ram,0x0e5a54) */
/* WARNING: Removing unreachable block (ram,0x0e5a44) */
/* WARNING: Removing unreachable block (ram,0x0e5a3c) */
/* WARNING: Removing unreachable block (ram,0x0e5a38) */
/* WARNING: Removing unreachable block (ram,0x0e5a34) */
/* WARNING: Removing unreachable block (ram,0x0e5a30) */
/* WARNING: Removing unreachable block (ram,0x0e5a2c) */
/* WARNING: Removing unreachable block (ram,0x0e5a1a) */
/* WARNING: Removing unreachable block (ram,0x0e5a12) */
/* WARNING: Removing unreachable block (ram,0x0e59ee) */
/* WARNING: Removing unreachable block (ram,0x0e5a04) */
/* WARNING: Removing unreachable block (ram,0x0e5a00) */
/* WARNING: Removing unreachable block (ram,0x0e59fc) */
/* WARNING: Removing unreachable block (ram,0x0e59e0) */
/* WARNING: Removing unreachable block (ram,0x0e59da) */
/* WARNING: Removing unreachable block (ram,0x0e59d6) */
/* WARNING: Removing unreachable block (ram,0x0e59ca) */
/* WARNING: Removing unreachable block (ram,0x0e59c4) */
/* WARNING: Removing unreachable block (ram,0x0e59b6) */
/* WARNING: Removing unreachable block (ram,0x0e59b2) */
/* WARNING: Removing unreachable block (ram,0x0e59ae) */
/* WARNING: Removing unreachable block (ram,0x0e59aa) */
/* WARNING: Removing unreachable block (ram,0x0e59a6) */
/* WARNING: Removing unreachable block (ram,0x0e5968) */
/* WARNING: Removing unreachable block (ram,0x0e597e) */
/* WARNING: Removing unreachable block (ram,0x0e597a) */
/* WARNING: Removing unreachable block (ram,0x0e5976) */
/* WARNING: Removing unreachable block (ram,0x0e595a) */
/* WARNING: Removing unreachable block (ram,0x0e5994) */
/* WARNING: Removing unreachable block (ram,0x0e5990) */
/* WARNING: Removing unreachable block (ram,0x0e598c) */
/* WARNING: Removing unreachable block (ram,0x0e594c) */
/* WARNING: Removing unreachable block (ram,0x0e5900) */
/* WARNING: Removing unreachable block (ram,0x0e58fc) */
/* WARNING: Removing unreachable block (ram,0x0e58f8) */
/* WARNING: Removing unreachable block (ram,0x0e58f4) */
/* WARNING: Removing unreachable block (ram,0x0e58e4) */
/* WARNING: Removing unreachable block (ram,0x0e58e0) */
/* WARNING: Removing unreachable block (ram,0x0e58dc) */
/* WARNING: Removing unreachable block (ram,0x0e58d0) */
/* WARNING: Removing unreachable block (ram,0x0e58c4) */
/* WARNING: Removing unreachable block (ram,0x0e5948) */
/* WARNING: Removing unreachable block (ram,0x0e5a16) */
/* WARNING: Removing unreachable block (ram,0x0e5abc) */

void egs52_update_near_d4e8_0e58be(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  char cVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  
  cVar9 = '\0';
  uVar1 = Ram00fd56;
  if (((((uVar1 & 8) != 0) && (uVar1 = Ram00fd60, (uVar1 & 8) == 0)) &&
      (uVar1 = Ram00d3b8, (uVar1 & 1) == 0)) && (uVar1 = Ram00fd62, (uVar1 & 1) == 0)) {
    iVar10 = Ram00f67a;
    uVar1 = iVar10 + 0x1e;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d4fa;
    uVar6 = Ram00d4fa;
    if ((uVar1 == uVar6 || uVar1 < uVar2) && (uVar1 = Ram00fd58, (uVar1 & 0x80) == 0)) {
      cVar9 = -1;
    }
  }
  uVar1 = Ram00fd62;
  Ram00fd62 = uVar1 & 0xfffb;
  uVar3 = Ram00d3c2;
  Ram00d4e8 = uVar3;
  uVar3 = Ram00d3c4;
  Ram00d4f0 = uVar3;
  cVar7 = egs52_match_fault_status_mask(0xb,1);
  if (cVar7 == '\x01') {
    uVar1 = Ram00fd62;
    Ram00fd62 = uVar1 | 4;
    iVar10 = Ram00f67a;
    uVar2 = iVar10 + 6;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d4e6 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d4ec = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar8 = egs52_update_fault_status(0xc,0);
    UNK_00d433 = uVar8;
    uVar8 = egs52_update_fault_status(0xd,0);
    UNK_00d433 = uVar8;
    uVar8 = egs52_update_fault_status(0xe,0);
    UNK_00d433 = uVar8;
    goto LAB_0e5aca;
  }
  iVar10 = Ram00f67a;
  uVar1 = iVar10 + 4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) == 0) || (cVar9 != -1)) {
    uVar8 = egs52_update_fault_status(0xc,0);
    UNK_00d433 = uVar8;
    uVar3 = Ram00d4e8;
    Ram00d4e6 = uVar3;
  }
  else {
    iVar10 = Ram00d4e8;
    if (iVar10 == 0) {
      uVar8 = egs52_update_fault_status(0xc,3);
      UNK_00d433 = uVar8;
    }
    else {
      uVar8 = egs52_update_fault_status(0xc,2);
      UNK_00d433 = uVar8;
      uVar3 = Ram00d4e8;
      Ram00d4e6 = uVar3;
    }
  }
  cVar7 = egs52_match_fault_status_mask(0xc,1);
  if (cVar7 == '\x01') {
    uVar1 = Ram00fd62;
    Ram00fd62 = uVar1 | 4;
    iVar10 = Ram00f67a;
    uVar1 = iVar10 + 6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d4e6 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar10 = Ram00f67a;
  uVar1 = iVar10 + 4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) == 0) || (cVar9 != -1)) ||
     ((cVar7 = UNK_00d577, cVar7 != '\0' ||
      ((cVar7 = UNK_00d449, cVar7 != '\x03' && (cVar7 != '\x04')))))) {
LAB_0e5a0a:
    uVar8 = egs52_update_fault_status(0xd,0);
    UNK_00d433 = uVar8;
    uVar3 = Ram00d4f0;
    Ram00d4ec = uVar3;
  }
  else {
    cVar7 = UNK_00d449;
    cVar5 = UNK_00d454;
    if (cVar7 != cVar5) goto LAB_0e5a0a;
    iVar10 = Ram00d4f0;
    if (iVar10 == 0) {
      uVar8 = egs52_update_fault_status(0xd,3);
      UNK_00d433 = uVar8;
    }
    else {
      uVar8 = egs52_update_fault_status(0xd,2);
      UNK_00d433 = uVar8;
      uVar3 = Ram00d4f0;
      Ram00d4ec = uVar3;
    }
  }
  cVar7 = egs52_match_fault_status_mask(0xd,1);
  if (cVar7 == '\x01') {
    uVar1 = Ram00fd62;
    Ram00fd62 = uVar1 | 4;
    iVar10 = Ram00f67a;
    uVar1 = iVar10 + 6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d4ec = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar10 = Ram00f67a;
  uVar1 = iVar10 + 4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x10) == 0) ||
      (cVar7 = UNK_00d577, cVar7 != '\0')) ||
     ((cVar9 != -1 || (uVar1 = Ram00fd3a, (uVar1 & 1) != 0)))) {
LAB_0e5aa2:
    uVar8 = egs52_update_fault_status(0xe,0);
    UNK_00d433 = uVar8;
  }
  else {
    uVar1 = iVar10 + 0x10;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar6 = Ram00d4f0;
    if ((uVar6 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) ||
       (iVar10 = Ram00d4e8, iVar10 == 0)) goto LAB_0e5aa2;
    iVar10 = Ram00d3c2;
    iVar4 = Ram00d3c4;
    iVar10 = iVar10 - iVar4;
    if (iVar10 < 0) {
      iVar10 = -iVar10;
    }
    iVar4 = Ram00f67a;
    uVar1 = iVar4 + 0x12;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (iVar10 < *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      uVar8 = egs52_update_fault_status(0xe,2);
      UNK_00d433 = uVar8;
    }
    else {
      uVar8 = egs52_update_fault_status(0xe,3);
      UNK_00d433 = uVar8;
    }
  }
  cVar9 = egs52_match_fault_status_mask(0xe,1);
  if (cVar9 == '\x01') {
    uVar1 = Ram00fd62;
    Ram00fd62 = uVar1 | 4;
    iVar10 = Ram00f67a;
    uVar2 = iVar10 + 6;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d4e6 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d4ec = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
LAB_0e5aca:
  uVar1 = Ram00fd62;
  if ((uVar1 & 4) != 0) {
    iVar10 = Ram00f67a;
    uVar1 = iVar10 + 6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d524 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  return;
}


