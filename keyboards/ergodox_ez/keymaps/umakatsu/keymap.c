#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | 5    |           | 6    |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl    | A/L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Lock |           | App  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl|//Ctr   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  Win |Alt   | [    |   ]  |                                        | LEFT| LEFT | RIGHT| RIGHT| ESC    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.

 *                                        | App  | Del  |       | LGui | L1    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Bs   |Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   |jpn   |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = LAYOUT_ergodox( // layer 0 : default
        // left hand
        KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_RCTL, LT(MDIA, KC_A), KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LALT(LCTL(KC_DEL)),
        LT(SYMB, KC_GRV), KC_LGUI, KC_LALT, KC_LBRC, KC_RBRC,
        KC_BTN2, KC_DELT,
        KC_HOME,
        KC_BSPC, KC_BSPC, LALT(KC_GRV),
        // right hand
        KC_6, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
        KC_BTN2, KC_N, KC_M, KC_COMM, KC_DOT, CTL_T(KC_SLSH), CTL_T(KC_SLSH),
        KC_LEFT, KC_LEFT, KC_RIGHT, KC_RGHT, KC_ESC,
        KC_LGUI, TO(SYMB),
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC),
    /* Keymap 1: Symbol Layer (MAC用、BASEとほぼ一緒)
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  5   |           |  6   |   6  |   7  |   8  |   9  |   0 |   F11  |
 * |--------+------+------+------+------+-------------|            |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl    | A/L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Lock |           | App  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl|//Ctrl  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  opt | Cmd  | [    |   ]  |                                        | LEFT| LEFT | RIGHT| RIGHT| ESC    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.

 *                                        | App  | Del  |       | LGui | L1    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |z
 *                                 | Bs   |Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   |jpn   |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
    // SYMBOLS
    [SYMB] = LAYOUT_ergodox(
        // left hand
        KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_RCTL, LT(MDIA, KC_A), KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LALT(LCTL(KC_DEL)),
        LT(SYMB, KC_GRV), KC_LALT, KC_LGUI, KC_LBRC, KC_RBRC,
        ALT_T(KC_APP), KC_DELT,
        KC_HOME,
        KC_BSPC, KC_BSPC, LGUI(KC_SPC),
        // right hand
        KC_6, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
        ALT_T(KC_APP), KC_N, KC_M, KC_COMM, KC_DOT, CTL_T(KC_SLSH), CTL_T(KC_SLSH),
        KC_LEFT, KC_LEFT, KC_RIGHT, KC_RGHT, KC_ESC,
        KC_LGUI, TO(BASE),
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC),
    /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |PageUP| MsUp |PageDW|      |      |           |      |      | VolUp|VolDw |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |LCLICK|RCLICK|      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |WHUP  |      |WHDOWN|      |      |           |      |      |      | Prev | UP |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |       |LEFT | DOWN |RIGHT |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    // MEDIA AND MOUSE
    [MDIA] = LAYOUT_ergodox(
        KC_EQL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_PGUP, KC_MS_U, KC_PGDN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_MINS,
        KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WBAK),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
