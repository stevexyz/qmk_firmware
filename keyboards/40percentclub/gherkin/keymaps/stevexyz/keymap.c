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
 * see jj40/stevexyz for more information
 */


#include QMK_KEYBOARD_H

enum layers {
  LAYER_HOME, // home base layer
  LAYER_FUNC, // function keys and cursors
  LAYER_NUMSYM, // numbers and other characters
  LAYER_SYST, // media, mouse and other system keys
};

enum custom_keycodes {
  CK_CONFIGINIT = SAFE_RANGE,
  CK_TRIPLEZERO,
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
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | Enter|
 * | Shift| FnNav|NumSym| AltGr| OSkey| OSkey| AltGr| FnNav|NumSym| Shift|
 * |------+------+------+------+------+------|------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  | Space|      |
 * |      | Ctrl |  Alt | FnNav|NumSym| Shift|  Alt | Ctrl | Shift|      |
 * `---------------------------------------------------------------------'
 */
  [LAYER_HOME] = LAYOUT_ortho_3x10(
         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
         MT(MOD_LSFT, KC_A), LT(LAYER_FUNC, KC_S), LT(LAYER_NUMSYM, KC_D), MT(MOD_RALT, KC_F), MT(MOD_LGUI, KC_G), MT(MOD_RGUI, KC_H), MT(MOD_RALT, KC_J), LT(LAYER_FUNC, KC_K), LT(LAYER_NUMSYM, KC_L), MT(MOD_RSFT, KC_ENT),
         XXXXXXX, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(LAYER_FUNC, KC_C), LT(LAYER_NUMSYM, KC_V), MT(MOD_LSFT, KC_B), MT(MOD_LALT, KC_N), MT(MOD_RCTL, KC_M), MT(MOD_RSFT, KC_SPC), XXXXXXX ),

/* Function and Navigation Layer
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |  ESC | Home | PgDn | PgUp |  End | Left | Down |  Up  | Right| Baksp|
 * | Shift| ____ |SysLay| AltGr| OSkey| OSkey| AltGr| ____ |SysLay| Shift|
 * |------+------+------+------+------+------|------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |      |
 * |      | Ctrl |  Alt | ____ |SysLay| Shift|  Alt | Ctrl | Shift|      |
 * `---------------------------------------------------------------------'
 */
  [LAYER_FUNC] = LAYOUT_ortho_3x10(
         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
         MT(MOD_LSFT, KC_ESC), KC_HOME, LT(LAYER_SYST, KC_PGDN), MT(MOD_RALT, KC_PGUP), MT(MOD_LGUI, KC_END), MT(MOD_RGUI, KC_LEFT), MT(MOD_RALT, KC_DOWN), KC_UP, LT(LAYER_SYST, KC_RGHT), MT(MOD_RSFT, KC_BSPC),
         XXXXXXX, KC_LCTL, KC_LALT, KC_NO, MO(LAYER_SYST), KC_LSFT, KC_LALT, KC_RCTL, MT(MOD_RSFT, KC_SPC), XXXXXXX ),

/* Number and Symbols Layer
 * ,---------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |   ~  |   _  |   +  |   {  |   }  |  |   |   :  |   "  |      |
 * |  TAB |   `  |   -  |   =  |   [  |   ]  |  \   |   ;  |   '  |      |
 * | Shift|SysLay| ____ | AltGr| OSkey| OSkey| AltGr|SysLay| ____ | Shift|
 * |------+------+------+------+------+------|------+------+------+------+
 * |      |      |      |      |      |   <  |   >  |   ?  |      |      |
 * |      | ____ | ____ | ____ | ____ |   ,  |   .  |   /  | ____ |      |
 * |      | Ctrl |  Alt |SysLay| ____ | Shift|  Alt | Ctrl | Shift|      |
 * `---------------------------------------------------------------------'
 */
  [LAYER_NUMSYM] = LAYOUT_ortho_3x10(
         KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
         MT(MOD_LSFT, KC_TAB), LT(LAYER_SYST, KC_GRV), KC_MINS, MT(MOD_RALT, KC_EQL), MT(MOD_LGUI, KC_LBRC), MT(MOD_RGUI, KC_RBRC), MT(MOD_RALT, KC_BSLS), LT(LAYER_SYST, KC_SCLN), KC_QUOT, MT(MOD_RSFT, KC_DEL),
         XXXXXXX, KC_LCTL, KC_LALT, MO(LAYER_SYST), KC_NO, MT(MOD_LSFT, KC_COMM), MT(MOD_LALT, KC_DOT), MT(MOD_RCTL, KC_SLSH), MT(MOD_RSFT, KC_SPC), XXXXXXX ),

/* System Layer
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * | F11  | F12  | Play | Next |MsWhlU|MsBtn1|OSMenu|SysReq|MsBtn2|Backsp|
 * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * | Caps | Mute | Vol- | Vol+ |MsWhlD|MsLeft|MSDown| MsUp |MsRigh| Ins  |
 * | Shift| ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | Shift|
 * |------+------+------+------+------+------|------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |
 * |      | ____ | ____ | ____ | ____ |PrnScr|ScrLck|Pause | ____ |      |
 * |      | Ctrl |  Alt | ____ | ____ | ____ | ____ | ____ | Shift|      |
 * `---------------------------------------------------------------------'
 */
  [LAYER_SYST] = LAYOUT_ortho_3x10(
         KC_F11, KC_F12, KC_MPLY, KC_MNXT, KC_MS_WH_UP, KC_MS_BTN1, KC_APP, KC_SYSREQ, KC_MS_BTN2, KC_BSPC, 
         MT(MOD_LSFT, KC_CAPS), KC_MUTE, KC_VOLD, KC_VOLU, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, MT(MOD_RSFT, KC_INS), 
         XXXXXXX, KC_LCTL, KC_LALT, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, MT(MOD_RSFT, KC_SPC), XXXXXXX ),

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

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}



