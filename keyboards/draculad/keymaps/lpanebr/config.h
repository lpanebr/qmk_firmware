#pragma once
#define SPLIT_USB_DETECT
// Lower Tapping term fixes my problem with quikly typing deadkeys
#define TAPPING_TERM 125
#define MK_COMBINED
// #define RGBLIGHT_LAYERS

// This only affects Mod Tap keys like I use for homerow mods.
// Fixes my problem of getting ß and æ when I type ls and la quickly.
#define IGNORE_MOD_TAP_INTERRUPT
// Try fixing homerow and LT keys to allow slow typing.
#define TAPPING_TERM_PER_KEY
// Try fixing lost ability to use modded deadkeys quikly.
#define PERMISSIVE_HOLD

