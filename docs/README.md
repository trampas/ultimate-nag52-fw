# Docs Build Notes

This docs folder uses a draw.io-first diagram workflow and supports HTML/PDF publication.

## Layout

- Source diagrams: docs/diagrams/*.drawio
- Exported renders: docs/diagrams/*.{png,svg,jpg,jpeg,webp,pdf}

## Build diagrams

Run:

```sh
make -C docs diagrams
```

Choose one or more output formats:

```sh
DRAWIO_FORMATS="svg png" make -C docs diagrams
```

Note: when using the Docker fallback, your user must have access to the Docker daemon socket.

The build script tries, in order:

1. local draw.io CLI (drawio)
2. local draw.io CLI (draw.io)
3. Docker image (default: rlespinasse/drawio-desktop-headless:latest)

## Build documents (HTML and PDF)

Build HTML:

```sh
make -C docs docs-html
```

Build PDF from generated HTML:

```sh
make -C docs docs-pdf
```

Run full docs pipeline:

```sh
make -C docs docs-all
```

The HTML/PDF script uses pandoc and then one of: weasyprint, wkhtmltopdf, or chromium.

Override Docker image if desired:

```sh
DRAWIO_DOCKER_IMAGE=<image> make -C docs diagrams
```

## Editing workflow

1. Edit the .drawio source in docs/diagrams.
2. Run make -C docs diagrams.
3. Commit both .drawio and .png files.
4. Reference the .png in markdown and keep source nearby for iteration.

## Commit guard (diagram parity)

A repository pre-commit hook blocks commits when a staged draw.io file does not have at least one matching staged rendered sibling.

Install it once per clone:

```sh
scripts/install_git_hooks.sh
```

What it enforces:

- If docs/diagrams/foo.drawio is staged, stage at least one rendered sibling such as docs/diagrams/foo.svg or docs/diagrams/foo.png.
- If a drawio is staged for deletion, any tracked rendered siblings of the same stem must also be staged for deletion.
- Allowed render extensions default to: png svg jpg jpeg webp pdf

Hook location:

- .githooks/pre-commit

## AI quality loop

Workspace instruction file:

- .github/instructions/diagram-quality.instructions.md

Expected loop for diagram edits:

1. Export rendered diagrams with make -C docs diagrams.
2. Inspect rendered diagrams for connector crossings, connector endpoint mistakes, label overlap, clipped text, and typography issues.
3. Fix the .drawio source.
4. Re-export and re-inspect until clean.

If export is blocked by environment permissions, document the blocker and do not claim visual QA passed.

## Control change notes

- [2026-09-09 kickdown changes and validation](kickdown_changes_20260909.md)
- [Transmission and vehicle simulation feasibility](simulation_feasibility.md)

## EGS51 reverse engineering

Index and artifact list: [722.6 / EGS51 / NAG52 documentation index](7226_egs51_nag52_developer_guide.md).

OEM behavior and the pressure control chain are in the
[primer](7226_egs51_primer.md); NAG52 comparison is in the
[behavior and parity guide](nag52_behavior_and_parity.md).
