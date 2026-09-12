/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1e5c; FLS offset 0x051e5c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1e9a) */
/* WARNING: Removing unreachable block (ram,0x0d1e94) */
/* WARNING: Removing unreachable block (ram,0x0d1e88) */
/* WARNING: Removing unreachable block (ram,0x0d1e84) */
/* WARNING: Removing unreachable block (ram,0x0d1e7c) */
/* WARNING: Removing unreachable block (ram,0x0d1e74) */
/* WARNING: Removing unreachable block (ram,0x0d1e66) */
/* WARNING: Removing unreachable block (ram,0x0d1e5e) */

void egs52_update_near_fd4e_0d1e5c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = Ram00fd4e;
  if ((uVar1 & 1) != 0) {
    cVar5 = UNK_00d577;
    if (cVar5 == '\x01') {
      iVar6 = egs52_compute_from_near_f638_0d1c5e();
      iVar3 = Ram00d41c;
      if (iVar3 <= iVar6) {
        uVar1 = Ram00fd4e;
        Ram00fd4e = uVar1 | 2;
      }
      cVar5 = UNK_00d579;
      iVar3 = Ram00f63a;
      uVar1 = iVar3 + 2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar7 = egs52_update_near_d41a_0d6eb0
                        (cVar5 + -1,*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
      iVar3 = Ram00d41c;
      iVar6 = Ram00d41c;
      if ((iVar7 != iVar6 && iVar3 <= iVar7) || (bVar4 = UNK_00d566, 2 < bVar4)) {
        uVar1 = Ram00fd4e;
        Ram00fd4e = uVar1 & 0xfffe;
      }
    }
    else {
      uVar1 = Ram00fd4e;
      Ram00fd4e = uVar1 & 0xfffe;
    }
  }
  return;
}


