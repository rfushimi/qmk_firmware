# @wes's userspace

## Compile

```sh
$ qmk compile [-j 0] [-c] -kb bastardkb/tbkmini/v2/splinky_3 -km wes
```

## Flash

The following command also compiles the keymap if needed. Flash both sides
separatly with the same firmware. Double-tap the reset button on the adapter to
enter bootloader.

TODO: Add `QK_BOOT` keycode to enter bootloader from the firmware.

```sh
$ qmk flash [-j 0] [-c] -kb bastardkb/tbkmini/v2/splinky_3 -km wes
```

## `qmk-compile` and `qmk-flash` options

- `-j 0`: parallel compilation
- `-c`: runs `qmk clean` before compiling

## Modifying the keymap

The bulk of the keymap is in `/users/wes/wes.h`.

When adding/removing layers, update `/keyboards/bastardkb/tbkmini/keymaps/wes/keymap.c` accordingly.
