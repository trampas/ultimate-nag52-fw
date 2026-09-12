/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a79fc; FLS offset 0x0279fc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a7a96) */
/* WARNING: Removing unreachable block (ram,0x0a7a8c) */
/* WARNING: Removing unreachable block (ram,0x0a7a88) */
/* WARNING: Removing unreachable block (ram,0x0a7a7c) */
/* WARNING: Removing unreachable block (ram,0x0a7a4e) */
/* WARNING: Removing unreachable block (ram,0x0a7a5c) */
/* WARNING: Removing unreachable block (ram,0x0a7a40) */
/* WARNING: Removing unreachable block (ram,0x0a7a3c) */
/* WARNING: Removing unreachable block (ram,0x0a7a2e) */
/* WARNING: Removing unreachable block (ram,0x0a7a24) */
/* WARNING: Removing unreachable block (ram,0x0a7a1c) */
/* WARNING: Removing unreachable block (ram,0x0a7a58) */
/* WARNING: Removing unreachable block (ram,0x0a7a54) */

undefined1 egs52_transform_memory_0a79fc(uint param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  undefined1 uVar8;
  
  cVar5 = egs52_compute_from_near_f84e_0a1c32(param_2);
  if (cVar5 == -0xe) {
    uVar8 = 0xf2;
  }
  else {
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(char *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) = (char)((uint)param_2 >> 8);
    uVar1 = param_1 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)param_2;
    uVar2 = param_1 + 2;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
    cVar6 = egs52_match_fault_status_mask(cVar5,8);
    if (cVar6 == '\0') {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 0x10;
    }
    bVar7 = egs52_update_near_fd6c_0a1220(cVar5);
    if ((bVar7 & 0x40) == 0) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 0x20;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 0x60;
    }
    cVar5 = egs52_update_near_fd6c_0a14c0(cVar5,param_1 + 3,0,0xcdf2,param_1 + 10);
    if (cVar5 == '\0') {
      uVar4 = Ram00cdf2;
      uVar1 = param_1 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)((uint)uVar4 >> 8);
      uVar4 = Ram00cdf2;
      param_1 = param_1 + 9;
      uVar1 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) = (char)uVar4;
      uVar8 = 0x2d;
    }
    else {
      uVar8 = 0xf2;
    }
  }
  return uVar8;
}


