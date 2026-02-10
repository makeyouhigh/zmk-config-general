# Urchin 🪸

![Urchin Thumbnail](/docs/images/urchin_thumbnail.jpg)

This document describes the Urchin keyboard: its hardware, design philosophy, layout, and how ZMK firmware applies to it.

The Urchin keyboard was originally designed by Duccio (duckyb) as a 34-key wireless-only split keyboard optimized for ZMK and nice!nano controllers. It is a derivative of the Sweep/Swoop family with native support for nice!view displays and hotswappable sockets.

## Reference Material

- Original Urchin hardware & firmware: <https://github.com/duckyb/urchin>
  - Original makers firmware: <https://github.com/duckyb/urchin-zmk-firmware>
  - Original makers shield: <https://github.com/duckyb/urchin-zmk-module>
- Variant ZMK configurations and community forks: <https://github.com/theearp/zmk-urchin>

## Hardware Overview

- 34-key split matrix (3 rows of 10 keys per half plus thumb cluster)
- Wireless only: no wired USB connection supported natively; Bluetooth via nice!nano controllers required
- Kailh Choc v1 hotswap sockets for low-profile switches
- Designed with power savings and deep sleep in mind
- Support for optional nice!view displays (sharp memory-in-pixel)
- Custom PCB with diodes and matrix for ZMK compatibility

## Layout

### Physical Layout

The Urchin uses a compact 3×5+2 split layout per half with a thumb cluster.

![Urchin Render](/docs/images/urchin_render.png)

![Urchin Layout](/docs/images/urchin_layout.svg)

### Keymap

Urchin keymaps often use layer modifiers under the thumbs to access numbers, symbols, and navigation.

![Urchin Keymap](/docs/images/urchin_keymap.svg)

## Firmware Structure

The original ZMK firmware for Urchin includes:

- Matrix definitions for the split 34-key layout
- Bluetooth configuration for nice!nano
- Optional display support for nice!view screens
- Layer and behavior definitions matching the physical layout

Community forks modify keymaps and layer logic, but the core hardware support remains in the original repo structure.

## How to Use

### Build

1. Clone the Urchin ZMK repo (or use this repo’s Urchin integration).
2. Adjust config/urchin.conf for features like sleep, display, and Bluetooth power.
3. Customize config/urchin.keymap for your preferred layers.
4. Build using GitHub Actions or a local ZMK build environment.

### Flashing

1. Flash the left half first using the appropriate UF2 (urchin_left.uf2).
2. Flash the right half next (urchin_right.uf2).
3. Power both halves on and ensure Bluetooth pairing with your host.

## Display and Power

- Nice!view displays provide battery, connection, and layer status if installed.
- Power usage is optimized for long battery life using deep sleep.

## Typical Use Case

Urchin is used by split keyboard enthusiasts who want:

- Wireless Bluetooth connection
- Compact ergonomic layout without a number row
- Layer-based number and symbol access
- Display feedback for connection and battery status

Many users report the split 3×5 layout feels fast once the muscle memory develops.

## Status

- Urchin targets are active in `build.yaml`.
- Dongle role targets are present as `urchin_dongle` and `urchin_left_w_dongle`.
