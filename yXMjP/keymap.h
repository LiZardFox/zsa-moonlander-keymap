#pragma once

#include QMK_KEYBOARD_H


#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE

enum layer_names {
  BASE = 0,
  STEN,
  NMSY,
  UTIL,
  NAVI,
  MOUS,
  GAME,
  GAMP,
  KRIT
};

#define NAV_EQL LT(NAVI, KC_EQUAL)
#define UTL_MNS LT(UTIL, KC_MINUS)
#define OS_KRIT OSL(KRIT)
#define MO_GAMP MO(GAMP)
#define MOU_BSP LT(MOUS, KC_BSPC)
#define NAV_ENT  LT(NAVI, KC_ENTER)

#define STEN_TT TT(STEN) 
#define NMSY_TT TT(NMSY) 
#define UTIL_TT TT(UTIL) 
#define NAVI_TT TT(NAVI) 
#define MOUS_TT TT(MOUS) 
#define GAME_TT TT(GAME) 
#define GAMP_TT TT(GAMP) 
#define KRIT_TT TT(KRIT) 

// RGB
#define TOGG_LC TOGGLE_LAYER_COLOR

// Right hand home row
#define HOME_A MT(MOD_LALT, KC_A)
#define HOME_O LT(NMSY, KC_O)
#define HOME_E MT(MOD_LSFT, KC_E)
#define HOME_U MT(MOD_LCTL, KC_U)

// Left hand home row
#define HOME_H MT(MOD_RCTL, KC_H)
#define HOME_T MT(MOD_RSFT, KC_T)
#define HOME_N LT(NMSY, KC_N)
#define HOME_S MT(MOD_RALT, KC_S)

// Meh keys
#define MEH_J MEH_T(KC_J)
#define MEH_W MEH_T(KC_W)

// One Shot Modifiers
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)

#define LGUI_ESC  MT(MOD_LGUI, KC_ESCAPE)

// Shortcuts
#define SA_TAB S(A(KC_TAB))
#define A_TAB A(KC_TAB)
#define SC_TAB S(C(KC_TAB))
#define C_TAB C(KC_TAB)

#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COPY LCTL(KC_C)
#define CUT  LCTL(KC_X)
#define CLPBRD LGUI(KC_V)
#define PASTE_F LCTL(LSFT(KC_V))
// VS Code
#define VS_TRMNL = LCTL(LSFT(KC_GRAVE))

//Krita Shortcuts
#define KR_BRSH0 LALT(LCTL(KC_0))
#define KR_BRSH1 LALT(LCTL(KC_1))
#define KR_BRSH2 LALT(LCTL(KC_2))
#define KR_BRSH3 LALT(LCTL(KC_3))
#define KR_BRSH4 LALT(LCTL(KC_4))
#define KR_BRSH5 LALT(LCTL(KC_5))
#define KR_BRSH6 LALT(LCTL(KC_6))
#define KR_BRSH7 LALT(LCTL(KC_7))
#define KR_BRSH8 LALT(LCTL(KC_8))
#define KR_BRSH9 LALT(LCTL(KC_9))
#define KR_DUPLL LCTL(KC_J)


enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,  
  CR_EURO,
  NOTE_PAD,
  VS_CODE,
  GER_AE,
  GER_OE,
  GER_UE,
  GER_SZ,
  NEXTSEN,
  JOINLN,
  SRCHSEL,
  BRACES,
  QUOP,
  JIGGLE
};

#ifdef TAP_DANCE_ENABLE

enum tap_dance_codes {
  TDSTGA,
  TDBAGA,
  TDBAST,
  TDLOCK,
  TDEDMO,
  TDALF4,
};

#define TD_STGA  TD(TDSTGA)
#define TD_BAGA  TD(TDBAGA)
#define TD_BAST  TD(TDBAST)
#define TD_LOCK  TD(TDLOCK)
#define TD_EDMO  TD(TDEDMO)
#define TD_ALF4  TD(TDALF4)

#else 

#define TD_STGA  TG(STEN)
#define TD_BAGA  TG(BASE)
#define TD_BAST  TG(BASE)
#define TD_LOCK  KC_TRNS
#define TD_EDMO  KC_TRNS
#define TD_ALF4  KC_F4

#endif


#define HOM_SFT LT(1, KC_S)
#define END_SFT LT(3, KC_F18)