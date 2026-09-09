# Diagram Workflow

- Source files: docs/diagrams/*.drawio
- Rendered files: docs/diagrams/*.{png,svg,jpg,jpeg,webp,pdf}
- Build command: make -C docs diagrams

Format selection example:

```sh
DRAWIO_FORMATS="svg png" make -C docs diagrams
```

Quality gate for every diagram update:

1. Export at least one rendered format.
2. Inspect PNG for connector and typography problems.
3. Fix draw.io source.
4. Re-export.
5. Re-check until clean.

Do not merge diagram edits without regenerated rendered output unless export is blocked by environment constraints.
