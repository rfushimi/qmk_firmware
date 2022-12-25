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
};

enum layers_3x5_keymap {
    _DVORAK = 0,
    _APTmak, // Alternative layout.
    _APTv3,  // Alternative layout.
    _RSTHD,  // Alternative layout.
    _MOTION, // Navigation.
    _WINMGT, // Window management.
    _SYMBOL, // Symbols.
    _NUMBER, // Numbers.
    _SYSTEM, // Special.
};

// Layers.
#define BSPC_MO LT(_MOTION, KC_BACKSPACE)
#define BSP_SFT MT(MOD_LSFT, KC_BACKSPACE)
#define ENT_CTL MT(MOD_LCTL, KC_ENTER)
#define ENT_NUM LT(_NUMBER, KC_ENTER)
#define ENT_SYM LT(_SYMBOL, KC_ENTER)
#define ESC_MO LT(_MOTION, KC_ESCAPE)
#define E_MO LT(_MOTION, KC_E)
#define E_SYM LT(_SYMBOL, KC_E)
#define MOTION MO(_MOTION)
#define NUMBER MO(_NUMBER)
#define WINMGT MO(_WINMGT)
#define SPC_MO LT(_MOTION, KC_SPACE)
#define SPC_SYM LT(_SYMBOL, KC_SPACE)
#define SYSTEM OSL(_SYSTEM)

// Oneshot mods.
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)

// Ctrl-Tab.
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)

// Shorthands for readability.
#define ___x___ KC_NO
#define GA(key) G(A(KC_##key))

#define DEL_WRD C(KC_BACKSPACE)
#define ALT_SPC A(KC_SPACE)
#define ALT_ENT A(KC_ENTER)
#define LAUNCHR G(KC_SPACE)

#define WS_LEFT G(A(KC_LEFT))
#define WS_RGHT G(A(KC_RIGHT))

#define ALPHA_APTmak DF(_APTmak)
#define ALPHA_APTv3 DF(_APTv3)
#define ALPHA_DVORAK DF(_DVORAK)
#define ALPHA_RSTHD DF(_RSTHD)
#define APTmak ALPHA_APTmak
#define APTv3 ALPHA_APTv3
#define DVORAK ALPHA_DVORAK
#define RSTHD ALPHA_RSTHD

/**
 * \brief Adaptation of the Dvorak layout.
 */
// clang-format off
#define DVORAK_split_3x5_2                                                                    \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
    KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                               KC_LSFT,  SPC_MO, SPC_SYM, ENT_NUM
// clang-format on

/**
 * \brief Adaptation of the RSTHD layout.
 */
// clang-format off
#define RSTHD_split_3x5_2                                                                     \
       KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,    KC_Z,    KC_L, KC_COMM,    KC_U,    KC_Q, \
       KC_R,    KC_S,    KC_T,    KC_H,    KC_D,    KC_M,    KC_N,    KC_A,    KC_I,    KC_O, \
    KC_SLSH,    KC_V,    KC_G,    KC_P,    KC_B,    KC_X,    KC_W,  KC_DOT, KC_COLN, KC_QUOT, \
                               KC_LSFT,    E_MO, SPC_SYM, ENT_NUM
// clang-format on

/**
 * \brief Adaptation of Apsu's APTmak layout.
 */
// clang-format off
#define APTmak_split_3x5_2                                                                    \
       KC_V,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, \
       KC_R,    KC_S,    KC_T,    KC_H,    KC_K,    KC_X,    KC_N,    KC_A,    KC_I,    KC_O, \
    KC_LSFT,    KC_C,    KC_G,    KC_D,    KC_Q,    KC_Z,    KC_M, KC_COMM,  KC_DOT, KC_LSFT, \
                               KC_LCTL,  SPC_MO,   E_SYM, ENT_NUM
// clang-format on

/**
 * \brief Adaptation of the APTv3 layout.
 */
// clang-format off
#define APTv3_split_3x5_2                                                                     \
       KC_W,    KC_G,    KC_D,    KC_F,    KC_B,    KC_Q,    KC_L,    KC_U,    KC_O,    KC_Y, \
       KC_R,    KC_S,    KC_T,    KC_H,    KC_K,    KC_J,    KC_N,    KC_E,    KC_A,    KC_I, \
       KC_X,    KC_C,    KC_M,    KC_P,    KC_V,    KC_Z, KC_COMM,  KC_DOT, KC_QUOT, KC_COLN, \
                               KC_LSFT,  ESC_MO, SPC_SYM, ENT_NUM
// clang-format on

/**
 * \brief Navigation layer.
 */
// clang-format off
#define MOTION_split_3x5_2                                                                    \
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB, ___x___, ___x___, ___x___,   KC_UP, ___x___, ___x___, \
    OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, \
    ___x___, ___x___, KC_DOWN,   KC_UP, ___x___, ___x___, KC_LEFT, KC_RGHT, ___x___, ___x___, \
                                SYSTEM, _______, ___x___, ___x___
// clang-format on

/**
 * \brief Window management layer, with convenience left-hand shortcuts for right-hand mouse.
 */
// clang-format off
#define WINMGT_split_3x5_2                                                                    \
      GA(1),   GA(2),   GA(3),   GA(4),   GA(5), WS_LEFT,   KC_F7,   KC_F8,   KC_F9, WS_RGHT, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5), ___x___,   KC_F4,   KC_F5,   KC_F6, ___x___, \
    KC_LSFT, ___x___, ___x___, ___x___, ___x___, ___x___,   KC_F1,   KC_F2,   KC_F3, KC_LSFT, \
                               ___x___, ___x___, ALT_SPC, ALT_ENT
// clang-format on

/**
 * \brief Symbols.
 */
// clang-format off
#define SYMBOL_split_3x5_2                                                                    \
     KC_ESC,   KC_LT, KC_QUES,   KC_GT, KC_COLN, ___x___, KC_LBRC, KC_PERC, KC_RBRC,  KC_GRV, \
    KC_EXLM, KC_PLUS, KC_MINS,  KC_EQL, KC_HASH, KC_CIRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_SCLN, \
    KC_TILD, KC_BSLS, KC_ASTR, KC_SLSH, KC_AMPR, KC_PIPE, KC_LCBR,  KC_DLR, KC_RCBR,   KC_AT, \
                               DEL_WRD, KC_BSPC, _______,  SYSTEM
// clang-format on

/**
 * \brief Numrow.
 */
// clang-format off
#define NUMBER_split_3x5_2                                                                    \
    ___x___,    KC_7,    KC_8,    KC_9, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___,    KC_4,    KC_5,    KC_6, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___,    KC_1,    KC_2,    KC_3, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
                                KC_DOT,    KC_0, ___x___, _______
// clang-format on

/**
 * \brief Special keycodes/functions.
 */
// clang-format off
#define SYSTEM_split_3x5_2                                                                    \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG, RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
      RSTHD,   APTv3,  APTmak,  DVORAK,  EE_CLR,  EE_CLR,  DVORAK,  APTmak,   APTv3,   RSTHD, \
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
                k33, k34,   WINMGT,  KC_LCTL, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define APTmak_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(APTmak_split_3x5_2)
#define APTv3_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(APTv3_split_3x5_2)
#define RSTHD_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(RSTHD_split_3x5_2)
#define MOTION_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(MOTION_split_3x5_2)
#define WINMGT_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(WINMGT_split_3x5_2)
#define NUMBER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(NUMBER_split_3x5_2)
#define SYMBOL_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYMBOL_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
