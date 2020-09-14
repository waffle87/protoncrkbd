#pragma once

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LOWER:
          if (record->event.pressed) {
              layer_on(_LOWER);
          } else {
              layer_off(_LOWER);
          }
          return false;
      case RAISE:
          if (record->event.pressed) {
              layer_on(_RAISE);
          } else {
              layer_off(_RAISE);
          }
          return false;
      case ADJUST:
          if (record->event.pressed) {
              layer_on(_ADJUST);
          } else {
              layer_off(_ADJUST);
          }
          return false;
      case CP_PSTE:
        if (record->event.pressed) {
            tap_code16(C(KC_C));
        } else {
            tap_code16(C(KC_V));
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

      case UNIT3:
        if (record->event.pressed) {
          send_unicode_string("ﾟ･✿ヾ╲(｡◕‿◕｡)╱✿･ﾟ");
        } else {
        }
        break;

      case UNIT4:
        if (record->event.pressed) {
          send_unicode_string("╰༼.◕ヮ◕.༽つ¤=[]—————");
        } else {
        }
        break;

      case UNIT5:
        if (record->event.pressed) {
          send_unicode_string("｡＾･ｪ･＾｡");
        } else {
        }
        break;

      case UNIT6:
        if (record->event.pressed) {
          send_unicode_string("へ‿(ツ)‿ㄏ");
        } else {
        }
        break;

      case SSH_PI:
        if (record->event.pressed) {
            SEND_STRING("ssh pi@applepi.local"SS_TAP(X_ENTER) SS_DELAY(10000) "password_lol"SS_TAP(X_ENTER));
        } else {
        }
        break;

      case CTLS:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_S)SS_UP(X_LCTL));
        } else {
        }
        break;

      case ALT_TAB:
        if (record->event.pressed) {
          if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
          }
          alt_tab_timer = timer_read();
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;

      case CAD:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BSPC))));
          return false;
        }
        break;

      case MAKE:
        if (!record->event.pressed) {
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
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
