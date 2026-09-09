# Test firmware

`ploopyco_madromys_rev1_001_ergo_test_rclick_v1.uf2` maps **all eight buttons to right click**.
Flash it like the real firmware (hold Thumb inner while plugging in, copy onto the `RPI-RP2`
drive), then press each button: a context menu should open for every one. It checks that all
eight pads register; it does not tell the buttons apart. Flash the real firmware afterwards.

## Pin finder

`ploopyco_madromys_pinfinder_v2.uf2` treats **every spare RP2040 GPIO** as a button and
types a letter when that pin is pulled to ground. Flash it, open a text editor, press each
button (or bridge each switch pad to ground) and read the letter:

| Letter | Pin | Letter | Pin | Letter | Pin |
|---|---|---|---|---|---|
| | | i | GP15 | q | GP23 |
| b | GP3 | j | GP16 | r | GP24 |
| c | GP4 | k | GP17 | s | GP25 |
| d | GP6 | l | GP18 | t | GP26 |
| e | GP8 | m | GP19 | u | GP27 |
| f | GP10 | n | GP20 | v | GP28 |
| g | GP11 | o | GP21 | w | GP29 |
| h | GP14 | p | GP22 | | |

Expected from the R1.001 schematic: SW1 k, SW2 m, SW3 q, SW4 o, SW6 g, SW8 i, and SW5/SW7 some
pair of c/h. A letter that repeats by itself means that pin is tied low on the board. This
firmware uses USB PID `0x5C49` so it never collides with the real one. GP1 is not scanned: on the
author's board it reads low at power-up (v1 of this file scanned it as the Bootmagic key and the
board fell into the bootloader on every plug-in). Bootmagic is on GP15 (Thumb inner), as in the
real firmware, so holding Thumb inner while plugging in still reaches the bootloader.
