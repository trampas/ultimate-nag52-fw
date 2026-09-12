/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a0000; FLS offset 0x020000.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a00a2) */
/* WARNING: Removing unreachable block (ram,0x0a009c) */
/* WARNING: Removing unreachable block (ram,0x0a0094) */
/* WARNING: Removing unreachable block (ram,0x0a0090) */
/* WARNING: Removing unreachable block (ram,0x0a008c) */
/* WARNING: Removing unreachable block (ram,0x0a0088) */
/* WARNING: Removing unreachable block (ram,0x0a006e) */
/* WARNING: Removing unreachable block (ram,0x0a0060) */
/* WARNING: Removing unreachable block (ram,0x0a0058) */
/* WARNING: Removing unreachable block (ram,0x0a0042) */
/* WARNING: Removing unreachable block (ram,0x0a003e) */
/* WARNING: Removing unreachable block (ram,0x0a003a) */
/* WARNING: Removing unreachable block (ram,0x0a0020) */
/* WARNING: Removing unreachable block (ram,0x0a002e) */
/* WARNING: Removing unreachable block (ram,0x0a0006) */
/* WARNING: Removing unreachable block (ram,0x0a0014) */
/* WARNING: Removing unreachable block (ram,0x0a0054) */
/* WARNING: Removing unreachable block (ram,0x0a0082) */

void egs52_update_near_c34e_0a0000(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  for (uVar5 = 0; uVar5 < bRam0b0462; uVar5 = uVar5 + 1) {
    uVar1 = uVar5 + 0x844b;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_transform_memory_09f6de(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),0);
  }
  for (uVar5 = 0; uVar5 < bRam0b0463; uVar5 = uVar5 + 1) {
    uVar1 = uVar5 + 0x8454;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_transform_memory_09f6de(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),0);
  }
  uVar5 = Ram00c34e;
  Ram00c34e = uVar5 & 0xfcff;
  bVar4 = UNK_00f842;
  if (bVar4 < bRam0b044a) {
    uVar5 = (uint)bVar4 * 0x1c + 0x83be;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = (uint)bVar4 * 0x1c + 0x83c0;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    egs52_transform_far_memory_0a5b5e
              (*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)),
               *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)));
    bVar4 = UNK_00f842;
    uVar5 = (uint)bVar4 * 0x1c + 0x83c2;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    egs52_update_near_cda4_0a5c46(*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)));
    uVar5 = egs52_compute_from_near_cda2_0a5f9c();
    if ((uVar5 & 1) == 0) {
      uVar5 = Ram00c34e;
      Ram00c34e = uVar5 & 0xfffd;
    }
    else {
      Ram00c354 = 0;
      Ram00c356 = 0;
      Ram00c358 = 0;
      Ram00c35a = 0;
      uVar5 = Ram00c34e;
      Ram00c34e = uVar5 & 0xfffd;
      uVar5 = Ram00c34e;
      Ram00c34e = uVar5 | 1;
    }
  }
  return;
}


