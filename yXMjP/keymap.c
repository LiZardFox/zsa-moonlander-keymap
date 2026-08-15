#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_steno.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
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
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
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

#define DUAL_FUNC_0 LT(15, KC_N)
#define DUAL_FUNC_1 LT(12, KC_F15)
#define DUAL_FUNC_2 LT(12, KC_3)
#define DUAL_FUNC_3 LT(7, KC_F13)
#define DUAL_FUNC_4 LT(5, KC_F10)
#define DUAL_FUNC_5 LT(11, KC_H)
#define DUAL_FUNC_6 LT(6, KC_F12)
#define DUAL_FUNC_7 LT(15, KC_V)
#define DUAL_FUNC_8 LT(14, KC_F9)
#define DUAL_FUNC_9 LT(11, KC_7)
#define DUAL_FUNC_10 LT(8, KC_8)
#define DUAL_FUNC_11 LT(7, KC_T)
#define DUAL_FUNC_12 LT(10, KC_X)
#define DUAL_FUNC_13 LT(12, KC_6)
#define DUAL_FUNC_14 LT(11, KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         TD(DANCE_1),    
    CW_TOGG,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    DUAL_FUNC_0,    MT(MOD_LALT, KC_A),LT(1, KC_O),    MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_U),KC_I,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_D,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_T),LT(1, KC_N),    MT(MOD_RALT, KC_S),LT(2, KC_MINUS),
    KC_BSLS,        KC_SCLN,        KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_EQUAL,       
    TT(1),          TT(4),          TT(5),          DM_REC1,        MO(2),          DM_PLY1,                                                                                                        DM_PLY2,        MO(2),          DM_REC2,        TT(5),          TT(4),          TT(1),          
    KC_BSPC,        LT(5, KC_DELETE),MT(MOD_LGUI, KC_ESCAPE),                KC_RIGHT_GUI,   LT(4, KC_ENTER),KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_NUM,         KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_GRAVE,       KC_TILD,                                        KC_CALCULATOR,  KC_COMMA,       DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,    KC_SLASH,       
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_AMPR,        KC_TRANSPARENT,                                                                 ST_MACRO_0,     KC_DOT,         DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,    KC_ASTR,        KC_MINUS,       
    KC_PIPE,        KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_ASTR,                                        KC_COLN,        DUAL_FUNC_8,    DUAL_FUNC_9,    DUAL_FUNC_10,   KC_PLUS,        KC_KP_ENTER,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, DUAL_FUNC_4,    DUAL_FUNC_4,    KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 ST_MACRO_2,     QK_DYNAMIC_TAPPING_TERM_UP,LCTL(LSFT(KC_F12)),LALT(LCTL(KC_UP)),LCTL(KC_F12),   KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_GRAVE)),LCTL(LSFT(KC_M)),KC_TRANSPARENT,                                                                 ST_MACRO_3,     QK_DYNAMIC_TAPPING_TERM_PRINT,ST_MACRO_4,     TD(DANCE_2),    ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 QK_DYNAMIC_TAPPING_TERM_DOWN,LCTL(KC_I),     LALT(LCTL(KC_DOWN)),LALT(LCTL(KC_I)),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,                                                                                                RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [3] = LAYOUT_moonlander(
    TD(DANCE_3),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_4),    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_5),    
    KC_BSPC,        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ESCAPE,      KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NO,          KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_B,           KC_ENTER,                                                                                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_SPACE,       MO(6),                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     DUAL_FUNC_11,   KC_UP,          DUAL_FUNC_12,   KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, DUAL_FUNC_13,   DUAL_FUNC_14,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_WWW_BACK,    KC_WWW_FORWARD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_UP,    TD(DANCE_6),    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_APPLICATION, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_AUDIO_MUTE,  KC_MS_WH_LEFT,  KC_MS_BTN3,     KC_MS_WH_RIGHT, KC_MS_JIGGLER_TOGGLE,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN4,     KC_MS_BTN5,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Y,           KC_O,           KC_I,           KC_U,           KC_P,           KC_Y,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_T,           KC_1,           KC_2,           KC_3,           KC_H,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_J,           KC_K,           KC_L,           KC_M,           KC_N,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    TD(DANCE_7),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_STENO_BOLT,                                  QK_STENO_GEMINI,KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TD(DANCE_8),    
    KC_NO,          STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_NO,                                          KC_NO,          STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         
    KC_NO,          STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_NO,                                                                          KC_NO,          STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,         
    KC_NO,          STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                        STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,         
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    STN_A,          STN_O,          STN_NC,                         STN_NC,         STN_E,          STN_U
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

const uint16_t PROGMEM combo0[] = { KC_Q, KC_J, MT(MOD_LSFT, KC_E), LT(1, KC_O), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_D, KC_C, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_SCLN, MT(MOD_LALT, KC_A), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_Q, LT(1, KC_O), COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LCTL, KC_U), KC_K, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_Z, MT(MOD_RALT, KC_S), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_A, KC_Z, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_SCLN, KC_Q, MT(MOD_LSFT, KC_E), KC_J, LT(1, KC_O), MT(MOD_LALT, KC_A), COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_CAPS, KC_LEFT_CTRL, KC_Z, KC_A, KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_SCLN, MT(MOD_RSFT, KC_T), MT(MOD_LALT, KC_A), COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_Q, MT(MOD_RSFT, KC_T), LT(1, KC_O), COMBO_END};
const uint16_t PROGMEM combo14[] = { MT(MOD_LCTL, KC_U), KC_K, MT(MOD_RSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_SPACE, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo16[] = { KC_Q, KC_J, MT(MOD_RSFT, KC_T), LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo17[] = { MT(MOD_LSFT, KC_E), KC_W, KC_V, LT(1, KC_O), COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_O, KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo21[] = { KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM combo22[] = { KC_SPACE, MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo23[] = { KC_M, KC_W, KC_V, KC_SPACE, COMBO_END};
const uint16_t PROGMEM combo24[] = { KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM combo25[] = { KC_M, MT(MOD_RCTL, KC_H), COMBO_END};
const uint16_t PROGMEM combo26[] = { MT(MOD_RSFT, KC_T), KC_W, COMBO_END};
const uint16_t PROGMEM combo27[] = { MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo28[] = { KC_M, KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo29[] = { MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(1, KC_N), LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo30[] = { KC_M, KC_W, KC_V, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo31[] = { KC_SPACE, MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(1, KC_N), LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo32[] = { KC_SPACE, KC_M, KC_W, KC_V, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo33[] = { KC_RIGHT_GUI, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo34[] = { KC_M, MT(MOD_RSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo35[] = { MT(MOD_RSFT, KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo36[] = { LT(1, KC_N), KC_V, MT(MOD_RSFT, KC_T), KC_W, COMBO_END};
const uint16_t PROGMEM combo37[] = { DUAL_FUNC_11, KC_UP, DUAL_FUNC_12, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo39[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo41[] = { MT(MOD_RCTL, KC_H), KC_M, KC_V, LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo42[] = { KC_M, KC_W, MT(MOD_RSFT, KC_T), LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo43[] = { MT(MOD_RCTL, KC_H), KC_M, KC_W, MT(MOD_RSFT, KC_T), COMBO_END};
const uint16_t PROGMEM combo44[] = { MT(MOD_RCTL, KC_H), KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo45[] = { LT(1, KC_N), KC_V, COMBO_END};
const uint16_t PROGMEM combo46[] = { KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo47[] = { KC_M, MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), LT(1, KC_N), KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM combo48[] = { KC_M, MT(MOD_RSFT, KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo49[] = { MT(MOD_RCTL, KC_H), MT(MOD_RSFT, KC_T), KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo50[] = { LT(1, KC_O), MT(MOD_LSFT, KC_E), MT(MOD_RSFT, KC_T), LT(1, KC_N), COMBO_END};
const uint16_t PROGMEM combo51[] = { KC_Q, KC_J, KC_W, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LGUI(KC_DOT)),
    COMBO(combo1, LALT(KC_TAB)),
    COMBO(combo2, ST_MACRO_6),
    COMBO(combo3, ST_MACRO_7),
    COMBO(combo4, ST_MACRO_8),
    COMBO(combo5, ST_MACRO_9),
    COMBO(combo6, KC_MEDIA_PLAY_PAUSE),
    COMBO(combo7, TO(3)),
    COMBO(combo8, TO(0)),
    COMBO(combo9, KC_4),
    COMBO(combo10, KC_5),
    COMBO(combo11, KC_6),
    COMBO(combo12, ST_MACRO_10),
    COMBO(combo13, ST_MACRO_11),
    COMBO(combo14, ST_MACRO_12),
    COMBO(combo15, CW_TOGG),
    COMBO(combo16, KC_QUES),
    COMBO(combo17, KC_EXLM),
    COMBO(combo18, KC_7),
    COMBO(combo19, KC_8),
    COMBO(combo20, KC_9),
    COMBO(combo21, KC_0),
    COMBO(combo22, KC_LABK),
    COMBO(combo23, KC_RABK),
    COMBO(combo24, KC_UNDS),
    COMBO(combo25, KC_DQUO),
    COMBO(combo26, KC_PIPE),
    COMBO(combo27, KC_LPRN),
    COMBO(combo28, KC_RPRN),
    COMBO(combo29, KC_LBRC),
    COMBO(combo30, KC_RBRC),
    COMBO(combo31, KC_LCBR),
    COMBO(combo32, KC_RCBR),
    COMBO(combo33, KC_CAPS),
    COMBO(combo34, KC_SLASH),
    COMBO(combo35, KC_BSLS),
    COMBO(combo36, KC_EQUAL),
    COMBO(combo37, LCTL(KC_HOME)),
    COMBO(combo38, LCTL(KC_END)),
    COMBO(combo39, LCTL(KC_LEFT)),
    COMBO(combo40, LCTL(KC_RIGHT)),
    COMBO(combo41, KC_HASH),
    COMBO(combo42, KC_DLR),
    COMBO(combo43, KC_PERC),
    COMBO(combo44, KC_AMPR),
    COMBO(combo45, KC_COLN),
    COMBO(combo46, KC_SCLN),
    COMBO(combo47, KC_AT),
    COMBO(combo48, KC_CIRC),
    COMBO(combo49, KC_TILD),
    COMBO(combo50, ST_MACRO_13),
    COMBO(combo51, ST_MACRO_14),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, KC_A):
            return g_tapping_term + 75;
        case MT(MOD_LCTL, KC_U):
            return g_tapping_term + 75;
        case MT(MOD_RCTL, KC_H):
            return g_tapping_term + 75;
        case MT(MOD_RALT, KC_S):
            return g_tapping_term + 75;
        case KC_SPACE:
            return g_tapping_term -135;
        default:
            return g_tapping_term;
    }
}


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
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {40,240,174}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {190,238,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,54,140}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {221,236,121}, {176,241,174}, {21,237,224}, {0,0,0}, {0,0,0}, {176,241,174}, {144,199,242}, {176,241,174}, {0,0,0}, {0,0,0}, {221,236,121}, {176,241,174}, {21,237,224}, {0,0,0}, {20,230,227}, {74,255,255}, {74,255,255}, {74,255,255}, {0,218,204}, {131,219,203}, {148,219,203}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {32,226,188}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,104}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {69,201,230}, {0,0,0}, {0,0,0}, {123,232,160}, {20,250,216}, {69,201,230}, {0,0,0}, {0,0,0}, {20,250,216}, {20,250,216}, {199,255,176}, {0,0,0}, {0,0,0}, {123,232,160}, {20,250,216}, {199,255,176}, {0,0,0}, {0,0,0}, {0,207,168}, {0,207,168}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {172,255,255}, {0,255,112}, {0,0,0}, {74,255,255}, {180,227,168}, {20,250,216}, {172,255,255}, {0,0,0}, {74,255,255}, {20,250,216}, {20,250,216}, {180,227,168}, {123,255,255}, {74,255,255}, {180,227,168}, {20,250,216}, {172,255,255}, {123,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {180,227,168}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {186,255,112}, {0,0,0}, {0,0,0}, {0,224,133}, {0,218,204}, {198,255,112}, {0,0,0}, {0,0,0}, {104,179,197}, {19,218,204}, {216,255,112}, {0,0,0}, {0,0,0}, {192,224,133}, {40,218,204}, {20,255,65}, {0,0,0}, {0,0,0}, {28,174,241}, {0,255,112}, {238,218,204}, {0,0,0}, {247,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {21,237,224}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {73,158,185}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {175,172,207}, {21,237,224}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {73,158,185}, {0,0,0}, {0,0,0}, {175,172,207}, {175,172,207}, {175,172,207}, {175,172,207} },

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
        case SINGLE_TAP: layer_move(7); break;
        case DOUBLE_TAP: layer_move(3); break;
        case DOUBLE_SINGLE_TAP: layer_move(7); break;
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
        case SINGLE_TAP: layer_move(7); break;
        case DOUBLE_TAP: layer_move(3); break;
        case DOUBLE_SINGLE_TAP: layer_move(7); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
    }
    dance_state[2].step = 0;
}
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(7); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[4].step = 0;
}
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(7); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[6].step = 0;
}
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(3); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
    }
    dance_state[7].step = 0;
}
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: layer_move(3); break;
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
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_8_finished, dance_8_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(1)  SS_LSFT(SS_TAP(X_0))SS_DELAY(1)  SS_TAP(X_EQUAL)SS_DELAY(1)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(1)  SS_LSFT(SS_TAP(X_LBRC))  SS_DELAY(1) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(50)  SS_TAP(X_N)SS_DELAY(1)  SS_TAP(X_O)SS_DELAY(1)  SS_TAP(X_T)SS_DELAY(1)  SS_TAP(X_E)SS_DELAY(1)  SS_TAP(X_P)SS_DELAY(1)  SS_TAP(X_A)SS_DELAY(1)  SS_TAP(X_D)  SS_DELAY(1) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(50)  SS_TAP(X_C)SS_DELAY(1)  SS_TAP(X_O)SS_DELAY(1)  SS_TAP(X_D)SS_DELAY(1)  SS_TAP(X_E)  SS_DELAY(1) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_LEFT)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_RIGHT)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4) ));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT)SS_DELAY(5)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_COMMA)SS_DELAY(5)  SS_TAP(X_SPACE));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_TAB));
        } else {
          unregister_code16(LSFT(KC_TAB));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_7);
        } else {
          unregister_code16(KC_7);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_7);
        } else {
          unregister_code16(KC_KP_7);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_8);
        } else {
          unregister_code16(KC_8);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_8);
        } else {
          unregister_code16(KC_KP_8);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_9);
        } else {
          unregister_code16(KC_9);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_9);
        } else {
          unregister_code16(KC_KP_9);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_0);
        } else {
          unregister_code16(KC_0);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_0);
        } else {
          unregister_code16(KC_KP_0);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_4);
        } else {
          unregister_code16(KC_4);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_4);
        } else {
          unregister_code16(KC_KP_4);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_5);
        } else {
          unregister_code16(KC_5);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_5);
        } else {
          unregister_code16(KC_KP_5);
        }  
      }  
      return false;
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_6);
        } else {
          unregister_code16(KC_6);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_6);
        } else {
          unregister_code16(KC_KP_6);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_1);
        } else {
          unregister_code16(KC_1);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_1);
        } else {
          unregister_code16(KC_KP_1);
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_2);
        } else {
          unregister_code16(KC_2);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_2);
        } else {
          unregister_code16(KC_KP_2);
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_3);
        } else {
          unregister_code16(KC_3);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_KP_3);
        } else {
          unregister_code16(KC_KP_3);
        }  
      }  
      return false;
    case DUAL_FUNC_11:
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
    case DUAL_FUNC_12:
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
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_TAB));
        } else {
          unregister_code16(LSFT(KC_TAB));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_TAB)));
        } else {
          unregister_code16(LCTL(LSFT(KC_TAB)));
        }  
      }  
      return false;
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_TAB));
        } else {
          unregister_code16(LCTL(KC_TAB));
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
  }
  return true;
}

