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
 * The TBK Mini with per-key RGB has 21 LED on each split.
 */
#define RGBLIGHT_SPLIT \
  { 21, 21 }

/**
 * Limit maximum brightness to keep power consumption reasonable, and avoid
 * disconnects.
 */
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 32

/**
 * Default RGB mode to use: relaxing mode.
 */
// Unloads all animations but the rainbow swirl, reduces memory footprint.
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_DEFAULT_SPD 0
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT 4

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
