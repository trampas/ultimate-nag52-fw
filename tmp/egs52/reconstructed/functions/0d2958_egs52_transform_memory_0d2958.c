/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d2958; FLS offset 0x052958.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d2a3e) */
/* WARNING: Removing unreachable block (ram,0x0d2a34) */
/* WARNING: Removing unreachable block (ram,0x0d2a16) */
/* WARNING: Removing unreachable block (ram,0x0d2a10) */
/* WARNING: Removing unreachable block (ram,0x0d2a06) */
/* WARNING: Removing unreachable block (ram,0x0d2a04) */
/* WARNING: Removing unreachable block (ram,0x0d29fa) */
/* WARNING: Removing unreachable block (ram,0x0d29f2) */
/* WARNING: Removing unreachable block (ram,0x0d29ee) */
/* WARNING: Removing unreachable block (ram,0x0d29e4) */
/* WARNING: Removing unreachable block (ram,0x0d29e2) */
/* WARNING: Removing unreachable block (ram,0x0d29d8) */
/* WARNING: Removing unreachable block (ram,0x0d29b8) */
/* WARNING: Removing unreachable block (ram,0x0d29b0) */
/* WARNING: Removing unreachable block (ram,0x0d29a6) */
/* WARNING: Removing unreachable block (ram,0x0d29a4) */
/* WARNING: Removing unreachable block (ram,0x0d299c) */
/* WARNING: Removing unreachable block (ram,0x0d2994) */
/* WARNING: Removing unreachable block (ram,0x0d2988) */
/* WARNING: Removing unreachable block (ram,0x0d2afc) */
/* WARNING: Removing unreachable block (ram,0x0d2af2) */
/* WARNING: Removing unreachable block (ram,0x0d2aea) */
/* WARNING: Removing unreachable block (ram,0x0d2ae6) */
/* WARNING: Removing unreachable block (ram,0x0d2adc) */
/* WARNING: Removing unreachable block (ram,0x0d2ada) */
/* WARNING: Removing unreachable block (ram,0x0d2ad0) */
/* WARNING: Removing unreachable block (ram,0x0d2ab2) */
/* WARNING: Removing unreachable block (ram,0x0d2aaa) */
/* WARNING: Removing unreachable block (ram,0x0d2aa0) */
/* WARNING: Removing unreachable block (ram,0x0d2a9e) */
/* WARNING: Removing unreachable block (ram,0x0d2a94) */
/* WARNING: Removing unreachable block (ram,0x0d2a8c) */
/* WARNING: Removing unreachable block (ram,0x0d2a88) */
/* WARNING: Removing unreachable block (ram,0x0d2a7e) */
/* WARNING: Removing unreachable block (ram,0x0d2a7c) */
/* WARNING: Removing unreachable block (ram,0x0d2a74) */
/* WARNING: Removing unreachable block (ram,0x0d2a54) */
/* WARNING: Removing unreachable block (ram,0x0d2a4c) */
/* WARNING: Removing unreachable block (ram,0x0d296c) */
/* WARNING: Removing unreachable block (ram,0x0d2968) */
/* WARNING: Removing unreachable block (ram,0x0d2964) */
/* WARNING: Removing unreachable block (ram,0x0d2a44) */
/* WARNING: Removing unreachable block (ram,0x0d2990) */

void egs52_transform_memory_0d2958(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  int iVar6;
  undefined1 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar5;
  
  iVar6 = Ram00f62e;
  uVar1 = iVar6 + 0x10;
  uVar8 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar8 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  uVar2 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar6 + 0xe;
  uVar8 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar8 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar8 = uVar1;
  if (param_1 < uVar1) {
    uVar8 = param_1;
  }
  uVar9 = uVar2;
  if (uVar2 < uVar8) {
    uVar9 = uVar8;
  }
  if (uVar9 < uVar1 + uVar2 >> 1) {
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f4;
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      (*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) + iVar6);
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 1 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f4;
    uVar4 = (long)iVar6 * (long)(int)(uVar9 - uVar2);
    uVar5 = (uint)(uVar4 >> 0x10);
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      ((int)*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                       (int)((long)(uVar4 & 0xffff | (ulong)uVar5 << 0x10) /
                            (long)(int)(uVar1 - uVar2)) * 2,(int)uVar4,uVar5);
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 1 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 2 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f6;
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      (*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) + iVar6);
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 2 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 3 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f6;
    uVar4 = (long)iVar6 * (long)(int)(uVar9 - uVar2);
    uVar9 = (uint)(uVar4 >> 0x10);
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      ((int)*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                       (int)((long)(uVar4 & 0xffff | (ulong)uVar9 << 0x10) /
                            (long)(int)(uVar1 - uVar2)) * 2,(int)uVar4,uVar9);
    iVar6 = Ram00d7d8;
    uVar8 = iVar6 + 3 + (param_2 & 0xff);
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) = uVar7;
  }
  else {
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f4;
    uVar4 = (long)iVar6 * (long)(int)(uVar1 - uVar9);
    uVar5 = (uint)(uVar4 >> 0x10);
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      ((int)*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                       (int)((long)(uVar4 & 0xffff | (ulong)uVar5 << 0x10) /
                            (long)(int)(uVar1 - uVar2)) * 2,(int)uVar4,uVar5);
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 1 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f4;
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      (*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) + iVar6);
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 1 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar3 = iVar6 + 2 + (param_2 & 0xff);
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    iVar6 = Ram00d3f6;
    uVar4 = (long)iVar6 * (long)(int)(uVar1 - uVar9);
    uVar9 = (uint)(uVar4 >> 0x10);
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      ((int)*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                       (int)((long)(uVar4 & 0xffff | (ulong)uVar9 << 0x10) /
                            (long)(int)(uVar1 - uVar2)) * 2,uVar9);
    iVar6 = Ram00d7d8;
    uVar8 = iVar6 + 2 + (param_2 & 0xff);
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) = uVar7;
    iVar6 = Ram00d7d8;
    uVar8 = iVar6 + 3 + (param_2 & 0xff);
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar6 = Ram00d3f6;
    uVar7 = egs52_compute_from_near_f62e_0d290c
                      (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) + iVar6);
    iVar6 = Ram00d7d8;
    uVar8 = iVar6 + 3 + (param_2 & 0xff);
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) = uVar7;
  }
  return;
}


