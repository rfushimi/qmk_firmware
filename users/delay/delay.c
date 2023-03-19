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
#include "features/tap_dance.h"
#include "features/repeat.h"

static oneshot_layer_mod_td_state_t oneshot_shortcut_layer_td_state = {
    .td_state = 0,
    .layer = _SHORTCUTS,
    .mod = MOD_LSFT,
};

// All tap dance functions would go here.
tap_dance_action_t tap_dance_actions[] = {
    [TD_ONESHOT_SHORTCUTS_LAYER_SHIFT] =
        {
            .fn =
                {
                    NULL,
                    tap_dance_layer_mod_finished,
                    tap_dance_layer_mod_reset,
                },
            .user_data = &oneshot_shortcut_layer_td_state,
        },
};

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
    ALPHA_Z_COMBO,         // Q and J => send Z.
    BACKSPACE_COMBO,       // W and V => send Backspace.
    CAPS_LOCK_COMBO,       // , and R => activate Caps Lock.
    CAPS_WORD_COMBO,       // . and C => activate Caps Word.
    ENTER_COMBO,           // H and N => send Enter.
    ESCAPE_COMBO,          // C and R => send Escape.
    TAB_COMBO,             // , and . => send Tab.
    SINGLE_QUOTE_COMBO,    // H and N => send '.
    DOUBLE_QUOTE_COMBO,    // O and U => send ".
    RIGHT_ARROW_COMBO,     // G and C => send ->.
    FAT_RIGHT_ARROW_COMBO, // . and P => send =>.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t alpha_z_combo[] PROGMEM = {KC_Q, KC_J, COMBO_END};
const uint16_t backspace_combo[] PROGMEM = {KC_W, KC_V, COMBO_END};
const uint16_t caps_lock_combo[] PROGMEM = {KC_COMMA, KC_R, COMBO_END};
const uint16_t caps_word_combo[] PROGMEM = {KC_DOT, KC_C, COMBO_END};
const uint16_t enter_combo[] PROGMEM = {KC_T, KC_N, COMBO_END};
const uint16_t escape_combo[] PROGMEM = {KC_C, KC_R, COMBO_END};
const uint16_t tab_combo[] PROGMEM = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t single_quote_combo[] PROGMEM = {KC_O, KC_U, COMBO_END};
const uint16_t double_quote_combo[] PROGMEM = {KC_H, KC_N, COMBO_END};
const uint16_t right_arrow_combo[] PROGMEM = {KC_G, KC_C, COMBO_END};
const uint16_t fat_right_arrow_combo[] PROGMEM = {KC_DOT, KC_P, COMBO_END};

combo_t key_combos[] = {
    [ALPHA_Z_COMBO] = COMBO(alpha_z_combo, KC_Z),                               // Z.
    [BACKSPACE_COMBO] = COMBO(backspace_combo, KC_BACKSPACE),                   // Backspace.
    [CAPS_LOCK_COMBO] = COMBO_ACTION(caps_lock_combo),                          // Caps lock.
    [CAPS_WORD_COMBO] = COMBO_ACTION(caps_word_combo),                          // Caps word.
    [ENTER_COMBO] = COMBO(enter_combo, KC_ENTER),                               // Enter.
    [ESCAPE_COMBO] = COMBO(escape_combo, KC_ESCAPE),                            // Escape.
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),                                     // Tab.
    [SINGLE_QUOTE_COMBO] = COMBO(single_quote_combo, KC_QUOTE),                 // Single quote.
    [DOUBLE_QUOTE_COMBO] = COMBO(double_quote_combo, KC_DOUBLE_QUOTE),          // Double quote.
    [RIGHT_ARROW_COMBO] = COMBO(right_arrow_combo, KC_RIGHT_ARROW),             // Right arrow.
    [FAT_RIGHT_ARROW_COMBO] = COMBO(fat_right_arrow_combo, KC_FAT_RIGHT_ARROW), // Fat right arrow.
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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case MO_LOWER:
        case MO_UPPER:
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

    // Escape resets internal state.
    switch (keycode) {
        case KC_ESCAPE:
            clear_oneshot_mods();
            clear_oneshot_locked_mods();
            del_mods(MOD_MASK_SHIFT);
            break;
    }

    return true;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case QK_TRI_LAYER_LOWER:
        case KC_ESCAPE:
            return true;
        default:
            return false;
    }
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode == TD_SHORTCUTS) {
        return 90;
    }
    return TAPPING_TERM;
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
