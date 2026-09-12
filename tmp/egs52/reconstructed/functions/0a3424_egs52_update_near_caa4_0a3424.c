/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3424; FLS offset 0x023424.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a34f0) */
/* WARNING: Removing unreachable block (ram,0x0a34a2) */
/* WARNING: Removing unreachable block (ram,0x0a349a) */
/* WARNING: Removing unreachable block (ram,0x0a348e) */
/* WARNING: Removing unreachable block (ram,0x0a34ba) */
/* WARNING: Removing unreachable block (ram,0x0a34b4) */
/* WARNING: Removing unreachable block (ram,0x0a3470) */
/* WARNING: Removing unreachable block (ram,0x0a34f8) */
/* WARNING: Removing unreachable block (ram,0x0a34d2) */
/* WARNING: Removing unreachable block (ram,0x0a3448) */
/* WARNING: Removing unreachable block (ram,0x0a343c) */
/* WARNING: Removing unreachable block (ram,0x0a3430) */
/* WARNING: Removing unreachable block (ram,0x0a3458) */
/* WARNING: Removing unreachable block (ram,0x0a34cc) */
/* WARNING: Removing unreachable block (ram,0x0a347e) */
/* WARNING: Removing unreachable block (ram,0x0a348a) */
/* WARNING: Removing unreachable block (ram,0x0a34e2) */

int egs52_update_near_caa4_0a3424(byte param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  
  cVar3 = UNK_00caa4;
  if (cVar3 == '\0') {
    UNK_00caa4 = 1;
    iVar5 = (uint)param_1 * 8;
    iVar4 = egs52_update_near_f876_0a3f66(*(undefined2 *)((uint3)(iVar5 + 0x7f4) | 0x90000));
    if (iVar4 == 0) {
      UNK_00caa4 = 0;
      iVar5 = 0;
    }
    else {
      if (*(char *)((uint3)(iVar5 + 0x7f2) | 0x90000) == '\x03') {
        bVar6 = 0;
        while( true ) {
          uVar1 = (uint)bVar6 * 6 + 0xca80;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == param_1) break;
          bVar6 = bVar6 + 1;
        }
        uVar2 = (uint)bVar6 * 6 + 0xca84;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == -1) {
          iVar5 = egs52_update_near_c166_0971e8
                            (*(undefined2 *)((uint3)(iVar5 + 0x7f0) | 0x90000),iVar4,
                             *(undefined2 *)((uint3)(iVar5 + 0x7f4) | 0x90000));
        }
        else {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          iVar5 = egs52_update_near_c166_0971e8
                            (*(int *)((uint3)(iVar5 + 0x7f0) | 0x90000) +
                             *(int *)((uint3)(iVar5 + 0x7f4) | 0x90000) *
                             (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)),iVar4,
                             *(undefined2 *)((uint3)(iVar5 + 0x7f4) | 0x90000));
        }
      }
      else {
        iVar5 = egs52_update_near_c166_0971e8
                          (*(undefined2 *)((uint3)(iVar5 + 0x7f0) | 0x90000),iVar4,
                           *(undefined2 *)((uint3)(iVar5 + 0x7f4) | 0x90000));
      }
      if (iVar5 == 0) {
        egs52_free_small_heap_block(iVar4);
        UNK_00caa4 = 0;
        iVar5 = 0;
      }
      else {
        UNK_00caa4 = 0;
      }
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}


