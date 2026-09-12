/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3eba; FLS offset 0x023eba.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3ef0) */
/* WARNING: Removing unreachable block (ram,0x0a3f28) */
/* WARNING: Removing unreachable block (ram,0x0a3f58) */
/* WARNING: Removing unreachable block (ram,0x0a3f34) */
/* WARNING: Removing unreachable block (ram,0x0a3f0c) */
/* WARNING: Removing unreachable block (ram,0x0a3f48) */
/* WARNING: Removing unreachable block (ram,0x0a3f2c) */
/* WARNING: Removing unreachable block (ram,0x0a3f16) */
/* WARNING: Removing unreachable block (ram,0x0a3efe) */
/* WARNING: Removing unreachable block (ram,0x0a3eec) */
/* WARNING: Removing unreachable block (ram,0x0a3ee8) */
/* WARNING: Removing unreachable block (ram,0x0a3ec2) */
/* WARNING: Removing unreachable block (ram,0x0a3ebe) */
/* WARNING: Removing unreachable block (ram,0x0a3eba) */
/* WARNING: Removing unreachable block (ram,0x0a3f3c) */
/* WARNING: Removing unreachable block (ram,0x0a3f52) */
/* WARNING: Removing unreachable block (ram,0x0a3f1e) */
/* WARNING: Removing unreachable block (ram,0x0a3f4e) */
/* WARNING: Removing unreachable block (ram,0x0a3ecc) */
/* WARNING: Removing unreachable block (ram,0x0a3ee0) */
/* WARNING: Removing unreachable block (ram,0x0a3f44) */

undefined2 egs52_update_near_caaf_0a3eba(void)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  ushort count;
  uchar *destination;
  undefined2 uVar5;
  
  bVar2 = UNK_00caae;
  cVar4 = *(char *)((uint3)(bVar2 + 0x9ba) | 0x90000);
  UNK_00caaf = cVar4;
  if (cVar4 != -1) {
    do {
      bVar2 = UNK_00caae;
      bVar2 = *(byte *)((uint3)(bVar2 + 0x9ba) | 0x90000);
      UNK_00caaf = bVar2;
      if (bVar2 != 0xff) {
        iVar1 = *(int *)((uint3)((uint)bVar2 * 8 + 0x7f6) | 0x90000);
        if (iVar1 == 0) {
          Ram00cab0 = 1;
        }
        else {
          count = egs52_register_arithmetic_095b76(bVar2,iVar1);
          uVar3 = UNK_00caaf;
          destination = (uchar *)egs52_read_channel_table_word(uVar3);
          bVar2 = UNK_00caaf;
          egs52_memcpy_near(destination,*(uchar **)((uint3)((uint)bVar2 * 8 + 0x7f6) | 0x90000),
                            count);
          uVar3 = UNK_00caaf;
          bVar2 = UNK_00caaf;
          uVar5 = egs52_update_near_caa4_0a2fba
                            (uVar3,*(undefined2 *)((uint3)((uint)bVar2 * 8 + 0x7f6) | 0x90000));
          Ram00cab0 = uVar5;
        }
        iVar1 = Ram00cab0;
        if (iVar1 != 0) {
          cVar4 = UNK_00caae;
          UNK_00caae = cVar4 + '\x01';
        }
      }
      iVar1 = Ram00cab0;
    } while ((iVar1 != 0) && (cVar4 = UNK_00caaf, cVar4 != -1));
    return 1;
  }
  uVar5 = Ram00cab0;
  cVar4 = egs52_update_near_caa4_0a3d02(uVar5,0,0);
  if (cVar4 == '\x03') {
    UNK_00caae = 0;
    return 2;
  }
  return 1;
}


