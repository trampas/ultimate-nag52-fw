/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f05e; FLS offset 0x01f05e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Removing unreachable block (ram,0x09f0e2) */
/* WARNING: Removing unreachable block (ram,0x09f0e6) */
/* WARNING: Removing unreachable block (ram,0x09f0fc) */
/* WARNING: Removing unreachable block (ram,0x09f072) */
/* WARNING: Removing unreachable block (ram,0x09f102) */
/* WARNING: Removing unreachable block (ram,0x09f076) */
/* WARNING: Removing unreachable block (ram,0x09f0ee) */

char egs52_call_092118_09f05e(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  ushort count;
  ushort crc;
  
  bVar3 = 0;
  cVar2 = '\0';
  while (((*(int *)((uint3)((uint)bVar3 * 4 + 0x782) | 0x90000) != 0 &&
          (*(int *)((uint3)((uint)bVar3 * 4 + 0x784) | 0x90000) != 0)) && (cVar2 == '\0'))) {
    uVar4 = *(uint *)((uint3)((uint)bVar3 * 4 + 0x782) | 0x90000);
    count = *(int *)((uint3)((uint)bVar3 * 4 + 0x784) | 0x90000) - 10;
    crc = 0;
    while (count != 0) {
      if (count < 0x401) {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        crc = egs52_crc16_a001_far(uVar4 & 0x3fff | uVar1 << 0xe,uVar1 >> 2,count,crc);
        count = 0;
      }
      else {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        crc = egs52_crc16_a001_far(uVar4 & 0x3fff | uVar1 << 0xe,uVar1 >> 2,0x400,crc);
        count = count - 0x400;
        uVar4 = uVar4 + 0x400;
        egs52_service_watchdog(0xc001);
        egs52_update_near_c1aa_0994da();
      }
    }
    uVar1 = (*(int *)((uint3)((uint)bVar3 * 4 + 0x782) | 0x90000) +
            *(int *)((uint3)((uint)bVar3 * 4 + 0x784) | 0x90000)) - 2;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (crc != *(ushort *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      cVar2 = bVar3 + 1;
    }
    bVar3 = bVar3 + 1;
  }
  return cVar2;
}


