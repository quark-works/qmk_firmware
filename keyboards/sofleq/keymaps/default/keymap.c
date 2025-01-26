// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_MSINC = QK_USER, // Increase multiplier
    KC_MSDEC,           // Decrease multiplier
    KC_MSDEF,           // Reset multiplier
    KC_MSTMP            // Temporarily use default multiplier
};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) }
};
#endif

static float mouse_multiplier = 1.0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   KC_MSDEF,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
            KC_LGUI,KC_LALT, KC_LCTL, MO(1), KC_ENT,                      KC_SPC, MO(2),KC_RCTL,KC_RALT,KC_RGUI
),

[1] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[2] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                      KC_MSDEC, KC_MSINC  , _______,  KC_MSTMP ,  KC_MSDEF ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                       KC_PGUP, _______,   KC_UP, _______,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[3] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,XXXXXXX,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.x *= mouse_multiplier;
    mouse_report.y *= mouse_multiplier;
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static float temp_multiplier = 1.0; // For storing the temporary state
    
    switch (keycode) {
        case KC_MSINC:
            if (record->event.pressed) {
                mouse_multiplier += 0.2;
            }
            break;

        case KC_MSDEC:
            if (record->event.pressed) {
                mouse_multiplier -= 0.2;
                if (mouse_multiplier < 0.2) {
                    mouse_multiplier = 0.2; // Prevent negative or zero multiplier
                }
            }
            break;

        case KC_MSDEF:
            if (record->event.pressed) {
                mouse_multiplier = 1.0;
            }
            break;

        case KC_MSTMP:
            if (record->event.pressed) {
                temp_multiplier = mouse_multiplier; // Store current multiplier
                mouse_multiplier = 1.0;            // Set to default multiplier
            } else {
                mouse_multiplier = temp_multiplier; // Restore previous multiplier
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 2:
            oled_write_P(PSTR("Upper"), false);
            break;
        case 3:
            oled_write_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    
    oled_write_P(PSTR("MM: "), false);
    oled_write(get_u8_str(mouse_multiplier*10, ' '), false);
}   

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return true;
}

#endif
