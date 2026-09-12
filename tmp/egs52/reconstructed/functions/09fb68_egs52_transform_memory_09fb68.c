/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09fb68; FLS offset 0x01fb68.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x09fba6) */
/* WARNING: Removing unreachable block (ram,0x09fba2) */
/* WARNING: Removing unreachable block (ram,0x09fb9a) */
/* WARNING: Removing unreachable block (ram,0x09fb84) */
/* WARNING: Removing unreachable block (ram,0x09fb7a) */
/* WARNING: Removing unreachable block (ram,0x09fb6a) */

undefined2 egs52_transform_memory_09fb68(byte param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  
  iVar4 = Ram00f84c;
  if (iVar4 == 0) {
    uVar5 = 0xff;
  }
  else {
    uVar3 = param_1 + 0xc3ac;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0x80 | 0x28;
    uVar1 = (uint)param_1 * 0x14 + 0x9309;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar4 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) * 4;
    (*(code *)((uint3)*(uint *)((uint3)(iVar4 + 0xa2c) | 0x90000) << 0x10 |
              (uint3)*(uint *)((uint3)(iVar4 + 0xa2a) | 0x90000)))(param_1,0);
    uVar5 = 0;
  }
  return uVar5;
}


