# DELTA OMEGA

![DELTA OMEGA](/docs/images/delta_omega_header.png)

A portable ultra-low-profile (ULP) wireless 3×5+2 split keyboard designed by [unspecworks](https://github.com/unspecworks). It focuses on extreme portability, rigid construction, and minimal key count while preserving ergonomics through splay and stagger.

> [!Note]
> Delta Omega hardware design, case, and branding are owned by [unspecworks](https://github.com/unspecworks).
> This repository only provides ZMK configuration and documentation.

## Overview

- Switch support: Cherry MX ULP or Kailh PG1316s
- 34 keys, splayed and staggered with choc spacing
- Wireless
- CNC aluminum case

Delta Omega targets users who want a travel ready split keyboard with minimal thickness and a solid, premium enclosure. The layout prioritizes thumb efficiency and compact reach over key count.

## Parameters

### Hardware

![Dimension](/docs/images/delta_omega_dimension.png)
![Splay Layout](/docs/images/delta_omega_splay_layout.png)

### Physical Layout

![Layout](/docs/images/delta_omega_layout.svg)

### Keymap

![Keymap](/docs/images/delta_omega_keymap.svg)

## ZMK Support

Delta Omega provides official ZMK support via a dedicated keyboard module maintained by the designer.

- [ZMK keyboard module](https://github.com/unspecworks/zmk-keyboard-delta-omega)
- [Pre configured ZMK repository](https://github.com/unspecworks/zmk-delta-omega)

This repository consumes Delta Omega support rather than re implementing the shield locally.

## Firmware Integration in This Repo

- Delta Omega shield is sourced from the upstream module
- No custom matrix or pin definitions are duplicated here
- User behavior and layout live under config/delta_omega.\*
- Build wiring is handled via west.yml and build.yaml

This keeps hardware definitions upstream and avoids drift.

## Documentation and References

- [DELTA OMEGA](https://github.com/unspecworks/delta-omega)
  - [Delta ULP Keycap](https://github.com/unspecworks/delta-ulp-keycap)
- [Video](https://youtu.be/UktrqN3MlLI)
- [ZMK Keyboard Module](https://github.com/unspecworks/zmk-keyboard-delta-omega)
  - [Pre-conf ZMK Config](https://github.com/unspecworks/zmk-delta-omega)
