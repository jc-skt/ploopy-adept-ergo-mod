# Ploopy Adept - Ergo Mod

A sculpted, eight-button top for the [Ploopy Adept](https://ploopy.co) trackball, with matching
custom QMK firmware that is remappable in [VIA](https://usevia.app).

The stock Adept ships with six buttons. The Madromys R1.001 PCB has two more switch pads (SW5 and
SW7) that are left empty; this mod populates them and replaces the top shell with an ergonomic
one: two stacked buttons on the left, two tall thumb keys, two stacked buttons on the right and
two side-by-side buttons under them.

| | |
|---|---|
| **Status** | Firmware builds and lints clean. **Not yet tested on hardware**; see the note on GP4/GP14 below. STL files are still being exported. |
| **Hardware** | Ploopy Adept (Madromys R1.001 or later PCB), all eight switch pads populated |
| **Firmware** | QMK, keyboard `ploopyco/madromys/rev1_001_ergo`, keymap `default`, VIA enabled, USB PID `0x5C48` |
| **Remapping** | VIA with a sideloaded draft definition (`firmware/via/adept-ergo-8.json`) |

## Contents

```
firmware/ploopyco_madromys_rev1_001_ergo_default.uf2   ready-to-flash firmware
firmware/via/adept-ergo-8.json                      VIA v3 draft definition for the ergo layout
firmware/qmk/rev1_001_ergo/                         QMK keyboard folder (source)
firmware/test/                                      all-buttons-right-click test build
firmware/LICENSE                                    GPL-2.0-or-later (firmware)
stl/                                                printable parts (coming soon)
LICENSE                                             CC BY-SA 4.0 (hardware, docs)
```

## Button map

One matrix row; the columns follow the direct-pin order
`GP15, GP17, GP19, GP21, GP23, GP11, GP4, GP14`.

| Physical button (ergo top) | PCB pad | Pin | Default action |
|---|---|---|---|
| Left top | SW1 | GP17 | Forward (`MS_BTN5`) |
| Left middle | SW2 | GP19 | Back (`MS_BTN4`) |
| Thumb outer | SW5 | GP4 * | Left click (`MS_BTN1`) |
| Thumb inner | SW8 | GP15 | Drag scroll, hold (`DRAG_SCROLL`) |
| Right top | SW4 | GP21 | Shift, hold (`KC_LSFT`) |
| Right middle | SW3 | GP23 | Right click (`MS_BTN2`) |
| Right bottom inner | SW6 | GP11 | Cycle DPI 1200 / 1600 / 2400 (`DPI_CONFIG`) |
| Right bottom outer | SW7 | GP14 * | Middle click (`MS_BTN3`) |

\* **Unconfirmed.** SW5 and SW7 are the pads the stock board leaves empty. The unmerged upstream
8-button commit assigns them GP4 and GP14 but not which is which. If, in VIA's key tester, the
thumb outer and right bottom outer keys light up swapped, swap the two matrix indices `[0, 6]`
and `[0, 7]` in `keyboard.json` and the labels `"0,6"` / `"0,7"` in the VIA JSON, then rebuild.
This README will be updated once it has been checked on a real board.

Drag scroll is momentary (hold), divisor 8 on both axes. Everything is remappable in VIA; the
custom keycodes `DPI` and `Drag` appear under the **Custom** group.

## Flashing

1. Put the trackball into the bootloader: hold **Thumb inner** while plugging in the USB cable
   (Bootmagic), or, with the bottom cover off, bridge the two gold-plated vias on the PCB with
   tweezers while plugging in. A USB drive called `RPI-RP2` appears.
2. Copy `firmware/ploopyco_madromys_rev1_001_ergo_default.uf2` onto that drive. It ejects itself
   and the trackball re-enumerates as a mouse.

There is no reset button on the Madromys. If the board stops enumerating altogether, enter the
bootloader with the vias, copy Raspberry Pi's
[`flash_nuke.uf2`](https://datasheets.raspberrypi.com/soft/flash_nuke.uf2) to `RPI-RP2`, wait
for the drive to return, then flash again.

## Remapping in VIA

The firmware uses PID `0x5C48`, which VIA does not know, so the layout is loaded as a draft:

1. Open https://usevia.app in Chrome or Edge (WebHID is required).
2. Settings (gear) > turn on **Show Design tab**.
3. **Design** tab > **Load Draft Definition** > pick `firmware/via/adept-ergo-8.json`.
4. **Configure** tab > **Authorize device +** > choose *Ploopy Adept Ergo 8*.

Draft definitions live in the browser's storage, so repeat step 3 after clearing site data or on
a new machine. Remapped keys are stored on the trackball and survive replugging.

## Building from source

The keyboard folder lives on the
[`adept-ergo-8button`](https://github.com/jc-skt/qmk_firmware/tree/adept-ergo-8button) branch
of `jc-skt/qmk_firmware`:

```
qmk setup jc-skt/qmk_firmware -b adept-ergo-8button
qmk compile -kb ploopyco/madromys/rev1_001_ergo -km default
```

Or copy `firmware/qmk/rev1_001_ergo/` into `keyboards/ploopyco/madromys/` of any recent QMK
checkout (see `firmware/qmk/README.md`).

## Printing

STL files and print settings are coming soon.

## License

- Hardware, models and documentation: [CC BY-SA 4.0](LICENSE), the same license Ploopy uses for
  the Adept. This is a derivative of Ploopy's design; Ploopy Corporation owns the original.
- Firmware (`firmware/`): [GPL-2.0-or-later](firmware/LICENSE), like QMK.

## Credits

- [Ploopy](https://ploopy.co) for the Adept, the open hardware files and the QMK support.
- [QMK](https://qmk.fm) and [VIA](https://usevia.app).
