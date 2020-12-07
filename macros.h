/* Copyright 2020 @toastedmangoes/@waffle#6666
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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case CP_PSTE:
        if (record->event.pressed) {
            tap_code16(G(KC_C));
        } else {
            tap_code16(G(KC_V));
        }
        return false;

      case MT(MOD_LSFT, KC_F23):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_EXLM);
          } else {
            unregister_code16(KC_EXLM);
          }
          return false;
        }
        break;


      case MT(MOD_RSFT, KC_F24):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_RPRN);
          } else {
            unregister_code16(KC_RPRN);
          }
          return false;
        }
        break;

      case MT(MOD_RSFT, KC_F22):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_LPRN);
          } else {
            unregister_code16(KC_LPRN);
          }
          return false;
        }
        break;

#ifdef UNICODE_ENABLE
      case UNIT:
        if (record->event.pressed) {
          send_unicode_string("(＾▽＾)");
        } else {
        }
        break;

      case UNIT2:
        if (record->event.pressed) {
          send_unicode_string("≧ω≦");
        } else {
        }
        break;

      case UNIT4:
        if (record->event.pressed) {
        send_unicode_string("(╯°□°）╯︵ ┻━┻");
        } else {
        }
        break;

      case UNIT5:
        if (record->event.pressed) {
          send_unicode_string("┬──┬ ノ( ゜-゜ノ)");
        } else {
        }
        break;
#endif

      case SSH_PI:
        if (record->event.pressed) {
            SEND_STRING("ssh pi@___.local"SS_TAP(X_ENTER) SS_DELAY(2000) "___"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case CTLS:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_S)SS_UP(X_LGUI));
        } else {
        }
        break;

        case GIT:
          if (record->event.pressed) {
            SEND_STRING("https://github.com/qmk/qmk_firmware/find/master"SS_TAP(X_ENTER));
          } else {
          }
          break;

        case SETUP:
          if (record->event.pressed) {
            SEND_STRING("___");
          } else {
          }
          break;

        case ZAD:
          if (record->event.pressed) {
            SEND_STRING("___");
          } else {
          }
          break;

        case CONF:
          if (record->event.pressed) {
            SEND_STRING("https://config.qmk.fm/#/"SS_TAP(X_ENTER));
          } else {
          }
          break;

        case MMAP:
            if (record->event.pressed) {
                SEND_STRING("___"SS_TAP(X_ENTER)SS_TAP(X_ENTER));
                SEND_STRING("___"SS_TAP(X_ENTER));
            } else {
            }
            break;

        case NKINV:
            if (record->event.pressed) {
                SEND_STRING("___"SS_TAP(X_ENTER));
            } else {
            }
            break;

        case VIA:
            if (record->event.pressed) {
                SEND_STRING("https://caniusevia.com/docs/download_firmware"SS_TAP(X_ENTER));
            } else {
            }
            break;

        case CD1:
          if (record->event.pressed) {
            SEND_STRING("cd qmk_firmware"SS_TAP(X_ENTER));
          } else {
          }
          break;

      case ALT_TAB:
        if (record->event.pressed) {
          if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LGUI);
          }
          alt_tab_timer = timer_read();
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;

      case MAKE:
        if (!record->event.pressed) {
          //SEND_STRING("cd qmk_firmware"(SS_DELAY(500));
          SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                          ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                          ":teensy"
#elif defined(BOOLOADER_CATERINA)
                          ":avrdude"
#endif
                          SS_TAP(X_ENTER));
            }
            return false;
            break;

  }
  return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }
}
