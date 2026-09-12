/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0db40a; FLS offset 0x05b40a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0db4f8) */
/* WARNING: Removing unreachable block (ram,0x0db4f4) */
/* WARNING: Removing unreachable block (ram,0x0db4f0) */
/* WARNING: Removing unreachable block (ram,0x0db4dc) */
/* WARNING: Removing unreachable block (ram,0x0db4d6) */
/* WARNING: Removing unreachable block (ram,0x0db4ca) */
/* WARNING: Removing unreachable block (ram,0x0db4c6) */
/* WARNING: Removing unreachable block (ram,0x0db4be) */
/* WARNING: Removing unreachable block (ram,0x0db4ba) */
/* WARNING: Removing unreachable block (ram,0x0db4b6) */
/* WARNING: Removing unreachable block (ram,0x0db4b4) */
/* WARNING: Removing unreachable block (ram,0x0db4a4) */
/* WARNING: Removing unreachable block (ram,0x0db49e) */
/* WARNING: Removing unreachable block (ram,0x0db496) */
/* WARNING: Removing unreachable block (ram,0x0db492) */
/* WARNING: Removing unreachable block (ram,0x0db48e) */
/* WARNING: Removing unreachable block (ram,0x0db48a) */
/* WARNING: Removing unreachable block (ram,0x0db486) */
/* WARNING: Removing unreachable block (ram,0x0db478) */
/* WARNING: Removing unreachable block (ram,0x0db474) */
/* WARNING: Removing unreachable block (ram,0x0db470) */
/* WARNING: Removing unreachable block (ram,0x0db464) */
/* WARNING: Removing unreachable block (ram,0x0db458) */
/* WARNING: Removing unreachable block (ram,0x0db44a) */
/* WARNING: Removing unreachable block (ram,0x0db432) */
/* WARNING: Removing unreachable block (ram,0x0db426) */
/* WARNING: Removing unreachable block (ram,0x0db41a) */
/* WARNING: Removing unreachable block (ram,0x0db412) */
/* WARNING: Removing unreachable block (ram,0x0db422) */
/* WARNING: Removing unreachable block (ram,0x0db444) */
/* WARNING: Removing unreachable block (ram,0x0db44e) */
/* WARNING: Removing unreachable block (ram,0x0db46c) */

void egs52_update_near_d67e_0db40a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  undefined1 uVar7;
  int iVar8;
  
  iVar8 = Ram00d6a8;
  if (iVar8 < 0) {
    iVar8 = Ram00d6a8;
    iVar8 = -iVar8;
  }
  else {
    iVar8 = Ram00d6a8;
  }
  iVar5 = Ram00d69e;
  Ram00d67e = (int)(((long)iVar8 * (long)iVar5) / 10);
  bVar6 = 0;
  while( true ) {
    iVar8 = Ram00f652;
    uVar1 = iVar8 + (uint)bVar6 * 2 + 0x8a;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar8 = Ram00d67e;
    if ((iVar8 <= *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) || (4 < bVar6)) break;
    bVar6 = bVar6 + 1;
  }
  iVar8 = Ram00f652;
  uVar3 = iVar8 + 0x84 + (uint)bVar6;
  uVar1 = 0x24;
  if (((uVar3 & 0xc000) != 0) &&
     ((uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)))) {
    uVar1 = 3;
  }
  uVar1 = (uint)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  uVar3 = Ram00d674;
  Ram00d674 = uVar3 + uVar1;
  iVar8 = Ram00d676;
  Ram00d676 = iVar8 + ((int)uVar1 >> 0xf) + (uint)CARRY2(uVar3,uVar1);
  iVar8 = Ram00d676;
  if ((iVar8 < 0) || (uVar1 = Ram00fd2a, (uVar1 & 1) == 0)) {
    Ram00d674 = 0;
    Ram00d676 = 0;
  }
  uVar2 = Ram00d674;
  iVar8 = Ram00f652;
  uVar1 = iVar8 + 0x94;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar2) {
    iVar8 = Ram00f6fe;
    uVar3 = iVar8 + 3;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar6 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = (bVar6 & 0xf0) + (bVar6 & 0xf) + 1;
    Ram00d674 = 0;
    Ram00d676 = 0;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar8 = Ram00f652;
    uVar2 = iVar8 + 0xba;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) <
        (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xf)) {
      uVar7 = 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xf0;
    }
    else {
      uVar7 = 2;
    }
  }
  else {
    uVar7 = 2;
  }
  egs52_update_fault_status(0x35,uVar7);
  uVar2 = Ram00d674;
  iVar8 = Ram00f652;
  uVar1 = iVar8 + 0xbc;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar2) {
    uVar1 = Ram00fd2c;
    Ram00fd2c = uVar1 & 0xffdf;
  }
  return;
}


