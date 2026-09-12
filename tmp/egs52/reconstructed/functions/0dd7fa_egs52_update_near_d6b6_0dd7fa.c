/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dd7fa; FLS offset 0x05d7fa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Removing unreachable block (ram,0x0ddffc) */
/* WARNING: Removing unreachable block (ram,0x0ddff8) */
/* WARNING: Removing unreachable block (ram,0x0ddff4) */
/* WARNING: Removing unreachable block (ram,0x0ddfc4) */
/* WARNING: Removing unreachable block (ram,0x0ddfc0) */
/* WARNING: Removing unreachable block (ram,0x0ddfb8) */
/* WARNING: Removing unreachable block (ram,0x0ddfac) */
/* WARNING: Removing unreachable block (ram,0x0ddfa4) */
/* WARNING: Removing unreachable block (ram,0x0ddf98) */
/* WARNING: Removing unreachable block (ram,0x0ddf90) */
/* WARNING: Removing unreachable block (ram,0x0ddf8c) */
/* WARNING: Removing unreachable block (ram,0x0ddf5e) */
/* WARNING: Removing unreachable block (ram,0x0ddf74) */
/* WARNING: Removing unreachable block (ram,0x0ddf68) */
/* WARNING: Removing unreachable block (ram,0x0ddf64) */
/* WARNING: Removing unreachable block (ram,0x0ddf4a) */
/* WARNING: Removing unreachable block (ram,0x0ddf30) */
/* WARNING: Removing unreachable block (ram,0x0ddf46) */
/* WARNING: Removing unreachable block (ram,0x0ddf3a) */
/* WARNING: Removing unreachable block (ram,0x0ddf36) */
/* WARNING: Removing unreachable block (ram,0x0ddf1c) */
/* WARNING: Removing unreachable block (ram,0x0ddee2) */
/* WARNING: Removing unreachable block (ram,0x0ddee0) */
/* WARNING: Removing unreachable block (ram,0x0ddf18) */
/* WARNING: Removing unreachable block (ram,0x0ddf16) */
/* WARNING: Removing unreachable block (ram,0x0ddf10) */
/* WARNING: Removing unreachable block (ram,0x0ddef4) */
/* WARNING: Removing unreachable block (ram,0x0ddef0) */
/* WARNING: Removing unreachable block (ram,0x0ddeec) */
/* WARNING: Removing unreachable block (ram,0x0ddeb4) */
/* WARNING: Removing unreachable block (ram,0x0ddeac) */
/* WARNING: Removing unreachable block (ram,0x0ddea2) */
/* WARNING: Removing unreachable block (ram,0x0dde9e) */
/* WARNING: Removing unreachable block (ram,0x0dde92) */
/* WARNING: Removing unreachable block (ram,0x0dde8a) */
/* WARNING: Removing unreachable block (ram,0x0dde82) */
/* WARNING: Removing unreachable block (ram,0x0dde6a) */
/* WARNING: Removing unreachable block (ram,0x0dde66) */
/* WARNING: Removing unreachable block (ram,0x0dde62) */
/* WARNING: Removing unreachable block (ram,0x0dde5e) */
/* WARNING: Removing unreachable block (ram,0x0dde4a) */
/* WARNING: Removing unreachable block (ram,0x0dde42) */
/* WARNING: Removing unreachable block (ram,0x0dde0a) */
/* WARNING: Removing unreachable block (ram,0x0dddfe) */
/* WARNING: Removing unreachable block (ram,0x0dde2c) */
/* WARNING: Removing unreachable block (ram,0x0dde24) */
/* WARNING: Removing unreachable block (ram,0x0dddf6) */
/* WARNING: Removing unreachable block (ram,0x0dddf2) */
/* WARNING: Removing unreachable block (ram,0x0dddf0) */
/* WARNING: Removing unreachable block (ram,0x0dddea) */
/* WARNING: Removing unreachable block (ram,0x0ddde6) */
/* WARNING: Removing unreachable block (ram,0x0ddde4) */
/* WARNING: Removing unreachable block (ram,0x0dddd6) */
/* WARNING: Removing unreachable block (ram,0x0ddd74) */
/* WARNING: Removing unreachable block (ram,0x0ddd70) */
/* WARNING: Removing unreachable block (ram,0x0ddd6c) */
/* WARNING: Removing unreachable block (ram,0x0ddd60) */
/* WARNING: Removing unreachable block (ram,0x0ddd5c) */
/* WARNING: Removing unreachable block (ram,0x0ddd58) */
/* WARNING: Removing unreachable block (ram,0x0ddd4c) */
/* WARNING: Removing unreachable block (ram,0x0ddd48) */
/* WARNING: Removing unreachable block (ram,0x0ddd44) */
/* WARNING: Removing unreachable block (ram,0x0ddd3e) */
/* WARNING: Removing unreachable block (ram,0x0ddd22) */
/* WARNING: Removing unreachable block (ram,0x0ddd14) */
/* WARNING: Removing unreachable block (ram,0x0ddd10) */
/* WARNING: Removing unreachable block (ram,0x0ddd3a) */
/* WARNING: Removing unreachable block (ram,0x0ddd2c) */
/* WARNING: Removing unreachable block (ram,0x0ddd28) */
/* WARNING: Removing unreachable block (ram,0x0ddd0a) */
/* WARNING: Removing unreachable block (ram,0x0ddd02) */
/* WARNING: Removing unreachable block (ram,0x0ddcfe) */
/* WARNING: Removing unreachable block (ram,0x0ddcf8) */
/* WARNING: Removing unreachable block (ram,0x0ddcf4) */
/* WARNING: Removing unreachable block (ram,0x0ddcf0) */
/* WARNING: Removing unreachable block (ram,0x0ddce0) */
/* WARNING: Removing unreachable block (ram,0x0ddcd8) */
/* WARNING: Removing unreachable block (ram,0x0ddcca) */
/* WARNING: Removing unreachable block (ram,0x0ddcc4) */
/* WARNING: Removing unreachable block (ram,0x0ddcba) */
/* WARNING: Removing unreachable block (ram,0x0ddd96) */
/* WARNING: Removing unreachable block (ram,0x0ddd92) */
/* WARNING: Removing unreachable block (ram,0x0ddd8c) */
/* WARNING: Removing unreachable block (ram,0x0ddd88) */
/* WARNING: Removing unreachable block (ram,0x0dddc0) */
/* WARNING: Removing unreachable block (ram,0x0dddb8) */
/* WARNING: Removing unreachable block (ram,0x0dddb0) */
/* WARNING: Removing unreachable block (ram,0x0dddaa) */
/* WARNING: Removing unreachable block (ram,0x0ddda6) */
/* WARNING: Removing unreachable block (ram,0x0dddd0) */
/* WARNING: Removing unreachable block (ram,0x0dddca) */
/* WARNING: Removing unreachable block (ram,0x0dddc6) */
/* WARNING: Removing unreachable block (ram,0x0ddda0) */
/* WARNING: Removing unreachable block (ram,0x0ddd9c) */
/* WARNING: Removing unreachable block (ram,0x0ddd80) */
/* WARNING: Removing unreachable block (ram,0x0ddd7c) */
/* WARNING: Removing unreachable block (ram,0x0ddcb0) */
/* WARNING: Removing unreachable block (ram,0x0ddcac) */
/* WARNING: Removing unreachable block (ram,0x0ddca6) */
/* WARNING: Removing unreachable block (ram,0x0ddc96) */
/* WARNING: Removing unreachable block (ram,0x0ddc8e) */
/* WARNING: Removing unreachable block (ram,0x0ddc6c) */
/* WARNING: Removing unreachable block (ram,0x0ddc68) */
/* WARNING: Removing unreachable block (ram,0x0ddc66) */
/* WARNING: Removing unreachable block (ram,0x0ddc62) */
/* WARNING: Removing unreachable block (ram,0x0ddc50) */
/* WARNING: Removing unreachable block (ram,0x0ddc48) */
/* WARNING: Removing unreachable block (ram,0x0ddc3c) */
/* WARNING: Removing unreachable block (ram,0x0ddc30) */
/* WARNING: Removing unreachable block (ram,0x0ddc2c) */
/* WARNING: Removing unreachable block (ram,0x0ddc1a) */
/* WARNING: Removing unreachable block (ram,0x0ddc12) */
/* WARNING: Removing unreachable block (ram,0x0ddc06) */
/* WARNING: Removing unreachable block (ram,0x0ddbfe) */
/* WARNING: Removing unreachable block (ram,0x0ddbfa) */
/* WARNING: Removing unreachable block (ram,0x0ddbe6) */
/* WARNING: Removing unreachable block (ram,0x0ddbd4) */
/* WARNING: Removing unreachable block (ram,0x0ddbc8) */
/* WARNING: Removing unreachable block (ram,0x0ddbbe) */
/* WARNING: Removing unreachable block (ram,0x0ddbb0) */
/* WARNING: Removing unreachable block (ram,0x0ddbac) */
/* WARNING: Removing unreachable block (ram,0x0ddba4) */
/* WARNING: Removing unreachable block (ram,0x0ddb98) */
/* WARNING: Removing unreachable block (ram,0x0ddb90) */
/* WARNING: Removing unreachable block (ram,0x0ddc88) */
/* WARNING: Removing unreachable block (ram,0x0ddc82) */
/* WARNING: Removing unreachable block (ram,0x0ddc7e) */
/* WARNING: Removing unreachable block (ram,0x0ddc7a) */
/* WARNING: Removing unreachable block (ram,0x0ddc76) */
/* WARNING: Removing unreachable block (ram,0x0ddc72) */
/* WARNING: Removing unreachable block (ram,0x0ddb88) */
/* WARNING: Removing unreachable block (ram,0x0ddb76) */
/* WARNING: Removing unreachable block (ram,0x0ddb6e) */
/* WARNING: Removing unreachable block (ram,0x0ddb6a) */
/* WARNING: Removing unreachable block (ram,0x0ddb62) */
/* WARNING: Removing unreachable block (ram,0x0ddb5e) */
/* WARNING: Removing unreachable block (ram,0x0ddb5a) */
/* WARNING: Removing unreachable block (ram,0x0ddb4a) */
/* WARNING: Removing unreachable block (ram,0x0ddb42) */
/* WARNING: Removing unreachable block (ram,0x0ddb3a) */
/* WARNING: Removing unreachable block (ram,0x0ddb2e) */
/* WARNING: Removing unreachable block (ram,0x0ddb2a) */
/* WARNING: Removing unreachable block (ram,0x0ddb26) */
/* WARNING: Removing unreachable block (ram,0x0ddb1c) */
/* WARNING: Removing unreachable block (ram,0x0ddb14) */
/* WARNING: Removing unreachable block (ram,0x0ddb10) */
/* WARNING: Removing unreachable block (ram,0x0ddb04) */
/* WARNING: Removing unreachable block (ram,0x0ddafe) */
/* WARNING: Removing unreachable block (ram,0x0ddafa) */
/* WARNING: Removing unreachable block (ram,0x0ddaf2) */
/* WARNING: Removing unreachable block (ram,0x0ddaee) */
/* WARNING: Removing unreachable block (ram,0x0ddae2) */
/* WARNING: Removing unreachable block (ram,0x0ddade) */
/* WARNING: Removing unreachable block (ram,0x0ddad8) */
/* WARNING: Removing unreachable block (ram,0x0ddad2) */
/* WARNING: Removing unreachable block (ram,0x0ddacc) */
/* WARNING: Removing unreachable block (ram,0x0ddab6) */
/* WARNING: Removing unreachable block (ram,0x0ddac6) */
/* WARNING: Removing unreachable block (ram,0x0ddab2) */
/* WARNING: Removing unreachable block (ram,0x0ddaa4) */
/* WARNING: Removing unreachable block (ram,0x0dda98) */
/* WARNING: Removing unreachable block (ram,0x0dda8e) */
/* WARNING: Removing unreachable block (ram,0x0dda8a) */
/* WARNING: Removing unreachable block (ram,0x0dda84) */
/* WARNING: Removing unreachable block (ram,0x0dda80) */
/* WARNING: Removing unreachable block (ram,0x0dda1a) */
/* WARNING: Removing unreachable block (ram,0x0dda18) */
/* WARNING: Removing unreachable block (ram,0x0dda16) */
/* WARNING: Removing unreachable block (ram,0x0dda52) */
/* WARNING: Removing unreachable block (ram,0x0dda50) */
/* WARNING: Removing unreachable block (ram,0x0dda4e) */
/* WARNING: Removing unreachable block (ram,0x0dda78) */
/* WARNING: Removing unreachable block (ram,0x0dda74) */
/* WARNING: Removing unreachable block (ram,0x0dda6a) */
/* WARNING: Removing unreachable block (ram,0x0dda66) */
/* WARNING: Removing unreachable block (ram,0x0dda60) */
/* WARNING: Removing unreachable block (ram,0x0dda5e) */
/* WARNING: Removing unreachable block (ram,0x0dda56) */
/* WARNING: Removing unreachable block (ram,0x0dda44) */
/* WARNING: Removing unreachable block (ram,0x0dda3c) */
/* WARNING: Removing unreachable block (ram,0x0dda38) */
/* WARNING: Removing unreachable block (ram,0x0dda34) */
/* WARNING: Removing unreachable block (ram,0x0dda2a) */
/* WARNING: Removing unreachable block (ram,0x0dda24) */
/* WARNING: Removing unreachable block (ram,0x0dda1e) */
/* WARNING: Removing unreachable block (ram,0x0dda0c) */
/* WARNING: Removing unreachable block (ram,0x0dda06) */
/* WARNING: Removing unreachable block (ram,0x0dd9fe) */
/* WARNING: Removing unreachable block (ram,0x0dd9fa) */
/* WARNING: Removing unreachable block (ram,0x0dd9f2) */
/* WARNING: Removing unreachable block (ram,0x0dd9e6) */
/* WARNING: Removing unreachable block (ram,0x0dd9de) */
/* WARNING: Removing unreachable block (ram,0x0dd9d8) */
/* WARNING: Removing unreachable block (ram,0x0dd9d4) */
/* WARNING: Removing unreachable block (ram,0x0dd9d0) */
/* WARNING: Removing unreachable block (ram,0x0dd9c8) */
/* WARNING: Removing unreachable block (ram,0x0dd9c4) */
/* WARNING: Removing unreachable block (ram,0x0dd9bc) */
/* WARNING: Removing unreachable block (ram,0x0dd9b8) */
/* WARNING: Removing unreachable block (ram,0x0dd9b4) */
/* WARNING: Removing unreachable block (ram,0x0dd9ae) */
/* WARNING: Removing unreachable block (ram,0x0dd9a0) */
/* WARNING: Removing unreachable block (ram,0x0dd998) */
/* WARNING: Removing unreachable block (ram,0x0dd994) */
/* WARNING: Removing unreachable block (ram,0x0dd98c) */
/* WARNING: Removing unreachable block (ram,0x0dd988) */
/* WARNING: Removing unreachable block (ram,0x0dd984) */
/* WARNING: Removing unreachable block (ram,0x0dd974) */
/* WARNING: Removing unreachable block (ram,0x0dd96c) */
/* WARNING: Removing unreachable block (ram,0x0dd964) */
/* WARNING: Removing unreachable block (ram,0x0dd958) */
/* WARNING: Removing unreachable block (ram,0x0dd950) */
/* WARNING: Removing unreachable block (ram,0x0dd94c) */
/* WARNING: Removing unreachable block (ram,0x0dd946) */
/* WARNING: Removing unreachable block (ram,0x0dd942) */
/* WARNING: Removing unreachable block (ram,0x0dd93e) */
/* WARNING: Removing unreachable block (ram,0x0dd936) */
/* WARNING: Removing unreachable block (ram,0x0dd932) */
/* WARNING: Removing unreachable block (ram,0x0dd92c) */
/* WARNING: Removing unreachable block (ram,0x0dd928) */
/* WARNING: Removing unreachable block (ram,0x0dd924) */
/* WARNING: Removing unreachable block (ram,0x0dd920) */
/* WARNING: Removing unreachable block (ram,0x0dd91a) */
/* WARNING: Removing unreachable block (ram,0x0dd90a) */
/* WARNING: Removing unreachable block (ram,0x0dd906) */
/* WARNING: Removing unreachable block (ram,0x0dd8fa) */
/* WARNING: Removing unreachable block (ram,0x0dd8ea) */
/* WARNING: Removing unreachable block (ram,0x0dd8e4) */
/* WARNING: Removing unreachable block (ram,0x0dd8cc) */
/* WARNING: Removing unreachable block (ram,0x0dd8a0) */
/* WARNING: Removing unreachable block (ram,0x0dd8aa) */
/* WARNING: Removing unreachable block (ram,0x0dd890) */
/* WARNING: Removing unreachable block (ram,0x0dd88c) */
/* WARNING: Removing unreachable block (ram,0x0dd888) */
/* WARNING: Removing unreachable block (ram,0x0dd884) */
/* WARNING: Removing unreachable block (ram,0x0dd880) */
/* WARNING: Removing unreachable block (ram,0x0dd87c) */
/* WARNING: Removing unreachable block (ram,0x0dd874) */
/* WARNING: Removing unreachable block (ram,0x0dd868) */
/* WARNING: Removing unreachable block (ram,0x0dd864) */
/* WARNING: Removing unreachable block (ram,0x0dd860) */
/* WARNING: Removing unreachable block (ram,0x0dd85c) */
/* WARNING: Removing unreachable block (ram,0x0dd858) */
/* WARNING: Removing unreachable block (ram,0x0dd850) */
/* WARNING: Removing unreachable block (ram,0x0dd848) */
/* WARNING: Removing unreachable block (ram,0x0dd840) */
/* WARNING: Removing unreachable block (ram,0x0dd83c) */
/* WARNING: Removing unreachable block (ram,0x0dd838) */
/* WARNING: Removing unreachable block (ram,0x0dd834) */
/* WARNING: Removing unreachable block (ram,0x0dd824) */
/* WARNING: Removing unreachable block (ram,0x0dd820) */
/* WARNING: Removing unreachable block (ram,0x0dd81c) */
/* WARNING: Removing unreachable block (ram,0x0dd818) */
/* WARNING: Removing unreachable block (ram,0x0dd814) */
/* WARNING: Removing unreachable block (ram,0x0dd810) */
/* WARNING: Removing unreachable block (ram,0x0dd80c) */
/* WARNING: Removing unreachable block (ram,0x0dd804) */
/* WARNING: Removing unreachable block (ram,0x0dd82c) */
/* WARNING: Removing unreachable block (ram,0x0dd8a8) */
/* WARNING: Removing unreachable block (ram,0x0dd8bc) */
/* WARNING: Removing unreachable block (ram,0x0dd8c4) */
/* WARNING: Removing unreachable block (ram,0x0dda7c) */
/* WARNING: Removing unreachable block (ram,0x0dda9e) */
/* WARNING: Removing unreachable block (ram,0x0ddb86) */
/* WARNING: Removing unreachable block (ram,0x0ddc92) */
/* WARNING: Removing unreachable block (ram,0x0ddca2) */
/* WARNING: Removing unreachable block (ram,0x0ddcbe) */
/* WARNING: Removing unreachable block (ram,0x0dddda) */
/* WARNING: Removing unreachable block (ram,0x0dde20) */
/* WARNING: Removing unreachable block (ram,0x0dde02) */
/* WARNING: Removing unreachable block (ram,0x0dde9a) */
/* WARNING: Removing unreachable block (ram,0x0ddec0) */
/* WARNING: Removing unreachable block (ram,0x0ddeda) */
/* WARNING: Removing unreachable block (ram,0x0ddf24) */
/* WARNING: Removing unreachable block (ram,0x0ddf52) */
/* WARNING: Removing unreachable block (ram,0x0ddfdc) */
/* WARNING: Removing unreachable block (ram,0x0ddfe0) */

void egs52_update_near_d6b6_0dd7fa(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  char cVar8;
  byte bVar9;
  long lVar10;
  ulong uVar11;
  char cVar12;
  char cVar13;
  undefined1 uVar14;
  int iVar15;
  int iVar16;
  short old;
  ushort old_00;
  int iVar17;
  byte bVar18;
  short sVar19;
  undefined2 uVar20;
  int iVar21;
  ushort uVar22;
  byte bVar23;
  uint uVar24;
  int iVar25;
  
  Ram00d6b6 = 0;
  egs52_update_near_d67a_0da9b8();
  uVar20 = Ram00d69e;
  Ram00d6b8 = uVar20;
  uVar20 = Ram00d6e0;
  Ram00d6e2 = uVar20;
  iVar25 = Ram00d63e;
  iVar21 = Ram00d640;
  Ram00d6e0 = iVar25 - iVar21;
  if (iVar25 - iVar21 < 0) {
    iVar25 = Ram00d6e0;
    iVar25 = -iVar25;
  }
  else {
    iVar25 = Ram00d6e0;
  }
  Ram00d69e = iVar25;
  iVar21 = Ram00f652;
  uVar1 = iVar21 + 0x124;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  sVar19 = Ram00d6f6;
  sVar19 = egs52_weighted_average_s16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),iVar25,sVar19);
  Ram00d6f6 = sVar19;
  uVar20 = egs52_update_near_d6ba_0db50a();
  Ram00d664 = uVar20;
  iVar21 = Ram00d69e;
  iVar25 = Ram00d664;
  Ram00d662 = iVar21 - iVar25;
  bVar18 = UNK_00d647;
  if (((bVar18 < 3) || (5 < bVar18)) || (bVar18 = UNK_00d646, (bVar18 & 8) != 0)) {
    iVar25 = Ram00f652;
    uVar1 = iVar25 + 0x22;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d694 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar25 = Ram00f6fe;
    uVar1 = iVar25 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d6dc = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar18 = 0;
    do {
      bVar23 = 0;
      do {
        iVar25 = (uint)bVar23 + (uint)bVar18 * 4;
        iVar21 = Ram00f6fe;
        uVar2 = iVar21 + 4 + iVar25;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar24 = iVar25 + 0xd6c0;
        uVar3 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar3 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar24 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
        bVar23 = bVar23 + 1;
      } while (bVar23 < 4);
      bVar18 = bVar18 + 1;
    } while (bVar18 < 7);
  }
  iVar25 = Ram00f654;
  iVar21 = Ram00f654;
  uVar1 = Ram00d640;
  bVar18 = egs52_curve_u8('\x05',(uchar *)(iVar25 + 0x50),(uchar *)(iVar21 + 0x55),
                          (uchar)(uVar1 / 0x1e));
  Ram00d68e = (uint)bVar18;
  uVar14 = UNK_00d649;
  iVar21 = egs52_update_near_d688_0da630(0,uVar14);
  iVar25 = Ram00d68e;
  Ram00d660 = iVar21 * 0xc + iVar25 * 3;
  bVar18 = UNK_00d647;
  if ((bVar18 != 0) && (bVar18 < 6)) {
    iVar25 = Ram00f652;
    uVar1 = iVar25 + (uint)bVar18 * 2 + 0x5c;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    iVar25 = Ram00d660;
    Ram00d660 = iVar25 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar25 = Ram00f652;
  uVar1 = iVar25 + 0x45;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  sVar19 = Ram00d63c;
  old = Ram00d6a6;
  sVar19 = egs52_weighted_average_s16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),sVar19,old);
  Ram00d6a6 = sVar19;
  iVar25 = Ram00f652;
  uVar1 = iVar25 + 0x46;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar22 = Ram00d64c;
  old_00 = Ram00d6aa;
  uVar22 = egs52_weighted_average_u16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),uVar22,old_00);
  Ram00d6aa = uVar22;
  uVar1 = Ram00fd2a;
  if ((((uVar1 & 0x800) == 0) || (iVar25 = Ram00d64a, iVar25 != 0)) ||
     ((cVar8 = UNK_00d648, cVar8 != '\0' || ((bVar18 = UNK_00d647, bVar18 == 0 || (6 < bVar18))))))
  {
LAB_0dda7c:
    iVar25 = Ram00f652;
    uVar1 = iVar25 + 0xf2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6ee = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  else {
    iVar25 = Ram00f652;
    uVar1 = iVar25 + 0xb1;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    bVar18 = UNK_00d649;
    if (bVar18 <= *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) goto LAB_0dda7c;
    uVar1 = iVar25 + 0xdc;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d63e;
    uVar24 = Ram00d63e;
    if (uVar1 == uVar24 || uVar1 < uVar2) goto LAB_0dda7c;
    uVar1 = iVar25 + 0xf4;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) == 0) goto LAB_0dda7c;
    uVar1 = iVar25 + 0x44;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar25 = Ram00d6a6;
    iVar21 = Ram00d6aa;
    cVar8 = UNK_00d6f0;
    sVar19 = egs52_weighted_average_s16
                       (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),iVar25 - iVar21,
                        (int)cVar8);
    UNK_00d6f0 = (char)sVar19;
    iVar25 = Ram00d6ee;
    if (iVar25 == 0) {
      iVar25 = Ram00f652;
      uVar1 = iVar25 + 0xf2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d6ee = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      iVar21 = Ram00f6fe;
      uVar2 = iVar21 + 1;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = iVar25 + 0xf5;
      uVar24 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar24 = 3;
      }
      if ((int)*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff)) <
          (int)(char)sVar19 - (int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) {
        iVar25 = Ram00f652;
        uVar1 = iVar25 + 0xf6;
        uVar24 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar24 = 3;
        }
        uVar5 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if ((int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) <
            (int)*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff)) -
            (int)*(char *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff))) {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar24 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) +
               *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
          goto LAB_0dda88;
        }
      }
      cVar8 = UNK_00d6f0;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar24 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar24 = 3;
      }
      if ((int)cVar8 - (int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) <
          -(int)*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff))) {
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iVar25 = Ram00f652;
        uVar24 = iVar25 + 0xf6;
        uVar5 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar5 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar4 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if ((int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) -
            (int)*(char *)((uint3)uVar5 << 0xe | (uint3)(uVar24 & 0x3fff)) <
            (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) {
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar24 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar24 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar24 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar24 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) -
               *(char *)((uint3)uVar24 << 0xe | (uint3)(uVar3 & 0x3fff));
          goto LAB_0dda88;
        }
      }
      iVar25 = Ram00f652;
      uVar24 = iVar25 + 0xf6;
      uVar1 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cVar8 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff));
      cVar12 = UNK_00d6f0;
      cVar13 = UNK_00d6f0;
      if (cVar8 != cVar13 && (char)(cVar8 - cVar13) < '\0' == SBORROW1(cVar8,cVar12)) {
        cVar8 = UNK_00d6f0;
        uVar1 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (-(int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff)) < (int)cVar8) {
          uVar14 = UNK_00d6f0;
          uVar1 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar14;
        }
      }
    }
  }
LAB_0dda88:
  bVar18 = UNK_00d658;
  iVar25 = Ram00f652;
  uVar2 = iVar25 + 0x127;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  pbVar7 = (byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  if (bVar18 == *pbVar7 || bVar18 < *pbVar7) {
    bVar23 = 1;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar18 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  else {
    bVar23 = 3;
    iVar25 = Ram00f652;
    uVar24 = iVar25 + 0x12a;
    uVar1 = 0x24;
    if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (bVar18 < *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff))) {
      bVar23 = 1;
      while( true ) {
        uVar24 = uVar2 + bVar23;
        uVar1 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        pbVar7 = (byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff));
        if (bVar18 == *pbVar7 || bVar18 < *pbVar7) break;
        bVar23 = bVar23 + 1;
      }
    }
    else {
      uVar1 = 0x24;
      if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar18 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff));
    }
  }
  uVar1 = bVar23 + 0xd34b;
  uVar24 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar24 = 3;
  }
  Ram00d600 = (int)*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = bVar23 + 0xd34c;
  uVar24 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar24 = 3;
  }
  Ram00d602 = (int)*(char *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar25 = Ram00f652;
  uVar24 = iVar25 + 0x126 + (uint)bVar23;
  uVar1 = 0x24;
  if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d604 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff));
  uVar2 = uVar2 + bVar23;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d606 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  Ram00d608 = (uint)bVar18;
  uVar22 = egs52_lerp_signed_axis((ushort *)0xd600);
  UNK_00d702 = (char)uVar22;
  iVar25 = Ram00f652;
  uVar2 = iVar25 + 0xf4;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 1) != 0) {
    iVar25 = Ram00f6fe;
    uVar1 = iVar25 + 1;
    uVar24 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar24 = 3;
    }
    UNK_00d702 = *(undefined1 *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar1 = Ram00fd2a;
  if ((((uVar1 & 0x800) == 0) || (iVar25 = Ram00d64a, iVar25 != 0)) ||
     ((cVar8 = UNK_00d648, cVar8 != '\0' || ((bVar18 = UNK_00d647, bVar18 == 0 || (6 < bVar18))))))
  {
LAB_0ddc8e:
    UNK_00d6dd = 0;
    Ram00d6fc = 0;
  }
  else {
    iVar25 = Ram00f652;
    uVar1 = iVar25 + 0xb1;
    uVar24 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
    {
      uVar24 = 3;
    }
    bVar18 = UNK_00d649;
    if (bVar18 <= *(byte *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff))) goto LAB_0ddc8e;
    uVar1 = iVar25 + 0xdc;
    uVar24 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar24 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar24 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar24 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar24 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar24 = Ram00d63e;
    uVar3 = Ram00d63e;
    if (uVar1 == uVar3 || uVar1 < uVar24) goto LAB_0ddc8e;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 1) != 0) goto LAB_0ddc8e;
    uVar2 = iVar25 + 0x126;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar18 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    bVar23 = UNK_00d6dd;
    bVar9 = UNK_00d6dd;
    if (bVar18 == bVar9 || bVar18 < bVar23) {
      iVar25 = Ram00d6fc;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar25 = (int)((long)iVar25 /
                    (long)(ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)));
      Ram00d6fe = iVar25;
      iVar21 = Ram00f652;
      uVar1 = iVar21 + 299;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d700 = (int)(((long)iVar25 *
                        (long)(int)(uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
                       100);
      bVar18 = UNK_00d658;
      uVar2 = iVar21 + 0x127;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      pbVar7 = (byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (bVar18 != *pbVar7 && *pbVar7 <= bVar18) {
        uVar24 = iVar21 + 0x12a;
        uVar1 = 0x24;
        if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (bVar18 < *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff))) {
          bVar23 = 1;
          while( true ) {
            uVar24 = uVar2 + bVar23;
            uVar1 = 0x24;
            if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            pbVar7 = (byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff));
            if (bVar18 == *pbVar7 || bVar18 < *pbVar7) break;
            bVar23 = bVar23 + 1;
          }
          uVar1 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar3 = iVar21 + 0x126 + (uint)bVar23;
          uVar2 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar9 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff)) -
                  *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
          uVar2 = bVar23 + 0xd34b;
          uVar1 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          iVar25 = Ram00d700;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) +
               (char)(((long)(int)((uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff)) -
                                  (uint)bVar18) * (long)iVar25) / (long)(int)(uint)bVar9);
          uVar2 = bVar23 + 0xd34c;
          iVar25 = Ram00f652;
          uVar24 = iVar25 + 0x126 + (uint)bVar23;
          uVar1 = 0x24;
          if ((((uVar24 & 0xc000) != 0) && (uVar1 = 0x21, (uVar24 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar24 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          iVar25 = Ram00d700;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          uVar5 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(char *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) +
               (char)(((long)(int)((uint)bVar18 -
                                  (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar24 & 0x3fff))) *
                      (long)iVar25) / (long)(int)(uint)bVar9);
        }
      }
      UNK_00d6dd = 0;
      Ram00d6fc = 0;
    }
    else {
      cVar8 = UNK_00d6dd;
      UNK_00d6dd = cVar8 + '\x01';
      iVar15 = Ram00d6fc;
      iVar25 = Ram00d6a6;
      iVar21 = Ram00d6aa;
      cVar8 = UNK_00d702;
      Ram00d6fc = ((iVar15 + iVar25) - iVar21) - (int)cVar8;
    }
  }
  bVar18 = UNK_00d646;
  if ((bVar18 & 0x80) == 0) {
    iVar25 = Ram00d6a6;
    iVar21 = Ram00f652;
    uVar2 = iVar21 + 0x7a;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d6be = iVar25 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    iVar25 = Ram00d63c;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d65e = iVar25 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  else {
    iVar25 = Ram00d6a6;
    cVar8 = UNK_00d702;
    Ram00d6be = iVar25 - cVar8;
    iVar25 = Ram00d692;
    if (iVar25 == 0) {
      iVar25 = Ram00f652;
      uVar1 = iVar25 + 0x125;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) == 0) {
        iVar25 = Ram00d63c;
        cVar8 = UNK_00d702;
        Ram00d65e = iVar25 - cVar8;
        Ram00d6f4 = 0;
      }
      else {
        Ram00d6f4 = 0;
        cVar8 = UNK_00d650;
        if (cVar8 == '\0') {
          iVar25 = Ram00d654;
          cVar8 = UNK_00d702;
          uVar2 = Ram00d4a0;
          uVar1 = Ram00d49e;
          Ram00d65e = ((iVar25 - cVar8) - (uVar2 >> 2)) - (uVar1 >> 2);
        }
        else {
          iVar25 = Ram00d63c;
          cVar8 = UNK_00d702;
          Ram00d65e = iVar25 - cVar8;
        }
      }
    }
    else {
      iVar25 = Ram00d640;
      iVar21 = Ram00d664;
      bVar18 = UNK_00d648;
      iVar15 = Ram00f654;
      iVar16 = Ram00f654;
      iVar17 = Ram00f654;
      iVar21 = egs52_map_s16(5,5,(short *)(iVar16 + 0x82),(short *)(iVar17 + 0x8c),
                             (short *)(iVar15 + 0x96),(uint)bVar18,iVar25 + iVar21);
      iVar25 = Ram00f652;
      uVar1 = iVar25 + 0x11a;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar25 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      iVar15 = Ram00d644;
      iVar16 = Ram00d644;
      if (iVar25 != iVar16 && iVar15 <= iVar25) {
        Ram00d692 = 0;
      }
      iVar25 = Ram00f652;
      uVar2 = iVar25 + 0xf4;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
        iVar25 = Ram00d63c;
        cVar8 = UNK_00d702;
        if (iVar21 <= iVar25 - cVar8) {
          iVar21 = iVar25 - cVar8;
        }
        Ram00d65e = iVar21;
      }
      else {
        iVar25 = Ram00d654;
        cVar8 = UNK_00d702;
        if (iVar21 <= iVar25 - cVar8) {
          iVar21 = iVar25 - cVar8;
        }
        Ram00d65e = iVar21;
      }
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0x40) == 0) {
        iVar25 = Ram00f652;
        uVar1 = iVar25 + 0x118;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar21 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        iVar15 = Ram00d644;
        iVar16 = Ram00d644;
        if (iVar21 != iVar16 && iVar15 <= iVar21) {
          iVar15 = Ram00d6f2;
          iVar21 = Ram00d64c;
          uVar1 = iVar25 + 0x112;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          iVar25 = Ram00d6f4;
          Ram00d6f4 = iVar25 + (int)(((long)(iVar15 - iVar21) *
                                     (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))
                                    / 100);
          iVar21 = Ram00d6f4;
          iVar25 = Ram00d65e;
          Ram00d65e = iVar25 - iVar21;
        }
      }
    }
  }
  uVar1 = Ram00fd2a;
  if ((uVar1 & 1) == 0) {
    iVar25 = Ram00d64a;
    iVar21 = Ram00d664;
    uVar1 = Ram00d64a;
    uVar22 = (ushort)(((ulong)uVar1 * 1000) / (ulong)(uint)(iVar25 - iVar21));
  }
  else {
    iVar25 = Ram00d64a;
    iVar21 = Ram00d664;
    uVar1 = Ram00d64a;
    uVar22 = (ushort)(((ulong)uVar1 * 1000) / (ulong)(uint)(iVar25 + iVar21));
  }
  iVar25 = Ram00f620;
  iVar21 = Ram00f620;
  uVar22 = egs52_curve_u16(0xb,(ushort *)(iVar25 + 0xc),(ushort *)(iVar21 + 0x22),uVar22);
  iVar25 = Ram00d64a;
  iVar15 = Ram00d664;
  iVar21 = Ram00d64a;
  iVar16 = Ram00d664;
  uVar1 = iVar21 + iVar16;
  uVar11 = (ulong)(uint)(iVar25 + iVar15) * (ulong)uVar1;
  uVar2 = (uint)(uVar11 >> 0x10);
  lVar10 = CONCAT22(uVar1,uVar2);
  Ram00d6f2 = (int)(((ulong)uVar22 * ((uVar11 & 0xffff | (ulong)uVar2 << 0x10) / 10000 & 0xffff)) /
                   10000);
  iVar25 = Ram00d644;
  if (iVar25 < 0) {
    iVar25 = Ram00d644;
    uVar24 = -iVar25;
  }
  else {
    uVar24 = Ram00d644;
  }
  iVar25 = Ram00f652;
  uVar3 = iVar25 + 0x50;
  uVar5 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar5 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar3 & 0x3fff)) < uVar24) &&
     (uVar24 = Ram00fd2a, lVar10 = CONCAT22(uVar1,uVar2), (uVar24 & 1) != 0)) {
    iVar21 = Ram00d644;
    if (iVar21 < 1) {
      iVar25 = Ram00f652;
      uVar1 = iVar25 + 0x14;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar21 = Ram00d644;
      lVar10 = (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * (long)iVar21;
      iVar21 = (int)(lVar10 / 100);
      uVar2 = iVar25 + 10;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      piVar6 = (int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (iVar21 == *piVar6 || iVar21 < *piVar6) {
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iVar21 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      iVar25 = Ram00d65e;
      Ram00d65e = iVar25 + iVar21;
    }
    else {
      uVar1 = iVar25 + 6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      lVar10 = (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * (long)iVar21;
      iVar21 = (int)(lVar10 / 100);
      uVar2 = iVar25 + 8;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) <= iVar21) {
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iVar21 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      iVar25 = Ram00d65e;
      Ram00d65e = iVar25 + iVar21;
    }
  }
  iVar25 = Ram00d65e;
  if (iVar25 < 1) {
    iVar25 = Ram00d65e;
    iVar21 = Ram00d6f2;
    iVar25 = iVar25 + iVar21;
    if (-1 < iVar25) {
      iVar25 = 0;
    }
    Ram00d65e = iVar25;
  }
  else {
    iVar21 = Ram00d6f2;
    iVar25 = iVar25 - iVar21;
    if (iVar25 < 1) {
      iVar25 = 0;
    }
    Ram00d65e = iVar25;
  }
  iVar25 = Ram00d6be;
  if (iVar25 < 1) {
    iVar25 = Ram00d6be;
    iVar21 = Ram00d6aa;
    iVar25 = iVar25 + iVar21;
    if (-1 < iVar25) {
      iVar25 = 0;
    }
    Ram00d6a8 = iVar25;
  }
  else {
    iVar21 = Ram00d6aa;
    iVar25 = iVar25 - iVar21;
    if (iVar25 < 1) {
      iVar25 = 0;
    }
    Ram00d6a8 = iVar25;
  }
  egs52_update_near_d692_0db2b4((int)((ulong)lVar10 >> 0x10),uVar22);
  uVar1 = Ram00fd2a;
  if ((((uVar1 & 0x1000) == 0) && (uVar1 = Ram00fd2a, (uVar1 & 8) == 0)) &&
     ((uVar1 = Ram00fd2a, (uVar1 & 0x10) == 0 && (uVar1 = Ram00fd2a, (uVar1 & 0x20) == 0)))) {
    iVar25 = Ram00f6fe;
    uVar1 = iVar25 + 3;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) == 0) &&
        (bVar18 = UNK_00d647, bVar18 != 0)) &&
       ((bVar18 < 6 &&
        (((uVar1 = Ram00fd2a, (uVar1 & 0x2000) != 0 && (bVar18 = UNK_00d646, (bVar18 & 0x10) != 0))
         || ((uVar1 = Ram00fd2a, (uVar1 & 0x2000) == 0 && (bVar18 = UNK_00d646, (bVar18 & 1) != 0)))
         ))))) {
      iVar25 = Ram00f61e;
      uVar1 = iVar25 + 0x19;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) == 0) {
        egs52_update_near_d67c_0db768();
        egs52_update_near_d666_0dbf7e();
        egs52_update_near_d708_0dd674();
        uVar1 = Ram00fd2a;
        if ((uVar1 & 4) == 0) {
          iVar25 = Ram00f652;
          uVar1 = iVar25 + 5;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) == 0) {
            egs52_update_near_d690_0dc336();
          }
          else {
            egs52_update_near_d690_0dccd0();
          }
        }
        goto LAB_0de000;
      }
    }
  }
  UNK_00d704 = 0;
  Ram00d706 = 0;
  Ram00d666 = 0;
LAB_0de000:
  egs52_update_near_d433_0daa28();
  egs52_update_near_d6b0_0da902();
  return;
}


