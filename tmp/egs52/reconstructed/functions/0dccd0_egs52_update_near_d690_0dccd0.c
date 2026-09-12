/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dccd0; FLS offset 0x05ccd0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Removing unreachable block (ram,0x0dd64e) */
/* WARNING: Removing unreachable block (ram,0x0dd652) */
/* WARNING: Removing unreachable block (ram,0x0dd63c) */
/* WARNING: Removing unreachable block (ram,0x0dd638) */
/* WARNING: Removing unreachable block (ram,0x0dd634) */
/* WARNING: Removing unreachable block (ram,0x0dd62c) */
/* WARNING: Removing unreachable block (ram,0x0dd602) */
/* WARNING: Removing unreachable block (ram,0x0dd5f6) */
/* WARNING: Removing unreachable block (ram,0x0dd5e6) */
/* WARNING: Removing unreachable block (ram,0x0dd5d8) */
/* WARNING: Removing unreachable block (ram,0x0dd5dc) */
/* WARNING: Removing unreachable block (ram,0x0dd5c8) */
/* WARNING: Removing unreachable block (ram,0x0dd26a) */
/* WARNING: Removing unreachable block (ram,0x0dd266) */
/* WARNING: Removing unreachable block (ram,0x0dd262) */
/* WARNING: Removing unreachable block (ram,0x0dd25e) */
/* WARNING: Removing unreachable block (ram,0x0dd25a) */
/* WARNING: Removing unreachable block (ram,0x0dd248) */
/* WARNING: Removing unreachable block (ram,0x0dd240) */
/* WARNING: Removing unreachable block (ram,0x0dd230) */
/* WARNING: Removing unreachable block (ram,0x0dd22c) */
/* WARNING: Removing unreachable block (ram,0x0dd026) */
/* WARNING: Removing unreachable block (ram,0x0dd02c) */
/* WARNING: Removing unreachable block (ram,0x0dd012) */
/* WARNING: Removing unreachable block (ram,0x0dd030) */
/* WARNING: Removing unreachable block (ram,0x0dd016) */
/* WARNING: Removing unreachable block (ram,0x0dd006) */
/* WARNING: Removing unreachable block (ram,0x0dd022) */
/* WARNING: Removing unreachable block (ram,0x0dd002) */
/* WARNING: Removing unreachable block (ram,0x0dcfe2) */
/* WARNING: Removing unreachable block (ram,0x0dcfda) */
/* WARNING: Removing unreachable block (ram,0x0dcfc4) */
/* WARNING: Removing unreachable block (ram,0x0dcfd6) */
/* WARNING: Removing unreachable block (ram,0x0dcfb6) */
/* WARNING: Removing unreachable block (ram,0x0dcfaa) */
/* WARNING: Removing unreachable block (ram,0x0dcf9a) */
/* WARNING: Removing unreachable block (ram,0x0dcf96) */
/* WARNING: Removing unreachable block (ram,0x0dcf92) */
/* WARNING: Removing unreachable block (ram,0x0dcf86) */
/* WARNING: Removing unreachable block (ram,0x0dcf80) */
/* WARNING: Removing unreachable block (ram,0x0dcf6a) */
/* WARNING: Removing unreachable block (ram,0x0dcf7c) */
/* WARNING: Removing unreachable block (ram,0x0dcf5c) */
/* WARNING: Removing unreachable block (ram,0x0dcf50) */
/* WARNING: Removing unreachable block (ram,0x0dcf40) */
/* WARNING: Removing unreachable block (ram,0x0dcf3c) */
/* WARNING: Removing unreachable block (ram,0x0dcf38) */
/* WARNING: Removing unreachable block (ram,0x0dcf2c) */
/* WARNING: Removing unreachable block (ram,0x0dcf22) */
/* WARNING: Removing unreachable block (ram,0x0dcf1a) */
/* WARNING: Removing unreachable block (ram,0x0dcf18) */
/* WARNING: Removing unreachable block (ram,0x0dcf0a) */
/* WARNING: Removing unreachable block (ram,0x0dcf06) */
/* WARNING: Removing unreachable block (ram,0x0dcef0) */
/* WARNING: Removing unreachable block (ram,0x0dcf02) */
/* WARNING: Removing unreachable block (ram,0x0dcee2) */
/* WARNING: Removing unreachable block (ram,0x0dced6) */
/* WARNING: Removing unreachable block (ram,0x0dcec6) */
/* WARNING: Removing unreachable block (ram,0x0dcec2) */
/* WARNING: Removing unreachable block (ram,0x0dcebe) */
/* WARNING: Removing unreachable block (ram,0x0dceb2) */
/* WARNING: Removing unreachable block (ram,0x0dceac) */
/* WARNING: Removing unreachable block (ram,0x0dce96) */
/* WARNING: Removing unreachable block (ram,0x0dcea8) */
/* WARNING: Removing unreachable block (ram,0x0dce88) */
/* WARNING: Removing unreachable block (ram,0x0dce7c) */
/* WARNING: Removing unreachable block (ram,0x0dce6c) */
/* WARNING: Removing unreachable block (ram,0x0dce68) */
/* WARNING: Removing unreachable block (ram,0x0dce64) */
/* WARNING: Removing unreachable block (ram,0x0dce58) */
/* WARNING: Removing unreachable block (ram,0x0dce4e) */
/* WARNING: Removing unreachable block (ram,0x0dce42) */
/* WARNING: Removing unreachable block (ram,0x0dce3e) */
/* WARNING: Removing unreachable block (ram,0x0dd1f4) */
/* WARNING: Removing unreachable block (ram,0x0dd210) */
/* WARNING: Removing unreachable block (ram,0x0dd21e) */
/* WARNING: Removing unreachable block (ram,0x0dd204) */
/* WARNING: Removing unreachable block (ram,0x0dd1f0) */
/* WARNING: Removing unreachable block (ram,0x0dd216) */
/* WARNING: Removing unreachable block (ram,0x0dd206) */
/* WARNING: Removing unreachable block (ram,0x0dd200) */
/* WARNING: Removing unreachable block (ram,0x0dd1e6) */
/* WARNING: Removing unreachable block (ram,0x0dd1d0) */
/* WARNING: Removing unreachable block (ram,0x0dd1ca) */
/* WARNING: Removing unreachable block (ram,0x0dd1ba) */
/* WARNING: Removing unreachable block (ram,0x0dd1b6) */
/* WARNING: Removing unreachable block (ram,0x0dd1c6) */
/* WARNING: Removing unreachable block (ram,0x0dd1c0) */
/* WARNING: Removing unreachable block (ram,0x0dd1b0) */
/* WARNING: Removing unreachable block (ram,0x0dd1a4) */
/* WARNING: Removing unreachable block (ram,0x0dd194) */
/* WARNING: Removing unreachable block (ram,0x0dd190) */
/* WARNING: Removing unreachable block (ram,0x0dd18c) */
/* WARNING: Removing unreachable block (ram,0x0dd184) */
/* WARNING: Removing unreachable block (ram,0x0dd17e) */
/* WARNING: Removing unreachable block (ram,0x0dd16e) */
/* WARNING: Removing unreachable block (ram,0x0dd16a) */
/* WARNING: Removing unreachable block (ram,0x0dd17a) */
/* WARNING: Removing unreachable block (ram,0x0dd174) */
/* WARNING: Removing unreachable block (ram,0x0dd164) */
/* WARNING: Removing unreachable block (ram,0x0dd158) */
/* WARNING: Removing unreachable block (ram,0x0dd148) */
/* WARNING: Removing unreachable block (ram,0x0dd144) */
/* WARNING: Removing unreachable block (ram,0x0dd140) */
/* WARNING: Removing unreachable block (ram,0x0dd138) */
/* WARNING: Removing unreachable block (ram,0x0dd12e) */
/* WARNING: Removing unreachable block (ram,0x0dd126) */
/* WARNING: Removing unreachable block (ram,0x0dd124) */
/* WARNING: Removing unreachable block (ram,0x0dd112) */
/* WARNING: Removing unreachable block (ram,0x0dd10c) */
/* WARNING: Removing unreachable block (ram,0x0dd108) */
/* WARNING: Removing unreachable block (ram,0x0dd104) */
/* WARNING: Removing unreachable block (ram,0x0dd0f4) */
/* WARNING: Removing unreachable block (ram,0x0dd0f0) */
/* WARNING: Removing unreachable block (ram,0x0dd100) */
/* WARNING: Removing unreachable block (ram,0x0dd0fa) */
/* WARNING: Removing unreachable block (ram,0x0dd0ea) */
/* WARNING: Removing unreachable block (ram,0x0dd0de) */
/* WARNING: Removing unreachable block (ram,0x0dd0ce) */
/* WARNING: Removing unreachable block (ram,0x0dd0ca) */
/* WARNING: Removing unreachable block (ram,0x0dd0c6) */
/* WARNING: Removing unreachable block (ram,0x0dd0be) */
/* WARNING: Removing unreachable block (ram,0x0dd0b8) */
/* WARNING: Removing unreachable block (ram,0x0dd0a8) */
/* WARNING: Removing unreachable block (ram,0x0dd0a4) */
/* WARNING: Removing unreachable block (ram,0x0dd0b4) */
/* WARNING: Removing unreachable block (ram,0x0dd0ae) */
/* WARNING: Removing unreachable block (ram,0x0dd09e) */
/* WARNING: Removing unreachable block (ram,0x0dd092) */
/* WARNING: Removing unreachable block (ram,0x0dd082) */
/* WARNING: Removing unreachable block (ram,0x0dd07e) */
/* WARNING: Removing unreachable block (ram,0x0dd07a) */
/* WARNING: Removing unreachable block (ram,0x0dd072) */
/* WARNING: Removing unreachable block (ram,0x0dd068) */
/* WARNING: Removing unreachable block (ram,0x0dd060) */
/* WARNING: Removing unreachable block (ram,0x0dd05c) */
/* WARNING: Removing unreachable block (ram,0x0dd054) */
/* WARNING: Removing unreachable block (ram,0x0dd04e) */
/* WARNING: Removing unreachable block (ram,0x0dd04a) */
/* WARNING: Removing unreachable block (ram,0x0dce36) */
/* WARNING: Removing unreachable block (ram,0x0dce30) */
/* WARNING: Removing unreachable block (ram,0x0dce2c) */
/* WARNING: Removing unreachable block (ram,0x0dce20) */
/* WARNING: Removing unreachable block (ram,0x0dce16) */
/* WARNING: Removing unreachable block (ram,0x0dce12) */
/* WARNING: Removing unreachable block (ram,0x0dce0e) */
/* WARNING: Removing unreachable block (ram,0x0dce04) */
/* WARNING: Removing unreachable block (ram,0x0dce00) */
/* WARNING: Removing unreachable block (ram,0x0dcdfa) */
/* WARNING: Removing unreachable block (ram,0x0dcdf4) */
/* WARNING: Removing unreachable block (ram,0x0dcdf0) */
/* WARNING: Removing unreachable block (ram,0x0dcde4) */
/* WARNING: Removing unreachable block (ram,0x0dcddc) */
/* WARNING: Removing unreachable block (ram,0x0dcdd8) */
/* WARNING: Removing unreachable block (ram,0x0dcdd4) */
/* WARNING: Removing unreachable block (ram,0x0dcdd0) */
/* WARNING: Removing unreachable block (ram,0x0dcdc4) */
/* WARNING: Removing unreachable block (ram,0x0dcdc0) */
/* WARNING: Removing unreachable block (ram,0x0dcdbc) */
/* WARNING: Removing unreachable block (ram,0x0dcdb0) */
/* WARNING: Removing unreachable block (ram,0x0dd310) */
/* WARNING: Removing unreachable block (ram,0x0dd308) */
/* WARNING: Removing unreachable block (ram,0x0dd300) */
/* WARNING: Removing unreachable block (ram,0x0dd2fc) */
/* WARNING: Removing unreachable block (ram,0x0dd2f8) */
/* WARNING: Removing unreachable block (ram,0x0dd2f4) */
/* WARNING: Removing unreachable block (ram,0x0dd2ec) */
/* WARNING: Removing unreachable block (ram,0x0dd2e8) */
/* WARNING: Removing unreachable block (ram,0x0dd2e0) */
/* WARNING: Removing unreachable block (ram,0x0dd2c0) */
/* WARNING: Removing unreachable block (ram,0x0dd2bc) */
/* WARNING: Removing unreachable block (ram,0x0dd2b8) */
/* WARNING: Removing unreachable block (ram,0x0dd2b4) */
/* WARNING: Removing unreachable block (ram,0x0dd2d8) */
/* WARNING: Removing unreachable block (ram,0x0dd2d4) */
/* WARNING: Removing unreachable block (ram,0x0dd2a2) */
/* WARNING: Removing unreachable block (ram,0x0dd290) */
/* WARNING: Removing unreachable block (ram,0x0dd28c) */
/* WARNING: Removing unreachable block (ram,0x0dd288) */
/* WARNING: Removing unreachable block (ram,0x0dd284) */
/* WARNING: Removing unreachable block (ram,0x0dd278) */
/* WARNING: Removing unreachable block (ram,0x0dcda4) */
/* WARNING: Removing unreachable block (ram,0x0dd3f2) */
/* WARNING: Removing unreachable block (ram,0x0dd3ee) */
/* WARNING: Removing unreachable block (ram,0x0dd3ea) */
/* WARNING: Removing unreachable block (ram,0x0dd3e6) */
/* WARNING: Removing unreachable block (ram,0x0dd3e0) */
/* WARNING: Removing unreachable block (ram,0x0dd3dc) */
/* WARNING: Removing unreachable block (ram,0x0dd3d8) */
/* WARNING: Removing unreachable block (ram,0x0dd3d2) */
/* WARNING: Removing unreachable block (ram,0x0dd3d0) */
/* WARNING: Removing unreachable block (ram,0x0dd3cc) */
/* WARNING: Removing unreachable block (ram,0x0dd3c8) */
/* WARNING: Removing unreachable block (ram,0x0dd3c2) */
/* WARNING: Removing unreachable block (ram,0x0dd3be) */
/* WARNING: Removing unreachable block (ram,0x0dd3ba) */
/* WARNING: Removing unreachable block (ram,0x0dd3b4) */
/* WARNING: Removing unreachable block (ram,0x0dd3b2) */
/* WARNING: Removing unreachable block (ram,0x0dd3a8) */
/* WARNING: Removing unreachable block (ram,0x0dd3a6) */
/* WARNING: Removing unreachable block (ram,0x0dd39e) */
/* WARNING: Removing unreachable block (ram,0x0dd39a) */
/* WARNING: Removing unreachable block (ram,0x0dd38e) */
/* WARNING: Removing unreachable block (ram,0x0dd38a) */
/* WARNING: Removing unreachable block (ram,0x0dd386) */
/* WARNING: Removing unreachable block (ram,0x0dd41e) */
/* WARNING: Removing unreachable block (ram,0x0dd41a) */
/* WARNING: Removing unreachable block (ram,0x0dd416) */
/* WARNING: Removing unreachable block (ram,0x0dd40e) */
/* WARNING: Removing unreachable block (ram,0x0dd436) */
/* WARNING: Removing unreachable block (ram,0x0dd432) */
/* WARNING: Removing unreachable block (ram,0x0dd42e) */
/* WARNING: Removing unreachable block (ram,0x0dd426) */
/* WARNING: Removing unreachable block (ram,0x0dd406) */
/* WARNING: Removing unreachable block (ram,0x0dd402) */
/* WARNING: Removing unreachable block (ram,0x0dd3fa) */
/* WARNING: Removing unreachable block (ram,0x0dd380) */
/* WARNING: Removing unreachable block (ram,0x0dd37c) */
/* WARNING: Removing unreachable block (ram,0x0dd446) */
/* WARNING: Removing unreachable block (ram,0x0dd442) */
/* WARNING: Removing unreachable block (ram,0x0dd43e) */
/* WARNING: Removing unreachable block (ram,0x0dd36e) */
/* WARNING: Removing unreachable block (ram,0x0dd36a) */
/* WARNING: Removing unreachable block (ram,0x0dd35e) */
/* WARNING: Removing unreachable block (ram,0x0dd35a) */
/* WARNING: Removing unreachable block (ram,0x0dd34e) */
/* WARNING: Removing unreachable block (ram,0x0dd34a) */
/* WARNING: Removing unreachable block (ram,0x0dd33e) */
/* WARNING: Removing unreachable block (ram,0x0dd346) */
/* WARNING: Removing unreachable block (ram,0x0dd336) */
/* WARNING: Removing unreachable block (ram,0x0dd32e) */
/* WARNING: Removing unreachable block (ram,0x0dd328) */
/* WARNING: Removing unreachable block (ram,0x0dd320) */
/* WARNING: Removing unreachable block (ram,0x0dd31c) */
/* WARNING: Removing unreachable block (ram,0x0dcd94) */
/* WARNING: Removing unreachable block (ram,0x0dcd88) */
/* WARNING: Removing unreachable block (ram,0x0dcd7c) */
/* WARNING: Removing unreachable block (ram,0x0dcd78) */
/* WARNING: Removing unreachable block (ram,0x0dcd64) */
/* WARNING: Removing unreachable block (ram,0x0dd556) */
/* WARNING: Removing unreachable block (ram,0x0dd552) */
/* WARNING: Removing unreachable block (ram,0x0dd54e) */
/* WARNING: Removing unreachable block (ram,0x0dd542) */
/* WARNING: Removing unreachable block (ram,0x0dd546) */
/* WARNING: Removing unreachable block (ram,0x0dd536) */
/* WARNING: Removing unreachable block (ram,0x0dd528) */
/* WARNING: Removing unreachable block (ram,0x0dd51e) */
/* WARNING: Removing unreachable block (ram,0x0dd524) */
/* WARNING: Removing unreachable block (ram,0x0dd516) */
/* WARNING: Removing unreachable block (ram,0x0dd506) */
/* WARNING: Removing unreachable block (ram,0x0dd504) */
/* WARNING: Removing unreachable block (ram,0x0dd500) */
/* WARNING: Removing unreachable block (ram,0x0dd4fa) */
/* WARNING: Removing unreachable block (ram,0x0dd4f8) */
/* WARNING: Removing unreachable block (ram,0x0dd4ea) */
/* WARNING: Removing unreachable block (ram,0x0dd4e4) */
/* WARNING: Removing unreachable block (ram,0x0dd4da) */
/* WARNING: Removing unreachable block (ram,0x0dd4d8) */
/* WARNING: Removing unreachable block (ram,0x0dd4d4) */
/* WARNING: Removing unreachable block (ram,0x0dd4ce) */
/* WARNING: Removing unreachable block (ram,0x0dd4ca) */
/* WARNING: Removing unreachable block (ram,0x0dd4c6) */
/* WARNING: Removing unreachable block (ram,0x0dd4c0) */
/* WARNING: Removing unreachable block (ram,0x0dd4b6) */
/* WARNING: Removing unreachable block (ram,0x0dd4ae) */
/* WARNING: Removing unreachable block (ram,0x0dd4aa) */
/* WARNING: Removing unreachable block (ram,0x0dd496) */
/* WARNING: Removing unreachable block (ram,0x0dd492) */
/* WARNING: Removing unreachable block (ram,0x0dd48e) */
/* WARNING: Removing unreachable block (ram,0x0dd4a6) */
/* WARNING: Removing unreachable block (ram,0x0dd4a0) */
/* WARNING: Removing unreachable block (ram,0x0dd49c) */
/* WARNING: Removing unreachable block (ram,0x0dd486) */
/* WARNING: Removing unreachable block (ram,0x0dd47e) */
/* WARNING: Removing unreachable block (ram,0x0dd47a) */
/* WARNING: Removing unreachable block (ram,0x0dd476) */
/* WARNING: Removing unreachable block (ram,0x0dd46a) */
/* WARNING: Removing unreachable block (ram,0x0dd466) */
/* WARNING: Removing unreachable block (ram,0x0dd462) */
/* WARNING: Removing unreachable block (ram,0x0dd5ba) */
/* WARNING: Removing unreachable block (ram,0x0dd5b6) */
/* WARNING: Removing unreachable block (ram,0x0dd5b2) */
/* WARNING: Removing unreachable block (ram,0x0dd5ac) */
/* WARNING: Removing unreachable block (ram,0x0dd5a8) */
/* WARNING: Removing unreachable block (ram,0x0dd598) */
/* WARNING: Removing unreachable block (ram,0x0dd5a0) */
/* WARNING: Removing unreachable block (ram,0x0dd590) */
/* WARNING: Removing unreachable block (ram,0x0dd57c) */
/* WARNING: Removing unreachable block (ram,0x0dd584) */
/* WARNING: Removing unreachable block (ram,0x0dd574) */
/* WARNING: Removing unreachable block (ram,0x0dd570) */
/* WARNING: Removing unreachable block (ram,0x0dd56a) */
/* WARNING: Removing unreachable block (ram,0x0dd562) */
/* WARNING: Removing unreachable block (ram,0x0dd55c) */
/* WARNING: Removing unreachable block (ram,0x0dd45a) */
/* WARNING: Removing unreachable block (ram,0x0dd456) */
/* WARNING: Removing unreachable block (ram,0x0dcd58) */
/* WARNING: Removing unreachable block (ram,0x0dd628) */
/* WARNING: Removing unreachable block (ram,0x0dd624) */
/* WARNING: Removing unreachable block (ram,0x0dd61c) */
/* WARNING: Removing unreachable block (ram,0x0dd618) */
/* WARNING: Removing unreachable block (ram,0x0dd614) */
/* WARNING: Removing unreachable block (ram,0x0dd610) */
/* WARNING: Removing unreachable block (ram,0x0dd60c) */
/* WARNING: Removing unreachable block (ram,0x0dcd4c) */
/* WARNING: Removing unreachable block (ram,0x0dcd44) */
/* WARNING: Removing unreachable block (ram,0x0dcd40) */
/* WARNING: Removing unreachable block (ram,0x0dcd36) */
/* WARNING: Removing unreachable block (ram,0x0dcd2c) */
/* WARNING: Removing unreachable block (ram,0x0dcd24) */
/* WARNING: Removing unreachable block (ram,0x0dcd20) */
/* WARNING: Removing unreachable block (ram,0x0dcd16) */
/* WARNING: Removing unreachable block (ram,0x0dcd12) */
/* WARNING: Removing unreachable block (ram,0x0dcd0e) */
/* WARNING: Removing unreachable block (ram,0x0dccfe) */
/* WARNING: Removing unreachable block (ram,0x0dccf6) */
/* WARNING: Removing unreachable block (ram,0x0dccf2) */
/* WARNING: Removing unreachable block (ram,0x0dccea) */
/* WARNING: Removing unreachable block (ram,0x0dcce4) */
/* WARNING: Removing unreachable block (ram,0x0dcce0) */
/* WARNING: Removing unreachable block (ram,0x0dccda) */
/* WARNING: Removing unreachable block (ram,0x0dcd06) */
/* WARNING: Removing unreachable block (ram,0x0dd608) */
/* WARNING: Removing unreachable block (ram,0x0dcd5c) */
/* WARNING: Removing unreachable block (ram,0x0dd44e) */
/* WARNING: Removing unreachable block (ram,0x0dcd6c) */
/* WARNING: Removing unreachable block (ram,0x0dd318) */
/* WARNING: Removing unreachable block (ram,0x0dcda8) */
/* WARNING: Removing unreachable block (ram,0x0dd272) */
/* WARNING: Removing unreachable block (ram,0x0dd30c) */
/* WARNING: Removing unreachable block (ram,0x0dcdb4) */
/* WARNING: Removing unreachable block (ram,0x0dd046) */
/* WARNING: Removing unreachable block (ram,0x0dce46) */
/* WARNING: Removing unreachable block (ram,0x0dcea2) */
/* WARNING: Removing unreachable block (ram,0x0dce9a) */
/* WARNING: Removing unreachable block (ram,0x0dcefc) */
/* WARNING: Removing unreachable block (ram,0x0dcef4) */
/* WARNING: Removing unreachable block (ram,0x0dcf76) */
/* WARNING: Removing unreachable block (ram,0x0dcf6e) */
/* WARNING: Removing unreachable block (ram,0x0dcfd0) */
/* WARNING: Removing unreachable block (ram,0x0dcfc8) */
/* WARNING: Removing unreachable block (ram,0x0dcff8) */
/* WARNING: Removing unreachable block (ram,0x0dd008) */
/* WARNING: Removing unreachable block (ram,0x0dd018) */
/* WARNING: Removing unreachable block (ram,0x0dd028) */
/* WARNING: Removing unreachable block (ram,0x0dd5ca) */
/* WARNING: Removing unreachable block (ram,0x0dd65a) */
/* WARNING: Removing unreachable block (ram,0x0dd214) */
/* WARNING: Removing unreachable block (ram,0x0dd1fc) */
/* WARNING: Removing unreachable block (ram,0x0dcd74) */
/* WARNING: Removing unreachable block (ram,0x0dd21a) */

void egs52_update_near_d690_0dccd0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  undefined1 uVar12;
  char cVar13;
  byte bVar14;
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
  if (iVar22 == 0) {
    uVar4 = Ram00d706;
    uVar24 = Ram00d660;
    uVar3 = Ram00d660;
    if (uVar4 == uVar3 || uVar4 < uVar24) goto LAB_0dccea;
  }
  else {
LAB_0dccea:
    iVar22 = Ram00d6ec;
    if (iVar22 != 0) goto LAB_0dd62c;
    uVar4 = Ram00d706;
    uVar24 = Ram00d660;
    uVar3 = Ram00d660;
    if (uVar4 != uVar3 && uVar24 <= uVar4) goto LAB_0dd62c;
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
  uVar3 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if (iVar22 < *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff))) {
    uVar24 = iVar23 + 0x9b;
    uVar3 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    bVar19 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
    bVar20 = UNK_00d649;
    bVar6 = UNK_00d649;
    if (((bVar19 != bVar6 && bVar20 <= bVar19) && (cVar13 = UNK_00d704, cVar13 == '\x03')) &&
       (bVar19 = UNK_00d647, 2 < bVar19)) {
      uVar24 = iVar23 + 0x34;
      uVar3 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar24 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
      uVar3 = Ram00d63e;
      uVar4 = Ram00d63e;
      if ((uVar24 != uVar4 && uVar3 <= uVar24) && (cVar13 = UNK_00d650, cVar13 == '\0')) {
        uVar4 = Ram00d706;
        uVar24 = Ram00d660;
        uVar3 = Ram00d660;
        if (uVar4 == uVar3 || uVar4 < uVar24) {
          iVar22 = Ram00f652;
          uVar3 = iVar22 + 0xcc;
          uVar24 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
          uVar4 = Ram00d680;
          uVar9 = Ram00d680;
          if (uVar24 == uVar9 || uVar24 < uVar4) {
            uVar17 = Ram00d66c;
            uVar18 = Ram00d66e;
            uVar24 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            Ram00d690 = (int)(CONCAT22(uVar18,uVar17) /
                             (long)(ulong)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)))
            ;
            uVar17 = Ram00d65e;
            uVar12 = UNK_00d649;
            egs52_update_near_d688_0da630(uVar17,uVar12);
            uVar24 = Ram00fd2a;
            if ((uVar24 & 1) == 0) {
              iVar22 = Ram00f652;
              uVar24 = iVar22 + 0xcb;
              uVar3 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              Ram00d6de = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
            }
            else {
              iVar22 = Ram00f652;
              uVar24 = iVar22 + 0x1a;
              uVar3 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              Ram00d6de = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
            }
            iVar23 = Ram00d6de;
            iVar22 = Ram00d690;
            if (iVar23 < iVar22) {
              bVar19 = UNK_00d689;
              uVar3 = bVar19 + 0xd6c0;
              uVar24 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) != '\0') {
                iVar22 = Ram00f652;
                uVar24 = iVar22 + 0x3e;
                uVar4 = 0x24;
                if ((((uVar24 & 0xc000) != 0) && (uVar4 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                bVar19 = UNK_00d649;
                if (*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar19) {
                  uVar24 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar4 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + -1;
                }
              }
              bVar19 = UNK_00d689;
              uVar3 = bVar19 + 0xd6bf;
              uVar24 = 0x24;
              if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                uVar24 = 3;
              }
              if (*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) != '\0') {
                iVar22 = Ram00f652;
                uVar4 = iVar22 + 0x41;
                uVar24 = 0x24;
                if ((((uVar4 & 0xc000) != 0) && (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                bVar19 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                bVar20 = UNK_00d649;
                bVar6 = UNK_00d649;
                if (bVar19 != bVar6 && bVar20 <= bVar19) {
                  uVar24 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar4 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                       *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + -1;
                }
              }
              iVar22 = Ram00d68e;
              uVar24 = Ram00d660;
              if (iVar22 * 3 + 0xcU < uVar24) {
                iVar22 = Ram00d660;
                Ram00d660 = iVar22 + -0xc;
              }
              else {
                Ram00d660 = iVar22 * 3;
              }
              for (bVar19 = UNK_00d689; bVar19 != 0; bVar19 = bVar19 - 1) {
                uVar3 = bVar19 + 0xd6c0;
                uVar24 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                uVar9 = bVar19 + 0xd6bf;
                uVar4 = 0x24;
                if ((((uVar9 & 0xc000) != 0) && (uVar4 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) <
                    *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar9 & 0x3fff))) {
                  uVar24 = 0x24;
                  if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                     (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                    uVar24 = 3;
                  }
                  uVar4 = 0x24;
                  if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
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
            if ((iVar22 == 0) || (cVar13 = UNK_00d696, cVar13 == '\x02')) {
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
              uVar3 = Ram00d66c;
              Ram00d66c = uVar3 + uVar24;
              iVar22 = Ram00d66e;
              Ram00d66e = iVar22 + ((int)uVar24 >> 0xf) + (uint)CARRY2(uVar3,uVar24);
            }
            else {
              Ram00d680 = 0;
              Ram00d66c = 0;
              Ram00d66e = 0;
            }
          }
        }
        else {
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
          uVar3 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          if (((iVar22 < (int)(uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff))) &&
              (uVar24 = Ram00fd2a, (uVar24 & 1) != 0)) && (iVar22 = Ram00d6e0, 0 < iVar22)) {
            uVar3 = iVar23 + 0x24;
            uVar24 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
            uVar4 = Ram00d680;
            uVar9 = Ram00d680;
            if (uVar24 == uVar9 || uVar24 < uVar4) {
              uVar24 = iVar23 + 0x7c;
              uVar4 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar4 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              uVar24 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar24 & 0x3fff));
              uVar4 = Ram00d706;
              uVar9 = Ram00d706;
              if (uVar24 != uVar9 && uVar4 <= uVar24) {
                uVar17 = Ram00d66c;
                uVar18 = Ram00d66e;
                uVar24 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar24 = 3;
                }
                Ram00d690 = (int)(CONCAT22(uVar18,uVar17) /
                                 (long)(ulong)*(byte *)((uint3)uVar24 << 0xe |
                                                       (uint3)(uVar3 & 0x3fff)));
                iVar22 = Ram00f652;
                uVar24 = iVar22 + 0x42;
                uVar3 = 0x24;
                if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                uVar24 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                uVar3 = Ram00d63e;
                uVar4 = Ram00d63e;
                if (uVar24 == uVar4 || uVar24 < uVar3) {
                  bVar19 = UNK_00d688;
                  iVar23 = (uint)bVar19 * 2;
                  uVar24 = iVar22 + iVar23 + 0x26;
                  uVar3 = 0x24;
                  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                    uVar3 = 3;
                  }
                  iVar22 = Ram00f652;
                  uVar4 = iVar22 + iVar23 + 0x24;
                  uVar9 = 0x24;
                  if ((((uVar4 & 0xc000) != 0) && (uVar9 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                     (uVar9 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                    uVar9 = 3;
                  }
                  bVar19 = UNK_00d689;
                  iVar22 = Ram00f652;
                  uVar7 = iVar22 + 0x3e + (uint)bVar19;
                  uVar1 = 0x24;
                  if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  bVar19 = UNK_00d689;
                  iVar22 = Ram00f652;
                  uVar8 = iVar22 + 0x3d + (uint)bVar19;
                  uVar2 = 0x24;
                  if ((((uVar8 & 0xc000) != 0) && (uVar2 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                     (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                    uVar2 = 3;
                  }
                  uVar21 = egs52_vector_length_estimate
                                     (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) -
                                      *(int *)((uint3)uVar9 << 0xe | (uint3)(uVar4 & 0x3fff)),
                                      (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff))
                                      - (uint)*(byte *)((uint3)uVar2 << 0xe |
                                                       (uint3)(uVar8 & 0x3fff)));
                  iVar22 = Ram00f652;
                  uVar24 = iVar22 + 0xab;
                  uVar3 = 0x24;
                  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                    uVar3 = 3;
                  }
                  iVar10 = Ram00d690;
                  if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                    bVar19 = UNK_00d688;
                    uVar24 = iVar22 + 0x3e;
                    uVar3 = 0x24;
                    if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                       (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                      uVar3 = 3;
                    }
                    bVar20 = UNK_00d649;
                    if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar20) {
                      bVar20 = UNK_00d689;
                      iVar22 = (uint)bVar19 * 4;
                      uVar24 = (uint)bVar20 + iVar22 + 0xd6bc;
                      uVar3 = 0x24;
                      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000))
                         && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                        uVar3 = 3;
                      }
                      if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < 0xfa) {
                        iVar10 = Ram00f652;
                        uVar24 = iVar10 + 0x32;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        iVar10 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                        iVar15 = Ram00d65e;
                        iVar16 = Ram00d65e;
                        if (iVar10 != iVar16 && iVar15 <= iVar10) {
                          bVar20 = egs52_compute_from_near_d688_0da518(3,uVar21,iVar23);
                          bVar19 = UNK_00d689;
                          uVar3 = (uint)bVar19 + iVar22 + 0xd6bc;
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                              (uint)bVar20 < 0xfa) {
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            uVar4 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar4 = 3;
                            }
                            *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + bVar20;
                          }
                          else {
                            bVar19 = UNK_00d689;
                            uVar24 = (uint)bVar19 + iVar22 + 0xd6bc;
                            uVar3 = 0x24;
                            if ((((uVar24 & 0xc000) != 0) &&
                                (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                               (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                              uVar3 = 3;
                            }
                            *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0xfa;
                          }
                        }
                      }
                      bVar19 = UNK_00d689;
                      uVar24 = (uint)bVar19 + iVar22 + 0xd6c0;
                      uVar3 = 0x24;
                      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000))
                         && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                        uVar3 = 3;
                      }
                      if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < 0xfa) {
                        iVar10 = Ram00f652;
                        uVar24 = iVar10 + 0x26;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        iVar10 = Ram00d65e;
                        if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                          bVar20 = egs52_compute_from_near_d688_0da518(4,uVar21,iVar23);
                          bVar19 = UNK_00d689;
                          uVar3 = (uint)bVar19 + iVar22 + 0xd6c0;
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                              (uint)bVar20 < 0xfa) {
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            uVar4 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar4 = 3;
                            }
                            *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + bVar20;
                          }
                          else {
                            bVar19 = UNK_00d689;
                            uVar24 = (uint)bVar19 + iVar22 + 0xd6c0;
                            uVar3 = 0x24;
                            if ((((uVar24 & 0xc000) != 0) &&
                                (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                               (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                              uVar3 = 3;
                            }
                            *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0xfa;
                          }
                        }
                      }
                    }
                    bVar19 = UNK_00d688;
                    iVar22 = Ram00f652;
                    uVar3 = iVar22 + 0x41;
                    uVar24 = 0x24;
                    if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                       (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                      uVar24 = 3;
                    }
                    bVar20 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                    bVar6 = UNK_00d649;
                    bVar14 = UNK_00d649;
                    if (bVar20 != bVar14 && bVar6 <= bVar20) {
                      bVar20 = UNK_00d689;
                      iVar22 = (uint)bVar19 * 4;
                      uVar24 = (uint)bVar20 + iVar22 + 0xd6bb;
                      uVar3 = 0x24;
                      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000))
                         && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                        uVar3 = 3;
                      }
                      if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < 0xfa) {
                        iVar10 = Ram00f652;
                        uVar24 = iVar10 + 0x32;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        iVar10 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                        iVar15 = Ram00d65e;
                        iVar16 = Ram00d65e;
                        if (iVar10 != iVar16 && iVar15 <= iVar10) {
                          bVar20 = egs52_compute_from_near_d688_0da518(1,uVar21,iVar23);
                          bVar19 = UNK_00d689;
                          uVar3 = (uint)bVar19 + iVar22 + 0xd6bb;
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                              (uint)bVar20 < 0xfa) {
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            uVar4 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar4 = 3;
                            }
                            *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + bVar20;
                          }
                          else {
                            bVar19 = UNK_00d689;
                            uVar24 = (uint)bVar19 + iVar22 + 0xd6bb;
                            uVar3 = 0x24;
                            if ((((uVar24 & 0xc000) != 0) &&
                                (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                               (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                              uVar3 = 3;
                            }
                            *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0xfa;
                          }
                        }
                      }
                      bVar19 = UNK_00d689;
                      uVar24 = (uint)bVar19 + iVar22 + 0xd6bf;
                      uVar3 = 0x24;
                      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000))
                         && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                        uVar3 = 3;
                      }
                      if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < 0xfa) {
                        iVar10 = Ram00f652;
                        uVar24 = iVar10 + 0x26;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        iVar10 = Ram00d65e;
                        if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                          bVar20 = egs52_compute_from_near_d688_0da518(2,uVar21,iVar23);
                          bVar19 = UNK_00d689;
                          uVar3 = (uint)bVar19 + iVar22 + 0xd6bf;
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          if ((uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                              (uint)bVar20 < 0xfa) {
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            uVar4 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar4 = 3;
                            }
                            *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                 *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) + bVar20;
                          }
                          else {
                            bVar19 = UNK_00d689;
                            uVar24 = (uint)bVar19 + iVar22 + 0xd6bf;
                            uVar3 = 0x24;
                            if ((((uVar24 & 0xc000) != 0) &&
                                (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                               (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                              uVar3 = 3;
                            }
                            *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0xfa;
                          }
                        }
                      }
                    }
                    cVar13 = UNK_00d688;
                    for (bVar19 = cVar13 - 1; bVar19 < 6; bVar19 = bVar19 + 1) {
                      cVar13 = UNK_00d689;
                      for (bVar20 = cVar13 - 1; bVar20 < 3; bVar20 = bVar20 + 1) {
                        iVar22 = (uint)bVar20 + (uint)bVar19 * 4;
                        uVar3 = iVar22 + 0xd6c0;
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        uVar4 = iVar22 + 0xd6c4;
                        uVar24 = 0x24;
                        if ((((uVar4 & 0xc000) != 0) && (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar9 = 0x24;
                          if ((((uVar4 & 0xc000) != 0) && (uVar9 = 0x21, (uVar4 & 0xc000) != 0x4000)
                              ) && (uVar9 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                            uVar9 = 3;
                          }
                          *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar4 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        }
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        uVar9 = iVar22 + 0xd6c1;
                        uVar24 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar1 = 0x24;
                          if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)
                              ) && (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                            uVar1 = 3;
                          }
                          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        }
                        uVar24 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
                        uVar3 = iVar22 + 0xd6c5;
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar9 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar1 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)
                              ) && (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar1 = 3;
                          }
                          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
                        }
                        uVar24 = 0x24;
                        if ((((uVar4 & 0xc000) != 0) && (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar4 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar9 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)
                              ) && (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar9 = 3;
                          }
                          *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        }
                      }
                    }
                  }
                  else {
                    bVar19 = UNK_00d688;
                    iVar22 = Ram00f652;
                    uVar24 = iVar22 + 0xaa;
                    uVar3 = 0x24;
                    if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                       (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                      uVar3 = 3;
                    }
                    iVar10 = (int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                    iVar15 = Ram00d690;
                    iVar16 = Ram00d690;
                    if (iVar10 != iVar16 && iVar15 <= iVar10) {
                      uVar24 = iVar22 + 0x3e;
                      uVar3 = 0x24;
                      if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000))
                         && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                        uVar3 = 3;
                      }
                      bVar20 = UNK_00d649;
                      if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar20) {
                        bVar20 = UNK_00d689;
                        iVar22 = (uint)bVar19 * 4;
                        uVar24 = (uint)bVar20 + iVar22 + 0xd6bc;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) != '\0') {
                          iVar10 = Ram00f652;
                          uVar24 = iVar10 + 0x32;
                          uVar3 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          iVar10 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                          iVar15 = Ram00d65e;
                          iVar16 = Ram00d65e;
                          if (iVar10 != iVar16 && iVar15 <= iVar10) {
                            bVar20 = egs52_compute_from_near_d688_0da518(3,uVar21,iVar23);
                            bVar19 = UNK_00d689;
                            uVar3 = (uint)bVar19 + iVar22 + 0xd6bc;
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)))
                            {
                              uVar24 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar24 = 3;
                              }
                              uVar4 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar4 = 3;
                              }
                              *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                   *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) -
                                   bVar20;
                            }
                            else {
                              bVar19 = UNK_00d689;
                              uVar24 = (uint)bVar19 + iVar22 + 0xd6bc;
                              uVar3 = 0x24;
                              if ((((uVar24 & 0xc000) != 0) &&
                                  (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                                uVar3 = 3;
                              }
                              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0;
                            }
                          }
                        }
                        bVar19 = UNK_00d689;
                        uVar24 = (uint)bVar19 + iVar22 + 0xd6c0;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) != '\0') {
                          iVar10 = Ram00f652;
                          uVar24 = iVar10 + 0x26;
                          uVar3 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          iVar10 = Ram00d65e;
                          if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                            bVar20 = egs52_compute_from_near_d688_0da518(4,uVar21,iVar23);
                            bVar19 = UNK_00d689;
                            uVar3 = (uint)bVar19 + iVar22 + 0xd6c0;
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)))
                            {
                              uVar24 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar24 = 3;
                              }
                              uVar4 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar4 = 3;
                              }
                              *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                   *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) -
                                   bVar20;
                            }
                            else {
                              bVar19 = UNK_00d689;
                              uVar24 = (uint)bVar19 + iVar22 + 0xd6c0;
                              uVar3 = 0x24;
                              if ((((uVar24 & 0xc000) != 0) &&
                                  (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                                uVar3 = 3;
                              }
                              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0;
                            }
                          }
                        }
                      }
                    }
                    bVar19 = UNK_00d688;
                    iVar22 = Ram00f652;
                    uVar24 = iVar22 + 0xaa;
                    uVar3 = 0x24;
                    if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                       (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                      uVar3 = 3;
                    }
                    iVar10 = (int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                    iVar15 = Ram00d690;
                    iVar16 = Ram00d690;
                    if (iVar10 != iVar16 && iVar15 <= iVar10) {
                      uVar3 = iVar22 + 0x41;
                      uVar24 = 0x24;
                      if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                         && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                        uVar24 = 3;
                      }
                      bVar20 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                      bVar6 = UNK_00d649;
                      bVar14 = UNK_00d649;
                      if (bVar20 != bVar14 && bVar6 <= bVar20) {
                        bVar20 = UNK_00d689;
                        iVar22 = (uint)bVar19 * 4;
                        uVar24 = (uint)bVar20 + iVar22 + 0xd6bb;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) != '\0') {
                          iVar10 = Ram00f652;
                          uVar24 = iVar10 + 0x32;
                          uVar3 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          iVar10 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                          iVar15 = Ram00d65e;
                          iVar16 = Ram00d65e;
                          if (iVar10 != iVar16 && iVar15 <= iVar10) {
                            bVar20 = egs52_compute_from_near_d688_0da518(1,uVar21,iVar23);
                            bVar19 = UNK_00d689;
                            uVar3 = (uint)bVar19 + iVar22 + 0xd6bb;
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)))
                            {
                              uVar24 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar24 = 3;
                              }
                              uVar4 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar4 = 3;
                              }
                              *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                   *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) -
                                   bVar20;
                            }
                            else {
                              bVar19 = UNK_00d689;
                              uVar24 = (uint)bVar19 + iVar22 + 0xd6bb;
                              uVar3 = 0x24;
                              if ((((uVar24 & 0xc000) != 0) &&
                                  (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                                uVar3 = 3;
                              }
                              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0;
                            }
                          }
                        }
                        bVar19 = UNK_00d689;
                        uVar24 = (uint)bVar19 + iVar22 + 0xd6bf;
                        uVar3 = 0x24;
                        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)
                            ) && (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) != '\0') {
                          iVar10 = Ram00f652;
                          uVar24 = iVar10 + 0x26;
                          uVar3 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          iVar10 = Ram00d65e;
                          if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar10) {
                            bVar20 = egs52_compute_from_near_d688_0da518(2,uVar21,iVar23);
                            bVar19 = UNK_00d689;
                            uVar3 = (uint)bVar19 + iVar22 + 0xd6bf;
                            uVar24 = 0x24;
                            if ((((uVar3 & 0xc000) != 0) &&
                                (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                               (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                              uVar24 = 3;
                            }
                            if (bVar20 < *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)))
                            {
                              uVar24 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar24 = 3;
                              }
                              uVar4 = 0x24;
                              if ((((uVar3 & 0xc000) != 0) &&
                                  (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                                 (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                                uVar4 = 3;
                              }
                              *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                                   *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) -
                                   bVar20;
                            }
                            else {
                              bVar19 = UNK_00d689;
                              uVar24 = (uint)bVar19 + iVar22 + 0xd6bf;
                              uVar3 = 0x24;
                              if ((((uVar24 & 0xc000) != 0) &&
                                  (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                                uVar3 = 3;
                              }
                              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = 0;
                            }
                          }
                        }
                      }
                    }
                    for (bVar19 = UNK_00d688; bVar19 != 0; bVar19 = bVar19 - 1) {
                      for (bVar20 = UNK_00d689; bVar20 != 0; bVar20 = bVar20 - 1) {
                        iVar22 = (uint)bVar20 + (uint)bVar19 * 4;
                        uVar3 = iVar22 + 0xd6bf;
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        uVar4 = iVar22 + 0xd6c0;
                        uVar24 = 0x24;
                        if ((((uVar4 & 0xc000) != 0) && (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar4 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar9 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) && (uVar9 = 0x21, (uVar3 & 0xc000) != 0x4000)
                              ) && (uVar9 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar9 = 3;
                          }
                          *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        }
                        uVar9 = iVar22 + 0xd6bc;
                        uVar24 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        bVar6 = *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
                        uVar24 = 0x24;
                        if ((((uVar4 & 0xc000) != 0) && (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        pbVar5 = (byte *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        if (bVar6 != *pbVar5 && *pbVar5 <= bVar6) {
                          uVar24 = 0x24;
                          if ((((uVar4 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar1 = 0x24;
                          if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)
                              ) && (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                            uVar1 = 3;
                          }
                          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar4 & 0x3fff));
                        }
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        uVar1 = iVar22 + 0xd6bb;
                        uVar4 = 0x24;
                        if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000))
                           && (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                          uVar4 = 3;
                        }
                        if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) <
                            *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) {
                          uVar24 = 0x24;
                          if ((((uVar3 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar4 = 0x24;
                          if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)
                              ) && (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                            uVar4 = 3;
                          }
                          *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                        }
                        uVar24 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        uVar3 = 0x24;
                        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000))
                           && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                          uVar3 = 3;
                        }
                        if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff)) <
                            *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
                          uVar24 = 0x24;
                          if ((((uVar9 & 0xc000) != 0) &&
                              (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
                             (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                            uVar24 = 3;
                          }
                          uVar3 = 0x24;
                          if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)
                              ) && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) =
                               *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
                        }
                      }
                    }
                  }
                  uVar17 = Ram00d65e;
                  uVar12 = UNK_00d649;
                  iVar22 = egs52_update_near_d688_0da630(uVar17,uVar12);
                  uVar24 = iVar22 * 0xc;
                  Ram00d6b6 = uVar24;
                  uVar3 = Ram00d6b4;
                  lVar11 = CONCAT22(-(uint)(uVar24 < uVar3),uVar24 - uVar3) * 10;
                  uVar24 = (uint)lVar11;
                  uVar3 = Ram00d670;
                  Ram00d670 = uVar3 - uVar24;
                  iVar22 = Ram00d672;
                  Ram00d672 = (iVar22 - (int)((ulong)lVar11 >> 0x10)) - (uint)(uVar3 < uVar24);
                }
              }
              Ram00d680 = 0;
              Ram00d66c = 0;
              Ram00d66e = 0;
            }
            else {
              iVar22 = Ram00d680;
              if ((iVar22 == 0) || (cVar13 = UNK_00d696, cVar13 == '\0')) {
                iVar23 = Ram00d6f8;
                iVar22 = Ram00d660;
                iVar10 = Ram00f652;
                uVar24 = iVar10 + 0x37;
                uVar3 = 0x24;
                if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                uVar4 = (uint)(((long)(iVar23 - iVar22) *
                               (long)(int)(uint)*(byte *)((uint3)uVar3 << 0xe |
                                                         (uint3)(uVar24 & 0x3fff))) / 100);
                iVar22 = (int)uVar4 >> 0xf;
                uVar24 = iVar10 + 0x10c;
                uVar3 = 0x24;
                if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                   (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                  uVar3 = 3;
                }
                uVar24 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                iVar23 = (int)uVar24 >> 0xf;
                uVar3 = (uint)(uVar4 < uVar24);
                if (iVar22 - iVar23 == uVar3 && uVar4 == uVar24 ||
                    (int)((iVar22 - iVar23) - uVar3) < 0 !=
                    (SBORROW2(iVar22,iVar23) != SBORROW2(iVar22 - iVar23,(uint)(uVar4 < uVar24)))) {
                  iVar22 = Ram00f652;
                  uVar24 = iVar22 + 0x10c;
                  uVar3 = 0x24;
                  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                    uVar3 = 3;
                  }
                  uVar24 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
                }
                else {
                  iVar22 = Ram00d6f8;
                  iVar10 = Ram00d660;
                  iVar23 = Ram00f652;
                  uVar24 = iVar23 + 0x37;
                  uVar3 = 0x24;
                  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                    uVar3 = 3;
                  }
                  uVar24 = (uint)(((long)(iVar22 - iVar10) *
                                  (long)(int)(uint)*(byte *)((uint3)uVar3 << 0xe |
                                                            (uint3)(uVar24 & 0x3fff))) / 100);
                }
                uVar3 = Ram00d666;
                uVar4 = Ram00d66c;
                iVar22 = Ram00d66e;
                Ram00d66c = (uVar3 + uVar4) - uVar24;
                Ram00d66e = ((((int)uVar3 >> 0xf) + iVar22 + (uint)CARRY2(uVar3,uVar4)) -
                            ((int)uVar24 >> 0xf)) - (uint)(uVar3 + uVar4 < uVar24);
                iVar22 = Ram00d680;
                Ram00d680 = iVar22 + 1;
                UNK_00d696 = 0;
              }
              else {
                Ram00d680 = 0;
                Ram00d66c = 0;
                Ram00d66e = 0;
              }
            }
          }
          else {
            iVar22 = Ram00f652;
            uVar24 = iVar22 + 0x38;
            uVar3 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar3 = 3;
            }
            iVar23 = Ram00d65e;
            if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < iVar23) {
              uVar24 = iVar22 + 0x36;
              uVar3 = 0x24;
              if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              iVar22 = (int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
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
                uVar3 = iVar22 + 0xac;
                uVar4 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                if (uVar24 < *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff))) {
                  uVar24 = iVar22 + 0x3a;
                  uVar3 = 0x24;
                  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                    uVar3 = 3;
                  }
                  uVar4 = Ram00d63e;
                  if ((*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < uVar4) &&
                     (uVar24 = Ram00fd2a, (uVar24 & 1) == 0)) {
                    uVar24 = iVar22 + 0x9a;
                    uVar3 = 0x24;
                    if (((uVar24 & 0xc000) != 0) &&
                       ((uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000 &&
                        (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)))) {
                      uVar3 = 3;
                    }
                    bVar19 = UNK_00d649;
                    if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar19) {
                      uVar3 = iVar22 + 0x24;
                      uVar24 = 0x24;
                      if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                         && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                        uVar24 = 3;
                      }
                      uVar24 = (uint)*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
                      uVar4 = Ram00d680;
                      uVar9 = Ram00d680;
                      if (uVar24 == uVar9 || uVar24 < uVar4) {
                        uVar17 = Ram00d66c;
                        uVar18 = Ram00d66e;
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        Ram00d690 = (int)(CONCAT22(uVar18,uVar17) /
                                         (long)(ulong)*(byte *)((uint3)uVar24 << 0xe |
                                                               (uint3)(uVar3 & 0x3fff)));
                        iVar22 = Ram00f652;
                        uVar3 = iVar22 + 0xae;
                        uVar24 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        iVar22 = Ram00f652;
                        uVar9 = iVar22 + 0x3c;
                        uVar4 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar4 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar4 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar4 = 3;
                        }
                        iVar22 = Ram00d690;
                        if (*(int *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) +
                            *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar9 & 0x3fff)) < iVar22) {
                          iVar22 = Ram00f652;
                          uVar24 = iVar22 + 0xb0;
                          uVar4 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar4 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar4 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar4 = 3;
                          }
                          bVar19 = *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar24 & 0x3fff));
                          bVar20 = UNK_00d6dc;
                          bVar6 = UNK_00d6dc;
                          if (bVar19 != bVar6 && bVar20 <= bVar19) {
                            cVar13 = UNK_00d6dc;
                            UNK_00d6dc = cVar13 + '\x01';
                          }
                        }
                        uVar24 = 0x24;
                        if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000))
                           && (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
                          uVar24 = 3;
                        }
                        uVar4 = 0x24;
                        if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000))
                           && (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                          uVar4 = 3;
                        }
                        iVar22 = *(int *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff)) -
                                 *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff));
                        iVar23 = Ram00d690;
                        iVar10 = Ram00d690;
                        if (iVar22 != iVar10 && iVar23 <= iVar22) {
                          iVar22 = Ram00f652;
                          uVar24 = iVar22 + 0xad;
                          uVar3 = 0x24;
                          if ((((uVar24 & 0xc000) != 0) &&
                              (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
                             (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
                            uVar3 = 3;
                          }
                          bVar19 = UNK_00d6dc;
                          if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) < bVar19) {
                            cVar13 = UNK_00d6dc;
                            UNK_00d6dc = cVar13 + -1;
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
                        cVar13 = UNK_00d696;
                        if (cVar13 == '\x01') {
                          uVar24 = Ram00d666;
                          uVar3 = Ram00d66c;
                          Ram00d66c = uVar3 + uVar24;
                          iVar22 = Ram00d66e;
                          Ram00d66e = iVar22 + ((int)uVar24 >> 0xf) + (uint)CARRY2(uVar3,uVar24);
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
                      goto LAB_0dd5be;
                    }
                  }
                }
              }
            }
            Ram00d680 = 0;
            Ram00d66c = 0;
            Ram00d66e = 0;
          }
        }
LAB_0dd5be:
        bVar19 = 0;
        do {
          uVar3 = bVar19 + 0xd6c0;
          uVar24 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          iVar22 = Ram00f652;
          uVar9 = iVar22 + 0x11c + (uint)bVar19;
          uVar4 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar4 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          if (*(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) <
              *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar9 & 0x3fff))) {
            uVar24 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar24 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar24 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar24 = 3;
            }
            uVar4 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
                 *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar9 & 0x3fff));
          }
          bVar19 = bVar19 + 1;
        } while (bVar19 < 4);
        uVar12 = UNK_00d649;
        iVar23 = egs52_update_near_d688_0da630(0,uVar12);
        iVar22 = Ram00d68e;
        Ram00d660 = iVar23 * 0xc + iVar22 * 3;
        goto LAB_0dd62c;
      }
    }
  }
  Ram00d680 = 0;
  Ram00d66c = 0;
  Ram00d66e = 0;
  iVar22 = Ram00f652;
  uVar24 = iVar22 + 0x80;
  uVar3 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d684 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
  uVar3 = iVar22 + 0xf0;
  uVar24 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar24 = 3;
  }
  Ram00d6ec = *(undefined2 *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
  uVar24 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar24 = 3;
  }
  Ram00d6ec = *(undefined2 *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
LAB_0dd62c:
  iVar22 = Ram00d694;
  if (iVar22 != 0) {
    uVar12 = UNK_00d6dc;
    iVar22 = Ram00f6fe;
    uVar24 = iVar22 + 2;
    uVar3 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) = uVar12;
    bVar19 = 0;
    do {
      bVar20 = 0;
      do {
        iVar22 = (uint)bVar20 + (uint)bVar19 * 4;
        uVar24 = iVar22 + 0xd6c0;
        uVar3 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        iVar23 = Ram00f6fe;
        uVar9 = iVar23 + 4 + iVar22;
        uVar4 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar4 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar9 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff));
        bVar20 = bVar20 + 1;
      } while (bVar20 < 4);
      bVar19 = bVar19 + 1;
    } while (bVar19 < 7);
  }
  return;
}


