// Jonathan Bowe https://github.com/BoweFlex

#include QMK_KEYBOARD_H

enum layers {
  _CANARY,
  _LOWER,
  _RAISE,
  _ADJUST
};

/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Canary (Custom)
 * ,---------------------------------------------------------------------.
 * |   W  |   L  |   Y  |   P  |   B  |   '  |   F  |   O  |   U  |   Q  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   D  |LALT/R|LGUI/S|LCTL/T|   G  |   M  |RCTL/N|RGUI/E|RALT/I|   A  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   K  |   /  |   H  |   ,  |   .  |   J  |
 * `------+------+------+------+------+------+------+------+------+------'
 *                      |TL2/SP|Shift |TL1/RT| BKSP |                     
 *                      `---------------------------'                     
 */
    [_CANARY] = LAYOUT_split_3x5_2(
    KC_W,       KC_L,       KC_Y,       KC_P, KC_B, KC_QUOT,       KC_F,       KC_O,       KC_U,KC_Q,
    KC_D,ALT_T(KC_R),GUI_T(KC_S),CTL_T(KC_T), KC_G,    KC_M,CTL_T(KC_N),GUI_T(KC_E),ALT_T(KC_I),KC_A,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_K,        KC_SLSH,    KC_H,    KC_COMM, KC_DOT,  KC_J,
                       LT(2,KC_SPC), KC_LSFT,   LT(1,KC_ENT), KC_BSPC
    ),
/* LOWER
 * ,---------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   4  |   5  |   6  |      | ESC  | ESC  | LEFT | DOWN |  UP  | RIGHT|
 * |------+------+------+------+------+------+------+------+------+------|
 * |   7  |   8  |   9  |   0  | TAB  | TAB  |      |      |      |      |
 * `------+------+------+------+------+------+------+------+------+------'
 *                      |      | GUI  |      |      |                     
 *                      `---------------------------'                     
 */
    [_LOWER] = LAYOUT_split_3x5_2(
    KC_1,    KC_2,    KC_3,    KC_4,       KC_5,       KC_6,       KC_7,          KC_8,         KC_9,       KC_0,
    KC_4,    KC_5,    KC_6, _______,     KC_ESC,     KC_ESC,    KC_LEFT,       KC_DOWN,        KC_UP,    KC_RGHT,
    KC_7,    KC_8,    KC_9,    KC_0,     KC_TAB,     KC_TAB,    _______, C(S(KC_MINS)), C(S(KC_EQL)),    _______,
                            _______,    KC_LGUI,    _______,    _______
    ),
/* RAISE
 * ,---------------------------------------------------------------------.
 * |      |      |  {   |  [   |  (   |  )   |  ]   |  }   |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |  :   |  @   |  ~   |  \   |  +   |  =   |  |   |  `   |  !   |  ;   |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |  &   |  %   |  #   |  _   |  -   |  $   |  ^   |  *   |      |
 * `------+------+------+------+------+------+------+------+------+------'
 *                      |      |      |      | DEL  |                     
 *                      `---------------------------'                     
 */
    [_RAISE] = LAYOUT_split_3x5_2(
    _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,     KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
    KC_COLN,   KC_AT, KC_TILD, KC_BSLS, KC_PLUS,      KC_EQL, KC_PIPE,  KC_GRV, KC_EXLM, KC_SCLN,
    _______, KC_AMPR, KC_PERC, KC_HASH, KC_UNDS,     KC_MINS,  KC_DLR, KC_CIRC, KC_ASTR, _______,
                               _______, _______,     _______,  KC_DEL
    ),
/* ADJUST (LOWER + RAISE)
 * ,---------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  | F10  |PLY/PS|PRTSCN|      |      |      |BOOTLD|
 * |------+------+------+------+------+------+------+------+------+------|
 * |  F4  |  F5  |  F6  | F11  |VOL_DN|BRI_UP|SCL_UP|LFTCLK| MS_UP| RTCLK|
 * |------+------+------+------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F12  |VOL_DN|BRI_DN|SCL_DN| MS_LT| MS_DN| MS_RT|
 * `------+------+------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |                     
 *                      `---------------------------'                     
 */
    [_ADJUST] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F10, KC_MPLY,      KC_PSCR, _______, _______, _______, QK_BOOT,
    KC_F4,   KC_F5,   KC_F6,   KC_F11, KC_VOLU,      KC_BRIU, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,
    KC_F7,   KC_F8,   KC_F9,   KC_F12, KC_VOLD,      KC_BRID, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,
                               _______, _______,     _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT); // Intercept tap to send Return
            } else if (record->event.pressed) {
                // tap_code16(TL_LOWR); // Intercept hold function to momentarily enable LOWER layer
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case LT(2,KC_SPC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SPC); // Intercept tap to send Space
            } else if (record->event.pressed) {
                // tap_code16(TL_UPPR); // Intercept hold function to momentarily enable UPPER layer
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
    }
    return true;
};
