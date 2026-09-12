/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08115c; FLS offset 0x00115c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0812dc) */
/* WARNING: Removing unreachable block (ram,0x0812d8) */
/* WARNING: Removing unreachable block (ram,0x0812d4) */
/* WARNING: Removing unreachable block (ram,0x0812d0) */
/* WARNING: Removing unreachable block (ram,0x08120a) */
/* WARNING: Removing unreachable block (ram,0x081232) */
/* WARNING: Removing unreachable block (ram,0x0811c0) */
/* WARNING: Removing unreachable block (ram,0x081276) */
/* WARNING: Removing unreachable block (ram,0x081256) */
/* WARNING: Removing unreachable block (ram,0x0811b4) */
/* WARNING: Removing unreachable block (ram,0x0811a2) */
/* WARNING: Removing unreachable block (ram,0x08119e) */
/* WARNING: Removing unreachable block (ram,0x08119a) */
/* WARNING: Removing unreachable block (ram,0x081196) */
/* WARNING: Removing unreachable block (ram,0x081192) */
/* WARNING: Removing unreachable block (ram,0x081186) */
/* WARNING: Removing unreachable block (ram,0x081182) */
/* WARNING: Removing unreachable block (ram,0x08116c) */
/* WARNING: Removing unreachable block (ram,0x081168) */
/* WARNING: Removing unreachable block (ram,0x081246) */
/* WARNING: Removing unreachable block (ram,0x0811e4) */
/* WARNING: Removing unreachable block (ram,0x0812c6) */
/* WARNING: Removing unreachable block (ram,0x08120e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f3f0 : 0x08120a */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined1 egs52_update_near_f3fe_08115c(char param_1)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  uchar uVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  uRam00f3fe = 0x65;
  if (((cRam00f403 == '\x02') && (uVar1 = Ram00fdee, (uVar1 & 1) != 0)) &&
     (uRam00f3ff = 0xac, cRam00f406 == '\0')) {
    uRam00f400 = 0xca;
    egs52_update_near_f615_08172a(uRam00f3f0,uRam00f3f2,uRam00f3f4,uRam00f3f6);
    if (((param_1 == '\0') || (param_1 == '\x02')) && (bVar2 = UNK_00f615, (bVar2 & 4) != 0)) {
      uRam00f401 = 0x35;
      cVar3 = egs52_register_sequence_0810fc();
      if (cVar3 == '\x01') {
        uVar4 = egs52_register_sequence_081af0();
        if ((uVar4 != '\0') && (uVar4 = egs52_register_sequence_081b00(), uVar4 != '\0')) {
          UNK_00f615 = 0x20;
          egs52_transform_memory_081a92(0);
          egs52_update_near_f3e6_080c1a(0xf5d4,0,0xb,4);
          uVar1 = Ram00fdee;
          if ((uVar1 & 2) != 0) {
            if (param_1 == '\0') {
              uVar5 = egs52_compute_from_near_fdee_081a42(0x256,0x24,uRam090238);
            }
            else {
              egs52_update_near_f3e6_080c30(uRam00f3f0,uRam00f3f2);
              uVar1 = Ram00fdee;
              if ((uVar1 & 4) == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = 1;
              }
            }
          }
        }
      }
      else {
        uVar5 = egs52_compute_from_near_fdee_081a42(0x256,0x24,uRam090238);
      }
    }
    else if ((param_1 == '\x01') && ((bVar2 = UNK_00f615, (bVar2 & 2) != 0 || ((bVar2 & 4) != 0))))
    {
      uRam00f401 = 0x35;
      cVar3 = egs52_register_sequence_08112c();
      if (cVar3 == '\x01') {
        uVar4 = egs52_register_sequence_081af4();
        if ((uVar4 != '\0') && (uVar4 = egs52_register_sequence_081b04(), uVar4 != '\0')) {
          UNK_00f615 = 0x20;
          egs52_transform_memory_081a92(0);
          egs52_update_near_f3e6_080c1a(0xf5d4,0,9,4);
          uVar1 = Ram00fdee;
          if ((uVar1 & 2) != 0) {
            uVar5 = egs52_compute_from_near_fdee_081a42(0x26c,0x20,8);
          }
        }
      }
      else {
        uVar5 = egs52_compute_from_near_fdee_081a42(0x26c,0x20,8);
      }
    }
  }
  uRam00f3fe = 0;
  uRam00f3ff = 0;
  uRam00f400 = 0;
  uRam00f401 = 0;
  return uVar5;
}


