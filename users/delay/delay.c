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

#include "action_util.h"
#include "config.h"
#include "delay.h"
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
#    include "quantum/rgb_matrix/rgb_matrix.h"
#endif // RGB_MATRIX_ENABLE

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMMA, KC_HASH},                  // Shifts , to #
    {KC_DOT, KC_EXLM},                    // Shifts . to !
    {KC_EQUAL, KC_EQUAL},                 // Don't shift =
    {KC_SLASH, KC_SLASH},                 // Don't shift /
    {KC_BACKSLASH, KC_BACKSLASH},         // Don't shift backslash
    {KC_GRAVE, KC_GRAVE},                 // Don't shift `
    {KC_LEFT_BRACKET, KC_LEFT_BRACKET},   // Don't shift [
    {KC_RIGHT_BRACKET, KC_RIGHT_BRACKET}, // Don't shift ]
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum combo_events {
    CAPS_LOCK_COMBO, // , and R => activate Caps Lock.
    CAPS_WORD_COMBO, // . and C => activate Caps Word.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t caps_lock_combo[] PROGMEM = {KC_COMMA, KC_R, COMBO_END};
const uint16_t caps_word_combo[] PROGMEM = {KC_DOT, KC_C, COMBO_END};

combo_t key_combos[] = {
    [CAPS_LOCK_COMBO] = COMBO_ACTION(caps_lock_combo),
    [CAPS_WORD_COMBO] = COMBO_ACTION(caps_word_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
        switch (combo_index) {
            case CAPS_LOCK_COMBO:
                clear_oneshot_mods();
                set_oneshot_locked_mods(MOD_LSFT);
                add_mods(MOD_LSFT);
                break;
            case CAPS_WORD_COMBO:
                clear_oneshot_mods();
                caps_word_on();
                break;
        }
    }
}

#ifdef TAPPING_TERM_PER_KEY
__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t* record) {
    return TAPPING_TERM;
}

/**
 * \brief Define key-specific `TAPPING_TERM`.
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    return get_tapping_term_keymap(keycode, record);
}
#endif // TAPPING_TERM_PER_KEY

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
    return true;
}
#endif // TAPPING_FORCE_HOLD_PER_KEY

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        // I have a dedicated underscore key, so no need to shift KC_MINS.
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case KC_ESCAPE:
            clear_oneshot_mods();
            clear_oneshot_locked_mods();
            del_mods(MOD_MASK_SHIFT);
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

void shutdown_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
#ifdef OLED_ENABLE
    oled_off();
#endif // OLED_ENABLE
}
