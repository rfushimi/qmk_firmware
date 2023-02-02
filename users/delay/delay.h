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

#if defined(KEYBOARD_bastardkb_charybdis)
#    include "charybdis.h"
#elif defined(KEYBOARD_bastardkb_dilemma)
#    include "dilemma.h"
#endif

/**
 * \brief Custom keycodes.
 *
 * Use `SAFE_RANGE_KEYMAP` for keymap specific codes, instead of `SAFE_RANGE`.
 */
enum keycodes_user {
#ifdef POINTING_DEVICE_ENABLE
#    if defined(KEYBOARD_bastardkb_charybdis)
    KEYCODE_USER_BEGIN = CHARYBDIS_SAFE_RANGE,
#    elif defined(KEYBOARD_bastardkb_dilemma)
    KEYCODE_USER_BEGIN = DILEMMA_SAFE_RANGE,
#    else
    KEYCODE_USER_BEGIN = SAFE_RANGE,
#    endif
#else
    KEYCODE_USER_BEGIN = SAFE_RANGE,
#endif
    // Custom keycodes.
    SAFE_RANGE_KEYMAP = KEYCODE_USER_BEGIN,
    OSM_ALT,
    OSM_CTL,
    OSM_GUI,
    OSM_SFT,
};

enum layers_3x5_keymap {
    _DVORAK = 0,
    _NAV,
    _SYM,
    _DEV,
    _SYSTEM,
    _SPECIAL,
};

// Layers.
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define DEV MO(_DEV)
#define SYSTEM OSL(_SYSTEM)
#define SPECIAL MO(_SPECIAL)

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
    KC_COLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                                   NAV, KC_LSFT,  KC_SPC,     SYM
// clang-format on

/**
 * \brief Navigation layer.
 */
// clang-format off
#define NAV_split_3x5_2                                                                       \
    ___x___, RCS_TAB,  KC_TAB, CTL_TAB, ___x___, ___x___, KC_HOME,   KC_UP,  KC_END, DEL_WRD, \
    OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, \
    ___x___, KC_LBRC, KC_LCBR, KC_LPRN, ___x___, ___x___, KC_RPRN, KC_RCBR, KC_RBRC, KC_SCLN, \
                               _v_v_v_,  SYSTEM,  KC_ENT, _______
// clang-format on

/**
 * \brief Numpad and symbols.
 */
// clang-format off
#define SYM_split_3x5_2                                                                       \
     KC_ESC,    KC_7,    KC_8,    KC_9, KC_BSLS, KC_HASH, KC_CIRC, KC_UNDS,  KC_DLR,  KC_GRV, \
     KC_EQL,    KC_4,    KC_5,    KC_6, KC_AMPR, KC_EXLM, KC_PLUS, KC_MINS,   KC_AT, KC_QUES, \
    ___x___,    KC_1,    KC_2,    KC_3, KC_PIPE, KC_PERC, KC_COLN, KC_SLSH, KC_ASTR, ___x___, \
                               _______,    KC_0,  SYSTEM, _v_v_v_
// clang-format on

/**
 * \brief Others.
 */
// clang-format off
#define DEV_split_3x5_2                                                                       \
    ___x___, KC_HASH, KC_EXLM, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, OSM_SFT, OSM_CTL, OSM_ALT, OSM_GUI, \
     KC_EQL,   KC_LT, KC_MINS,   KC_GT, ___x___, ___x___,  KC_DOT, KC_SLSH, KC_TILD, ___x___, \
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
 * \brief Window management layer, with convenience left-hand shortcuts for right-hand mouse.
 */
// clang-format off
#define SPECIAL_split_3x5_2                                                                   \
    ___x___, RCS_TAB, LAUNCHR, CTL_TAB, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5), A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5), \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
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
                k33, k34,  SPECIAL,  KC_LCTL, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define NAV_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(NAV_split_3x5_2)
#define SYM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYM_split_3x5_2)
#define DEV_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DEV_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
#define SPECIAL_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SPECIAL_split_3x5_2)
