---
applyTo: "docs/diagrams/*.drawio,docs/**/*.md"
description: "Use when creating or editing draw.io diagrams or docs that reference rendered diagram assets. Enforce export, visual QA, source fixes, and docs build flow before finalizing."
---

# Diagram Quality Gate

When a task creates or edits any draw.io source in docs/diagrams, run this loop before final response:

1. Export all diagrams to rendered assets with the docs build pipeline:
   - Run: make -C docs diagrams
   - Optional format selection: DRAWIO_FORMATS="svg png" make -C docs diagrams
2. Inspect rendered output with image inspection tools.
3. Fix the draw.io source if any issue is found.
4. Re-export and re-inspect.
5. Repeat until all checks pass.

## Required checks

- No connectors crossing through text labels.
- No connector endpoints terminating inside unrelated blocks.
- No overlapping labels.
- No clipped text at page edges.
- Consistent typography and readable font size.
- Visual hierarchy is clear: titles, section blocks, and callouts are distinguishable.
- Diagram filename stem and referenced rendered filename stem match.
- At least one rendered sibling exists for each changed draw.io file (for example .png, .svg, .jpg, .jpeg, .webp, or .pdf).

## Documentation checks

For any markdown file that references a diagram:

- Reference a rendered diagram asset for readers (for example PNG/SVG/JPEG/PDF).
- Keep the source drawio file in the same folder.
- Ensure docs mention the build command used to generate PNGs.
- Ensure docs build flow is clear when producing HTML and PDF outputs.

## Failure policy

If export cannot run in the current environment (for example Docker permission denied), do not claim visual QA passed.
Instead:

- State exactly what blocked export.
- Keep changes limited to source/documentation that can be validated.
- Leave a clear follow-up action: run make -C docs diagrams in an environment with draw.io CLI or Docker access.
