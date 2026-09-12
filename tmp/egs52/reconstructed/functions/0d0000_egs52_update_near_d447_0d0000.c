/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d0000; FLS offset 0x050000.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d000a) */
/* WARNING: Removing unreachable block (ram,0x0d004e) */
/* WARNING: Removing unreachable block (ram,0x0d0046) */
/* WARNING: Removing unreachable block (ram,0x0d0038) */
/* WARNING: Removing unreachable block (ram,0x0d0036) */
/* WARNING: Removing unreachable block (ram,0x0d0032) */
/* WARNING: Removing unreachable block (ram,0x0d002c) */
/* WARNING: Removing unreachable block (ram,0x0d0020) */
/* WARNING: Removing unreachable block (ram,0x0d001c) */
/* WARNING: Removing unreachable block (ram,0x0d007c) */
/* WARNING: Removing unreachable block (ram,0x0d006e) */
/* WARNING: Removing unreachable block (ram,0x0d006a) */
/* WARNING: Removing unreachable block (ram,0x0d0066) */
/* WARNING: Removing unreachable block (ram,0x0d0064) */
/* WARNING: Removing unreachable block (ram,0x0d0060) */
/* WARNING: Removing unreachable block (ram,0x0d005a) */
/* WARNING: Removing unreachable block (ram,0x0d0010) */

undefined2 egs52_update_near_d447_0d0000(char param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  undefined2 uVar6;
  
  if (param_1 == '\0') {
    bVar4 = UNK_00d447;
    UNK_00d447 = bVar4 & 0xef;
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = 1;
    return 1;
  }
  if (param_1 != '\x01') {
    if (param_1 != '\x02') {
      return 0;
    }
    iVar5 = Ram00f6fe;
    uVar3 = iVar5 + 3;
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
         *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0xbf;
    iVar5 = Ram00f652;
    uVar1 = iVar5 + 4;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    UNK_00d447 = *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar6 = egs52_call_095b6a_095abc(2);
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = uVar6;
    return 1;
  }
  iVar5 = Ram00f652;
  uVar1 = iVar5 + 5;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 2) == 0) {
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = 1;
    return 0;
  }
  iVar5 = Ram00f6fe;
  uVar3 = iVar5 + 3;
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
       *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) | 0x40;
  UNK_00d447 = 0;
  uVar6 = egs52_call_095b6a_095abc(2);
  uVar1 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = uVar6;
  return 1;
}


