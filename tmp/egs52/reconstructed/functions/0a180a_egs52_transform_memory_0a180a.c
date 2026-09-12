/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a180a; FLS offset 0x02180a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1892) */
/* WARNING: Removing unreachable block (ram,0x0a1876) */
/* WARNING: Removing unreachable block (ram,0x0a1840) */
/* WARNING: Removing unreachable block (ram,0x0a1830) */
/* WARNING: Removing unreachable block (ram,0x0a1822) */
/* WARNING: Removing unreachable block (ram,0x0a1814) */
/* WARNING: Removing unreachable block (ram,0x0a18ac) */

undefined1 egs52_transform_memory_0a180a(byte param_1,uint param_2)

{
  uint uVar1;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar2;
  
  iVar3 = Ram00f84e;
  if (iVar3 == 1) {
    uVar6 = param_2 + 6;
    uVar5 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    if (*(char *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) == '\0') {
      uVar5 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      uVar6 = param_2 + (uint)*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) * 6;
      uVar5 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      if (*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) < 0x80) {
        if (param_1 == 0xff) {
          param_1 = egs52_register_arithmetic_0a134c(0);
        }
        if (param_1 == 0xfd) {
          uVar4 = 0xf0;
        }
        else {
          uVar5 = (uint)param_1 * 8 + 0xc450;
          uVar6 = 0;
          do {
            uVar1 = 0x24;
            if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            uVar2 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                 *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff));
            param_2 = param_2 + 1;
            uVar5 = uVar5 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < 8);
          uVar6 = (uint)(param_1 >> 4) * 2 + 0xc43c;
          uVar5 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar5 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          uVar1 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar6 & 0x3fff)) &
               ~(1 << (uint)param_1 % 0x10);
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0xf9;
      }
    }
    else {
      uVar4 = 0xf9;
    }
  }
  else {
    uVar4 = 0xf0;
  }
  return uVar4;
}


