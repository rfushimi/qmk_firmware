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

#include "features/tap_dance.h"
#include "quantum.h"

#if defined(KEYBOARD_bastardkb_charybdis)
#include "charybdis.h"
#elif defined(KEYBOARD_bastardkb_dilemma)
#include "dilemma.h"
#endif

/**
 * \brief Custom keycodes.
 *
 * Use `SAFE_RANGE_KEYMAP` for keymap specific codes, instead of `SAFE_RANGE`.
 */
enum keycodes_user {
#ifdef POINTING_DEVICE_ENABLE
#if defined(KEYBOARD_bastardkb_charybdis)
  KEYCODE_USER_BEGIN = CHARYBDIS_SAFE_RANGE,
#elif defined(KEYBOARD_bastardkb_dilemma)
  KEYCODE_USER_BEGIN = DILEMMA_SAFE_RANGE,
#elif defined(VIA_ENABLE)
  KEYCODE_USER_BEGIN = USER00,
#else
  KEYCODE_USER_BEGIN = SAFE_RANGE,
#endif
#else
  KEYCODE_USER_BEGIN = SAFE_RANGE,
#endif
  // Oneshot mods.
  OSM_ALT = KEYCODE_USER_BEGIN,
  OSM_CTL,
  OSM_GUI,
  OSM_SFT,
  // Custom keycodes.
  CK_DOUBLE_COLON,
  SAFE_RANGE_KEYMAP,
};

// This keymap uses ASCG home row mods.
//
//             Left hand                          Right hand
// ╭───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────╮
// │  Alt  │  Gui  │ Ctrl  │ Shift │   │ Shift │ Ctrl  │  Gui  │  Alt  │
// ╰───────┴───────┴───────┴───────╯   ╰───────┴───────┴───────┴───────╯

#ifdef KEYMAP_DELAY_HOMEROW
// Home row mods for Dvorak layer.
#define HOME_A LALT_T(KC_A)
#define HOME_O LGUI_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LGUI_T(KC_N)
#define HOME_S RALT_T(KC_S)
#else
#define HOME_A KC_A
#define HOME_O KC_O
#define HOME_E KC_E
#define HOME_U KC_U
#define HOME_H KC_H
#define HOME_T KC_T
#define HOME_N KC_N
#define HOME_S KC_S
#endif  // KEYMAP_DELAY_HOMEROW

#define VIM_TAB_LEFT LALT(LSFT(KC_LEFT))
#define VIM_TAB_RIGHT LALT(LSFT(KC_RIGHT))
#define VIM_TERMINAL LCTL(LALT(KC_T))
#define VIM_TERMINAL_ESCAPE LCTL(KC_ESC)
#define VIM_CMP_DOWN LCTL(KC_J)
#define VIM_CMP_UP LCTL(KC_K)
#define VIM_CMP_SELECT LCTL(KC_Y)

#define SC_PASTE_NO_FORMAT LGUI(S(KC_V))
#define SC_LAUNCHER LGUI(KC_SPACE)
#define WS_PREVIOUS LCTL(LALT(KC_LEFT))
#define WS_NEXT LCTL(LALT(KC_RIGHT))

#define CK_ELLIPSIS LALT(KC_SEMICOLON)

// Shorthands.
#define SC_PSTE SC_PASTE
#define LAUNCHR SC_LAUNCHER
#define WS_PREV WS_PREVIOUS
#define CK_ELPS CK_ELLIPSIS
#define CK_DCOL CK_DOUBLE_COLON
#define VIM_T_L VIM_TAB_LEFT
#define VIM_T_R VIM_TAB_RIGHT
#define V_CMP_D VIM_CMP_DOWN
#define V_CMP_U VIM_CMP_UP
#define V_CMP_S VIM_CMP_SELECT
#define VIMTERM VIM_TERMINAL
#define VIMTESC VIM_TERMINAL_ESCAPE

/**
 * \brief Similar to `_kb`, `_user`, `_user_keymap`, and other variants, but for
 * keymaps.
 *
 * docs.qmk.fm/using-qmk/software-features/feature_userspace#customized-functions.
 */
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
void keyboard_post_init_keymap(void);
void oneshot_locked_mods_changed_keymap(uint8_t mods);
void shutdown_keymap(void);

enum layers_keymap {
  _DVORAK = 0,
  _MOTION,  // Navigation.
  _SYMBOL,  // Symbols.
  _NUMBER,  // Numbers.
  _SYSTEM,  // Special.
};

// Layers.
#define MOTION MO(_MOTION)
#define NUMBER MO(_NUMBER)
#define SYMBOL MO(_SYMBOL)
#define SYSTEM OSL(_SYSTEM)
#define SPC_MO LT(_MOTION, KC_SPACE)
#define ESC_SYM LT(_SYMBOL, KC_ESC)

// Tap dances.
#define QK_OSA OSM(MOD_LCTL)
#define QK_OSC OSM(MOD_LCTL)
#define QK_OSG OSM(MOD_LGUI)
#define QK_OSS OSM(MOD_LSFT)

// Ctrl-Tab.
#define CTL_TAB C(KC_TAB)
#define RCS_TAB RCS(KC_TAB)

// Shorthands for readability.
#define ___x___ KC_NO

/**
 * \brief Mostly vanilla Dvorak layout.
 */
// clang-format off
#define DVORAK_split_3x5_2                                                                    \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
     HOME_A,  HOME_O,  HOME_E,  HOME_U,    KC_I,    KC_D,  HOME_H,  HOME_T,  HOME_N,  HOME_S, \
    KC_COLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                                QK_OSG,  SPC_MO, ESC_SYM,  QK_OSC
// clang-format on

/**
 * \brief Navigation layer, with convenience one-hand shortcuts.
 *
 * Shortcuts on the left side for use with the mouse in the right hand.
 * Inverted T navigation cluster on the right side to combine with left side
 * home row mods.
 */
// clang-format off
#define MOTION_split_3x5_2                                                                    \
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB,  SYSTEM, ___x___, KC_HOME,   KC_UP,  KC_END, KC_BSPC, \
    OSM_ALT, OSM_GUI, OSM_CTL, OSM_SFT, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, \
    ___x___, WS_PREV, ___x___, WS_NEXT, ___x___, ___x___, KC_WH_U, KC_WH_D, ___x___, ___x___, \
                               ___x___, _______, _______, _______
// clang-format on

/**
 * \brief Symbols.
 */
// clang-format off
#define SYMBOL_split_3x5_2                                                                    \
     KC_ESC, CK_DCOL, KC_UNDS, KC_COLN,   KC_AT,  SYSTEM, KC_LPRN, KC_SCLN, KC_RPRN, KC_PERC, \
    KC_EXLM, KC_CIRC, KC_MINS, KC_PLUS, KC_HASH, KC_AMPR, OSM_SFT, OSM_CTL, OSM_GUI, OSM_ALT, \
    KC_TILD,  KC_DLR, KC_ASTR, KC_SLSH, KC_QUES, KC_PIPE, KC_LCBR, KC_BSLS, KC_RCBR,  KC_GRV, \
                               _______, _______, _______, ___x___
// clang-format on

/**
 * \brief Numrow.
 */
// clang-format off
#define NUMBER_split_3x5_2                                                                    \
    KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR, ___x___,   KC_LT,  KC_EQL,   KC_GT, ___x___, \
    KC_MINS,    KC_4,    KC_5,    KC_6, KC_PLUS, ___x___, OSM_SFT, OSM_CTL, OSM_GUI, OSM_ALT, \
     KC_DOT,    KC_1,    KC_2,    KC_3, KC_COMM, ___x___, KC_LBRC,    KC_0, KC_RBRC, CK_ELPS, \
                               ___x___, _______, _______, ___x___
// clang-format on

/**
 * \brief Special keycodes/functions.
 */
// clang-format off
#define SYSTEM_split_3x5_2                                                                    \
    ___x___, ___x___, ___x___, ___x___, RGB_TOG, RGB_TOG, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, EEP_RST, EEP_RST, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, QK_BOOT, QK_BOOT, ___x___, ___x___, ___x___, ___x___, \
                               ___x___, ___x___, ___x___, ___x___
// clang-format on

// clang-format off
/**
 * \brief Converts a 3x5_2 layout into the more community 3x5_3 layout.
 *
 * In other words, converts a split-34 keymap into a split-36 one.
 */
#define _LAYOUT_split_3x5_2_to_split_3x5_3(                  \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                          k33, k34, k35, k36)                \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                 k33, k34, QK_OSA, QK_OSS, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) \
  _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define MOTION_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(MOTION_split_3x5_2)
#define NUMBER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(NUMBER_split_3x5_2)
#define SYMBOL_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYMBOL_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
