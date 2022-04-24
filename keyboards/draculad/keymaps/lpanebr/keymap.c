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

enum layer_number {
  _BASE,
  _NUM,
  _FUNC,
  _MUS,
  _NAV,
  _ADJ
};


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] =  LAYOUT(
        TD(TD_Q_ESC), KC_W,          KC_E,            KC_R,         KC_T,                                          KC_Y,  KC_U,          KC_I,          KC_O,          KC_P,
        LGUI_T(KC_A), LALT_T(KC_S),  LCTL_T(KC_D),    LSFT_T(KC_F), KC_G,                                          KC_H,  RSFT_T(KC_J),  LCTL_T(KC_K),  RALT_T(KC_L),  RGUI_T(BR_TILD),
        LSFT_T(KC_Z), LT(0,KC_X),    TD(TD_C_CEDIL),  LT(0,KC_V),   KC_B,                                          KC_N,  KC_M,          KC_COMM,       KC_DOT,        LT(0,BR_SLSH),
                                                                    KC_NO,                                         KC_NO,
                                                      KC_BSPC,      LT(_NAV,KC_SPC), LT(_MUS,KC_TAB),      KC_ENT, LT(_NUM,KC_SPC), LT(_FUNC,KC_DEL)
    ),
    [_NUM] = LAYOUT(
        TD(TD_QTS),      BR_LCBR,         BR_LBRC,         BR_LPRN,         BR_EXLM,                                BR_GRV,  KC_7,         KC_8,         KC_9,         KC_MINS,
        LGUI_T(BR_SLSH), LALT_T(BR_ASTR), LCTL_T(BR_MINS), LSFT_T(BR_PLUS), BR_EQL,                                 BR_ACUT, RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), RGUI_T(KC_PLUS),
        BR_BSLS,         BR_RCBR,         BR_RBRC,         BR_RPRN,         BR_AMPR,                                KC_0,    KC_1,         TD(TD_2_C),   TD(TD_3_P),   TD(TD_C_P),
                                                                            KC_NO,                                  KC_NO,
                                                                   XXXXXXX, KC_LALT, XXXXXXX,              _______, KC_ENT,  KC_NO
    ),
    [_FUNC] = LAYOUT(
        KC_ESC,        KC_F1,         KC_F2,         KC_F3,         KC_F4,                                          KC_F12, KC_F7,         KC_F8,         KC_F9,         KC_INS,
        LGUI_T(KC_NO), LALT_T(KC_F5), LCTL_T(KC_F6), LSFT_T(KC_F7), KC_F8,                                          KC_F11, RSFT_T(KC_F4), RCTL_T(KC_F5), RALT_T(KC_F6), RGUI_T(KC_NO),
        KC_LSFT,       KC_F9,         KC_F10,        KC_F11,        KC_F12,                                         KC_F10, KC_F1,         KC_F2,         KC_F3,         KC_NO,
                                                                    KC_NO,                                          KC_NO,
                                                           KC_LALT, XXXXXXX, XXXXXXX,                      XXXXXXX, _______, KC_NO
    ),
    [_NAV] = LAYOUT(
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      BR_CIRC, BR_QUOT, BR_DQUO, BR_DLR, XXXXXXX,
        KC_LALT, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
                                            XXXXXXX,                      XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MUS] = LAYOUT(
        KC_LCTL, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL2,
        KC_LALT, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,                      KC_MS_L,  KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1, 
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ACL0, 
                                            XXXXXXX,                      XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_ADJ] = LAYOUT(
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                                            XXXXXXX,                      _______,
                                   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
    )
};

//LCTL_T(BR_MINS), LSFT_T(BR_PLUS) BR_SLSH
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(BR_ASTR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_ASTR); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCTL_T(BR_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_MINS); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(BR_PLUS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(BR_PLUS); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,BR_SLSH):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(BR_SCLN); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
    }
    return true;
}
