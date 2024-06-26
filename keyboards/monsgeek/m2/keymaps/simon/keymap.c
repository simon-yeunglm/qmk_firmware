/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

#include "rgb_matrix_user.h"
#include "keymap_layer.h"

enum user_keycodes {
    CTL_N   = SAFE_RANGE,
    CTL_MINS,
    CTL_PLUS,
    CTL_RBRC,
    ENCRYPT,
    NEW_BLD,
    THANKS,
    UE4_FPS,            // execute UE4 macro for stat FPS
    UE4_PROF,           // execute UE4 macro for performance profiling
    LED_OFF,

    DBG_LED,            // debug LED
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_Base] = LAYOUT(
        KC_ESC,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,  KC_DEL,    KC_PSCR, UE4_FPS, UE4_PROF, KC_PAUS,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,      KC_EQL,  KC_BSPC,   KC_CALC, KC_PSLS, KC_PAST,  KC_PMNS,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS,   KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
        TT(L_FnCap),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT          ,   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,               KC_UP,     KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,    KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT,          MO(L_FnCtl),  KC_LEFT, KC_DOWN,   KC_RGHT, KC_P0,   KC_PDOT          ),


    [L_FnCap] = LAYOUT(
	    KC_ESC,     KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______,      _______, _______,   THANKS,  KC_VOLU, KC_VOLD, KC_MPLY,
        _______,    _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, CTL_MINS,     CTL_PLUS,_______,   KC_NUM,  NEW_BLD, ENCRYPT, _______,
        KC_F6  ,    _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,      CTL_RBRC,_______,   _______, _______, _______, _______,
        TT(L_FnCap),_______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,      _______,  _______,  _______, _______,
        _______,    _______, LED_OFF, KC_CALC, _______, _______, CTL_N  , KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, _______,               KC_PGUP,   _______, _______, _______, _______,
        _______,    GU_TOGG, _______,                   _______,                           _______,           _______,      KC_HOME, KC_PGDN,   KC_END,  KC_INS,  _______        ),
        
    [L_FnCtl] = LAYOUT(
	    RESET,      KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______,      _______, _______,  THANKS,  KC_VOLU, KC_VOLD, KC_MPLY,
        _______,    _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, CTL_MINS,     CTL_PLUS,_______,  KC_NUM,  NEW_BLD, ENCRYPT, _______,
        KC_F6  ,    _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,      CTL_RBRC,_______, _______, _______, _______, _______,
        KC_CAPS,    _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,      _______, _______,  _______, _______,
        _______,    _______, LED_OFF, KC_CALC, _______, _______, CTL_N  , KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, _______,               KC_PGUP, _______,  _______, _______, _______,
        _______,    GU_TOGG, _______,                   _______,                           _______,           _______,      KC_HOME, KC_PGDN,  KC_END,  KC_INS,  _______        ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t row     = record->event.key.row;
    uint8_t col     = record->event.key.col;
    bool    pressed = record->event.pressed;
    rgb_matrix_user_process(row, col, pressed);

    switch (keycode) {
        case CTL_N:
            if (record->event.pressed) {
                register_code(  KC_RCTL);
                register_code(  KC_N);
                unregister_code(KC_N);
                unregister_code(KC_RCTL);
            }
            return false;
        case CTL_MINS:
            if (record->event.pressed) {
                register_code(  KC_RCTL);
                register_code(  KC_MINS);
                unregister_code(KC_MINS);
                unregister_code(KC_RCTL);
            }
            return false;
        case CTL_PLUS:
            if (record->event.pressed) {
                register_code(  KC_RCTL);
                register_code(  KC_EQL );
                unregister_code(KC_EQL );
                unregister_code(KC_RCTL);
            }
            return false;
        case CTL_RBRC:
            if (record->event.pressed) {
                register_code(  KC_RCTL);
                register_code(  KC_RBRC);
                unregister_code(KC_RBRC);
                unregister_code(KC_RCTL);
            }
            return false;
        case ENCRYPT:
            if (record->event.pressed) {
                SEND_STRING("Can you help me to encrypt the build?\nThank you.");
            }
            return false;
        case NEW_BLD:
            if (record->event.pressed) {
                SEND_STRING("A new build has been uploaded to .\n");
            }
            return false;
        case THANKS:
            if (record->event.pressed) {
                SEND_STRING("Please let me know if there are any problems.\nThank you.");
            }
            return false;
        case UE4_FPS:
            if (record->event.pressed) {
                SEND_STRING("`stat fps\n`stat unit\n");
            }
            return false;
        case UE4_PROF:
            if (record->event.pressed) {
                SEND_STRING("`stat StartFile\n");
                wait_ms(2000);
                SEND_STRING("`stat StopFile\n");
            }
            return false;
        case LED_OFF:
            if (!record->event.pressed) 
                rgb_matrix_user_sleep();
            return false;
        case DBG_LED:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_CustomEffect);
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CustomEffect);
}