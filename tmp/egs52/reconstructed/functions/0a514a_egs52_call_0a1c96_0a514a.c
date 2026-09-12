/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a514a; FLS offset 0x02514a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a517a) */
/* WARNING: Removing unreachable block (ram,0x0a5170) */
/* WARNING: Removing unreachable block (ram,0x0a5162) */

void egs52_call_0a1c96_0a514a(byte param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  
  bVar4 = egs52_compute_from_near_f84e_0a1c96(param_1);
  uVar1 = (uint)bVar4 * 0x14 + 0x9308;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6 + 0x9003;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = param_1 + 0xccd8;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((bVar3 <= *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) && (bVar3 != 0)) {
    egs52_transform_memory_09ff1e(bVar4,0x40);
  }
  return;
}


