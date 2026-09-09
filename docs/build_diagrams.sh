#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DIAGRAM_DIR="${SCRIPT_DIR}/diagrams"
FORMATS_RAW="${DRAWIO_FORMATS:-png}"

# shellcheck disable=SC2206
FORMATS=( ${FORMATS_RAW//,/ } )

if [[ ${#FORMATS[@]} -eq 0 ]]; then
  echo "DRAWIO_FORMATS resolved to an empty list." >&2
  exit 1
fi

if [[ ! -d "${DIAGRAM_DIR}" ]]; then
  echo "No diagrams directory found at ${DIAGRAM_DIR}" >&2
  exit 1
fi

run_with_local_cli() {
  local cli="$1"
  echo "Using local CLI: ${cli}"
  while IFS= read -r -d '' src; do
    for fmt in "${FORMATS[@]}"; do
      local out="${src%.drawio}.${fmt}"
      "${cli}" --export --format "${fmt}" --output "${out}" "${src}"
      echo "Exported ${out}"
    done
  done < <(find "${DIAGRAM_DIR}" -type f -name '*.drawio' -print0)
}

run_with_docker() {
  local image="${DRAWIO_DOCKER_IMAGE:-rlespinasse/drawio-desktop-headless:latest}"
  echo "Using Docker image: ${image}"
  docker run --rm \
    -u "$(id -u):$(id -g)" \
    -v "${SCRIPT_DIR}:/workspace" \
    -w /workspace \
    -e DRAWIO_FORMATS="${FORMATS_RAW}" \
    "${image}" \
    bash -lc '
      set -euo pipefail
      shopt -s nullglob
      files=(diagrams/*.drawio)
      if [[ ${#files[@]} -eq 0 ]]; then
        echo "No .drawio files found in docs/diagrams" >&2
        exit 1
      fi
      formats_raw="${DRAWIO_FORMATS:-png}"
      # shellcheck disable=SC2206
      formats=( ${formats_raw//,/ } )
      for src in "${files[@]}"; do
        for fmt in "${formats[@]}"; do
          out="${src%.drawio}.${fmt}"
          drawio --export --format "$fmt" --output "$out" "$src"
          echo "Exported $out"
        done
      done
    '
}

if command -v drawio >/dev/null 2>&1; then
  run_with_local_cli drawio
  exit 0
fi

if command -v draw.io >/dev/null 2>&1; then
  run_with_local_cli draw.io
  exit 0
fi

if command -v docker >/dev/null 2>&1; then
  run_with_docker
  exit 0
fi

echo "No draw.io CLI found and Docker is unavailable." >&2
echo "Install draw.io CLI or Docker, then run: make -C docs diagrams" >&2
exit 1
