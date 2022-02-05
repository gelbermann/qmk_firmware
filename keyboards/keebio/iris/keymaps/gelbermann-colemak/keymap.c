#include QMK_KEYBOARD_H

// Layers
#define COLEM     DF(_COLEMAK_DH)
#define QWERT     DF(_QWERTY)
#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define NAV       TG(_NAV)

// Utils
#define KC_UNDS                 LSFT(KC_MINS)  // _
#define KC_NUM                  KC_NUMLOCK
#define SWITCH_KEYBOARD_LAYOUT  KB_LYOT


enum layers_keycodes {
  _COLEMAK_DH,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
};

enum macros_keycodes {
  SWITCH_KEYBOARD_LAYOUT = SAFE_RANGE,
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
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_ENT,           _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
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
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, RESET,   _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_LBRC, KC_RBRC, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_INS,  KC_VOLU, KC_LPRN, KC_RPRN, _______,                            KC_HOME, KC_P4,   KC_P5,   KC_P6,   KC_BSLS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPLY, KC_VOLD, KC_LCBR, KC_RCBR, _______, _______,          _______, KC_END,  KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_DELETE,
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
     _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KB_LYOT,          _______, KC_PPLS, KC_DOWN, NAV,     _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KB_LYOT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
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

    set_single_persistent_default_layer(
        language_state.colemak
            ? _COLEMAK_DH
            : _QWERTY
    );
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        // TODO: following two cases can be united with `toggle_keyboard_layout` with some careful thought
        case _COLEMAK_DH:
            if (record->event.pressed) {
                language_state.colemak = true;
                return false;
            }
            break;

        case _QWERTY:
            if (record->event.pressed) {
                language_state.colemak = false;
                return false;
            }
            break;

        // https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
        case SWITCH_KEYBOARD_LAYOUT:
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _NAV); // TODO: NOT WORKING ATM
}

// TODO: consider layer-change code for per-layer rgb lighting: https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
// This would be VERY useful for debugging colemak/qwerty-hebrew/english issues!






// TODO:
/* Current status is:
   2. NAV layer doesn't work at all.

   3. WIP: customizing layer change:
      I need to always be able to switch language via macro, and only do it via macro.
      This way I can expand the macro to also switch between qwerty-colemak, so that I'm always in english-colemak and hebrew-qwerty.
      This can be acheived by having some boolean state for english/hebrew, that is checked and updated on each KB_LYOT execution,
      along with actually changing between colemak and qwerty according to its state.
      This would require another macro to only flip the boolean state, in case I get stuck in colemak-hebrew or qwerty-english.

      Something like this:
      struct state_t {
          bool english;
          bool colemak;
      };
      ?
*/
