/* My keymap. */

#include "keymap_steno.h"
#include QMK_KEYBOARD_H
#include <rgblight.h>

enum layers {
    STENO,
    QWERTY,
    NAV,
    FUN,
    /*
    NUM,
    NUMPAD,
    SYM,
    */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [STENO] = LAYOUT(
        /* Number bar row. */
        STN_RES1, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,
        STN_N6, STN_N7, STN_N8, STN_N9, STN_NA, STN_FN,

        /* Top steno row, STKPW... */
        TO(QWERTY), STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,
        STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,

        /* TODO: what should this key do? */
        KC_NO, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,
        STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,

        /* Thumbs, numbers are on the outside edge. */
        STN_NB, STN_A, STN_O,
        STN_E, STN_U, STN_NC),

    [QWERTY] = LAYOUT(
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,

        TO(STENO), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,

        KC_ESC, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,

        KC_LBRC, KC_TAB, KC_BSPC,
        KC_SPC, KC_ENT, KC_RBRC),

    [NAV] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUS, KC_NO,

        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_PSCR, KC_BSPC, KC_DEL, KC_SCRL, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO),

        [FUN] = LAYOUT(
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,
        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO),
};

/* The combinations of top and middle row will send the numbers from
 * that row. */
const uint16_t PROGMEM cmb_1[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM cmb_2[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM cmb_3[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_4[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_5[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_6[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM cmb_7[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_8[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_9[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_0[] = {KC_P, KC_SCLN, COMBO_END};

/* The middle and bottom row will directly give the symbol from the
 * number, without needing a shift. */
const uint16_t PROGMEM cmb_s1[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM cmb_s2[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM cmb_s3[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_s4[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_s5[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_s6[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_s7[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_s8[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_s9[] = {KC_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_s0[] = {KC_SCLN, KC_SLSH, COMBO_END};

/* This combo is needed for the one remaining symbol. */
const uint16_t PROGMEM cmb_back[] = {KC_MINS, KC_QUOT, COMBO_END};

/* 'EU' is the NAV mode shift. */
const uint16_t PROGMEM cmd_nav[] = {KC_ENT, KC_SPC, COMBO_END};

/* '#A' is the FUN mode shift. */
const uint16_t PROGMEM cmd_fun[] = {KC_LBRC, KC_TAB, COMBO_END};

/* Stick caps lock on the grave and switch key combo. */
const uint16_t PROGMEM cmd_caps[] = {KC_GRV, TO(STENO), COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_1, MT(MOD_LGUI, KC_1)),
    COMBO(cmb_2, MT(MOD_LALT, KC_2)),
    COMBO(cmb_3, MT(MOD_LSFT, KC_3)),
    COMBO(cmb_4, MT(MOD_LCTL, KC_4)),
    COMBO(cmb_5, KC_5),
    COMBO(cmb_6, KC_6),
    COMBO(cmb_7, MT(MOD_LCTL, KC_7)),
    COMBO(cmb_8, MT(MOD_LSFT, KC_8)),
    COMBO(cmb_9, MT(MOD_LALT, KC_9)),
    COMBO(cmb_0, MT(MOD_LGUI, KC_0)),

    COMBO(cmb_s1, LSFT(KC_1)),
    COMBO(cmb_s2, LSFT(KC_2)),
    COMBO(cmb_s3, LSFT(KC_3)),
    COMBO(cmb_s4, LSFT(KC_4)),
    COMBO(cmb_s5, LSFT(KC_5)),
    COMBO(cmb_s6, LSFT(KC_6)),
    COMBO(cmb_s7, LSFT(KC_7)),
    COMBO(cmb_s8, LSFT(KC_8)),
    COMBO(cmb_s9, LSFT(KC_9)),
    COMBO(cmb_s0, LSFT(KC_0)),

    COMBO(cmb_back, KC_BSLS),

    COMBO(cmd_nav, MO(NAV)),
    COMBO(cmd_fun, MO(FUN)),

    COMBO(cmd_caps, KC_CAPS),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void matrix_init_user(void) {
        steno_set_mode(STENO_MODE_GEMINI);
}

/* Make the LEDS track the layer we have enabled. */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case STENO:
        rgblight_setrgb(0, 0, 32);
        break;
    case QWERTY:
        rgblight_setrgb(0, 16, 0);
        break;
    case NAV:
        rgblight_setrgb(16, 16, 0);
        break;
#if 0
    case NUM:
        rgblight_setrgb(16, 0, 0);
        break;
    case NUMPAD:
        rgblight_setrgb(16, 0, 32);
        break;
    case SYM:
        rgblight_setrgb(0, 16, 32);
        break;
#endif
    default:
        rgblight_setrgb(16, 16, 32);
        break;
    }
    return state;
}
