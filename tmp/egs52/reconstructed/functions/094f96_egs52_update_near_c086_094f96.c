/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094f96; FLS offset 0x014f96.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09500a) */
/* WARNING: Removing unreachable block (ram,0x095002) */
/* WARNING: Removing unreachable block (ram,0x094ff8) */
/* WARNING: Removing unreachable block (ram,0x094ff4) */
/* WARNING: Removing unreachable block (ram,0x0950a2) */
/* WARNING: Removing unreachable block (ram,0x09509e) */
/* WARNING: Removing unreachable block (ram,0x095096) */
/* WARNING: Removing unreachable block (ram,0x09508c) */
/* WARNING: Removing unreachable block (ram,0x095088) */
/* WARNING: Removing unreachable block (ram,0x095072) */
/* WARNING: Removing unreachable block (ram,0x09505e) */
/* WARNING: Removing unreachable block (ram,0x094fe2) */
/* WARNING: Removing unreachable block (ram,0x094f96) */
/* WARNING: Removing unreachable block (ram,0x09505a) */

undefined2 egs52_update_near_c086_094f96(void)

{
  int iVar1;
  char cVar2;
  uchar uVar3;
  uint uVar4;
  
  uVar4 = Ram00c086;
  if (((uVar4 & 0x800) != 0) || (cVar2 = egs52_match_fault_status_mask(0x30,1), cVar2 != '\0')) {
    return 0;
  }
  cVar2 = egs52_match_fault_status_mask(0x14,1);
  if ((((cVar2 == '\0') && (cVar2 = egs52_match_fault_status_mask(0x4a,1), cVar2 == '\0')) &&
      (cVar2 = egs52_match_fault_status_mask(0x4b,1), cVar2 == '\0')) &&
     (uVar4 = Ram00c086, (uVar4 & 0x400) == 0)) {
    uVar3 = egs52_get_status_c31b();
    if (uVar3 != '\x01') {
      return 0;
    }
    uVar4 = 0x24;
    if ((((uRam0904de & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\b') {
      uVar4 = 0x24;
      if ((((uRam0904de & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\x06') {
        uVar4 = 0x24;
        if ((((uRam0904de & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if (((*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != -1) &&
            (cVar2 = egs52_match_fault_status_mask(0x11,1), cVar2 != '\x01')) &&
           ((cVar2 = egs52_match_fault_status_mask(0x12,1), cVar2 != '\x01' &&
            (cVar2 = egs52_match_fault_status_mask(0x4c,1), cVar2 != '\x01')))) {
          uVar4 = egs52_compute_from_near_c06e_094d98();
          if ((uVar4 & 0x80) == 0) {
            return 0;
          }
          uVar4 = egs52_compute_from_near_f61e_0964d2();
          if ((uVar4 & 0x11) == 0) {
            return 0;
          }
        }
      }
    }
    return 1;
  }
  uVar4 = Ram00fdf2;
  iVar1 = Ram00fdf4;
  if (iVar1 == 0 && uVar4 < 500) {
    return 0;
  }
  uVar4 = Ram00c086;
  Ram00c086 = uVar4 & 0xfbff;
  uVar3 = egs52_get_status_c31b();
  if ((uVar3 != '\0') && (uVar3 = egs52_get_status_c31b(), uVar3 != '\x02')) {
    uVar4 = 0x24;
    if (((uRam0904de & 0xc000) != 0) &&
       ((uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000 &&
        (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)))) {
      uVar4 = 3;
    }
    if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\b') {
      uVar4 = 0x24;
      if ((((uRam0904de & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\x06') {
        return 0;
      }
    }
    uVar4 = 0x24;
    if ((((uRam0904de & 0xc000) != 0) && (uVar4 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (((*(char *)((uint3)uVar4 << 0xe | (uint3)(uRam0904de & 0x3fff)) != -1) &&
        (cVar2 = egs52_match_fault_status_mask(0x11,5), cVar2 == '\0')) &&
       ((cVar2 = egs52_match_fault_status_mask(0x12,5), cVar2 == '\0' &&
        (cVar2 = egs52_match_fault_status_mask(0x4c,5), cVar2 == '\0')))) {
      return 1;
    }
  }
  return 0;
}


