# QMK keyboard folder: `ploopyco/madromys/rev1_001_ergomod`

Drop `rev1_001_ergomod/` into `keyboards/ploopyco/madromys/` of a QMK checkout, apply
`0001-madromys-move-pid-to-rev1_001.patch` (QMK merges the parent `info.json` last, so the stock
PID/name set there must move down into `rev1_001/keyboard.json` or they override this variant's
PID `0x5C48` and VIA shows the stock Adept), then:

```
git apply firmware/qmk/0001-madromys-move-pid-to-rev1_001.patch
qmk compile -kb ploopyco/madromys/rev1_001_ergomod -km default
```

The same folder is committed on the branch
[`adept-ergo-mod` of jc-skt/qmk_firmware](https://github.com/jc-skt/qmk_firmware/tree/adept-ergo-mod/keyboards/ploopyco/madromys/rev1_001_ergomod),
which is the easiest way to build it: clone that fork, check out the branch, run the command above.

The VIA keymap is the `default` one (not `via`, which current `qmk lint` refuses);
it still has `VIA_ENABLE = yes`.

This folder is GPL-2.0-or-later, like the rest of QMK (see `../LICENSE`).
