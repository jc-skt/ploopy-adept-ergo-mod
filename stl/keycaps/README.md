# Keycaps

Eight sculpted keycaps for the ergo top, one per button. They are derived from
[KLP Lamé](https://github.com/braindefender/KLP-Lame-Keycaps) by braindefender (CC BY-SA 4.0):
the dish of the Lamé **[MX] Normal** cap (finger keys) and the lip-dish-fall profile of the
**[MX] Thumb** cap were measured and rebuilt as parametric sweeps on the footprint of each button
of this top, so every cap fills its own outline instead of being a 1U/1.5U square. They have no
switch stem; each cap sits on the flat pad of its flex button.

## Files

| File | Physical button | Profile |
|---|---|---|
| `left-top.stl` | Left top | Lamé Normal dish on a 20 mm tower |
| `left-mid.stl` | Left middle | Lamé Normal dish on a 20 mm tower |
| `thumb-left.stl` | Thumb outer (left click) | Lamé Thumb: north lip, centred dish, south fall |
| `thumb-right.stl` | Thumb inner (drag scroll) | Lamé Thumb, with a clearance arc for the ball |
| `right-top.stl` | Right top | Lamé Normal dish |
| `right-middle.stl` | Right middle | Lamé Normal dish |
| `right-bot-left.stl` | Right bottom inner (DPI) | Lamé Normal dish |
| `right-bot-right.stl` | Right bottom outer (middle click) | Lamé Normal dish |

Names match the bodies in the Fusion 360 source (`top / keycaps / thumb`, `right-side`, `left-side`).

## Parametric adjustment

The caps are built from user parameters in the Fusion 360 archive in [`../../fusion/`](../../fusion/).
Open the file, **Modify > Change Parameters**, edit a value, let the model recompute, then export
the changed body with **right-click body > Save As Mesh** (STL). The dish is a sweep along a
path made of conic curves, so it recomputes cleanly across the ranges listed; the rim fillets are
the first thing to fail if a value is pushed too far (the feature turns red; put the value back and
it heals).

All values in mm. "Top plane" is the flat top of the cap before the dish is cut.

### Shared

| Parameter | Default | What it does |
|---|---|---|
| `kc_taper` | 0.5 | Inset of the cap's top outline relative to its base outline: the side walls lean in by this much. 0 gives vertical walls. |

### Thumb caps (`thumb-left`, `thumb-right`)

| Parameter | Default | What it does |
|---|---|---|
| `kc_thumb_height` | 4.38 | Height of the cap's top plane above the pad. |
| `kc_thumb_scoop` | 1.1 | Dish depth below the top plane at mid-length (the floor). The north lip rises back to the top plane. |
| `kc_thumb_drop` | 2 | How far the south top edge sits below the top plane: the "fall" your thumb slides down. Must be larger than `kc_thumb_scoop`. |
| `kc_thumb_overrun` | 3 | How far the dish sweep path runs past both cap ends. Leave alone unless the dish stops short of an edge. |
| `kc_thumb_rim` | 1.1 | Rim roll: fillet of the top edge loop, applied before the dish cut. Larger = softer edge. |
| `kc_thumb_break` | 1 | Edge break where the dish meets the rolled rim (after the cut). |

### Right-side caps (`right-top`, `right-middle`, `right-bot-left`, `right-bot-right`)

| Parameter | Default | What it does |
|---|---|---|
| `kc_right_height` | 6 | Height of the top plane above the pad. |
| `kc_right_scoop` | 0.8 | Dish depth at the cap centre below the top plane (the Lamé Normal measures 0.78). Verified 0.3 to 1.5. |
| `kc_right_overrun` | 3 | Dish sweep overrun past both cap ends (also sets the tool height). Leave alone. |
| `kc_right_rim` | 1 | Rim roll fillet before the dish cut. Verified up to about 1.5; 1.6 exceeds the smallest cap's corners. |
| `kc_right_break` | 0.25 | Edge break where the dish meets the rolled rim. |

### Left-side caps (`left-top`, `left-mid`)

Same recipe as the right side with its own set of values, so the two sides can differ.

| Parameter | Default | What it does |
|---|---|---|
| `kc_left_height` | 20 | Height of the top plane above the pad. These two are tall towers; verified 8 to 24. |
| `kc_left_scoop` | 0.8 | Dish depth at the cap centre. Verified 0.3 to 1.5. |
| `kc_left_overrun` | 3 | Dish sweep overrun. Leave alone. |
| `kc_left_rim` | 1 | Rim roll fillet before the dish cut. Verified up to 1.5. |
| `kc_left_break` | 0.25 | Edge break where the dish meets the rolled rim. |

`kc_btn1_height` also appears in the parameter list but drives nothing; ignore it.

What is **not** parametric: the cap outlines (they are projected from the top's button recesses,
so they follow the top), the dish curvature relative to cap width (the dish tool is a circle
through the cap's own edge points, so a wider cap automatically gets a wider bowl), and the thumb
caps' 10° rotation.

## Printing

Print each cap dish-up on its flat base. The dishes are shallow (0.8 mm on the finger caps), so
use the finest layer height your printer manages comfortably.

## License

CC BY-SA 4.0, like the original KLP Lamé and the rest of this repository (see [`../../LICENSE`](../../LICENSE)).
