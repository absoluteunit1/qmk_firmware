#include QMK_KEYBOARD_H
#include <stdio.h>
#include "qmk-vim/src/vim.h"
#include "features/sentence_case.h"

enum custom_keycodes {
    VIMTOG = SAFE_RANGE,
    RAYCAST,
    WINDOWS, // opens all applications via raycast
    CUSTOM_CAPS,
    CLIPBOARD_HISTORY,
    FZF_AUTOCOMPLETE,
    SPEECH_TO_TEXT,
    SCREENSHOT,
};

enum tap_dance_keycodes {
     TD_Q_CAPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(
	    KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P,
	    LT(2, KC_A), KC_S, KC_D, KC_F, KC_G,                            KC_H, KC_J, KC_K, KC_L, LT(3, KC_SCLN),
	    LSFT_T(KC_Z), LALT_T(KC_X), LGUI_T(KC_C), LCTL_T(KC_V), KC_B,   KC_N, RCTL_T(KC_M), RGUI_T(KC_COMM), RALT_T(KC_DOT), RSFT_T(KC_SLSH),
	    LM(6, MOD_LGUI), LT(1, KC_TAB), KC_SPC,                         KC_BSPC, LT(4, KC_MINUS), LT(5, KC_ESC)
	),
	[1] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_LPRN, KC_RPRN, KC_NO, CUSTOM_CAPS,
        KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_NO,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR, QK_CAPS_WORD_TOGGLE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO,
        KC_NO, KC_TRNS, KC_NO,                                          KC_NO, KC_NO, KC_NO
	),
	[2] = LAYOUT_split_3x5_3(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_TILD, KC_DQT, KC_QUOT, KC_AMPR, KC_PIPE,
	    KC_TRNS, KC_NO, KC_NO, KC_COLON, KC_NO,                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, KC_GRV, KC_NO, KC_EXLM, KC_BSLS,
	    KC_NO, FZF_AUTOCOMPLETE, VIMTOG,                                RAYCAST, WINDOWS, CLIPBOARD_HISTORY
    ),
	[3] = LAYOUT_split_3x5_3(
	    KC_AT, KC_1, KC_2, KC_3, KC_PLUS,                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_0, KC_4, KC_5, KC_6, KC_EQL,                                 KC_NO, KC_J, KC_K, KC_NO, KC_NO,
	    KC_ASTR, KC_7, KC_8, KC_9, KC_MINUS,                            KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO,
        KC_PERC, KC_HASH, KC_TRNS,                                      KC_TRNS, KC_NO, KC_NO
    ),
	[4] = LAYOUT_split_3x5_3(
	    KC_NO, KC_F1, KC_F2, KC_F3, KC_NO,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F10, KC_F4, KC_F5, KC_F6, KC_NO,                             KC_TRNS, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
	    KC_NO, KC_F7, KC_F8, KC_F9, KC_NO,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_NO, SCREENSHOT, SPEECH_TO_TEXT,                              KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[5] = LAYOUT_split_3x5_3(
	    KC_NO, KC_F11, KC_F12, KC_F13, KC_NO,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F20, KC_F14, KC_F15, KC_F16, KC_NO,                          KC_TRNS, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
	    KC_NO, KC_F17, KC_F18, KC_F19, KC_NO,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_SLEP, QK_BOOT, KC_TRNS,                                      KC_NO, KC_NO, KC_TRNS
    ),
    [6] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, HYPR(KC_F12), HYPR(KC_F13), HYPR(KC_F14), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              LSFT(KC_TAB), KC_NO, KC_NO, KC_TAB, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                              KC_NO, HYPR(KC_F11), KC_NO, KC_NO, KC_L,
        KC_TRNS, KC_NO, KC_NO,                                          KC_NO, KC_NO, KC_NO
    ),
};

const uint16_t PROGMEM enter_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_S, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(enter_combo, KC_ENT),
    COMBO(esc_combo, KC_ESC),
};

 // Tap Dance definitions
 tap_dance_action_t tap_dance_actions[] = {
     // Tap once for Escape, twice for Caps Lock
     [TD_Q_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_CAPS),
 };


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_MINUS):
            return 200;
        case LT(2, KC_A):
            return 195;
        case LT(3, KC_SCLN):
            return 195;
        case LT(1, KC_TAB):
            return 195;
        case LSFT_T(KC_Z):
            return 195;
        case LALT_T(KC_X):
            return 195;
        case LGUI_T(KC_C):
            return 195;
        case LCTL_T(KC_V):
            return 195;
        case RCTL_T(KC_M):
            return 195;
        case RGUI_T(KC_COMM):
            return 195;
        case RALT_T(KC_DOT):
            return 195;
        case RSFT_T(KC_SLSH):
            return 195;
        default:
            return TAPPING_TERM;
    }
}


const key_override_t left_word_override = ko_make_basic(MOD_MASK_ALT, KC_H, LALT(KC_LEFT));
const key_override_t right_word_override = ko_make_basic(MOD_MASK_ALT, KC_L, LALT(KC_RIGHT));
const key_override_t shift_space_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_TAB);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &left_word_override,
    &right_word_override,
    &shift_space_override,
    NULL
};

bool caps_lock_state = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_sentence_case(keycode, record)) { return false; }
    if (!process_vim_mode(keycode, record)) { return false; }

    switch (keycode) {

        case SPEECH_TO_TEXT:
            if (record->event.pressed) {
                tap_code16(HYPR(KC_N));
            }
            return false;

        case SCREENSHOT:
            if (record->event.pressed) {
                tap_code16(HYPR(KC_S));
            }
            return false;

        case FZF_AUTOCOMPLETE:
            if (record->event.pressed) {
                SEND_STRING("**");
                tap_code(KC_TAB);
            }
            return false;

        case CLIPBOARD_HISTORY:
            if (record->event.pressed) {
                tap_code16(HYPR(KC_C));
            }
            return false;

        case CUSTOM_CAPS:
            if (record->event.pressed) {
                if (caps_lock_state) {
                    caps_lock_state = false;
                } else {
                    caps_lock_state = true;
                }
                tap_code(KC_CAPS);
            }
            return false;

        case KC_ESC:
            if (record->event.pressed) {
                if (caps_lock_state) {
                    tap_code(KC_CAPS);
                    caps_lock_state = false;
                }
                caps_word_off();
                tap_code(KC_ESC);
            }
            return false;

        case WINDOWS:
            if (record->event.pressed) {
                tap_code16(HYPR(KC_W));
            }
            return false;

        case RAYCAST:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI));
                tap_code(KC_SPC);
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            return false;

        case VIMTOG:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;

        // This will do most of the grunt work with the keycodes.
        case KC_S:
            if (record->event.pressed && record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_mods(MOD_BIT(KC_LGUI));
                    tap_code(KC_C);
                    tap_code(KC_S);
                    add_mods(MOD_BIT(KC_LGUI));
                    return false;
                }
            }
            return true;

        case KC_E:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    tap_code(KC_V);
                    tap_code(KC_E);
                    add_mods(MOD_BIT(KC_LCTL));
                    return false;
                }
            }
            return true;

        case KC_R:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_mods(MOD_BIT(KC_LGUI));
                    tap_code(KC_C);
                    tap_code(KC_R);
                    add_mods(MOD_BIT(KC_LGUI));
                    return false;
                }
            }
            return true;

        case KC_A:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_mods(MOD_BIT(KC_LGUI));
                    tap_code(KC_C);
                    tap_code(KC_A);
                    add_mods(MOD_BIT(KC_LGUI));
                    return false;
                }
            }
            return true;

       case KC_O:
           if (record->event.pressed) {
               if (get_mods() & MOD_BIT(KC_RCTL)) {
                   unregister_mods(MOD_BIT(KC_RCTL));
                   tap_code(KC_M);
                   tap_code(KC_O);
                   add_mods(MOD_BIT(KC_RCTL));
                   return false;
               }
           }
           return true;

       case KC_I:
           if (record->event.pressed) {
               if (get_mods() & MOD_BIT(KC_RCTL)) {
                   unregister_mods(MOD_BIT(KC_RCTL));
                   tap_code(KC_M);
                   tap_code(KC_I);
                   add_mods(MOD_BIT(KC_RCTL));
                   return false;
               }
           }
           return true;

       // todo: create custom alt modifiers to create symbols
       case RGUI_T(KC_COMM):
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
    }
    return true;
};
