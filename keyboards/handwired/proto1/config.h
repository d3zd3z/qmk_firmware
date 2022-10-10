/*
 * Copyright 2022 David Brown <davidb@davidb.org>
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

#define MATRIX_ROWS 5
#define MATRIX_COLS 6
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP5, GP6 }
#define MATRIX_COL_PINS { GP7, GP8, GP9, GP26, GP27, GP28 }

#define DEBUG_MATRIX_SCAN_RATE
#define QMK_WAITING_TEST_BUSY_PIN GP21
#define QMK_WAITING_TEST_YIELD_PIN GP23

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
