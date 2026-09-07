#!/bin/bash
# Does a settings block written by an older firmware still load correctly?
#
# Appending a setting must be safe across a firmware upgrade, or every new field
# costs the user everything they had tuned in that block. Compiles the real
# EEPROM::read_subsystem_settings for the host against a fake flash and checks
# the four cases that matter: upgrade, steady state, first boot, downgrade.
#
# Usage: tmp/settings_migration_check/check.sh
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
g++ -std=gnu++17 -w -include "$HERE/stubs/preinclude.h" \
    -I"$HERE/stubs" -I"$HERE/../shift_replay/stubs" \
    -I"$HERE/../../src" -I"$HERE/../../lib/core" -I"$HERE/../.." \
    "$HERE/main.cpp" -o "$HERE/mig"
"$HERE/mig"
