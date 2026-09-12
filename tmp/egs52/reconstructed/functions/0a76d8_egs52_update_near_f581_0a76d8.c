/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a76d8; FLS offset 0x0276d8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a779a) */
/* WARNING: Removing unreachable block (ram,0x0a7794) */
/* WARNING: Removing unreachable block (ram,0x0a7774) */
/* WARNING: Removing unreachable block (ram,0x0a7764) */
/* WARNING: Removing unreachable block (ram,0x0a775e) */
/* WARNING: Removing unreachable block (ram,0x0a774e) */
/* WARNING: Removing unreachable block (ram,0x0a774a) */
/* WARNING: Removing unreachable block (ram,0x0a775a) */
/* WARNING: Removing unreachable block (ram,0x0a7756) */
/* WARNING: Removing unreachable block (ram,0x0a7732) */
/* WARNING: Removing unreachable block (ram,0x0a771e) */
/* WARNING: Removing unreachable block (ram,0x0a7718) */
/* WARNING: Removing unreachable block (ram,0x0a7714) */
/* WARNING: Removing unreachable block (ram,0x0a7710) */
/* WARNING: Removing unreachable block (ram,0x0a772a) */
/* WARNING: Removing unreachable block (ram,0x0a7704) */
/* WARNING: Removing unreachable block (ram,0x0a76e2) */
/* WARNING: Removing unreachable block (ram,0x0a76de) */
/* WARNING: Removing unreachable block (ram,0x0a76da) */
/* WARNING: Removing unreachable block (ram,0x0a776e) */
/* WARNING: Removing unreachable block (ram,0x0a77a4) */
/* WARNING: Removing unreachable block (ram,0x0a777c) */
/* WARNING: Removing unreachable block (ram,0x0a778e) */
/* WARNING: Removing unreachable block (ram,0x0a77ae) */

void egs52_update_near_f581_0a76d8(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  uchar uVar5;
  uint uVar6;
  
  uRam00f581 = 0;
  uVar6 = 0x24;
  if ((((uRam00f462 & 0xc000) != 0) && (uVar6 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  cVar3 = *(char *)((uint3)uVar6 << 0xe | (uint3)(uRam00f462 & 0x3fff));
  if (cVar3 == ' ') {
    if (cRam00f469 == '\x02') {
      uVar4 = egs52_compute_from_near_c32b_09ed5c();
      uVar6 = iRam00f464 + 1;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = uVar4;
      uRam00f581 = 0;
      cRam00f469 = '\x03';
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else if (cVar3 == '!') {
    if (cRam00f469 == '\x02') {
      uVar6 = egs52_register_arithmetic_09edae();
      if (uVar6 < 0x100) {
        uVar1 = iRam00f464 + 1;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = (char)uVar6;
      }
      else {
        uVar6 = iRam00f464 + 1;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0xff;
      }
      uRam00f581 = 0;
      cRam00f469 = '\x03';
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else if ((cVar3 == '$') || (cVar3 == '\"')) {
    if (cRam00f469 == '\x02') {
      uVar5 = egs52_read_indexed_word_c044((uchar *)(iRam00f464 + 1));
      if (uVar5 == '\0') {
        uRam00f581 = 0;
        cRam00f469 = '\x04';
      }
      else {
        uRam00f581 = 0x23;
      }
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else {
    uRam00f581 = 0x12;
    uVar6 = Ram00fdec;
    Ram00fdec = uVar6 & 0xfffe;
  }
  return;
}


