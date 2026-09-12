/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a476e; FLS offset 0x02476e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a47a0) */
/* WARNING: Removing unreachable block (ram,0x0a479a) */
/* WARNING: Removing unreachable block (ram,0x0a4790) */
/* WARNING: Removing unreachable block (ram,0x0a478c) */

undefined2 egs52_update_near_cacc_0a476e(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  
  __write_psw_bits(0x40,0x40);
  uVar3 = Ram00fd02;
  uVar1 = Ram00fd02;
  if ((uVar1 & 0x400) == 0x400) {
    __write_psw_bits(0x40,0);
  }
  else {
    uVar1 = Ram00fd02;
    Ram00fd02 = uVar1 | 0x400;
    uVar3 = egs52_call_096f56_09c462(2,param_1);
    uVar1 = iRam0904d4 + 2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar3;
    uVar3 = egs52_update_near_c31e_09c724(uVar3);
    Ram00cacc = uVar3;
    uVar1 = Ram00fd02;
    Ram00fd02 = uVar1 & 0xfbff;
  }
  uVar3 = Ram00cacc;
  return uVar3;
}


