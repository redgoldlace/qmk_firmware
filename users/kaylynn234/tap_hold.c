#ifdef TAP_DANCE_ENABLE
#include <quantum.h>
#include <tap_hold.h>

void process_tap_hold(uint16_t keycode, keyrecord_t *record, uint16_t tap_hold_key) {
    if (keycode != TD(tap_hold_key)) {
        return;
    }

    tap_dance_action_t *action = &tap_dance_actions[TD_INDEX(keycode)];
    if (!record->event.pressed && action->state.count && !action->state.finished) {
        tap_hold_info_t *tap_hold = (tap_hold_info_t *)action->user_data;
        tap_code16(tap_hold->on_tap);
    }
}

void tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    if (!state->pressed) {
        return;
    }

    tap_hold_info_t *info = (tap_hold_info_t *)user_data;
    bool is_held;

#ifndef PERMISSIVE_HOLD
    is_held = state->count == 1;
#else
    is_held = state->count == 1 && !state->interrupted;
#endif

    if (is_held) {
        register_code16(info->on_hold);
        info->active = TAP_HOLD_HELD;
    } else {
        register_code16(info->on_tap);
        info->active = TAP_HOLD_TAPPED;
    }
}

void tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_hold_info_t *info = (tap_hold_info_t *)user_data;
    uint16_t active_key;

    switch (info->active) {
        case TAP_HOLD_NONE:
            return;
        case TAP_HOLD_TAPPED:
            active_key = info->on_tap;
            break;
        case TAP_HOLD_HELD:
            active_key = info->on_hold;
            break;
    }

    unregister_code16(active_key);
    info->active = TAP_HOLD_NONE;
}
#endif // TAP_DANCE_ENABLE
