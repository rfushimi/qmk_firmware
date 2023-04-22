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
    KC_RIGHT_ARROW,
    KC_FAT_RIGHT_ARROW,
};

/** Layer list. */
enum layers_3x5_keymap {
    _DVORAK = 0,
    _LOWER,
    _UPPER,
    _ADJUST,
    _SYSTEM,
};

// Layers.
#define DVORAK DF(_DVORAK)
#define SYSTEM OSL(_SYSTEM)

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
                               TL_LOWR,  KC_SPC,     KC_LSFT, TL_UPPR
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define LOWER_split_3x5_2                                                                         \
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB, ___x___,     ___x___, ___x___,   KC_UP, KC_BSPC, ___x___, \
    OSM_ALT, OSM_GUI, OSM_CTL, OSM_SFT, OSM_CLR,     ___x___, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5),     ___x___, ___x___, ___x___, ___x___, ___x___, \
                               _v_v_v_,  SYSTEM,     _______, _______
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define UPPER_split_3x5_2                                                                         \
    KC_PERC,  KC_ESC, KC_QUES, KC_COLN,   KC_AT,     _______, ___x___, KC_CIRC, KC_TILD,  KC_GRV, \
    KC_EXLM, KC_PLUS, KC_MINS,  KC_EQL, KC_HASH,     _______, KC_LPRN, KC_UNDS, KC_RPRN, KC_SCLN, \
    ___x___,  KC_DLR, KC_ASTR, KC_SLSH, ___x___,     ___x___, KC_PIPE, KC_AMPR, KC_BSLS, ___x___, \
                               _______, _______,      SYSTEM, _v_v_v_
// clang-format on

/** Another numpad and symbols. */
// clang-format off
#define ADJUST_split_3x5_2                                                                        \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,     ___x___, KC_LBRC, ___x___, KC_RBRC, ___x___, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     ___x___, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___,     ___x___, KC_LCBR,    KC_0, KC_RCBR, ___x___, \
                               _v_v_v_, ___x___,     ___x___, _v_v_v_
// clang-format on

/** Special keycodes/functions. */
// clang-format off
#define SYSTEM_split_3x5_2                                                                        \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG,     RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___,  EE_CLR,      EE_CLR, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT,     QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on
