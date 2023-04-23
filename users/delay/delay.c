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
#include "keymap_us.h"
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
#include "quantum/rgb_matrix/rgb_matrix.h"
#endif // RGB_MATRIX_ENABLE

#include "features/custom_shift_keys.h"
#include "features/osm_callum.h"
#include "features/repeat.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_EQUAL, KC_EQUAL},                 // Don't shift =
    {KC_SLASH, KC_SLASH},                 // Don't shift /
    {KC_BACKSLASH, KC_BACKSLASH},         // Don't shift backslash
    {KC_GRAVE, KC_GRAVE},                 // Don't shift `
    {KC_LEFT_BRACKET, KC_LEFT_BRACKET},   // Don't shift [
    {KC_RIGHT_BRACKET, KC_RIGHT_BRACKET}, // Don't shift ]
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum combo_events {
    NUM_WORD_COMBO,        // activate Num Word.
    CAPS_WORD_COMBO,       // activate Caps Word.
    RIGHT_ARROW_COMBO,     // send ->.
    FAT_RIGHT_ARROW_COMBO, // send =>.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t num_word_combo[] PROGMEM = {KC_COMMA, KC_DOT, KC_P, COMBO_END};
const uint16_t caps_word_combo[] PROGMEM = {KC_G, KC_C, KC_R, COMBO_END};
const uint16_t right_arrow_combo[] PROGMEM = {KC_ESCAPE, KC_QUESTION, COMBO_END};
const uint16_t fat_right_arrow_combo[] PROGMEM = {KC_QUESTION, KC_COLON, COMBO_END};

combo_t key_combos[] = {
    [NUM_WORD_COMBO] = COMBO(num_word_combo, KC_NUM_WORD),                      // Num word.
    [CAPS_WORD_COMBO] = COMBO(caps_word_combo, KC_CAPS_WORD),                   // Caps word.
    [RIGHT_ARROW_COMBO] = COMBO(right_arrow_combo, KC_RIGHT_ARROW),             // Right arrow.
    [FAT_RIGHT_ARROW_COMBO] = COMBO(fat_right_arrow_combo, KC_FAT_RIGHT_ARROW), // Fat right arrow.
};

uint16_t get_combo_term(uint16_t combo_index, combo_t* combo) {
    switch (combo_index) {
        case NUM_WORD_COMBO:
        case CAPS_WORD_COMBO:
        case RIGHT_ARROW_COMBO:
        case FAT_RIGHT_ARROW_COMBO:
            return 50;
    }
    return COMBO_TERM;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case QK_TRI_LAYER_LOWER:
        case QK_TRI_LAYER_UPPER:
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

static oneshot_state osm_sft_state = os_up_unqueued;
static oneshot_state osm_ctl_state = os_up_unqueued;
static oneshot_state osm_alt_state = os_up_unqueued;
static oneshot_state osm_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // One-shot mods.
    update_oneshot(&osm_sft_state, KC_LSFT, OSM_SFT, keycode, record);
    update_oneshot(&osm_ctl_state, KC_LCTL, OSM_CTL, keycode, record);
    update_oneshot(&osm_alt_state, KC_LALT, OSM_ALT, keycode, record);
    update_oneshot(&osm_gui_state, KC_LGUI, OSM_GUI, keycode, record);

    // Repeat.
    process_repeat_key(keycode == REPEAT, keycode, record);

    // Custom shifted keys.
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case KC_CAPS_WORD:
                clear_oneshot_mods();
                caps_word_on();
                return false;
            case KC_RIGHT_ARROW:
                tap_code16(KC_MINUS);
                tap_code16(KC_RIGHT_ANGLE_BRACKET);
                return false;
            case KC_FAT_RIGHT_ARROW:
                tap_code16(KC_EQUAL);
                tap_code16(KC_RIGHT_ANGLE_BRACKET);
                return false;
        }
    }

    // Reset internal state.
    switch (keycode) {
        case OSM_CLR:
        case KC_ESCAPE:
            clear_oneshot_mods();
            clear_oneshot_locked_mods();
            del_mods(MOD_MASK_SHIFT);
            break;
    }

    return true;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    return keycode == KC_ESCAPE;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case QK_TRI_LAYER_LOWER:
        case QK_TRI_LAYER_UPPER:
        case KC_LSFT:
        case OSM_SFT:
        case OSM_CTL:
        case OSM_ALT:
        case OSM_GUI:
            return true;
        default:
            return false;
    }
}

// Gotta go fast.
void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int32_t i = 0; i < 40; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
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
}
