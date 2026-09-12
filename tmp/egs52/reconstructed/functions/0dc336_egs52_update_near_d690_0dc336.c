/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dc336; FLS offset 0x05c336.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Removing unreachable block (ram,0x0dcc9e) */
/* WARNING: Removing unreachable block (ram,0x0dcc92) */
/* WARNING: Removing unreachable block (ram,0x0dcc82) */
/* WARNING: Removing unreachable block (ram,0x0dc9ce) */
/* WARNING: Removing unreachable block (ram,0x0dc9c6) */
/* WARNING: Removing unreachable block (ram,0x0dc9be) */
/* WARNING: Removing unreachable block (ram,0x0dc9ba) */
/* WARNING: Removing unreachable block (ram,0x0dc9b6) */
/* WARNING: Removing unreachable block (ram,0x0dc9b2) */
/* WARNING: Removing unreachable block (ram,0x0dc9aa) */
/* WARNING: Removing unreachable block (ram,0x0dc9a6) */
/* WARNING: Removing unreachable block (ram,0x0dc99e) */
/* WARNING: Removing unreachable block (ram,0x0dc97e) */
/* WARNING: Removing unreachable block (ram,0x0dc97a) */
/* WARNING: Removing unreachable block (ram,0x0dc976) */
/* WARNING: Removing unreachable block (ram,0x0dc972) */
/* WARNING: Removing unreachable block (ram,0x0dc996) */
/* WARNING: Removing unreachable block (ram,0x0dc992) */
/* WARNING: Removing unreachable block (ram,0x0dc960) */
/* WARNING: Removing unreachable block (ram,0x0dc94e) */
/* WARNING: Removing unreachable block (ram,0x0dc94a) */
/* WARNING: Removing unreachable block (ram,0x0dc946) */
/* WARNING: Removing unreachable block (ram,0x0dc942) */
/* WARNING: Removing unreachable block (ram,0x0dc936) */
/* WARNING: Removing unreachable block (ram,0x0dc928) */
/* WARNING: Removing unreachable block (ram,0x0dc924) */
/* WARNING: Removing unreachable block (ram,0x0dc920) */
/* WARNING: Removing unreachable block (ram,0x0dc91c) */
/* WARNING: Removing unreachable block (ram,0x0dc918) */
/* WARNING: Removing unreachable block (ram,0x0dc906) */
/* WARNING: Removing unreachable block (ram,0x0dc8fe) */
/* WARNING: Removing unreachable block (ram,0x0dc8ee) */
/* WARNING: Removing unreachable block (ram,0x0dc8ea) */
/* WARNING: Removing unreachable block (ram,0x0dc8b0) */
/* WARNING: Removing unreachable block (ram,0x0dc8b2) */
/* WARNING: Removing unreachable block (ram,0x0dc8ce) */
/* WARNING: Removing unreachable block (ram,0x0dc8a0) */
/* WARNING: Removing unreachable block (ram,0x0dc8c2) */
/* WARNING: Removing unreachable block (ram,0x0dc8ac) */
/* WARNING: Removing unreachable block (ram,0x0dc8d4) */
/* WARNING: Removing unreachable block (ram,0x0dc8c0) */
/* WARNING: Removing unreachable block (ram,0x0dc8b8) */
/* WARNING: Removing unreachable block (ram,0x0dc8a2) */
/* WARNING: Removing unreachable block (ram,0x0dc898) */
/* WARNING: Removing unreachable block (ram,0x0dc88a) */
/* WARNING: Removing unreachable block (ram,0x0dc884) */
/* WARNING: Removing unreachable block (ram,0x0dc874) */
/* WARNING: Removing unreachable block (ram,0x0dc870) */
/* WARNING: Removing unreachable block (ram,0x0dc882) */
/* WARNING: Removing unreachable block (ram,0x0dc87a) */
/* WARNING: Removing unreachable block (ram,0x0dc86a) */
/* WARNING: Removing unreachable block (ram,0x0dc860) */
/* WARNING: Removing unreachable block (ram,0x0dc85a) */
/* WARNING: Removing unreachable block (ram,0x0dc84a) */
/* WARNING: Removing unreachable block (ram,0x0dc846) */
/* WARNING: Removing unreachable block (ram,0x0dc842) */
/* WARNING: Removing unreachable block (ram,0x0dc83c) */
/* WARNING: Removing unreachable block (ram,0x0dc834) */
/* WARNING: Removing unreachable block (ram,0x0dc82e) */
/* WARNING: Removing unreachable block (ram,0x0dc81e) */
/* WARNING: Removing unreachable block (ram,0x0dc81a) */
/* WARNING: Removing unreachable block (ram,0x0dc82c) */
/* WARNING: Removing unreachable block (ram,0x0dc824) */
/* WARNING: Removing unreachable block (ram,0x0dc814) */
/* WARNING: Removing unreachable block (ram,0x0dc80a) */
/* WARNING: Removing unreachable block (ram,0x0dc804) */
/* WARNING: Removing unreachable block (ram,0x0dc7f4) */
/* WARNING: Removing unreachable block (ram,0x0dc7f0) */
/* WARNING: Removing unreachable block (ram,0x0dc7ec) */
/* WARNING: Removing unreachable block (ram,0x0dc7e6) */
/* WARNING: Removing unreachable block (ram,0x0dc7de) */
/* WARNING: Removing unreachable block (ram,0x0dc7d4) */
/* WARNING: Removing unreachable block (ram,0x0dc7cc) */
/* WARNING: Removing unreachable block (ram,0x0dc7ca) */
/* WARNING: Removing unreachable block (ram,0x0dc7b8) */
/* WARNING: Removing unreachable block (ram,0x0dc7b2) */
/* WARNING: Removing unreachable block (ram,0x0dc7ae) */
/* WARNING: Removing unreachable block (ram,0x0dc7aa) */
/* WARNING: Removing unreachable block (ram,0x0dc79a) */
/* WARNING: Removing unreachable block (ram,0x0dc796) */
/* WARNING: Removing unreachable block (ram,0x0dc7a8) */
/* WARNING: Removing unreachable block (ram,0x0dc7a0) */
/* WARNING: Removing unreachable block (ram,0x0dc790) */
/* WARNING: Removing unreachable block (ram,0x0dc786) */
/* WARNING: Removing unreachable block (ram,0x0dc780) */
/* WARNING: Removing unreachable block (ram,0x0dc770) */
/* WARNING: Removing unreachable block (ram,0x0dc76c) */
/* WARNING: Removing unreachable block (ram,0x0dc768) */
/* WARNING: Removing unreachable block (ram,0x0dc762) */
/* WARNING: Removing unreachable block (ram,0x0dc75a) */
/* WARNING: Removing unreachable block (ram,0x0dc754) */
/* WARNING: Removing unreachable block (ram,0x0dc740) */
/* WARNING: Removing unreachable block (ram,0x0dc73c) */
/* WARNING: Removing unreachable block (ram,0x0dc752) */
/* WARNING: Removing unreachable block (ram,0x0dc74c) */
/* WARNING: Removing unreachable block (ram,0x0dc746) */
/* WARNING: Removing unreachable block (ram,0x0dc736) */
/* WARNING: Removing unreachable block (ram,0x0dc730) */
/* WARNING: Removing unreachable block (ram,0x0dc72a) */
/* WARNING: Removing unreachable block (ram,0x0dc71a) */
/* WARNING: Removing unreachable block (ram,0x0dc716) */
/* WARNING: Removing unreachable block (ram,0x0dc712) */
/* WARNING: Removing unreachable block (ram,0x0dc70c) */
/* WARNING: Removing unreachable block (ram,0x0dc706) */
/* WARNING: Removing unreachable block (ram,0x0dc6fc) */
/* WARNING: Removing unreachable block (ram,0x0dc6f4) */
/* WARNING: Removing unreachable block (ram,0x0dc6f0) */
/* WARNING: Removing unreachable block (ram,0x0dc6e8) */
/* WARNING: Removing unreachable block (ram,0x0dc6e2) */
/* WARNING: Removing unreachable block (ram,0x0dc6de) */
/* WARNING: Removing unreachable block (ram,0x0dc6da) */
/* WARNING: Removing unreachable block (ram,0x0dc696) */
/* WARNING: Removing unreachable block (ram,0x0dc6ba) */
/* WARNING: Removing unreachable block (ram,0x0dc694) */
/* WARNING: Removing unreachable block (ram,0x0dc6bc) */
/* WARNING: Removing unreachable block (ram,0x0dc6a6) */
/* WARNING: Removing unreachable block (ram,0x0dc690) */
/* WARNING: Removing unreachable block (ram,0x0dc6c4) */
/* WARNING: Removing unreachable block (ram,0x0dc6aa) */
/* WARNING: Removing unreachable block (ram,0x0dc684) */
/* WARNING: Removing unreachable block (ram,0x0dc67a) */
/* WARNING: Removing unreachable block (ram,0x0dc66a) */
/* WARNING: Removing unreachable block (ram,0x0dc662) */
/* WARNING: Removing unreachable block (ram,0x0dc650) */
/* WARNING: Removing unreachable block (ram,0x0dc64c) */
/* WARNING: Removing unreachable block (ram,0x0dc660) */
/* WARNING: Removing unreachable block (ram,0x0dc658) */
/* WARNING: Removing unreachable block (ram,0x0dc63e) */
/* WARNING: Removing unreachable block (ram,0x0dc634) */
/* WARNING: Removing unreachable block (ram,0x0dc62e) */
/* WARNING: Removing unreachable block (ram,0x0dc61e) */
/* WARNING: Removing unreachable block (ram,0x0dc61a) */
/* WARNING: Removing unreachable block (ram,0x0dc616) */
/* WARNING: Removing unreachable block (ram,0x0dc60c) */
/* WARNING: Removing unreachable block (ram,0x0dc604) */
/* WARNING: Removing unreachable block (ram,0x0dc5fe) */
/* WARNING: Removing unreachable block (ram,0x0dc5ec) */
/* WARNING: Removing unreachable block (ram,0x0dc5e8) */
/* WARNING: Removing unreachable block (ram,0x0dc5fc) */
/* WARNING: Removing unreachable block (ram,0x0dc5f4) */
/* WARNING: Removing unreachable block (ram,0x0dc5da) */
/* WARNING: Removing unreachable block (ram,0x0dc5d0) */
/* WARNING: Removing unreachable block (ram,0x0dc5ca) */
/* WARNING: Removing unreachable block (ram,0x0dc5ba) */
/* WARNING: Removing unreachable block (ram,0x0dc5b6) */
/* WARNING: Removing unreachable block (ram,0x0dc5b2) */
/* WARNING: Removing unreachable block (ram,0x0dc5a8) */
/* WARNING: Removing unreachable block (ram,0x0dc5a0) */
/* WARNING: Removing unreachable block (ram,0x0dc596) */
/* WARNING: Removing unreachable block (ram,0x0dc58e) */
/* WARNING: Removing unreachable block (ram,0x0dc58c) */
/* WARNING: Removing unreachable block (ram,0x0dc57e) */
/* WARNING: Removing unreachable block (ram,0x0dc57a) */
/* WARNING: Removing unreachable block (ram,0x0dc568) */
/* WARNING: Removing unreachable block (ram,0x0dc564) */
/* WARNING: Removing unreachable block (ram,0x0dc578) */
/* WARNING: Removing unreachable block (ram,0x0dc570) */
/* WARNING: Removing unreachable block (ram,0x0dc556) */
/* WARNING: Removing unreachable block (ram,0x0dc54c) */
/* WARNING: Removing unreachable block (ram,0x0dc546) */
/* WARNING: Removing unreachable block (ram,0x0dc536) */
/* WARNING: Removing unreachable block (ram,0x0dc532) */
/* WARNING: Removing unreachable block (ram,0x0dc52e) */
/* WARNING: Removing unreachable block (ram,0x0dc524) */
/* WARNING: Removing unreachable block (ram,0x0dc51c) */
/* WARNING: Removing unreachable block (ram,0x0dc516) */
/* WARNING: Removing unreachable block (ram,0x0dc500) */
/* WARNING: Removing unreachable block (ram,0x0dc4fc) */
/* WARNING: Removing unreachable block (ram,0x0dc514) */
/* WARNING: Removing unreachable block (ram,0x0dc50e) */
/* WARNING: Removing unreachable block (ram,0x0dc508) */
/* WARNING: Removing unreachable block (ram,0x0dc4ee) */
/* WARNING: Removing unreachable block (ram,0x0dc4e8) */
/* WARNING: Removing unreachable block (ram,0x0dc4e2) */
/* WARNING: Removing unreachable block (ram,0x0dc4d2) */
/* WARNING: Removing unreachable block (ram,0x0dc4ce) */
/* WARNING: Removing unreachable block (ram,0x0dc4ca) */
/* WARNING: Removing unreachable block (ram,0x0dc4c0) */
/* WARNING: Removing unreachable block (ram,0x0dc4ba) */
/* WARNING: Removing unreachable block (ram,0x0dc4b0) */
/* WARNING: Removing unreachable block (ram,0x0dc4a8) */
/* WARNING: Removing unreachable block (ram,0x0dc4a4) */
/* WARNING: Removing unreachable block (ram,0x0dc4a0) */
/* WARNING: Removing unreachable block (ram,0x0dc49c) */
/* WARNING: Removing unreachable block (ram,0x0dc494) */
/* WARNING: Removing unreachable block (ram,0x0dc490) */
/* WARNING: Removing unreachable block (ram,0x0dc488) */
/* WARNING: Removing unreachable block (ram,0x0dc480) */
/* WARNING: Removing unreachable block (ram,0x0dc47a) */
/* WARNING: Removing unreachable block (ram,0x0dc476) */
/* WARNING: Removing unreachable block (ram,0x0dc46a) */
/* WARNING: Removing unreachable block (ram,0x0dc460) */
/* WARNING: Removing unreachable block (ram,0x0dc45c) */
/* WARNING: Removing unreachable block (ram,0x0dc458) */
/* WARNING: Removing unreachable block (ram,0x0dc44e) */
/* WARNING: Removing unreachable block (ram,0x0dc44a) */
/* WARNING: Removing unreachable block (ram,0x0dc444) */
/* WARNING: Removing unreachable block (ram,0x0dc43e) */
/* WARNING: Removing unreachable block (ram,0x0dc43a) */
/* WARNING: Removing unreachable block (ram,0x0dc42e) */
/* WARNING: Removing unreachable block (ram,0x0dc426) */
/* WARNING: Removing unreachable block (ram,0x0dc422) */
/* WARNING: Removing unreachable block (ram,0x0dc41e) */
/* WARNING: Removing unreachable block (ram,0x0dc41a) */
/* WARNING: Removing unreachable block (ram,0x0dc40e) */
/* WARNING: Removing unreachable block (ram,0x0dc40a) */
/* WARNING: Removing unreachable block (ram,0x0dc406) */
/* WARNING: Removing unreachable block (ram,0x0dc3fe) */
/* WARNING: Removing unreachable block (ram,0x0dc3fa) */
/* WARNING: Removing unreachable block (ram,0x0dc3f2) */
/* WARNING: Removing unreachable block (ram,0x0dcad0) */
/* WARNING: Removing unreachable block (ram,0x0dcacc) */
/* WARNING: Removing unreachable block (ram,0x0dcac8) */
/* WARNING: Removing unreachable block (ram,0x0dcac6) */
/* WARNING: Removing unreachable block (ram,0x0dcac2) */
/* WARNING: Removing unreachable block (ram,0x0dcaba) */
/* WARNING: Removing unreachable block (ram,0x0dcab6) */
/* WARNING: Removing unreachable block (ram,0x0dcab4) */
/* WARNING: Removing unreachable block (ram,0x0dcaae) */
/* WARNING: Removing unreachable block (ram,0x0dcaa8) */
/* WARNING: Removing unreachable block (ram,0x0dcaa6) */
/* WARNING: Removing unreachable block (ram,0x0dcaa2) */
/* WARNING: Removing unreachable block (ram,0x0dcaa0) */
/* WARNING: Removing unreachable block (ram,0x0dca9c) */
/* WARNING: Removing unreachable block (ram,0x0dca94) */
/* WARNING: Removing unreachable block (ram,0x0dca90) */
/* WARNING: Removing unreachable block (ram,0x0dca8e) */
/* WARNING: Removing unreachable block (ram,0x0dca88) */
/* WARNING: Removing unreachable block (ram,0x0dca82) */
/* WARNING: Removing unreachable block (ram,0x0dca80) */
/* WARNING: Removing unreachable block (ram,0x0dca76) */
/* WARNING: Removing unreachable block (ram,0x0dca74) */
/* WARNING: Removing unreachable block (ram,0x0dca6c) */
/* WARNING: Removing unreachable block (ram,0x0dca68) */
/* WARNING: Removing unreachable block (ram,0x0dca5c) */
/* WARNING: Removing unreachable block (ram,0x0dca58) */
/* WARNING: Removing unreachable block (ram,0x0dca54) */
/* WARNING: Removing unreachable block (ram,0x0dcafc) */
/* WARNING: Removing unreachable block (ram,0x0dcaf8) */
/* WARNING: Removing unreachable block (ram,0x0dcaf4) */
/* WARNING: Removing unreachable block (ram,0x0dcaec) */
/* WARNING: Removing unreachable block (ram,0x0dcb14) */
/* WARNING: Removing unreachable block (ram,0x0dcb10) */
/* WARNING: Removing unreachable block (ram,0x0dcb0c) */
/* WARNING: Removing unreachable block (ram,0x0dcb04) */
/* WARNING: Removing unreachable block (ram,0x0dcae4) */
/* WARNING: Removing unreachable block (ram,0x0dcae0) */
/* WARNING: Removing unreachable block (ram,0x0dcad8) */
/* WARNING: Removing unreachable block (ram,0x0dca4c) */
/* WARNING: Removing unreachable block (ram,0x0dca48) */
/* WARNING: Removing unreachable block (ram,0x0dcb24) */
/* WARNING: Removing unreachable block (ram,0x0dcb20) */
/* WARNING: Removing unreachable block (ram,0x0dcb1c) */
/* WARNING: Removing unreachable block (ram,0x0dca38) */
/* WARNING: Removing unreachable block (ram,0x0dca30) */
/* WARNING: Removing unreachable block (ram,0x0dca2c) */
/* WARNING: Removing unreachable block (ram,0x0dca1c) */
/* WARNING: Removing unreachable block (ram,0x0dca18) */
/* WARNING: Removing unreachable block (ram,0x0dca0c) */
/* WARNING: Removing unreachable block (ram,0x0dca08) */
/* WARNING: Removing unreachable block (ram,0x0dc9fc) */
/* WARNING: Removing unreachable block (ram,0x0dca04) */
/* WARNING: Removing unreachable block (ram,0x0dc9f4) */
/* WARNING: Removing unreachable block (ram,0x0dc9ec) */
/* WARNING: Removing unreachable block (ram,0x0dc9e6) */
/* WARNING: Removing unreachable block (ram,0x0dc9de) */
/* WARNING: Removing unreachable block (ram,0x0dc9da) */
/* WARNING: Removing unreachable block (ram,0x0dc9d6) */
/* WARNING: Removing unreachable block (ram,0x0dc3de) */
/* WARNING: Removing unreachable block (ram,0x0dc3d2) */
/* WARNING: Removing unreachable block (ram,0x0dc3c6) */
/* WARNING: Removing unreachable block (ram,0x0dc3c2) */
/* WARNING: Removing unreachable block (ram,0x0dc3b6) */
/* WARNING: Removing unreachable block (ram,0x0dcc18) */
/* WARNING: Removing unreachable block (ram,0x0dcc14) */
/* WARNING: Removing unreachable block (ram,0x0dcc10) */
/* WARNING: Removing unreachable block (ram,0x0dcc04) */
/* WARNING: Removing unreachable block (ram,0x0dcc08) */
/* WARNING: Removing unreachable block (ram,0x0dcbfa) */
/* WARNING: Removing unreachable block (ram,0x0dcbee) */
/* WARNING: Removing unreachable block (ram,0x0dcbe4) */
/* WARNING: Removing unreachable block (ram,0x0dcbea) */
/* WARNING: Removing unreachable block (ram,0x0dcbdc) */
/* WARNING: Removing unreachable block (ram,0x0dcbcc) */
/* WARNING: Removing unreachable block (ram,0x0dcbca) */
/* WARNING: Removing unreachable block (ram,0x0dcbc6) */
/* WARNING: Removing unreachable block (ram,0x0dcbc0) */
/* WARNING: Removing unreachable block (ram,0x0dcbbe) */
/* WARNING: Removing unreachable block (ram,0x0dcbb0) */
/* WARNING: Removing unreachable block (ram,0x0dcbaa) */
/* WARNING: Removing unreachable block (ram,0x0dcba0) */
/* WARNING: Removing unreachable block (ram,0x0dcb9c) */
/* WARNING: Removing unreachable block (ram,0x0dcb9a) */
/* WARNING: Removing unreachable block (ram,0x0dcb96) */
/* WARNING: Removing unreachable block (ram,0x0dcb90) */
/* WARNING: Removing unreachable block (ram,0x0dcb8c) */
/* WARNING: Removing unreachable block (ram,0x0dcb88) */
/* WARNING: Removing unreachable block (ram,0x0dcb82) */
/* WARNING: Removing unreachable block (ram,0x0dcb78) */
/* WARNING: Removing unreachable block (ram,0x0dcb74) */
/* WARNING: Removing unreachable block (ram,0x0dcb6c) */
/* WARNING: Removing unreachable block (ram,0x0dcb68) */
/* WARNING: Removing unreachable block (ram,0x0dcb60) */
/* WARNING: Removing unreachable block (ram,0x0dcb5c) */
/* WARNING: Removing unreachable block (ram,0x0dcb58) */
/* WARNING: Removing unreachable block (ram,0x0dcb54) */
/* WARNING: Removing unreachable block (ram,0x0dcb48) */
/* WARNING: Removing unreachable block (ram,0x0dcb44) */
/* WARNING: Removing unreachable block (ram,0x0dcb40) */
/* WARNING: Removing unreachable block (ram,0x0dcc7c) */
/* WARNING: Removing unreachable block (ram,0x0dcc78) */
/* WARNING: Removing unreachable block (ram,0x0dcc74) */
/* WARNING: Removing unreachable block (ram,0x0dcc6e) */
/* WARNING: Removing unreachable block (ram,0x0dcc6a) */
/* WARNING: Removing unreachable block (ram,0x0dcc5a) */
/* WARNING: Removing unreachable block (ram,0x0dcc62) */
/* WARNING: Removing unreachable block (ram,0x0dcc52) */
/* WARNING: Removing unreachable block (ram,0x0dcc3e) */
/* WARNING: Removing unreachable block (ram,0x0dcc46) */
/* WARNING: Removing unreachable block (ram,0x0dcc36) */
/* WARNING: Removing unreachable block (ram,0x0dcc32) */
/* WARNING: Removing unreachable block (ram,0x0dcc2c) */
/* WARNING: Removing unreachable block (ram,0x0dcc24) */
/* WARNING: Removing unreachable block (ram,0x0dcc1e) */
/* WARNING: Removing unreachable block (ram,0x0dcb38) */
/* WARNING: Removing unreachable block (ram,0x0dcb34) */
/* WARNING: Removing unreachable block (ram,0x0dcb2c) */
/* WARNING: Removing unreachable block (ram,0x0dc3a6) */
/* WARNING: Removing unreachable block (ram,0x0dccc0) */
/* WARNING: Removing unreachable block (ram,0x0dccbc) */
/* WARNING: Removing unreachable block (ram,0x0dccb8) */
/* WARNING: Removing unreachable block (ram,0x0dccb4) */
/* WARNING: Removing unreachable block (ram,0x0dccb0) */
/* WARNING: Removing unreachable block (ram,0x0dccac) */
/* WARNING: Removing unreachable block (ram,0x0dcca8) */
/* WARNING: Removing unreachable block (ram,0x0dcca4) */
/* WARNING: Removing unreachable block (ram,0x0dc394) */
/* WARNING: Removing unreachable block (ram,0x0dc38c) */
/* WARNING: Removing unreachable block (ram,0x0dc384) */
/* WARNING: Removing unreachable block (ram,0x0dc380) */
/* WARNING: Removing unreachable block (ram,0x0dc376) */
/* WARNING: Removing unreachable block (ram,0x0dc36e) */
/* WARNING: Removing unreachable block (ram,0x0dc36a) */
/* WARNING: Removing unreachable block (ram,0x0dc360) */
/* WARNING: Removing unreachable block (ram,0x0dc35c) */
/* WARNING: Removing unreachable block (ram,0x0dc350) */
/* WARNING: Removing unreachable block (ram,0x0dc348) */
/* WARNING: Removing unreachable block (ram,0x0dc340) */
/* WARNING: Removing unreachable block (ram,0x0dc358) */
/* WARNING: Removing unreachable block (ram,0x0dc3a2) */
/* WARNING: Removing unreachable block (ram,0x0dc3ae) */
/* WARNING: Removing unreachable block (ram,0x0dc3ee) */
/* WARNING: Removing unreachable block (ram,0x0dc698) */
/* WARNING: Removing unreachable block (ram,0x0dc6b6) */
/* WARNING: Removing unreachable block (ram,0x0dc682) */
/* WARNING: Removing unreachable block (ram,0x0dc6a8) */
/* WARNING: Removing unreachable block (ram,0x0dc8c4) */
/* WARNING: Removing unreachable block (ram,0x0dc8d2) */
/* WARNING: Removing unreachable block (ram,0x0dc8dc) */
/* WARNING: Removing unreachable block (ram,0x0dc8bc) */
/* WARNING: Removing unreachable block (ram,0x0dc930) */
/* WARNING: Removing unreachable block (ram,0x0dc9ca) */
/* WARNING: Removing unreachable block (ram,0x0dc3be) */
/* WARNING: Removing unreachable block (ram,0x0dc8d8) */
/* WARNING: Removing unreachable block (ram,0x0dc6a2) */
/* WARNING: Removing unreachable block (ram,0x0dc6c0) */

void egs52_update_near_d690_0dc336(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  byte bVar12;
  undefined1 uVar13;
  char cVar14;
  int iVar15;
  int iVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  byte bVar19;
  byte bVar20;
  ushort uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  
  iVar22 = Ram00d684;
  if (iVar22 != 0) {
    return;
  }
  iVar22 = Ram00d644;
  if (iVar22 < 0) {
    iVar22 = Ram00d644;
    iVar22 = -iVar22;
  }
  else {
    iVar22 = Ram00d644;
  }
  iVar23 = Ram00f652;
  uVar24 = iVar23 + 0x9c;
  uVar2 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) <= iVar22) {
LAB_0dcca4:
    Ram00d680 = 0;
    Ram00d66c = 0;
    Ram00d66e = 0;
    iVar22 = Ram00f652;
    uVar24 = iVar22 + 0x80;
    uVar2 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d684 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
    uVar24 = iVar22 + 0xf0;
    uVar2 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6ec = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
    return;
  }
  uVar24 = iVar23 + 0x9b;
  uVar2 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar19 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
  bVar20 = UNK_00d649;
  bVar7 = UNK_00d649;
  if ((bVar19 == bVar7 || bVar19 < bVar20) || (cVar14 = UNK_00d704, cVar14 != '\x03'))
  goto LAB_0dcca4;
  uVar24 = iVar23 + 0x34;
  uVar2 = 0x24;
  if (((uVar24 & 0xc000) != 0) &&
     ((uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)))) {
    uVar2 = 3;
  }
  uVar24 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
  uVar2 = Ram00d63e;
  uVar5 = Ram00d63e;
  if (((uVar24 == uVar5 || uVar24 < uVar2) || (cVar14 = UNK_00d650, cVar14 != '\0')) ||
     (bVar19 = UNK_00d647, bVar19 < 3)) goto LAB_0dcca4;
  uVar5 = Ram00d706;
  uVar24 = Ram00d660;
  uVar2 = Ram00d660;
  if (uVar5 == uVar2 || uVar5 < uVar24) {
    iVar22 = Ram00f652;
    uVar2 = iVar22 + 0x24;
    uVar24 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar24 = 3;
    }
    uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar5 = Ram00d680;
    uVar9 = Ram00d680;
    if (uVar24 == uVar9 || uVar24 < uVar5) {
      uVar17 = Ram00d66c;
      uVar18 = Ram00d66e;
      uVar24 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar24 = 3;
      }
      Ram00d690 = (int)(CONCAT22(uVar18,uVar17) /
                       (long)(ulong)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)));
      iVar22 = Ram00f652;
      uVar24 = iVar22 + 0x1a;
      uVar2 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar22 = Ram00d690;
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar22) {
        uVar17 = Ram00d65e;
        uVar13 = UNK_00d649;
        egs52_update_near_d688_0da630(uVar17,uVar13);
        bVar19 = UNK_00d689;
        iVar22 = Ram00f6fe;
        uVar2 = iVar22 + 4 + (uint)bVar19;
        uVar24 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar24 = 3;
        }
        if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
          iVar23 = Ram00f652;
          uVar24 = iVar23 + 0x3e;
          uVar5 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar5 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          bVar19 = UNK_00d649;
          if (*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar19) {
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar5 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
          }
        }
        bVar19 = UNK_00d689;
        iVar23 = Ram00f6fe;
        uVar2 = iVar23 + 3 + (uint)bVar19;
        uVar24 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar24 = 3;
        }
        if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
          iVar10 = Ram00f652;
          uVar5 = iVar10 + 0x41;
          uVar24 = 0x24;
          if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          bVar19 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
          bVar20 = UNK_00d649;
          bVar7 = UNK_00d649;
          if (bVar19 != bVar7 && bVar20 <= bVar19) {
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar5 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
          }
        }
        iVar10 = Ram00d68e;
        uVar24 = Ram00d660;
        if (iVar10 * 3 + 0xcU < uVar24) {
          iVar10 = Ram00d660;
          Ram00d660 = iVar10 + -0xc;
        }
        else {
          Ram00d660 = iVar10 * 3;
        }
        for (bVar19 = UNK_00d689; bVar19 != 0; bVar19 = bVar19 - 1) {
          uVar2 = iVar22 + 4 + (uint)bVar19;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          uVar9 = iVar23 + 3 + (uint)bVar19;
          uVar5 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar5 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) <
              *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar9 & 0x3fff))) {
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar5 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                 *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
          }
        }
      }
      Ram00d680 = 0;
      Ram00d66c = 0;
      Ram00d66e = 0;
    }
    else {
      iVar22 = Ram00d680;
      if ((iVar22 == 0) || (cVar14 = UNK_00d696, cVar14 == '\x02')) {
        iVar22 = Ram00d680;
        Ram00d680 = iVar22 + 1;
        UNK_00d696 = 2;
        iVar22 = Ram00d6a8;
        if (iVar22 < 0) {
          iVar22 = Ram00d6a8;
          iVar22 = -iVar22;
        }
        else {
          iVar22 = Ram00d6a8;
        }
        if (iVar22 < 0) {
          uVar24 = 0;
        }
        else {
          iVar22 = Ram00d6a8;
          if (iVar22 < 0) {
            iVar22 = Ram00d6a8;
            uVar24 = -iVar22;
          }
          else {
            uVar24 = Ram00d6a8;
          }
        }
        uVar2 = Ram00d66c;
        Ram00d66c = uVar2 + uVar24;
        iVar22 = Ram00d66e;
        Ram00d66e = iVar22 + ((int)uVar24 >> 0xf) + (uint)CARRY2(uVar2,uVar24);
      }
      else {
        Ram00d680 = 0;
        Ram00d66c = 0;
        Ram00d66e = 0;
      }
    }
    goto LAB_0dcc80;
  }
  iVar22 = Ram00d662;
  if (iVar22 < 0) {
    iVar22 = Ram00d662;
    iVar22 = -iVar22;
  }
  else {
    iVar22 = Ram00d662;
  }
  iVar23 = Ram00f652;
  uVar24 = iVar23 + 0xa9;
  uVar2 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((((int)(uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) <= iVar22) ||
      (uVar24 = Ram00fd2a, (uVar24 & 1) == 0)) || (iVar22 = Ram00d6e0, iVar22 < 1)) {
    iVar22 = Ram00f652;
    uVar24 = iVar22 + 0x38;
    uVar2 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar23 = Ram00d65e;
    if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar23) {
      uVar24 = iVar22 + 0x36;
      uVar2 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar22 = (int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
      iVar23 = Ram00d65e;
      iVar10 = Ram00d65e;
      if (iVar22 != iVar10 && iVar23 <= iVar22) {
        iVar22 = Ram00d662;
        if (iVar22 < 0) {
          iVar22 = Ram00d662;
          uVar24 = -iVar22;
        }
        else {
          uVar24 = Ram00d662;
        }
        iVar22 = Ram00f652;
        uVar2 = iVar22 + 0xac;
        uVar5 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        if (uVar24 < *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff))) {
          uVar24 = iVar22 + 0x3a;
          uVar2 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar5 = Ram00d63e;
          if ((*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < uVar5) &&
             (uVar24 = Ram00fd2a, (uVar24 & 1) == 0)) {
            uVar24 = iVar22 + 0x9a;
            uVar2 = 0x24;
            if (((uVar24 & 0xc000) != 0) &&
               ((uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000 &&
                (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)))) {
              uVar2 = 3;
            }
            bVar19 = UNK_00d649;
            if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar19) &&
               (iVar23 = Ram00d694, iVar23 != 0)) {
              uVar2 = iVar22 + 0x24;
              uVar24 = 0x24;
              if (((uVar2 & 0xc000) != 0) &&
                 ((uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
                  (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
                uVar24 = 3;
              }
              uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
              uVar5 = Ram00d680;
              uVar9 = Ram00d680;
              if (uVar24 == uVar9 || uVar24 < uVar5) {
                uVar17 = Ram00d66c;
                uVar18 = Ram00d66e;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                Ram00d690 = (int)(CONCAT22(uVar18,uVar17) /
                                 (long)(ulong)*(byte *)((uint3)uVar24 << 0xe |
                                                       (uint3)(uVar2 & 0x3fff)));
                iVar22 = Ram00f652;
                uVar2 = iVar22 + 0xae;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                iVar22 = Ram00f652;
                uVar9 = iVar22 + 0x3c;
                uVar5 = 0x24;
                if ((((uVar9 & 0xc000) != 0) && (uVar5 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                iVar22 = Ram00d690;
                if (*(int *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                    *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar9 & 0x3fff)) < iVar22) {
                  iVar22 = Ram00f6fe;
                  uVar5 = iVar22 + 2;
                  uVar24 = 0x24;
                  if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  iVar22 = Ram00f652;
                  uVar1 = iVar22 + 0xb0;
                  uVar4 = 0x24;
                  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff)) <
                      *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) {
                    uVar24 = 0x24;
                    if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                       (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                      uVar24 = 3;
                    }
                    uVar1 = 0x24;
                    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                      uVar1 = 3;
                    }
                    *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                         *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff)) + '\x01';
                  }
                }
                uVar24 = 0x24;
                if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                iVar22 = *(int *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff)) -
                         *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff));
                iVar23 = Ram00d690;
                iVar10 = Ram00d690;
                if (iVar22 != iVar10 && iVar23 <= iVar22) {
                  iVar22 = Ram00f6fe;
                  uVar2 = iVar22 + 2;
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  iVar22 = Ram00f652;
                  uVar5 = iVar22 + 0xad;
                  uVar9 = 0x24;
                  if ((((uVar5 & 0xc000) != 0) && (uVar9 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                     (uVar9 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                    uVar9 = 3;
                  }
                  if (*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar5 & 0x3fff)) <
                      *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff))) {
                    uVar24 = 0x24;
                    if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                       (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                      uVar24 = 3;
                    }
                    uVar5 = 0x24;
                    if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                       (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                      uVar5 = 3;
                    }
                    *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                         *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
                  }
                }
                Ram00d680 = 0;
                Ram00d66c = 0;
                Ram00d66e = 0;
              }
              else {
                iVar22 = Ram00d680;
                if (iVar22 == 0) {
                  UNK_00d696 = 1;
                }
                cVar14 = UNK_00d696;
                if (cVar14 == '\x01') {
                  uVar24 = Ram00d666;
                  uVar2 = Ram00d66c;
                  Ram00d66c = uVar2 + uVar24;
                  iVar22 = Ram00d66e;
                  Ram00d66e = iVar22 + ((int)uVar24 >> 0xf) + (uint)CARRY2(uVar2,uVar24);
                  iVar22 = Ram00d680;
                  Ram00d680 = iVar22 + 1;
                }
                else {
                  iVar22 = Ram00d680;
                  if (iVar22 == 0) {
                    Ram00d680 = 0;
                    Ram00d66c = 0;
                    Ram00d66e = 0;
                  }
                }
              }
              goto LAB_0dcc80;
            }
          }
        }
      }
    }
    Ram00d680 = 0;
    Ram00d66c = 0;
    Ram00d66e = 0;
    goto LAB_0dcc80;
  }
  uVar2 = iVar23 + 0x24;
  uVar24 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar24 = 3;
  }
  uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
  uVar5 = Ram00d680;
  uVar9 = Ram00d680;
  if (uVar24 != uVar9 && uVar5 <= uVar24) {
    iVar22 = Ram00d680;
    if ((iVar22 == 0) || (cVar14 = UNK_00d696, cVar14 == '\0')) {
      iVar23 = Ram00d6f8;
      iVar22 = Ram00d660;
      iVar10 = Ram00f652;
      uVar24 = iVar10 + 0x37;
      uVar2 = 0x24;
      if (((uVar24 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000))
         )) {
        uVar2 = 3;
      }
      uVar5 = (uint)(((long)(iVar23 - iVar22) *
                     (long)(int)(uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff))) /
                    100);
      iVar22 = (int)uVar5 >> 0xf;
      uVar24 = iVar10 + 0x10c;
      uVar2 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar24 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
      iVar23 = (int)uVar24 >> 0xf;
      uVar2 = (uint)(uVar5 < uVar24);
      if (iVar22 - iVar23 == uVar2 && uVar5 == uVar24 ||
          (int)((iVar22 - iVar23) - uVar2) < 0 !=
          (SBORROW2(iVar22,iVar23) != SBORROW2(iVar22 - iVar23,(uint)(uVar5 < uVar24)))) {
        iVar22 = Ram00f652;
        uVar24 = iVar22 + 0x10c;
        uVar2 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar24 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
      }
      else {
        iVar23 = Ram00d6f8;
        iVar22 = Ram00d660;
        iVar10 = Ram00f652;
        uVar24 = iVar10 + 0x37;
        uVar2 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar24 = (uint)(((long)(iVar23 - iVar22) *
                        (long)(int)(uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)))
                       / 100);
      }
      uVar2 = Ram00d666;
      uVar5 = Ram00d66c;
      iVar22 = Ram00d66e;
      Ram00d66c = (uVar2 + uVar5) - uVar24;
      Ram00d66e = ((((int)uVar2 >> 0xf) + iVar22 + (uint)CARRY2(uVar2,uVar5)) - ((int)uVar24 >> 0xf)
                  ) - (uint)(uVar2 + uVar5 < uVar24);
      iVar22 = Ram00d680;
      Ram00d680 = iVar22 + 1;
      UNK_00d696 = 0;
    }
    else {
      Ram00d680 = 0;
      Ram00d66c = 0;
      Ram00d66e = 0;
    }
    goto LAB_0dcc80;
  }
  uVar24 = iVar23 + 0x7c;
  uVar5 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar5 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  uVar24 = *(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar24 & 0x3fff));
  uVar5 = Ram00d706;
  uVar9 = Ram00d706;
  if (uVar24 != uVar9 && uVar5 <= uVar24) {
    uVar18 = Ram00d66c;
    uVar17 = Ram00d66e;
    uVar24 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar24 = 3;
    }
    Ram00d690 = (int)(CONCAT22(uVar17,uVar18) /
                     (long)(ulong)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)));
    iVar22 = Ram00f652;
    uVar24 = iVar22 + 0x42;
    uVar2 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar24 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
    uVar2 = Ram00d63e;
    uVar5 = Ram00d63e;
    if (uVar24 == uVar5 || uVar24 < uVar2) {
      bVar19 = UNK_00d688;
      iVar23 = (uint)bVar19 * 2;
      uVar24 = iVar22 + iVar23 + 0x26;
      uVar2 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar22 = Ram00f652;
      uVar5 = iVar22 + iVar23 + 0x24;
      uVar9 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar9 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      bVar19 = UNK_00d689;
      iVar22 = Ram00f652;
      uVar4 = iVar22 + 0x3e + (uint)bVar19;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar19 = UNK_00d689;
      iVar22 = Ram00f652;
      uVar8 = iVar22 + 0x3d + (uint)bVar19;
      uVar3 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar3 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar21 = egs52_vector_length_estimate
                         (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) -
                          *(int *)((uint3)uVar9 << 0xe | (uint3)(uVar5 & 0x3fff)),
                          (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) -
                          (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar8 & 0x3fff)));
      iVar22 = Ram00f652;
      uVar24 = iVar22 + 0xab;
      uVar2 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar10 = Ram00d690;
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
        iVar10 = Ram00d694;
        if (iVar10 == 0) {
          uVar24 = iVar22 + 0x25;
          uVar2 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar19 = UNK_00d688;
          if (bVar19 <= *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff))) goto LAB_0dc6da;
        }
        bVar19 = UNK_00d688;
        iVar22 = Ram00f652;
        uVar24 = iVar22 + 0x3e;
        uVar2 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar20 = UNK_00d649;
        if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar20) {
          bVar20 = UNK_00d689;
          iVar22 = (uint)bVar19 * 4;
          iVar10 = Ram00f6fe;
          uVar2 = iVar10 + (uint)bVar20 + iVar22;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xfa) {
            iVar10 = Ram00f652;
            uVar24 = iVar10 + 0x32;
            uVar2 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
            iVar15 = Ram00d65e;
            iVar16 = Ram00d65e;
            if (iVar10 != iVar16 && iVar15 <= iVar10) {
              bVar20 = egs52_compute_from_near_d688_0da518(3,uVar21,iVar23);
              bVar19 = UNK_00d689;
              iVar10 = Ram00f6fe;
              uVar2 = iVar10 + (uint)bVar19 + iVar22;
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + (uint)bVar20 <
                  0xfa) {
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                     *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + bVar20;
              }
              else {
                bVar19 = UNK_00d689;
                iVar10 = Ram00f6fe;
                uVar2 = iVar10 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfa;
              }
            }
          }
          bVar19 = UNK_00d689;
          iVar10 = Ram00f6fe;
          uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xfa) {
            iVar10 = Ram00f652;
            uVar24 = iVar10 + 0x26;
            uVar2 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            iVar10 = Ram00d65e;
            if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
              bVar20 = egs52_compute_from_near_d688_0da518(4,uVar21,iVar23);
              bVar19 = UNK_00d689;
              iVar10 = Ram00f6fe;
              uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + (uint)bVar20 <
                  0xfa) {
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                     *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + bVar20;
              }
              else {
                bVar19 = UNK_00d689;
                uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfa;
              }
            }
          }
        }
        bVar19 = UNK_00d688;
        iVar22 = Ram00f652;
        uVar2 = iVar22 + 0x41;
        uVar24 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar24 = 3;
        }
        bVar20 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
        bVar7 = UNK_00d649;
        bVar12 = UNK_00d649;
        if (bVar20 != bVar12 && bVar7 <= bVar20) {
          bVar20 = UNK_00d689;
          iVar22 = (uint)bVar19 * 4;
          iVar10 = Ram00f6fe;
          uVar2 = iVar10 + -1 + (uint)bVar20 + iVar22;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xfa) {
            iVar10 = Ram00f652;
            uVar24 = iVar10 + 0x32;
            uVar2 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
            iVar15 = Ram00d65e;
            iVar16 = Ram00d65e;
            if (iVar10 != iVar16 && iVar15 <= iVar10) {
              bVar20 = egs52_compute_from_near_d688_0da518(1,uVar21,iVar23);
              bVar19 = UNK_00d689;
              iVar10 = Ram00f6fe;
              uVar2 = iVar10 + -1 + (uint)bVar19 + iVar22;
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + (uint)bVar20 <
                  0xfa) {
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                     *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + bVar20;
              }
              else {
                bVar19 = UNK_00d689;
                uVar2 = iVar10 + -1 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfa;
              }
            }
          }
          bVar19 = UNK_00d689;
          iVar10 = Ram00f6fe;
          uVar2 = iVar10 + 3 + (uint)bVar19 + iVar22;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) < 0xfa) {
            iVar10 = Ram00f652;
            uVar24 = iVar10 + 0x26;
            uVar2 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            iVar10 = Ram00d65e;
            if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
              bVar20 = egs52_compute_from_near_d688_0da518(2,uVar21,iVar23);
              bVar19 = UNK_00d689;
              iVar23 = Ram00f6fe;
              uVar2 = iVar23 + 3 + (uint)bVar19 + iVar22;
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + (uint)bVar20 <
                  0xfa) {
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar5 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar5 = 3;
                }
                *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                     *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) + bVar20;
              }
              else {
                bVar19 = UNK_00d689;
                uVar2 = iVar23 + 3 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfa;
              }
            }
          }
        }
        cVar14 = UNK_00d688;
        for (bVar19 = cVar14 - 1; bVar19 < 6; bVar19 = bVar19 + 1) {
          cVar14 = UNK_00d689;
          for (bVar20 = cVar14 - 1; bVar20 < 3; bVar20 = bVar20 + 1) {
            iVar22 = (uint)bVar20 + (uint)bVar19 * 4;
            iVar23 = Ram00f6fe;
            uVar2 = iVar23 + 4 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            iVar23 = Ram00f6fe;
            uVar5 = iVar23 + 8 + iVar22;
            uVar24 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar9 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar9 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar9 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar9 = 3;
              }
              *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar5 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            }
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            iVar23 = Ram00f6fe;
            uVar9 = iVar23 + 5 + iVar22;
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            }
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
            iVar23 = Ram00f6fe;
            uVar2 = iVar23 + 9 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
            }
            uVar24 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar9 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar9 = 3;
              }
              *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            }
          }
        }
      }
      else {
LAB_0dc6da:
        bVar19 = UNK_00d688;
        iVar22 = Ram00f652;
        uVar24 = iVar22 + 0xaa;
        uVar2 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar10 = (int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
        iVar15 = Ram00d690;
        iVar16 = Ram00d690;
        if (iVar10 != iVar16 && iVar15 <= iVar10) {
          uVar24 = iVar22 + 0x3e;
          uVar2 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar20 = UNK_00d649;
          if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar20) {
            bVar20 = UNK_00d689;
            iVar22 = (uint)bVar19 * 4;
            iVar10 = Ram00f6fe;
            uVar2 = iVar10 + (uint)bVar20 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
              iVar10 = Ram00f652;
              uVar24 = iVar10 + 0x32;
              uVar2 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
              iVar15 = Ram00d65e;
              iVar16 = Ram00d65e;
              if (iVar10 != iVar16 && iVar15 <= iVar10) {
                bVar20 = egs52_compute_from_near_d688_0da518(3,uVar21,iVar23);
                bVar19 = UNK_00d689;
                iVar10 = Ram00f6fe;
                uVar2 = iVar10 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff))) {
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar5 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar5 = 3;
                  }
                  *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) - bVar20;
                }
                else {
                  bVar19 = UNK_00d689;
                  iVar10 = Ram00f6fe;
                  uVar2 = iVar10 + (uint)bVar19 + iVar22;
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
                }
              }
            }
            bVar19 = UNK_00d689;
            iVar10 = Ram00f6fe;
            uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
              iVar10 = Ram00f652;
              uVar24 = iVar10 + 0x26;
              uVar2 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              iVar10 = Ram00d65e;
              if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                bVar20 = egs52_compute_from_near_d688_0da518(4,uVar21,iVar23);
                bVar19 = UNK_00d689;
                iVar10 = Ram00f6fe;
                uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff))) {
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar5 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar5 = 3;
                  }
                  *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) - bVar20;
                }
                else {
                  bVar19 = UNK_00d689;
                  uVar2 = iVar10 + 4 + (uint)bVar19 + iVar22;
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
                }
              }
            }
          }
        }
        bVar19 = UNK_00d688;
        iVar22 = Ram00f652;
        uVar24 = iVar22 + 0xaa;
        uVar2 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar10 = (int)*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
        iVar15 = Ram00d690;
        iVar16 = Ram00d690;
        if (iVar10 != iVar16 && iVar15 <= iVar10) {
          uVar2 = iVar22 + 0x41;
          uVar24 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          bVar20 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
          bVar7 = UNK_00d649;
          bVar12 = UNK_00d649;
          if (bVar20 != bVar12 && bVar7 <= bVar20) {
            bVar20 = UNK_00d689;
            iVar22 = (uint)bVar19 * 4;
            iVar10 = Ram00f6fe;
            uVar2 = iVar10 + -1 + (uint)bVar20 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
              iVar10 = Ram00f652;
              uVar24 = iVar10 + 0x32;
              uVar2 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff));
              iVar15 = Ram00d65e;
              iVar16 = Ram00d65e;
              if (iVar10 != iVar16 && iVar15 <= iVar10) {
                bVar20 = egs52_compute_from_near_d688_0da518(1,uVar21,iVar23);
                bVar19 = UNK_00d689;
                iVar10 = Ram00f6fe;
                uVar2 = iVar10 + -1 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff))) {
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar5 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar5 = 3;
                  }
                  *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) - bVar20;
                }
                else {
                  bVar19 = UNK_00d689;
                  uVar2 = iVar10 + -1 + (uint)bVar19 + iVar22;
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
                }
              }
            }
            bVar19 = UNK_00d689;
            iVar10 = Ram00f6fe;
            uVar2 = iVar10 + 3 + (uint)bVar19 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
              iVar10 = Ram00f652;
              uVar24 = iVar10 + 0x26;
              uVar2 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar2 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              iVar10 = Ram00d65e;
              if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                bVar20 = egs52_compute_from_near_d688_0da518(2,uVar21,iVar23);
                bVar19 = UNK_00d689;
                iVar23 = Ram00f6fe;
                uVar2 = iVar23 + 3 + (uint)bVar19 + iVar22;
                uVar24 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff))) {
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar5 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar5 = 3;
                  }
                  *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) - bVar20;
                }
                else {
                  bVar19 = UNK_00d689;
                  uVar2 = iVar23 + 3 + (uint)bVar19 + iVar22;
                  uVar24 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
                }
              }
            }
          }
        }
        for (bVar19 = UNK_00d688; bVar19 != 0; bVar19 = bVar19 - 1) {
          for (bVar20 = UNK_00d689; bVar20 != 0; bVar20 = bVar20 - 1) {
            iVar22 = (uint)bVar20 + (uint)bVar19 * 4;
            iVar23 = Ram00f6fe;
            uVar2 = iVar23 + 3 + iVar22;
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            iVar23 = Ram00f6fe;
            uVar5 = iVar23 + 4 + iVar22;
            uVar24 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar9 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar9 = 3;
              }
              *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            }
            iVar23 = Ram00f6fe;
            uVar9 = iVar23 + iVar22;
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            bVar7 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
            uVar24 = 0x24;
            if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            pbVar6 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            if (bVar7 != *pbVar6 && *pbVar6 <= bVar7) {
              uVar24 = 0x24;
              if ((((uVar5 & 0xc000) != 0) && (uVar24 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar1 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar5 & 0x3fff));
            }
            uVar24 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            iVar23 = Ram00f6fe;
            uVar1 = iVar23 + -1 + iVar22;
            uVar5 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff)) <
                *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff))) {
              uVar24 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar24 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar5 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar5 = 3;
              }
              *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar2 & 0x3fff));
            }
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff)) <
                *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
              uVar24 = 0x24;
              if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              uVar2 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                   *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
            }
          }
        }
      }
      uVar17 = Ram00d65e;
      uVar13 = UNK_00d649;
      iVar22 = egs52_update_near_d688_0da630(uVar17,uVar13);
      uVar24 = iVar22 * 0xc;
      Ram00d6b6 = uVar24;
      uVar2 = Ram00d6b4;
      lVar11 = CONCAT22(-(uint)(uVar24 < uVar2),uVar24 - uVar2) * 10;
      uVar24 = (uint)lVar11;
      uVar2 = Ram00d670;
      Ram00d670 = uVar2 - uVar24;
      iVar22 = Ram00d672;
      Ram00d672 = (iVar22 - (int)((ulong)lVar11 >> 0x10)) - (uint)(uVar2 < uVar24);
    }
  }
  Ram00d680 = 0;
  Ram00d66c = 0;
  Ram00d66e = 0;
LAB_0dcc80:
  uVar13 = UNK_00d649;
  iVar23 = egs52_update_near_d688_0da630(0,uVar13);
  iVar22 = Ram00d68e;
  Ram00d660 = iVar23 * 0xc + iVar22 * 3;
  return;
}


