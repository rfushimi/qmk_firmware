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
    OSM_CLR,
    KC_NUM_WORD,
    KC_CAPS_WORD,
    KC_RIGHT_ARROW,
    KC_FAT_RIGHT_ARROW,
};

/** Layer list. */
enum layers_3x5_keymap {
    _DVORAK = 0,
    _NAV,
    _NUM,
    _SYM,
    _NAV_ADJUST,
    _NUM_ADJUST,
    _SYSTEM,
};

// Assert correct layer order.
_Static_assert(_NAV < _NAV_ADJUST, "Invalid layer order");
_Static_assert(_SYM < _NAV_ADJUST, "Invalid layer order");
_Static_assert(_NUM < _NUM_ADJUST, "Invalid layer order");
_Static_assert(_SYM < _NUM_ADJUST, "Invalid layer order");

// Layers.
#define DVORAK DF(_DVORAK)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define NAV_SPC LT(_NAV, KC_SPACE)
#define SYSTEM OSL(_SYSTEM)
#define NUMWRD TG(_NUMWORD)

// Shorthands for readability.
#define ___x___ KC_NO
#define _v_v_v_ KC_TRANSPARENT

// Ctrl-Tab.
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)
#define LAUNCHR G(KC_SPACE)

/** Adaptation of the Dvorak layout. */
// clang-format off
#define DVORAK_split_3x5_2                                                                        \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
     REPEAT,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                                   NUM, NAV_SPC,     KC_LSFT,     SYM
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define NAV_split_3x5_2                                                                           \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5),     ___x___, ___x___, ___x___, KC_BSPC, ___x___, \
    OSM_ALT, OSM_GUI, OSM_CTL, OSM_SFT, ___x___,     ___x___, ___x___,  KC_TAB, ___x___,  KC_ENT, \
    RCS_TAB, CTL_TAB, KC_DOWN,   KC_UP, ___x___,     ___x___, KC_LEFT, KC_RGHT, ___x___, ___x___, \
                               ___x___, _v_v_v_,     LAUNCHR, _______
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define NAV_ADJUST_split_3x5_2                                                                    \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, ___x___, G(KC_C), KC_BSPC,  KC_END, \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, KC_HOME, G(KC_T), G(KC_N),  KC_ENT, \
    ___x___, ___x___, KC_PGDN, KC_PGUP, G(KC_X),     ___x___, ___x___, G(KC_W), G(KC_V), ___x___, \
                               ___x___, _v_v_v_,     ___x___, _v_v_v_
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define NUM_split_3x5_2                                                                           \
    ___x___, KC_COMM,  KC_DOT, ___x___, ___x___,     ___x___,    KC_7,    KC_8,    KC_9, ___x___, \
    KC_PERC, KC_PLUS, KC_MINS,  KC_EQL, ___x___,     ___x___,    KC_4,    KC_5,    KC_6,  KC_ENT, \
    ___x___, KC_TILD, KC_ASTR, KC_SLSH, ___x___,     ___x___,    KC_1,    KC_2,    KC_3, ___x___, \
                               _v_v_v_,  SYSTEM,        KC_0, _______
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define SYM_split_3x5_2                                                                           \
    ___x___,  KC_ESC, KC_QUES, KC_COLN, ___x___,     ___x___,   KC_AT, KC_EXLM, KC_HASH, ___x___, \
    ___x___, KC_LPRN, KC_MINS, KC_RPRN, ___x___,     ___x___, KC_LCBR, KC_UNDS, KC_RCBR, KC_SCLN, \
    ___x___,  KC_DLR, KC_ASTR, KC_SLSH, ___x___,     ___x___, ___x___, KC_CIRC,  KC_GRV, ___x___, \
                               _______, _______,      SYSTEM, _v_v_v_
// clang-format on

/** Remaining symbols. */
// clang-format off
#define NUM_ADJUST_split_3x5_2                                                                    \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, ___x___, ___x___, KC_BSPC, ___x___, \
    ___x___,   KC_LT, KC_MINS,   KC_GT, ___x___,     ___x___, KC_LBRC,  KC_EQL, KC_RBRC,  KC_ENT, \
    ___x___, ___x___, ___x___, ___x___, ___x___,     ___x___, KC_PIPE, KC_BSLS, KC_AMPR, ___x___, \
                               _v_v_v_, ___x___,     ___x___, _v_v_v_
// clang-format on

#if 0
/** Num-word layer. */
// clang-format off
#define NUMWORD_split_3x5_2                                                                       \
    ___x___, KC_COMM,  KC_DOT,    KC_Y, ___x___,     ___x___,    KC_7,    KC_8,    KC_9, ___x___, \
    KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, ___x___,     ___x___,    KC_4,    KC_5,    KC_6, ___x___, \
    ___x___, ___x___,    KC_J,    KC_K, ___x___,     ___x___,    KC_1,    KC_2,    KC_3, ___x___, \
                                NUMWRD,  KC_SPC,        KC_0, ___x___
// clang-format on
#endif

/** Special keycodes/functions. */
// clang-format off
#define SYSTEM_split_3x5_2                                                                        \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG,     RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___,  EE_CLR,      EE_CLR, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT,     QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on
