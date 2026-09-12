/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7be2; FLS offset 0x057be2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7bf6) */
/* WARNING: Removing unreachable block (ram,0x0d7c42) */
/* WARNING: Removing unreachable block (ram,0x0d7c38) */
/* WARNING: Removing unreachable block (ram,0x0d7c34) */
/* WARNING: Removing unreachable block (ram,0x0d7c30) */
/* WARNING: Removing unreachable block (ram,0x0d7c28) */
/* WARNING: Removing unreachable block (ram,0x0d7c22) */
/* WARNING: Removing unreachable block (ram,0x0d7c1e) */
/* WARNING: Removing unreachable block (ram,0x0d7c16) */
/* WARNING: Removing unreachable block (ram,0x0d7c0e) */
/* WARNING: Removing unreachable block (ram,0x0d7c0a) */
/* WARNING: Removing unreachable block (ram,0x0d7bee) */
/* WARNING: Removing unreachable block (ram,0x0d7bea) */
/* WARNING: Removing unreachable block (ram,0x0d7be2) */
/* WARNING: Removing unreachable block (ram,0x0d7c06) */
/* WARNING: Removing unreachable block (ram,0x0d7bfa) */

int egs52_update_near_d3fc_0d7be2(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  short old;
  byte bVar5;
  int iVar6;
  short sVar7;
  
  cVar4 = UNK_00d579;
  if (cVar4 == '\x01') {
    iVar3 = Ram00f634;
    uVar1 = iVar3 + 0x3d;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x80) != 0) {
      Ram00d3fc = 0;
      Ram00d400 = 0;
      return 0;
    }
  }
  iVar6 = Ram00d508;
  iVar3 = Ram00d506;
  bVar5 = UNK_00d468;
  sVar7 = (short)(((long)(iVar6 - iVar3) * (long)(int)(uint)bVar5) / 0x14);
  Ram00d3fc = sVar7;
  iVar3 = Ram00f634;
  uVar1 = iVar3 + 0x3e;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  old = Ram00d400;
  sVar7 = egs52_weighted_average_s16
                    (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),sVar7,old);
  Ram00d400 = sVar7;
  iVar3 = Ram00f634;
  uVar1 = iVar3 + 0x3d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar3 = Ram00d400;
  return (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x7f) * iVar3;
}


