/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0972dc; FLS offset 0x0172dc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097334) */
/* WARNING: Removing unreachable block (ram,0x097330) */
/* WARNING: Removing unreachable block (ram,0x097320) */
/* WARNING: Removing unreachable block (ram,0x09731e) */
/* WARNING: Removing unreachable block (ram,0x097310) */
/* WARNING: Removing unreachable block (ram,0x0972f6) */
/* WARNING: Removing unreachable block (ram,0x097300) */
/* WARNING: Removing unreachable block (ram,0x0972f2) */
/* WARNING: Removing unreachable block (ram,0x097302) */
/* WARNING: Removing unreachable block (ram,0x0972e6) */
/* WARNING: Removing unreachable block (ram,0x0972e2) */
/* WARNING: Removing unreachable block (ram,0x097344) */
/* WARNING: Removing unreachable block (ram,0x09730a) */
/* WARNING: Removing unreachable block (ram,0x09733c) */
/* WARNING: Removing unreachable block (ram,0x097318) */
/* WARNING: Removing unreachable block (ram,0x09731a) */

undefined2 egs52_update_near_c168_0972dc(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  
  UNK_00c168 = 1;
  uVar5 = Ram00c164;
  if (uVar5 == 0) {
    UNK_00c168 = 0;
  }
  else {
    uVar4 = 0;
    while( true ) {
      uVar1 = uVar5 + 10;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == param_1) {
        uVar1 = uVar5 + 2;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) != '\0') {
          UNK_00c168 = 0;
          return 0;
        }
        uVar1 = uVar5 + 4;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        if (uVar4 == 0) {
          uVar4 = 0x24;
          if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          Ram00c164 = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff));
        }
        else {
          uVar1 = 0x24;
          if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar2 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
               *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
        }
        egs52_free_small_heap_block(uVar5);
        UNK_00c169 = 1;
        UNK_00c168 = 0;
        return uVar3;
      }
      uVar4 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) == 0) break;
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = uVar5;
      uVar5 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
    }
    UNK_00c168 = 0;
  }
  return 0;
}


