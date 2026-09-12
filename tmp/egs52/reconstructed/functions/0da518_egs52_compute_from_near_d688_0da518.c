/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da518; FLS offset 0x05a518.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da5d8) */
/* WARNING: Removing unreachable block (ram,0x0da5d4) */
/* WARNING: Removing unreachable block (ram,0x0da5c8) */
/* WARNING: Removing unreachable block (ram,0x0da5b8) */
/* WARNING: Removing unreachable block (ram,0x0da588) */
/* WARNING: Removing unreachable block (ram,0x0da584) */
/* WARNING: Removing unreachable block (ram,0x0da57a) */
/* WARNING: Removing unreachable block (ram,0x0da56e) */
/* WARNING: Removing unreachable block (ram,0x0da56a) */
/* WARNING: Removing unreachable block (ram,0x0da560) */
/* WARNING: Removing unreachable block (ram,0x0da55c) */
/* WARNING: Removing unreachable block (ram,0x0da550) */
/* WARNING: Removing unreachable block (ram,0x0da54c) */
/* WARNING: Removing unreachable block (ram,0x0da546) */
/* WARNING: Removing unreachable block (ram,0x0da538) */
/* WARNING: Removing unreachable block (ram,0x0da534) */
/* WARNING: Removing unreachable block (ram,0x0da52e) */
/* WARNING: Removing unreachable block (ram,0x0da528) */
/* WARNING: Removing unreachable block (ram,0x0da540) */
/* WARNING: Removing unreachable block (ram,0x0da576) */
/* WARNING: Removing unreachable block (ram,0x0da5c0) */

undefined2 egs52_compute_from_near_d688_0da518(char param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if ((param_1 == '\x01') || (param_1 == '\x03')) {
    bVar3 = UNK_00d688;
    iVar6 = Ram00f652;
    uVar4 = iVar6 + (uint)bVar3 * 2 + 0x24;
    uVar7 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar7 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar6 = Ram00d65e;
    iVar6 = iVar6 - *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar4 & 0x3fff));
  }
  else {
    bVar3 = UNK_00d688;
    iVar6 = Ram00f652;
    uVar4 = iVar6 + (uint)bVar3 * 2 + 0x26;
    uVar7 = 0x24;
    if (((uVar4 & 0xc000) != 0) &&
       ((uVar7 = 0x21, (uVar4 & 0xc000) != 0x4000 && (uVar7 = 0x2c, (uVar4 & 0xc000) != 0x8000)))) {
      uVar7 = 3;
    }
    iVar6 = Ram00d65e;
    iVar6 = *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar4 & 0x3fff)) - iVar6;
  }
  if ((param_1 == '\x01') || (param_1 == '\x02')) {
    bVar3 = UNK_00d689;
    iVar5 = Ram00f652;
    uVar7 = iVar5 + 0x3d + (uint)bVar3;
    uVar4 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar4 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar3 = UNK_00d649;
    iVar5 = (uint)bVar3 - (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar7 & 0x3fff));
  }
  else {
    bVar3 = UNK_00d689;
    iVar5 = Ram00f652;
    uVar7 = iVar5 + 0x3e + (uint)bVar3;
    uVar4 = 0x24;
    if (((uVar7 & 0xc000) != 0) &&
       ((uVar4 = 0x21, (uVar7 & 0xc000) != 0x4000 && (uVar4 = 0x2c, (uVar7 & 0xc000) != 0x8000)))) {
      uVar4 = 3;
    }
    bVar3 = UNK_00d649;
    iVar5 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar7 & 0x3fff)) - (uint)bVar3;
  }
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  uVar4 = egs52_call_0df36e_0da5f2(iVar6,iVar5,param_2);
  iVar6 = Ram00d690;
  if (iVar6 < 0) {
    iVar6 = Ram00d690;
    uVar7 = -iVar6;
  }
  else {
    uVar7 = Ram00d690;
  }
  iVar6 = Ram00f652;
  uVar1 = iVar6 + 0xbb;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  return (int)(((((ulong)uVar4 * (ulong)uVar7) / 100 & 0xffff) *
               (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 12000);
}


