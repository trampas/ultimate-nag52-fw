#!/bin/bash
# build.sh <variant> <srcroot>   variant: old|new
set -e
V=$1; SRC=$2; FW=$HOME/projects/ultimate-nag52-fw
HERE=$(cd $(dirname $0); pwd)
DEF=""; [ "$V" = "new" ] && DEF="-DNEW_ALGO"
INC="-I$HERE -I$HERE/stubs -I$SRC/src -I$SRC -I$FW/src -I$FW -I$FW/lib/core"
# NOTE: maps.cpp MUST come from $SRC, not $FW - it holds the shift point and shift time
# maps, so sourcing it from the repo makes every map A/B silently compare a build against
# itself. Only genuinely variant-independent code belongs in COMMON.
COMMON="$FW/lib/core/tcu_maths.cpp $FW/lib/core/lookupmap.cpp $FW/lib/core/lookuptable.cpp $FW/lib/core/lookupheader.cpp $FW/src/common_structs_ops.cpp $FW/src/stored_map.cpp $FW/src/stored_data.cpp $SRC/src/maps.cpp"
VAR="$SRC/src/shifting_algo/s_algo.cpp $SRC/src/shifting_algo/shift_crossover.cpp $SRC/src/shifting_algo/shift_release.cpp $SRC/src/shifting_algo/shifting_algo_helpers.cpp $SRC/src/pressure_manager.cpp $SRC/src/adaptation/shift_adaptation.cpp $SRC/src/adaptation/quality_adapt.cpp $SRC/src/models/clutch_speed.cpp $SRC/src/models/input_torque.cpp"
g++ -std=gnu++17 -O1 -g -w -fno-strict-aliasing $DEF -include $HERE/stubs/preinclude.h $INC $HERE/harness.cpp $COMMON $VAR -o $HERE/sim_$V
echo built sim_$V
