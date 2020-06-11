/* Copyright 2020 Stefano Maragò
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// still working on "TO" layers + numlock always on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // 12+11+11+9
  [0] = LAYOUT(
    MT(MOD_LGUI,KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_UP, KC_DOT,
    KC_LCTL, TT(1), KC_LALT, KC_SPC, MT(MOD_RSFT,KC_SPC), TT(1), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    KC_LSFT, KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_PGUP, KC_SLSH,
    KC_LCTL, LT(2,KC_APP), KC_LALT, KC_SPC, MT(MOD_RSFT,KC_SPC), LT(2,KC_INS), KC_HOME, KC_PGDN, KC_END
  ),
  [2] = LAYOUT(
    TO(0), KC_PSCR, KC_SLCK, KC_PAUS, KC_PSLS, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PEQL, RESET,
    KC_CAPS, KC_MPLY, KC_STOP, KC_MPRV, KC_MNXT, _______, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PENT,
    TO(2), KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_P1, KC_P2, KC_P3, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,
    TO(3), _______, _______, _______, KC_P0, KC_PDOT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
  ),
  [3] = LAYOUT(
    TO(0), KC_SLEP, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, BL_TOGG, BL_DEC, BL_INC, BL_STEP, _______, _______, _______, _______, _______, _______,
    _______, RGB_TOG, RGB_VAD, RGB_VAI, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

// set num lock alwways on
void matrix_init_user(void) {
  if (!host_keyboard_led_state().num_lock) {
      tap_code(KC_NUMLOCK);
  }
}
