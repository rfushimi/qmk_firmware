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

// clang-format off
#define _LAYOUT(                                             \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                          k33, k34, k35, k36)                \
    LAYOUT_split_3x5_3(                                      \
           k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
           k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
           k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, \
                   k33, k34, KC_NO, KC_NO, k35, k36)
// clang-format on

#define LAYOUT(...) _LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(DVORAK_split_3x5_2),
  [_APTMAK] = LAYOUT(APTMAK_split_3x5_2),
  [_LOWER] = LAYOUT(LOWER_split_3x5_2),
  [_UPPER] = LAYOUT(UPPER_split_3x5_2),
  [_ADJUST] = LAYOUT(ADJUST_split_3x5_2),
  [_SYSTEM] = LAYOUT(SYSTEM_split_3x5_2),
};
// clang-format on
