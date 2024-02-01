/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    keyboard_pre_init_user();

    // Set our LED pins as output
    setPinOutput(B11);
    setPinOutput(C14);
    setPinOutput(B12);
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        writePin(B11, !led_state.num_lock);
        writePin(C14, !led_state.caps_lock);
        writePin(B12, !led_state.scroll_lock);
    }

    return true;
}
