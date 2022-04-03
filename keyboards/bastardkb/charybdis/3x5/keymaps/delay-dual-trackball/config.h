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
#pragma once

// Trackball angle adjustment.
#undef ROTATIONAL_TRANSFORM_ANGLE
#define ROTATIONAL_TRANSFORM_ANGLE -80

// Custom DPI.
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800
#define CHARYBDIS_MINIMUM_SNIPING_DPI 300

// Disable unused keycodes.
#define NO_CHARYBDIS_KEYCODES

// Double trackball build.
#undef POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_COMBINED

#define POINTING_DEVICE_INVERT_X_RIGHT
