/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    KAY_BASE,
    KAY_FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KAY_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             LCMD(KC_D),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PSCR,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(KAY_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [KAY_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [KAY_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [KAY_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

#if defined(COMBO_ENABLE)
enum combos {
    COMBO_SKIP_LEFT,
    COMBO_SKIP_RIGHT,
    COMBO_NUMPAD_0,
    COMBO_NUMPAD_1,
    COMBO_NUMPAD_2,
    COMBO_NUMPAD_3,
    COMBO_NUMPAD_4,
    COMBO_NUMPAD_5,
    COMBO_NUMPAD_6,
    COMBO_NUMPAD_7,
    COMBO_NUMPAD_8,
    COMBO_NUMPAD_9,
};

const uint16_t PROGMEM combo_skip_left[] = {KC_LALT, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_skip_right[] = {KC_LALT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_numpad_0[] = {KC_LALT, KC_0, COMBO_END};
const uint16_t PROGMEM combo_numpad_1[] = {KC_LALT, KC_1, COMBO_END};
const uint16_t PROGMEM combo_numpad_2[] = {KC_LALT, KC_2, COMBO_END};
const uint16_t PROGMEM combo_numpad_3[] = {KC_LALT, KC_3, COMBO_END};
const uint16_t PROGMEM combo_numpad_4[] = {KC_LALT, KC_4, COMBO_END};
const uint16_t PROGMEM combo_numpad_5[] = {KC_LALT, KC_5, COMBO_END};
const uint16_t PROGMEM combo_numpad_6[] = {KC_LALT, KC_6, COMBO_END};
const uint16_t PROGMEM combo_numpad_7[] = {KC_LALT, KC_7, COMBO_END};
const uint16_t PROGMEM combo_numpad_8[] = {KC_LALT, KC_8, COMBO_END};
const uint16_t PROGMEM combo_numpad_9[] = {KC_LALT, KC_9, COMBO_END};

combo_t key_combos[] = {
    [COMBO_SKIP_LEFT] = COMBO(combo_skip_left, KC_HOME),
    [COMBO_SKIP_RIGHT] = COMBO(combo_skip_right, KC_END),
    [COMBO_NUMPAD_0] = COMBO(combo_numpad_0, KC_KP_0),
    [COMBO_NUMPAD_1] = COMBO(combo_numpad_1, KC_KP_1),
    [COMBO_NUMPAD_2] = COMBO(combo_numpad_2, KC_KP_2),
    [COMBO_NUMPAD_3] = COMBO(combo_numpad_3, KC_KP_3),
    [COMBO_NUMPAD_4] = COMBO(combo_numpad_4, KC_KP_4),
    [COMBO_NUMPAD_5] = COMBO(combo_numpad_5, KC_KP_5),
    [COMBO_NUMPAD_6] = COMBO(combo_numpad_6, KC_KP_6),
    [COMBO_NUMPAD_7] = COMBO(combo_numpad_7, KC_KP_7),
    [COMBO_NUMPAD_8] = COMBO(combo_numpad_8, KC_KP_8),
    [COMBO_NUMPAD_9] = COMBO(combo_numpad_9, KC_KP_9),
};
#endif // COMBO_ENABLE