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

/**
 * \brief Custom keycodes.
 */
enum keycodes_user {
    // Custom keycodes.
    SAFE_RANGE_KEYMAP = QK_USER,
    OSM_ALT,
    OSM_CTL,
    OSM_GUI,
    OSM_SFT,
};

enum layers_3x5_keymap {
    _DVORAK = 0,
    _LOWER,
    _UPPER,
    _ADJUST,
    _SYSTEM,
};

// Layers.
#define SYSTEM OSL(_SYSTEM)

// Ctrl-Tab.
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)

// Shorthands for readability.
#define ___x___ KC_NO
#define _v_v_v_ KC_TRANSPARENT

#define DEL_WRD C(KC_BACKSPACE)
#define LAUNCHR A(KC_P)

/**
 * \brief Adaptation of the Dvorak layout.
 */
// clang-format off
#define DVORAK_split_3x5_2                                                                    \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
    ___x___,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                               TL_LOWR, KC_LSFT,  KC_SPC, TL_UPPR
// clang-format on

/**
 * \brief Mostly navigation focused layer.
 */
// clang-format off
#define LOWER_split_3x5_2                                                                       \
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB, ___x___, ___x___, KC_HOME,   KC_UP,  KC_END, ___x___, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5), ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, \
    OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
                               _v_v_v_,  SYSTEM,  KC_ENT, _______
// clang-format on

/**
 * \brief Numpad and symbols.
 */
// clang-format off
#define UPPER_split_3x5_2                                                                       \
    KC_PERC,    KC_7,    KC_8,    KC_9, KC_BSLS, ___x___, KC_CIRC,   KC_AT,  KC_DLR,  KC_GRV, \
    KC_COLN,    KC_4,    KC_5,    KC_6, KC_AMPR, ___x___, KC_PLUS,  KC_ESC, KC_MINS, KC_UNDS, \
    KC_QUES,    KC_1,    KC_2,    KC_3, KC_PIPE, ___x___, KC_HASH, KC_SLSH, KC_ASTR, KC_EXLM, \
                               _______,    KC_0,  SYSTEM, _v_v_v_
// clang-format on

/**
 * \brief Others.
 */
// clang-format off
#define ADJUST_split_3x5_2                                                                       \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___, KC_LBRC, KC_LPRN, KC_LCBR, ___x___, ___x___, KC_RCBR, KC_RPRN, KC_RBRC, KC_SCLN, \
      KC_LT,  KC_EQL, KC_MINS,   KC_GT, ___x___, ___x___,  KC_DOT, KC_SLSH, KC_TILD, ___x___, \
                               _v_v_v_, ___x___, ___x___, _v_v_v_
// clang-format on

/**
 * \brief Special keycodes/functions.
 */
// clang-format off
#define SYSTEM_split_3x5_2                                                                    \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG, RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___,  EE_CLR,  EE_CLR, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT, QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___, ___x___, ___x___
// clang-format on

/**
 * \brief Converts a 3x5_2 layout into the more common 3x5_3 layout.
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
                k33, k34,  KC_LGUI,  KC_LCTL, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define LOWER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(LOWER_split_3x5_2)
#define UPPER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(UPPER_split_3x5_2)
#define ADJUST_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(ADJUST_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
