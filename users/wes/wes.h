#pragma once

#include "quantum.h"

enum keycodes_user {
    // Custom keycodes start here.
    SAFE_RANGE_KEYMAP = QK_USER,
};

enum layers_3x6_3_keymap {
    _DVORAK = 0,
    _LOWER,
    _RAISE,
};

// Layers.
#define LWR_BSP LT(_LOWER, KC_BACKSPACE)
#define RSE_SPC LT(_RAISE, KC_SPACE)

// Ctrl-Tab.
#define CTL_TAB LCTL_T(KC_TAB)

// Shorthands for readability.
#define ___x___ KC_NO
#define GA(key) G(A(KC_##key))

// clang-format off
#define DVORAK_split_3x6_3                                                                                      \
    CTL_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RBRC, \
    KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV, \
                               LWR_BSP, KC_HOME, KC_LALT, KC_RALT,  KC_END, RSE_SPC

#define LOWER_split_3x6_3                                                                                       \
    _______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, _______, \
    _______, ___x___, ___x___, KC_PGUP, ___x___, ___x___, ___x___, ___x___, ___x___,   KC_UP, ___x___, KC_VOLU, \
    _______, ___x___, KC_HOME, KC_PGDN,  KC_END, ___x___, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, \
                               _______, ___x___, ___x___, KC_MUTE, KC_MFFD, KC_MPLY

#define RAISE_split_3x6_3                                                                                       \
    _______, ___x___, ___x___, KC_UNDS, KC_PLUS, ___x___, ___x___,    KC_7,    KC_8,    KC_9, ___x___, _______, \
    _______, ___x___, ___x___, KC_LPRN, KC_RPRN, KC_BSLS, KC_LBRC,    KC_4,    KC_5,    KC_6, ___x___, _______, \
    _______, ___x___, ___x___, KC_MINS,  KC_EQL, ___x___,    KC_0,    KC_1,    KC_2,    KC_3, ___x___, _______, \
                               ___x___, ___x___, ___x___, ___x___, ___x___, _______
// clang-format on
