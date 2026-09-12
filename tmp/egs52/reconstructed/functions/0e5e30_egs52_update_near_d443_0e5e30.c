/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e5e30; FLS offset 0x065e30.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e5e76) */
/* WARNING: Removing unreachable block (ram,0x0e5e72) */
/* WARNING: Removing unreachable block (ram,0x0e5e62) */
/* WARNING: Removing unreachable block (ram,0x0e5e5e) */
/* WARNING: Removing unreachable block (ram,0x0e5e5a) */
/* WARNING: Removing unreachable block (ram,0x0e5eae) */
/* WARNING: Removing unreachable block (ram,0x0e5ea4) */
/* WARNING: Removing unreachable block (ram,0x0e5e8e) */
/* WARNING: Removing unreachable block (ram,0x0e5e68) */
/* WARNING: Removing unreachable block (ram,0x0e5e80) */
/* WARNING: Removing unreachable block (ram,0x0e5e7a) */

void egs52_update_near_d443_0e5e30(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  
  cVar5 = egs52_match_fault_status_mask(0x25,5);
  if (((cVar5 == '\x01') || (cVar5 = egs52_match_fault_status_mask(0x27,5), cVar5 == '\x01')) ||
     (cVar5 = egs52_match_fault_status_mask(0x52,5), cVar5 == '\x01')) {
    iVar3 = Ram00f67a;
    uVar1 = iVar3 + 0xe;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d443 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    return;
  }
  cVar5 = UNK_00d231;
  if (cVar5 == -1) {
    iVar3 = Ram00f67a;
    uVar1 = iVar3 + 0xe;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d443 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    return;
  }
  bVar4 = UNK_00d231;
  if (0xa3 < bVar4) {
    UNK_00d443 = 0xfe;
    return;
  }
  bVar4 = UNK_00d231;
  UNK_00d443 = (char)(((ulong)bVar4 * 200) / 0x80);
  return;
}


