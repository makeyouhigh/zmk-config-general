# Dongle

## Multiple Keyboards With a Single Dongle

This repository is designed around a **single dongle with multiple registered keyboards**.
Only one keyboard set is active at any time. Keyboards are swapped by power state, not by software switching.

## Concept

- One dongle acts as the **BLE central**.
- Multiple split keyboards are **pre-paired** to the dongle.
- Each keyboard consists of two peripherals, left and right.
- Only one keyboard set is powered and connected at a time.

This is a **swap model**, not a multi-input model.

### Design Trade-offs

I think the advantage of dongles is very much overrated.

This document treats dongle mode as a workaround, not an upgrade.

Most commonly cited benefits only exist when comparing dongle-based BLE against host-direct BLE. When compared against a wired keyboard, or a wired master split, those advantages disappear.

Latency is not improved relative to wired. A dongle adds a private BLE hop followed by USB. This can be more stable than host BLE, but it is never better than a wired connection. Any perceived latency improvement comes from avoiding unreliable desktop BLE stacks, not from superior transport.

Reliability is not increased in absolute terms. The failure mode is inverted. Without the dongle, the keyboard cannot connect at all. This trades intermittent BLE issues for a hard external dependency.

Power savings are irrelevant when the master half is connected over USB. A plugged master already avoids host BLE power costs without additional hardware.

Multi-host switching is not unique to dongles. ZMK already supports multiple BLE profiles. The dongle simplifies host switching at the cost of locking operation to a specific device.

Security benefits only apply when comparing against public BLE HID. Compared to wired USB HID, a dongle increases the attack surface rather than reducing it.

Split architecture is simpler from a firmware perspective, but physically worse for users due to reduced mobility and the requirement to carry and not lose an extra device.

The only clear and unconditional benefit of a dongle is offloading UI features such as displays and LEDs without relying on host drivers or HID extensions. All other benefits are trade-offs made specifically to avoid unreliable host BLE behavior, not fundamental technical improvements.

## What “multiple keyboards registered” means

- The dongle stores BLE bond information for many keyboards.
- All keyboards are known to the dongle in advance.
- At runtime, the dongle connects only to the keyboard that is powered on.

It does **not** mean:

- Multiple keyboards sending input simultaneously.
- Hot switching without power cycling.
- Acting as a BLE input mixer.

## Required Constraints

- Never power more than one keyboard set at the same time.
- Always power off the previous keyboard before powering on another.
- Each keyboard must be bonded once to the dongle.

Violating these constraints leads to:

- Reconnect latency
- Pairing churn
- Phantom or misrouted input

## Dongle Requirements

The dongle firmware must be configured as follows:

- ZMK split enabled
- Dongle acts as split central
- Peripheral connection count greater than or equal to 2
- BLE bond storage large enough for all keyboards

If there are N split keyboards, the dongle may need to remember up to **2N bonded peripherals**.

## Initial Pairing Procedure

1. Flash the dongle firmware.
2. Clear BLE bonds on the dongle and all keyboards.
3. Power on keyboard A.
4. Wait until pairing completes.
5. Power off keyboard A.
6. Repeat for keyboard B, C, and so on.

After this process, all keyboards are registered.

## Daily Usage

1. Power off the currently used keyboard.
2. Power on the desired keyboard.
3. The dongle reconnects automatically using stored bonds.

No reflashing or re-pairing is required.

## Design Rationale

- ZMK BLE is optimized for a single active input device.
- Centralizing BLE handling in the dongle reduces dependence on host BLE behavior.
- Power-based swapping avoids firmware-side complexity.
- This model scales predictably as more keyboards are added.

This repository follows this model by design.

## Variations

### Headless

- Nice!Nano v2
- Seeeduino Xiao BLE

### Display

- [ZMK Dongle Display](https://github.com/englmaxi/zmk-dongle-display)
- [Prospector](https://github.com/carrefinho/prospector-zmk-module)
- [Yet Another Dongle Screen(YADS)](https://github.com/janpfischer/zmk-dongle-screen)

---
