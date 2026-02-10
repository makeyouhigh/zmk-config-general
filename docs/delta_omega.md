# Delta Omega

![Delta Omega](/docs/images/delta_omega_header.png)

This document covers Delta Omega support as integrated in this repository.

## Reference Material

- Delta Omega hardware: <https://github.com/unspecworks/delta-omega>
- Delta Omega ZMK module: <https://github.com/unspecworks/zmk-keyboard-delta-omega>
- ZMK docs: <https://zmk.dev/docs>

## Hardware Overview

- 34-key (3x5+2) split keyboard
- Ultra-low-profile design
- Module provides upstream shield definitions; this repo focuses on user config and build matrix wiring

## Layout

### Physical Layout

![Delta Omega dimension](/docs/images/delta_omega_dimension.png)
![Delta Omega splay](/docs/images/delta_omega_splay_layout.png)
![Delta Omega layout](/docs/images/delta_omega_layout.svg)

### Keymap

![Delta Omega keymap](/docs/images/delta_omega_keymap.svg)

## Firmware Structure

Relevant paths in this repo:

- `config/delta_omega.keymap`
- `config/delta_omega.conf`
- `config/delta_omega_dongle.keymap`
- `boards/shields/delta_omega_variants/`
- `build.yaml`
- `config/west.yml`

Module-provided hardware path after `west update`:

- `modules/keyboards/delta-omega/boards/shields/delta_omega/`

## How to Use

### Build

1. Ensure dependencies are updated: `west update`.
2. Edit user behavior in `config/delta_omega.keymap` and `config/delta_omega.conf`.
3. Build or run CI using matrix entries in `build.yaml`.

Current active targets:

- `delta_omega_left`
- `delta_omega_right`
- `delta_omega_reset`
- `delta_omega_dongle`
- `delta_omega_left_w_dongle`

### Flashing

1. Put left or right target into bootloader mode.
2. Flash matching UF2 artifact for that target.
3. For split operation, flash both halves with matching firmware batch.
4. If BLE state is stale after topology changes, flash reset and re-pair.

## Status

- Delta Omega support is active via upstream module integration.
- Dedicated dongle-side overlay/config exists in `boards/shields/delta_omega_variants/`.
- Build matrix entries are present in `build.yaml`.
