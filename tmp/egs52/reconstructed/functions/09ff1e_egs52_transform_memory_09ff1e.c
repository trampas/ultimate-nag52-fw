/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09ff1e; FLS offset 0x01ff1e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x09ff6c) */
/* WARNING: Removing unreachable block (ram,0x09ff64) */
/* WARNING: Removing unreachable block (ram,0x09ff60) */
/* WARNING: Removing unreachable block (ram,0x09ff5e) */
/* WARNING: Removing unreachable block (ram,0x09ff5a) */
/* WARNING: Removing unreachable block (ram,0x09ff4a) */
/* WARNING: Removing unreachable block (ram,0x09ff46) */
/* WARNING: Removing unreachable block (ram,0x09ff38) */

void egs52_transform_memory_09ff1e(byte param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  
  if (param_2 == '@') {
    uVar1 = (uint)param_1 * 0x14 + 0x9309;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar4 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 4;
    (*(code *)((uint3)*(uint *)((uint3)(iVar4 + 0xa2c) | 0x90000) << 0x10 |
              (uint3)*(uint *)((uint3)(iVar4 + 0xa2a) | 0x90000)))(param_1,0xff);
    uVar2 = param_1 + 0xc3ac;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) | 4;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xf7;
    egs52_update_near_fd6c_0a2120(param_1);
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0x10) == 0) {
      uVar5 = 5;
    }
    else {
      uVar5 = 7;
    }
    egs52_update_near_fd6c_0a1cc8(param_1,uVar5);
  }
  return;
}


