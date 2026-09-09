#!/bin/bash
# Re-annotate one bank's Ghidra project with the pass-3 scripts (no re-analysis).
#   ghidra/run_annotate.sh 0|1
# Runs in the foreground; wrap in nohup and poll the pidfile for long runs (see README section 7).
set -e
cd "$(dirname "$0")/.."
BANK=${1:-1}
if [ "$BANK" = 0 ]; then PROJ=ghidra_projects/proj0b; NAME=EGS51A; else PROJ=ghidra_projects/proj1; NAME=EGS51B; fi
echo $$ > logs/annotate_bank$BANK.pid
exec /snap/ghidra/47/ghidra/support/analyzeHeadless "$PWD/$PROJ" $NAME \
  -process bank$BANK.bin -noanalysis -scriptPath "$PWD/ghidra" \
  -postScript PrepEntrySIC810 \
  -postScript MduAnnotate \
  -postScript FindMapDescriptors \
  -postScript KeilSwitchTables 1CED \
  -postScript LjmpTables \
  -postScript ApplySymbols "$PWD/reconstructed/symbols.txt" $BANK \
  > logs/annotate_bank$BANK.log 2>&1
