#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(
	    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
	    LSFT_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN),
	    KC_Z, KC_X, MEH_T(KC_C), HYPR_T(KC_V), KC_B, KC_N, HYPR_T(KC_M), MEH_T(KC_COMM), KC_DOT, KC_SLSH,
	    KC_LEAD, LT(6, KC_TAB), LT(4, KC_SPC), LT(1,KC_BSPC), LT(2, KC_ESC), MO(5)
	),
	[1] = LAYOUT_split_3x5_3(
	    KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_0, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[2] = LAYOUT_split_3x5_3(
	    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F10, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[3] = LAYOUT_split_3x5_3( // league of legends layer
	    KC_TAB, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_1, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_NO
    ),
	[4] = LAYOUT_split_3x5_3(
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, QK_CAPS_WORD_TOGGLE,
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO
    ),
	[5] = LAYOUT_split_3x5_3(
	    KC_TRNS, KC_F11, KC_F12, KC_F13, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F20, KC_F14, KC_F15, KC_F16, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_TRNS, KC_F17, KC_F18, KC_F19, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),
	[6] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY,
        KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

// HOME ROW COMBOS
const uint16_t PROGMEM tick_combo[] = {LSFT_T(KC_A), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM mins_combo[] = {LCTL_T(KC_F), LGUI_T(KC_D), COMBO_END};
//const uint16_t PROGMEM exc_combo[] = {LGUI_T(KC_D), LALT_T(KC_S), COMBO_END}; // available for a combo
const uint16_t PROGMEM pipe_combo[] = {LCTL_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_H, RCTL_T(KC_J), COMBO_END};
const uint16_t PROGMEM enter_combo[] = {RCTL_T(KC_J), RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM quotes_combo[] = {RGUI_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM del_combo[] = {RALT_T(KC_L), RSFT_T(KC_SCLN), COMBO_END};

// TOP ROW COMBOS
const uint16_t PROGMEM at_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM exc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM carat_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM percent_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM am_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM asterisk_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM toggle_league_layer_combo[] = {KC_W, KC_E, KC_R, KC_T, COMBO_END};

// BOTTOM ROW COMBOS
const uint16_t PROGMEM square_open_combo[] = {KC_X, MEH_T(KC_C), COMBO_END};
const uint16_t PROGMEM round_open_combo[] = {MEH_T(KC_C), HYPR_T(KC_V), COMBO_END};
const uint16_t PROGMEM square_close_combo[] = {MEH_T(KC_COMM), KC_DOT, COMBO_END};
const uint16_t PROGMEM round_close_combo[] = {HYPR_T(KC_M), MEH_T(KC_COMM), COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    COMBO(tick_combo, MT(MOD_LSFT | MOD_LALT, KC_GRV)),
    COMBO(exc_combo, MT(MOD_LALT | MOD_LGUI, KC_EXLM)),
    COMBO(mins_combo, MT(MOD_LGUI | MOD_LCTL, KC_MINS)),
    COMBO(pipe_combo, KC_BSLS),
    COMBO(plus_combo, KC_EQL),
    COMBO(enter_combo, MT(MOD_RCTL | MOD_RGUI, KC_ENT)),
    COMBO(quotes_combo, MT(MOD_RALT | MOD_RGUI, KC_QUOT)),
    COMBO(del_combo, MT(MOD_RALT | MOD_RSFT, KC_DEL )),
    COMBO(at_combo, KC_AT),
    COMBO(exc_combo, KC_EXLM),
    COMBO(hash_combo, KC_HASH),
    COMBO(dollar_combo, KC_DLR),
    COMBO(percent_combo, KC_PERC),
    COMBO(carat_combo, KC_CIRC),
    COMBO(am_combo, KC_AMPR),
    COMBO(asterisk_combo, KC_ASTR),
    COMBO(square_open_combo, KC_LBRC),
    COMBO(round_open_combo, KC_LPRN),
    COMBO(square_close_combo, KC_RBRC),
    COMBO(round_close_combo, KC_RPRN),
    COMBO(toggle_league_layer_combo, TG(3)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
            return 130;
        case LT(2, KC_ESC):
            return 130;
        case LT(4, KC_SPC):
            return 130;
        case LSFT_T(KC_A):
            return 130;
        case LALT_T(KC_S):
            return 150;
        case LGUI_T(KC_D):
            return 150;
        case LCTL_T(KC_F):
            return 160;
        case RCTL_T(KC_J):
            return 160;
        case RGUI_T(KC_K):
            return 160;
        case RALT_T(KC_L):
            return 160;
        case RSFT_T(KC_SCLN):
            return 130;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
            return true;
        case LT(2, KC_ESC):
            return true;
        case LT(6, KC_TAB):
            return true;
        case LT(4, KC_SPC):
            return true;
        case LSFT_T(KC_A):
            return true;
        case LALT_T(KC_S):
            return true;
        case LGUI_T(KC_D):
            return true;
        case LCTL_T(KC_F):
            return true;
        case RSFT_T(KC_SCLN):
            return true;
        default:
            return false;
    }
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_M, KC_M) {
      SEND_STRING("suprun.anton6@gmail.com");
    }
    SEQ_TWO_KEYS(KC_P, KC_P) {
      SEND_STRING("15959845October1!");
      tap_code(KC_ENT);
    }
  }
}

// todo: add more symbols to the hold space layer (top and bottom rows) and remove some dual symbols (r and e, commonly rolled chars you misclick alot)
// todo: figure out a good spot to place caps word and caps lock
// todo: add more leader key behaviour
// todo: explore retro tapping (send tap key behaviour if you were holding down the key and didn't press any other key longer than tap term)
// todo: add another layer that triggers qwerty keyboard but not hold tap functionality (maybe consider using leader key for switching)
