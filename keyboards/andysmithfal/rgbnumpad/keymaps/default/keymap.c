/* Copyright 2019 Ryota Goto
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_numpad_6x4( /* Base */
    LALT(KC_SPC),  KC_BSPC, TO(1), 
    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_P4,   KC_P5,   KC_P6,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,
	KC_P0,   KC_PDOT
  ), 
  
  [1] = LAYOUT_numpad_6x4(
    RGB_TOG, RGB_MOD, TO(2), 
    RGB_HUI, RGB_SAI, RGB_VAI, _______,
    RGB_HUD, RGB_SAD, RGB_VAD, _______,
    _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______
  ), 
  [2] = LAYOUT_numpad_6x4(
    _______, _______, TO(0), 
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = 17; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            default:
                break;
        }
    }
    return false;
}
