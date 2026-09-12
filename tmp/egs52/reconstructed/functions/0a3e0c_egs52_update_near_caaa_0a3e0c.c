/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3e0c; FLS offset 0x023e0c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3ea2) */
/* WARNING: Removing unreachable block (ram,0x0a3e32) */
/* WARNING: Removing unreachable block (ram,0x0a3e6a) */
/* WARNING: Removing unreachable block (ram,0x0a3e9c) */
/* WARNING: Removing unreachable block (ram,0x0a3e52) */
/* WARNING: Removing unreachable block (ram,0x0a3e60) */
/* WARNING: Removing unreachable block (ram,0x0a3eac) */
/* WARNING: Removing unreachable block (ram,0x0a3e90) */
/* WARNING: Removing unreachable block (ram,0x0a3e72) */
/* WARNING: Removing unreachable block (ram,0x0a3e56) */
/* WARNING: Removing unreachable block (ram,0x0a3e3e) */
/* WARNING: Removing unreachable block (ram,0x0a3e38) */
/* WARNING: Removing unreachable block (ram,0x0a3e0c) */
/* WARNING: Removing unreachable block (ram,0x0a3e7c) */
/* WARNING: Removing unreachable block (ram,0x0a3e88) */
/* WARNING: Removing unreachable block (ram,0x0a3e98) */
/* WARNING: Removing unreachable block (ram,0x0a3e16) */
/* WARNING: Removing unreachable block (ram,0x0a3e2a) */
/* WARNING: Removing unreachable block (ram,0x0a3e80) */
/* WARNING: Removing unreachable block (ram,0x0a3ea6) */

undefined2 egs52_update_near_caaa_0a3e0c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  undefined1 uVar5;
  char cVar6;
  ushort count;
  uchar *destination;
  undefined2 uVar7;
  
  bVar4 = UNK_00caaa;
  if (bVar4 < 0x35) {
    do {
      bVar4 = UNK_00caaa;
      iVar2 = *(int *)((uint3)((uint)bVar4 * 8 + 0x7f6) | 0x90000);
      if (iVar2 == 0) {
        Ram00caac = 1;
      }
      else {
        cVar6 = UNK_00caaa;
        if ((byte)(cVar6 - 2U) < 9) {
          uVar3 = (uint)(byte)(cVar6 - 2U) * 2 + 0x2766;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
                    /* WARNING: Switch is manually overridden */
          switch((uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) | 0xa0000) {
          case 0xa3e56:
            uVar5 = UNK_00caaa;
            count = egs52_register_arithmetic_095b76(uVar5,iVar2);
            uVar5 = UNK_00caaa;
            destination = (uchar *)egs52_read_channel_table_word(uVar5);
            bVar4 = UNK_00caaa;
            egs52_memcpy_near(destination,*(uchar **)((uint3)((uint)bVar4 * 8 + 0x7f6) | 0x90000),
                              count);
          }
        }
        uVar5 = UNK_00caaa;
        bVar4 = UNK_00caaa;
        uVar7 = egs52_update_near_caa4_0a2fba
                          (uVar5,*(undefined2 *)((uint3)((uint)bVar4 * 8 + 0x7f6) | 0x90000));
        Ram00caac = uVar7;
      }
      iVar2 = Ram00caac;
      if (iVar2 != 0) {
        cVar6 = UNK_00caaa;
        UNK_00caaa = cVar6 + '\x01';
      }
      iVar2 = Ram00caac;
    } while ((iVar2 != 0) && (bVar4 = UNK_00caaa, bVar4 < 0x35));
    return 1;
  }
  uVar7 = Ram00caac;
  cVar6 = egs52_update_near_caa4_0a3d02(uVar7,0,0);
  if (cVar6 == '\x03') {
    UNK_00caaa = 0;
    return 2;
  }
  return 1;
}


