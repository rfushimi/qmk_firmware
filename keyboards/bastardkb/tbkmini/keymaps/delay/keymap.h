#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
  BASE,
  DEVR,
  NAVR,
  NUMR,
  SYMR,
};

enum custom_keycodes {
  // Custom version of these keycode that don't produce shifted symbols.
  NS_BSLS = SAFE_RANGE,
  NS_COMM,
  NS_DOT,
  C_ESC,
  NS_GRV,
  NS_LBRC,
  NS_RBRC,
  C_RESET,
  NS_SCLN,
  NS_SLSH,
};

// Home row mods.
#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)

#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

// Layers.
#define SPC_NAV LT(NAVR, KC_SPC)
#define BSP_DEV LT(DEVR, KC_BSPC)
#define ENT_NUM LT(NUMR, KC_ENT)
#define ESC_DEV LT(DEVR, KC_ESC)
#define TAB_SYM LT(SYMR, KC_TAB)

// Tap dances.
#define OSM_SFT OSM(MOD_LSFT)

// Custom NAV keycodes, for Apple macOS.
#define U_CUT LCMD(KC_X)
#define U_COPY LCMD(KC_C)
#define U_PASTE LCMD(KC_V)

// Spaces navigation.
#define C_SCR_L LGUI(KC_LEFT)
#define C_SCR_R LGUI(KC_RIGHT)
