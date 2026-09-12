/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a41b6; FLS offset 0x0241b6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a420a) */
/* WARNING: Removing unreachable block (ram,0x0a4216) */
/* WARNING: Removing unreachable block (ram,0x0a421c) */
/* WARNING: Removing unreachable block (ram,0x0a4210) */
/* WARNING: Removing unreachable block (ram,0x0a4204) */
/* WARNING: Removing unreachable block (ram,0x0a422e) */
/* WARNING: Removing unreachable block (ram,0x0a423a) */
/* WARNING: Removing unreachable block (ram,0x0a4240) */
/* WARNING: Removing unreachable block (ram,0x0a4234) */
/* WARNING: Removing unreachable block (ram,0x0a4228) */
/* WARNING: Removing unreachable block (ram,0x0a424c) */
/* WARNING: Removing unreachable block (ram,0x0a4258) */
/* WARNING: Removing unreachable block (ram,0x0a425e) */
/* WARNING: Removing unreachable block (ram,0x0a4252) */
/* WARNING: Removing unreachable block (ram,0x0a4246) */
/* WARNING: Removing unreachable block (ram,0x0a4222) */
/* WARNING: Removing unreachable block (ram,0x0a41fe) */
/* WARNING: Removing unreachable block (ram,0x0a41fa) */
/* WARNING: Removing unreachable block (ram,0x0a41f6) */

void egs52_call_096f56_0a41b6(void)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  
  uVar2 = egs52_update_near_fd00_096f56(0,0);
  cVar1 = egs52_match_fault_status_mask(0x14,1);
  if (((cVar1 == '\0') && (cVar1 = egs52_match_fault_status_mask(0x4a,1), cVar1 == '\0')) &&
     (cVar1 = egs52_match_fault_status_mask(0x4b,1), cVar1 == '\0')) {
    uVar4 = 0x24;
    if ((((uRam0904dc & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904dc & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904dc & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar4 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uRam0904dc & 0x3fff));
  }
  else {
    uVar4 = 0xff;
  }
  if (uVar2 < uRam0909c0) {
    uVar3 = uRam0909c8;
    if ((uRam0909c4 <= uVar4) && (uVar3 = uRam0909cc, uVar4 <= uRam0909c6)) {
      uVar3 = uRam0909ca;
    }
  }
  else if (uRam0909c2 < uVar2) {
    uVar3 = uRam0909d4;
    if ((uRam0909c4 <= uVar4) && (uVar3 = uRam0909d8, uVar4 <= uRam0909c6)) {
      uVar3 = uRam0909d6;
    }
  }
  else {
    uVar3 = uRam0909ce;
    if ((uRam0909c4 <= uVar4) && (uVar3 = uRam0909d2, uVar4 <= uRam0909c6)) {
      uVar3 = uRam0909d0;
    }
  }
  egs52_update_near_c17a_097f16(uVar3);
  return;
}


