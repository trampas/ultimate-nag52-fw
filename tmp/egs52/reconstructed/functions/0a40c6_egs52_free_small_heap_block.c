/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a40c6; FLS offset 0x0240c6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a41a2) */
/* WARNING: Removing unreachable block (ram,0x0a4194) */
/* WARNING: Removing unreachable block (ram,0x0a4188) */
/* WARNING: Removing unreachable block (ram,0x0a4174) */
/* WARNING: Removing unreachable block (ram,0x0a4134) */
/* WARNING: Removing unreachable block (ram,0x0a4144) */
/* WARNING: Removing unreachable block (ram,0x0a411c) */
/* WARNING: Removing unreachable block (ram,0x0a4154) */
/* WARNING: Removing unreachable block (ram,0x0a413a) */
/* WARNING: Removing unreachable block (ram,0x0a412c) */
/* WARNING: Removing unreachable block (ram,0x0a4116) */
/* WARNING: Removing unreachable block (ram,0x0a4106) */
/* WARNING: Removing unreachable block (ram,0x0a4102) */
/* WARNING: Removing unreachable block (ram,0x0a40fe) */
/* WARNING: Removing unreachable block (ram,0x0a40f6) */
/* WARNING: Removing unreachable block (ram,0x0a40f0) */
/* WARNING: Removing unreachable block (ram,0x0a40ec) */
/* WARNING: Removing unreachable block (ram,0x0a40e8) */
/* WARNING: Removing unreachable block (ram,0x0a40e4) */
/* WARNING: Removing unreachable block (ram,0x0a40dc) */
/* WARNING: Removing unreachable block (ram,0x0a40d6) */
/* WARNING: Removing unreachable block (ram,0x0a40c6) */
/* WARNING: Removing unreachable block (ram,0x0a40d2) */
/* WARNING: Removing unreachable block (ram,0x0a4122) */
/* WARNING: Removing unreachable block (ram,0x0a4150) */
/* WARNING: Removing unreachable block (ram,0x0a4160) */
/* WARNING: Removing unreachable block (ram,0x0a4168) */
/* WARNING: Removing unreachable block (ram,0x0a4190) */
/* WARNING: Removing unreachable block (ram,0x0a4198) */
/* WARNING: Removing unreachable block (ram,0x0a415a) */

void egs52_free_small_heap_block(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  cVar3 = UNK_00f876;
  if (cVar3 == '\0') {
    UNK_00f876 = 1;
    cVar3 = UNK_00e101;
    if (cVar3 == '\0') {
      UNK_00e100 = 0;
      UNK_00e101 = 0xfc;
      UNK_00e102 = 1;
      UNK_00e1fc = 0;
      UNK_00e1fd = 0xfc;
      UNK_00e1fe = 2;
      Ram00e200 = 0xf8;
      Ram00e202 = 0;
      Ram00e204 = 0;
    }
    uVar6 = 0;
    do {
      if (param_1 == uVar6 + 0xe104) {
        uVar2 = uVar6 + 0xe101;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        uVar4 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = uVar6 + 0xe100;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar5 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = uVar5 + 0xe102;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\x01') {
          uVar5 = uVar6;
        }
        uVar6 = uVar4 + 0xe102;
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) == '\x01') {
          uVar4 = uVar4 + 0xe101;
          uVar6 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar6 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          uVar4 = (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar4 & 0x3fff));
        }
        Ram00e202 = uVar5;
        Ram00e200 = (uVar4 - uVar5) + -4;
        uVar2 = uVar5 + 0xe102;
        uVar6 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        *(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff)) = 2;
        uVar6 = uVar5 + 0xe101;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = (char)uVar4;
        uVar4 = uVar4 + 0xe100;
        uVar6 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar6 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        *(char *)((uint3)uVar6 << 0xe | (uint3)(uVar4 & 0x3fff)) = (char)uVar5;
        uVar6 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        *(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff)) = 1;
        uVar6 = 0xfc;
      }
      else {
        uVar6 = uVar6 + 0xe101;
        uVar2 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff));
      }
    } while (uVar6 < 0xfc);
    UNK_00f876 = 0;
    return;
  }
  uVar6 = 0;
  do {
    if (param_1 == uVar6 + 0xe104) {
      uVar6 = uVar6 + 0xe102;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) = 1;
      Ram00e200 = 0xf8;
      Ram00e202 = 0;
      Ram00e204 = 0;
      uVar6 = 0xfc;
    }
    else {
      uVar6 = uVar6 + 0xe101;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar6 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff));
    }
  } while (uVar6 < 0xfc);
  return;
}


