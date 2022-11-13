#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, \
    k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, \
               k24, k25, k26, k27, k28, k29 \
) { \
        { k26, k05, k04, k02, k13, }, \
        { k25, k17, k15, k14, k00, }, \
        { k24, k16, k03, k01, k12, }, \
        { k27, k06, k07, k09, k22, }, \
        { k28, k18, k20, k21, k11, }, \
        { k29, k19, k08, k10, k23 }, \
}

/* With rows and columns swapped */
/*
        { k26, k25, k24, k27, k28, k29, }, \
        { k05, k17, k16, k06, k18, k19, }, \
        { k04, k15, k03, k07, k20, k08, }, \
        { k02, k14, k01, k09, k21, k10, }, \
        { k13, k00, k12, k22, k11, k23, }, \
*/

/* Allow the georgi layout to be used directly. */
#define LAYOUT_georgi LAYOUT
