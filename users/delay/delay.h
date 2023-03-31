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
    _APTMAK,
    _LOWER,
    _UPPER,
    _ADJUST,
    _SYSTEM,
};

// Layers.
#define APTMAK DF(_APTMAK)
#define DVORAK DF(_DVORAK)
#define SYSTEM OSL(_SYSTEM)

// Homerow mods.
#define HMR_A LGUI_T(KC_A)
#define HMR_O LCTL_T(KC_O)
#define HMR_E LSFT_T(KC_E)
#define HMR_U LALT_T(KC_U)

#define HMR_H LALT_T(KC_H)
#define HMR_T LSFT_T(KC_T)
#define HMR_N LCTL_T(KC_N)
#define HMR_S LGUI_T(KC_S)

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
      HMR_A,   HMR_O,   HMR_E,   HMR_U,    KC_I,        KC_D,   HMR_H,   HMR_T,   HMR_N,   HMR_S, \
     REPEAT,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                               TL_LOWR,  KC_SPC,     ___x___, TL_UPPR
// clang-format on

/** Adaptation of the APTmak layout. */
// clang-format off
#define APTMAK_split_3x5_2                                                                        \
       KC_V,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, \
       KC_R,    KC_S,    KC_T,    KC_H,    KC_K,        KC_X,    KC_N,    KC_A,    KC_I,    KC_O, \
    ___x___,    KC_C,    KC_G,    KC_D,    KC_Q,        KC_Z,    KC_M, KC_COMM,  KC_DOT, ___x___, \
                               TL_LOWR,  KC_SPC,        KC_E, TL_UPPR
// clang-format on

/** Mostly navigation focused layer. */
// clang-format off
#define LOWER_split_3x5_2                                                                         \
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB, ___x___,     ___x___, ___x___,   KC_UP, KC_BSPC, ___x___, \
    OSM_GUI, OSM_CTL, OSM_SFT, OSM_ALT, ___x___,     ___x___, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5),     ___x___, ___x___, ___x___, ___x___, ___x___, \
                               _v_v_v_,  SYSTEM,     _______, _______
// clang-format on

/** Numpad and symbols. */
// clang-format off
#define UPPER_split_3x5_2                                                                         \
     KC_GRV, KC_PERC, KC_QUES, KC_COLN,   KC_AT,     KC_TILD, ___x___, ___x___, ___x___, ___x___, \
    KC_EXLM, KC_PLUS, KC_MINS,  KC_EQL, KC_HASH,     KC_CIRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_SCLN, \
    ___x___,  KC_DLR, KC_ASTR, KC_SLSH, ___x___,     ___x___, KC_PIPE, KC_AMPR, KC_BSLS, ___x___, \
                               _______,  KC_ESC,      SYSTEM, _v_v_v_
// clang-format on

/** Another numpad and symbols. */
// clang-format off
#define ADJUST_split_3x5_2                                                                        \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___,     ___x___, KC_LBRC, ___x___, KC_RBRC, ___x___, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___,     ___x___, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___,     ___x___, KC_LCBR,    KC_0, KC_RCBR, ___x___, \
                               _v_v_v_, ___x___,     ___x___, _v_v_v_
// clang-format on

/** Special keycodes/functions. */
// clang-format off
#define SYSTEM_split_3x5_2                                                                        \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG,     RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___,  APTMAK,  DVORAK, ___x___,  EE_CLR,      EE_CLR, ___x___,  DVORAK,  APTMAK, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT,     QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___,     ___x___, ___x___
// clang-format on
