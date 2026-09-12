/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089dbe; FLS offset 0x009dbe.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x089dec) */
/* WARNING: Removing unreachable block (ram,0x089dd6) */
/* WARNING: Removing unreachable block (ram,0x089e16) */
/* WARNING: Removing unreachable block (ram,0x089e12) */
/* WARNING: Removing unreachable block (ram,0x089dbe) */
/* WARNING: Removing unreachable block (ram,0x089e00) */
/* WARNING: Removing unreachable block (ram,0x089de8) */

void egs52_call_083132_089dbe(uint param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  cVar2 = *(char *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff));
  if (cVar2 == '\x12') {
    param_1 = param_1 + 2;
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar3 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) * 0x12;
    (*(code *)((uint3)*(uint *)((uint3)(iVar3 + 0xffe) | 0x88000) << 0x10 |
              (uint3)*(uint *)((uint3)(iVar3 + 0xffc) | 0x88000)))();
    return;
  }
  if (cVar2 == '\x13') {
    egs52_update_near_fdea_0826f6();
    return;
  }
  if (cVar2 == '\x14') {
    param_1 = param_1 + 2;
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar3 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) * 0x12;
    (*(code *)((uint3)*(uint *)((uint3)(iVar3 + 0xffa) | 0x88000) << 0x10 |
              (uint3)*(uint *)((uint3)(iVar3 + 0xff8) | 0x88000)))();
  }
  return;
}


