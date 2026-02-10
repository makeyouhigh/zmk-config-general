# Cornix

![Cornix thumbnail](/docs/images/cornix_thumbnail.webp)

This document covers the Cornix integration used in this repository.

## Reference Material

- Cornix project and docs: <https://cornixhub.com/>
- Cornix ZMK module source: <https://github.com/hitsmaxft/zmk-keyboard-cornix>
- ZMK docs: <https://zmk.dev/docs>

## Hardware Overview

- 48-key column-staggered split keyboard
- Wireless split operation via dedicated left/right boards
- Upstream module provides board definitions and dongle-adapter shields

## Layout

### Physical Layout

![Cornix layout](/docs/images/cornix_layout.svg)

### Keymap

![Cornix keymap](/docs/images/cornix_keymap.svg)

## Firmware Structure

Relevant paths in this repo:

- `config/cornix.keymap`
- `config/cornix.conf`
- `config/cornix_dongle_adapter.keymap`
- `build.yaml`
- `config/west.yml`

Module-provided hardware paths after `west update`:

- `modules/keyboards/cornix/boards/jzf/cornix/`
- `modules/keyboards/cornix/boards/shields/cornix_dongle_adapter/`
- `modules/keyboards/cornix/boards/shields/cornix_dongle_eyelash/`

## How to Use

### Build

1. Ensure dependencies are updated: `west update`.
2. Keep Cornix user behavior in `config/cornix.keymap` and `config/cornix.conf`.
3. Trigger CI or local build using targets in `build.yaml`.

Current active targets:

- `cornix_left`
- `cornix_right`
- `cornix_reset`
- `cornix_dongle`
- `cornix_left_w_dongle`

### Flashing

1. Put each target board into bootloader mode.
2. Flash matching firmware artifact (`*.uf2`) per target.
3. For split operation, flash both sides with matching build set.
4. If pairing state is stale, flash reset target and re-pair.

## Status

- Cornix support is active via upstream module integration.
- Build matrix entries exist in `build.yaml`.
- Dongle target uses `cornix_dongle_adapter` + `cornix_dongle_eyelash` with `dongle_display`.
