/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089ce0; FLS offset 0x009ce0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x089d98) */
/* WARNING: Removing unreachable block (ram,0x089d94) */
/* WARNING: Removing unreachable block (ram,0x089d86) */
/* WARNING: Removing unreachable block (ram,0x089d82) */
/* WARNING: Removing unreachable block (ram,0x089d7e) */
/* WARNING: Removing unreachable block (ram,0x089d7c) */
/* WARNING: Removing unreachable block (ram,0x089d78) */
/* WARNING: Removing unreachable block (ram,0x089d74) */
/* WARNING: Removing unreachable block (ram,0x089d68) */
/* WARNING: Removing unreachable block (ram,0x089d64) */
/* WARNING: Removing unreachable block (ram,0x089d56) */
/* WARNING: Removing unreachable block (ram,0x089d52) */
/* WARNING: Removing unreachable block (ram,0x089d4c) */
/* WARNING: Removing unreachable block (ram,0x089d44) */
/* WARNING: Removing unreachable block (ram,0x089d40) */
/* WARNING: Removing unreachable block (ram,0x089d3a) */
/* WARNING: Removing unreachable block (ram,0x089d26) */
/* WARNING: Removing unreachable block (ram,0x089d22) */
/* WARNING: Removing unreachable block (ram,0x089d1c) */
/* WARNING: Removing unreachable block (ram,0x089d14) */
/* WARNING: Removing unreachable block (ram,0x089d10) */
/* WARNING: Removing unreachable block (ram,0x089d0a) */
/* WARNING: Removing unreachable block (ram,0x089d06) */
/* WARNING: Removing unreachable block (ram,0x089daa) */
/* WARNING: Removing unreachable block (ram,0x089ce6) */
/* WARNING: Removing unreachable block (ram,0x089d36) */
/* WARNING: Removing unreachable block (ram,0x089d70) */

void egs52_update_near_f40a_089ce0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  cVar5 = *(char *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
  if (cVar5 == '\x16') {
    uRam00f432 = 0x15;
    egs52_update_near_f439_089650(0xf432);
  }
  else if (cVar5 == '\x0e') {
    uVar1 = param_1 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar4 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    param_1 = param_1 + 4;
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
    uRam00f40c = *(undefined1 *)
                  ((uint3)(*(uint *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff)) &
                          0x3ff) << 0xe |
                  (uint3)(*(uint *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar4 + 6U & 0x3fff)) &
                         0x3fff));
    uRam00f40a = 0x12;
    egs52_call_083132_089dbe(0xf40a);
  }
  else if (cVar5 == '\x0f') {
    uVar1 = param_1 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar4 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    param_1 = param_1 + 4;
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
    uRam00f40c = *(undefined1 *)
                  ((uint3)(*(uint *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff)) &
                          0x3ff) << 0xe |
                  (uint3)(*(uint *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar4 + 6U & 0x3fff)) &
                         0x3fff));
    uRam00f40a = 0x13;
    egs52_call_083132_089dbe(0xf40a);
  }
  else if (cVar5 == '\x10') {
    uVar1 = param_1 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar4 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    param_1 = param_1 + 4;
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
    iVar3 = *(int *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(iVar4 + 6U & 0x3fff));
    uVar1 = *(uint *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff));
    if (*(int *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar3 + 4U & 0x3fff)) != 0 ||
        *(int *)((uint3)(uVar1 & 0x3ff) << 0xe | (uint3)(iVar3 + 6U & 0x3fff)) != 0) {
      uRam00f40a = 0x14;
      uRam00f40c = *(undefined1 *)
                    ((uint3)(*(uint *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(iVar4 + 8U & 0x3fff))
                            & 0x3ff) << 0xe |
                    (uint3)(*(uint *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(iVar4 + 6U & 0x3fff))
                           & 0x3fff));
      egs52_call_083132_089dbe(0xf40a);
    }
  }
  return;
}


