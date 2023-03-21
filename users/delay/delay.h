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
};

/** Tap-dance keycodes. */
enum tap_dances_user {
    TD_ONESHOT_SHIFT,     // Custom OSM Shift with layer on hold.
    TD_ONESHOT_SHORTCUTS_LAYER_SHIFT, // Custom OSM layer with mod on hold.
};

// Layers.
#define SYSTEM OSL(_SYSTEM)
#define SPC_SYM LT(_SYMBOLS, KC_SPACE)
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
#define LAUNCHR G(KC_SPACE)

/** Adaptation of the Dvorak layout. */
// clang-format off
#define DVORAK_split_3x5_2                                                                        \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
    ___x___,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                               MO_LOWR, KC_LSFT,     SPC_SYM, MO_UPPR
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define LOWER_split_3x5_2                                                                         \
    G(KC_C), RCS_TAB, LAUNCHR, CTL_TAB, G(KC_V),     ___x___, ___x___, C(KC_C), C(KC_R), C(KC_L), \
    OSM_ALT, OSM_CTL, OSM_SFT, OSM_GUI, ___x___,     C(KC_D), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5),     ___x___, ___x___,  KC_TAB, ___x___, ___x___, \
                               _v_v_v_,  SYSTEM,      KC_ENT, KC_BSPC
// clang-format on

/** Another numpad and symbols. */
// clang-format off
#define SYMBOLS_split_3x5_2                                                                       \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,      KC_GRV, KC_CIRC, KC_QUES,  KC_DLR,   KC_AT, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     KC_PERC, KC_LPRN, KC_MINS, KC_RPRN, KC_SCLN, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___,     KC_HASH, KC_LCBR, KC_EXLM, KC_RCBR, ___x___, \
                                KC_ESC,    KC_0,     _v_v_v_,  SYSTEM
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define UPPER_split_3x5_2                                                                         \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,     ___x___, KC_PLUS, KC_SLSH, KC_ASTR, KC_TILD, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     KC_PIPE,   KC_LT, KC_UNDS,   KC_GT, KC_AMPR, \
    ___x___,    KC_1,    KC_2,    KC_3, KC_COLN,     KC_BSLS, KC_LBRC,  KC_EQL, KC_RBRC, ___x___, \
                                KC_ESC,    KC_0,      SYSTEM, _v_v_v_
// clang-format on

/** Special keycodes/functions. */
// clang-format off
#define SYSTEM_split_3x5_2                                                                        \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG,     RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___,  EE_CLR,      EE_CLR, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT,     QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on
