#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/_build"
HTML_DIR="${BUILD_DIR}/html"
PDF_DIR="${BUILD_DIR}/pdf"
MODE="${1:-all}"

if ! command -v pandoc >/dev/null 2>&1; then
  echo "pandoc is required to build docs." >&2
  exit 1
fi

mkdir -p "${HTML_DIR}" "${PDF_DIR}"

build_html() {
  while IFS= read -r md; do
    base="$(basename "${md}" .md)"
    out="${HTML_DIR}/${base}.html"
    pandoc -s "${md}" -o "${out}"
    echo "Built ${out}"
  done < <(find "${SCRIPT_DIR}" -maxdepth 1 -type f -name '*.md' -print)
}

build_pdf_from_html() {
  if command -v weasyprint >/dev/null 2>&1; then
    for html in "${HTML_DIR}"/*.html; do
      [[ -e "${html}" ]] || continue
      base="$(basename "${html}" .html)"
      out="${PDF_DIR}/${base}.pdf"
      weasyprint "${html}" "${out}"
      echo "Built ${out}"
    done
    return
  fi

  if command -v wkhtmltopdf >/dev/null 2>&1; then
    for html in "${HTML_DIR}"/*.html; do
      [[ -e "${html}" ]] || continue
      base="$(basename "${html}" .html)"
      out="${PDF_DIR}/${base}.pdf"
      wkhtmltopdf "${html}" "${out}"
      echo "Built ${out}"
    done
    return
  fi

  if command -v chromium >/dev/null 2>&1; then
    for html in "${HTML_DIR}"/*.html; do
      [[ -e "${html}" ]] || continue
      base="$(basename "${html}" .html)"
      out="${PDF_DIR}/${base}.pdf"
      chromium --headless --disable-gpu --print-to-pdf="${out}" "file://${html}"
      echo "Built ${out}"
    done
    return
  fi

  echo "No HTML->PDF converter found. Install one of: weasyprint, wkhtmltopdf, chromium." >&2
  exit 1
}

case "${MODE}" in
  html)
    build_html
    ;;
  pdf)
    build_html
    build_pdf_from_html
    ;;
  all)
    build_html
    build_pdf_from_html
    ;;
  *)
    echo "Usage: $0 [html|pdf|all]" >&2
    exit 1
    ;;
esac
