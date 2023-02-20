#include "action.h"
#include "osm_bitmask.h"

static uint8_t x_osm_state_pressed = 0; // Bit flag for Gui, Alt, Shift, Control, repeated for right, left.
static uint8_t x_osm_state_sticky  = 0;

bool process_osm(uint16_t keycode, bool pressed, uint16_t reset_key) {
    bool is_one_shot = IS_QK_ONE_SHOT_MOD(keycode);
    bool is_trigger  = keycode == reset_key || IS_BASIC_KEYCODE(keycode);

    // If the 5th bit indicates left (0), use 4 bits as-is, otherwise move them to the left by 4 spaces.
    uint8_t mod_mask = (uint8_t)((keycode >> 4) & 1) == 0 ? keycode & 0b1111 : (keycode & 0b1111) << 4;

    if (is_one_shot && pressed) {
        // Toggle sticky-ness and make sure to make the active mods mirror that.
        x_osm_state_pressed |= mod_mask;
        x_osm_state_sticky ^= mod_mask;
        register_mods(mod_mask & x_osm_state_sticky);
        return false;
    } else if (is_one_shot && !pressed) {
        // Deactivate mods that are not sticky (because they were not deactivated on one-shot, because they were still pressed)
        x_osm_state_pressed &= ~mod_mask;
        unregister_mods(mod_mask & ~x_osm_state_sticky);
        return false;
    } else if (is_trigger) {
        bool discard_event = keycode == reset_key && x_osm_state_pressed == 0;

        if (!pressed) {
            // Remove sticky-ness and deactivate mods that are not pressed (those categorized as one-shot)
            unregister_mods(x_osm_state_sticky & ~x_osm_state_pressed);
            x_osm_state_sticky = 0;
        }
        return !discard_event;
    }

    return true;
}
