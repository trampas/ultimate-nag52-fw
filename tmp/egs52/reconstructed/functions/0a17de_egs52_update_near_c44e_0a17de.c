/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a17de; FLS offset 0x0217de.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a17ee) */
/* WARNING: Removing unreachable block (ram,0x0a17de) */
/* WARNING: Removing unreachable block (ram,0x0a17fc) */

undefined1 egs52_update_near_c44e_0a17de(uint param_1)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar2;
  
  iVar3 = Ram00f84e;
  if (iVar3 != 1) {
    return 0xf0;
  }
  uVar5 = 0xc43e;
  uVar4 = 0;
  do {
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
         *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
    param_1 = param_1 + 1;
    uVar5 = uVar5 + 1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  UNK_00c44e = 0;
  return 0;
}


