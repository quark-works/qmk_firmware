// Copyright 2022 Brandon Beltran (@Quark)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_1,    KC_2,
        KC_3,    KC_4,
        KC_5,    KC_6,
        KC_7,    KC_8
    )
};
