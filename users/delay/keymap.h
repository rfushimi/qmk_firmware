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
  // Custom keycodes.
  SAFE_RANGE_KEYMAP = KEYCODE_USER_BEGIN,
};

// This keymap uses ASCG home row mods (on layers).
//
//             Left hand                          Right hand
// ╭───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────╮
// │  Alt  │  Gui  │ Ctrl  │ Shift │   │ Shift │ Ctrl  │  Gui  │  Alt  │
// ╰───────┴───────┴───────┴───────╯   ╰───────┴───────┴───────┴───────╯

#define SC_PASTE_NO_FORMAT LGUI(S(KC_V))
#define SC_LAUNCHER LGUI(KC_SPACE)

#define CK_ELLIPSIS LALT(KC_SEMICOLON)

// Shorthands.
#define LAUNCHR SC_LAUNCHER
#define CK_ELPS CK_ELLIPSIS

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
#define SYSTEM OSL(_SYSTEM)
#define SPC_MO LT(_MOTION, KC_SPACE)
#define ENT_SY LT(_SYMBOL, KC_ENTER)

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

/**
 * \brief Mostly vanilla Dvorak layout.
 */
// clang-format off
#define DVORAK_split_3x5_2                                                                    \
    KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
    KC_COLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                               OSM_SFT,  SPC_MO,  ENT_SY, OSM_CTL
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
    LAUNCHR, RCS_TAB,  KC_TAB, CTL_TAB, ___x___, ___x___, KC_HOME,   KC_UP,  KC_END, ___x___, \
    OSM_ALT, OSM_GUI, OSM_CTL, OSM_SFT, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, \
    A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5), A(KC_6), A(KC_7), A(KC_8), A(KC_9), A(KC_0), \
                                SYSTEM, _______, _______, _______
// clang-format on

/**
 * \brief Symbols.
 */
// clang-format off
#define SYMBOL_split_3x5_2                                                                    \
     KC_ESC,   KC_LT, KC_QUES,   KC_GT, KC_COLN, ___x___, KC_LBRC, KC_PERC, KC_RBRC,  KC_GRV, \
    KC_EXLM, KC_PLUS, KC_MINS,  KC_EQL, KC_HASH, KC_CIRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_SCLN, \
    KC_TILD, KC_BSLS, KC_ASTR, KC_SLSH, KC_AMPR, KC_PIPE, KC_LCBR,  KC_DLR, KC_RCBR,   KC_AT, \
                               _______, _______, _______,  SYSTEM
// clang-format on

/**
 * \brief Numrow.
 */
// clang-format off
#define NUMBER_split_3x5_2                                                                    \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, \
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, C(KC_A), ___x___, ___x___, \
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
                k33, k34,  OSM_ALT,  OSM_GUI, k35, k36
// clang-format on

#define LAYOUT_split_3x5_2_to_split_3x5_3(...) \
  _LAYOUT_split_3x5_2_to_split_3x5_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(DVORAK_split_3x5_2)
#define MOTION_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(MOTION_split_3x5_2)
#define NUMBER_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(NUMBER_split_3x5_2)
#define SYMBOL_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYMBOL_split_3x5_2)
#define SYSTEM_split_3x5_3 LAYOUT_split_3x5_2_to_split_3x5_3(SYSTEM_split_3x5_2)
