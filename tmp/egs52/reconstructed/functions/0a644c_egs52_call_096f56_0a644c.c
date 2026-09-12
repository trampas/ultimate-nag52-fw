/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a644c; FLS offset 0x02644c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6478) */
/* WARNING: Removing unreachable block (ram,0x0a6470) */
/* WARNING: Removing unreachable block (ram,0x0a6468) */
/* WARNING: Removing unreachable block (ram,0x0a6460) */
/* WARNING: Removing unreachable block (ram,0x0a6452) */

undefined1 egs52_call_096f56_0a644c(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar3 = egs52_update_near_fd00_096f56
                    (*(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)),0);
  uVar1 = param_2 + 4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (uVar3 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
    uVar1 = param_2 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (uVar3 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      uVar1 = param_2 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (uVar3 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        uVar1 = param_2 + 6;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (uVar3 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          uVar4 = 2;
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 4;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 6;
  }
  return uVar4;
}


