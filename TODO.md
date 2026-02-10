# Development TODO

Use this as a process tracker.

Rule of done for each firmware target:

- [ ] target implemented (shield/config/keymap/overlay)
- [ ] target added to `build.yaml`
- [ ] CI build passed
- [ ] runtime test passed (pairing/reconnect/role behavior)
- [ ] docs updated

## 1. Dongle

### 1.0 Naming / baseline

- [ ] Freeze naming convention (`<keyboard>_<hardware>_<role>`)
- [ ] Freeze hardware IDs (`zdd`, `prospector`)
- [x] Freeze role names (`dongle`, `central`, `scanner`)

### ZMK Dongle Display(`zdd`)

- [ ] implement device single
  - [x] totem
  - [x] urchin
  - [x] sofle
  - [x] eyelash sofle
  - [x] cornix
  - [x] delta omega
  - [x] corne
  - [x] eyelash corne variation
- [ ] develop central
  - [ ] totem
  - [ ] urchin
  - [ ] sofle
  - [ ] eyelash sofle
  - [ ] cornix
  - [ ] delta omega
  - [ ] corne
- [ ] develop scanner
  - [ ] totem
  - [ ] urchin
  - [ ] sofle
  - [ ] eyelash sofle
  - [ ] cornix
  - [ ] delta omega
  - [ ] corne

### Prospector hardware(`prospector`) + YADS firmware

- [ ] implement device single
  - [ ] totem
  - [ ] urchin
  - [ ] sofle
  - [ ] eyelash sofle
  - [ ] cornix
  - [ ] delta omega
  - [ ] corne
- [ ] develop central
  - [ ] totem
  - [ ] urchin
  - [ ] sofle
  - [ ] eyelash sofle
  - [ ] cornix
  - [ ] delta omega
  - [ ] corne
- [ ] develop scanner
  - [ ] totem
  - [ ] urchin
  - [ ] sofle
  - [ ] eyelash sofle
  - [ ] cornix
  - [ ] delta omega
  - [ ] corne

### 1.5 Shared dongle checks

- [x] Confirm scanner source keyboards use `scanner-advertisement`
- [x] Confirm bond reset workflow (`settings_reset` and `BT_CLR`) per role
- [x] Confirm role switch workflow (reflash dongle, reflash keyboard when needed)

## 2. Keyboard / Devices

- [x] Totem: verify left/right/reset targets
- [x] Urchin: verify left/right/reset targets
- [x] Sofle: verify left/right/reset targets
- [x] Corne: verify target status and doc status
- [ ] Cornix: verify target status and doc status
- [ ] Delta Omega: verify target status and doc status

- [ ] `*_left_w_dongle` targets: verify display config is correct for each keyboard
- [ ] Continuum integration: remove duplicated per-keyboard keymap logic
- [ ] Verify sleep/battery/BLE defaults per keyboard family
- [ ] Verify split peripheral counts are correct for each central role target

## 3. Documentation

- [x] Keep `README.md` and `README_KO.md` synchronized after each feature batch
- [x] Keep dongle role wording consistent (`dongle`, `central`, `scanner`)
- [x] Update `docs/dongle.md` matrix and examples after each new target
- [x] Run docs sanity pass against `docs/docs_rules.md`
- [x] Keep `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md`, and docs rules aligned
- [x] Ensure each keyboard doc has current build/flash/troubleshooting sections

## 4. CICD

- [ ] Keep all existing matrix targets green
- [ ] Confirm `urchin_left_w_dongle` display regression stays fixed
- [ ] Add new targets incrementally (do not batch too many at once)
- [x] Ensure each target has unique `artifact-name`
- [ ] Keep `cmake-args` overrides minimal and documented in `build.yaml`
- [ ] Verify module pins in `config/west.yml` before releases
- [ ] Add release checklist step: artifact count and names match matrix

## 5. Nice to Have

- [ ] Add standalone compatibility matrix doc (`keyboard x hardware x role`)
- [ ] Add dongle troubleshooting decision tree
- [ ] Add reusable manual runtime test checklist template
- [ ] Add changelog template focused on firmware behavior changes
- [ ] Add simple architecture diagrams for each dongle role
