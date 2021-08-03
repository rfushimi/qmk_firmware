#pragma once

/**
 * Forces NKRO during keyboard startup.
 */
#define FORCE_NKRO

/**
 * Flash each side with `-bl dfu-split-{left,right}` to set handedness in memory
 * eg. `qmk flash -bl dfu-split-left -kb bastardkb/tbkmini -km delay`.
 */
#define EE_HANDS

/**
 * Left is primary.
 */
#undef MASTER_RIGHT
#define MASTER_LEFT

/* RGB configuration. */

/**
 * Default RGB mode to use: relaxing mode.
 */
// Unloads all animations but the rainbow swirl, reduces memory footprint.
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_HUE_BREATHING
#define DISABLE_RGB_MATRIX_HUE_PENDULUM
#define DISABLE_RGB_MATRIX_HUE_WAVE
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Disables control of rgb matrix by keycodes (must use code functions to
// control the feature).
#define RGB_MATRIX_DISABLE_KEYCODES

// Rainbow swirl as startup mode.
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#define RGB_MATRIX_STARTUP_SPD 0

// Startup values.
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 255

// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 32

/* One-Shot keys. */

/**
 * Tapping this number of times holds the key until tapped once again.
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TAP_TOGGLE 2

/**
 * Time (in ms) before the one shot key is released.
 * https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
 */
#define ONESHOT_TIMEOUT 1500

/* Tap dances. */

/**
 * If you have a lot of accidental mod activations, crank up the tapping term.
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 *
 * See https://precondition.github.io/home-row-mods#tapping-term.
 */
#define TAPPING_TERM 150

/**
 * Customize the TAPPING_TERM for specific keys.
 */
#define TAPPING_TERM_PER_KEY

/**
 * Disable auto-repeat when pressing key twice, except for one-shot shift.
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
 *
 * See https://precondition.github.io/home-row-mods#tapping-force-hold.
 */
#define TAPPING_FORCE_HOLD_PER_KEY

/*
 * Note that the following two flags, PERMISSIVE_HOLD and
 * IGNORE_MOD_TAP_INTERRUPT, behave differently when both enabled.
 *
 * See https://redirect.is/3mv2fhj for a visual explanation of PERMISSIVE_HOLD
 * and IGNORE_MOD_TAP_INTERRUPT behavior.
 */

/**
 * Must-have for home row mod.
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 (within TAPPING_TERM) ➞ ae
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
 *
 * Ignores key presses that interrupt a mod-tap.
 * See https://precondition.github.io/home-row-mods#ignore-mod-tap-interrupt.
 */
#define IGNORE_MOD_TAP_INTERRUPT

/**
 * Faster mod-tap hold trigger.
 *   Mod🠗 K🠗 K🠕 Mod🠕 (within TAPPING_TERM) ➞ Mod+K
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
 *
 * See https://precondition.github.io/home-row-mods#permissive-hold.
 *
 * TODO(delay): in case of excessive triggers on the home-row, consider using
 * PERMISIVE_HOLD_PER_KEY to target only the thumb cluster's keys.
 */
#define PERMISSIVE_HOLD
