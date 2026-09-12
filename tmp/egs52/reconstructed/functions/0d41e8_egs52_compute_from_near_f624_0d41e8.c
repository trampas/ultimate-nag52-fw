/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d41e8; FLS offset 0x0541e8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d4278) */
/* WARNING: Removing unreachable block (ram,0x0d4274) */
/* WARNING: Removing unreachable block (ram,0x0d424e) */
/* WARNING: Removing unreachable block (ram,0x0d4236) */
/* WARNING: Removing unreachable block (ram,0x0d4232) */
/* WARNING: Removing unreachable block (ram,0x0d4226) */
/* WARNING: Removing unreachable block (ram,0x0d41fa) */
/* WARNING: Removing unreachable block (ram,0x0d41f6) */
/* WARNING: Removing unreachable block (ram,0x0d41f2) */
/* WARNING: Removing unreachable block (ram,0x0d41ee) */
/* WARNING: Removing unreachable block (ram,0x0d4222) */
/* WARNING: Removing unreachable block (ram,0x0d4256) */
/* WARNING: Removing unreachable block (ram,0x0d425e) */

uint egs52_compute_from_near_f624_0d41e8(char param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = 0;
  iVar4 = Ram00f624;
  uVar1 = iVar4 + 0xc2;
  uVar7 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar7 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar7 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar7 = 3;
  }
  uVar2 = iVar4 + 0xc4;
  uVar3 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar5 = UNK_00d5cc;
  uVar1 = *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar1 & 0x3fff)) -
          (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) * (uint)bVar5) / 100;
  if (param_1 == '\0') {
    uVar6 = 0;
  }
  else if (param_1 == '\x01') {
    uVar2 = Ram00d524;
    uVar3 = Ram00d524;
    iVar4 = Ram00f624;
    uVar7 = iVar4 + 200;
    uVar6 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar6 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar6 = (uint)(((((ulong)uVar2 * (ulong)uVar3) / 1000 & 0xffff) * (ulong)uVar1) /
                  (ulong)*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar7 & 0x3fff)));
  }
  else if (param_1 == '\x02') {
    iVar4 = Ram00d4e4;
    if (iVar4 < 0) {
      iVar4 = Ram00d4e4;
      uVar7 = -iVar4;
    }
    else {
      uVar7 = Ram00d4e4;
    }
    iVar4 = Ram00f624;
    uVar6 = iVar4 + 0xca;
    uVar2 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar6 = (uint)(((((ulong)uVar7 * (ulong)uVar7) / 1000 & 0xffff) * (ulong)uVar1) /
                  (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)));
  }
  return uVar6 / 10;
}


