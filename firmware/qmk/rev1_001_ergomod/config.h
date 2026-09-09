// Ploopy Adept (Madromys R1.001+) with all eight switch pads populated,
// under the ploopy-adept-ergo top. Modelled on the unmerged upstream
// commit 42212a39 (rev1_001_8button); GP4 and GP14 are freed for SW5/SW7.
#pragma once

#include "ploopyco/madromys/config.h"
#ifdef UNUSABLE_PINS
#    undef UNUSABLE_PINS
#endif

#define UNUSABLE_PINS { GP1, GP3, GP6, GP8, GP10, GP16, GP18, GP20, GP22, GP24, GP25, GP26, GP27, GP28, GP29 }
