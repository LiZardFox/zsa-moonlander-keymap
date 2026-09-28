#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif
#ifndef SUPER_TAB_TIME_ACTIVE
#define SUPER_TAB_TIME_ACTIVE 1000
#endif

static uint8_t numl_state = 0;
bool numlock_changed = false;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_ctrl_tab_active = false;
uint16_t ctrl_tab_timer = 0;


#ifdef AUDIO_ENABLE
float megalovania[][2] = SONG(MEGALOVANIA);
float weight_of_the_world[][2] = SONG(WEIGHT_OF_THE_WORLD);
float renai_circulation[][2] = SONG(RENAI_CIRCULATION);
float rick_roll[][2] = SONG(RICK_ROLL);
float song_of_the_ancients[][2] = SONG(SONG_OF_THE_ANCIENTS);
float all_star[][2] = SONG(ALL_STAR);
float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float numl_on[][2] = SONG(NUM_LOCK_ON_SOUND);
float numl_off[][2] = SONG(NUM_LOCK_OFF_SOUND);
float caps_word_on_song[][2] = SONG(ZELDA_PUZZLE);
float caps_word_off_song[][2] = SONG(ZELDA_TREASURE);
#endif

enum layers {
  BASE,
  GAME,
  STEN,
  SYMB,
  UTIL,
  NAVI,
  MOUS,
  GAMP,
  KRTA,
};

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
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
  DOT_SPAC,
  COMA_SPAC,
  SM_SLEP,
  SM_POWR,
  VRSN,
};



enum tap_dance_codes {
  STENO_GAME,
  BASE_GAME,
  STENO_BASE,
  VS_MOVE_EDITOR,
  ALT_F4,
};

#define HOME_SHIFT_HOME LT(7, KC_T)
#define END_SHIFT_END LT(10, KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]={
[BASE]=LAYOUT_moonlander(
TD(STENO_GAME),       	KC_F1,                	KC_F2,                	KC_F3,                	KC_F4,                	KC_F5,                	KC_F6,                	KC_F7,                	KC_F8,                	KC_F9,                	KC_F10,               	KC_F11,               	KC_F12,               	TD(STENO_GAME),       	
KC_BSLS,              	KC_QUOTE,             	KC_COMMA,             	KC_DOT,               	KC_P,                 	KC_Y,                 	_______,              	_______,              	KC_F,                 	KC_G,                 	KC_C,                 	KC_R,                 	KC_L,                 	KC_SLASH,             	
LT(4, KC_EQUAL),       	LALT_T(KC_A),         	LT(SYMB,KC_O),          LSFT_T(KC_E),         	LCTL_T(KC_U),         	KC_I,                 	_______,              	_______,              	KC_D,                 	RCTL_T(KC_H),         	RSFT_T(KC_T),         	LT(SYMB,KC_N),          RALT_T(KC_S),         	LT(UTIL,KC_MINUS),            	
SH_TOGG,              	KC_SCLN,              	KC_Q,                 	KC_J,                 	KC_K,                 	KC_X,                 	                                                KC_B,                 	KC_M,                 	KC_W,                 	KC_V,                 	KC_Z,                 	SH_TOGG,             	
TT(SYMB),             	TT(NAVI),             	TT(MOUS),             	DM_REC1,              	QK_ALT_REPEAT_KEY,    	                        DM_PLY1,              	DM_PLY2,              	                        QK_REPEAT_KEY,        	DM_REC2,              	TT(MOUS),             	TT(NAVI),             	TT(SYMB),             	
                                                KC_BSPC,              	                        LT(MOUS,KC_DELETE),     MT(MOD_LGUI,KC_ESCAPE), KC_RIGHT_GUI,         	LT(NAVI,KC_ENTER),      KC_SPACE
),                    	
[GAME]=LAYOUT_moonlander(
TD(STENO_BASE),       	_______,              	_______,              	_______,              	TD(ALT_F4),           	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	TD(STENO_BASE),       	
KC_BSPC,              	KC_TAB,               	KC_Q,                 	KC_W,                 	KC_E,                 	KC_R,                 	KC_T,                 	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
KC_ESCAPE,            	KC_CAPS,              	KC_A,                 	KC_S,                 	KC_D,                 	KC_F,                 	KC_G,                 	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
KC_DELETE,            	KC_LEFT_CTRL,         	KC_Z,                 	KC_X,                 	KC_C,                 	KC_V,                 	                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
XXXXXXX,                XXXXXXX,              	OSL(KRTA),             	KC_LEFT_ALT,          	KC_B,                 	                        KC_ENTER,             	_______,              	                        _______,              	_______,              	_______,              	_______,              	_______,              	
                                                                                                KC_LEFT_SHIFT,        	KC_SPACE,             	MO(GAMP),             	_______,              	_______,              	_______
),                    	
[STEN]=LAYOUT_moonlander(
TD(BASE_GAME),        	_______,              	_______,              	_______,              	_______,              	_______,              	QK_STENO_BOLT,        	QK_STENO_GEMINI,      	XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	TD(BASE_GAME),        	
XXXXXXX,              	STN_N1,               	STN_N2,               	STN_N3,               	STN_N4,               	STN_N5,               	XXXXXXX,              	XXXXXXX,              	STN_N6,               	STN_N7,               	STN_N8,               	STN_N9,               	STN_NA,               	STN_NB,               	
XXXXXXX,              	STN_S1,               	STN_TL,               	STN_PL,               	STN_HL,               	STN_ST1,              	XXXXXXX,              	XXXXXXX,              	STN_ST3,              	STN_FR,               	STN_PR,               	STN_LR,               	STN_TR,               	STN_DR,               	
XXXXXXX,              	STN_S2,               	STN_KL,               	STN_WL,               	STN_RL,               	STN_ST2,              	                                                STN_ST4,              	STN_RR,               	STN_BR,               	STN_GR,               	STN_SR,               	STN_ZR,               	
SHFT_ALT_TAB,         	XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	KC_LCTL,              	                        _______,              	_______,              	                        XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	XXXXXXX,              	ALT_TAB,              	
                                                                                                STN_A,                	STN_O,                	STN_NC,               	STN_NC,               	STN_E,                	STN_U
),                    	
[SYMB]=LAYOUT_moonlander(
QK_REBOOT,            	_______,               	_______,               	_______,               	_______,               	_______,               	_______,               	_______,               	_______,               	_______,               	_______,              	_______,               	_______,               	_______,              	
KC_NUM,               	KC_EXLM,              	KC_AT,                	KC_LCBR,              	KC_RCBR,              	KC_GRAVE,             	KC_TILD,              	KC_CALCULATOR,        	KC_PCMM,             	  KC_KP_7,              	KC_KP_8,              	KC_KP_9,              	KC_KP_0,              	KC_PSLS,             	
_______,              	KC_HASH,              	KC_DLR,               	KC_LPRN,              	KC_RPRN,              	KC_AMPR,              	_______,              	EURO_SIGN,            	KC_PDOT,               	KC_KP_4,              	KC_KP_5,              	KC_KP_6,              	KC_PAST,              	KC_PMNS,             	
KC_PIPE,              	KC_PERC,              	KC_CIRC,              	KC_LBRC,              	KC_RBRC,              	KC_ASTR,              	                                                KC_COLN,              	KC_KP_1,              	KC_KP_2,              	KC_KP_3,              	KC_PPLS,              	KC_PEQL,          	
_______,              	_______,              	_______,              	_______,              	_______,              	                        _______,              	_______,              	                        KC_KP_0,              	KC_KP_0,              	KC_PDOT,               	_______,              	_______,              	
                                                                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______
),                    	
[UTIL]=LAYOUT_moonlander(
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	SM_POWR,              	SM_SLEP,              	_______,              	_______,              	_______,              	_______,              	QK_BOOT,              	
_______,               	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	NOTE_PAD,             	DT_UP,                	LCTL(LSFT(KC_F12)),   	LALT(LCTL(KC_UP)),    	LCTL(KC_F12),         	_______,              	_______,              	
AC_TOGG,              	EMPT_FUNC,            	_______,              	_______,              	LCTL(LSFT(KC_GRAVE)), 	LCTL(LSFT(KC_M)),     	_______,              	VS_CODE,              	DT_PRNT,              	VS_WIND_LEFT,         	TD(VS_MOVE_EDITOR),   	VS_WIND_RIGHT,        	_______,              	_______,              	
QK_AUDIO_TOGGLE,      	_______,              	_______,              	_______,              	_______,              	_______,              	                                                DT_DOWN,              	LCTL(KC_I),           	LALT(LCTL(KC_DOWN)),  	LALT(LCTL(KC_I)),     	_______,              	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	                        RGB_MODE_FORWARD,     	RGB_TOG,              	                        _______,              	_______,              	_______,              	_______,              	_______,              	
                                                                                                RGB_VAD,              	RGB_VAI,              	TOGGLE_LAYER_COLOR,   	RGB_SLD,              	RGB_HUD,              	RGB_HUI
),                    	
[NAVI]=LAYOUT_moonlander(
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	KC_PAGE_UP,           	HOME_SHIFT_HOME,      	KC_UP,                	END_SHIFT_END,        	KC_MS_WH_UP,          	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	KC_PGDN,              	KC_LEFT,              	KC_DOWN,              	KC_RIGHT,             	KC_MS_WH_DOWN,        	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	                                                _______,              	SHFT_ALT_TAB,         	ALT_TAB,              	SHFT_CTRL_TAB,        	CTRL_TAB,             	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	                        _______,              	_______,              	                        KC_WWW_BACK,          	KC_WWW_FORWARD,       	_______,              	_______,              	_______,              	
                                                                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______
),                    	
[MOUS]=LAYOUT_moonlander(
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,               	_______,              	_______,              	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	KC_AUDIO_VOL_UP,      	KC_MS_BTN1,           	KC_MS_UP,             	KC_MS_BTN2,           	KC_MS_WH_UP,          	KC_MPLY,              	
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	KC_AUDIO_VOL_DOWN,    	KC_MS_LEFT,           	KC_MS_DOWN,           	KC_MS_RIGHT,          	KC_MS_WH_DOWN,        	KC_APP,               	
_______,              	_______,              	KC_MS_ACCEL0,          	KC_MS_ACCEL1,           KC_MS_ACCEL2,          	_______,              	                                                KC_AUDIO_MUTE,        	KC_MS_WH_LEFT,        	KC_MS_BTN3,           	KC_MS_WH_RIGHT,       	KC_MS_JIGGLER_TOGGLE, 	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	                        _______,              	_______,              	                        KC_MS_BTN4,           	KC_MS_BTN5,           	_______,              	_______,              	_______,              	
                                                                                                _______,              	_______,              	_______,              	_______,              	_______,              	KC_MS_BTN1
),                    	
[GAMP]=LAYOUT_moonlander(
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	KC_Y,                 	KC_O,                 	KC_I,                 	KC_U,                 	KC_P,                 	KC_Y,                 	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	KC_T,                 	KC_1,                 	KC_2,                 	KC_3,                 	KC_H,                 	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	KC_J,                 	KC_K,                 	KC_L,                 	KC_M,                 	KC_N,                 	                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	                        _______,              	_______,              	                        _______,              	_______,              	_______,              	_______,              	_______,              	
                                                                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______
),                         	
[KRTA]=LAYOUT_moonlander(
_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	_______,               	LCTL(LALT(KC_7)),       LCTL(LALT(KC_8)),       LCTL(LALT(KC_9)),      	_______,                _______,               	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	_______,               	LCTL(LALT(KC_4)),       LCTL(LALT(KC_5)),       LCTL(LALT(KC_6)),      	_______,                _______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	LCTL(LALT(KC_0)),       LCTL(LALT(KC_1)),       LCTL(LALT(KC_2)),       LCTL(LALT(KC_3)),      	_______,                 	                                              _______,              	_______,              	_______,              	_______,              	_______,              	_______,              	
_______,              	_______,              	_______,              	_______,              	_______,              	                        _______,              	_______,              	                        _______,              	_______,              	_______,              	_______,              	_______,              	
                                                                                                _______,              	_______,              	_______,              	_______,              	_______,              	_______
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

const uint16_t PROGMEM combo0[] = { KC_Q, KC_J, LSFT_T(KC_E), LT(SYMB, KC_O), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_D, KC_C, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_SCLN, LALT_T(KC_A), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_Q, LT(SYMB, KC_O), COMBO_END};
const uint16_t PROGMEM combo4[] = { LCTL_T(KC_U), KC_K, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_Z, RALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_A, KC_Z, KC_X, KC_S, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_SCLN, KC_Q, LSFT_T(KC_E), KC_J, LT(SYMB, KC_O), LALT_T(KC_A), COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_CAPS, KC_LEFT_CTRL, KC_Z, KC_A, KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_SPACE, LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo16[] = { KC_Q, KC_J, RSFT_T(KC_T), LT(SYMB, KC_N), COMBO_END};
const uint16_t PROGMEM combo17[] = { LSFT_T(KC_E), KC_W, KC_V, LT(SYMB, KC_O), COMBO_END};
const uint16_t PROGMEM combo18[] = { KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_O, KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo21[] = { KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM combo22[] = { KC_SPACE, RCTL_T(KC_H), RSFT_T(KC_T), LT(SYMB, KC_N), COMBO_END};
const uint16_t PROGMEM combo23[] = { KC_M, KC_W, KC_V, KC_SPACE, COMBO_END};
const uint16_t PROGMEM combo24[] = { KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM combo25[] = { KC_M, RCTL_T(KC_H), COMBO_END};
const uint16_t PROGMEM combo26[] = { RSFT_T(KC_T), KC_W, COMBO_END};
const uint16_t PROGMEM combo27[] = { RCTL_T(KC_H), RSFT_T(KC_T), LT(SYMB, KC_N), COMBO_END};
const uint16_t PROGMEM combo28[] = { KC_M, KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo29[] = { RCTL_T(KC_H), RSFT_T(KC_T), LT(SYMB, KC_N), LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo30[] = { KC_M, KC_W, KC_V, LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo31[] = { KC_SPACE, RCTL_T(KC_H), RSFT_T(KC_T), LT(SYMB, KC_N), LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo32[] = { KC_SPACE, KC_M, KC_W, KC_V, LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo33[] = { KC_RIGHT_GUI, LT(NAVI, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo34[] = { KC_M, RSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo35[] = { RSFT_T(KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo36[] = { LT(SYMB, KC_N), KC_V, RSFT_T(KC_T), KC_W, COMBO_END};
const uint16_t PROGMEM combo37[] = { HOME_SHIFT_HOME, KC_UP, END_SHIFT_END, COMBO_END};
const uint16_t PROGMEM combo38[] = { KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo39[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo40[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo41[] = { RCTL_T(KC_H), KC_M, KC_V, LT(SYMB, KC_N), COMBO_END};
const uint16_t PROGMEM combo42[] = { KC_M, KC_W, RSFT_T(KC_T), LT(SYMB, KC_N), COMBO_END};
const uint16_t PROGMEM combo43[] = { RCTL_T(KC_H), KC_M, KC_W, RSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo44[] = { RCTL_T(KC_H), KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo45[] = { LT(SYMB, KC_N), KC_V, COMBO_END};
const uint16_t PROGMEM combo46[] = { KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo47[] = { KC_M, RCTL_T(KC_H), RSFT_T(KC_T), LT(SYMB, KC_N), KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM combo48[] = { KC_M, RSFT_T(KC_T), KC_V, COMBO_END};
const uint16_t PROGMEM combo49[] = { RCTL_T(KC_H), RSFT_T(KC_T), KC_W, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LGUI(KC_DOT)),
    COMBO(combo1, ALT_TAB),
    COMBO(combo2, GER_AE),
    COMBO(combo3, GER_OE),
    COMBO(combo4, GER_UE),
    COMBO(combo5, GER_SZ),
    COMBO(combo6, KC_MEDIA_PLAY_PAUSE),
    COMBO(combo7, TO(GAME)),
    COMBO(combo8, TO(BASE)),
    COMBO(combo9, KC_4),
    COMBO(combo10, KC_5),
    COMBO(combo11, KC_6),
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
  [GAME] = {
{32,226,188}, 	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{188,255,255},	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{188,255,255},	{188,255,255},	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{188,255,255},	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,255,104},  	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                {0,0,0},      	{0,0,0},      	                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
                                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0}
},

  [STEN] = {
{21,237,224}, 	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	
{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	
{175,172,207},	{73,158,185}, 	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{175,172,207},	{21,237,224}, 	{175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	
{175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	                                {175,172,207},	{175,172,207},	{175,172,207},	{0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	
{175,172,207},	{0,0,0},      	{0,0,0},      	{175,172,207},	                {175,172,207},	{175,172,207},	                {0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{73,158,185}, 	
                                                {0,0,0},      	{0,0,0},      	{175,172,207},	{175,172,207},	{175,172,207},	{175,172,207}
},

  [SYMB] = {
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                                {0,245,245},  	{0,245,245},  	{0,245,245},  	{0,0,0},      	{0,0,0},      	{0,245,245},  	{0,245,245},  	
{0,245,245},  	{0,0,0},      	{0,0,0},      	{0,245,245},  	                {0,245,245},  	{0,245,245},  	                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
                                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0}
},
  
  [UTIL] = {
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{40,240,174}, 	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{190,238,63}, 	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,54,140},   	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                                {221,236,121},	{176,241,174},	{21,237,224}, 	{0,0,0},      	{0,0,0},      	{176,241,174},	{144,199,242},	
{176,241,174},	{0,0,0},      	{0,0,0},      	{221,236,121},	                {176,241,174},	{21,237,224}, 	                {0,0,0},      	{20,230,227}, 	{74,255,255}, 	{74,255,255}, 	{74,255,255}, 	{0,218,204},  	
                                                {131,219,203},	{148,219,203},	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0}
},
  
  [NAVI] = {
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{172,255,255},	{172,255,255},	{69,201,230}, 	{0,0,0},      	{0,0,0},      	                                {123,232,160},	{20,250,216}, 	{69,201,230}, 	{0,0,0},      	{0,0,0},      	{20,250,216}, 	{20,250,216}, 	
{199,255,176},	{0,0,0},      	{0,0,0},      	{123,232,160},	                {20,250,216}, 	{199,255,176},	                {0,0,0},      	{0,0,0},      	{0,207,168},  	{0,207,168},  	{0,0,0},      	{0,0,0},      	
                                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0}
},
  
  [MOUS] = {
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{188,255,255},	{41,255,255}, 	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{172,255,255},	{172,255,255},	{0,255,112},  	{0,0,0},      	{74,255,255}, 	                                {180,227,168},	{20,250,216}, 	{172,255,255},	{0,0,0},      	{74,255,255}, 	{20,250,216}, 	{20,250,216}, 	
{180,227,168},	{123,255,255},	{74,255,255}, 	{180,227,168},	                {20,250,216}, 	{172,255,255},	                {123,255,255},	{0,0,0},      	{219,255,255},	{219,255,255},	{219,255,255},	{0,0,0},      	
                                                {0,0,0},      	{0,0,0},      	{180,227,168},	{0,0,0},      	{0,0,0},      	{0,0,0}
},

  [GAMP] = {
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{186,255,112},	{0,0,0},      	{0,0,0},      	{0,224,133},  	{0,218,204},  	{198,255,112},	
{0,0,0},      	{0,0,0},      	{104,179,197},	{19,218,204}, 	{216,255,112},	{0,0,0},      	{0,0,0},      	{192,224,133},	{40,218,204}, 	{20,255,65},  	{0,0,0},      	{0,0,0},      	{28,174,241}, 	{0,255,112},  	
{238,218,204},	{0,0,0},      	{247,218,204},	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	                {0,0,0},      	{0,0,0},      	                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	
                                                {0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0},      	{0,0,0}
},
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

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    if(biton32(layer_state)>0){
      set_layer_color(biton32(layer_state));
    }
    else {
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
  
  static tap dance_state[5];
  
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
  
  void steno_game_each(tap_dance_state_t *state, void *user_data);
  void steno_game_finished(tap_dance_state_t *state, void *user_data);
  void steno_game_reset(tap_dance_state_t *state, void *user_data);
  
  void steno_game_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 3:
            STATUS_LED_1(true);
            break;
        case 4:
            STATUS_LED_2(true);
            break;
        case 5:
            STATUS_LED_3(true);
            break;
        case 6:        
            STATUS_LED_4(true);
            break;
        case 7:
            STATUS_LED_5(true);
          case 8:
            STATUS_LED_6(true);
          break;
        default:
            // reset all LEDs
            STATUS_LED_6(false);
            wait_ms(50);
            STATUS_LED_5(false);
            wait_ms(50);
            STATUS_LED_4(false);
            wait_ms(50);
            STATUS_LED_3(false);
            wait_ms(50);
            STATUS_LED_2(false);
            wait_ms(50);
            STATUS_LED_1(false);
    }
  }


  void steno_game_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[STENO_GAME].step = dance_step(state);
    switch (dance_state[STENO_GAME].step) {
      case SINGLE_TAP: layer_move(STEN); break;
      case SINGLE_HOLD: layer_move(STEN); break;
      case DOUBLE_TAP: layer_move(GAME); break;
      case DOUBLE_SINGLE_TAP: layer_move(STEN); break;
    }
  }
  
  void steno_game_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[STENO_GAME].step) {
      case MORE_TAPS: {
            STATUS_LED_1(false);
            wait_ms(50);
            STATUS_LED_2(false);
            wait_ms(50);
            STATUS_LED_3(false);
            wait_ms(50);
            STATUS_LED_4(false);
            wait_ms(50);
            STATUS_LED_5(false);
            wait_ms(50);
            STATUS_LED_6(false);
            #ifdef AUDIO_ENABLE
            switch (state->count)
            {
            case 3:
              PLAY_SONG(megalovania);
              break;
            case 4: PLAY_SONG(weight_of_the_world);
              break;
            case 5: PLAY_SONG(renai_circulation);
              break;
            case 6: PLAY_SONG(rick_roll);
              break;
            case 7: PLAY_SONG(song_of_the_ancients);
              break;
            case 8: PLAY_SONG(all_star);
              break;
            }
            #endif
      }
    }
    dance_state[STENO_GAME].step = 0;
  }
  void base_game_finished(tap_dance_state_t *state, void *user_data);
  void base_game_reset(tap_dance_state_t *state, void *user_data);
  
  void base_game_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[BASE_GAME].step = dance_step(state);
    switch (dance_state[BASE_GAME].step) {
      case SINGLE_TAP: layer_move(BASE); break;
      case SINGLE_HOLD: layer_move(BASE); break;
      case DOUBLE_TAP: layer_move(GAME); break;
      case DOUBLE_SINGLE_TAP: layer_move(BASE); break;
    }
  }
  
  void base_game_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[BASE_GAME].step) {
    }
    dance_state[BASE_GAME].step = 0;
  }
  void steno_base_finished(tap_dance_state_t *state, void *user_data);
  void steno_base_reset(tap_dance_state_t *state, void *user_data);
  
  void steno_base_finished(tap_dance_state_t *state, void *user_data) {
      dance_state[STENO_BASE].step = dance_step(state);
      switch (dance_state[STENO_BASE].step) {
          case SINGLE_TAP: layer_move(BASE); break;
          case SINGLE_HOLD: layer_move(BASE); break;
          case DOUBLE_TAP: layer_move(STEN); break;
          case DOUBLE_SINGLE_TAP: layer_move(BASE); break;
      }
  }
  
  void steno_base_reset(tap_dance_state_t *state, void *user_data) {
      wait_ms(10);
      switch (dance_state[STENO_BASE].step) {
      }
      dance_state[STENO_BASE].step = 0;
  }
  void on_vs_move_editor(tap_dance_state_t *state, void *user_data);
  void vs_move_editor_finished(tap_dance_state_t *state, void *user_data);
  void vs_move_editor_reset(tap_dance_state_t *state, void *user_data);
  
  void on_vs_move_editor(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
      tap_code16(LALT(LCTL(KC_RIGHT)));
      tap_code16(LALT(LCTL(KC_RIGHT)));
      tap_code16(LALT(LCTL(KC_RIGHT)));
    }
    if(state->count > 3) {
      tap_code16(LALT(LCTL(KC_RIGHT)));
    }
  }
  
  void vs_move_editor_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[VS_MOVE_EDITOR].step = dance_step(state);
    switch (dance_state[VS_MOVE_EDITOR].step) {
      case SINGLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); break;
      case DOUBLE_TAP: register_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT))); break;
      case DOUBLE_HOLD: register_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_RIGHT))); register_code16(LALT(LCTL(KC_RIGHT)));
    }
}

void vs_move_editor_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[VS_MOVE_EDITOR].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(KC_LEFT))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_RIGHT))); break;
    }
    dance_state[VS_MOVE_EDITOR].step = 0;
}
void on_alt_F4(tap_dance_state_t *state, void *user_data);
void alt_F4_finished(tap_dance_state_t *state, void *user_data);
void alt_F4_reset(tap_dance_state_t *state, void *user_data);

void on_alt_F4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void alt_F4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[ALT_F4].step = dance_step(state);
    switch (dance_state[ALT_F4].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void alt_F4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[ALT_F4].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[ALT_F4].step = 0;
}


tap_dance_action_t tap_dance_actions[] = {
        [STENO_GAME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, steno_game_finished, steno_game_reset),
        [VS_MOVE_EDITOR] = ACTION_TAP_DANCE_FN_ADVANCED(on_vs_move_editor, vs_move_editor_finished, vs_move_editor_reset),
        [STENO_BASE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, steno_base_finished, steno_base_reset),
        [ALT_F4] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt_F4, alt_F4_finished, alt_F4_reset),
        [BASE_GAME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_game_finished, base_game_reset),
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
    case EURO_SIGN:
    if (record->event.pressed) {
      process_alt_num_key("00128");
    }
    return false;
    case GER_SZ:
    if (record->event.pressed) {
      process_alt_num_key("0223");
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
    case DOT_SPAC:
    if (record->event.pressed) {
      SEND_STRING(". ");
    }
    break;
    case COMA_SPAC:
    if (record->event.pressed) {
      SEND_STRING(", ");
    }
    break;
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
    case TAB_SHIFT_TAB:
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
    case HOME_SHIFT_HOME:
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
    case END_SHIFT_END:
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
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
  if (get_highest_layer(layer_state) != BASE)
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
        case TAB_SHIFT_TAB:
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
            return 0;
        case LT(SYMB, KC_O):
        case LT(SYMB, KC_N):
            return 60;
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

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&next_track_override,
	&prev_track_override,
	&vol_up_override,
	&vol_down_override,
	&brightness_up_override,
	&brightness_down_override
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