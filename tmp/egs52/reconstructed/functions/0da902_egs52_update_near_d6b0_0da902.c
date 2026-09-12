/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da902; FLS offset 0x05a902.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da9b2) */
/* WARNING: Removing unreachable block (ram,0x0da9ac) */
/* WARNING: Removing unreachable block (ram,0x0da99e) */
/* WARNING: Removing unreachable block (ram,0x0da99a) */
/* WARNING: Removing unreachable block (ram,0x0da996) */
/* WARNING: Removing unreachable block (ram,0x0da95a) */
/* WARNING: Removing unreachable block (ram,0x0da952) */
/* WARNING: Removing unreachable block (ram,0x0da964) */
/* WARNING: Removing unreachable block (ram,0x0da94c) */
/* WARNING: Removing unreachable block (ram,0x0da948) */
/* WARNING: Removing unreachable block (ram,0x0da944) */
/* WARNING: Removing unreachable block (ram,0x0da93c) */
/* WARNING: Removing unreachable block (ram,0x0da926) */
/* WARNING: Removing unreachable block (ram,0x0da938) */
/* WARNING: Removing unreachable block (ram,0x0da916) */
/* WARNING: Removing unreachable block (ram,0x0da90a) */
/* WARNING: Removing unreachable block (ram,0x0da988) */
/* WARNING: Removing unreachable block (ram,0x0da984) */
/* WARNING: Removing unreachable block (ram,0x0da980) */
/* WARNING: Removing unreachable block (ram,0x0da992) */
/* WARNING: Removing unreachable block (ram,0x0da98e) */
/* WARNING: Removing unreachable block (ram,0x0da97a) */
/* WARNING: Removing unreachable block (ram,0x0da976) */
/* WARNING: Removing unreachable block (ram,0x0da972) */
/* WARNING: Removing unreachable block (ram,0x0da902) */
/* WARNING: Removing unreachable block (ram,0x0da96a) */
/* WARNING: Removing unreachable block (ram,0x0da912) */
/* WARNING: Removing unreachable block (ram,0x0da934) */
/* WARNING: Removing unreachable block (ram,0x0da92a) */
/* WARNING: Removing unreachable block (ram,0x0da960) */
/* WARNING: Removing unreachable block (ram,0x0da956) */

void egs52_update_near_d6b0_0da902(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  
  cVar5 = UNK_00d704;
  if (cVar5 == '\x03') {
    uVar2 = Ram00d67e;
    uVar3 = Ram00d6b0;
    iVar4 = Ram00d6b2;
    iVar4 = ((int)uVar2 >> 0xf) + iVar4 + (uint)CARRY2(uVar2,uVar3);
    if (iVar4 < (int)(uint)(uVar2 + uVar3 < 65000)) {
      Ram00d6b0 = uVar2 + uVar3;
      Ram00d6b2 = iVar4;
    }
    else {
      Ram00d6b0 = 65000;
      Ram00d6b2 = 0;
    }
    iVar4 = Ram00f652;
    uVar3 = iVar4 + 0xb8;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = Ram00d6b0;
    bVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) < uVar7;
    iVar4 = Ram00d6b2;
    if ((int)(-(uint)bVar1 - iVar4) < 0 == (SBORROW2(0,iVar4) != SBORROW2(-iVar4,(uint)bVar1))) {
      Ram00d6b0 = 0;
      Ram00d6b2 = 0;
    }
    else {
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar3 = Ram00d6b0;
      Ram00d6b0 = uVar3 - uVar2;
      iVar4 = Ram00d6b2;
      Ram00d6b2 = iVar4 - (uint)(uVar3 < uVar2);
    }
  }
  else {
    iVar4 = Ram00f652;
    uVar3 = iVar4 + 0xb6;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = Ram00d6b0;
    bVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) < uVar7;
    iVar4 = Ram00d6b2;
    if ((int)(-(uint)bVar1 - iVar4) < 0 == (SBORROW2(0,iVar4) != SBORROW2(-iVar4,(uint)bVar1))) {
      Ram00d6b0 = 0;
      Ram00d6b2 = 0;
    }
    else {
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar3 = Ram00d6b0;
      Ram00d6b0 = uVar3 - uVar2;
      iVar4 = Ram00d6b2;
      Ram00d6b2 = iVar4 - (uint)(uVar3 < uVar2);
    }
  }
  uVar7 = Ram00d6b0;
  iVar4 = Ram00f652;
  uVar2 = iVar4 + 0x16;
  uVar3 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar6 = UNK_00d649;
  Ram00d6ae = (uint)bVar6 + uVar7 / *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
  return;
}


