/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09b222; FLS offset 0x01b222.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09b2f8) */
/* WARNING: Removing unreachable block (ram,0x09b2f2) */
/* WARNING: Removing unreachable block (ram,0x09b2ee) */
/* WARNING: Removing unreachable block (ram,0x09b2e8) */
/* WARNING: Removing unreachable block (ram,0x09b2e0) */
/* WARNING: Removing unreachable block (ram,0x09b2da) */
/* WARNING: Removing unreachable block (ram,0x09b2d2) */
/* WARNING: Removing unreachable block (ram,0x09b2cc) */
/* WARNING: Removing unreachable block (ram,0x09b2c8) */
/* WARNING: Removing unreachable block (ram,0x09b2c4) */
/* WARNING: Removing unreachable block (ram,0x09b2c0) */
/* WARNING: Removing unreachable block (ram,0x09b2be) */
/* WARNING: Removing unreachable block (ram,0x09b2bc) */
/* WARNING: Removing unreachable block (ram,0x09b2b4) */
/* WARNING: Removing unreachable block (ram,0x09b2b2) */
/* WARNING: Removing unreachable block (ram,0x09b2ac) */
/* WARNING: Removing unreachable block (ram,0x09b2a8) */
/* WARNING: Removing unreachable block (ram,0x09b2a4) */
/* WARNING: Removing unreachable block (ram,0x09b2a2) */
/* WARNING: Removing unreachable block (ram,0x09b29c) */
/* WARNING: Removing unreachable block (ram,0x09b296) */
/* WARNING: Removing unreachable block (ram,0x09b28c) */
/* WARNING: Removing unreachable block (ram,0x09b28a) */
/* WARNING: Removing unreachable block (ram,0x09b284) */
/* WARNING: Removing unreachable block (ram,0x09b27c) */
/* WARNING: Removing unreachable block (ram,0x09b27a) */
/* WARNING: Removing unreachable block (ram,0x09b274) */
/* WARNING: Removing unreachable block (ram,0x09b26e) */
/* WARNING: Removing unreachable block (ram,0x09b26a) */
/* WARNING: Removing unreachable block (ram,0x09b266) */
/* WARNING: Removing unreachable block (ram,0x09b264) */
/* WARNING: Removing unreachable block (ram,0x09b25e) */
/* WARNING: Removing unreachable block (ram,0x09b25a) */
/* WARNING: Removing unreachable block (ram,0x09b256) */
/* WARNING: Removing unreachable block (ram,0x09b250) */
/* WARNING: Removing unreachable block (ram,0x09b232) */
/* WARNING: Removing unreachable block (ram,0x09b224) */

void egs52_update_near_c2b8_09b222(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  
  uVar4 = uRam00f464;
  cVar5 = UNK_00c102;
  if ((cVar5 == '\x06') && ((cRam083e7c == -1 || (cRam083e7c == -4)))) {
    uVar1 = Ram00fdec;
    if ((uVar1 & 0x20) == 0) {
      uVar2 = uRam00f464 + 1;
      cRam00f57d = '\0';
      uVar6 = UNK_00c103;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar6 = UNK_00c103;
      UNK_00c2b8 = uVar6;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 6;
      uVar2 = uVar4 - 1;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xa2;
      uVar3 = uVar4 - 2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar2 = uVar4 - 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xf3;
      uVar3 = uVar4 - 4;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = uRam00f594;
      uVar4 = uVar4 - 5;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0x83;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cRam00f57d = cRam00f57d + *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
      uRam00f581 = 0;
      Ram00fdea = 3;
      Ram00fdec = 0x42;
      uRam00f408 = 1;
      uVar4 = Ram00fde8;
      Ram00fde8 = uVar4 | 1;
      uRam00f469 = 3;
      uRam00f46b = 1;
      uRam00f46c = 1;
      uRam00f57e = 8;
      uVar4 = Ram00fd02;
      Ram00fd02 = uVar4 | 0x20;
      cRam00f583 = cRam00f57d;
    }
    else {
      egs52_update_near_c2ba_09bca4();
    }
  }
  return;
}


