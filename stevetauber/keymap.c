#include QMK_KEYBOARD_H
#include "keymap_slovenian.h"

#define _QWERTY 0
#define _HR 1
#define _FUNC 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  HR,
  FUNC,
};

int dance (qk_tap_dance_state_t *state);
void td_reset (qk_tap_dance_state_t *state, void *user_data);

enum td_keycodes {
  ENTER_SPOTLIGHT, // spotlight on tap, gui on hold
  SWITCH_SPACES,   // switch to space 1 or 2 
};

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
} td_state_options;

static td_state_options td_state_enter_spotlight;
void enter_spotlight_finished (qk_tap_dance_state_t *state, void *user_data);

static td_state_options td_state_switch_spaces;
void switch_spaces_finished (qk_tap_dance_state_t *state, void *user_data);


// Shortcut to make keymap more readable
#define MO_FUNC MO(_FUNC)
#define TG_HRHR TG(_HR)
#define TD_ESL  TD(ENTER_SPOTLIGHT)
#define TD_SWSP TD(SWITCH_SPACES)
#define LGA     LGUI(KC_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,MO_FUNC ,                          MO_FUNC ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,LGA     ,TG_HRHR ,        TG_HRHR ,LGA     ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_BSLS ,TD_SWSP ,KC_LALT ,     KC_SPC  ,    KC_LGUI ,TD_ESL  ,        KC_DEL  ,KC_BSPC ,    KC_ENT  ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_HR] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,RGB_M_P ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,_______ ,                          _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,RGB_TOG ,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PEQL ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_COMM ,KC_PDOT ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};


void td_reset (qk_tap_dance_state_t *state, void *user_data) {
}

// ENTER_SPOTLIGHT
int dance_es (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    }
    else {
      return SINGLE_HOLD;
    }
  } else { return SINGLE_TAP; } // Default to pressing enter
}

void enter_spotlight_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state_enter_spotlight = dance_es (state);
  switch (td_state_enter_spotlight) {
    case SINGLE_TAP:
      SEND_STRING(SS_TAP(X_ENTER));
      break;
    case SINGLE_HOLD:
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      break;
    default:
      break;
  }
}


// SWITCH_SPACES
int dance_ss (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    return SINGLE_TAP;
  } else if (state->count == 2) {
    return DOUBLE_TAP;
  } else { return SINGLE_TAP; } // Default to screen 1
}


void switch_spaces_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state_switch_spaces = dance_ss (state);
  switch (td_state_switch_spaces) {
    case SINGLE_TAP:
      SEND_STRING(SS_LCTL(SS_TAP(X_1)));
      break;
    case DOUBLE_TAP:
      SEND_STRING(SS_LCTL(SS_TAP(X_2)));
      break;
    default:
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENTER_SPOTLIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter_spotlight_finished, td_reset),
  [SWITCH_SPACES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, switch_spaces_finished, td_reset)
};
