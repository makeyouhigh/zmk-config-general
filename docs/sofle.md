# Sofle

![Sofle layout](/docs/images/sofle_thumbnail.jpg)
This document describes the Sofle keyboard configuration in this repository and how to build and flash it.

## Reference Material

- Sofle hardware and build info: <https://github.com/josefadamcik/SofleKeyboard>
- ZMK documentation: <https://zmk.dev/>

## Hardware Overview

- Split ergonomic keyboard with column stagger
- 6×4 alpha cluster per half plus a 5-key thumb cluster
- Typically built with nice!nano or compatible controllers for ZMK
- Common add-ons: OLED displays, rotary encoders, and RGB underglow

## Layout

### Physical layout

Physical switch arrangement.

![Sofle layout](/docs/images/sofle_layout.svg)

### Keymap

The logical keymap used by this configuration.

![Sofle keymap](/docs/images/sofle_keymap.svg)

## Firmware Structure

Relevant paths.

- `docs/sofle.md`
  - This document
- `docs/images/sofle_keymap.svg`
  - Rendered Sofle keymap
- `config/sofle.conf` (recommended)
  - User-level feature configuration for Sofle builds
  - User-level feature configuration (Display, Encoders, Power)
- `config/sofle.keymap` (recommended)
  - Layers, behaviors, combos, and macros
  - 60-key layout definition with sensor bindings

If Sofle-specific config files do not exist yet, add them under `config/` and follow the same patterns used by the other keyboards in this repo.

## How to Use

### Build

1. Fork this repository.
2. Clone your fork locally.
3. Add or edit `config/sofle.keymap` and `config/sofle.conf` as needed.
4. Commit and push your changes.
5. Download the Sofle firmware artifacts from the successful GitHub Actions build.

Current CI targets in `build.yaml`:

- `sofle_left`, `sofle_right`, `sofle_reset`
- `sofle_dongle`, `sofle_left_w_dongle`
- `eyelash_sofle_left`, `eyelash_sofle_right`, `eyelash_sofle_reset`
- `eyelash_sofle_dongle`, `eyelash_sofle_left_w_dongle`

> [!NOTE]
> `eyelash_sofle_dongle` currently reuses Sofle-style dongle key mapping. Eyelash-only extra inputs are staged for follow-up mapping work.

### Flashing

1. Connect the left half to your PC via USB.
2. Enter bootloader mode (usually by double-tapping reset).
3. Drag and drop the left-half UF2 file onto the mounted drive.
4. Repeat for the right half with the right-half UF2 file.

## Reference

- [Sofle Keyboard Document](https://josefadamcik.github.io/SofleKeyboard/)

## Status

- Sofle targets are active in `build.yaml`.
- Dongle role targets are present as `sofle_dongle` and `sofle_left_w_dongle`.
- Eyelash Sofle targets are present as `eyelash_sofle_dongle` and `eyelash_sofle_left_w_dongle`.
