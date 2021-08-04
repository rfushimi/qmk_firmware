#include QMK_KEYBOARD_H
#include "quantum/rgb_matrix.h"

enum layer_names {
  BASE,  // Default, alpha, layer.
  DEVR,  // Characters heavily used when programming.
  NAVR,  // Navigation layer.
  NUMR,  // Number pad.
  SYMR,  // Other special characters commonly found in regular text.
};

enum custom_keycodes {
  // Custom version of these keycodes to add special effects.
  FX_ESC = SAFE_RANGE,  // Auto-unlock OSM Shift.
  FX_RST,               // Changes LEDs color before entering reset mode.
  // Custom version of these keycodes that can't be shifted.
  NS_0,
  NS_1,
  NS_2,
  NS_3,
  NS_4,
  NS_5,
  NS_6,
  NS_7,
  NS_8,
  NS_9,
  NS_BSLS,
  NS_COMM,
  NS_DOT,
  NS_GRV,
  NS_LBRC,
  NS_RBRC,
  NS_SCLN,
  NS_SLSH,
};

// Custom NAV keycodes, for Apple macOS.
#define FX_CUT LCMD(KC_X)
#define FX_COPY LCMD(KC_C)
#define FX_PSTE LCMD(KC_V)

// Spaces navigation.
#define FX_SCRL LGUI(KC_LEFT)
#define FX_SCRR LGUI(KC_RIGHT)

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
#define TAB_SYM LT(SYMR, KC_TAB)

// Tap dances.
#define OSM_SFT OSM(MOD_LSFT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_QUOT, NS_COMM,  NS_DOT,    KC_P,    KC_Y,      KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX,  HOME_A,  HOME_O,  HOME_E,  HOME_U,    KC_I,      KC_D,  HOME_H,  HOME_T,  HOME_N,  HOME_S, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, NS_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, SPC_NAV,  FX_ESC,   OSM_SFT, ENT_NUM, TAB_SYM
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [DEVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,  FX_RST, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LCBR, KC_AMPR, KC_RCBR, KC_PIPE, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_CIRC, KC_LPRN, KC_ASTR, KC_RPRN,  KC_DLR, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   NS_BSLS,  NS_DOT, NS_SLSH, KC_TILD, KC_QUES, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  BSP_DEV, XXXXXXX, XXXXXXX,   XXXXXXX,  KC_ENT,  KC_TAB
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NAVR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, FX_PSTE, FX_COPY,  FX_CUT, XXXXXXX,   KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, FX_SCRL, FX_SCRR, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  XXXXXXX, SPC_NAV, XXXXXXX,   XXXXXXX,  KC_ENT,  KC_TAB
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [NUMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX, KC_PEQL,    NS_7,    NS_8,    NS_9, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, KC_PMNS,    NS_4,    NS_5,    NS_6, KC_PPLS,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, KC_PSLS,    NS_1,    NS_2,    NS_3, KC_PAST,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                                  KC_BSPC,    NS_0, KC_PDOT,   XXXXXXX, ENT_NUM, XXXXXXX
  //                            ╰──────────────────────────╯ ╰──────────────────────────╯
  ),

  [SYMR] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,  NS_GRV,   KC_LT, NS_SLSH,   KC_GT, KC_PERC,   XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,  FX_RST, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX, KC_COLN, NS_LBRC, KC_UNDS, NS_RBRC, XXXXXXX,   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
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
    // TODO(delay): Reconcile this code with the new ESC_DEV layer key.
    case FX_ESC: {
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
    case FX_RST: {
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      rgb_matrix_sethsv_noeeprom(0, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
      reset_keyboard();
      break;
    }
    case NS_0:
      NO_SHIFT_CODE(KC_0);
    case NS_1:
      NO_SHIFT_CODE(KC_1);
    case NS_2:
      NO_SHIFT_CODE(KC_2);
    case NS_3:
      NO_SHIFT_CODE(KC_3);
    case NS_4:
      NO_SHIFT_CODE(KC_4);
    case NS_5:
      NO_SHIFT_CODE(KC_5);
    case NS_6:
      NO_SHIFT_CODE(KC_6);
    case NS_7:
      NO_SHIFT_CODE(KC_7);
    case NS_8:
      NO_SHIFT_CODE(KC_8);
    case NS_9:
      NO_SHIFT_CODE(KC_9);
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
    case FX_ESC:
      UNREGISTER_CODE_IF_PRESSED(KC_ESC);
    case NS_0:
      UNREGISTER_CODE_IF_PRESSED(KC_0);
    case NS_1:
      UNREGISTER_CODE_IF_PRESSED(KC_1);
    case NS_2:
      UNREGISTER_CODE_IF_PRESSED(KC_2);
    case NS_3:
      UNREGISTER_CODE_IF_PRESSED(KC_3);
    case NS_4:
      UNREGISTER_CODE_IF_PRESSED(KC_4);
    case NS_5:
      UNREGISTER_CODE_IF_PRESSED(KC_5);
    case NS_6:
      UNREGISTER_CODE_IF_PRESSED(KC_6);
    case NS_7:
      UNREGISTER_CODE_IF_PRESSED(KC_7);
    case NS_8:
      UNREGISTER_CODE_IF_PRESSED(KC_8);
    case NS_9:
      UNREGISTER_CODE_IF_PRESSED(KC_9);
    case NS_BSLS:
      UNREGISTER_CODE_IF_PRESSED(KC_BSLASH);
    case NS_COMM:
      UNREGISTER_CODE_IF_PRESSED(KC_COMMA);
    case NS_DOT:
      UNREGISTER_CODE_IF_PRESSED(KC_DOT);
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
 * Apply default/startup RGB matrix values.
 *
 * This is to replace the missing `rgb_matrix_reload_from_eeprom()`.
 */
static void _rgb_matrix_apply_default(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
  rgb_matrix_sethsv_noeeprom(RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT,
                             RGB_MATRIX_STARTUP_VAL);
  rgb_matrix_set_speed_noeeprom(RGB_MATRIX_STARTUP_SPD);
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
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(155, 80, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
  } else if (!mods) {
    _rgb_matrix_apply_default();  // Load default values.
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
  rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
  rgb_matrix_sethsv(RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT,
                    RGB_MATRIX_STARTUP_VAL);
  rgb_matrix_set_speed(RGB_MATRIX_STARTUP_SPD);
}
