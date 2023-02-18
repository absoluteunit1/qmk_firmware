#include QMK_KEYBOARD_H
#include <stdio.h>
#include "qmk-vim/src/vim.h"
#include "features/sentence_case.h"

// TODO PRIORITY STACK
// make entering and leave vim emulation easier
// add button to put laptop into sleep
// consider adding custom key override behaviour for alt-key


enum custom_keycodes {
    EXIT_LOL = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//                                                    DEFAULT LAYER
	[0] = LAYOUT_split_3x5_3(
	    KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P,
	    LSFT_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), KC_G,   KC_H, RCTL_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN),
	    KC_Z, KC_X, KC_C, KC_V, KC_B,                                   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
	    KC_LEAD, LT(1, KC_TAB), LT(2, KC_SPC),                          LT(3, KC_BSPC), LT(4, KC_ESC), LT(5, KC_DEL)
	),

    //                                                TAB HOLD
	[1] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_LPRN, KC_RPRN, KC_NO, KC_CAPS,
        KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_NO,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, QK_CAPS_WORD_TOGGLE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_PIPE,
        KC_NO, KC_TRNS, KC_NO,                                          KC_NO, KC_NO, KC_NO //todo: add common symbols here too
	),

//                                                    SPACE HOLD
	[2] = LAYOUT_split_3x5_3(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_TILD, KC_DQT, KC_QUOT, KC_AMPR, KC_NO,
	    KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_NO,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, //todo: consider putting caps word and caps here instead of tab latr
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_GRV, KC_PIPE, KC_EXLM, KC_BSLS,
	    KC_NO, KC_NO, KC_TRNS,                                          KC_ENT, KC_UNDS, KC_NO //todo: add something here; move underscore to a more intuitive position
    ),
//                                                    BACKSPACE HOLD
	[3] = LAYOUT_split_3x5_3(
	    KC_AT, KC_1, KC_2, KC_3, KC_PLUS,                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_0, KC_4, KC_5, KC_6, KC_PMNS,                                KC_NO, KC_J, KC_K, KC_L, KC_SCLN,
	    KC_ASTR, KC_7, KC_8, KC_9, KC_EQL,                              KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_PERC, KC_HASH, KC_TRNS,                                      KC_TRNS, KC_NO, KC_NO
    ),
//                                                    ESCAPE HOLD
	[4] = LAYOUT_split_3x5_3(
	    KC_NO, KC_F1, KC_F2, KC_F3, KC_NO,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F10, KC_F4, KC_F5, KC_F6, KC_NO,                             KC_TRNS, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
	    KC_NO, KC_F7, KC_F8, KC_F9, KC_NO,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_NO, KC_NO, KC_NO,                                            KC_TRNS, KC_TRNS, KC_TRNS
    ),

//                                                    DELETE HOLD
	[5] = LAYOUT_split_3x5_3(
	    KC_NO, KC_F11, KC_F12, KC_F13, KC_NO,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F20, KC_F14, KC_F15, KC_F16, KC_NO,                          KC_TRNS, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
	    KC_NO, KC_F17, KC_F18, KC_F19, KC_NO,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_SLEP, QK_BOOT, KC_TRNS,                                      KC_NO, KC_NO, KC_TRNS
    ),

	[6] = LAYOUT_split_3x5_3(
	    KC_TAB, KC_W, KC_E, KC_R, KC_T,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_A, KC_S, KC_D, KC_F, KC_G,                                   KC_NO, KC_NO, KC_NO, EXIT_LOL, KC_NO,
	    KC_Z, KC_X, KC_C, KC_V, KC_B,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_LALT, KC_SPC,                                         KC_NO, KC_NO, KC_NO
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SCLN):
            return 160;
        case LSFT_T(KC_A):
            return 160;
        case MT(MOD_RGUI | MOD_RALT, KC_ENT):
            return 250;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_ESC):
            return true;
        case LT(1, KC_TAB):
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

//const uint16_t PROGMEM test_combo2[] = {LSFT_T(KC_A), LT(_LAYER, KC_B), KC_C, COMBO_END};
//const uint16_t PROGMEM test_combo2[] = {LSFT_T(KC_A), LT(_LAYER, KC_B), KC_C, COMBO_END};
//const uint16_t PROGMEM test_combo2[] = {LSFT_T(KC_A), LT(_LAYER, KC_B), KC_C, COMBO_END};
//const uint16_t PROGMEM test_combo2[] = {LSFT_T(KC_A), LT(_LAYER, KC_B), KC_C, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {RGUI_T(KC_K), RALT_T(KC_L), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(enter_combo, MT(MOD_RGUI | MOD_RALT, KC_ENT))
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_DOT) {
      toggle_vim_mode();
    }

    SEQ_ONE_KEY(RALT_T(KC_L)) {
      layer_invert(6);
    }

    SEQ_ONE_KEY(KC_L) {
      layer_invert(6);
    }

    SEQ_TWO_KEYS(KC_M, KC_M) {
      SEND_STRING("suprun.anton6@gmail.com");
    }

  }
}

bool process_normal_mode_user(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed && keycode == KC_Q) {
        toggle_vim_mode();
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_sentence_case(keycode, record)) { return false; }
    if (!process_vim_mode(keycode, record)) { return false; }

    switch (keycode) {

        case EXIT_LOL:
            if (record->event.pressed) {
                layer_invert(6);
                return false;
            }
            return true;

        case LALT_T(KC_S):
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_S);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
            }
            return true;

        case LCTL_T(KC_F):
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_F);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
            }
            return true;

        case LGUI_T(KC_D):
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_D);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
            }
            return true;

        case LSFT_T(KC_A):
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_A);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_mods(MOD_BIT(KC_LGUI));
                    tap_code(KC_D);
                    tap_code(KC_A);
                    add_mods(MOD_BIT(KC_LGUI));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    tap_code(KC_F);
                    tap_code(KC_A);
                    add_mods(MOD_BIT(KC_LCTL));
                    return false;
                }
            }
            return true;

        case KC_E:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    tap_code(KC_F);
                    tap_code(KC_E);
                    add_mods(MOD_BIT(KC_LCTL));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_E);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_E);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
            }
            return true;

        case KC_R:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_R);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_mods(MOD_BIT(KC_LGUI));
                    tap_code(KC_D);
                    tap_code(KC_R);
                    add_mods(MOD_BIT(KC_LGUI));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_R);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
            }
            return true;

        case KC_T:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_T);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_T);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
            }
            return true;

        case KC_C:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_C);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_C);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
            }
            return true;

        case KC_V:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_A);
                    tap_code(KC_V);
                    add_mods(MOD_BIT(KC_LSFT));
                    return false;
                }
                if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_S);
                    tap_code(KC_V);
                    add_mods(MOD_BIT(KC_LALT));
                    return false;
                }
            }
            return true;

       case KC_B:
           if (record->event.pressed) {
               if (get_mods() & MOD_BIT(KC_LSFT)) {
                   unregister_mods(MOD_BIT(KC_LSFT));
                   tap_code(KC_A);
                   tap_code(KC_B);
                   add_mods(MOD_BIT(KC_LSFT));
                   return false;
               }
               if (get_mods() & MOD_BIT(KC_LALT)) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   tap_code(KC_S);
                   tap_code(KC_B);
                   add_mods(MOD_BIT(KC_LALT));
                   return false;
               }
               if (get_mods() & MOD_BIT(KC_LGUI)) {
                   unregister_mods(MOD_BIT(KC_LGUI));
                   tap_code(KC_D);
                   tap_code(KC_B);
                   add_mods(MOD_BIT(KC_LGUI));
                   return false;
               }
           }
           return true;

       case KC_N:
           if (record->event.pressed) {
               if (get_mods() & MOD_BIT(KC_RGUI)) {
                   unregister_mods(MOD_BIT(KC_RGUI));
                   tap_code(KC_K);
                   tap_code(KC_N);
                   add_mods(MOD_BIT(KC_RGUI));
                   return false;
               }
           }
           return true;

       case KC_I:
           if (record->event.pressed) {
               if (get_mods() & MOD_BIT(KC_RALT)) {
                   unregister_mods(MOD_BIT(KC_RALT));
                   tap_code(KC_L);
                   tap_code(KC_I);
                   add_mods(MOD_BIT(KC_RALT));
                   return false;
               }
               if (get_mods() & MOD_BIT(KC_RCTL)) {
                   unregister_mods(MOD_BIT(KC_RCTL));
                   tap_code(KC_J);
                   tap_code(KC_I);
                   add_mods(MOD_BIT(KC_RCTL));
                   return false;
               }
           }
           return true;

       // todo: add for KC_I above, do the same for KC_O, KC_U (consider: lu, lo, li, ly, lm, ln, etc)
       // todo: consider making both thumb keys a space and make shift+space a backspace? might be very confusing at first but beneficial in long run to reduce finger strain on thumbs
       // todo: consider alt+j, h, k, l, ;, \,,/,.,m : backspace, escape, tab, shift tab, enter, space
       // todo: create custom alt modifiers to create symbols

       case KC_COMM:
           if (record->event.pressed) {
               if ((get_mods() & MOD_BIT(KC_LALT)) && !(get_mods() & MOD_BIT(KC_LSFT)) && !(get_mods() & MOD_BIT(KC_LGUI)) && !(get_mods() & MOD_BIT(KC_LCTL))) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   SEND_STRING(":=");
                   add_mods(MOD_BIT(KC_LALT));
                   return false;
               }

               if ((get_mods() & MOD_BIT(KC_LALT)) && (get_mods() & MOD_BIT(KC_LSFT)) && !(get_mods() & MOD_BIT(KC_LGUI)) && !(get_mods() & MOD_BIT(KC_LCTL))) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   unregister_mods(MOD_BIT(KC_LSFT));
                   tap_code16(KC_LCBR);
                   add_mods(MOD_BIT(KC_LALT));
                   add_mods(MOD_BIT(KC_LSFT));
                   return false;
               }
           }
           return true;

       case RCTL_T(KC_J):
           if (record->event.pressed) {
               if ((get_mods() & MOD_BIT(KC_LALT)) && !(get_mods() & MOD_BIT(KC_LSFT)) && !(get_mods() & MOD_BIT(KC_LGUI)) && !(get_mods() & MOD_BIT(KC_LCTL))) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   tap_code(KC_SPC);
                   add_mods(MOD_BIT(KC_LALT));
                   return false;
               }
           }
           return true;

       case KC_H:
           if (record->event.pressed) {
               if ((get_mods() & MOD_BIT(KC_LALT)) && !(get_mods() & MOD_BIT(KC_LSFT)) && !(get_mods() & MOD_BIT(KC_LGUI)) && !(get_mods() & MOD_BIT(KC_LCTL))) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   tap_code(KC_BSPC);
                   add_mods(MOD_BIT(KC_LALT));
                   return false;
               }
           }
           return true;

// todo: CREATE ONE FOR COMMON SHORTCUTS LIKE COMMAND + SPACE,C
       case RGUI_T(KC_K):
           if (record->event.pressed) {
               if ((get_mods() & MOD_BIT(KC_LALT)) && !(get_mods() & MOD_BIT(KC_LSFT)) && !(get_mods() & MOD_BIT(KC_LGUI)) && !(get_mods() & MOD_BIT(KC_LCTL))) {
                   unregister_mods(MOD_BIT(KC_LALT));
                   tap_code(KC_ENT);
                   add_mods(MOD_BIT(KC_LALT));
                   return false;
               }
           }
           return true;
    }
    return true;
};
