/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4678; FLS offset 0x024678.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a46ee) */
/* WARNING: Removing unreachable block (ram,0x0a46ea) */
/* WARNING: Removing unreachable block (ram,0x0a46c2) */
/* WARNING: Removing unreachable block (ram,0x0a46c6) */
/* WARNING: Removing unreachable block (ram,0x0a46d6) */
/* WARNING: Removing unreachable block (ram,0x0a46b2) */
/* WARNING: Removing unreachable block (ram,0x0a46d4) */
/* WARNING: Removing unreachable block (ram,0x0a46be) */
/* WARNING: Removing unreachable block (ram,0x0a46ae) */
/* WARNING: Removing unreachable block (ram,0x0a469c) */
/* WARNING: Removing unreachable block (ram,0x0a46e0) */
/* WARNING: Removing unreachable block (ram,0x0a4690) */
/* WARNING: Removing unreachable block (ram,0x0a468e) */
/* WARNING: Removing unreachable block (ram,0x0a468a) */
/* WARNING: Removing unreachable block (ram,0x0a46b4) */
/* WARNING: Removing unreachable block (ram,0x0a46a6) */
/* WARNING: Removing unreachable block (ram,0x0a46ca) */

void egs52_transform_memory_0a4678(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  
  uVar4 = (param_1 & 0xff) + 0xcac6;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar2 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
       *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) + -1;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) == '\0') {
    for (bVar6 = 0; bVar6 < *(byte *)((uint3)((param_1 & 0xff) + 0x9fe) | 0x90000);
        bVar6 = bVar6 + 1) {
      iVar5 = (param_1 & 0xff) * 2;
      uVar1 = iVar5 - 0x756;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + (uint)bVar6 * 2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != -1) {
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
        *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
             *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(undefined2 *)((uint3)((uint)bVar6 * 2 + (param_1 & 0xff) * 8 + 0x9da) | 0x90000);
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 1;
          uVar1 = iVar5 - 0x75e;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + (uint)bVar6 * 4;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar7 = uVar2 + 2;
          uVar3 = 0x24;
          if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          (*(code *)((uint3)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) << 0x10 |
                    (uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))))();
        }
      }
    }
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) =
         *(undefined1 *)((uint3)((param_1 & 0xff) + 0x9fa) | 0x90000);
  }
  return;
}


