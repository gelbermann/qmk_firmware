#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ X │ X │ X │ X │
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼   │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │Ent│
     * ├───────┼───┼   │
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_ortho_6x4(
        _______,  _______,  _______,  _______,
        KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_P4,    KC_P5,    KC_P6,
        KC_P1,    KC_P2,    KC_P3,    KC_PENT,
                  KC_P0,    KC_PDOT
    )
};
