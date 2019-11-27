/* Copyright 2019 Stefano Marago'
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


/*
 * This file is the QMK keymap to configure an ortholinear 40% keyboard
 * (with 48 keys) into an ortholinear 33 keys "small" layout.
 * See the 28 keys version for a "minimal" design.
 * "rules.mk" and "config.h" complete the configuration
 */

// TODO: depict inverted S and D FN and NUM in keyboards


#include QMK_KEYBOARD_H

enum layers {
  LAYER_HOME, // home base layer
  LAYER_FUNC, // function keys and cursors
  LAYER_NUMSYM, // numbers and other characters
  LAYER_SYST, // media and other system keys
  LAYER_NUMONLY, // numeric keypad
  LAYER_LIGHTS, // numeric keypad
  LAYER_MOUSE, // mouse layer
};

enum custom_keycodes {
  CK_CONFIGINIT = SAFE_RANGE,
  CK_TRIPLEZERO,
};

enum {
  TD_P_BSPC = 0,
  TD_Q_ESC,
  TD_A_TAB,
  TD_A_GRAVE,
  TD_E_GRAVE,
  TD_E_ACUTE,
  TD_I_GRAVE,
  TD_O_GRAVE,
  TD_U_GRAVE,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_P_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  //[TD_E_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_EGRAVE),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * LEGEND:
 *
 * ,--------------------------------.
 * |     Top row: shifted character |
 * | Central row: standard char     |
 * |  Bottom row: hold modifier     |
 * `--------------------------------'
 *
 *  "____" means free to be assigned
 *
 */


/* Qwerty Home Layer
 * ------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Baksp|      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | Enter|  Up  |      |
 * | Shift| FnNav|NumSym| AltGr| OSkey| OSkey| AltGr| FnNav|NumSym| Shift| ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  | Space| Left | Down | Right|
 * |      | Ctrl |  Alt | FnNav|NumSym| Shift|  Alt | Ctrl | Shift| ____ | ____ | ____ |
 * ------------------------------------------------------------------------------------'
 */
  [LAYER_HOME] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, XXXXXXX,
         MT(MOD_LSFT, KC_A), LT(LAYER_NUMSYM, KC_S), LT(LAYER_FUNC, KC_D), MT(MOD_RALT, KC_F), MT(MOD_LGUI, KC_G), MT(MOD_RGUI, KC_H), MT(MOD_RALT, KC_J), LT(LAYER_FUNC, KC_K), LT(LAYER_NUMSYM, KC_L), MT(MOD_RSFT, KC_ENT), KC_UP, XXXXXXX,
         XXXXXXX, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(LAYER_FUNC, KC_C), LT(LAYER_NUMSYM, KC_V), MT(MOD_LSFT, KC_B), MT(MOD_LALT, KC_N), MT(MOD_RCTL, KC_M), MT(MOD_RSFT, KC_SPC), KC_LEFT, KC_DOWN, KC_RIGHT),

/* Function and Navigation Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Baksp|      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |  ESC | Home | PgDn | PgUp |  End | Left | Down |  Up  | Right| Baksp| PgUp |      |
 * | Shift| ____ |SysLay| AltGr| OSkey| OSkey| AltGr| ____ |SysLay| Shift| ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | Home | PgDn |  End |
 * |      | Ctrl |  Alt | ____ |SysLay| Shift|  Alt | Ctrl | Shift| ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
  [LAYER_FUNC] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC, XXXXXXX,
         MT(MOD_LSFT, KC_ESC), LT(LAYER_SYST, KC_HOME), KC_PGDN, MT(MOD_RALT, KC_PGUP), MT(MOD_LGUI, KC_END), MT(MOD_RGUI, KC_LEFT), MT(MOD_RALT, KC_DOWN), KC_UP, LT(LAYER_SYST, KC_RGHT), MT(MOD_RSFT, KC_BSPC), KC_PGUP, XXXXXXX,
         XXXXXXX, KC_LCTL, KC_LALT, KC_NO, MO(LAYER_SYST), KC_LSFT, KC_LALT, KC_RCTL, MT(MOD_RSFT, KC_SPC), KC_HOME, KC_PGDN, KC_END ),

/* Number and Symbols Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |      |
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |   ~  |   _  |   +  |   {  |   }  |  |   |   :  |   "  |      |      |      |
 * |  TAB |   `  |   -  |   =  |   [  |   ]  |  \   |   ;  |   '  |  Del |MousUp|      |
 * | Shift|SysLay| ____ | AltGr| OSkey| OSkey| AltGr|SysLay| ____ | Shift| ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   <  |   >  |   ?  |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ |   ,  |   .  |   /  | ____ |MsLeft|MousDn|MsRigt|
 * |      | Ctrl |  Alt |SysLay| ____ | Shift|  Alt | Ctrl | Shift| ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
  [LAYER_NUMSYM] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, XXXXXXX,
         MT(MOD_LSFT, KC_TAB), KC_GRV, LT(LAYER_SYST, KC_MINS), MT(MOD_RALT, KC_EQL), MT(MOD_LGUI, KC_LBRC), MT(MOD_RGUI, KC_RBRC), MT(MOD_RALT, KC_BSLS), LT(LAYER_SYST, KC_SCLN), KC_QUOT, MT(MOD_RSFT, KC_DEL), KC_MS_UP, XXXXXXX,
         XXXXXXX, KC_LCTL, KC_LALT, MO(LAYER_SYST), KC_NO, MT(MOD_LSFT, KC_COMM), MT(MOD_LALT, KC_DOT), MT(MOD_RCTL, KC_SLSH), MT(MOD_RSFT, KC_SPC), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT ),

/* System Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | F11  | F12  |NumLay|LghLay|MsSpd1|MsSpd2|MsSpd3|KbInit| Power|SysReq| Ins  |      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | Caps | Mute | Vol- | Vol+ | Play | Next | ____ | ____ |OSMenu| Ins  |MsWhUp|      |
 * | Shift| ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | Shift| ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ |PrnScr|ScrLck|Pause | ____ |MsBtn1|MsWhDn|MsBtn2|
 * |      | Ctrl |  Alt | ____ | ____ | ____ | ____ | ____ | Shift| ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
  [LAYER_SYST] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_F11, KC_F12, TG(LAYER_NUMONLY), TG(LAYER_LIGHTS), KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, CK_CONFIGINIT, KC_POWER, KC_SYSREQ, KC_INS, XXXXXXX,
         MT(MOD_LSFT, KC_CAPS), KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_APP, MT(MOD_RSFT, KC_INS), KC_MS_WH_UP, XXXXXXX,
         XXXXXXX, KC_LCTL, KC_LALT, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, MT(MOD_RSFT, KC_SPC), KC_MS_BTN1, KC_MS_WH_DOWN, KC_MS_BTN2 ),

/* Numeric Keypad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |NumLck| ____ |NumLay|  /   |  *   |  -   |  7   |  8   |  9   |Backsp| Baksp|      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | Tab  |  (   |  )   |  =   |  ,   |  +   |  4   |  5   |  6   | Enter|  Up  |      |
 * | Shift| ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | Shift| ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | 000  |  .   |  0   |  1   |  2   |  3   | Left | Down | Right|
 * |      | Ctrl |  Alt | ____ | ____ | ____ | ____ | ____ | Shift| ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
  [LAYER_NUMONLY] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_NLCK, KC_NO, TG(LAYER_NUMONLY), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_P7, KC_P8, KC_P9, KC_BSPC, KC_BSPC, XXXXXXX,
         MT(MOD_LSFT, KC_TAB), KC_LPRN, KC_RPRN, KC_EQUAL, KC_KP_COMMA, KC_KP_PLUS, KC_P4, KC_P5, KC_P6, MT(MOD_LSFT, KC_KP_ENTER), KC_UP, XXXXXXX,
         XXXXXXX, KC_LCTL, KC_LALT, CK_TRIPLEZERO, KC_KP_DOT, KC_P0, KC_P1, KC_P2, MT(MOD_LSFT, KC_P3), KC_LEFT, KC_DOWN, KC_RIGHT ),

/* Backlight adjustment Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | ____ | ____ | ____ |LghLay| ____ | Hue+ | Sat+ | Val+ | ____ | Plain|Toggle|      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | ____ | ____ |ModeFw|ModeBw| ____ | Hue- | Sat- | Val- | ____ |Toggle| Val+ |      |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |Breath|Rainbw| Swirl| Snake|Knight| XMas |Gradnt| Test |ModeBw| Val- |ModeFw|
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------------------------------------------------------------------'
 */
  [LAYER_LIGHTS] = LAYOUT_ortho_4x12(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_NO, KC_NO, KC_NO, TG(LAYER_LIGHTS), KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, RGB_M_P, RGB_TOG, XXXXXXX,
         KC_NO, KC_NO, RGB_MOD, RGB_RMOD, KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, RGB_TOG, RGB_VAI, XXXXXXX,
         XXXXXXX, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, RGB_RMOD, RGB_VAD, RGB_MOD ),

};


void matrix_init_user(void) {
  // eeconfig_init(); // reset keyboard to a standard default state; useful when new releases messup with eeprom values
  // set num lock on at start (for numonly layer to work)
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      SEND_STRING(SS_TAP(X_NUMLOCK)); //register_code(KC_NUMLOCK); unregister_code(KC_NUMLOCK);
  }
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_CONFIGINIT:
      if (record->event.pressed) {
        eeconfig_init(); // reset keyboard to a standard default state; useful when new releases messup with eeprom values
      } // else { when released... }
      break;
    case CK_TRIPLEZERO:
      if (record->event.pressed) {
        SEND_STRING("000");
      } // else { when released... }
      break;
  }
  return true;
};


/* Empty keyboard template
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |------+------+------+------+------+------+------|------+------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |      |
 * |      |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |      |
 * `-----------------------------------------------------------------------------------'
 */
