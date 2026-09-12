/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da300; FLS offset 0x05a300.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da36a) */
/* WARNING: Removing unreachable block (ram,0x0da366) */
/* WARNING: Removing unreachable block (ram,0x0da360) */
/* WARNING: Removing unreachable block (ram,0x0da35c) */
/* WARNING: Removing unreachable block (ram,0x0da34e) */
/* WARNING: Removing unreachable block (ram,0x0da34a) */
/* WARNING: Removing unreachable block (ram,0x0da342) */
/* WARNING: Removing unreachable block (ram,0x0da33e) */
/* WARNING: Removing unreachable block (ram,0x0da33a) */
/* WARNING: Removing unreachable block (ram,0x0da336) */
/* WARNING: Removing unreachable block (ram,0x0da332) */
/* WARNING: Removing unreachable block (ram,0x0da32e) */
/* WARNING: Removing unreachable block (ram,0x0da326) */
/* WARNING: Removing unreachable block (ram,0x0da322) */
/* WARNING: Removing unreachable block (ram,0x0da31e) */
/* WARNING: Removing unreachable block (ram,0x0da310) */
/* WARNING: Removing unreachable block (ram,0x0da30c) */
/* WARNING: Removing unreachable block (ram,0x0da300) */

void egs52_update_near_d56a_0da300(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ushort old;
  byte bVar4;
  int iVar5;
  char cVar6;
  undefined2 uVar7;
  ushort uVar8;
  
  cVar3 = UNK_00d579;
  uVar7 = egs52_compute_from_near_f636_0d892a(cVar3 + -1);
  Ram00d56a = uVar7;
  cVar3 = UNK_00d566;
  if (cVar3 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xffbf;
    iVar5 = Ram00f63a;
    uVar1 = iVar5 + 0x2f;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar6 = egs52_update_near_d5f6_0d7110();
    cVar3 = UNK_00d5b0;
    UNK_00d5b1 = cVar6 + cVar3;
    cVar3 = UNK_00d566;
    UNK_00d566 = cVar3 + '\x01';
  }
  else if (cVar3 != '\x01') goto LAB_0da360;
  old = Ram00d556;
  uVar8 = Ram00d552;
  bVar4 = UNK_00d5b0;
  uVar8 = egs52_ramp_u16(old,uVar8,(uint)bVar4);
  Ram00d556 = uVar8;
  cVar3 = UNK_00d579;
  uVar7 = egs52_update_near_d600_0d7cb8(cVar3 + -1,uVar8);
  Ram00d56c = uVar7;
LAB_0da360:
  cVar3 = UNK_00d5b1;
  if (cVar3 == '\0') {
    UNK_00d566 = 0;
    cVar3 = UNK_00d437;
    UNK_00d437 = cVar3 + '\x01';
  }
  return;
}


