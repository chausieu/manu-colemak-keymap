#include "ergodox_ez.h"
#include "action_layer.h"
#include "version.h"

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
  CONSOLE_LOG,
  JUSTIFYCONTENT,
  ALIGNITEMS,
  ASSIGN,
  APPEND,
  RENDER,
  PSEUDODIV,
  render_img,
  liteYoutube,
  className,
  CLASS,
  STYLE,
  YTIMG,
  DELETEMETAFIELD,
  GITADD,
  GITCOMMIT,
  GITPUSH,
  GITPULL,
  THEMEWATCH,
  COM,
  MAKE,
  YOUR,
  YOU,
  WITH,
  DEGREE,
  TRADE,
  REG,
  YOURE,
  CONSTANT,
  LAMDA,
  THANKS,
  COULD,
  STRING,
  RENAME,
  PRODUCTS,
  PAGES,
  premio,
  DONE,
  THANKYOU,
};



const uint16_t PROGMEM classname_combo[] = {KC_C, KC_L, KC_E, COMBO_END};
const uint16_t PROGMEM class_combo[] = {KC_C, KC_L, KC_X, COMBO_END};
const uint16_t PROGMEM style_combo[] = {KC_S, KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM ytimg_combo[] = {KC_I, KC_T, KC_A, COMBO_END};
const uint16_t PROGMEM dltmetafield_combo[] = {KC_D, KC_M, KC_E, COMBO_END};
const uint16_t PROGMEM signature_combo[] = {KC_S, KC_I, KC_G, COMBO_END};
const uint16_t PROGMEM gitadd_combo[] = {KC_H, KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM gitcommit_combo[] = {KC_H, KC_I, KC_C, COMBO_END};
const uint16_t PROGMEM gitpush_combo[] = {KC_H, KC_I, KC_P, COMBO_END};
const uint16_t PROGMEM gitpull_combo[] = {KC_H, KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM themewatch_combo[] = {KC_T, KC_H, KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM com_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM make_combo[] =  { KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM with_combo[] =  { KC_W, KC_SLASH, COMBO_END};
const uint16_t PROGMEM your_combo[] =  { KC_U, KC_R, COMBO_END};
const uint16_t PROGMEM you_combo[] =  { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM degree_combo[] =  { KC_D, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM trade_combo[] =  { KC_T, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM reg_combo[] =  { KC_R, KC_E, KC_G, COMBO_END};
const uint16_t PROGMEM youre_combo[] =  { KC_Y, KC_R, COMBO_END};
const uint16_t PROGMEM const_combo[] =  { KC_C, KC_T, COMBO_END};
const uint16_t PROGMEM lamda_combo[] =  { KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM thanks_combo[] =  { KC_T, KC_K, KC_S, COMBO_END};
const uint16_t PROGMEM rename_combo[] = {KC_D, KC_I, KC_R, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM products_combo[] =  { KC_P, KC_R, KC_SLASH, COMBO_END};
const uint16_t PROGMEM pages_combo[] =  { KC_P, KC_A, KC_SLASH, COMBO_END};
const uint16_t PROGMEM premio_combo[] = { KC_P, KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM the_combo[] = { KC_T, KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM dot_combo[] = { KC_D, KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM done_combo[] = { KC_D, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM thankyou_combo[] = {KC_T, KC_K, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(classname_combo, className),
  COMBO(class_combo, CLASS),
  COMBO(style_combo, STYLE),
  COMBO(ytimg_combo, YTIMG),
  COMBO(dltmetafield_combo, DELETEMETAFIELD),
  COMBO(signature_combo, SIGNATURE),
  COMBO(gitadd_combo, GITADD),
  COMBO(gitcommit_combo, GITCOMMIT),
  COMBO(gitpush_combo, GITPUSH),
  COMBO(gitpull_combo, GITPULL),
  COMBO(themewatch_combo, THEMEWATCH),
  COMBO(com_combo, COM),
  COMBO(make_combo, MAKE),
  COMBO(with_combo, WITH),
  COMBO(your_combo, YOUR),
  COMBO(you_combo, YOU),
  COMBO(degree_combo, UC(0x00b0)),
  COMBO(trade_combo, UC(0x2122)),
  COMBO(reg_combo, UC(0x00ae)),
  COMBO(youre_combo, YOURE),
  COMBO(const_combo, CONSTANT),
  COMBO(lamda_combo, LAMDA),
  COMBO(thanks_combo, THANKS),
  COMBO(rename_combo, RENAME),
  COMBO(products_combo, PRODUCTS),
  COMBO(pages_combo, PAGES),
  COMBO(premio_combo, premio),
  COMBO(dot_combo,UC(0x2022)),
  COMBO(done_combo, DONE),
  COMBO(thankyou_combo, THANKYOU),
};

//7 7 6 7 5 KC
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRANSPARENT,
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TRANSPARENT,
    KC_BSPACE, KC_A, KC_R, KC_S, KC_T, KC_D,
    KC_LSHIFT, LT(4, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_TRANSPARENT, 
    LT(3, KC_LEFT), LT(5,KC_RIGHT), LT(6,KC_UP), KC_DOWN, 
    LT(1,KC_ENTER), MT(MOD_LSFT, KC_BSPACE), MT(MOD_LALT, KC_DELETE), KC_CAPSLOCK, MT(MOD_LCTL, KC_TAB), ALT_TAB, KC_TRANSPARENT,

     KC_TRANSPARENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
     KC_TRANSPARENT, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_QUOTE, 
     KC_H, KC_N, KC_E, KC_I, KC_O, KC_MINUS, 
     KC_TRANSPARENT, KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
     KC_SPACE, KC_BSLASH, KC_LBRACKET, KC_RBRACKET, LT(3, KC_GRAVE), 
     KC_LGUI, LT(2,KC_ENTER), MT(MOD_RSFT, KC_TAB), KC_TRANSPARENT, KC_RCTL, KC_DELETE),

    [1] = LAYOUT_ergodox(KC_TRANSPARENT, LALT(KC_F3), KC_SPACE, LCTL(KC_COMMA), LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRANSPARENT,
    KC_TRANSPARENT, LALT(KC_F3), LCTL(KC_W), LCTL(KC_F), LCTL(LSFT(KC_G)), LCTL(LSFT(KC_L)),KC_TRANSPARENT,
    KC_DELETE, RCTL(KC_A), LCTL(KC_R), LCTL(KC_S), LCTL(KC_T), LCTL(KC_D),
    KC_TRANSPARENT, LCTL(KC_Z), LCTL(KC_X), RCTL(KC_C), RCTL(KC_V), RCTL(LSFT(KC_B)), KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(LSFT(KC_Z)), KC_WWW_BACK, LCTL(KC_PGDOWN), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6, KC_PGUP, KC_PGDOWN, KC_LPRN, KC_RPRN, KC_PSCREEN, 
    KC_TRANSPARENT, LSFT(KC_HOME), KC_HOME, KC_UP, KC_END, LSFT(KC_END), KC_TRANSPARENT, 
    KC_LCBR, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR, KC_BSLASH, 
    KC_TRANSPARENT, KC_LPRN, KC_DQUO, KC_EQUAL, KC_QUOTE, KC_RPRN, KC_RSHIFT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LCTRL, KC_LALT, RSFT(KC_HOME), LSFT(KC_END), KC_TRANSPARENT, KC_LSHIFT),

    [2] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_WWW_FORWARD, KC_TRANSPARENT, 
    	KC_CAPSLOCK, KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WWW_BACK, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_TRANSPARENT, KC_TRANSPARENT, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL2, KC_MS_ACCEL1, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_WWW_HOME, KC_WWW_BACK, KC_MS_BTN3, KC_WWW_FORWARD, KC_TRANSPARENT, LGUI(KC_L), 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR, KC_BSLASH, 
    KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT),

    [3] = LAYOUT_ergodox(KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
     SHOPIFYDIR, SHOPIFYDIR, JUSTIFYCONTENT, ALIGNITEMS, LCTL(KC_P), liteYoutube, KC_TRANSPARENT, 
     KC_CAPSLOCK, CONSOLE_LOG, DIV_WRAPPER, LAZYIMAGE, CURLYPERCENT, render_img, 
    KC_TRANSPARENT, CURLYPERCENT, KC_TRANSPARENT, COMMENT, ENDCOMMENT, PSEUDODIV, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, GITADD, GITCOMMIT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    KC_TRANSPARENT, KC_KP_SLASH, KC_7, KC_8, KC_9, KC_KP_MINUS, KC_F12, 
    KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS, KC_EQUAL, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL, KC_0),

    [4] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_P),LCTL(KC_G),KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,APPEND,ASSIGN,RENDER,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,LALT(LCTL(LSFT(KC_W))),LALT(LCTL(KC_I)),LALT(LCTL(KC_C)),KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LCTL(KC_E)),
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

    [5] = LAYOUT_ergodox(MO(6), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP), LCTL(KC_PGDOWN),LALT(LCTL(KC_E)),

        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

    [6] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

    [7] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_7,KC_8,KC_9,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_4,KC_5,KC_6,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_1,KC_2,KC_3,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_DOT,KC_0,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
    
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
        SEND_STRING("img.[loading=\"lazy\" width=\"\" height=\"\"]");
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
        SEND_STRING("div.container" SS_TAP(X_TAB));
      }
      break;
    case CONSOLE_LOG:
      if (record->event.pressed){
        SEND_STRING("console.log()" SS_TAP(X_LEFT));
      }
      break;
    case liteYoutube: 
      if (record->event.pressed){
        SEND_STRING("lite-youtube.[videoid playlabel]");
        SEND_STRING(SS_LCTL("e"));
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

      case JUSTIFYCONTENT:
        if (record->event.pressed){
          SEND_STRING("justify-content-");
        }
        break;
      case ALIGNITEMS:
        if (record->event.pressed){
          SEND_STRING("align-items-");
        }
        break; 
      case ASSIGN: 
        if (record->event.pressed){
          SEND_STRING("{% assign  %}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;
      case APPEND:
        if (record->event.pressed){
          SEND_STRING("| append: '");
        }
        break;
      case RENDER: 
        if (record->event.pressed){
          SEND_STRING("{% render  %}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;

      case render_img: 
        if (record->event.pressed){
          SEND_STRING("{% render 'img' with  %}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) );
        }
        break;
      case PSEUDODIV:
        if(record->event.pressed){
          SEND_STRING("content: '';" SS_TAP(X_ENTER));
          SEND_STRING("position: absolute;" SS_TAP(X_ENTER));
          SEND_STRING("width: 100%;" SS_TAP(X_ENTER));
          SEND_STRING("height: 100%;" SS_TAP(X_ENTER));
          SEND_STRING("top: 0;" SS_TAP(X_ENTER));
          SEND_STRING("left: 0;" SS_TAP(X_ENTER));
        }
      break;
      case className: 
      if(record->event.pressed){
        SEND_STRING("className=\"\"" SS_TAP(X_LEFT));
      }
      break;
      case CLASS: 
      if(record->event.pressed){
        SEND_STRING("class=\"\"" SS_TAP(X_LEFT));
      }
      break;
      case STYLE: 
      if(record->event.pressed){
        SEND_STRING("style=");
      }
      break;
      case YTIMG: 
      if(record->event.pressed){
        SEND_STRING("https://i.ytimg.com/vi//hqdefault.jpg" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;

      case DELETEMETAFIELD: 
      if(record->event.pressed){
        SEND_STRING("'+DELETE_METAFIELD+");
      }
      break;

      case GITADD: 
      if(record->event.pressed){
        SEND_STRING("git add .");
      }
      break;

      case GITCOMMIT: 
      if(record->event.pressed){
        SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
      }
      break;
     
      case GITPUSH: 
      if(record->event.pressed){
        SEND_STRING("git push origin ");
      }
      break;
      case GITPULL: 
      if(record->event.pressed){
        SEND_STRING("git pull");
      }
      break;
      case THEMEWATCH: 
      if(record->event.pressed){
        SEND_STRING("theme watch -e ");
      }
      break;

      case COM :
      if(record->event.pressed){
        SEND_STRING("com ");
      }
      break;

      case MAKE :
      if(record->event.pressed){
        SEND_STRING("make ");
      }
      break;
        case YOUR :
      if(record->event.pressed){
        SEND_STRING("your ");
      }
      break;
        case YOU :
      if(record->event.pressed){
        SEND_STRING("you ");
      }
      break;
        case WITH :
      if(record->event.pressed){
        SEND_STRING("with ");
      }
      break;
       
        case YOURE :
      if(record->event.pressed){
        SEND_STRING("you're ");
      }
      break;
        case CONSTANT :
      if(record->event.pressed){
        SEND_STRING("const ");
      }
      break;
        case LAMDA :
      if(record->event.pressed){
        SEND_STRING("=> {}" SS_TAP(X_LEFT) SS_TAP(X_ENTER));
      }
      break;

      case THANKS :
      if(record->event.pressed){
        SEND_STRING("Thanks");
      }
      break;
      case COULD :
      if(record->event.pressed){
        SEND_STRING("could ");
      }
      break;

      case STRING : 
      if (record->event.pressed){
        SEND_STRING("string");
      }
      break;

      case RENAME: 
      if (record->event.pressed){
        SEND_STRING("dir | rename-item -newname {$_.name -replace \"\"}" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;

      case PRODUCTS: 
      if (record->event.pressed){
        SEND_STRING("/products/");
      }
      break;

      case PAGES: 
      if (record->event.pressed){
        SEND_STRING("/pages/");
      }
      break;

      case premio: 
      if (record->event.pressed){
        SEND_STRING("premioinc.com");
      }
      break;

      case DONE: 
      if (record->event.pressed){
        SEND_STRING("done");
      }
      break;

      case THANKYOU: 
      if (record->event.pressed){
        SEND_STRING("Thank you");
      }
      break;
  }
  return true;

}

void matrix_scan_user(void) {
if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 400) {
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

uint32_t layer_state_set_user(uint32_t state) 
{
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_2_off();
  ergodox_right_led_1_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
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
