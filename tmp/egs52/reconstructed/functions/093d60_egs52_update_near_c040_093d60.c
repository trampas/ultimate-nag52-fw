/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093d60; FLS offset 0x013d60.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093d96) */
/* WARNING: Removing unreachable block (ram,0x093d92) */
/* WARNING: Removing unreachable block (ram,0x093da2) */
/* WARNING: Removing unreachable block (ram,0x093d9e) */
/* WARNING: Removing unreachable block (ram,0x093d6a) */
/* WARNING: Removing unreachable block (ram,0x093d68) */
/* WARNING: Removing unreachable block (ram,0x093d64) */
/* WARNING: Removing unreachable block (ram,0x093d9a) */

char egs52_update_near_c040_093d60(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  char cVar3;
  
  uVar1 = 0x24;
  if ((((uRam09027c & 0xc000) != 0) && (uVar1 = 0x21, (uRam09027c & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam09027c & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar2 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uRam09027c & 0x3fff));
  uVar1 = 0x24;
  if ((((uRam09027c & 0xc000) != 0) && (uVar1 = 0x21, (uRam09027c & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam09027c & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(int *)((uint3)uVar1 << 0xe | (uint3)(uRam09027c & 0x3fff)) = param_1;
  cVar3 = egs52_register_sequence_09ceaa(0x274,9,0x32,param_1 + 4,0);
  if (cVar3 == '\0') {
    UNK_00c040 = 0;
    UNK_00c041 = 0;
    UNK_00c042 = 0;
  }
  else {
    uVar1 = 0x24;
    if ((((uRam09027c & 0xc000) != 0) && (uVar1 = 0x21, (uRam09027c & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam09027c & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uRam09027c & 0x3fff)) = uVar2;
  }
  return cVar3;
}


