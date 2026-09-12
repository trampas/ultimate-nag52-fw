/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081584; FLS offset 0x001584.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08171c) */
/* WARNING: Removing unreachable block (ram,0x081718) */
/* WARNING: Removing unreachable block (ram,0x081700) */
/* WARNING: Removing unreachable block (ram,0x0816f2) */
/* WARNING: Removing unreachable block (ram,0x0816ee) */
/* WARNING: Removing unreachable block (ram,0x0816c4) */
/* WARNING: Removing unreachable block (ram,0x0816c2) */
/* WARNING: Removing unreachable block (ram,0x0816be) */
/* WARNING: Removing unreachable block (ram,0x081694) */
/* WARNING: Removing unreachable block (ram,0x08168c) */
/* WARNING: Removing unreachable block (ram,0x081684) */
/* WARNING: Removing unreachable block (ram,0x081654) */
/* WARNING: Removing unreachable block (ram,0x081646) */
/* WARNING: Removing unreachable block (ram,0x081642) */
/* WARNING: Removing unreachable block (ram,0x081618) */
/* WARNING: Removing unreachable block (ram,0x081616) */
/* WARNING: Removing unreachable block (ram,0x081612) */
/* WARNING: Removing unreachable block (ram,0x0815e8) */
/* WARNING: Removing unreachable block (ram,0x0815e0) */
/* WARNING: Removing unreachable block (ram,0x0815d8) */
/* WARNING: Removing unreachable block (ram,0x0815a8) */
/* WARNING: Removing unreachable block (ram,0x081596) */
/* WARNING: Removing unreachable block (ram,0x08158e) */

uint egs52_update_near_f3fe_081584(void)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  uRam00f3fe = 0x53;
  uRam00f3ff = 0xac;
  uVar4 = egs52_call_081058_080f90(0xfe00,0xfefc);
  uVar4 = uVar4 & 0xff;
  if ((uRam00f3f8 & 9) == 9) {
    uVar4 = uVar4 | 0x8000;
  }
  cVar3 = egs52_register_sequence_0810fc();
  if (cVar3 == '\x02') {
    uVar5 = uVar4 | 0x4000;
    if ((uVar4 & 0x8020) == 0x8020) {
      uRam00f400 = 0xca;
      uRam00f401 = 0x35;
      UNK_00f615 = 0x20;
      egs52_transform_memory_081a92(0);
      uRam00f5d6 = 0x9048;
      uRam00f5d4 = 0x2442;
      uVar2 = UNK_00f615;
      egs52_update_near_f3e6_080c1a(0xf5d4,0,0xb,4);
      uVar1 = Ram00fdee;
      if ((uVar1 & 2) != 0) {
        uVar5 = uVar4 | 0x3000;
      }
      uRam00f400 = 0;
      uRam00f401 = 0;
    }
  }
  else {
    uVar5 = uVar4;
    if (cVar3 == '\x01') {
      uVar5 = uVar4 | 0x3000;
    }
  }
  if ((uRam00f3f8 & 0x120) == 0x120) {
    uVar5 = uVar5 | 0x800;
  }
  cVar3 = egs52_register_sequence_08112c();
  if (cVar3 == '\x02') {
    uVar4 = uVar5 | 0x400;
    if (((uVar5 & 0x800) != 0) && ((uVar5 & 0xb) == 0)) {
      uRam00f400 = 0xca;
      uRam00f401 = 0x35;
      UNK_00f615 = 0x20;
      egs52_transform_memory_081a92(0);
      uRam00f5d6 = 0x4224;
      uRam00f5d4 = 0x4890;
      uVar2 = UNK_00f615;
      egs52_update_near_f3e6_080c1a(0xf5d4,0,9,4);
      uVar1 = Ram00fdee;
      if ((uVar1 & 2) != 0) {
        uVar4 = uVar5 | 0x300;
      }
      uRam00f400 = 0;
      uRam00f401 = 0;
    }
  }
  else {
    uVar4 = uVar5;
    if (cVar3 == '\x01') {
      uVar4 = uVar5 | 0x300;
    }
  }
  if (cRam00f403 != '\x02') {
    uVar4 = uVar4 | 0x40;
  }
  if ((uVar4 & 0x1120) == 0x1120) {
    uVar4 = uVar4 | 0x80;
  }
  uRam00f3fe = 0;
  uRam00f3ff = 0;
  return uVar4;
}


