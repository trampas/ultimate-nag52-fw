/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da9b8; FLS offset 0x05a9b8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0daa22) */
/* WARNING: Removing unreachable block (ram,0x0daa1c) */
/* WARNING: Removing unreachable block (ram,0x0daa18) */
/* WARNING: Removing unreachable block (ram,0x0daa12) */
/* WARNING: Removing unreachable block (ram,0x0daa0e) */
/* WARNING: Removing unreachable block (ram,0x0daa08) */
/* WARNING: Removing unreachable block (ram,0x0daa04) */
/* WARNING: Removing unreachable block (ram,0x0da9fe) */
/* WARNING: Removing unreachable block (ram,0x0da9fa) */
/* WARNING: Removing unreachable block (ram,0x0da9f4) */
/* WARNING: Removing unreachable block (ram,0x0da9f0) */
/* WARNING: Removing unreachable block (ram,0x0da9ea) */
/* WARNING: Removing unreachable block (ram,0x0da9e6) */
/* WARNING: Removing unreachable block (ram,0x0da9e0) */
/* WARNING: Removing unreachable block (ram,0x0da9dc) */
/* WARNING: Removing unreachable block (ram,0x0da9d6) */
/* WARNING: Removing unreachable block (ram,0x0da9d2) */
/* WARNING: Removing unreachable block (ram,0x0da9cc) */
/* WARNING: Removing unreachable block (ram,0x0da9c8) */
/* WARNING: Removing unreachable block (ram,0x0da9c2) */
/* WARNING: Removing unreachable block (ram,0x0da9be) */
/* WARNING: Removing unreachable block (ram,0x0da9b8) */

void egs52_update_near_d67a_0da9b8(void)

{
  int iVar1;
  char cVar2;
  
  iVar1 = Ram00d67a;
  if (iVar1 != 0) {
    iVar1 = Ram00d67a;
    Ram00d67a = iVar1 + -1;
  }
  iVar1 = Ram00d6ee;
  if (iVar1 != 0) {
    iVar1 = Ram00d6ee;
    Ram00d6ee = iVar1 + -1;
  }
  iVar1 = Ram00d684;
  if (iVar1 != 0) {
    iVar1 = Ram00d684;
    Ram00d684 = iVar1 + -1;
  }
  iVar1 = Ram00d6ec;
  if (iVar1 != 0) {
    iVar1 = Ram00d6ec;
    Ram00d6ec = iVar1 + -1;
  }
  iVar1 = Ram00d65c;
  if (iVar1 != 0) {
    iVar1 = Ram00d65c;
    Ram00d65c = iVar1 + -1;
  }
  iVar1 = Ram00d6a4;
  if (iVar1 != 0) {
    iVar1 = Ram00d6a4;
    Ram00d6a4 = iVar1 + -1;
  }
  iVar1 = Ram00d692;
  if (iVar1 != 0) {
    iVar1 = Ram00d692;
    Ram00d692 = iVar1 + -1;
  }
  iVar1 = Ram00d694;
  if (iVar1 != 0) {
    iVar1 = Ram00d694;
    Ram00d694 = iVar1 + -1;
  }
  cVar2 = UNK_00d697;
  if (cVar2 != '\0') {
    cVar2 = UNK_00d697;
    UNK_00d697 = cVar2 + -1;
  }
  iVar1 = Ram00d6a0;
  if (iVar1 != 0) {
    iVar1 = Ram00d6a0;
    Ram00d6a0 = iVar1 + -1;
  }
  cVar2 = UNK_00d6f1;
  if (cVar2 != '\0') {
    cVar2 = UNK_00d6f1;
    UNK_00d6f1 = cVar2 + -1;
  }
  return;
}


