/* Copyright 2020 @toastedmangoes
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

enum combos {
  RU_ENT,
  EI_BSP,
  GH_QUOT,
  VM_QUES,
  CM_DQUO,
  TY_COLN,
  DF_BTN1,
  JK_BTN2,
  VB_WHD,
  NM_WHU
};

const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cm_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[RU_ENT] = COMBO(ru_combo, KC_ENT),
[EI_BSP] = COMBO(ei_combo, CTLBSP),
[GH_QUOT] = COMBO(gh_combo, KC_QUOT),
[VM_QUES] = COMBO(vm_combo, KC_QUES),
[CM_DQUO] = COMBO(cm_combo, KC_DQUO),
[TY_COLN] = COMBO(ty_combo, KC_COLN),
[DF_BTN1] = COMBO(df_combo, KC_BTN1),
[JK_BTN2] = COMBO(jk_combo, KC_BTN2),
[VB_WHD] = COMBO(vb_combo, KC_WH_D),
[NM_WHU] = COMBO(nm_combo, KC_WH_U)
};
