# Development

This document describes the development workflow used by this repository.

## Current CI Scope

The active firmware matrix is defined in `build.yaml`.

- `seeeduino_xiao_ble + totem_left` -> `totem_left.uf2`
- `seeeduino_xiao_ble + totem_right` -> `totem_right.uf2`
- `seeeduino_xiao_ble + settings_reset` -> `totem_reset.uf2`

Other keyboard docs are reference material; they are not currently included in the CI build matrix.

## Recommended Workflow (GitHub Actions)

1. Edit `config/*.keymap` and/or `config/*.conf`.
2. Commit and push your branch.
3. Wait for the `Build ZMK firmware` workflow to pass.
4. Download artifacts from Actions:
5. Flash the matching `.uf2` files to each half.

This is the easiest way to stay aligned with this repository's pinned dependencies in `config/west.yml`.

## Local Build (Docker, PowerShell)

### Prerequisites

- Docker Desktop
- Git
- This repository cloned locally

### Build all artifacts locally

Run from repository root:

```powershell
New-Item -ItemType Directory -Force firmware | Out-Null

# Left
docker run --rm -it -v "${PWD}:/config" -v "${PWD}/firmware:/firmware" zmkfirmware/zmk-build-arm:stable bash -lc "set -e; mkdir -p /work && cd /work; git clone --depth 1 --branch v0.3 https://github.com/zmkfirmware/zmk.git; cd zmk; west init -l app; west update; west zephyr-export; west build -p -s app -b seeeduino_xiao_ble -- -DSHIELD=totem_left -DSNIPPET='common-config;studio-rpc-usb-uart' -DZMK_CONFIG=/config; cp build/zephyr/zmk.uf2 /firmware/totem_left.uf2"

# Right
docker run --rm -it -v "${PWD}:/config" -v "${PWD}/firmware:/firmware" zmkfirmware/zmk-build-arm:stable bash -lc "set -e; mkdir -p /work && cd /work; git clone --depth 1 --branch v0.3 https://github.com/zmkfirmware/zmk.git; cd zmk; west init -l app; west update; west zephyr-export; west build -p -s app -b seeeduino_xiao_ble -- -DSHIELD=totem_right -DSNIPPET='common-config' -DZMK_CONFIG=/config; cp build/zephyr/zmk.uf2 /firmware/totem_right.uf2"

# Reset firmware
docker run --rm -it -v "${PWD}:/config" -v "${PWD}/firmware:/firmware" zmkfirmware/zmk-build-arm:stable bash -lc "set -e; mkdir -p /work && cd /work; git clone --depth 1 --branch v0.3 https://github.com/zmkfirmware/zmk.git; cd zmk; west init -l app; west update; west zephyr-export; west build -p -s app -b seeeduino_xiao_ble -- -DSHIELD=settings_reset -DZMK_CONFIG=/config; cp build/zephyr/zmk.uf2 /firmware/totem_reset.uf2"
```

Expected outputs:

- `firmware/totem_left.uf2`
- `firmware/totem_right.uf2`
- `firmware/totem_reset.uf2`

## Flashing

For each target device:

1. Connect via USB.
2. Enter bootloader mode (usually double-tap reset).
3. Copy the matching `.uf2` file to the mounted drive.
4. Wait for automatic reboot.

Typical order for a clean state:

1. Flash `totem_reset.uf2` (optional, for bond/settings reset).
2. Flash `totem_left.uf2` to left half.
3. Flash `totem_right.uf2` to right half.

## Quick Troubleshooting

- Build fails with unknown shield: verify `-DSHIELD` matches one of `totem_left`, `totem_right`, `settings_reset`.
- Missing modules during local build: ensure `west update` ran successfully.
- Split reconnect problems after flashing: flash reset firmware and re-pair from scratch.
