#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

bool is_alt_tab_active = false; 
uint16_t alt_tab_timer     = 0;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,  // can always be here
  EPRM,
  RGB_SLD,
  COMMENT,
  ENDCOMMENT,
  SHOPIFYDIR,
  CURLYPERCENT,
  SIGNATURE,
  LAZYIMAGE,
  MINIMIZE,
  DIV_WRAPPER,
  ALT_TAB,
};


//7 7 6 7 5 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRANSPARENT,
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TRANSPARENT,
    KC_BSPACE, KC_A, KC_R, KC_S, KC_T, KC_D,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRANSPARENT, 
    KC_LCTL, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,
    ALT_TAB, KC_LALT, KC_CAPSLOCK, LT(1,KC_ENTER),MT(MOD_LCTL, KC_BSPACE), LT(3, KC_TAB),

                         KC_TRANSPARENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
                         KC_TRANSPARENT, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_QUOTE,
                         KC_H, KC_N, KC_E, KC_I, KC_O, KC_MINUS, KC_TRANSPARENT,
                         KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
                         KC_GRAVE, KC_BSLASH, KC_LBRACKET, KC_RBRACKET, MO(2),
          KC_LGUI, KC_RALT, KC_CAPSLOCK, KC_DELETE, KC_ENTER, LT(2,KC_SPACE)),

    [1] = LAYOUT_ergodox(KC_TRANSPARENT, LALT(KC_F3), KC_SPACE, KC_ENTER, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_W),KC_TRANSPARENT,
    KC_DELETE, LCTL(KC_A), LCTL(KC_R), LCTL(KC_S), LCTL(KC_T), LCTL(KC_D),
    KC_TRANSPARENT, MO(3), MINIMIZE, RCTL(KC_F), LCTL(LSFT(KC_G)), LCTL(LSFT(KC_L)), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_PGUP), LCTL(KC_PGDOWN),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6, KC_PGUP, KC_PGDOWN, KC_LPRN, KC_RPRN, KC_PSCREEN, 
    KC_TRANSPARENT, KC_LBRACKET, KC_HOME, KC_UP, KC_END, KC_RBRACKET, KC_TRANSPARENT, 
    KC_LCBR, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR, KC_BSLASH, 
    KC_TRANSPARENT, KC_LPRN, KC_DQUO, KC_EQUAL, KC_QUOTE, KC_RPRN, KC_RSHIFT, 
    RSFT(KC_HOME), RSFT(KC_END), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LCTRL, KC_LALT, RSFT(KC_HOME), LSFT(KC_END), KC_ENTER, KC_SPACE),

    [2] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_MS_BTN2, KC_TRANSPARENT, 
    	KC_CAPSLOCK, KC_MS_ACCEL1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    	TG(4), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_WWW_HOME, KC_WWW_BACK, KC_MS_BTN3, KC_WWW_FORWARD, KC_TRANSPARENT, LGUI(KC_L), 
    KC_TRANSPARENT, KC_LBRACKET, KC_HOME, KC_UP, KC_END, KC_RBRACKET, KC_TRANSPARENT, 
    KC_LCBR, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR, KC_BSLASH, 
    KC_TRANSPARENT,LCTL(KC_Z),LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT),
    


    [3] = LAYOUT_ergodox(KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
     KC_TRANSPARENT, SHOPIFYDIR, SIGNATURE, COMMENT, ENDCOMMENT, KC_TRANSPARENT, KC_TRANSPARENT, 
     KC_CAPSLOCK, KC_TRANSPARENT, DIV_WRAPPER, LAZYIMAGE, CURLYPERCENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, COMMENT, ENDCOMMENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    KC_TRANSPARENT, KC_KP_SLASH, KC_7, KC_8, KC_9, KC_KP_MINUS, KC_F12, 
    KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS, KC_EQUAL, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL, KC_0),
    /*
    [4] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRANSPARENT,
                KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_B,KC_TRANSPARENT,
                KC_BSPACE,KC_A,KC_R,KC_S,KC_T,KC_G,
                KC_LSHIFT,KC_Z,KC_X,KC_C,KC_D,KC_V,KC_TRANSPARENT,
                KC_RCTRL,KC_GRAVE,KC_BSLASH,KC_RIGHT,KC_LEFT,
                KC_TRANSPARENT,KC_LALT,KC_CAPSLOCK,KC_BSPACE,KC_ENTER,KC_TAB,

                KC_TRANSPARENT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_DELETE,
                KC_TRANSPARENT,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_QUOTE,
                KC_K,KC_N,KC_E,KC_I,KC_O,KC_MINUS,
                KC_TRANSPARENT,KC_M,KC_H,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
                KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,
                KC_LGUI,KC_RCTRL,KC_PGUP,KC_PGDOWN,LT(5,KC_ENTER),KC_SPACE),
    */

    [4] = LAYOUT_ergodox(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRANSPARENT, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRANSPARENT, KC_BSPACE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE, KC_BSLASH, KC_LEFT, KC_RIGHT, KC_RCTRL, KC_LALT, KC_HOME, KC_TRANSPARENT, KC_BSPACE, KC_END,

                         KC_TRANSPARENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL, KC_TRANSPARENT, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_TRANSPARENT, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, KC_UP, KC_DOWN, KC_LBRACKET, KC_RBRACKET, KC_TRANSPARENT, KC_LGUI, KC_RCTRL, KC_PGUP, KC_PGDOWN, KC_ENTER, KC_SPACE),

    /*
      [6] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
    */
};

bool           suspended            = false;
const uint16_t PROGMEM fn_actions[] = {[1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;

    case COMMENT:
      if (record->event.pressed) {
        SEND_STRING("{% comment %}");
      }

      break;
    case ENDCOMMENT:
      if (record->event.pressed) {
        SEND_STRING("{% endcomment %}");
      }
      break;
    case SHOPIFYDIR:
      if (record->event.pressed) {
        SEND_STRING("C:\\Users\\User\\source\\Workspaces\\Shopify\\");
      }

      break;
    case CURLYPERCENT:
      if (record->event.pressed) {
        SEND_STRING("{%  %}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;

    case SIGNATURE:
      if (record->event.pressed) {
        SEND_STRING("Charles Chau");
      }
      break;

    case LAZYIMAGE:
      if (record->event.pressed) {
        SEND_STRING("img.lazyload[data-src = \"\"]");
        SEND_STRING(SS_TAP(X_TAB));
      }
      break;

    case MINIMIZE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_SPACE);
        unregister_code(KC_LALT);
        tap_code(KC_N);
      }
      break;
    case DIV_WRAPPER:
      if (record->event.pressed) {
        SEND_STRING("div.wrapper.wrapper--margin" SS_TAP(X_TAB));
      }
      break;

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
      }
  return true;
}

void matrix_scan_user(void) {
if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 700) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_2_off();
  ergodox_right_led_1_off();
  switch (layer) {
    case 1:
      ergodox_right_led_2_on();
      break;
    case 2:
      ergodox_right_led_1_on();
      break;
    case 3:
      ergodox_right_led_2_on();
      ergodox_right_led_1_on();
      break;

      // case 4:
      // ergodox_right_led_2_on();
      // ergodox_right_led_1_on();
      // break;
      // case 5:
      // ergodox_right_led_2_on();
      // ergodox_right_led_3_on();
      // break;
      // case 6:
      // ergodox_right_led_1_on();
      // ergodox_right_led_3_on();
      // break;
      // case 7:
      // ergodox_right_led_1_on();
      // ergodox_right_led_2_on();
      // ergodox_right_led_3_on();
      // break;
    default:
      break;
  }
  return state;
};
