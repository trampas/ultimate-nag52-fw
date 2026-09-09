#!/bin/bash
cd ~/egs51_disasm
exec /snap/ghidra/47/ghidra/support/analyzeHeadless ~/egs51_disasm/proj0b EGS51A \
  -process bank0.bin -noanalysis -scriptPath ~/egs51_disasm/scripts \
  -postScript MakeFuncs -postScript DumpAll > ~/egs51_disasm/out/bank0_funcs.log 2>&1
