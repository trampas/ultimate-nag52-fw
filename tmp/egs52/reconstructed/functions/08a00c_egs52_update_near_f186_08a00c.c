/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08a00c; FLS offset 0x00a00c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08a02a) */
/* WARNING: Removing unreachable block (ram,0x08a026) */
/* WARNING: Removing unreachable block (ram,0x08a020) */
/* WARNING: Removing unreachable block (ram,0x08a00e) */

undefined1 egs52_update_near_f186_08a00c(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  iVar2 = *(int *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = LZCOUNT(iVar2);
  }
  uVar1 = Ram00f186;
  Ram00f186 = uVar1 & 0xffbf;
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(uint *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) =
       *(uint *)((uint3)(param_1 & 0x3fff) | 0x88000) &
       *(uint *)((uint3)(iVar3 * 2 + 0x1066) | 0x88000);
  uVar1 = Ram00f186;
  Ram00f186 = uVar1 | 0x40;
  return (char)iVar3;
}


