// Jonathan Bowe https://github.com/BoweFlex

#pragma once

// Defaults for usable home row mods
#define PERMISSIVE_HOLD // see https://docs.qmk.fm/tap_hold#permissive-hold
// Time to be considered a tap, works with higher value bc of permissive hold
#define TAPPING_TERM 250
// Shorten time for double tap -> holding multi-function keys
#define QUICK_TAP_TERM 175

// Improved mouse key defaults
// Delay between pressing a key and cursor movement
#define MOUSEKEY_DELAY 16
// Time between cursor movements in milliseconds
#define MOUSEKEY_INTERVAL 16
// Step size for acceleration
#define MOUSEKEY_MOVE_DELTA 9
#define MOUSEKEY_MAX_SPEED 12
#define MOUSEKEY_TIME_TO_MAX 70
#define MOUSEKEY_WHEEL_DELAY 16
#define MOUSEKEY_WHEEL_INTERVAL 30
#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 95

