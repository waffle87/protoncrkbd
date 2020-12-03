#pragma once

enum {
    BTN1B,
    BTN2N
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [BTN1B] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_BTN1),
    [BTN2N] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_BTN2)
};

