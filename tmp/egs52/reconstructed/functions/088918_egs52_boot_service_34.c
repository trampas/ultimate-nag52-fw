/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088918; FLS offset 0x008918.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08899a) */
/* WARNING: Removing unreachable block (ram,0x088994) */
/* WARNING: Removing unreachable block (ram,0x088992) */
/* WARNING: Removing unreachable block (ram,0x08898e) */
/* WARNING: Removing unreachable block (ram,0x088988) */
/* WARNING: Removing unreachable block (ram,0x0889a4) */
/* WARNING: Removing unreachable block (ram,0x08897a) */
/* WARNING: Removing unreachable block (ram,0x088974) */
/* WARNING: Removing unreachable block (ram,0x08896e) */
/* WARNING: Removing unreachable block (ram,0x08896a) */
/* WARNING: Removing unreachable block (ram,0x088962) */
/* WARNING: Removing unreachable block (ram,0x08895c) */
/* WARNING: Removing unreachable block (ram,0x088956) */
/* WARNING: Removing unreachable block (ram,0x088950) */
/* WARNING: Removing unreachable block (ram,0x08894c) */
/* WARNING: Removing unreachable block (ram,0x0889ae) */
/* WARNING: Removing unreachable block (ram,0x088946) */
/* WARNING: Removing unreachable block (ram,0x088934) */
/* WARNING: Removing unreachable block (ram,0x0889cc) */
/* WARNING: Removing unreachable block (ram,0x08891c) */
/* WARNING: Removing unreachable block (ram,0x088924) */
/* WARNING: Removing unreachable block (ram,0x0889c2) */
/* WARNING: Removing unreachable block (ram,0x088930) */
/* WARNING: Removing unreachable block (ram,0x0889b8) */

void egs52_boot_service_34(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  
  if (cRam00f407 == '\0') {
    if (cRam00f469 == '\b') {
      uVar1 = 0x24;
      if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff));
      if (((bVar3 & 0xe0) == 0x80) || ((bVar3 & 0xe0) == 0)) {
        uVar1 = uRam00f462 + 3;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
          uRam00f3f3 = 0;
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          bRam00f3f2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) & 0x1f;
          uVar2 = uRam00f462 + 1;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uRam00f3f1 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar2 = uRam00f462 + 2;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uRam00f3f0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar2 = uRam00f462 + 4;
          uRam00f3f7 = 0;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uRam00f3f6 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar2 = uRam00f462 + 5;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uRam00f3f5 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
          uVar2 = uRam00f462 + 6;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uRam00f3f4 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
          cVar4 = egs52_update_near_f406_0812e8();
          if (cVar4 == '\x01') {
            uVar1 = 0x24;
            if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) = cRam00f468 + -1;
            uRam00f581 = 0;
            cRam00f469 = '\x02';
          }
          else {
            uRam00f581 = 0x40;
          }
        }
        else {
          uRam00f581 = 0x22;
        }
      }
      else {
        uRam00f581 = 0x41;
      }
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else {
    uRam00f581 = 0x22;
  }
  return;
}


