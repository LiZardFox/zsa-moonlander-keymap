#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif



static uint8_t numl_state = 0;
bool numlock_changed = false;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_ctrl_tab_active = false;
uint16_t ctrl_tab_timer = 0;


#ifdef AUDIO_ENABLE
float one_up_sound[][2] = SONG(ONE_UP_SOUND);
float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float numl_on[][2] = SONG(NUM_LOCK_ON_SOUND);
float numl_off[][2] = SONG(NUM_LOCK_OFF_SOUND);
float caps_word_on_song[][2] = SONG(ZELDA_PUZZLE);
float caps_word_off_song[][2] = SONG(ZELDA_TREASURE);
#endif



enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  
  ALT_TAB,
  CTRL_TAB,
  SHFT_ALT_TAB,
  SHFT_CTRL_TAB,
  EURO_SIGN,
  EMPT_FUNC,
  NOTE_PAD,
  VS_CODE,
  VS_WIND_LEFT,
  VS_WIND_RIGHT,
  GER_AE,
  GER_OE,
  GER_UE,
  GER_SZ,
  SM_SLEP,
  SM_POWR,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
};

#define DUAL_FUNC_0 LT(1, KC_S)
#define DUAL_FUNC_1 LT(3, KC_F18)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         TD(DANCE_1),    
    KC_BSLS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRANSPARENT,                                 TD(DANCE_2),    KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    LT(4, KC_EQUAL),MT(MOD_LALT, KC_A),LT(2, KC_O),    MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_U),KC_I,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_D,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),LT(2, KC_N),    MT(MOD_RALT, KC_S),LT(3, KC_MINUS),
    SH_OS,          KC_SCLN,        KC_Q,           MEH_T(KC_J),    KC_K,           KC_X,                                           KC_B,           KC_M,           MEH_T(KC_W),    KC_V,           KC_Z,           SH_OS,         
    TT(2),          TT(4),          TT(5),          DM_REC1,        QK_ALT_REPEAT_KEY,         DM_PLY1,                                                                                                        DM_PLY2,        QK_REPEAT_KEY,         DM_REC2,        TT(5),          TT(4),          TT(2),          
    LT(5, KC_BSPC), OSM(MOD_LSFT),  MT(MOD_LGUI, KC_ESCAPE),                KC_RIGHT_GUI,   LT(4, KC_ENTER),KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    TD(DANCE_3),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_STENO_BOLT,                                  QK_STENO_GEMINI,KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TD(DANCE_4),    
    KC_NO,          STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_NO,                                          KC_NO,          STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         
    KC_NO,          STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_NO,                                                                          KC_NO,          STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,         
    KC_NO,          STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                        STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,         
    SHFT_ALT_TAB,         KC_NO,          KC_NO,          KC_NO,          KC_LEFT_CTRL,   KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          ALT_TAB,         
    STN_A,          STN_O,          STN_NC,                         STN_NC,         STN_E,          STN_U
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NUM,         KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_CALCULATOR,                                  KC_TILD,        KC_GRAVE,       KC_LCBR,        KC_RCBR,        KC_EXLM,        KC_AT,          KC_TRANSPARENT, 
    KC_KP_MINUS,    KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_DOT,      ST_MACRO_0,                                                                     KC_TRANSPARENT, KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_HASH,        KC_DLR,         KC_TRANSPARENT, 
    KC_KP_ENTER,    KC_KP_PLUS,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_COMMA,                                    KC_ASTR,        KC_LBRC,        KC_RBRC,        KC_PERC,        KC_CIRC,        KC_PIPE,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 ST_MACRO_2,     QK_DYNAMIC_TAPPING_TERM_UP,LCTL(LSFT(KC_F12)),LALT(LCTL(KC_UP)),LCTL(KC_F12),   KC_TRANSPARENT, KC_TRANSPARENT, 
    AC_TOGG,         ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_GRAVE)),KC_BSPC,        KC_TRANSPARENT,                                                                 ST_MACRO_3,     QK_DYNAMIC_TAPPING_TERM_PRINT,ST_MACRO_4,     TD(DANCE_5),    ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT, 
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 QK_DYNAMIC_TAPPING_TERM_DOWN,LCTL(KC_I),     LALT(LCTL(KC_DOWN)),LALT(LCTL(KC_I)),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,                                                                                                RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     DUAL_FUNC_0,    KC_UP,          DUAL_FUNC_1,    KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, SHFT_ALT_TAB,         ALT_TAB,         SHFT_CTRL_TAB,         CTRL_TAB,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_WWW_BACK,    KC_WWW_FORWARD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_UP,    KC_APPLICATION, 
    KC_TRANSPARENT, OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     LGUI(KC_V),     LCTL(LSFT(KC_V)),                                KC_AUDIO_MUTE,  KC_MS_WH_LEFT,  KC_MS_BTN3,     KC_MS_WH_RIGHT, KC_MS_JIGGLER_TOGGLE,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN4,     KC_MS_BTN5,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1
  ),
  [6] = LAYOUT_moonlander(
    TD(DANCE_6),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_7),    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_8),    
    KC_BSPC,        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ESCAPE,      KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_DELETE,      KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NO,          KC_TRANSPARENT, OSL(8),         KC_LEFT_ALT,    KC_B,           KC_ENTER,                                                                                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_SPACE,       MO(7),                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Y,           KC_O,           KC_I,           KC_U,           KC_P,           KC_Y,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_T,           KC_1,           KC_2,           KC_3,           KC_H,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_J,           KC_K,           KC_L,           KC_M,           KC_N,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, QK_LLCK,        LALT(LCTL(KC_7)),LALT(LCTL(KC_8)),LALT(LCTL(KC_9)),KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_J),     LALT(LCTL(KC_4)),LALT(LCTL(KC_5)),LALT(LCTL(KC_6)),KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(LCTL(KC_0)),LALT(LCTL(KC_1)),LALT(LCTL(KC_2)),LALT(LCTL(KC_3)),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
                 '*', '*', '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_Q, MT(MOD_LSFT, KC_E), LT(2, KC_O), MEH_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_D, KC_C, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_SCLN, MT(MOD_LALT, KC_A), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_Q, LT(2, KC_O), COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LCTL, KC_U), KC_K, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_Z, MT(MOD_RALT, KC_S), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_A, KC_Z, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_O, KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_SCLN, MT(MOD_LSFT, KC_E), LT(2, KC_O), MT(MOD_LALT, KC_A), KC_Q, MEH_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_CAPS, KC_LEFT_CTRL, KC_Z, KC_A, KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo16[] = { KC_Q, MT(MOD_RSFT, KC_T), LT(2, KC_N), MEH_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo17[] = { MT(MOD_LSFT, KC_E), KC_V, LT(2, KC_O), MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo18[] = { MT(MOD_RSFT, KC_T), MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_M, MT(MOD_RSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo20[] = { MT(MOD_RSFT, KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo21[] = { LT(2, KC_N), KC_V, MT(MOD_RSFT, KC_T), MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo22[] = { MT(MOD_RCTL, KC_H), KC_M, KC_V, LT(2, KC_N), COMBO_END};
const uint16_t PROGMEM combo23[] = { MT(MOD_RCTL, KC_H), KC_M, MEH_T(KC_W), MT(MOD_RSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo24[] = { MT(MOD_RCTL, KC_H), MEH_T(KC_W), KC_V, COMBO_END};
const uint16_t PROGMEM combo25[] = { LT(2, KC_N), KC_V, COMBO_END};
const uint16_t PROGMEM combo26[] = { KC_M, MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(2, KC_N), KC_V, MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo27[] = { KC_M, MT(MOD_RSFT, KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo28[] = { MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), MEH_T(KC_W), KC_V, COMBO_END};
const uint16_t PROGMEM combo29[] = { KC_V, MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo30[] = { KC_M, MEH_T(KC_W), COMBO_END};
const uint16_t PROGMEM combo31[] = { MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(2, KC_N), COMBO_END};
const uint16_t PROGMEM combo32[] = { KC_M, MEH_T(KC_W), KC_V, COMBO_END};
const uint16_t PROGMEM combo33[] = { KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo34[] = { DUAL_FUNC_0, KC_UP, DUAL_FUNC_1, COMBO_END};
const uint16_t PROGMEM combo35[] = { KC_DOWN, KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo36[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo37[] = { KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo39[] = { MEH_T(KC_W), KC_M, KC_K, MEH_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_RIGHT_GUI, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo41[] = { KC_SPACE, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo42[] = { MT(MOD_RCTL, KC_H), MT(MOD_LCTL, KC_U), MT(MOD_RSFT, KC_T), MT(MOD_LSFT, KC_E), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LGUI(KC_DOT)),
    COMBO(combo1, LALT(KC_TAB)),
    COMBO(combo2, ST_MACRO_6),
    COMBO(combo3, ST_MACRO_7),
    COMBO(combo4, ST_MACRO_8),
    COMBO(combo5, ST_MACRO_9),
    COMBO(combo6, KC_MEDIA_PLAY_PAUSE),
    COMBO(combo7, KC_4),
    COMBO(combo8, KC_5),
    COMBO(combo9, KC_6),
    COMBO(combo10, KC_7),
    COMBO(combo11, KC_8),
    COMBO(combo12, KC_9),
    COMBO(combo13, KC_0),
    COMBO(combo14, TO(6)),
    COMBO(combo15, TO(0)),
    COMBO(combo16, KC_QUES),
    COMBO(combo17, KC_EXLM),
    COMBO(combo18, KC_PIPE),
    COMBO(combo19, KC_SLASH),
    COMBO(combo20, KC_BSLS),
    COMBO(combo21, KC_EQUAL),
    COMBO(combo22, KC_HASH),
    COMBO(combo23, KC_PERC),
    COMBO(combo24, KC_AMPR),
    COMBO(combo25, KC_COLN),
    COMBO(combo26, KC_AT),
    COMBO(combo27, KC_CIRC),
    COMBO(combo28, KC_TILD),
    COMBO(combo29, KC_UNDS),
    COMBO(combo30, KC_SCLN),
    COMBO(combo31, KC_LPRN),
    COMBO(combo32, KC_RPRN),
    COMBO(combo33, LCTL(KC_LEFT)),
    COMBO(combo34, LCTL(KC_HOME)),
    COMBO(combo35, LCTL(KC_END)),
    COMBO(combo36, LCTL(KC_RIGHT)),
    COMBO(combo37, LSFT(KC_TAB)),
    COMBO(combo38, KC_TAB),
    COMBO(combo39, CW_TOGG),
    COMBO(combo40, KC_CAPS),
    COMBO(combo41, CW_TOGG),
    COMBO(combo42, QK_LEAD),
};

extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {21,237,224}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {73,158,185}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {175,172,207}, {21,237,224}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {73,158,185}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {175,172,207} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {40,240,174}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {190,238,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,54,140}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {221,236,121}, {176,241,174}, {21,237,224}, {0,0,0}, {0,0,0}, {176,241,174}, {144,199,242}, {176,241,174}, {0,0,0}, {0,0,0}, {221,236,121}, {176,241,174}, {21,237,224}, {0,0,0}, {20,230,227}, {74,255,255}, {74,255,255}, {74,255,255}, {0,218,204}, {131,219,203}, {148,219,203}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {69,201,230}, {0,0,0}, {0,0,0}, {123,232,160}, {20,250,216}, {69,201,230}, {0,0,0}, {0,0,0}, {20,250,216}, {20,250,216}, {199,255,176}, {0,0,0}, {0,0,0}, {123,232,160}, {20,250,216}, {199,255,176}, {0,0,0}, {0,0,0}, {0,207,168}, {0,207,168}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,250,106}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {139,250,106}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {139,250,106}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {139,250,106}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {0,255,112}, {0,0,0}, {0,0,0}, {180,227,168}, {20,250,216}, {172,255,255}, {0,0,0}, {0,0,0}, {20,250,216}, {20,250,216}, {180,227,168}, {123,255,255}, {0,0,0}, {180,227,168}, {20,250,216}, {172,255,255}, {123,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {180,227,168}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {32,226,188}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,104}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {186,255,112}, {0,0,0}, {0,0,0}, {0,224,133}, {0,218,204}, {198,255,112}, {0,0,0}, {0,0,0}, {104,179,197}, {19,218,204}, {216,255,112}, {0,0,0}, {0,0,0}, {192,224,133}, {40,218,204}, {20,255,65}, {0,0,0}, {0,0,0}, {28,174,241}, {0,255,112}, {238,218,204}, {0,0,0}, {247,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,226,188}, {0,0,0}, {197,243,86}, {0,0,0}, {0,0,0}, {197,243,86}, {197,243,86}, {197,243,86}, {0,0,0}, {0,0,0}, {197,243,86}, {197,243,86}, {197,243,86}, {0,0,0}, {0,0,0}, {197,243,86}, {197,243,86}, {197,243,86}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
      case 6:
        set_layer_color(6);
        break;
      case 7:
        set_layer_color(7);
        break;
      case 8:
        set_layer_color(8);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[9];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: layer_move(1); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(1); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: layer_move(1); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(1); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    }
    dance_state[1].step = 0;
}
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case DOUBLE_TAP: register_code16(LGUI(KC_L)); break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
    }
    dance_state[2].step = 0;
}
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    }
    dance_state[3].step = 0;
}
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
    }
    dance_state[5].step = 0;
}
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[7].step = 0;
}
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
    }
    dance_state[8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_8_finished, dance_8_reset),
};



static void tap_kp_code(char code[5]){
  int i;
  for (i = 0; code[i] != 0; i++){
    switch (code[i])
    {
    case '0':
      tap_code(KC_KP_0);
      break;
    case '1':
      tap_code(KC_KP_1);
      break;
    case '2':
      tap_code(KC_KP_2);
      break;
    case '3':
      tap_code(KC_KP_3);
      break;
    case '4':
      tap_code(KC_KP_4);
      break;
    case '5':
      tap_code(KC_KP_5);
      break;
    case '6':
      tap_code(KC_KP_6);
      break;
    case '7':
      tap_code(KC_KP_7);
      break;
    case '8':
      tap_code(KC_KP_8);
      break;
    case '9':
      tap_code(KC_KP_9);
      break;
    
    default:
      break;
    }
  }
}

static void process_alt_num_key_with_shift(char code[5], char shiftedCode[5]){
  uint8_t mods = get_mods();
  bool num_lock = host_keyboard_led_state().num_lock;
  bool caps = host_keyboard_led_state().caps_lock || is_caps_word_on();
  bool shift = (mods&MOD_MASK_SHIFT)!=0;
  if (!num_lock)
  {
    tap_code(KC_NUM);
  }
  clear_mods();
  register_code(KC_LALT);
  if(caps != shift){
    tap_kp_code(shiftedCode);
  }
  else
  {
    tap_kp_code(code);
  }
  unregister_code(KC_LALT);
  set_mods(mods);
  if (!num_lock)
  {
    tap_code(KC_NUM);
  }
}

static void process_alt_num_key(char code[5]){
  uint8_t mods = get_mods();
  bool num_lock = host_keyboard_led_state().num_lock;
  if (!num_lock)
  {
    tap_code(KC_NUM);
  }
  clear_mods();
  register_code(KC_LALT);
  tap_kp_code(code);
  unregister_code(KC_LALT);
  set_mods(mods);
  if (!num_lock)
  {
    tap_code(KC_NUM);
  }
}

static void process_num_lock_alteration(uint16_t keycode, uint16_t numl_keycode, keyrecord_t *record){
  if (!host_keyboard_led_state().num_lock) {
    if (record->event.pressed) {
      register_code16(keycode);
    } else {
      unregister_code16(keycode);
    }
  } else {
    if (record->event.pressed) {
      register_code16(numl_keycode);
    } else {
      unregister_code16(numl_keycode);
    }  
  }  
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (is_alt_tab_active && (keycode != ALT_TAB&&keycode != SHFT_ALT_TAB))
  {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
  }
  
  if (is_ctrl_tab_active && (keycode != CTRL_TAB&& keycode != SHFT_CTRL_TAB))
  {
      unregister_code(KC_LCTL);
      is_ctrl_tab_active = false;
  }
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;



    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_HOME);
        } else {
          unregister_code16(KC_HOME);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_HOME));
        } else {
          unregister_code16(LSFT(KC_HOME));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_END);
        } else {
          unregister_code16(KC_END);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_END));
        } else {
          unregister_code16(LSFT(KC_END));
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;


        case ST_MACRO_0:
        case EURO_SIGN:
        if (record->event.pressed) {
          process_alt_num_key("00128");
        }
        return false;
        case ST_MACRO_1:
        case EMPT_FUNC:
        if (record->event.pressed) {
          SEND_STRING("()=>{" SS_TAP(X_ENTER));
        }
        break;
        case ST_MACRO_2:
        case NOTE_PAD:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r")SS_DELAY(50) "notepad" SS_TAP(X_ENTER));
        }
        break;
        case ST_MACRO_3:
        case VS_CODE:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r")SS_DELAY(50) "code" SS_TAP(X_ENTER));
        }
        break;
        case ST_MACRO_4:
        case VS_WIND_LEFT:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_LEFT)));
        }
        break;
        case ST_MACRO_5:
        case VS_WIND_RIGHT:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_RIGHT)));
        }
        break;
        case ST_MACRO_9:
        case GER_SZ:
        if (record->event.pressed) {
          process_alt_num_key("0223");
        }
        return false;
        case ST_MACRO_6:
        case GER_AE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0228", "0196");
        }
        return false;
        case ST_MACRO_7:
        case GER_OE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0246", "0214");
        }
        return false;
        case ST_MACRO_8:
        case GER_UE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0252", "0220");
        }
        return false;
        case SM_POWR:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("x") SS_DELAY(300)"u"SS_DELAY(200)"u");
        }
        break;
        case SM_SLEP:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("x")SS_DELAY(300)"u"SS_DELAY(200)"s");
        }
        break;
        case ALT_TAB:
        if (record->event.pressed) {
          if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();

        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
      
    case SHFT_ALT_TAB:
    if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();

          register_code16(LSFT(KC_TAB));
      } else {
          unregister_code16(LSFT(KC_TAB));
      }
      break;
    case CTRL_TAB:
    if (record->event.pressed) {
        if (!is_ctrl_tab_active) {
          is_ctrl_tab_active = true;
          register_code(KC_LCTL);
        }
        ctrl_tab_timer = timer_read();

          register_code16(KC_TAB);
      } else {
          unregister_code16(KC_TAB);
      }
      break;
    case SHFT_CTRL_TAB:
    if (record->event.pressed) {
        if (!is_ctrl_tab_active) {
          is_ctrl_tab_active = true;
          register_code(KC_LCTL);
        }
        ctrl_tab_timer = timer_read();
        
        register_code16(LSFT(KC_TAB));
      } else {
        unregister_code16(LSFT(KC_TAB));
      }
      break;
    case KC_PPLS: 
      process_num_lock_alteration(KC_PLUS, KC_PPLS, record);
      return false;
    case KC_PCMM: 
      process_num_lock_alteration(KC_COMM, KC_PCMM, record);
      return false;
    case KC_PSLS: 
      process_num_lock_alteration(KC_SLSH, KC_PSLS, record);
      return false;
    case KC_PEQL: 
      process_num_lock_alteration(KC_EQL, KC_PEQL, record);
      return false;
    case KC_PAST: 
      process_num_lock_alteration(KC_ASTR, KC_PAST, record);
      return false;
    case KC_PMNS: 
      process_num_lock_alteration(KC_MINS, KC_PMNS, record);
      return false;
    case KC_PDOT: 
      process_num_lock_alteration(KC_DOT, KC_PDOT, record);
      return false;
    case KC_KP_1:
      process_num_lock_alteration(KC_1, KC_KP_1, record);
      return false;
    case KC_KP_2:
      process_num_lock_alteration(KC_2, KC_KP_2, record);
      return false;
    case KC_KP_3:
      process_num_lock_alteration(KC_3, KC_KP_3, record);
      return false;
    case KC_KP_4:
      process_num_lock_alteration(KC_4, KC_KP_4, record);
      return false;
    case KC_KP_5:
      process_num_lock_alteration(KC_5, KC_KP_5, record);
    return false;
    case KC_KP_6:
      process_num_lock_alteration(KC_6, KC_KP_6, record);
    return false;
    case KC_KP_7:
      process_num_lock_alteration(KC_7, KC_KP_7, record);
      return false;
    case KC_KP_8:
      process_num_lock_alteration(KC_8, KC_KP_8, record);
      return false;
    case KC_KP_9:
      process_num_lock_alteration(KC_9, KC_KP_9, record);
      return false;
    case KC_KP_0:
      process_num_lock_alteration(KC_0, KC_KP_0, record);
      return false;
  }
  return true;
}

void matrix_scan_user(void){
  if(is_alt_tab_active){
    if(timer_elapsed(alt_tab_timer)>SUPER_TAB_TIME_ACTIVE){
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
  }
  if(is_ctrl_tab_active){
    if(timer_elapsed(ctrl_tab_timer)>SUPER_TAB_TIME_ACTIVE){
        unregister_code(KC_LCTL);
        is_ctrl_tab_active = false;
    }
  }
}

bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
  if (get_highest_layer(layer_state) != 0)
  {
    return false;
  }
  
#ifdef AUDIO_ENABLE
  PLAY_SONG(autocorrect_song);
#endif
    return true;
}

bool led_update_user(led_t led_state) {
    #ifdef AUDIO_ENABLE
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
        caps_state = led_state.caps_lock;
    }
    if(numl_state != led_state.num_lock){
      led_state.num_lock ? PLAY_SONG(numl_on) : PLAY_SONG(numl_off);
      numl_state = led_state.num_lock;
    }
    #endif
    return true;
}


bool shutdown_user(bool jump_to_bootloader) {
    if (jump_to_bootloader) {
        // red for bootloader
        rgb_matrix_set_color_all(RGB_RED);
    } else {
        // off for soft reset
        rgb_matrix_set_color_all(RGB_OFF);
    }
    // force flushing -- otherwise will never happen
    rgb_matrix_update_pwm_buffers();
    // false to not process kb level
    return false;
}


uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & MOD_MASK_CTRL)) {  // Was Ctrl held?
        switch (keycode) {
            case KC_Y: return C(KC_Z);  // Ctrl + Y reverses to Ctrl + Z.
            case KC_Z: return C(KC_Y);  // Ctrl + Z reverses to Ctrl + Y.
            case KC_C: return C(KC_V);  // Ctrl + V after a Ctrl + C
        }
    }
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    switch (keycode) {
        case KC_TAB:
            if (shifted) {        // If the last key was Shift + Tab,
                return KC_TAB;    // ... the reverse is Tab.
            } else {              // Otherwise, the last key was Tab,
                return S(KC_TAB); // ... and the reverse is Shift + Tab.
            }
        case ALT_TAB:
            return SHFT_ALT_TAB;
        case SHFT_ALT_TAB:
            return ALT_TAB;
        case CTRL_TAB:
            return SHFT_CTRL_TAB;
        case SHFT_CTRL_TAB:
            return CTRL_TAB;
    }

    return KC_TRNS;  // Defer to default definitions.
}


uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
        case LSFT_T(KC_E):
        case RSFT_T(KC_T):
            return FLOW_TAP_TERM - 70;
        case LT(2, KC_O):
        case LT(2, KC_N):
            return FLOW_TAP_TERM - 40;
        default:
          return FLOW_TAP_TERM;
        }
    }
    return 0;
}

const key_override_t next_track_override = 
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_CTRL,       // Trigger modifiers: ctrl
    	KC_MPLY,             // Trigger key: play/pause
    	KC_MNXT,             // Replacement key
    	~0,                  // Activate on all layers
    	MOD_MASK_SA,         // Do not activate when shift or alt are pressed
    	ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl
    
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY,
											KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

const key_override_t vol_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_MPLY,
											KC_VOLU, ~0, MOD_MASK_CS, ko_option_no_reregister_trigger);

const key_override_t vol_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SA, KC_MPLY,
											KC_VOLD, ~0, MOD_MASK_CTRL, ko_option_no_reregister_trigger);

const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY,
											KC_BRIU, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);

const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_CSA, KC_MPLY, KC_BRID);




const key_override_t delete_key_override = 
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Also override for the layer tap backspace key
const key_override_t delete_key_override_lt = 
    ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, LT(5, KC_BSPC), KC_DEL, ~0, 0);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&next_track_override,
	&prev_track_override,
	&vol_up_override,
	&vol_down_override,
	&brightness_up_override,
	&brightness_down_override,
	&delete_key_override,
	&delete_key_override_lt,
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case GER_AE:
        case GER_OE:
        case GER_UE:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

void caps_word_set_user(bool active) {
  #ifdef AUDIO_ENABLE
    if (active) {
      PLAY_SONG(caps_word_on_song);
    } else {
      PLAY_SONG(caps_word_off_song);
    }
    #endif
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return TAPPING_TERM + 100; // Increase
        default:
            return TAPPING_TERM;
    }
}


void leader_start_user(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(one_up_sound);
#endif
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        // Leader, a => <>
        SEND_STRING("<>");
        tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(KC_C)) {
        // Leader, c => {}
        SEND_STRING("{}");
        tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(KC_D)){
        // Leader, d => ""
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_LEFT);
    } else if (leader_sequence_two_keys(KC_D, KC_D)){
        // Leader, d d d=> """"""
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_ENTER);
    } else if (leader_sequence_one_key(KC_P)) {
        // Leader, p => ()
        SEND_STRING("()");
        tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(KC_S)) {
        // Leader, s => []
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
  // git
    } else if (leader_sequence_two_keys(KC_G, KC_S)) {
        // Leader, g, s => git status
        SEND_STRING("git status"SS_TAP(X_ENTER));
    } else if (leader_sequence_two_keys(KC_G, KC_P)) {
        // Leader, g, p => git push
        SEND_STRING("git push"SS_TAP(X_ENTER));
    } else if (leader_sequence_two_keys(KC_G, KC_C)) {
        // Leader, g, c => git add -A && git commit -m ""
        SEND_STRING("git add -A ; git commit -m ");
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_LEFT);
    } else if (leader_sequence_two_keys(KC_G, KC_F)) {
        // Leader, g, f => git fetch
        SEND_STRING("git fetch"SS_TAP(X_ENTER));
    } else if (leader_sequence_two_keys(KC_G, KC_M)) {
        // Leader, g, m => git merge origin/oryx
        SEND_STRING("git merge origin/oryx"SS_TAP(X_ENTER));
  // Text
    } else if (leader_sequence_two_keys(KC_T, KC_T)) {
      // Leader, t, t => Thank you
      SEND_STRING("Thank you");
    } else if (leader_sequence_two_keys(KC_T, KC_X)) {
      // Leader, t, x => Thanks 
      SEND_STRING("Thanks");
  // SQL
    } else if (leader_sequence_two_keys(KC_S, KC_E)) {
        // Leader, s, e => SELECT * FROM ;
        SEND_STRING("SELECT * FROM ");
    } else if (leader_sequence_two_keys(KC_F, KC_F)) {
        // Leader, f, f => FROM ;
        SEND_STRING("FROM ");
    } else if (leader_sequence_two_keys(KC_W, KC_W)) {
        // Leader, w, w => WHERE ;
        SEND_STRING("WHERE ");
  // code 
    } else if (leader_sequence_two_keys(KC_P, KC_F)) {
      SEND_STRING("def ():");
      tap_code16(KC_ENTER);
      tap_code16(KC_UP);
      tap_code16(KC_END);
      tap_code16(KC_LEFT);
      tap_code16(KC_LEFT);
      tap_code16(KC_LEFT);
    // Shortcuts
    } else if (leader_sequence_two_keys(KC_S, KC_A)) {
      SEND_STRING(SS_LCTL("a")SS_DELAY(20)SS_LCTL("c"));
    } else if (leader_sequence_two_keys(KC_R, KC_A)) {
      SEND_STRING(SS_LCTL("a")SS_DELAY(20)SS_LCTL("v"));
  // German
    } else if (leader_sequence_two_keys(KC_A, KC_E)) {
      // Leader a, e => ä
        process_alt_num_key("0228");
    } else if (leader_sequence_three_keys(KC_T, KC_A, KC_E)) {
      // Leader t, a, e => Ä
        process_alt_num_key("0196");
    } else if (leader_sequence_two_keys(KC_O, KC_E)) {
      // Leader o, e => ö
        process_alt_num_key("0246");
    } else if (leader_sequence_three_keys(KC_T, KC_O, KC_E)) {
      // Leader t, ö, e => Ö
        process_alt_num_key("0214");
    } else if (leader_sequence_two_keys(KC_U, KC_E)) {
      // Leader u, e => ü
        process_alt_num_key("0252");
    } else if (leader_sequence_three_keys(KC_T, KC_U, KC_E)) {
      // Leader t, u, e => Ü
        process_alt_num_key("0220");
    } else if (leader_sequence_two_keys(KC_S, KC_Z)) {
      // Leader s, z => ß
        process_alt_num_key("0223");
  // Stream
    } else if (leader_sequence_three_keys(KC_S, KC_K, KC_B)) {
      // Leader s, k, b => KonBooba
      SEND_STRING("KonBooba");
    } else if (leader_sequence_two_keys(KC_S, KC_O)) {
      // Leader s, o => Otsu
      SEND_STRING("Otsu");
    } else if (leader_sequence_three_keys(KC_S, KC_O, KC_N)) {
      // Leader s, o, n => OtsuNanoyo
      SEND_STRING("OtsuNanoyo");
    } else if (leader_sequence_three_keys(KC_S, KC_W, KC_R)) {
      // Leader s, w, r => Welcome Raiders
      SEND_STRING("Welcome Raiders");
  // Emotes
    } else if (leader_sequence_four_keys(KC_S, KC_E, KC_S, KC_L)) {
      // Leader s, e, s, l => :_SinonLove:
          SEND_STRING(":_SinonLove:");
    } else if (leader_sequence_four_keys(KC_S, KC_E, KC_S, KC_C)) {
      // Leader s, e, s, l => :_SinonCheer:
          SEND_STRING(":_SinonCheer:");
    } else if (leader_sequence_four_keys(KC_S, KC_E, KC_S, KC_S)) {
      // Leader s, e, s, l => :_SinonSmug:
          SEND_STRING(":_SinonSmug:");
    } else if (leader_sequence_four_keys(KC_S, KC_E, KC_S, KC_Y)) {
      // Leader s, e, s, l => :_SinonCry:
          SEND_STRING(":_SinonCry:");
    }

}



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    
    if (is_swap_hands_on() && host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_ORANGE);
            }
        }
    }
    else if (is_swap_hands_on()) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_YELLOW);
            }
        }
    }
    else if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    return false;
}