#!/usr/bin/env bash
# Compatibility entry point: always decode and verify before importing.
set -euo pipefail
EGS52_ROOT="$(cd -- "$(dirname -- "$0")" && pwd)"
exec python3 "$EGS52_ROOT/tools/rebuild.py" "$@"
