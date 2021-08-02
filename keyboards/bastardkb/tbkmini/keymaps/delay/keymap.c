#include "keymap.h"
#include QMK_KEYBOARD_H
#include "quantum/rgblight.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_QUOT, NS_COMM,  NS_DOT,    KC_P,    KC_Y,      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  HOME_A,  HOME_O,  HOME_E,  HOME_U,    KC_I,      KC_D,  HOME_H,  HOME_T,  HOME_N,  HOME_S, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, NS_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, SPC_NAV, ESC_DEV,   OSM_SFT, ENT_NUM, TAB_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [DEVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, C_RESET, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LCBR, KC_AMPR, KC_RCBR, KC_PIPE, XXXXXXX,
  // |--------+--------+--------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_CIRC, KC_LPRN, KC_ASTR, KC_RPRN,  KC_DLR, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   NS_BSLS,  NS_DOT, NS_SLSH, KC_TILD, KC_QUES, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, XXXXXXX, ESC_DEV,   XXXXXXX,  KC_ENT,  KC_TAB
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NAVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, U_PASTE,  U_COPY,   U_CUT, XXXXXXX,   KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  // |--------+--------+--------+--------+--------|--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, C_SCR_L, C_SCR_R, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  XXXXXXX, SPC_NAV, XXXXXXX,   XXXXXXX,  KC_ENT,  KC_TAB
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NUMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_PEQL,    KC_7,    KC_8,    KC_9, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_PMNS,    KC_4,    KC_5,    KC_6, KC_PPLS,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_PSLS,    KC_1,    KC_2,    KC_3, KC_PAST,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC,    KC_0, KC_PDOT,   XXXXXXX, ENT_NUM, XXXXXXX
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [SYMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,  NS_GRV,   KC_LT, NS_SLSH,   KC_GT, KC_PERC,   XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, C_RESET, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_COLN, NS_LBRC, KC_UNDS, NS_RBRC, XXXXXXX,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC, KC_MINS,  KC_TAB,   XXXXXXX, XXXXXXX, TAB_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),
};
// clang-format on

#ifndef NO_SHIFT_CODE
#define NO_SHIFT_CODE(keycode)                          \
  {                                                     \
    if (record->event.pressed) {                        \
      const uint8_t mods = get_mods() & MOD_MASK_SHIFT; \
      if (mods) {                                       \
        del_mods(mods);                                 \
        register_code(keycode);                         \
        add_mods(mods);                                 \
      } else {                                          \
        register_code(keycode);                         \
      }                                                 \
    }                                                   \
    break;                                              \
  }
#endif  // NO_SHIFT_CODE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NS_BSLS:
      NO_SHIFT_CODE(KC_BSLASH);
    case NS_COMM:
      NO_SHIFT_CODE(KC_COMMA);
    case NS_DOT:
      NO_SHIFT_CODE(KC_DOT);
    case NS_GRV:
      NO_SHIFT_CODE(KC_GRAVE);
    case NS_LBRC:
      NO_SHIFT_CODE(KC_LBRC);
    case NS_RBRC:
      NO_SHIFT_CODE(KC_RBRC);
    // TODO(delay): Reconcile this code with the new ESC_DEV layer key.
    case C_ESC: {
      if (record->event.pressed) {
        const uint8_t locked_mods = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
        if (locked_mods) {
          // Clear any locked one-shot mod, if enabled.  The only one-shot layer
          // in this layout is the one-shot shift layer, so it is safe to clear
          // all locked mods.
          del_mods(locked_mods);
          clear_oneshot_locked_mods();
        }
        register_code(KC_ESC);
      }
      break;
    }
    case C_RESET: {
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(0, 255, RGBLIGHT_LIMIT_VAL);
      reset_keyboard();
      break;
    }
    case NS_SCLN:
      NO_SHIFT_CODE(KC_SCOLON);
    case NS_SLSH:
      NO_SHIFT_CODE(KC_SLASH);
  }
  return true;
};

#ifndef UNREGISTER_CODE_IF_PRESSED
#define UNREGISTER_CODE_IF_PRESSED(keycode) \
  {                                         \
    if (!record->event.pressed) {           \
      unregister_code(keycode);             \
    }                                       \
    break;                                  \
  }
#endif  // UNREGISTER_CODE_IF_PRESSED

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NS_BSLS:
      UNREGISTER_CODE_IF_PRESSED(KC_BSLASH);
    case NS_COMM:
      UNREGISTER_CODE_IF_PRESSED(KC_COMMA);
    case NS_DOT:
      UNREGISTER_CODE_IF_PRESSED(KC_DOT);
    case C_ESC:
      UNREGISTER_CODE_IF_PRESSED(KC_ESC);
    case NS_GRV:
      UNREGISTER_CODE_IF_PRESSED(KC_GRAVE);
    case NS_LBRC:
      UNREGISTER_CODE_IF_PRESSED(KC_LBRC);
    case NS_RBRC:
      UNREGISTER_CODE_IF_PRESSED(KC_RBRC);
    case NS_SCLN:
      UNREGISTER_CODE_IF_PRESSED(KC_SCOLON);
    case NS_SLSH:
      UNREGISTER_CODE_IF_PRESSED(KC_SLASH);
  }
}

/**
 * Called when a one-shot layer "lock" status changes.
 *
 * This is called automatically by the QMK framework when a one-shot layer is
 * activated and deactivated.
 * The only one-shot layer in this layout is the one-shot shift layer.  Turns
 * the RGBs solid blue when this layer is activated, and back to default when
 * deactivated.
 */
void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(155, 80, RGBLIGHT_LIMIT_VAL);
  } else if (!mods) {
    rgblight_reload_from_eeprom();  // Load default mode.
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Pinky and ring fingers.
    case HOME_A:
    case HOME_O:
    case HOME_N:
    case HOME_S:
      return TAPPING_TERM + 125;
    // Index fingers.
    case HOME_U:
    case HOME_H:
      return TAPPING_TERM + 25;
    // Thumbs.
    case SPC_NAV:
    case ENT_NUM:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  return keycode != OSM_SFT;
}

#if 0
void keyboard_post_init_user(void) {
}
#endif

void eeconfig_init_user(void) {
  rgblight_mode(RGBLIGHT_DEFAULT_MODE);
  rgblight_set_speed(RGBLIGHT_DEFAULT_SPD);
}
