// Copyright 2022 Brandon Beltran (@Quark)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x514b // QK Quark
#define PRODUCT_ID   0x5160 // Q60 QS-60
#define DEVICE_VER   0x0001
#define MANUFACTURER Quark
#define PRODUCT      QS-60

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { D3, C4, D4, B7, C7 }
#define MATRIX_COL_PINS { C5, D2, D1, D0, C2, B6, B5, B4, B3, B2, B1, B0, D6, D5 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define LED_CAPS_LOCK_PIN C6

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
