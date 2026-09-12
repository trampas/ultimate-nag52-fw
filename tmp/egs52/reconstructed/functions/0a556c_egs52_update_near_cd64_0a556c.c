/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a556c; FLS offset 0x02556c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a56d8) */
/* WARNING: Removing unreachable block (ram,0x0a56ea) */
/* WARNING: Removing unreachable block (ram,0x0a56e6) */
/* WARNING: Removing unreachable block (ram,0x0a56e2) */
/* WARNING: Removing unreachable block (ram,0x0a56c0) */
/* WARNING: Removing unreachable block (ram,0x0a56bc) */
/* WARNING: Removing unreachable block (ram,0x0a56aa) */
/* WARNING: Removing unreachable block (ram,0x0a56a4) */
/* WARNING: Removing unreachable block (ram,0x0a569e) */
/* WARNING: Removing unreachable block (ram,0x0a569a) */
/* WARNING: Removing unreachable block (ram,0x0a5696) */
/* WARNING: Removing unreachable block (ram,0x0a568e) */
/* WARNING: Removing unreachable block (ram,0x0a5686) */
/* WARNING: Removing unreachable block (ram,0x0a5682) */
/* WARNING: Removing unreachable block (ram,0x0a567e) */
/* WARNING: Removing unreachable block (ram,0x0a566e) */
/* WARNING: Removing unreachable block (ram,0x0a5644) */
/* WARNING: Removing unreachable block (ram,0x0a5662) */
/* WARNING: Removing unreachable block (ram,0x0a565e) */
/* WARNING: Removing unreachable block (ram,0x0a565a) */
/* WARNING: Removing unreachable block (ram,0x0a5638) */
/* WARNING: Removing unreachable block (ram,0x0a5634) */
/* WARNING: Removing unreachable block (ram,0x0a5622) */
/* WARNING: Removing unreachable block (ram,0x0a561c) */
/* WARNING: Removing unreachable block (ram,0x0a5616) */
/* WARNING: Removing unreachable block (ram,0x0a5612) */
/* WARNING: Removing unreachable block (ram,0x0a560e) */
/* WARNING: Removing unreachable block (ram,0x0a5606) */
/* WARNING: Removing unreachable block (ram,0x0a55fe) */
/* WARNING: Removing unreachable block (ram,0x0a55fa) */
/* WARNING: Removing unreachable block (ram,0x0a55f6) */
/* WARNING: Removing unreachable block (ram,0x0a55f2) */
/* WARNING: Removing unreachable block (ram,0x0a55ce) */
/* WARNING: Removing unreachable block (ram,0x0a55da) */
/* WARNING: Removing unreachable block (ram,0x0a55d6) */
/* WARNING: Removing unreachable block (ram,0x0a55c4) */
/* WARNING: Removing unreachable block (ram,0x0a55e2) */
/* WARNING: Removing unreachable block (ram,0x0a55de) */
/* WARNING: Removing unreachable block (ram,0x0a55ba) */
/* WARNING: Removing unreachable block (ram,0x0a55a8) */
/* WARNING: Removing unreachable block (ram,0x0a55a2) */
/* WARNING: Removing unreachable block (ram,0x0a559c) */
/* WARNING: Removing unreachable block (ram,0x0a5598) */
/* WARNING: Removing unreachable block (ram,0x0a5594) */
/* WARNING: Removing unreachable block (ram,0x0a558c) */
/* WARNING: Removing unreachable block (ram,0x0a5584) */
/* WARNING: Removing unreachable block (ram,0x0a5580) */
/* WARNING: Removing unreachable block (ram,0x0a557c) */
/* WARNING: Removing unreachable block (ram,0x0a5578) */
/* WARNING: Removing unreachable block (ram,0x0a556c) */
/* WARNING: Removing unreachable block (ram,0x0a55be) */
/* WARNING: Removing unreachable block (ram,0x0a55ca) */
/* WARNING: Removing unreachable block (ram,0x0a55e6) */
/* WARNING: Removing unreachable block (ram,0x0a563e) */
/* WARNING: Removing unreachable block (ram,0x0a5650) */
/* WARNING: Removing unreachable block (ram,0x0a5654) */
/* WARNING: Removing unreachable block (ram,0x0a5648) */
/* WARNING: Removing unreachable block (ram,0x0a567a) */
/* WARNING: Removing unreachable block (ram,0x0a56c6) */
/* WARNING: Removing unreachable block (ram,0x0a56cc) */
/* WARNING: Removing unreachable block (ram,0x0a56d0) */
/* WARNING: Removing unreachable block (ram,0x0a56dc) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x0904d8 : 0x0a5650 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_cd64_0a556c(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  
  Ram00cd64 = iRam0b058c * 10;
  Ram00cd66 = 0;
  Ram00cd68 = 0xffff;
  Ram00cd6a = 0xffff;
  Ram00cd6c = 0x1e;
  Ram00cd6e = 0x27;
  Ram00cd70 = 0x1e;
  Ram00cd72 = 0x1e;
  UNK_00cd74 = 2;
  UNK_00cd75 = 1;
  egs52_transform_memory_0a64fe(0,0xcd16,0xcd64);
  uVar4 = Ram00cd16;
  if (uRam0b058a < uVar4) {
    uVar4 = 0x24;
    if ((((uRam0904d8 & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904d8 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904d8 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    *(uint *)((uint3)uVar4 << 0xe | (uint3)(uRam0904d8 & 0x3fff)) = uRam0b058a;
  }
  else if (uVar4 < uRam0b0588) {
    uVar4 = 0x24;
    if ((((uRam0904d8 & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904d8 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904d8 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uRam0904d8 & 0x3fff)) = 0;
  }
  else {
    uVar4 = 0x24;
    if ((((uRam0904d8 & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904d8 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904d8 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar3 = Ram00cd16;
    *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uRam0904d8 & 0x3fff)) = uVar3;
  }
  Ram00cd76 = iRam0b0592 * 10;
  Ram00cd78 = 0;
  Ram00cd7a = 0xffff;
  Ram00cd7c = 0xffff;
  Ram00cd7e = 0x1e;
  Ram00cd80 = 0x27;
  Ram00cd82 = 0x1e;
  Ram00cd84 = 0x1e;
  UNK_00cd86 = 2;
  UNK_00cd87 = 1;
  egs52_transform_memory_0a64fe(1,0xcd30,0xcd76);
  uVar4 = Ram00cd30;
  if (uRam0b0590 < uVar4) {
    uVar4 = uRam0904d8 + 2;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uRam0b0590;
  }
  else if (uVar4 < uRam0b058e) {
    uVar4 = uRam0904d8 + 2;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
  }
  else {
    uVar1 = uRam0904d8 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar4;
  }
  uVar4 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar4 & 8) != 0) {
    Ram00cd88 = iRam0b0598 * 10;
    Ram00cd8a = 0;
    Ram00cd8c = 0xffff;
    Ram00cd8e = 0xffff;
    Ram00cd90 = 0x1e;
    Ram00cd92 = 0x4f;
    Ram00cd94 = 0x1e;
    Ram00cd96 = 0x1e;
    UNK_00cd98 = 2;
    UNK_00cd99 = 1;
    egs52_transform_memory_0a64fe(2,0xcd4a,0xcd88);
    uVar4 = Ram00cd4a;
    if (uVar4 <= uRam0b0596) {
      if (uVar4 < uRam0b0594) {
        uVar4 = uRam0904d8 + 6;
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
        return;
      }
      uVar1 = uRam0904d8 + 6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar4;
      return;
    }
    uVar4 = uRam0904d8 + 6;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uRam0b0596;
  }
  return;
}


