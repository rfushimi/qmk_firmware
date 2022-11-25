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
#include "users/delay/keymap.h"

#define LAYOUT_skeletyl(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_skeletyl(DVORAK_split_3x5_3),
  [_APTv3] = LAYOUT_skeletyl(APTv3_split_3x5_3),
  [_RSTHD] = LAYOUT_skeletyl(RSTHD_split_3x5_3),
  [_MOTION] = LAYOUT_skeletyl(MOTION_split_3x5_3),
  [_SYMBOL] = LAYOUT_skeletyl(SYMBOL_split_3x5_3),
  [_NUMBER] = LAYOUT_skeletyl(NUMBER_split_3x5_3),
  [_SYSTEM] = LAYOUT_skeletyl(SYSTEM_split_3x5_3),
};
// clang-format on
