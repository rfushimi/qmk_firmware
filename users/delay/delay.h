/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/** Custom keycodes. */
enum keycodes_user {
    SAFE_RANGE_KEYMAP = QK_USER,
    REPEAT,
    OSM_ALT,
    OSM_CTL,
    OSM_GUI,
    OSM_SFT,
    KC_RIGHT_ARROW,
    KC_FAT_RIGHT_ARROW,
};

/** Layer list. */
enum layers_3x5_keymap {
    _DVORAK = 0,
    _LOWER,
    _UPPER,
    _SYMBOLS,
    _SYSTEM,
    _SHORTCUTS,
};

/** Tap-dance keycodes. */
enum tap_dances_user {
    TD_ONESHOT_SHIFT,     // Custom OSM Shift with layer on hold.
    TD_ONESHOT_SHORTCUTS_LAYER_SHIFT, // Custom OSM layer with mod on hold.
};

// Layers.
#define SYSTEM OSL(_SYSTEM)
#define SPC_SYM LT(_SYMBOLS, KC_SPACE)
#define TD_SHORTCUTS TD(TD_ONESHOT_SHORTCUTS_LAYER_SHIFT)
#define MO_LOWER MO(_LOWER)
#define MO_UPPER MO(_UPPER)

// Shorthands for readability.
#define ___x___ KC_NO
#define _v_v_v_ KC_TRANSPARENT
#define TD_SHRT TD_SHORTCUTS
#define MO_LOWR MO_LOWER
#define MO_UPPR MO_UPPER

// Ctrl-Tab.
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)

#define DEL_WRD C(KC_BACKSPACE)
#define LAUNCHR G(KC_SPACE)

/** Adaptation of the Dvorak layout. */
// clang-format off
#define DVORAK_split_3x5_2                                                                        \
    KC_COLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
    ___x___,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V, ___x___, \
                               MO_LOWR, TD_SHRT,     SPC_SYM, MO_UPPR
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define LOWER_split_3x5_2                                                                         \
    ___x___, RCS_TAB, LAUNCHR, CTL_TAB, ___x___,     ___x___, KC_HOME,   KC_UP,  KC_END, ___x___, \
    OSM_ALT, OSM_CTL, OSM_SFT, OSM_GUI, ___x___,     ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, ___x___, ___x___, ___x___, ___x___, \
                               _v_v_v_,  SYSTEM,     _______, _______
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define UPPER_split_3x5_2                                                                         \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,     ___x___, KC_PLUS, KC_SLSH, KC_ASTR, KC_TILD, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     KC_PIPE,   KC_LT, KC_UNDS,   KC_GT, KC_AMPR, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___,     KC_BSLS, KC_LBRC,  KC_EQL, KC_RBRC, ___x___, \
                               _______,    KC_0,      SYSTEM, _v_v_v_
// clang-format on

/** Another numpad and symbols. */
// clang-format off
#define SYMBOLS_split_3x5_2                                                                       \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,      KC_GRV, KC_CIRC, KC_QUES,  KC_DLR,   KC_AT, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     KC_PERC, KC_LPRN, KC_MINS, KC_RPRN, KC_SCLN, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___,     KC_HASH, KC_LCBR, KC_EXLM, KC_RCBR, ___x___, \
                               _______,    KC_0,     _v_v_v_,  SYSTEM
// clang-format on

/** Special keycodes/functions. */
// clang-format off
#define SYSTEM_split_3x5_2                                                                        \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG,     RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___,  EE_CLR,      EE_CLR, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT,     QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on

/** Convenience shortcuts. */
// clang-format off
#define SHORTCUTS_split_3x5_2                                                                     \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, ___x___, C(KC_C), C(KC_R), C(KC_L), \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5),     C(KC_D), OSM_GUI, OSM_SFT, OSM_CTL, OSM_ALT, \
    ___x___, G(KC_X), G(KC_C), G(KC_V), ___x___,     ___x___, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on

/**
 * Converts a 3x5_2 layout into the more common 3x5_3 layout.
 *
 * In other words, converts a split-34 keymap into a split-36 one.
 */
// clang-format off
#define _LAYOUT_split_3x5_2_to_split_3x5_3(                  \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                          k33, k34, k35, k36)                \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                k33, k34,   REPEAT,  KC_LCTL, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define LOWER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(LOWER_split_3x5_2)
#define UPPER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(UPPER_split_3x5_2)
#define SYMBOLS_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYMBOLS_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
#define SHORTCUTS_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SHORTCUTS_split_3x5_2)
