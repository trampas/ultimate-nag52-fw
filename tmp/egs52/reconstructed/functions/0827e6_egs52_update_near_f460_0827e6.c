/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0827e6; FLS offset 0x0027e6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08280e) */
/* WARNING: Removing unreachable block (ram,0x08280a) */
/* WARNING: Removing unreachable block (ram,0x082800) */
/* WARNING: Removing unreachable block (ram,0x0827fa) */
/* WARNING: Removing unreachable block (ram,0x0827f2) */
/* WARNING: Removing unreachable block (ram,0x0828f8) */
/* WARNING: Removing unreachable block (ram,0x0828f4) */
/* WARNING: Removing unreachable block (ram,0x0828ec) */
/* WARNING: Removing unreachable block (ram,0x0828e8) */
/* WARNING: Removing unreachable block (ram,0x0828a4) */
/* WARNING: Removing unreachable block (ram,0x08289e) */
/* WARNING: Removing unreachable block (ram,0x08289a) */
/* WARNING: Removing unreachable block (ram,0x082898) */
/* WARNING: Removing unreachable block (ram,0x082894) */
/* WARNING: Removing unreachable block (ram,0x082890) */
/* WARNING: Removing unreachable block (ram,0x0828c6) */
/* WARNING: Removing unreachable block (ram,0x0828c0) */
/* WARNING: Removing unreachable block (ram,0x0828bc) */
/* WARNING: Removing unreachable block (ram,0x0828b8) */
/* WARNING: Removing unreachable block (ram,0x0828b4) */
/* WARNING: Removing unreachable block (ram,0x0828b0) */
/* WARNING: Removing unreachable block (ram,0x0828e4) */
/* WARNING: Removing unreachable block (ram,0x0828de) */
/* WARNING: Removing unreachable block (ram,0x0828da) */
/* WARNING: Removing unreachable block (ram,0x0828d6) */
/* WARNING: Removing unreachable block (ram,0x0828d2) */
/* WARNING: Removing unreachable block (ram,0x0828ce) */
/* WARNING: Removing unreachable block (ram,0x082884) */
/* WARNING: Removing unreachable block (ram,0x082880) */
/* WARNING: Removing unreachable block (ram,0x08287c) */
/* WARNING: Removing unreachable block (ram,0x082856) */
/* WARNING: Removing unreachable block (ram,0x082852) */
/* WARNING: Removing unreachable block (ram,0x08284c) */
/* WARNING: Removing unreachable block (ram,0x082844) */
/* WARNING: Removing unreachable block (ram,0x082876) */
/* WARNING: Removing unreachable block (ram,0x082870) */
/* WARNING: Removing unreachable block (ram,0x082868) */
/* WARNING: Removing unreachable block (ram,0x082860) */
/* WARNING: Removing unreachable block (ram,0x082832) */
/* WARNING: Removing unreachable block (ram,0x08282a) */
/* WARNING: Removing unreachable block (ram,0x082820) */
/* WARNING: Removing unreachable block (ram,0x08281a) */
/* WARNING: Removing unreachable block (ram,0x0827f6) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f460 : 0x0828b4 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f460_0827e6(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram00fdea;
  if ((uVar1 & 0x2000) == 0) {
    uVar1 = Ram00fdea;
    if ((((uVar1 & 0x4000) == 0) && (bRam00f57c + 1 <= uRam00f572)) ||
       ((uVar1 = Ram00fdea, (uVar1 & 0x4000) != 0 && (bRam00f57c + 10 < uRam00f572)))) {
      uVar1 = Ram00fdec;
      if ((uVar1 & 0x20) != 0) {
        uVar1 = Ram00fdec;
        if ((uVar1 & 0x100) == 0) {
          bRam00f57c = 0x19;
          uRam00f574 = 0x1a;
          uRam00f576 = 0x17;
          uRam00f578 = 5;
        }
        else {
          bRam00f57c = 9;
          uRam00f574 = 0x1a;
          uRam00f576 = 7;
          uRam00f578 = 0;
        }
      }
      uVar1 = Ram00ff6e;
      Ram00ff6e = uVar1 | 0x40;
      Ram00feb4 = uRam00f57a;
      uVar1 = 0x24;
      if ((((uRam00f460 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f460 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f460 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f460 & 0x3fff)) & 0xc0) == 0) {
        uVar1 = Ram00fdea;
        if ((uVar1 & 0x200) == 0) {
          uRam00f57e = 0xc;
          uVar1 = 0x24;
          if ((((uRam00f460 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f460 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f460 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          bRam00f57d = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f460 & 0x3fff));
          Ram00feb0 = (uint)bRam00f57d;
          uRam00f460 = uRam00f460 + 4;
        }
        else {
          uRam00f57e = 0xb;
          uVar1 = 0x24;
          if ((((uRam00f460 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f460 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f460 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          bRam00f57d = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f460 & 0x3fff));
          Ram00feb0 = (uint)bRam00f57d;
          uRam00f460 = uRam00f460 + 3;
        }
      }
      else {
        uRam00f57e = 9;
        uVar1 = 0x24;
        if ((((uRam00f460 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f460 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam00f460 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = uRam00f460 & 0x3fff;
        uRam00f460 = uRam00f460 + 1;
        bRam00f57d = *(byte *)((uint3)uVar1 << 0xe | (uint3)uVar2);
        Ram00feb0 = (uint)bRam00f57d;
      }
      bRam00f584 = bRam00f57d;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xffbf;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xbfff;
      uRam00f5b2 = uRam00f574;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 | 0x800;
    }
    return;
  }
  Ram00feb4 = 1;
  uRam00f460 = 0xf46d;
  uRam00f464 = uRam00f466;
  uRam00f57e = 8;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xdfff;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 0x4000;
  uVar1 = Ram00ff6e;
  Ram00ff6e = uVar1 | 0x40;
  uRam00f5b2 = uRam00f574;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 0x800;
  return;
}


