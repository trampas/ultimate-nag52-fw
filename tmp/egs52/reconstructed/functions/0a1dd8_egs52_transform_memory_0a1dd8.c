/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1dd8; FLS offset 0x021dd8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1e52) */
/* WARNING: Removing unreachable block (ram,0x0a1e2c) */
/* WARNING: Removing unreachable block (ram,0x0a1e38) */
/* WARNING: Removing unreachable block (ram,0x0a1e30) */
/* WARNING: Removing unreachable block (ram,0x0a1e26) */
/* WARNING: Removing unreachable block (ram,0x0a1df8) */
/* WARNING: Removing unreachable block (ram,0x0a1e22) */
/* WARNING: Removing unreachable block (ram,0x0a1e34) */
/* WARNING: Removing unreachable block (ram,0x0a1e3c) */

undefined1 egs52_transform_memory_0a1dd8(byte param_1,byte param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  egs52_update_near_cce8_0a5112(param_1);
  uVar7 = (uint)param_1 * 8 + 0xc456;
  uVar8 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  bVar4 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
  if (param_2 == 0xff) {
    uVar8 = 0;
    uVar7 = 1;
  }
  else {
    uVar8 = (uint)param_2;
    uVar7 = param_2 + 1;
  }
  for (; uVar8 < uVar7; uVar8 = uVar8 + 1) {
    uVar5 = (uint)param_1 * 8 + -0x3bb0 + uVar8 * 6;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 0;
    uVar1 = uVar5 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
    uVar1 = uVar5 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    uVar1 = uVar5 + 3;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    uVar5 = uVar5 + 4;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 0;
    iVar6 = Ram00f84e;
    if ((iVar6 != 0) && (uVar8 == bVar4)) {
      egs52_update_near_fd6c_0a2200(uVar3);
      iVar6 = Ram00f84e;
      if (iVar6 == 2) {
        egs52_transform_memory_09fb68(uVar3);
      }
      if (param_3 == '\0') {
        egs52_update_near_fd6c_0a2550(uVar3,0);
      }
    }
  }
  return 0;
}


