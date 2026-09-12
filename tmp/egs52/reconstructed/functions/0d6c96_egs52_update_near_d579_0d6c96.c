/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6c96; FLS offset 0x056c96.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6e0e) */
/* WARNING: Removing unreachable block (ram,0x0d6e04) */
/* WARNING: Removing unreachable block (ram,0x0d6e00) */
/* WARNING: Removing unreachable block (ram,0x0d6dfa) */
/* WARNING: Removing unreachable block (ram,0x0d6df6) */
/* WARNING: Removing unreachable block (ram,0x0d6dec) */
/* WARNING: Removing unreachable block (ram,0x0d6ddc) */
/* WARNING: Removing unreachable block (ram,0x0d6dd4) */
/* WARNING: Removing unreachable block (ram,0x0d6dc8) */
/* WARNING: Removing unreachable block (ram,0x0d6dc4) */
/* WARNING: Removing unreachable block (ram,0x0d6dbe) */
/* WARNING: Removing unreachable block (ram,0x0d6db6) */
/* WARNING: Removing unreachable block (ram,0x0d6db2) */
/* WARNING: Removing unreachable block (ram,0x0d6da8) */
/* WARNING: Removing unreachable block (ram,0x0d6d9a) */
/* WARNING: Removing unreachable block (ram,0x0d6d94) */
/* WARNING: Removing unreachable block (ram,0x0d6d84) */
/* WARNING: Removing unreachable block (ram,0x0d6d7a) */
/* WARNING: Removing unreachable block (ram,0x0d6d70) */
/* WARNING: Removing unreachable block (ram,0x0d6d62) */
/* WARNING: Removing unreachable block (ram,0x0d6d5c) */
/* WARNING: Removing unreachable block (ram,0x0d6d48) */
/* WARNING: Removing unreachable block (ram,0x0d6d44) */
/* WARNING: Removing unreachable block (ram,0x0d6d3c) */
/* WARNING: Removing unreachable block (ram,0x0d6d38) */
/* WARNING: Removing unreachable block (ram,0x0d6d34) */
/* WARNING: Removing unreachable block (ram,0x0d6d2e) */
/* WARNING: Removing unreachable block (ram,0x0d6d28) */
/* WARNING: Removing unreachable block (ram,0x0d6d24) */
/* WARNING: Removing unreachable block (ram,0x0d6d1e) */
/* WARNING: Removing unreachable block (ram,0x0d6d16) */
/* WARNING: Removing unreachable block (ram,0x0d6d12) */
/* WARNING: Removing unreachable block (ram,0x0d6d0a) */
/* WARNING: Removing unreachable block (ram,0x0d6d06) */
/* WARNING: Removing unreachable block (ram,0x0d6d02) */
/* WARNING: Removing unreachable block (ram,0x0d6cfc) */
/* WARNING: Removing unreachable block (ram,0x0d6cf8) */
/* WARNING: Removing unreachable block (ram,0x0d6cee) */
/* WARNING: Removing unreachable block (ram,0x0d6cde) */
/* WARNING: Removing unreachable block (ram,0x0d6cd8) */
/* WARNING: Removing unreachable block (ram,0x0d6cd4) */
/* WARNING: Removing unreachable block (ram,0x0d6cce) */
/* WARNING: Removing unreachable block (ram,0x0d6cc6) */
/* WARNING: Removing unreachable block (ram,0x0d6ca8) */
/* WARNING: Removing unreachable block (ram,0x0d6cc2) */
/* WARNING: Removing unreachable block (ram,0x0d6cbc) */
/* WARNING: Removing unreachable block (ram,0x0d6ca0) */
/* WARNING: Removing unreachable block (ram,0x0d6cb4) */
/* WARNING: Removing unreachable block (ram,0x0d6cae) */
/* WARNING: Removing unreachable block (ram,0x0d6d58) */
/* WARNING: Removing unreachable block (ram,0x0d6d88) */

void egs52_update_near_d579_0d6c96(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  byte bVar8;
  
  egs52_update_near_d490_0d6c72();
  bVar8 = UNK_00d577;
  if (bVar8 < 3) {
    cVar5 = UNK_00d454;
    UNK_00d579 = cVar5 + -1;
  }
  else {
    bVar8 = UNK_00d577;
    if (bVar8 < 5) {
      cVar5 = UNK_00d454;
      UNK_00d579 = cVar5 + '\x04';
    }
  }
  iVar4 = Ram00f622;
  bVar8 = UNK_00d579;
  uVar3 = iVar4 + 0xb + (uint)bVar8;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  UNK_00d477 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  bVar2 = UNK_00d477;
  bVar8 = UNK_00d454;
  iVar4 = Ram00f624;
  uVar3 = iVar4 + 0x26 + (uint)bVar2 * 2 + (uint)bVar8 * 0xc;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d46e = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  iVar4 = Ram00f624;
  uVar1 = iVar4 + (uint)bVar2 * 2 + 0x96;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d54a = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar6 = UNK_00d477;
  uVar7 = egs52_compute_from_near_f624_0d41e8(uVar6);
  Ram00d536 = uVar7;
  iVar4 = Ram00f622;
  bVar8 = UNK_00d579;
  uVar3 = iVar4 + 0x13 + (uint)bVar8;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  UNK_00d475 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  bVar8 = UNK_00d475;
  iVar4 = Ram00f624;
  uVar1 = iVar4 + (uint)bVar8 * 2 + 0x96;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d546 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar6 = UNK_00d475;
  uVar7 = egs52_compute_from_near_f624_0d41e8(uVar6);
  Ram00d532 = uVar7;
  cVar5 = UNK_00d577;
  if ((cVar5 == '\x02') || (cVar5 == '\x01')) {
    Ram00d47e = 0x7fff;
    bVar2 = UNK_00d475;
    bVar8 = UNK_00d454;
    iVar4 = Ram00f624;
    uVar3 = iVar4 + 0x1a + (uint)bVar2 * 2 + (uint)bVar8 * 0xc;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d46a = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  }
  else {
    Ram00d47e = 0x8000;
    cVar5 = UNK_00d577;
    if ((cVar5 == '\x04') || (cVar5 == '\x03')) {
      bVar2 = UNK_00d475;
      bVar8 = UNK_00d454;
      iVar4 = Ram00f624;
      uVar3 = iVar4 + 0x32 + (uint)bVar2 * 2 + (uint)bVar8 * 0xc;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      Ram00d46a = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    }
  }
  bVar8 = UNK_00d579;
  iVar4 = Ram00f622;
  iVar4 = iVar4 + (uint)bVar8 * 2;
  uVar1 = iVar4 + 0x1a;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar8 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar4 + 0x1b;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar2 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  if (bVar8 <= bVar2) {
    bVar8 = bVar2;
  }
  UNK_00d476 = bVar8;
  bVar2 = UNK_00d454;
  iVar4 = Ram00f624;
  uVar3 = iVar4 + 0x26 + (uint)bVar8 * 2 + (uint)bVar2 * 0xc;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d46c = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  iVar4 = Ram00f624;
  uVar1 = iVar4 + (uint)bVar8 * 2 + 0x96;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d548 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar7 = egs52_compute_from_near_f624_0d41e8(bVar8);
  Ram00d534 = uVar7;
  return;
}


