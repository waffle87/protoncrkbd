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

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(":widepeepohappy1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeepohappy2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
    } else {
      SEND_STRING(":widepeeposad1"SS_TAP(X_ENTER)SS_TAP(X_BSPC)":widepeeposad2"SS_TAP(X_ENTER)SS_TAP(X_BSPC)SS_TAP(X_ENTER));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [HAP_SAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, NULL),
};

