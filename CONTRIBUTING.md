# Contributing

Thanks for improving this ZMK config repository.

This file defines how to propose changes. Behavior expectations are defined in `CODE_OF_CONDUCT.md`.

## Scope

Contributions are welcome for:

- Firmware config: `config/*.keymap`, `config/*.conf`
- Shield and board support: `boards/shields/*`
- Build/release setup: `build.yaml`, `.github/workflows/*`
- Documentation: `README.md`, `docs/*`

## Workflow

1. Fork the repository.
2. Create a focused branch for one change set.
3. Make the smallest practical change that solves the problem.
4. Validate your change.
5. Open a pull request with clear context.

## Pull Request Expectations

Include these points in your PR description:

- What changed
- Why it changed
- How it was validated (CI run, local build, screenshots, or reasoning)
- Any known limitations or follow-up work

Keep unrelated edits out of the same PR.

## Validation Guidance

For firmware/config updates:

- Confirm shield/board names are valid.
- Confirm changed targets are represented correctly in `build.yaml`.
- If CI targets are affected, ensure the workflow can build them.

For documentation updates:

- Follow `docs/docs_rules.md`.
- Keep file paths and artifact names exact.
- Keep docs aligned with the current repository state.

## Style Guidance

- Prefer clear and concise technical language.
- Keep commit scopes small and reviewable.
- Avoid large refactors in feature/fix PRs unless explicitly discussed first.

## Reporting Issues

When opening an issue, include:

- Keyboard/board/shield names
- Expected behavior
- Actual behavior
- Reproduction steps
- Relevant commit hash or artifact name when available

Clear reports reduce triage time and speed up fixes.
