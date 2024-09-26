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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,         KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  LSFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  LSFT_T(KC_SLSH),
              TT(_LOWER), MO(_MODLEFT), KC_BSPC,         KC_SPC, MO(_MODRIGHT),  TT(_RAISE)
),

[_LOWER] = LAYOUT_split_3x5_3(
  KC_ENT, KC_PSLS, KC_PMNS, KC_COLN, KC_DEL,       KC_B, KC_C, KC_D, KC_E, KC_F,
  KC_PERC, KC_ASTR, KC_PLUS, KC_DOT, KC_PEQL,      KC_6, KC_7, KC_8, KC_9, KC_A,
  KC_AMPR, KC_LALT, LSFT(KC_T), KC_COMM, KC_SPC,   KC_1, KC_2, KC_3, KC_4, KC_5,
                    _______, _______, _______,    KC_0, _______, TG(_FUNC)
),

[_RAISE] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_LCBR, KC_RCBR, KC_HASH, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_DQUO,
  KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_DLR,      KC_PLUS, KC_MINS, KC_LT, KC_GT, KC_QUOT,
  KC_BSLS, KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE,     KC_EQL, KC_AT, KC_ESC, KC_QUES, KC_GRV,
                    TG(_FUNC), _______, _______,    _______, _______, _______

),

[_MODLEFT] = LAYOUT_split_3x5_3(
  KC_TAB,  KC_PGUP, LCTL(KC_E), KC_HOME, KC_CAPS,      _______,_______,_______,_______,_______,
  KC_ESC,  KC_PGDN, LCTL(KC_X), KC_END, KC_RALT,       _______,_______,_______,_______,_______,
  KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, LM(_AWESOME, MOD_LGUI),     _______,_______,_______,_______,_______,
                   _______,_______, KC_DEL,        KC_ENT, TT(_NAV), _______
),

[_MODRIGHT] = LAYOUT_split_3x5_3(
  _______,_______,_______,_______,_______,     KC_CAPS, KC_HOME, LALT(KC_SPACE), KC_PGUP, KC_TAB,
  _______,_______,_______,_______,_______,     KC_RALT, KC_END,  LCTL(KC_SPACE), KC_PGDN, KC_ESC,
  _______,_______,_______,_______,_______,     RCTL(KC_SPACE), KC_RGUI, KC_LCTL, KC_LALT, KC_RSFT,
                _______, TT(_NAV), KC_DEL,     KC_ENT, _______, _______
),

[_NAV] = LAYOUT_split_3x5_3(
  _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,_______,
                  _______,_______,_______,     _______,_______,_______

),

[_FUNC] = LAYOUT_split_3x5_3(
  _______,_______,_______,_______,_______,     KC_PSCR, KC_F9, KC_F10,KC_F11,KC_F12,
  _______,_______,_______,_______,_______,     KC_NUM_LOCK, KC_F5, KC_F6, KC_F7,KC_F8,
  _______,_______,_______,_______,_______,     KC_INS,KC_F1,KC_F2,KC_F3,KC_F4,
                  _______,_______,_______,     _______,_______,_______

),

[_AWESOME] = LAYOUT_split_3x5_3(
  _______,_______,_______,_______,_______,     KC_1, KC_2, KC_3, KC_4, KC_5,
  _______,_______,_______,_______,_______,     KC_H, KC_J, KC_K, KC_L, KC_6,
  _______,_______,_______,_______,_______,     KC_9, LCTL(KC_J), KC_8, KC_DOT, KC_7,
                  _______,_______,_______,     KC_SPC,_______,_______
),

};


// const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_BLUE}
// );
// const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_CYAN}
// );
// const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_PINK}
// );
// const rgblight_segment_t PROGMEM modright_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 6, HSV_RED}
// );
// const rgblight_segment_t PROGMEM modleft_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 6, HSV_RED}
// );
// const rgblight_segment_t PROGMEM awesome_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 6, HSV_GOLD}
// );
// const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {7, 3, HSV_GREEN}
// );
// const rgblight_segment_t PROGMEM func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 12, HSV_WHITE}
// );
// const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_WHITE},
//     {6, 1, HSV_WHITE}
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     qwerty_layer,
//     lower_layer,
//     raise_layer,
//     func_layer,
//     nav_layer,
//     awesome_layer,
//     modleft_layer,
//     modright_layer,
//     capslock_layer
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
//     rgblight_sethsv(HSV_BLUE);
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Both layers will light up if both kb layers are active
//     rgblight_set_layer_state(0, true);
//     rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
//     rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC));
//     rgblight_set_layer_state(4, layer_state_cmp(state, _NAV));
//     rgblight_set_layer_state(5, layer_state_cmp(state, _AWESOME));
//     rgblight_set_layer_state(6, layer_state_cmp(state, _MODLEFT));
//     rgblight_set_layer_state(7, layer_state_cmp(state, _MODRIGHT));
//     return state;
// }

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(8, led_state.caps_lock);
//     return true;
// }
