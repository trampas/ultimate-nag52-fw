/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088a90; FLS offset 0x008a90.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x088c02) */
/* WARNING: Removing unreachable block (ram,0x088bfe) */
/* WARNING: Removing unreachable block (ram,0x088bd2) */
/* WARNING: Removing unreachable block (ram,0x088bce) */
/* WARNING: Removing unreachable block (ram,0x088bca) */
/* WARNING: Removing unreachable block (ram,0x088bc6) */
/* WARNING: Removing unreachable block (ram,0x088bc2) */
/* WARNING: Removing unreachable block (ram,0x088b84) */
/* WARNING: Removing unreachable block (ram,0x088b6a) */
/* WARNING: Removing unreachable block (ram,0x088b66) */
/* WARNING: Removing unreachable block (ram,0x088b50) */
/* WARNING: Removing unreachable block (ram,0x088b4c) */
/* WARNING: Removing unreachable block (ram,0x088b48) */
/* WARNING: Removing unreachable block (ram,0x088b44) */
/* WARNING: Removing unreachable block (ram,0x088b40) */
/* WARNING: Removing unreachable block (ram,0x088b36) */
/* WARNING: Removing unreachable block (ram,0x088b24) */
/* WARNING: Removing unreachable block (ram,0x088bbe) */
/* WARNING: Removing unreachable block (ram,0x088ba0) */
/* WARNING: Removing unreachable block (ram,0x088bb0) */
/* WARNING: Removing unreachable block (ram,0x088b9c) */
/* WARNING: Removing unreachable block (ram,0x088b1a) */
/* WARNING: Removing unreachable block (ram,0x088b12) */
/* WARNING: Removing unreachable block (ram,0x088b0a) */
/* WARNING: Removing unreachable block (ram,0x088b02) */
/* WARNING: Removing unreachable block (ram,0x088afa) */
/* WARNING: Removing unreachable block (ram,0x088aec) */
/* WARNING: Removing unreachable block (ram,0x088be6) */
/* WARNING: Removing unreachable block (ram,0x088ade) */
/* WARNING: Removing unreachable block (ram,0x088ad6) */
/* WARNING: Removing unreachable block (ram,0x088ad2) */
/* WARNING: Removing unreachable block (ram,0x088ac6) */
/* WARNING: Removing unreachable block (ram,0x088abe) */
/* WARNING: Removing unreachable block (ram,0x088ab8) */
/* WARNING: Removing unreachable block (ram,0x088ab4) */
/* WARNING: Removing unreachable block (ram,0x088ab0) */
/* WARNING: Removing unreachable block (ram,0x088aa6) */
/* WARNING: Removing unreachable block (ram,0x088aa0) */
/* WARNING: Removing unreachable block (ram,0x088a9a) */
/* WARNING: Removing unreachable block (ram,0x088bfa) */
/* WARNING: Removing unreachable block (ram,0x088bf0) */
/* WARNING: Removing unreachable block (ram,0x088aca) */
/* WARNING: Removing unreachable block (ram,0x088bd8) */
/* WARNING: Removing unreachable block (ram,0x088af0) */
/* WARNING: Removing unreachable block (ram,0x088bb6) */
/* WARNING: Removing unreachable block (ram,0x088ba2) */
/* WARNING: Removing unreachable block (ram,0x088bb2) */
/* WARNING: Removing unreachable block (ram,0x088b2e) */
/* WARNING: Removing unreachable block (ram,0x088b7a) */
/* WARNING: Removing unreachable block (ram,0x088b8e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f462 : 0x088ab4 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_3d(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  undefined2 uStack_c;
  uint uStack_a;
  
  uVar6 = uRam00f462 + 3;
  uVar3 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if ((uint)bRam00f469 == *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) + 5) {
    uVar3 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    bRam00f58e = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff));
    uVar3 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    bVar5 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff));
    if (bRam00f58e == 0) {
      cRam00f581 = '\"';
    }
    else {
      uRam00f590 = uRam00f462;
      uRam00f592 = 0;
      (*(code *)((uint3)uRam08021a << 0x10 | (uint3)uRam080218))();
      if (cRam00f581 == '\0') {
        uVar3 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uStack_a = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff)) & 0xff1f;
        uVar3 = uRam00f462 + 1;
        uVar6 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar6 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar2 = uRam00f462 + 2;
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        uStack_c = CONCAT11(*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar3 & 0x3fff)),
                            *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)));
        uRam00f462 = uRam00f462 + 4;
        uRam00f3fe = 0x53;
        uRam00f3ff = 0xac;
        if ((bVar5 & 0xe0) == 0x80) {
          if (cRam00f407 == '\0') {
            uRam00f400 = 0xca;
            uRam00f401 = 0x35;
            uRam00f3e6 = uStack_c;
            uRam00f3e8 = uStack_a;
            uRam00f3ec = (uint)bRam00f58e;
            uRam00f3ea = uRam00f462;
            egs52_update_near_f615_08172a(uStack_c,uStack_a,0,0);
            __write_psw_bits(0x800,0);
            (*(code *)((uint3)uRam08020e << 0x10 | (uint3)uRam08020c))();
            __write_psw_bits(0x800,0x800);
            uVar3 = Ram00fdee;
            if ((uVar3 & 2) == 0) {
              cRam00f581 = '@';
            }
            else {
              bRam00f469 = 1;
            }
          }
          else {
            cRam00f581 = '\"';
          }
        }
        else {
          for (; bRam00f58e != 0; bRam00f58e = bRam00f58e - 1) {
            uVar3 = 0x24;
            if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            uVar6 = uRam00f462 & 0x3fff;
            uRam00f462 = uRam00f462 + 1;
            bVar1 = 0xfffe < uStack_c;
            *(undefined1 *)CONCAT12((char)uStack_a,uStack_c) =
                 *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)uVar6);
            uStack_c = uStack_c + 1;
            uStack_a = uStack_a + bVar1;
          }
          bRam00f469 = 1;
        }
        uRam00f401 = 0;
        uRam00f400 = 0;
        uRam00f3ff = 0;
        uRam00f3fe = 0;
      }
      else if (cRam00f581 == '\"') {
        cRam00f581 = 'B';
      }
    }
  }
  else {
    cRam00f581 = 'y';
  }
  uRam00f462 = uRam00f464;
  return;
}


