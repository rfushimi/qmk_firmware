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

#include QMK_KEYBOARD_H
#include "users/delay/delay.h"

#define LAYOUT_tbkmini(...) LAYOUT_split_3x6_3(__VA_ARGS__)

/**
 * \brief Converts a 3x5_3 layout into a 3x6_3 layout.
 */
// clang-format off
#define _LAYOUT_split_3x5_3_to_split_3x6_3(                         \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09,        \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,        \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29,        \
                     k32, k33, k34, k35, k36, k37)                  \
    KC_NO, k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, KC_NO, \
    KC_NO, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, KC_NO, \
    KC_NO, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, KC_NO, \
                     k32, k33, k34, k35, k36, k37
// clang-format on

#define LAYOUT_split_3x5_3_to_split_3x6_3(...) _LAYOUT_split_3x5_3_to_split_3x6_3(__VA_ARGS__)

/* Converts the 3x5_2 layouts into 3x5_3 layouts. */
#define DVORAK_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(DVORAK_split_3x5_3)
#define APTmak_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(APTmak_split_3x5_3)
#define APTv3_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(APTv3_split_3x5_3)
#define RSTHD_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(RSTHD_split_3x5_3)
#define MOTION_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(MOTION_split_3x5_3)
#define WINMGT_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(WINMGT_split_3x5_3)
#define NUMBER_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(NUMBER_split_3x5_3)
#define SYMBOL_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(SYMBOL_split_3x5_3)
#define SYSTEM_split_3x6_3 LAYOUT_split_3x5_3_to_split_3x6_3(SYSTEM_split_3x5_3)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_tbkmini(DVORAK_split_3x6_3),
  [_APTmak] = LAYOUT_tbkmini(APTmak_split_3x6_3),
  [_APTv3] = LAYOUT_tbkmini(APTv3_split_3x6_3),
  [_RSTHD] = LAYOUT_tbkmini(RSTHD_split_3x6_3),
  [_MOTION] = LAYOUT_tbkmini(MOTION_split_3x6_3),
  [_WINMGT] = LAYOUT_tbkmini(WINMGT_split_3x6_3),
  [_SYMBOL] = LAYOUT_tbkmini(SYMBOL_split_3x6_3),
  [_NUMBER] = LAYOUT_tbkmini(NUMBER_split_3x6_3),
  [_SYSTEM] = LAYOUT_tbkmini(SYSTEM_split_3x6_3),
};
// clang-format on
