/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6e1a; FLS offset 0x056e1a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6e8c) */
/* WARNING: Removing unreachable block (ram,0x0d6e88) */
/* WARNING: Removing unreachable block (ram,0x0d6e84) */
/* WARNING: Removing unreachable block (ram,0x0d6e80) */
/* WARNING: Removing unreachable block (ram,0x0d6e7c) */
/* WARNING: Removing unreachable block (ram,0x0d6e78) */
/* WARNING: Removing unreachable block (ram,0x0d6e74) */
/* WARNING: Removing unreachable block (ram,0x0d6e70) */
/* WARNING: Removing unreachable block (ram,0x0d6e6c) */
/* WARNING: Removing unreachable block (ram,0x0d6e64) */
/* WARNING: Removing unreachable block (ram,0x0d6e60) */
/* WARNING: Removing unreachable block (ram,0x0d6e5c) */
/* WARNING: Removing unreachable block (ram,0x0d6e56) */
/* WARNING: Removing unreachable block (ram,0x0d6e52) */
/* WARNING: Removing unreachable block (ram,0x0d6e48) */
/* WARNING: Removing unreachable block (ram,0x0d6e38) */
/* WARNING: Removing unreachable block (ram,0x0d6e32) */
/* WARNING: Removing unreachable block (ram,0x0d6e2e) */
/* WARNING: Removing unreachable block (ram,0x0d6e28) */
/* WARNING: Removing unreachable block (ram,0x0d6e20) */

void egs52_update_near_d477_0d6e1a(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  
  egs52_update_near_d490_0d6c72();
  iVar3 = Ram00f624;
  bVar4 = UNK_00d454;
  uVar2 = iVar3 + 0xaa + (uint)bVar4;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  UNK_00d477 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  bVar5 = UNK_00d477;
  bVar4 = UNK_00d454;
  iVar3 = Ram00f624;
  uVar2 = iVar3 + 0x26 + (uint)bVar5 * 2 + (uint)bVar4 * 0xc;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d46e = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  iVar3 = Ram00f624;
  uVar1 = iVar3 + (uint)bVar5 * 2 + 0x96;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d54a = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar6 = UNK_00d477;
  uVar7 = egs52_compute_from_near_f624_0d41e8(uVar6);
  Ram00d536 = uVar7;
  UNK_00d475 = 0xff;
  Ram00d46a = 0;
  Ram00d546 = 0;
  Ram00d532 = 0;
  UNK_00d476 = 0xff;
  Ram00d46c = 0;
  Ram00d548 = 0;
  Ram00d534 = 0;
  return;
}


