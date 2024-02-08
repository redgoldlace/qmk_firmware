#pragma once

#ifdef TAP_DANCE_ENABLE
#include <quantum.h>

typedef enum {
    TAP_HOLD_NONE,
    TAP_HOLD_TAPPED,
    TAP_HOLD_HELD
} tap_hold_active_t;

typedef struct {
    uint16_t on_tap;
    uint16_t on_hold;
    // We use this to discern which of `on_tap` or `on_hold` was actually registered, so that it can be unregistered
    // once the tapping term has ended.
    tap_hold_active_t active;
} tap_hold_info_t;


void process_tap_hold(uint16_t keycode, keyrecord_t *record, uint16_t tap_hold_key);
void tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_hold_reset(tap_dance_state_t *state, void *user_data);

#define TAP_HOLD(tap, hold) (tap_hold_info_t){ .on_tap = tap, .on_hold = hold, .active = TAP_HOLD_NONE }
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) { \
    .fn = {NULL, tap_hold_finished, tap_hold_reset}, \
    .user_data = (void *)&(TAP_HOLD(tap, hold)), \
}
#endif // TAP_DANCE_ENABLE