/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

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
#include "split_util.h"

enum layers {
    _QWERTY,  // 0
    _LOWER,     // 1
    _RAISE,    // 2
    _MODLEFT, // 3
    _MODRIGHT,// 4
    _NAV,     // 5
    _FUNC,    // 6
    _AWESOME // 7
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define HOME_A_(k) (LGUI_T(k))
#define HOME_S_(k) (LALT_T(k))
#define HOME_D_(k) (LSFT_T(k))
#define HOME_F_(k) (LCTL_T(k))

#define HOME_J_(k)    (RCTL_T(k))
#define HOME_K_(k)    (RSFT_T(k))
#define HOME_L_(k)    (RALT_T(k))
#define HOME_SCLN_(k) (RGUI_T(k))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case RGUI_T(KC_CIRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            break;
        case RALT_T(KC_DQUO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                return false;
            }
            break;
        case RSFT_T(KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                return false;
            }
            break;
        case RCTL_T(KC_MINS):
            if (record->tap.count && record->event.pressed) {
                if (is_caps_word_on()) {
                    tap_code16(KC_UNDS);
                } else {
                    tap_code16(KC_MINS);
                }
                return false;
            }
            break;
        case LCTL_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE);
                return false;
            }
            break;
        case LSFT_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case LALT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case LGUI_T(KC_TILD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD);
                return false;
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  HOME_A,       HOME_S,  HOME_D,  HOME_F,  KC_G,         KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,
  KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
              _______, OSL(_MODLEFT), KC_BSPC,            KC_SPACE, OSL(_MODRIGHT), _______
),

[_MODRIGHT] = LAYOUT_split_3x5_3(
  KC_EXLM,                  KC_LCBR,           KC_RCBR,          KC_PERC,           KC_HASH,                _______, KC_PLUS,          KC_ASTR,         KC_QUOT,          CW_TOGG,
  HOME_S_(KC_TILD),         HOME_S_(KC_LPRN),  HOME_D_(KC_RPRN), HOME_F_(KC_PIPE),  KC_DLR,                 _______, HOME_J_(KC_MINS), HOME_K_(KC_EQL), HOME_L_(KC_DQUO), HOME_SCLN_(KC_CIRC),
  KC_BSLS,                  KC_LBRC,           KC_RBRC,          KC_AMPR,           KC_AT,                  _______, KC_LT,            KC_GT,           KC_GRV,           _______,
                   _______,_______,_______,                                                                         KC_ENT, _______, _______
),

[_MODLEFT] = LAYOUT_split_3x5_3(
  KC_TAB, _______, _______, _______,  _______,                                         _______, _______, _______, _______,  _______,
  HOME_A_(KC_ESC), HOME_S_(KC_1), HOME_D_(KC_2), HOME_F_(KC_3), _______,               _______, HOME_J_(KC_4), HOME_K_(KC_5), HOME_L_(KC_6), HOME_SCLN_(KC_7),
  _______, _______, _______, _______,  _______,                                           _______, KC_8, KC_9, KC_0,  _______,
                    _______, _______, _______,                                         KC_ENT, _______, _______
),

};
