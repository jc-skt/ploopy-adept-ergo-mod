// Copyright 2026 jc-skt
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Physical order (LAYOUT_ergo). This is the "default" keymap (VIA enabled); qmk lint rejects keymaps named "via".
//   left top, left middle, thumb outer, thumb inner,
//   right top, right middle, right bottom inner, right bottom outer
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergo(
        MS_BTN5,     // left top            SW1  GP17  forward
        MS_BTN4,     // left middle         SW2  GP19  back
        MS_BTN1,     // thumb outer         SW5  GP4   left click
        DRAG_SCROLL, // thumb inner         SW8  GP15  drag scroll (hold)
        KC_LSFT,     // right top           SW4  GP21  shift (hold)
        MS_BTN2,     // right middle        SW3  GP23  right click
        DPI_CONFIG,  // right bottom inner  SW6  GP11  cycle DPI
        MS_BTN3      // right bottom outer  SW7  GP14  middle click
    ),
    // GP4 = SW5 and GP14 = SW7 confirmed on hardware 2026-09-08 (pin-finder firmware).
};
