#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

if [[ ! -f .githooks/pre-commit ]]; then
  echo "Missing .githooks/pre-commit" >&2
  exit 1
fi

chmod +x .githooks/pre-commit

git config core.hooksPath .githooks

echo "Installed git hooks for this repository."
echo "core.hooksPath=$(git config --get core.hooksPath)"
