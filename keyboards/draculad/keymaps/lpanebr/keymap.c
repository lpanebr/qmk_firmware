/*
Copyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_br_abnt2.h"


// Tap Dance declarations
enum {
    TD_Q_ESC,
    TD_C_CEDIL,
    TD_QTS,
    TD_C_P,
    TD_2_C,
    TD_3_P,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_C_CEDIL] = ACTION_TAP_DANCE_DOUBLE(KC_C, BR_CCED),
    [TD_QTS] = ACTION_TAP_DANCE_DOUBLE(BR_QUOT, BR_DQUO),
    [TD_C_P] = ACTION_TAP_DANCE_DOUBLE(BR_COMM, BR_DOT),
    [TD_2_C] = ACTION_TAP_DANCE_DOUBLE(KC_2, BR_COMM),
    [TD_3_P] = ACTION_TAP_DANCE_DOUBLE(KC_3, BR_DOT),
};

enum layer_number {
  _BASE,
  _NUM,
  _FUNC,
  _MUS,
  _NAV,
  _ADJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
        TD(TD_Q_ESC), KC_W,  KC_E,            KC_R,         KC_T,                                                  KC_Y,  KC_U,          LT(0,KC_I),    KC_O,          KC_P,
        KC_A, LALT_T(KC_S),  LCTL_T(KC_D),    LSFT_T(KC_F), KC_G,                                                  KC_H,  RSFT_T(KC_J),  RCTL_T(KC_K),  RALT_T(KC_L),  BR_TILD,
        LSFT_T(KC_Z), KC_X,  TD(TD_C_CEDIL),  LT(0,KC_V),   KC_B,                                                  KC_N,  KC_M,          KC_COMM,       KC_DOT,        LT(0,BR_SLSH),
                                                         XXXXXXX,                                                  XXXXXXX,
                       KC_LGUI, LT(_NAV,KC_SPC), LT(_MUS,KC_TAB),                                                  RGUI_T(KC_ENT), LT(_NUM,KC_SPC), LT(_FUNC,KC_APP)
    ),
    [_NUM] = LAYOUT(
        TD(TD_QTS),      BR_LCBR,         BR_LBRC,         BR_LPRN,         BR_EXLM,                               BR_GRV,  KC_7,         KC_8,         KC_9,         KC_MINS,
        LGUI_T(BR_SLSH), LALT_T(BR_ASTR), LCTL_T(BR_MINS), LSFT_T(BR_PLUS), BR_EQL,                                BR_ACUT, RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), RGUI_T(KC_PLUS),
        BR_BSLS,         BR_RCBR,         BR_RBRC,         BR_RPRN,         BR_AMPR,                               KC_0,    KC_1,         TD(TD_2_C),   TD(TD_3_P),   TD(TD_C_P),
                                                                            XXXXXXX,                               XXXXXXX,
                                                          _______, _______, _______,                               _______, _______,  _______
    ),
    [_FUNC] = LAYOUT(
        KC_F24, KC_F23, KC_F22, KC_F21, KC_PSTE,                                                                   KC_F12, KC_F7, KC_F8, KC_F9, KC_BSPC,
        KC_F20, KC_F19, KC_F18, KC_F17, KC_COPY,                                                                   KC_F11, KC_F4, KC_F5, KC_F6, KC_APP,
        KC_F16, KC_F15, KC_F14, KC_F13, _______,                                                                   KC_F10, KC_F1, KC_F2, KC_F3, KC_DEL,
                                        XXXXXXX,                                                                   XXXXXXX,
                      _______, _______, _______,                                                                   _______, _______, _______
    ),
    [_MUS] = LAYOUT(
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                                                               KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2,
        KC_LALT, KC_BTN2, KC_BTN3, KC_BTN1, _______,                                                               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
        KC_LSFT, KC_WBAK, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_WFWD,                                               KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL0,
                                            XXXXXXX,                                                               XXXXXXX,
                          _______, _______, _______,                                                               KC_LGUI, _______, _______
    ),
    [_NAV] = LAYOUT(
        C(S(KC_PGUP)), KC_WH_U, KC_MS_U, KC_WH_D, C(KC_PGUP),                                                      BR_CIRC, BR_QUOT, BR_DQUO, BR_DLR,  _______,
        C(S(KC_PGDN)), KC_MS_L, KC_MS_D, KC_MS_R, C(KC_PGDN),                                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,                                                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                            XXXXXXX,                                                               XXXXXXX,
                          _______, _______, _______,                                                               _______, _______, _______
    ),
    [_ADJ] = LAYOUT(
        RESET,   _______, _______, _______, _______,                                                               _______,  _______, _______, _______, _______,
        EEP_RST, _______, _______, _______, _______,                                                               RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,
        _______, _______, _______, _______, _______,                                                               RGB_M_R, RGB_M_SW, RGB_M_T, RGB_M_TW, _______,
                                            XXXXXXX,                                                               XXXXXXX,
                          _______, _______, _______,                                                               _______, _______, _______
    )
};

//LCTL_T(BR_MINS), LSFT_T(BR_PLUS) BR_SLSH
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(BR_ASTR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_ASTR);
                return false;
            }
            break;
        case LCTL_T(BR_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_MINS);
                return false;
            }
            break;
        case LSFT_T(BR_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_PLUS);
                return false;
            }
            break;
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V));
                return false;
            }
            return true;
        case LT(0,BR_SLSH):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(BR_SCLN);
                return false;
            }
            return true;
        case LT(0,KC_I): // Ins when holding I
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_INS);
                return false;
            }
            return true;
    }
    return true;
}

/* 
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 5, HSV_RED}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 5, HSV_BLUE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 5, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 5, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
    return state;
}
*/
