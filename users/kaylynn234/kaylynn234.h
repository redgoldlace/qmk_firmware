#pragma once

#include <quantum.h>

enum kay_layers{
    KAY_BASE,
    KAY_FN,
};

#if defined(COMBO_ENABLE)
enum kay_combos {
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
