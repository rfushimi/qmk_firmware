# HC Macropad

This keyboard is an custom edition for an internal event.

The design is available at [0xcharly/hc-macropad](https://github.com/0xcharly/hc-macropad).

## Building

Building the firmware using the QMK CLI:

```sh
qmk compile [--clean] [-j 0] -kb hc_macropad -km default
```

See [QMK's Getting Started](https://docs.qmk.fm/newbs_getting_started) guide for
instructions to setup the build environment.

## Flashing

The macropad uses a UF2 firmware which is trivial to flash: simply put the board
in bootloader mode (by double tapping the reset button) and drag n' drop the f/w
file into the mount point that appears on your host.


> [!NOTE]
>
> A shorthand for compiling and flashing in one command exists:
>
> ```
> qmk flash [--clean] [-j 0] -kb hc_macropad -km default
> ```

