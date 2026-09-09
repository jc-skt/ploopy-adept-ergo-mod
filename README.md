# Ploopy Adept - Ergo Mod

A sculpted, eight-button top for the [Ploopy Adept](https://ploopy.co) trackball, with matching
custom QMK firmware that is remappable in [VIA](https://usevia.app).

The stock Adept ships with six buttons. The Madromys R1.001 PCB has two more switch pads (SW5 and
SW7) that are left empty; this mod populates them and replaces the top shell with an ergonomic
one: two stacked buttons on the left, two tall thumb keys, two stacked buttons on the right and
two side-by-side buttons under them.

| | |
|---|---|
| **Status** | Firmware verified on a real board: all eight buttons, drag scroll, DPI cycling and VIA remapping (persists across replug). STLs being uploaded. |
| **Hardware** | Ploopy Adept (Madromys R1.001 or later PCB), all eight switch pads populated |
| **Firmware** | QMK, keyboard `ploopyco/madromys/rev1_001_ergomod`, keymap `default`, VIA enabled, USB PID `0x5C48`, current version **1.0.3** |
| **Remapping** | VIA with a sideloaded draft definition (`firmware/via/ploopy-adept-ergo-mod.json`) |

## Contents

```
firmware/ploopyco_madromys_rev1_001_ergomod_default_v1.0.3.uf2   ready-to-flash firmware (versioned)
firmware/via/ploopy-adept-ergo-mod.json             VIA v3 draft definition for the ergo layout
firmware/qmk/rev1_001_ergomod/                      QMK keyboard folder (source)
firmware/LICENSE                                    GPL-2.0-or-later (firmware)
stl/                                                bottom, top and cradle STLs
stl/keycaps/                                        eight parametric keycaps (KLP Lame derived) + parameter guide
fusion/                                             Fusion 360 source (.f3d)
LICENSE                                             CC BY-SA 4.0 (hardware, docs)
```

## Button map

One matrix row; the columns follow the direct-pin order
`GP15, GP17, GP19, GP21, GP23, GP11, GP4, GP14`.

| Physical button (ergo top) | PCB pad | Pin | Default action |
|---|---|---|---|
| Left top | SW1 | GP17 | Forward (`MS_BTN5`) |
| Left middle | SW2 | GP19 | Back (`MS_BTN4`) |
| Thumb outer | SW5 | GP4 | Left click (`MS_BTN1`) |
| Thumb inner | SW8 | GP15 | Drag scroll, hold (`DRAG_SCROLL`) |
| Right top | SW4 | GP21 | Shift, hold (`KC_LSFT`) |
| Right middle | SW3 | GP23 | Right click (`MS_BTN2`) |
| Right bottom inner | SW6 | GP11 | Cycle DPI 400 / 800 / 1200 / 1600 (`DPI_CONFIG`) |
| Right bottom outer | SW7 | GP14 | Middle click (`MS_BTN3`) |

SW5 and SW7 are the pads the stock board leaves empty; their pins were confirmed on a real
board. If one button never registers, suspect its solder joint or trace before the firmware. Do
not use GP1 for anything: it reads low at power-up on at least one board.

Drag scroll is momentary (hold), divisor 8 on both axes. The DPI button cycles 400 → 800 → 1200 →
1600 → 400, starting at 1200 after a fresh flash (the current step is remembered in EEPROM). Everything
is remappable in VIA; the custom keycodes `DPI` and `Drag` appear under the **Custom** group.

## Flashing

1. Put the trackball into the bootloader: hold **Thumb inner** while plugging in the USB cable
   (Bootmagic), or, with the bottom cover off, bridge the two gold-plated vias on the PCB with
   tweezers while plugging in. A USB drive called `RPI-RP2` appears.
2. Copy the newest `firmware/ploopyco_madromys_rev1_001_ergomod_default_v*.uf2` onto that drive. It ejects itself
   and the trackball re-enumerates as a mouse.

There is no reset button on the Madromys. If the board stops enumerating altogether, enter the
bootloader with the vias, copy Raspberry Pi's
[`flash_nuke.uf2`](https://datasheets.raspberrypi.com/soft/flash_nuke.uf2) to `RPI-RP2`, wait
for the drive to return, then flash again.

## Firmware versions

The version is in the file name and in the USB device descriptor (Device Manager shows it as the
firmware revision; VIA shows it under the device name).

| Version | Date | Change |
|---|---|---|
| 1.0.3 | 2026-09-08 | Renamed everything to *Ploopy Adept - Ergo Mod*: USB product name, VIA definition, QMK folder `rev1_001_ergomod`, branch `adept-ergo-mod`, file names. No functional change. |
| 1.0.2 | 2026-09-08 | DPI steps 400 / 800 / 1200 / 1600 (was 1200 / 1600 / 2400); starts at 1200. |
| 1.0.1 | 2026-09-08 | PID `0x5C48` really applied (1.0.0 still enumerated as the stock `0x5C47`, so VIA showed the stock Adept). |
| 1.0.0 | 2026-09-08 | First build. Not usable with the ergo VIA definition; superseded. |

## Remapping in VIA

The firmware uses PID `0x5C48`, which VIA does not know, so the layout is loaded as a draft:

1. Open https://usevia.app in Chrome or Edge (WebHID is required).
2. Settings (gear) > turn on **Show Design tab**.
3. **Design** tab > **Load Draft Definition** > pick `firmware/via/ploopy-adept-ergo-mod.json`.
4. **Configure** tab > **Authorize device +** > choose *Ploopy Adept - Ergo Mod*.

Draft definitions are kept in the browser's own storage (IndexedDB), so they survive reloads and closing the tab; repeat step 3 only after clearing site data, in a private window, or on
a new machine. Remapped keys are stored on the trackball and survive replugging.

## Building from source

The keyboard folder lives on the
[`adept-ergo-mod`](https://github.com/jc-skt/qmk_firmware/tree/adept-ergo-mod) branch
of `jc-skt/qmk_firmware`:

```
qmk setup jc-skt/qmk_firmware -b adept-ergo-mod
qmk compile -kb ploopyco/madromys/rev1_001_ergomod -km default
```

Or copy `firmware/qmk/rev1_001_ergomod/` into `keyboards/ploopyco/madromys/` of any recent QMK
checkout (see `firmware/qmk/README.md`).

## Printing

Three shell parts (`stl/bottom.stl`, `stl/top.stl`, `stl/cradle.stl`) and eight keycaps
(`stl/keycaps/`). The keycaps are derived from [KLP Lamé](https://github.com/braindefender/KLP-Lame-Keycaps)
and are parametric in the Fusion 360 source; `stl/keycaps/README.md` lists every parameter and
what it does.

## License

- Hardware, models and documentation: [CC BY-SA 4.0](LICENSE), the same license Ploopy uses for
  the Adept. This is a derivative of Ploopy's design; Ploopy Corporation owns the original.
- Firmware (`firmware/`): [GPL-2.0-or-later](firmware/LICENSE), like QMK.

## Credits

- [Ploopy](https://ploopy.co) for the Adept, the open hardware files and the QMK support.
- [braindefender's KLP Lamé](https://github.com/braindefender/KLP-Lame-Keycaps) for the keycap profiles (CC BY-SA 4.0).
- [QMK](https://qmk.fm) and [VIA](https://usevia.app).
