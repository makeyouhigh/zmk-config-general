# Dongle

This document is the repository-specific technical guide for dongle operation.

## Scope

- This guide describes dongle roles used in this repo.
- Dongle role is fixed by firmware build and cannot be switched at runtime.
- Changing role requires reflashing dongle firmware, and may also require reflashing keyboard firmware.

## Dongle Roles

This repository defines three dongle roles:

- `central`
  - One dongle acts as BLE central for multiple split keyboards that are pre-bonded.
  - Only one keyboard set should be active at a time.
- `dongle`
  - One dongle is dedicated to a single keyboard.
  - Intended for single-keyboard daily use with a fixed pairing set.
- `scanner`
  - Dongle passively scans keyboard status advertisements and renders status UI.
  - It is an observer role, not a BLE input transport path.

## Role Architecture Diagrams

These diagrams are conceptual and describe firmware role topology only.

### `dongle` role (single keyboard dedicated)

```text
[Keyboard Left] ----\
                     >==== BLE split link ====> [Keyboard Right]
                                     |
                                     | BLE (input transport)
                                     v
                              [Dongle (role=dongle)]
                                     |
                                     | USB or BLE
                                     v
                                   [Host]
```

### `central` role (multi-keyboard central)

```text
[Keyboard Set A: L/R] --\
[Keyboard Set B: L/R] ----> [Dongle (role=central)] ----> [Host]
[Keyboard Set C: L/R] --/             ^
                                      |
                          Only one keyboard set active at a time
```

### `scanner` role (status observer)

```text
[Keyboard(s)] -- status advertisements --> [Dongle (role=scanner)] --> [Display/UI]
     |
     +-- input path to host is separate (scanner is not input transport)
```

## Dongle Hardware Variants

This repo uses two dongle hardware families:

- ZMK Dongle Display (`zdd`) hardware
- Prospector hardware

Firmware direction in this repo:

- `zdd` hardware uses ZMK Dongle Display firmware family
- `prospector` hardware uses YADS firmware family (robust alternative track)

Both hardware variants can run any of the roles above, as long as the matching role firmware is flashed.

## Role Switching Rules

1. Build or download firmware for the target role.
2. Flash the dongle with that role firmware.
3. If required by topology change, flash matching keyboard firmware.
4. Clear stale BLE bonds before pairing again.

Role switching is a reflash workflow, not a runtime toggle.

## Naming Convention

This repository uses a fixed naming policy for dongle targets:

- Single keyboard role targets:
  - `<keyboard>_<hardware>_<role>`
  - Examples:
    - `totem_zdd_dongle`
    - `totem_prospector_dongle`
- Shared role targets (`central`, `scanner`):
  - `<hardware>_<role>`
  - Examples:
    - `zdd_central`, `prospector_central`
    - `zdd_scanner`, `prospector_scanner`

Frozen identifiers:

- Hardware IDs: `zdd`, `prospector`
- Role IDs: `dongle`, `central`, `scanner`

## Concrete Build Examples

These examples are naming and matrix templates.
Some are planned-only depending on current matrix coverage.

1. `zdd` + `dongle` role (single keyboard)
   - `board: nice_nano_v2`
   - `shield: totem_zdd_dongle`
   - `artifact-name: totem_zdd_dongle`
2. `prospector` + `dongle` role (single keyboard)
   - `board: <prospector_board>`
   - `shield: totem_prospector_dongle`
   - `artifact-name: totem_prospector_dongle`
3. `zdd` + `central` role
   - `board: nice_nano_v2`
   - `shield: zdd_central dongle_display`
   - `artifact-name: zdd_central`
4. `prospector` + `central` role
   - `board: <prospector_board>`
   - `shield: prospector_central`
   - `artifact-name: prospector_central`
5. `zdd` + `scanner` role
   - `board: nice_nano_v2`
   - `shield: zdd_scanner dongle_display`
   - `artifact-name: zdd_scanner`
6. `prospector` + `scanner` role
   - `board: <prospector_board>`
   - `shield: prospector_scanner`
   - `artifact-name: prospector_scanner`

## Current Build Coverage

Current state from `build.yaml` (checked on February 20, 2026):

- Active dongle-related entries:
  - `totem_zdd_dongle`
  - `totem_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `totem_zdd_dongle_reset` (settings reset target for that hardware class)
  - `urchin_zdd_dongle`
  - `urchin_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `urchin_zdd_dongle_reset` (settings reset target for that hardware class)
  - `delta_omega_zdd_dongle`
  - `delta_omega_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `delta_omega_zdd_dongle_reset` (settings reset target for that hardware class)
  - `corne_zdd_dongle`
  - `corne_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `corne_zdd_dongle_reset` (settings reset target for that hardware class)
  - `eyelash_corne_zdd_dongle`
  - `eyelash_corne_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `eyelash_corne_zdd_dongle_reset` (settings reset target for that hardware class)
  - `sofle_zdd_dongle`
  - `sofle_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `sofle_zdd_dongle_reset` (settings reset target for that hardware class)
  - `eyelash_sofle_zdd_dongle`
  - `eyelash_sofle_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `eyelash_sofle_zdd_dongle_reset` (settings reset target for that hardware class)
  - `cornix_zdd_dongle`
  - `cornix_left_w_dongle` (keyboard-side peripheral build for dongle topology)
  - `cornix_zdd_dongle_reset` (settings reset target for that hardware class)
  - `zdd_central`
  - `zdd_scanner`
- Not active yet:
  - `prospector_central`, `prospector_scanner`
  - `<keyboard>_prospector_dongle` family targets

## `central` Role: Multi-Keyboard Model

### Concept

- One dongle is the BLE central.
- Multiple split keyboard sets are pre-bonded to that dongle.
- Each split keyboard typically contributes two peripherals (left and right).
- At runtime, use one keyboard set at a time.

This is a swap model, not a multi-input model.

### Capacity and Constraints

- Never power more than one keyboard set at the same time.
- Power off the current keyboard before powering on the next keyboard.
- Each keyboard set must be bonded once.
- Bond storage must fit the total peripheral count.

If there are `N` split keyboards, plan for up to `2N` bonded peripherals.

Repository default for `zdd_central` currently sets:

- `CONFIG_ZMK_SPLIT_BLE_CENTRAL_PERIPHERALS=6`

### Pairing Procedure (Recommended)

1. Flash dongle firmware for `central` role.
2. Flash keyboard firmware compatible with that role.
3. Clear BLE bonds on dongle and keyboards before first pairing.
4. Power on keyboard A and complete bonding.
5. Power off keyboard A.
6. Repeat for keyboard B, C, and others.

### Daily Use

1. Power off the currently active keyboard.
2. Power on the keyboard you want to use.
3. The dongle reconnects using stored bonds.

## `scanner` Role: Status Observer Model

### Concept

- Scanner listens for status advertisements from compatible keyboard firmware.
- Scanner does not replace keyboard-to-host input routing.
- Scanner display is independent from host BLE stack quality.

### Requirements

- Keyboard firmware must enable status advertisement.
  - This repo uses `scanner-advertisement` snippet for that purpose.
- Channel settings must match your intended topology.
  - `CONFIG_PROSPECTOR_CHANNEL` on keyboards
  - `CONFIG_PROSPECTOR_SCANNER_CHANNEL` on scanner
  - `0` means broadcast/accept-all.

## Bond Reset Methods

Use one of these reset methods when reconnect behavior is unstable or after role changes:

- Flash `settings_reset` firmware (if target is available in your build matrix).
- Press a keyboard key mapped to `BT_CLR` (`&bt BT_CLR`) to clear BLE bonds.

## Personal Trade-off Notes

I still think the advantage of dongles is often overrated.

In this repo, dongle mode is mostly a role-based workaround, not a universal upgrade.

### `central` role

- Useful when you rotate multiple split keyboards and want one pre-bonded central point.
- Compared to wired, latency is not better because the path adds an extra BLE hop.
- Reliability does not increase in absolute terms. Failure mode shifts to dongle dependency.
- Operational burden is real: strict one-keyboard-at-a-time power policy and larger bond management (`2N` split peripherals for `N` keyboards).

### `dongle` role

- Practical for a single keyboard setup when host BLE behavior is inconsistent.
- Main gain is predictable reconnect behavior and stable host pathing.
- Compared to wired master split, benefits are limited and you still carry an extra dependency.

### `scanner` role

- This is still the clearest value case among dongle roles.
- Dedicated status UI offload is useful and can stay independent from host input transport.
- It is still additive hardware, so value depends on whether you actually use status surfaces.

### Bottom line

Most dongle benefits are comparative against weak host BLE stacks, not fundamental transport improvements over wired. For this repo, dongle is best treated as a targeted tool per role: `central` for multi-keyboard orchestration, `dongle` for single-keyboard stability, and `scanner` for UI/status observability.

## Related References

- [README Dongle section](../README.md#dongle)
- [ZMK Dongle Display](https://github.com/englmaxi/zmk-dongle-display)
- [YADS](https://github.com/janpfischer/zmk-dongle-screen)
- [Prospector Scanner Module](https://github.com/t-ogura/prospector-zmk-module)
- [zmk-config-prospector](https://github.com/t-ogura/zmk-config-prospector)
