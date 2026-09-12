/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a28ce; FLS offset 0x0228ce.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined1 egs52_update_near_fd6c_0a28ce(undefined1 param_1,undefined2 param_2)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = Ram00fd6c;
    Ram00fd6c = uVar1 & 0xfffd;
    uVar2 = egs52_update_near_fd6c_0a2b70(param_1,0);
    uVar2 = egs52_transform_memory_0a2c70(uVar2,param_2);
    uVar1 = Ram00fd6c;
    if ((uVar1 & 2) == 0) {
      return uVar2;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return 0xfa;
}


