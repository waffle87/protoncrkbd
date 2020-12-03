#pragma once

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CP_PSTE,
  SSH_PI,
  ALT_TAB,
  CTLS,
  MAKE,
  UNIT,
  UNIT2,
  UNIT4,
  UNIT5,
  GIT,
  SETUP,
  ZAD,
  MMAP,
  NKINV,
  CONF,
  VIA,
  CD1
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SFA SFT_T(KC_A)
#define SFCLN RSFT_T(KC_SCLN)
#define CTLSLH RCTL_T(KC_SLSH)
#define SFEXM MT(MOD_LSFT, KC_F23)
#define SFPRN MT(MOD_RSFT, KC_F24)
#define CTLESC CTL_T(KC_ESC)
#define CTLTZ CTL_T(KC_Z)
#define CTLNXT RCTL_T(KC_MNXT)
#define GPSCR G(KC_PSCR)
#define MPSCR G(S(KC_4))
#define CTLBSP ALT_T(KC_DEL)
#define SFL SFT_T(KC_L)
#define SFLPRN MT(MOD_RSFT, KC_F22)



