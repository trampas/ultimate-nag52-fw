/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a7c20; FLS offset 0x027c20.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a7cf8) */
/* WARNING: Removing unreachable block (ram,0x0a7cca) */
/* WARNING: Removing unreachable block (ram,0x0a7c94) */
/* WARNING: Removing unreachable block (ram,0x0a7cce) */
/* WARNING: Removing unreachable block (ram,0x0a7caa) */
/* WARNING: Removing unreachable block (ram,0x0a7c66) */
/* WARNING: Removing unreachable block (ram,0x0a7ca6) */
/* WARNING: Removing unreachable block (ram,0x0a7c5e) */
/* WARNING: Removing unreachable block (ram,0x0a7ce8) */
/* WARNING: Removing unreachable block (ram,0x0a7c7e) */
/* WARNING: Removing unreachable block (ram,0x0a7c46) */
/* WARNING: Removing unreachable block (ram,0x0a7c40) */
/* WARNING: Removing unreachable block (ram,0x0a7c3c) */
/* WARNING: Removing unreachable block (ram,0x0a7c30) */
/* WARNING: Removing unreachable block (ram,0x0a7c70) */
/* WARNING: Removing unreachable block (ram,0x0a7c82) */
/* WARNING: Removing unreachable block (ram,0x0a7cdc) */
/* WARNING: Removing unreachable block (ram,0x0a7ce0) */
/* WARNING: Removing unreachable block (ram,0x0a7c98) */
/* WARNING: Removing unreachable block (ram,0x0a7cfc) */

void egs52_transform_memory_0a7c20(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = param_1 - 0x744;
  uVar2 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) != '\0') {
    __write_psw_bits(0xf000,0xd000);
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) =
         *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) | 0x80;
    __write_psw_bits(0xf000,0x1000);
    do {
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar8 = egs52_register_sequence_0a7dea
                        (*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)));
      if (6 < iVar8) break;
      __write_psw_bits(0xf000,0xd000);
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = iVar8 * 2 + 0xa88;
      uVar4 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar5 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar5 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar7 & 0x3fff)) =
           *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) &
           ~(byte)*(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff));
      __write_psw_bits(0xf000,0x1000);
      iVar8 = param_1 * 4 + iVar8 * 0x10;
      uVar2 = iVar8 + 0xade;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar4 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar2 = iVar8 + 0xae0;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (uVar2 != 0 || uVar4 != 0) {
        iVar8 = 0;
        while( true ) {
          uVar3 = iVar8 * 4 + 0xad6;
          uVar5 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          uVar1 = iVar8 * 4 + 0xad8;
          uVar6 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          if (*(int *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff)) == 0 &&
              *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0) break;
          uVar3 = iVar8 * 4 + 0xad6;
          uVar5 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          uVar1 = iVar8 * 4 + 0xad8;
          uVar6 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          (*(code *)((uint3)*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) << 0x10 |
                    (uint3)*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff))))();
          iVar8 = iVar8 + 1;
        }
        __write_psw_bits(0xf000,0);
        (*(code *)((uint3)uVar2 << 0x10 | (uint3)uVar4))(0);
        __write_psw_bits(0xf000,0x1000);
        iVar8 = 0;
        while( true ) {
          uVar2 = iVar8 * 4 + 0xada;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar4 = iVar8 * 4 + 0xadc;
          uVar5 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0 &&
              *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) == 0) break;
          uVar2 = iVar8 * 4 + 0xada;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar4 = iVar8 * 4 + 0xadc;
          uVar5 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          (*(code *)((uint3)*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) << 0x10 |
                    (uint3)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))))();
          iVar8 = iVar8 + 1;
        }
      }
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
    } while (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) != -0x80);
    __write_psw_bits(0xf000,0xd000);
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar3 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar7 & 0x3fff)) =
         *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0x7f;
    __write_psw_bits(0xf000,0x1000);
  }
  return;
}


