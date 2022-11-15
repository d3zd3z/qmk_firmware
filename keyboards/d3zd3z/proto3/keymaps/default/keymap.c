/* My keymap. */

#include "keymap_steno.h"
#include QMK_KEYBOARD_H
#include <rgblight.h>

enum layers {
        STENO,
        QWERTY,
        NAV,
        /*
        NUM,
        NUMPAD,
        SYM,
        */
};

/* Home row keys that can be modifiers. */
#define HR_A MT(MOD_LGUI, KC_A)
#define HR_S MT(MOD_LALT, KC_S)
#define HR_D MT(MOD_LCTL, KC_D)
#define HR_F MT(MOD_LSFT, KC_F)

#define HR_J MT(MOD_LSFT, KC_J)
#define HR_K MT(MOD_LCTL, KC_K)
#define HR_L MT(MOD_LALT, KC_L)
#define HR_SCLN MT(MOD_LGUI, KC_SCLN)

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

        TO(STENO), HR_A, HR_S, HR_D, HR_F, KC_G,
        KC_H, HR_J, HR_K, HR_L, HR_SCLN, KC_QUOT,

        KC_ESC, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,

        KC_LBRC, KC_TAB, KC_BSPC,
        KC_ENT, KC_SPC, KC_RBRC),

    [NAV] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PAUS, KC_NO,

        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_PSCR, KC_BSPC, KC_DEL, KC_SCRL, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO)
};

/* The combinations of top and middle row will send the numbers from
 * that row. */
const uint16_t PROGMEM cmb_1[] = {KC_Q, HR_A, COMBO_END};
const uint16_t PROGMEM cmb_2[] = {KC_W, HR_S, COMBO_END};
const uint16_t PROGMEM cmb_3[] = {KC_E, HR_D, COMBO_END};
const uint16_t PROGMEM cmb_4[] = {KC_R, HR_F, COMBO_END};
const uint16_t PROGMEM cmb_5[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_6[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM cmb_7[] = {KC_U, HR_J, COMBO_END};
const uint16_t PROGMEM cmb_8[] = {KC_I, HR_K, COMBO_END};
const uint16_t PROGMEM cmb_9[] = {KC_O, HR_L, COMBO_END};
const uint16_t PROGMEM cmb_0[] = {KC_P, HR_SCLN, COMBO_END};

/* The middle and bottom row will directly give the symbol from the
 * number, without needing a shift. */
const uint16_t PROGMEM cmb_s1[] = {HR_A, KC_Z, COMBO_END};
const uint16_t PROGMEM cmb_s2[] = {HR_S, KC_X, COMBO_END};
const uint16_t PROGMEM cmb_s3[] = {HR_D, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_s4[] = {HR_F, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_s5[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_s6[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_s7[] = {HR_J, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_s8[] = {HR_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_s9[] = {HR_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_s0[] = {HR_SCLN, KC_SLSH, COMBO_END};

/* This combo is needed for the one remaining symbol. */
const uint16_t PROGMEM cmb_back[] = {KC_MINS, KC_QUOT, COMBO_END};

/* 'EU' is the NAV mode shift. */
const uint16_t PROGMEM cmd_nav[] = {KC_ENT, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_1, KC_1),
    COMBO(cmb_2, KC_2),
    COMBO(cmb_3, KC_3),
    COMBO(cmb_4, KC_4),
    COMBO(cmb_5, KC_5),
    COMBO(cmb_6, KC_6),
    COMBO(cmb_7, KC_7),
    COMBO(cmb_8, KC_8),
    COMBO(cmb_9, KC_9),
    COMBO(cmb_0, KC_0),

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
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

#if 0
/* Definitions for the bottom row that can also be modifiers. */
#define BM_V MT(MOD_LSFT, KC_V)
#define BM_C MT(MOD_LCTL, KC_C)
#define BM_X MT(MOD_LALT, KC_X)
#define BM_Z MT(MOD_LGUI, KC_Z)

/* Bottom row modifiers in the numpad mode that can also be modifiers. */
#define BM_KP_1 MT(MOD_LSFT, KC_KP_1)
#define BM_KP_2 MT(MOD_LCTL, KC_KP_2)
#define BM_KP_3 MT(MOD_LALT, KC_KP_3)
#define BM_KP_0 MT(MOD_LGUI, KC_KP_0)
#define BM_KP_DOT MT(MOD_LGUI, KC_KP_DOT)
#define BM_KP_COMMA MT(MOD_LALT, KC_COMMA)
#define BM_KP_ENTER MT(MOD_LCTL, KC_KP_ENTER)

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
        TO(STENO),  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,   KC_MINS,
        KC_NO,      BM_Z, BM_X, BM_C, BM_V, KC_B,   KC_N, BM_M, BM_COMM, BM_DOT, BM_SLSH, KC_ESC,
                       MO(NUM), KC_TAB, KC_BSPC,    KC_ENT, KC_SPC, MO(NUM)),

    /* Numbers and some random punctuation.  The rest of the punction
     * can be defined as combos. */
    [NUM] = LAYOUT(
        KC_NO,      KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        KC_NO,      LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS),
                   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO),

    /* Navigation.  This encodes the middle navigation keys on a full
     * keyboard. */
    [NAV] = LAYOUT(
        KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PAUS, KC_NO,
        KC_NO,      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_PSCR, KC_BSPC, KC_DEL,  KC_SCRL, KC_NO, KC_NO,
                   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO),

    /* Numpad provides all of the keys on the numeric keypad. */
    [NUMPAD] = LAYOUT(
        KC_NO,      KC_KP_PLUS, KC_KP_MINUS, KC_KP_SLASH, KC_EQL, KC_NO,           KC_NO, KC_KP_7, KC_KP_8, KC_KP_9,  KC_KP_0, KC_NO,
        KC_NO,      BM_KP_DOT, BM_KP_COMMA, BM_KP_ENTER, KC_LSFT, KC_NO,           KC_NO, BM_KP_1, BM_KP_2,  BM_KP_3, BM_KP_0, KC_NO,
                   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO),

    /* Numpad provides all of the keys on the numeric keypad. */
    [SYM] = LAYOUT(
        KC_NO,      LSFT(KC_4), LSFT(KC_1), LSFT(KC_9), LSFT(KC_0), KC_GRV,        KC_NO, LSFT(KC_5), LSFT(KC_8), LSFT(KC_2), LSFT(KC_6), LSFT(KC_MINS),
        KC_NO,      KC_MINUS, LSFT(KC_EQL), KC_LBRC, KC_RBRC, LSFT(KC_BSLS),       KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
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
const uint16_t PROGMEM cmb_quot[] = {KC_MINS, KC_ESC, COMBO_END};

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

/* Combinations for the thumb keys for the other layers. */
const uint16_t PROGMEM cmb_nummode[] = {MO(NUM), KC_TAB, COMBO_END};
const uint16_t PROGMEM cmb_navmode[] = {KC_TAB, KC_BSPC, COMBO_END};
const uint16_t PROGMEM cmb_symmode[] = {KC_ENT, KC_SPC, COMBO_END};

/* Navmode combos for the middle buttons. */
const uint16_t PROGMEM cmb_nav_left[] = {KC_HOME, KC_PSCR, COMBO_END};
const uint16_t PROGMEM cmb_nav_down[] = {KC_PGDN, KC_BSPC, COMBO_END};
const uint16_t PROGMEM cmb_nav_up[] = {KC_PGUP, KC_DEL, COMBO_END};
const uint16_t PROGMEM cmb_nav_right[] = {KC_END, KC_SCRL, COMBO_END};

/* Numpad combos for the middle keys. */
const uint16_t PROGMEM cmb_num_4[] = {KC_KP_7, BM_KP_1, COMBO_END};
const uint16_t PROGMEM cmb_num_5[] = {KC_KP_8, BM_KP_2, COMBO_END};
const uint16_t PROGMEM cmb_num_6[] = {KC_KP_9, BM_KP_3, COMBO_END};

/* Symbol mode combos for the middle keys. */
const uint16_t PROGMEM cmb_sym_hash[] = {LSFT(KC_4), KC_MINUS, COMBO_END};
const uint16_t PROGMEM cmb_sym_amp[] = {LSFT(KC_1), LSFT(KC_EQL), COMBO_END};
const uint16_t PROGMEM cmb_sym_lbrace[] = {LSFT(KC_9), KC_LBRC, COMBO_END};
const uint16_t PROGMEM cmb_sym_rbrace[] = {LSFT(KC_0), KC_RBRC, COMBO_END};
const uint16_t PROGMEM cmb_sym_bslash[] = {KC_GRV, LSFT(KC_BSLS), COMBO_END};

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

    /* Layer selects via thumbs. */
    COMBO(cmb_navmode, MO(NAV)),
    COMBO(cmb_nummode, MO(NUMPAD)),
    COMBO(cmb_symmode, MO(SYM)),

    /* Navmode combos. */
    COMBO(cmb_nav_left, KC_LEFT),
    COMBO(cmb_nav_down, KC_DOWN),
    COMBO(cmb_nav_up, KC_UP),
    COMBO(cmb_nav_right, KC_RIGHT),

    /* Numpad combos. */
    COMBO(cmb_num_4, KC_KP_4),
    COMBO(cmb_num_5, KC_KP_5),
    COMBO(cmb_num_6, KC_KP_6),

    /* Symbol combos. */
    COMBO(cmb_sym_hash, LSFT(KC_3)),
    COMBO(cmb_sym_amp, LSFT(KC_7)),
    COMBO(cmb_sym_lbrace, LSFT(KC_LBRC)),
    COMBO(cmb_sym_rbrace, LSFT(KC_RBRC)),
    COMBO(cmb_sym_bslash, KC_BSLS),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);
#endif

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
