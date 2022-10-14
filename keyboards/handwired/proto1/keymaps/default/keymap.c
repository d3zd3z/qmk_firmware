/* My keymap. */

#include "keymap_steno.h"
#include QMK_KEYBOARD_H
#include <rgblight.h>

enum layers {
	STENO,
	QWERTY,
        NUM,
};

/* Definitions for the bottom row that can also be modifiers. */
#define BM_V MT(MOD_LSFT, KC_V)
#define BM_C MT(MOD_LCTL, KC_C)
#define BM_X MT(MOD_LALT, KC_X)
#define BM_Z MT(MOD_LGUI, KC_Z)

#define BM_M MT(MOD_LSFT, KC_M)
#define BM_COMM MT(MOD_LCTL, KC_COMM)
#define BM_DOT MT(MOD_LALT, KC_DOT)
#define BM_SLSH MT(MOD_LGUI, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [STENO] =  LAYOUT(
        TO(QWERTY),   STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,   STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
        KC_NO,        STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,   STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                       STN_N1, STN_A, STN_O,   STN_E, STN_U, STN_N2),
    [QWERTY] = LAYOUT(
        TO(STENO),  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,   KC_BSPC,
	KC_NO    ,  BM_Z, BM_X, BM_C, BM_V, KC_B,   KC_N, BM_M, BM_COMM, BM_DOT, BM_SLSH, KC_ESC,
	               MO(NUM), KC_LCTL, KC_BSPC,    KC_ENT, KC_SPC, MO(NUM)),
    /* Numbers and some random punctuation.  The rest of the punction
     * can be defined as combos. */
    [NUM] = LAYOUT(
        KC_NO,      KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO,      LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS),
                   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO),
};

/* Allow the middle qwerty row by setting up as combos. */
const uint16_t PROGMEM cmb_a[] = {KC_Q, BM_Z, COMBO_END};
const uint16_t PROGMEM cmb_s[] = {KC_W, BM_X, COMBO_END};
const uint16_t PROGMEM cmb_d[] = {KC_E, BM_C, COMBO_END};
const uint16_t PROGMEM cmb_f[] = {KC_R, BM_V, COMBO_END};
const uint16_t PROGMEM cmb_g[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_h[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_j[] = {KC_U, BM_M, COMBO_END};
const uint16_t PROGMEM cmb_k[] = {KC_I, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_l[] = {KC_O, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_scln[] = {KC_P, BM_SLSH, COMBO_END};
const uint16_t PROGMEM cmb_quot[] = {KC_BSPC, KC_ESC, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_a, KC_A),
    COMBO(cmb_s, KC_S),
    COMBO(cmb_d, KC_D),
    COMBO(cmb_f, KC_F),
    COMBO(cmb_g, KC_G),
    COMBO(cmb_h, KC_H),
    COMBO(cmb_j, KC_J),
    COMBO(cmb_k, KC_K),
    COMBO(cmb_l, KC_L),
    COMBO(cmb_scln, KC_SCLN),
    COMBO(cmb_quot, KC_QUOT),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void matrix_init_user(void) {
	steno_set_mode(STENO_MODE_GEMINI);
}

/* Make the LEDS track the layer we have enabled. */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case STENO:
        SET_LED_STENO();
        break;
    case QWERTY:
        SET_LED_QWERTY();
        break;
    default:
        rgblight_setrgb(64, 16, 16);
        break;
    }
    return state;
}
