/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8b4a; FLS offset 0x058b4a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8cea) */
/* WARNING: Removing unreachable block (ram,0x0d8ce2) */
/* WARNING: Removing unreachable block (ram,0x0d8cda) */
/* WARNING: Removing unreachable block (ram,0x0d8cd4) */
/* WARNING: Removing unreachable block (ram,0x0d8cd0) */
/* WARNING: Removing unreachable block (ram,0x0d8ccc) */
/* WARNING: Removing unreachable block (ram,0x0d8cc4) */
/* WARNING: Removing unreachable block (ram,0x0d8cbc) */
/* WARNING: Removing unreachable block (ram,0x0d8cb8) */
/* WARNING: Removing unreachable block (ram,0x0d8cb4) */
/* WARNING: Removing unreachable block (ram,0x0d8cae) */
/* WARNING: Removing unreachable block (ram,0x0d8ca8) */
/* WARNING: Removing unreachable block (ram,0x0d8c96) */
/* WARNING: Removing unreachable block (ram,0x0d8ca4) */
/* WARNING: Removing unreachable block (ram,0x0d8c90) */
/* WARNING: Removing unreachable block (ram,0x0d8c86) */
/* WARNING: Removing unreachable block (ram,0x0d8c7a) */
/* WARNING: Removing unreachable block (ram,0x0d8c6a) */
/* WARNING: Removing unreachable block (ram,0x0d8c62) */
/* WARNING: Removing unreachable block (ram,0x0d8c5e) */
/* WARNING: Removing unreachable block (ram,0x0d8c58) */
/* WARNING: Removing unreachable block (ram,0x0d8c50) */
/* WARNING: Removing unreachable block (ram,0x0d8c4c) */
/* WARNING: Removing unreachable block (ram,0x0d8c42) */
/* WARNING: Removing unreachable block (ram,0x0d8c2e) */
/* WARNING: Removing unreachable block (ram,0x0d8c28) */
/* WARNING: Removing unreachable block (ram,0x0d8c1e) */
/* WARNING: Removing unreachable block (ram,0x0d8c10) */
/* WARNING: Removing unreachable block (ram,0x0d8bfe) */
/* WARNING: Removing unreachable block (ram,0x0d8bfa) */
/* WARNING: Removing unreachable block (ram,0x0d8bf2) */
/* WARNING: Removing unreachable block (ram,0x0d8bee) */
/* WARNING: Removing unreachable block (ram,0x0d8bea) */
/* WARNING: Removing unreachable block (ram,0x0d8be4) */
/* WARNING: Removing unreachable block (ram,0x0d8bde) */
/* WARNING: Removing unreachable block (ram,0x0d8bda) */
/* WARNING: Removing unreachable block (ram,0x0d8bd4) */
/* WARNING: Removing unreachable block (ram,0x0d8bcc) */
/* WARNING: Removing unreachable block (ram,0x0d8bc8) */
/* WARNING: Removing unreachable block (ram,0x0d8bc0) */
/* WARNING: Removing unreachable block (ram,0x0d8bbc) */
/* WARNING: Removing unreachable block (ram,0x0d8bb8) */
/* WARNING: Removing unreachable block (ram,0x0d8bb2) */
/* WARNING: Removing unreachable block (ram,0x0d8bae) */
/* WARNING: Removing unreachable block (ram,0x0d8ba4) */
/* WARNING: Removing unreachable block (ram,0x0d8b94) */
/* WARNING: Removing unreachable block (ram,0x0d8b8e) */
/* WARNING: Removing unreachable block (ram,0x0d8b8a) */
/* WARNING: Removing unreachable block (ram,0x0d8b84) */
/* WARNING: Removing unreachable block (ram,0x0d8b7c) */
/* WARNING: Removing unreachable block (ram,0x0d8b72) */
/* WARNING: Removing unreachable block (ram,0x0d8b6c) */
/* WARNING: Removing unreachable block (ram,0x0d8b5a) */
/* WARNING: Removing unreachable block (ram,0x0d8b56) */
/* WARNING: Removing unreachable block (ram,0x0d8b66) */
/* WARNING: Removing unreachable block (ram,0x0d8b78) */
/* WARNING: Removing unreachable block (ram,0x0d8c0a) */
/* WARNING: Removing unreachable block (ram,0x0d8c34) */
/* WARNING: Removing unreachable block (ram,0x0d8ca0) */
/* WARNING: Removing unreachable block (ram,0x0d8c9a) */

void egs52_update_near_d47e_0d8b4a(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  byte bVar9;
  undefined1 uVar10;
  int iVar11;
  undefined2 uVar12;
  
  egs52_update_near_d490_0d6c72();
  Ram00d47e = 0;
  cVar8 = UNK_00d577;
  if ((cVar8 == '\x02') || (cVar8 == '\x01')) {
    cVar8 = UNK_00d454;
    UNK_00d579 = cVar8 + -1;
  }
  else {
    cVar8 = UNK_00d454;
    UNK_00d579 = cVar8 + '\x04';
  }
  iVar6 = Ram00f622;
  bVar3 = UNK_00d579;
  uVar5 = iVar6 + 0xb + (uint)bVar3;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  UNK_00d477 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  bVar4 = UNK_00d477;
  bVar3 = UNK_00d454;
  iVar6 = Ram00f624;
  uVar5 = iVar6 + 0x26 + (uint)bVar4 * 2 + (uint)bVar3 * 0xc;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d46e = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  iVar6 = Ram00f624;
  uVar1 = iVar6 + (uint)bVar4 * 2 + 0x96;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  Ram00d54a = *(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = UNK_00d477;
  uVar12 = egs52_compute_from_near_f624_0d41e8(uVar10);
  Ram00d536 = uVar12;
  iVar6 = Ram00f622;
  bVar3 = UNK_00d579;
  uVar5 = iVar6 + 0x13 + (uint)bVar3;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  UNK_00d475 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  bVar3 = UNK_00d475;
  iVar6 = Ram00f624;
  uVar1 = iVar6 + (uint)bVar3 * 2 + 0x96;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  Ram00d546 = *(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = UNK_00d475;
  uVar12 = egs52_compute_from_near_f624_0d41e8(uVar10);
  Ram00d532 = uVar12;
  cVar8 = UNK_00d577;
  if ((cVar8 == '\x02') || (cVar8 == '\x01')) {
    bVar4 = UNK_00d475;
    bVar3 = UNK_00d454;
    iVar6 = Ram00f624;
    uVar5 = iVar6 + 0x1a + (uint)bVar4 * 2 + (uint)bVar3 * 0xc;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d46a = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  }
  else {
    bVar4 = UNK_00d475;
    bVar3 = UNK_00d454;
    iVar6 = Ram00f624;
    uVar5 = iVar6 + 0x32 + (uint)bVar4 * 2 + (uint)bVar3 * 0xc;
    uVar1 = 0x24;
    if (((uVar5 & 0xc000) != 0) &&
       ((uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)))) {
      uVar1 = 3;
    }
    Ram00d46a = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  }
  bVar3 = UNK_00d579;
  iVar6 = Ram00f622;
  iVar6 = iVar6 + (uint)bVar3 * 2;
  uVar1 = iVar6 + 0x1a;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  bVar3 = *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0x1b;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  bVar4 = *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar9 = UNK_00d454;
  iVar6 = Ram00f624;
  uVar5 = iVar6 + 0x26 + (uint)bVar3 * 2 + (uint)bVar9 * 0xc;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  uVar7 = iVar6 + 0x26 + (uint)bVar4 * 2 + (uint)bVar9 * 0xc;
  uVar1 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff));
  if (uVar1 < uVar5) {
    UNK_00d476 = bVar3;
    Ram00d46c = uVar5;
  }
  else {
    UNK_00d476 = bVar4;
    Ram00d46c = uVar1;
  }
  bVar3 = UNK_00d476;
  iVar6 = Ram00f624;
  uVar1 = iVar6 + (uint)bVar3 * 2 + 0x96;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  Ram00d548 = *(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = UNK_00d476;
  uVar12 = egs52_compute_from_near_f624_0d41e8(uVar10);
  Ram00d534 = uVar12;
  iVar6 = Ram00f626;
  uVar1 = iVar6 + 0x3a;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  iVar11 = Ram00d54c;
  bVar3 = UNK_00d579;
  uVar7 = iVar6 + (uint)bVar3 * 2 + 0x3a;
  uVar2 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d552 = (int)(((ulong)(uint)(iVar11 - *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)))
                    * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff))) / 1000);
  return;
}


