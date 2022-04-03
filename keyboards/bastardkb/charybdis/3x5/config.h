/*
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once

#include "config_common.h"

#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1832
#define DEVICE_VER 0x0001

/* Key matrix configuration. */
#define MATRIX_ROWS 8 // Rows are doubled-up.
#define MATRIX_COLS 5

#define DIODE_DIRECTION ROW2COL

/* Disable action features. */
#define NO_ACTION_MACRO    // Disable old-style macro handling.
#define NO_ACTION_FUNCTION // Disable old-style function handling.

/* Set 0 if debouncing isn't needed. */
#define DEBOUNCE 5

/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25

/* RGB matrix support. */
#ifdef RGB_MATRIX_ENABLE
#    if defined(POINTING_DEVICE_LEFT)
#        define RGBLED_NUM 35
#        define RGBLED_SPLIT \
            { 17, 18 }
#    elif defined(POINTING_DEVICE_LEFT)
#        define RGBLED_NUM 35
#        define RGBLED_SPLIT \
            { 18, 17 }
#    else
#        define RGBLED_NUM 34
#        define RGBLED_SPLIT \
            { 17, 17 }
#    endif

#    define SPLIT_TRANSPORT_MIRROR
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_SPLIT RGBLED_SPLIT
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#endif
