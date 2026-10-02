dance_state[7]#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"
#include "keymap.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

bool is_swap_hands_tap_toggle_on = false;

static uint8_t numl_state = 0;
bool numlock_changed = false;

#ifdef AUDIO_ENABLE
float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float numl_on[][2] = SONG(NUM_LOCK_ON_SOUND);
float numl_off[][2] = SONG(NUM_LOCK_OFF_SOUND);
float caps_word_on_song[][2] = SONG(ZELDA_PUZZLE);
float caps_word_off_song[][2] = SONG(ZELDA_TREASURE);
#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                              _______,  _______,  _______,  _______,  _______,  _______,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            _______,  _______,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  _______
),
  */
 [BASE] = LAYOUT_moonlander(
    TD_STGA,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TD_STGA,
    KC_BSLS,  QUOP,     LEADER,   KC_DOT,   KC_P,     KC_Y,     _______,          TD_LOCK,  KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,
    NAV_EQL,  HOME_A,   HOME_O,   HOME_E,   HOME_U,   KC_I,     _______,          _______,  KC_D,     HOME_H,   HOME_T,   HOME_N,   HOME_S,   UTL_MNS,
    SH_OS,    KC_SCLN,  KC_Q,     MEH_J,    KC_K,     KC_X,                                 KC_B,     KC_M,     MEH_W,    KC_V,     KC_Z,     SH_OS,  
    NMSY_TT,  NAVI_TT,  MOUS_TT,  DM_REC1,  QK_AREP,            DM_PLY1,          DM_PLY2,            QK_REP,   DM_REC2,  MOUS_TT,  NAVI_TT,  NMSY_TT,  
                                            MOU_BSP,  OS_LSFT,  LGUI_ESC,         KC_RGUI,  NAV_ENT,  KC_SPC
),

[STEN] = LAYOUT_moonlander(
    TD_BAGA,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOLT,          QK_GEMI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TD_BAGA,
    XXXXXXX,  STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   XXXXXXX,          XXXXXXX,  STN_N6,   STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,
    XXXXXXX,  STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  XXXXXXX,          XXXXXXX,  STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
    XXXXXXX,  STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,                              STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,  
    SA_TAB,   A_TAB,    XXXXXXX,  XXXXXXX,  KC_LCTL,            _______,          _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  SA_TAB,   A_TAB,   
                                            STN_A,    STN_O,    STN_NC,           STN_NC,  STN_E,   STN_U
),
[NMSY] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_NUM,   KC_PSLS,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_CALC,          KC_TILD,  KC_GRV,   KC_LCBR,  KC_RCBR,  KC_EXLM,  KC_AT,    _______,
    KC_PMNS,  KC_PAST,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_PDOT,  CR_EURO,          _______,  KC_AMPR,  KC_LPRN,  KC_RPRN,  KC_HASH,  KC_DLR,   _______,
    KC_PENT,  KC_PPLS,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_COMM,                              KC_ASTR,  KC_LBRC,  KC_RBRC,  KC_PERC,  KC_CIRC,  KC_PIPE,  
    _______,  _______,  KC_KP_0,  KC_KP_0,  KC_PDOT,            _______,          _______,            _______,  _______,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  _______
),
[UTIL] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          KC_PWR,   KC_SLEP,  _______,  _______,  _______,  _______,  QK_BOOT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          NOTE_PAD, DT_UP,    _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          VS_CODE,  DT_PRNT,  _______,  _______,  _______,  _______,  _______,
    AU_TOGG,  _______,  _______,  _______,  _______,  _______,                              DT_DOWN,  _______,  _______,  _______,  _______,  _______,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            _______,  _______,  _______,  _______,  _______,  
                                            RGB_VAD,  RGB_VAI,  TOGG_LC,          RGB_SLD,  RGB_HUD,  RGB_HUI
),
[NAVI] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  SELLUP,   JOINLN,   _______,  _______,          _______,  KC_PGUP,  HOM_SFT,  KC_UP,    END_SFT,  _______,  _______,
    _______,  _______,  SELWBAK,  SELLINE,  SELWORD,  _______,  _______,          _______,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                              _______,  SA_TAB,   A_TAB,    SC_TAB,   C_TAB,    _______,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            KC_WBAK,  KC_WFWD,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  _______
),
[MOUS] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  OM_W_U,   OM_BTNS,  OM_U,     OM_DBLS,  JIGGLE,   KC_APP,
    _______,  OS_LALT,  OS_LGUI,  OS_LSFT,  OS_LCTL,  SRCHSEL,  _______,          _______,  OM_W_D,   OM_L,     OM_D,     OM_R,     OM_FAST,  OM_SLOW,
    REDO,     UNDO,     CUT,      COPY,     CLPBRD,   PASTE_F,                              OM_RELS,  OM_HLDS,  OM_SEL1,  OM_SEL2,  OM_SEL3,  KC_MPLY,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            OM_BTN4,  OM_BTN5,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  OM_BTNS
),
[GAME] = LAYOUT_moonlander(
    TD_BAST,  _______,  _______,  _______,  TD_ALF4,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  TD_BAST,
    KC_BSPC,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,             _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_ESC,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,             _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_DEL,   KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,                                 _______,  _______,  _______,  _______,  _______,  _______,  
    XXXXXXX,  _______,  OS_KRIT,  KC_LALT,  KC_B,               KC_ENT,           _______,            _______,  _______,  _______,  _______,  _______,  
                                            KC_LSFT,  KC_SPC,   MO_GAMP,          _______,  _______,  _______
),
[GAMP] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_Y,     KC_O,     KC_I,     KC_U,     KC_P,     KC_Y,             _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_T,     KC_1,     KC_2,     KC_3,     KC_H,     _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_J,     KC_K,     KC_L,     KC_M,     KC_N,                                 _______,  _______,  _______,  _______,  _______,  _______,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            _______,  _______,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  _______
),
[KRIT] = LAYOUT_moonlander(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  QK_LLCK,  KR_BRSH7, KR_BRSH8, KR_BRSH9, _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KR_DUPLL, KR_BRSH4, KR_BRSH5, KR_BRSH6, _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KR_BRSH0, KR_BRSH1, KR_BRSH2, KR_BRSH3, _______,                              _______,  _______,  _______,  _______,  _______,  _______,  
    _______,  _______,  _______,  _______,  _______,            _______,          _______,            _______,  _______,  _______,  _______,  _______,  
                                            _______,  _______,  _______,          _______,  _______,  _______
),
};


socd_cleaner_t socd_opposing_pairs[] = {
  {{KC_W, KC_S}, SOCD_CLEANER_LAST},
  {{KC_A, KC_D}, SOCD_CLEANER_LAST}
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
const uint16_t PROGMEM combo43[] = { LT(2, KC_O), MT(MOD_LSFT, KC_E), MT(MOD_RSFT, KC_T),LT(2, KC_N), COMBO_END};

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
    COMBO(combo42, LEADER),
    COMBO(combo43, NEXTSEN),
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


void steno_game_finished(tap_dance_state_t *state, void *user_data);
void steno_game_reset(tap_dance_state_t *state, void *user_data);

void steno_game_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDSTGA].step = dance_step(state);
    switch (dance_state[TDSTGA].step) {
        case SINGLE_TAP: layer_move(STEN); break;
        case DOUBLE_TAP: layer_move(GAME); break;
        case DOUBLE_SINGLE_TAP: layer_move(STEN); break;
    }
}

void steno_game_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDSTGA].step) {
    }
    dance_state[TDSTGA].step = 0;
}
void pc_lock_finished(tap_dance_state_t *state, void *user_data);
void pc_lock_reset(tap_dance_state_t *state, void *user_data);

void pc_lock_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDLOCK].step = dance_step(state);
    switch (dance_state[TDLOCK].step) {
        case DOUBLE_TAP: register_code16(LGUI(KC_L)); break;
    }
}

void pc_lock_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDLOCK].step) {
        case DOUBLE_TAP: unregister_code16(LGUI(KC_L)); break;
    }
    dance_state[TDLOCK].step = 0;
}
void base_game_finished(tap_dance_state_t *state, void *user_data);
void base_game_reset(tap_dance_state_t *state, void *user_data);

void base_game_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDBAGA].step = dance_step(state);
    switch (dance_state[TDBAGA].step) {
        case SINGLE_TAP: layer_move(BASE); break;
        case DOUBLE_TAP: layer_move(GAME); break;
        case DOUBLE_SINGLE_TAP: layer_move(BASE); break;
    }
}

void base_game_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDBAGA].step) {
    }
    dance_state[TDBAGA].step = 0;
}
void on_move_editor(tap_dance_state_t *state, void *user_data);
void move_editor_finished(tap_dance_state_t *state, void *user_data);
void move_editor_reset(tap_dance_state_t *state, void *user_data);

void on_move_editor(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void move_editor_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDEDMO].step = dance_step(state);
    switch (dance_state[TDEDMO].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void move_editor_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDEDMO].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
    }
    dance_state[TDEDMO].step = 0;
}
void base_steno_finished(tap_dance_state_t *state, void *user_data);
void base_steno_reset(tap_dance_state_t *state, void *user_data);

void base_steno_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDBAST].step = dance_step(state);
    switch (dance_state[TDBAST].step) {
        case SINGLE_TAP: layer_move(BASE); break;
        case DOUBLE_TAP: layer_move(STEN); break;
        case DOUBLE_SINGLE_TAP: layer_move(BASE); break;
    }
}

void base_steno_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDBAST].step) {
    }
    dance_state[TDBAST].step = 0;
}
void on_f4_alt_f4(tap_dance_state_t *state, void *user_data);
void f4_alt_f4_finished(tap_dance_state_t *state, void *user_data);
void f4_alt_f4_reset(tap_dance_state_t *state, void *user_data);

void on_f4_alt_f4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void f4_alt_f4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TDALF4].step = dance_step(state);
    switch (dance_state[TDALF4].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void f4_alt_f4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TDALF4].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[TDALF4].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [TDSTGA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, steno_game_finished, steno_game_reset),
        [TDLOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pc_lock_finished, pc_lock_reset),
        [TDBAGA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_game_finished, base_game_reset),
        [TDEDMO] = ACTION_TAP_DANCE_FN_ADVANCED(on_move_editor, move_editor_finished, move_editor_reset),
        [TDBAST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_steno_finished, base_steno_reset),
        [TDALF4] = ACTION_TAP_DANCE_FN_ADVANCED(on_f4_alt_f4, f4_alt_f4_finished, f4_alt_f4_reset),
};


inline uint8_t get_tap_kc(uint16_t dual_role_key) {
    // Used to extract the basic tapping keycode from a dual-role key.
    // Example: get_tap_kc(MT(MOD_RSFT, KC_E)) == KC_E
    return dual_role_key & 0xFF;
}

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
  uint8_t oneshot_mods = get_oneshot_mods();
  bool num_lock = host_keyboard_led_state().num_lock;
  bool caps = host_keyboard_led_state().caps_lock || is_caps_word_on();
  bool shift = ((mods | oneshot_mods ) & MOD_MASK_SHIFT)!=0;
  if (!num_lock)
  {
    tap_code(KC_NUM);
  }
  clear_oneshot_mods();
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
  clear_oneshot_mods();
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

static bool process_quopostrokey(uint16_t keycode, keyrecord_t *record) {
  static bool within_word = false;

  if (keycode == QUOP) {
    if (record->event.pressed) {
      if (within_word) {
        tap_code(KC_QUOT);
      } else {
        SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
    }
    return false;
  }

  switch (keycode) {
  #ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

  // Determine whether the key is a letter.
  switch (keycode) {
    case KC_A ... KC_Z:
      within_word = true;
      break;

    default:
      within_word = false;
  }

  return true;  
}

static bool process_dead_key(uint16_t keycode, keyrecord_t *record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
        // Earlier return if this has not been considered tapped yet
        if (record->tap.count == 0) { return true; }
        // Get the base tapping keycode of a mod- or layer-tap key
        keycode = get_tap_kc(keycode);
        break;
    default:
        break;
  }

  switch (keycode) {
    case KC_QUOTE:
    case KC_DOUBLE_QUOTE:
    case KC_TILDE:
    case KC_GRAVE:
    case KC_CIRCUMFLEX:
      break;
    default:  // ignore all non dead keys
      return true;
  }

  if (record->event.pressed) {
    del_mods(MOD_MASK_SHIFT);
    del_oneshot_mods(MOD_MASK_SHIFT);

    tap_code16(keycode);
    tap_code(KC_SPACE);

    set_mods(mods);
    set_oneshot_mods(oneshot_mods);
  }  
  return false; // Skip all further processing of this key
}

uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
  static const int8_t deltas[32] = {
    -1, -2, -4, -5, -6, -7, -8, -8, -8, -8, -7, -6, -5, -4, -2, -1,  1,  2,  4,  5,  6,  7,  8,  8, 8,  8,  7,  6,  5,  4,  2,  1
  };
  static uint8_t phase = 0;
  report.x = deltas[phase];
  report.y = deltas[(phase + 8) & 31]
  phase = (phase + 1) & 31;
  host_mouse_send(&report);
  return 16;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_dead_key(keycode, record)) { return false; }
  if (!process_quopostrokey(keycode, record)) { return false; }

  if (record->event.pressed) {
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    static report_mouse_t report = {0};
    if (token) {
      cancel_deferred_exec(token);
      token = INVALID_DEFERRED_TOKEN;
      report = (report_mouse_t){};
      host_mouse_send(&report);
    } else if (keycode == JIGGLE) {
      token = defer_exec(1, jiggler_callback, NULL);
    }
  }

  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();
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

    case HOM_SFT:
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
    case END_SFT:
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


        case EURO_SIGN:
        if (record->event.pressed) {
          process_alt_num_key("00128");
        }
        return false;
        case EMPT_FUNC:
        if (record->event.pressed) {
          SEND_STRING("()=>{" SS_TAP(X_ENTER));
        }
        break;
        
        case NOTE_PAD:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r")SS_DELAY(50) "notepad" SS_TAP(X_ENTER));
        }
        break;
        
        case VS_CODE:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r")SS_DELAY(50) "code" SS_TAP(X_ENTER));
        }
        break;
      
        case VS_WIND_LEFT:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_LEFT)));
        }
        break;
      
        case VS_WIND_RIGHT:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(1)  SS_LCTL(SS_TAP(X_RIGHT)));
        }
        break;
        
        case GER_SZ:
        if (record->event.pressed) {
          process_alt_num_key("0223");
        }
        return false;
        
        case GER_AE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0228", "0196");
        }
        return false;
      
        case GER_OE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0246", "0214");
        }
        return false;
        
        case GER_UE:
        if (record->event.pressed) {
          process_alt_num_key_with_shift("0252", "0220");
        }
        return false;
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
    case NEXTSEN:  // Next sentence macro.
      if (record->event.pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
      }
      return false;
    case JOINLN:  // Join lines like Vim's `J` command.
      if (record->event.pressed) {
        SEND_STRING( // Go to the end of the line and tap delete.
            SS_TAP(X_END) SS_TAP(X_DEL)
            // In case this has joined two words together, insert one space.
            SS_TAP(X_SPC)
            SS_LCTL(
              // Go to the beginning of the next word.
              SS_TAP(X_RGHT) SS_TAP(X_LEFT)
              // Select back to the end of the previous word. This should select
              // all spaces and tabs between the joined lines from indentation
              // or trailing whitespace, including the space inserted earlier.
              SS_LSFT(SS_TAP(X_LEFT) SS_TAP(X_RGHT)))
            // Replace the selection with a single space.
            SS_TAP(X_SPC));
      }
      return false;
    case SRCHSEL:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
        // Mac users, change LCTL to LGUI.
        SEND_STRING(SS_LCTL("ct") SS_DELAY(200) SS_LCTL("v") SS_TAP(X_ENTER));
      }
      return false;
    case BRACES:  // Types [], {}, or <> and puts cursor between braces.
      if (record->event.pressed) {
        clear_oneshot_mods();  // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("{}");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("<>");
        } else {
          SEND_STRING("[]");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        register_mods(mods);  // Restore mods.
      }
      return false;
    case KC_BSPC: {  // Backspace with exponential repeating.
  // Initial delay before the first repeat.
  static const uint8_t INIT_DELAY_MS = 250;
  // This array customizes the rate at which the Backspace key
  // repeats. The delay after the ith repeat is REP_DELAY_MS[i].
  // Values must be between 1 and 255.
  static const uint8_t REP_DELAY_MS[] PROGMEM = {
      99, 79, 65, 57, 49, 43, 40, 35, 33, 30, 28, 26, 25, 23, 22, 20,
      20, 19, 18, 17, 16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10};
  static deferred_token token = INVALID_DEFERRED_TOKEN;
  static uint8_t rep_count = 0;
    
  if (!record->event.pressed) {  // Backspace released: stop repeating.
    cancel_deferred_exec(token);
    token = INVALID_DEFERRED_TOKEN;
  } else if (!token) {  // Backspace pressed: start repeating.
    tap_code(KC_BSPC);  // Initial tap of Backspace key.
    rep_count = 0;

    uint32_t bspc_callback(uint32_t trigger_time, void* cb_arg) {
      tap_code(KC_BSPC);
      if (rep_count < sizeof(REP_DELAY_MS)) { ++rep_count; }
      return pgm_read_byte(REP_DELAY_MS - 1 + rep_count); 
    }

    token = defer_exec(INIT_DELAY_MS, bspc_callback, NULL); 
  }
} return false;  // Skip normal handling.
  }
  return true;
}

#ifdef AUTO_CORRECT_ENABLE
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
#endif // AUTO_CORRECT_ENABLE

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
        case A(KC_TAB): return S(A(KC_TAB));
        case S(A(KC_TAB)): return A(KC_TAB);
        case C(KC_TAB): return S(C(KC_TAB));
        case S(C(KC_TAB)): return C(KC_TAB);
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

void super_leader_add_user(
  const uint16_t* seq, uint8_t num_seq, bool*partial
) {
    // "A, <key>, <same key>" where <key> is a letter => Taps AltGr+<key>.
    if (SUPER_LEADER_SEQ_STARTS_WITH((KC_A), partial) &&
        KC_A <= seq[1] && seq[1] <= KC_Z) {
      if (num_seq < 3) {
        *partial = true;
      } else if (num_seq == 3 && seq[1] == seq[2]) {
        uint16_t modded_keycode = ALGR(seq[1]);
        super_leader_set_match(SUPER_LEADER_KEY(modded_keycode));
      }
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

layer_state_t layer_state_set_user(layer_state_t state) {
  socd_cleaner_enabled = IS_LAYER_ON_STATE(state, GAME);
  return state;
}