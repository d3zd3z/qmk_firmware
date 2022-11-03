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

#define VERSION "v1.2: d3zd3z"

/* Not sure why I have to define these. */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xBEEF
#define DEVICE_VER 0x0001

#define MATRIX_ROWS 6
#define MATRIX_COLS 5
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN GP25
#define RGBLED_NUM 1

#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6 }
#define MATRIX_ROW_PINS { GP7, GP26, GP22 }

#define DEBUG_MATRIX_SCAN_RATE
#define QMK_WAITING_TEST_BUSY_PIN GP28
#define QMK_WAITING_TEST_YIELD_PIN GP29

// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* Configuration of the split. */
#define SPLIT_HAND_PIN GP27
#define SPLIT_HAND_PIN_LOW_IS_LEFT

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9
#define SERIAL_USART_PIN_SWAP

/* Tone down the RGB light so make it clear we have just booted, but
 * not so bright that it is blinding. */
#define RGBLIGHT_DEFAULT_HUE 170
#define RGBLIGHT_DEFAULT_VAL 10
#define RGBLIGHT_DEFAULT_SAT 64
