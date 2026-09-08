# QMK keyboard folder: `ploopyco/madromys/rev1_001_ergo`

Drop `rev1_001_ergo/` into `keyboards/ploopyco/madromys/` of a QMK checkout, then:

```
qmk compile -kb ploopyco/madromys/rev1_001_ergo -km ergo
```

The same folder is committed on the branch
[`adept-ergo-8button` of jc-skt/qmk_firmware](https://github.com/jc-skt/qmk_firmware/tree/adept-ergo-8button/keyboards/ploopyco/madromys/rev1_001_ergo),
which is the easiest way to build it: clone that fork, check out the branch, run the command above.

The keymap is called `ergo` (not `via`) because current `qmk lint` refuses keymaps named `via`;
it still has `VIA_ENABLE = yes`.

This folder is GPL-2.0-or-later, like the rest of QMK (see `../LICENSE`).
