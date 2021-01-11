/* Copyright 2020 @wafflekeebs/@waffle#6666
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

enum unicodemap_names {
    SIDE,
    UPAR,
    HAS,
    STAR,
    VIB
};

enum {
  HAP_SAD,
  QMK,
  DOCS,
  LINKS,
};

enum typing_mode {
  TM_NOMODE,
  TM_REGIONAL,
  TM_WIDE,
  TM_SCRIPT,
  TM_BLOCKS,
  TM_AUSSIE,
  TM_ZALGO,
  TM_WOWMODE,
  TM_D3MODE
};

enum custom_keycodes {
  CP_PSTE = SAFE_RANGE,
  UNIT,
  UNIT2,
  UNIT3,
  UNIT4,
  WEEB,
  CTLS,
  SSH_PI,
  GIT,
  SETUP,
  ZAD,
  CONF,
  MMAP,
  NKINV,
  VIA,
  CD1,
  ALT_TAB,
  MAKE,
  NANORESET,
  KC_NOMODE,
  KC_REGIONAL,
  KC_WIDE,
  KC_SCRIPT,
  KC_BLOCKS,
  KC_AUSSIE,
  KC_ZALGO,
  KC_WOWMODE,
  KC_D3MODE
};

#define LOWER MO(1)
#define RAISE MO(2)
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
#define HAPSAD TD(HAP_SAD)
#define DOCSTD TD(DOCS)
#define LINKSTD TD(LINKS)
#define QMKTD TD(QMK)
#define ZHAP X(SIDE)
#define ARWUP X(UPAR)
#define STARX X(STAR)
