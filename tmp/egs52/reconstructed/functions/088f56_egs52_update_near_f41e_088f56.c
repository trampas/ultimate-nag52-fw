/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088f56; FLS offset 0x008f56.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088fa8) */
/* WARNING: Removing unreachable block (ram,0x088fb0) */
/* WARNING: Removing unreachable block (ram,0x088fc0) */
/* WARNING: Removing unreachable block (ram,0x088f64) */
/* WARNING: Removing unreachable block (ram,0x088f90) */
/* WARNING: Removing unreachable block (ram,0x088f9a) */
/* WARNING: Removing unreachable block (ram,0x088fb4) */
/* WARNING: Removing unreachable block (ram,0x088fa4) */

void egs52_update_near_f41e_088f56(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  while (cVar5 = C1IR, cVar5 != '\0') {
    if (cVar5 == '\x01') {
      uVar2 = Ram00ef00;
      uVar1 = Ram00fde8;
      if ((bool)((byte)(uVar2 >> 0xf) ^ (byte)((uVar1 & 0x40) >> 6))) {
        uVar1 = Ram00fde8;
        uVar4 = Ram00fde8;
        Ram00fde8 = uVar4 & 0xffbf | (uVar2 >> 0xf) << 6;
        if ((uVar1 & 0x40) == 0x40) {
          egs52_update_near_f186_089090();
        }
      }
    }
    else {
      iVar3 = (uint)(byte)(cVar5 - 3U) * 0x10;
      uVar2 = iVar3 + 0xef10;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfffd;
      uVar4 = 0x8000 >> ((byte)(cVar5 - 3U) & 0xf);
      uVar1 = iVar3 + 0xef16;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) == 0) {
        bRam00f41c = bRam00f41c | 2;
        uRam00f420 = uRam00f420 | uVar4;
      }
      else {
        bRam00f41c = bRam00f41c | 1;
        uRam00f41e = uRam00f41e | uVar4;
      }
      egs52_update_near_f422_0894ca(0xf41a);
    }
  }
  return;
}


