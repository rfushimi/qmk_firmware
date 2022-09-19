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
#include "keymap.h"
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
#    include "quantum/rgb_matrix/rgb_matrix.h"
#    include "quantum/rgblight/rgblight_list.h"
#endif // RGB_MATRIX_ENABLE

#ifdef KEYMAP_DELAY_HOMEROW
#    include "features/achordion.h"
#endif // KEYMAP_DELAY_HOMEROW
#include "features/compose.h"
#include "features/custom_shift_keys.h"
#include "features/oneshot_mod.h"

typedef struct {
    oneshot_mod_state_t lalt;
    oneshot_mod_state_t lctl;
    oneshot_mod_state_t lgui;
    oneshot_mod_state_t lsft;
} osm_state_t;

bool is_oneshot_mod_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case MOTION:
        case NUMBER:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_mod_ignore_key(uint16_t keycode) {
    switch (keycode) {
        case MOTION:
        case NUMBER:
        case SYMBOL:
        case OSM_ALT:
        case OSM_CTL:
        case OSM_GUI:
        case OSM_SFT:
            return true;
        default:
            return false;
    }
}

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_DOT},                     // Don't shift .
    {KC_COMMA, KC_COMMA},                 // Don't shift ,
    {KC_EQUAL, KC_EQUAL},                 // Don't shift =
    {KC_SLASH, KC_SLASH},                 // Don't shift /
    {KC_BACKSLASH, KC_BACKSLASH},         // Don't shift backslash
    {KC_GRAVE, KC_GRAVE},                 // Don't shift `
    {KC_LEFT_BRACKET, KC_LEFT_BRACKET},   // Don't shift [
    {KC_RIGHT_BRACKET, KC_RIGHT_BRACKET}, // Don't shift ]
    {KC_SEMICOLON, KC_SEMICOLON},         // Don't shift ;
    {KC_QUOTE, KC_QUOTE},                 // Don't shift '
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
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning true means we
    // instead want to "force hold" and disable key repeating.
    switch (keycode) {
#    ifdef KEYMAP_DELAY_HOMEROW
        // Repeating is useful for Vim navigation keys.
        case HOME_U:
        case HOME_H:
            return false; // Enable key repeating.
#    endif                // KEYMAP_DELAY_HOMEROW
        default:
            return true; // Otherwise, force hold and disable key repeating.
    }
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

#ifdef KEYMAP_DELAY_HOMEROW
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
#    if 0
    // Exceptionally consider the following chords as holds, even though they are on the same hand in Dvorak.
    switch (tap_hold_keycode) {
        case HOME_S: // S + H and S + G.
            if (other_keycode == HOME_H || other_keycode == KC_G) {
                return true;
            }
            break;
    }

    // Also allow same-hand holds when the other key is in the rows below the alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
        return true;
    }
#    endif

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LGUI:
        case MOD_RGUI:
            return true; // Eagerly apply Ctrl and Gui mods.

        default:
            return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 800; // Use a timeout of 800 ms.
}
#endif // KEYMAP_DELAY_HOMEROW

static bool process_record_user_internal(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
#ifdef KEYMAP_DELAY_HOMEROW
    if (!process_achordion(keycode, record)) {
        return false;
    }
#endif // KEYMAP_DELAY_HOMEROW
    switch (keycode) {
        case KC_ESCAPE:
            clear_oneshot_mods();
            clear_oneshot_locked_mods();
            del_mods(MOD_MASK_SHIFT);
            break;
    }
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static osm_state_t osm_state = {
        .lalt = ONESHOT_UP_UNQUEUED,
        .lctl = ONESHOT_UP_UNQUEUED,
        .lgui = ONESHOT_UP_UNQUEUED,
        .lsft = ONESHOT_UP_UNQUEUED,
    };
    oneshot_mod_pre(&osm_state.lalt, KC_LALT, OSM_ALT, keycode, record);
    oneshot_mod_pre(&osm_state.lctl, KC_LCTL, OSM_CTL, keycode, record);
    oneshot_mod_pre(&osm_state.lgui, KC_LGUI, OSM_GUI, keycode, record);
    oneshot_mod_pre(&osm_state.lsft, KC_LSFT, OSM_SFT, keycode, record);

    const bool result = process_record_user_internal(keycode, record);

    oneshot_mod_post(&osm_state.lalt, KC_LALT, OSM_ALT, keycode, record);
    oneshot_mod_post(&osm_state.lctl, KC_LCTL, OSM_CTL, keycode, record);
    oneshot_mod_post(&osm_state.lgui, KC_LGUI, OSM_GUI, keycode, record);
    oneshot_mod_post(&osm_state.lsft, KC_LSFT, OSM_SFT, keycode, record);

    return result;
}

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_reset(void) {
    rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_sethsv(RGB_MATRIX_STARTUP_HSV);
    rgb_matrix_set_speed(RGB_MATRIX_STARTUP_SPD);
}
#endif // RGB_MATRIX_ENABLE

void matrix_scan_user(void) {
#ifdef KEYMAP_DELAY_HOMEROW
    achordion_task();
#endif // KEYMAP_DELAY_HOMEROW
    matrix_scan_keymap();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

/** Called on layer change. */
layer_state_t layer_state_set_user(layer_state_t state) {
    return layer_state_set_keymap(update_tri_layer_state(state, _MOTION, _NUMBER, _EXTEND));
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

void keyboard_post_init_user(void) {
    oneshot_enable();
    keyboard_post_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void eeconfig_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    eeconfig_update_rgb_matrix_default();
#endif // RGB_MATRIX_ENABLE
}

/**
 * \brief Called when a one-shot layer "lock" status changes.
 *
 * This is called automatically by the QMK framework when a one-shot layer is
 * activated and deactivated.
 * The only one-shot layer in this layout is the one-shot shift layer.  Turns
 * the RGBs solid blue when this layer is activated, and back to default when
 * deactivated.
 */
void oneshot_locked_mods_changed_user(uint8_t mods) {
#ifdef RGB_MATRIX_ENABLE
    if (mods & MOD_MASK_SHIFT) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
        rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    } else if (!mods) {
        rgb_matrix_reload_from_eeprom(); // Load default values.
    }
#endif // RGB_MATRIX_ENABLE
    oneshot_locked_mods_changed_keymap(mods);
}

__attribute__((weak)) void oneshot_locked_mods_changed_keymap(uint8_t mods) {}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
#ifdef OLED_ENABLE
    oled_off();
#endif // OLED_ENABLE
    shutdown_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}
