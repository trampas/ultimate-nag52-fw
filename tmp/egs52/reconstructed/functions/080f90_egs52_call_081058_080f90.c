/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x080f90; FLS offset 0x000f90.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x080ffa) */
/* WARNING: Removing unreachable block (ram,0x080ff6) */
/* WARNING: Removing unreachable block (ram,0x080fe8) */
/* WARNING: Removing unreachable block (ram,0x080fe4) */
/* WARNING: Removing unreachable block (ram,0x080fca) */
/* WARNING: Removing unreachable block (ram,0x080fc6) */
/* WARNING: Removing unreachable block (ram,0x080fb8) */
/* WARNING: Removing unreachable block (ram,0x080fb4) */

byte egs52_call_081058_080f90(undefined2 param_1,undefined2 param_2)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = egs52_transform_far_memory_081058(0x3fe8,8,0xf224,8);
  bVar2 = cVar1 != '\x01';
  if (iRam090040 + 1U == (uint)(iRam09003e != -1) && iRam09003e == -1) {
    bVar2 = bVar2 | 2;
  }
  else {
    cVar1 = egs52_transform_far_memory_081058(iRam09003e,iRam090040,0xf234,0x10);
    if (cVar1 != '\x01') {
      bVar2 = bVar2 | 2;
    }
  }
  if (iRam090064 + 1U == (uint)(iRam090062 != -1) && iRam090062 == -1) {
    bVar2 = bVar2 | 4;
  }
  else {
    cVar1 = egs52_transform_far_memory_081058(iRam090062,iRam090064,0xf244,0x10);
    if (cVar1 != '\x01') {
      bVar2 = bVar2 | 4;
    }
  }
  if (((bVar2 & 3) == 0) &&
     (cVar1 = egs52_register_arithmetic_0810cc(0xf224,8,param_1), cVar1 != '\x01')) {
    bVar2 = bVar2 | 8;
  }
  if (((bVar2 & 6) == 0) &&
     (cVar1 = egs52_register_arithmetic_0810cc(0xf234,0x10,param_2), cVar1 != '\x01')) {
    bVar2 = bVar2 | 0x10;
  }
  if (bVar2 == 0) {
    bVar2 = 0x20;
  }
  return bVar2;
}


