/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09b302; FLS offset 0x01b302.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09b378) */
/* WARNING: Removing unreachable block (ram,0x09b364) */
/* WARNING: Removing unreachable block (ram,0x09b354) */
/* WARNING: Removing unreachable block (ram,0x09b350) */
/* WARNING: Removing unreachable block (ram,0x09b342) */
/* WARNING: Removing unreachable block (ram,0x09b388) */
/* WARNING: Removing unreachable block (ram,0x09b31a) */
/* WARNING: Removing unreachable block (ram,0x09b332) */
/* WARNING: Removing unreachable block (ram,0x09b32e) */
/* WARNING: Removing unreachable block (ram,0x09b392) */
/* WARNING: Removing unreachable block (ram,0x09b38e) */
/* WARNING: Removing unreachable block (ram,0x09b322) */
/* WARNING: Removing unreachable block (ram,0x09b308) */
/* WARNING: Removing unreachable block (ram,0x09b384) */
/* WARNING: Removing unreachable block (ram,0x09b346) */

void egs52_update_near_c2c3_09b302(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  byte bVar5;
  
  uVar1 = Ram00fd02;
  if ((uVar1 & 0x40) != 0) {
    cVar4 = UNK_00c2c3;
    if (cVar4 == '\0') {
      uVar1 = Ram00ffc4;
      if ((uVar1 & 0x800) == 0) {
        cVar4 = UNK_00c2ba;
        UNK_00c2ba = cVar4 + '\x01';
      }
      else {
        bVar5 = UNK_00c2ba;
        if (bVar5 < 0xc) {
          UNK_00c2ba = 0;
          UNK_00c2c3 = 0;
        }
        else {
          UNK_00c2c3 = 1;
          UNK_00c2ba = 0;
        }
      }
    }
    else if (cVar4 == '\x01') {
      uVar3 = Ram00ffc4;
      if (((byte)((uint)uVar3 >> 8) & 8) == 8) {
        cVar4 = UNK_00c2ba;
        UNK_00c2ba = cVar4 + '\x01';
        bVar5 = UNK_00c2ba;
        if (0xb < bVar5) {
          UNK_00c2ba = 0;
          UNK_00c2c3 = 0;
          uVar1 = Ram00fd02;
          Ram00fd02 = uVar1 & 0xffbf;
          uVar1 = Ram00fd02;
          Ram00fd02 = uVar1 & 0xff7f;
          egs52_update_near_f57f_0a4446();
          egs52_update_near_f1c6_0a4430();
          UNK_00c2b8 = 0;
          bVar5 = 0;
          do {
            uVar1 = (uint)bVar5 * 0x34 + 0xe000;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
            bVar5 = bVar5 + 1;
          } while (bVar5 < 2);
        }
      }
      else {
        UNK_00c2ba = 0;
        UNK_00c2c3 = 0;
      }
    }
  }
  return;
}


