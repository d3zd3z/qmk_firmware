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
	KC_NO,      BM_Z, BM_X, BM_C, BM_V, KC_B,   KC_N, BM_M, BM_COMM, BM_DOT, BM_SLSH, KC_ESC,
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

/* In addition, borrow various symbols from the Emily's symbols.
 * These work in qwerty mode, and are the same basic as they would be
 * in steno mode. All will be combinations with the 'B' key as that
 * mode. */
const uint16_t PROGMEM cmb_sklam[] = {KC_B, KC_U, BM_M, COMBO_END};
const uint16_t PROGMEM cmb_dquot[] = {KC_B, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_hash[] = {KC_B, KC_U, BM_M, KC_O, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_dollar[] = {KC_B, BM_M, KC_I, BM_COMM, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_percent[] = {KC_B, KC_U, BM_M, KC_I, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_amp[] = {KC_B, KC_U, BM_COMM, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_squot[] = {KC_B, KC_U, COMBO_END};
const uint16_t PROGMEM cmb_lpren[] = {KC_B, KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_rpren[] = {KC_B, BM_M, BM_COMM, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_lbrack[] = {KC_B, KC_U, KC_I, KC_O, KC_ENT, COMBO_END};
const uint16_t PROGMEM cmb_rbrack[] = {KC_B, BM_M, BM_COMM, BM_DOT, KC_ENT, COMBO_END};
const uint16_t PROGMEM cmb_lang[] = {KC_B, KC_U, KC_I, KC_O, KC_SPC, COMBO_END};
const uint16_t PROGMEM cmb_rang[] = {KC_B, BM_M, BM_COMM, BM_DOT, KC_SPC, COMBO_END};
const uint16_t PROGMEM cmb_lcurly[] = {KC_B, KC_U, KC_I, KC_O, KC_ENT, KC_SPC, COMBO_END};
const uint16_t PROGMEM cmb_rcurly[] = {KC_B, BM_M, BM_COMM, BM_DOT, KC_ENT, KC_SPC, COMBO_END};
const uint16_t PROGMEM cmb_star[] = {KC_B, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_plus[] = {KC_B, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_equal[] = {KC_B, KC_I, BM_COMM, KC_O, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_at[] = {KC_B, KC_U, KC_I, KC_O, BM_M, BM_COMM, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_backslash[] = {KC_B, KC_U, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_caret[] = {KC_B, BM_M, KC_I, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_grave[] = {KC_B, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_pipe[] = {KC_B, KC_I, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_tilde[] = {KC_B, KC_U, KC_I, BM_COMM, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_B, KC_U, BM_DOT, COMBO_END};

/* Some are kind of silly, but we map them here in case I'm used to
 * them. */
const uint16_t PROGMEM cmb_comma[] = {KC_B, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_minus[] = {KC_B, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_dot[] = {KC_B, BM_M, COMBO_END};
const uint16_t PROGMEM cmb_slash[] = {KC_B, BM_M, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_colon[] = {KC_B, KC_O, BM_DOT, COMBO_END};
const uint16_t PROGMEM cmb_semicolon[] = {KC_B, BM_M, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_question[] = {KC_B, KC_U, KC_I, BM_COMM, COMBO_END};
const uint16_t PROGMEM cmb_underscore[] = {KC_B, BM_COMM, BM_DOT, COMBO_END};

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

    /* Punctuation borrowed from emily symbols. */
    COMBO(cmb_sklam, LSFT(KC_1)),
    COMBO(cmb_dquot, LSFT(KC_QUOT)),
    COMBO(cmb_hash, LSFT(KC_3)),
    COMBO(cmb_dollar, LSFT(KC_4)),
    COMBO(cmb_percent, LSFT(KC_5)),
    COMBO(cmb_amp, LSFT(KC_7)),
    COMBO(cmb_squot, KC_QUOT),
    COMBO(cmb_lpren, LSFT(KC_9)),
    COMBO(cmb_rpren, LSFT(KC_0)),
    COMBO(cmb_lbrack, KC_LBRC),
    COMBO(cmb_rbrack, KC_RBRC),
    COMBO(cmb_lang, LSFT(KC_COMM)),
    COMBO(cmb_rang, LSFT(KC_DOT)),
    COMBO(cmb_lcurly, LSFT(KC_LBRC)),
    COMBO(cmb_rcurly, LSFT(KC_RBRC)),
    COMBO(cmb_star, LSFT(KC_8)),
    COMBO(cmb_plus, LSFT(KC_EQL)),
    COMBO(cmb_equal, KC_EQL),
    COMBO(cmb_at, LSFT(KC_2)),
    COMBO(cmb_backslash, KC_BSLS),
    COMBO(cmb_caret, LSFT(KC_6)),
    COMBO(cmb_grave, KC_GRV),
    COMBO(cmb_pipe, LSFT(KC_BSLS)),
    COMBO(cmb_tilde, LSFT(KC_GRV)),
    COMBO(cmb_tab, KC_TAB),

    COMBO(cmb_comma, KC_COMM),
    COMBO(cmb_minus, KC_MINS),
    COMBO(cmb_dot, KC_DOT),
    COMBO(cmb_slash, KC_SLSH),
    COMBO(cmb_colon, LSFT(KC_SCLN)),
    COMBO(cmb_semicolon, KC_SCLN),
    COMBO(cmb_question, LSFT(KC_SLSH)),
    COMBO(cmb_underscore, LSFT(KC_MINS)),
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
