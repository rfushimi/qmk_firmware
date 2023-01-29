#include QMK_KEYBOARD_H
#include "users/wes/wes.h"

#define LAYOUT_tbkmini(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_tbkmini(DVORAK_split_3x6_3),
  [_LOWER] = LAYOUT_tbkmini(LOWER_split_3x6_3),
  [_RAISE] = LAYOUT_tbkmini(RAISE_split_3x6_3),
};
// clang-format on
