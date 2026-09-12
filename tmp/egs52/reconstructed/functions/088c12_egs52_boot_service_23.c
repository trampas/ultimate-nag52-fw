/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088c12; FLS offset 0x008c12.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088cba) */
/* WARNING: Removing unreachable block (ram,0x088cbc) */
/* WARNING: Removing unreachable block (ram,0x088cb0) */
/* WARNING: Removing unreachable block (ram,0x088cc0) */
/* WARNING: Removing unreachable block (ram,0x088c90) */
/* WARNING: Removing unreachable block (ram,0x088c8a) */
/* WARNING: Removing unreachable block (ram,0x088c7e) */
/* WARNING: Removing unreachable block (ram,0x088c76) */
/* WARNING: Removing unreachable block (ram,0x088c6c) */
/* WARNING: Removing unreachable block (ram,0x088c68) */
/* WARNING: Removing unreachable block (ram,0x088cd6) */
/* WARNING: Removing unreachable block (ram,0x088cc8) */
/* WARNING: Removing unreachable block (ram,0x088c5c) */
/* WARNING: Removing unreachable block (ram,0x088c54) */
/* WARNING: Removing unreachable block (ram,0x088c50) */
/* WARNING: Removing unreachable block (ram,0x088ce0) */
/* WARNING: Removing unreachable block (ram,0x088c3e) */
/* WARNING: Removing unreachable block (ram,0x088c3a) */
/* WARNING: Removing unreachable block (ram,0x088c36) */
/* WARNING: Removing unreachable block (ram,0x088c32) */
/* WARNING: Removing unreachable block (ram,0x088c24) */
/* WARNING: Removing unreachable block (ram,0x088c1a) */
/* WARNING: Removing unreachable block (ram,0x088cea) */

void egs52_boot_service_23(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uStack_a;
  uint uStack_8;
  
  uVar5 = uRam00f464;
  if ((cRam00f469 == '\x05') && ((cRam00f468 == -1 || (uVar1 = Ram00fdec, (uVar1 & 0x20) == 0)))) {
    uVar1 = uRam00f462 + 3;
    uVar3 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar3 = 3;
    }
    cRam00f58e = *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    if ((cRam00f58e == '\0') || (cRam00f58e == -1)) {
      cRam00f581 = 'S';
    }
    else {
      uRam00f590 = uRam00f462;
      uRam00f592 = 0xff;
      egs52_update_near_f581_0824c8();
      if (cRam00f581 == '\0') {
        uVar1 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uStack_8 = (uint)(*(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) & 0x1f);
        uVar1 = uRam00f462 + 1;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar2 = uRam00f462 + 2;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        uStack_a = CONCAT11(*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                            *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)));
        cRam00f469 = cRam00f58e + '\x01';
        for (; cRam00f58e != '\0'; cRam00f58e = cRam00f58e + -1) {
          uVar1 = 0x24;
          if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
               *(undefined1 *)
                ((uint3)((uStack_8 & 0xff) << 2 | (uStack_a & 0x4000) >> 0xe |
                        (uStack_a >> 0xf) << 1) << 0xe | (uint3)(uStack_a & 0x3fff));
          uStack_8 = uStack_8 + (0xfffe < uStack_a);
          uVar5 = uVar5 + 1;
          uStack_a = uStack_a + 1;
        }
      }
      else if (cRam00f581 == '\"') {
        cRam00f581 = 'R';
      }
    }
  }
  else {
    cRam00f581 = 'y';
  }
  return;
}


