#pragma once

#include "quantum.h"

#define LAYOUT( \
    t00, t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11, \
    m00, m01, m02, m03, m04, m05, m06, m07, m08, m09, m10, m11, \
    b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b10, b11, \
    th1, th2, th3, th4, th5, th6 \
) { \
        { t00, m00, b00, KC_NO, }, \
        { t01, m01, b01, KC_NO, }, \
        { t02, m02, b02, KC_NO, }, \
        { t03, m03, b03, th1, }, \
        { t04, m04, b04, th2, }, \
        { t05, m05, b05, th3, }, \
        { t11, m11, b11, KC_NO, }, \
        { t10, m10, b10, KC_NO, }, \
        { t09, m09, b09, KC_NO, }, \
        { t08, m08, b08, th6, }, \
        { t07, m07, b07, th5, }, \
        { t06, m06, b06, th4, }, \
}

/* Allow the georgi layout to be used directly. */
#define LAYOUT_georgi LAYOUT
