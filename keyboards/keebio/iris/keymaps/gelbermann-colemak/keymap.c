#include QMK_KEYBOARD_H
// #include "quantum.h" // for rgb lighting

// Layers
#define COLEM     DF(_COLEMAK_DH)
#define QWERT     DF(_QWERTY)
#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define NAV       TG(_NAV)

// Utils
#define KC_UNDS                 LSFT(KC_MINS)  // _
#define KC_NUM                  KC_NUMLOCK
#define TOGGLE_KEYBOARD_LAYOUT  LYT_TOG


enum layers_keycodes {
  _COLEMAK_DH,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
};

enum macros_keycodes {
  TOGGLE_KEYBOARD_LAYOUT = SAFE_RANGE,
  LALT_L,
  LALT_R,
  A_SHFT_L,
  A_SHFT_R,
};


struct language_state_t {
    bool english;
    bool colemak;
};
struct language_state_t language_state = {true, true};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_ENT,           RGB_TOG, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           RGB_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, RESET,   _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_LBRC, KC_RBRC, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_INS,  KC_VOLU, KC_LPRN, KC_RPRN, _______,                            KC_HOME, KC_4,    KC_5,    KC_6,    KC_BSLS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPLY, KC_VOLD, KC_LCBR, KC_RCBR, _______, _______,          _______, KC_END,  KC_1,    KC_2,    KC_3,    KC_0,    KC_DELETE,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, COLEM,                              QWERT,   KC_NUM,  _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, KC_AMPR, KC_ASTR, KC_GRAVE,KC_TILD,                            _______, KC_PGUP, KC_PGDN, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS,                            KC_EQL,  KC_UP,   KC_LEFT, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, LYT_TOG,          _______, KC_PPLS, KC_DOWN, NAV,     _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, NAV,     LYT_TOG,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     NAV,     _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,                            _______, KC_P,    _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                            _______, A_SHFT_L,LALT_L,  LALT_R,  A_SHFT_R,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, NAV,              _______, _______, _______, NAV,     _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, NAV,                       _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

};

void toggle_os_language(void) {
    language_state.english = !language_state.english;

    register_code(KC_LGUI);
    register_code(KC_K);
    unregister_code(KC_K);
    unregister_code(KC_LGUI);
}

void toggle_keyboard_layout(void) {
    language_state.colemak = !language_state.colemak;
    set_single_persistent_default_layer(language_state.colemak ? _COLEMAK_DH : _QWERTY);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        /* ================== handle layers ================== */

        case _COLEMAK_DH:
        case _QWERTY:
            if (record->event.pressed) {
                language_state.colemak = (keycode == _COLEMAK_DH);
                return false;
            }
            break;

        case _LOWER:
        case _RAISE:
            update_tri_layer(_LOWER, _RAISE, _NAV);
            return false;

        /* ================== handle macros ================== */

        case TOGGLE_KEYBOARD_LAYOUT:
            if (record->event.pressed) {
                toggle_keyboard_layout();
                toggle_os_language();
                return false;
            }
            break;

        case LALT_L:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
                return false;
            }
            break;

        case LALT_R:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT));
                return false;
            }
            break;

        case A_SHFT_L:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
            }
            break;

        case A_SHFT_R:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_TAP(X_RIGHT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
                return false;
            }
            break;
    }

    return true;
}

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _COLEMAK_DH) && language_state.colemak) {
        rgblight_setrgb(0xFF, 0xA2, 0x00);

    } else if (IS_LAYER_ON_STATE(state, _QWERTY) && !language_state.colemak) {
        rgblight_setrgb(0xB5, 0xB5, 0xB5);

    } else {    // `language_state` and layer not synced
        rgblight_setrgb(0x00, 0x00, 0x00);
    }

    return state;
}
*/

/*
TODO: possible improvements:
- Capsword and other case-hacks
- rgb light per layer (WIP)
*/
