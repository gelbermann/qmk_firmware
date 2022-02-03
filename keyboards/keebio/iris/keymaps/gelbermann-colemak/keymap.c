#include QMK_KEYBOARD_H

#include "keymap_hebrew.h"

#define COLEM     DF(_COLEMAK)
#define QWERT     DF(_QWERTY)
#define RAISE     MO(_RAISE)
#define LOWER     MO(_LOWER)
#define NAV       TG(_NAV)

enum custom_keycodes {
  /* Layers: */
  _COLEMAK_DHM = SAFE_RANGE,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,

  /* Macros: */
  _SW_LANG,
  _SHFT_L,
  _SHFT_R,
  _A_SHFT_L,
  _A_SHFT_R,
  // TODO: add alt+shift+L/R and alt+L/R macros
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DHM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
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
     _______, _______, _______, KC_LBRC, KC_RBRC, _______,                            KC_PIPE, KC_P7,   KC_P8,   KC_P9,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_INS,  _______, KC_LPRN, KC_RPRN, _______,                            KC_BSLS, KC_P4,   KC_P5,   KC_P6,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,          _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, KC_DELETE,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, COLEM,                              QWERT,   _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_AMPR, KC_ASTR, KC_TILD, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_HOME,                            KC_PGUP, KC_UP,   KC_LEFT, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_END,  _SW_LANG,         _______, KC_PGDN, KC_DOWN, NAV,     _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _SW_LANG,                  _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK_DHM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DHM);
      }
      return false;

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;

    case LOWER:
      handle_regular_layers(_LOWER, record->event.pressed);
      return false;

    case RAISE:
      handle_regular_layers(_RAISE, record->event.pressed);
      return false;

    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;

    default:
      handle_macros(keycode, record);
      break;
  }

  return true;
}

void handle_regular_layers(enum custom_keycodes layer, bool pressed) {
    if (pressed) {
        layer_on(layer);
        update_tri_layer(_LOWER, _RAISE, _NAV);
    } else {
        layer_off(layer);
        update_tri_layer(_LOWER, _RAISE, _NAV);
    }
}

void handle_macros(uint16_t keycode, keyrecord_t *record) {
    // https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
    switch(keycode) {
        case _SW_LANG:
            register_code(KC_LGUI);
            register_code(KC_K);
            unregister_code(KC_K);
            unregister_code(KC_LGUI);
            break;

        case _SHFT_L:
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT));
            break;

        case _SHFT_R:
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_RIGHT) SS_UP(X_LSHIFT));
            break;

        case _A_SHFT_L:
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
            break;

        case _A_SHFT_R:
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_TAP(X_RIGHT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
            break;
    }
}

// TODO: consider layer-change code for per-layer rgb lighting: https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code

// TODO: add missing key codes:
