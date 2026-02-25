# Sofle

![Sofle layout](/docs/images/sofle_thumbnail.jpg)

This document describes the Sofle keyboard configuration in this repository and how to build and flash it.

## Support Snapshot

Implemented matrix targets:

| Target | Board | Shield | Snippet | Artifact Name | Status |
| --- | --- | --- | --- | --- | --- |
| Left half | `nice_nano_v2` | `sofle_left nice_view_adapter nice_view` | `common-config studio-rpc-usb-uart` | `sofle_left` | Active |
| Right half | `nice_nano_v2` | `sofle_right nice_view_adapter nice_view` | none | `sofle_right` | Active |
| Reset | `nice_nano_v2` | `settings_reset` | none | `sofle_reset` | Active |
| Left half (dongle split) | `nice_nano_v2` | `sofle_left nice_view_adapter nice_view` | none | `sofle_left_w_dongle` | Active |
| Dongle (single keyboard) | `nice_nano_v2` | `sofle_dongle zdd_adapter dongle_display` | `studio-rpc-usb-uart` | `sofle_zdd_dongle` | Active |
| Dongle reset | `nice_nano_v2` | `settings_reset` | none | `sofle_zdd_dongle_reset` | Active |

Related implemented targets for Eyelash Sofle:

| Target | Board | Shield | Snippet | Artifact Name | Status |
| --- | --- | --- | --- | --- | --- |
| Left half | `eyelash_sofle_left` | `nice_view` | `common-config studio-rpc-usb-uart` | `eyelash_sofle_left` | Active |
| Right half | `eyelash_sofle_right` | `nice_view` | none | `eyelash_sofle_right` | Active |
| Reset | `nice_nano_v2` | `settings_reset` | none | `eyelash_sofle_reset` | Active |
| Left half (dongle split) | `eyelash_sofle_left` | `nice_view` | none | `eyelash_sofle_left_w_dongle` | Active |
| Dongle (single keyboard) | `nice_nano_v2` | `eyelash_sofle_dongle zdd_adapter dongle_display` | `studio-rpc-usb-uart` | `eyelash_sofle_zdd_dongle` | Active |
| Dongle reset | `nice_nano_v2` | `settings_reset` | none | `eyelash_sofle_zdd_dongle_reset` | Active |

## Reference Material

- Sofle hardware and build info: <https://github.com/josefadamcik/SofleKeyboard>
- ZMK documentation: <https://zmk.dev/>
- Sofle keyboard document: <https://josefadamcik.github.io/SofleKeyboard/>

## Hardware Overview

- Split ergonomic keyboard with column stagger
- 6x4 alpha cluster per half plus a 5-key thumb cluster
- Typically built with nice!nano or compatible controllers for ZMK
- Common add-ons: OLED displays, rotary encoders, and RGB underglow

## Layout

### Physical Layout

Physical switch arrangement.

![Sofle layout](/docs/images/sofle_layout.svg)

### Keymap

The logical keymap used by this configuration.

![Sofle keymap](/docs/images/sofle_keymap.svg)

## Firmware Structure

Implemented paths:

- `boards/shields/sofle/`
- `config/sofle.conf`
  - User-level feature configuration (display, encoders, power)
- `config/sofle.keymap`
  - Layers, behaviors, combos, macros, and sensor bindings
- `build.yaml`
- `docs/images/sofle_keymap.svg`

Related implemented paths for Eyelash Sofle:

- `boards/arm/eyelash_sofle/`
- `config/eyelash_sofle.conf`
- `config/eyelash_sofle.keymap`
- `boards/shields/eyelash_sofle/`

Dongle-specific config overrides:

- `config/sofle_zdd_dongle.conf`
- `config/eyelash_sofle_zdd_dongle.conf`

## How to Use

### Build

1. Edit `config/sofle.keymap` and `config/sofle.conf` as needed.
2. Build with CI or local Docker using artifact names from `build.yaml`.

Local Docker (recommended):

```bash
# list artifacts
docker compose run --rm zmk-build-release --list

# build only Sofle and Eyelash Sofle split targets
docker compose run --rm zmk-build-release --artifact-names sofle_left,sofle_right,sofle_reset,eyelash_sofle_left,eyelash_sofle_right,eyelash_sofle_reset

# build Sofle and Eyelash Sofle dongle targets
docker compose run --rm zmk-build-release --artifact-names sofle_left_w_dongle,sofle_zdd_dongle,sofle_zdd_dongle_reset,eyelash_sofle_left_w_dongle,eyelash_sofle_zdd_dongle,eyelash_sofle_zdd_dongle_reset
```

### Flashing

1. Connect the left half to your PC via USB.
2. Enter bootloader mode (usually by double-tapping reset).
3. Drag and drop the matching left UF2 file.
4. Repeat for the right half with the matching right UF2 file.
5. Use reset UF2 when clearing settings and BLE bonds.

Artifact-to-device mapping:

| Artifact | Flash To |
| --- | --- |
| `sofle_left.uf2` | Sofle left half |
| `sofle_right.uf2` | Sofle right half |
| `sofle_reset.uf2` | Sofle side when clearing settings/bonds |
| `sofle_left_w_dongle.uf2` | Sofle left half for dongle topology |
| `sofle_zdd_dongle.uf2` | Sofle dedicated dongle |
| `sofle_zdd_dongle_reset.uf2` | Sofle dongle reset target |
| `eyelash_sofle_left.uf2` | Eyelash Sofle left half |
| `eyelash_sofle_right.uf2` | Eyelash Sofle right half |
| `eyelash_sofle_reset.uf2` | Eyelash Sofle side when clearing settings/bonds |
| `eyelash_sofle_left_w_dongle.uf2` | Eyelash Sofle left half for dongle topology |
| `eyelash_sofle_zdd_dongle.uf2` | Eyelash Sofle dedicated dongle |
| `eyelash_sofle_zdd_dongle_reset.uf2` | Eyelash Sofle dongle reset target |

## Configuration

- `config/sofle.conf` controls system features.
- `config/sofle.keymap` defines layer and behavior logic.
- If Sofle-specific config files do not exist in another branch/repo, add them under `config/` and follow this structure.

## Troubleshooting

- If split halves fail to reconnect, flash reset UF2 and re-pair.
- If behavior differs between halves, reflash both halves from the same build batch.
- If Studio does not connect on left builds, confirm `common-config studio-rpc-usb-uart` is still enabled for left targets in `build.yaml`.
- For Eyelash Sofle, verify matrix/header include paths in `config/eyelash_sofle.keymap` before rebuilding.

## Status

- Sofle split targets are active in `build.yaml`.
- Eyelash Sofle split targets are active in `build.yaml`.
- Sofle and Eyelash Sofle dongle targets are active in `build.yaml`.
