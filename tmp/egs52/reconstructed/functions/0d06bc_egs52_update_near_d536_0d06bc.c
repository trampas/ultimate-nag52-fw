/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d06bc; FLS offset 0x0506bc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d071e) */
/* WARNING: Removing unreachable block (ram,0x0d070e) */
/* WARNING: Removing unreachable block (ram,0x0d0706) */
/* WARNING: Removing unreachable block (ram,0x0d0700) */
/* WARNING: Removing unreachable block (ram,0x0d06fc) */
/* WARNING: Removing unreachable block (ram,0x0d06f8) */
/* WARNING: Removing unreachable block (ram,0x0d06ec) */
/* WARNING: Removing unreachable block (ram,0x0d06ea) */
/* WARNING: Removing unreachable block (ram,0x0d06de) */
/* WARNING: Removing unreachable block (ram,0x0d06dc) */
/* WARNING: Removing unreachable block (ram,0x0d06d6) */
/* WARNING: Removing unreachable block (ram,0x0d06d2) */
/* WARNING: Removing unreachable block (ram,0x0d06ca) */
/* WARNING: Removing unreachable block (ram,0x0d06c6) */
/* WARNING: Removing unreachable block (ram,0x0d06be) */
/* WARNING: Removing unreachable block (ram,0x0d06e4) */

void egs52_update_near_d536_0d06bc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  undefined2 uVar9;
  
  uVar5 = UNK_00d477;
  uVar9 = egs52_compute_from_near_f624_0d41e8(uVar5);
  Ram00d536 = uVar9;
  uVar5 = UNK_00d475;
  uVar9 = egs52_compute_from_near_f624_0d41e8(uVar5);
  Ram00d532 = uVar9;
  iVar8 = Ram00f636;
  uVar4 = iVar8 + 2;
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = Ram00d4d2;
  if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) < uVar1) {
    uVar9 = Ram00d4d2;
  }
  else {
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar9 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
  }
  Ram00d49c = uVar9;
  egs52_update_near_d5f6_0d74a6();
  iVar8 = Ram00f626;
  uVar2 = iVar8 + 0x3a;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar6 = Ram00d54c;
  bVar7 = UNK_00d579;
  uVar1 = iVar8 + (uint)bVar7 * 2 + 0x3a;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d552 = (int)(((ulong)(uint)(iVar6 - *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)))
                    * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) / 1000);
  return;
}


