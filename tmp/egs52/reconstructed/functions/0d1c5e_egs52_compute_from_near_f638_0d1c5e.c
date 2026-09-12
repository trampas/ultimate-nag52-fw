/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1c5e; FLS offset 0x051c5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1c90) */
/* WARNING: Removing unreachable block (ram,0x0d1c8c) */
/* WARNING: Removing unreachable block (ram,0x0d1c82) */
/* WARNING: Removing unreachable block (ram,0x0d1c7e) */
/* WARNING: Removing unreachable block (ram,0x0d1c76) */
/* WARNING: Removing unreachable block (ram,0x0d1c72) */
/* WARNING: Removing unreachable block (ram,0x0d1c6a) */
/* WARNING: Removing unreachable block (ram,0x0d1c62) */

undefined2 egs52_compute_from_near_f638_0d1c5e(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = Ram00f638;
  uVar2 = iVar3 + 0x14;
  uVar6 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  if (*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff)) == '\0') {
    uVar6 = 1;
  }
  else {
    uVar6 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar6 = (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  cVar4 = UNK_00d579;
  iVar3 = Ram00f63a;
  uVar2 = iVar3 + 2;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = egs52_update_near_d41a_0d6eb0
                    (cVar4 + -1,*(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)));
  iVar3 = Ram00f638;
  uVar2 = iVar3 + 0x11;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  return (int)(((ulong)uVar5 * (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) /
              (ulong)uVar6);
}


