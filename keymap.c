#include QMK_KEYBOARD_H
#include "keycodes.h"

#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif

enum unicodemap_names {
    SNEK,
    HAP,
    SPK,
    AAA,
    BBB,
    CCC,
    DDD,
    EEE,
    FFF,
    GGG,
    HHH,
    JJJ,
    KKK,
    LLL,
    MMM,
    NNN,
    OOO,
    PPP,
    QQQ,
    RRR,
    SSS,
    TTT,
    UUU,
    VVV,
    WWW,
    XXX,
    YYY,
    ZZZ
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    //|------------------------------------------------------------|        |-----------------------------------------------------------|
       SSH_PI,    KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                G(KC_PSCR),
    //|--------+--------+--------+--------+--------+--------------|         |--------+--------+--------+--------+--------+--------------|
       ALT_TAB,    SFT_T(KC_A),   KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),    MAKE,
    //---------+--------+--------+--------+--------+-------------|          |--------+--------+--------+--------+--------+--------------|
       CP_PSTE,    CTL_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH),    TG(4),
    //---------+--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(1), KC_SPC,          KC_BSPC, MO(2), TG(3)
                                      //|----------------------------|  |------------------------|


  ),

  [_LOWER] = LAYOUT(
    //|-------------------------------------------------------------|            |------------------------------------------------------------------|
       CAD,       KC_1,                 KC_2,   KC_3,    KC_4,    KC_5,           KC_6,     KC_7,     KC_8,     KC_9,      KC_0,                  XXXXXXX,
    //|--------+--------+--------+--------+--------+----------------|            |--------+--------+--------+--------+--------+---------------------|
       XXXXXXX,   MT(MOD_LSFT, KC_F23), KC_AT,  KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN ,  MT(MOD_RSFT, KC_F24),  XXXXXXX,
    //|--------+--------+--------+--------+--------+----------------|            |--------+--------+--------+--------+--------+---------------------|
       XXXXXXX,   CTL_T(KC_ESC),        KC_TAB, KC_CAPS, KC_TILD, KC_GRV,         KC_QUOT,  KC_PSCR,  KC_MPRV,  KC_MPLY,  RCTL_T(KC_MNXT),        XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+------------|  |--------+--------+--------+--------+--------+--------+-----------------|
                                        LGUI_T(KC_PGUP), KC_TRNS, KC_SPC,    KC_ENT, KC_TRNS, LALT_T(KC_PGDN)
                                   //|----------------------------------|  |---------------------------------|
  ),

  [_RAISE] = LAYOUT(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
       XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,                      MAKE,    UNIT,    UNIT2,   UNIT3,   UNIT4,   RESET,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                      X(SPK),  KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                      KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_VOLD, KC_TRNS, KC_SPC,    KC_ENT, KC_TRNS, KC_VOLU
                                      //|---------------------------|  |---------------------------------------|
  ),

  [_ADJUST] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, CK_RST,  CK_DOWN, CK_UP,   CK_TOGG, RGB_TOG,                       MU_TOG, _______, KC_ASON, KC_ASDN, UC_M_WC, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                       MU_MOD, _______, KC_ASOFF, KC_ASUP, UC_M_MA, _______,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGBRST,                        AU_TOG, _______, _______, _______, UC_M_LN, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TG(5), KC_TRNS, _______,    _______, KC_TRNS, TG(3) \
                                      //|--------------------------|  |--------------------------|
  ),

  [_FUN] = LAYOUT(
    //|----------------------------------------------------------|                |------------------------------------------------------|
       XXXXXXX,  COMP6,    COMPKB,   _______,  _______,  _______,                  _______, _______, _______, _______, _______, XXXXXXX,
    //|--------+--------+--------+--------+--------+-------------|                |--------+--------+--------+--------+--------+---------|
       XXXXXXX,  _______,  _______,  _______,  _______,  _______,                  _______, _______, _______, _______, _______, XXXXXXX,
    //|--------+--------+--------+--------+--------+-------------|                |--------+--------+--------+--------+--------+---------|
       XXXXXXX,  _______,  _______,  _______,  _______,  _______,                  _______, _______, _______, _______, _______, TG(4),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+----------|
                                          _______, KC_TRNS, _______,    _______, KC_TRNS, _______
                                      //|---------------------------|  |---------------------------------------|
  ),

  [_UNICODE] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, X(QQQ),  X(WWW), X(EEE), X(RRR), X(TTT),                            X(YYY), X(UUU), X(III),  X(OOO),  X(PPP),  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, X(AAA), X(SSS), X(DDD), X(FFF), X(GGG),                             X(HHH), X(JJJ), X(KKK),  X(LLL),  _______, _______,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, X(ZZZ), X(XXX), X(CCC), X(VVV), X(BBB),                             X(NNN), X(MMM), UNIG,    _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         TG(5), KC_TRNS, _______,    _______, KC_TRNS, _______ \
                                      //|--------------------------|  |--------------------------|
  )
};

const uint32_t PROGMEM unicode_map[] = {
    [SNEK] = 0x1F40D,
    [HAP] = 0xFF3E,
    [SPK] = 0x2728,
    [AAA] = 0x1F1E6,
    [BBB] = 0x1F1E7,
    [CCC] = 0x1F1E8,
    [CCC] = 0x,
    [DDD] = 0x1F1E9,
    [EEE] = 0x,
    [FFF] = 0x,
    [GGG] = 0x,
    [HHH] = 0x,
    [JJJ] = 0x,
    [KKK] = 0x,
    [LLL] = 0x,
    [MMM] = 0x,
    [NNN] = 0x,
    [OOO] = 0x,
    [PPP] = 0x,
    [QQQ] = 0x1F1E7,
    [RRR] = 0x,
    [SSS] = 0x1F1F8,
    [TTT] = 0x,
    [UUU] = 0x,
    [VVV] = 0x,
    [WWW] = 0x,
    [XXX] = 0x,
    [YYY] = 0x,
    [ZZZ] = 0x,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        add_keylog(keycode);
    }
#endif

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

        case UNIG:
          if (record->event.pressed) {
            SEND_STRING(":regional_indicator_i: :regional_indicator_s: :regional_indicator_n: :regional_indicator_t:  :regional_indicator_u: :regional_indicator_n: :regional_indicator_i: :regional_indicator_c: :regional_indicator_o: :regional_indicator_d: :regional_indicator_e:  :regional_indicator_g: :regional_indicator_r: :regional_indicator_e: :regional_indicator_a: :regional_indicator_t: ");
          } else {
          }
          break;

        case SSH_PI:
          if (record->event.pressed) {
              SEND_STRING("ssh pi@applepi.local"SS_TAP(X_ENTER));
          } else {
          }
          break;

        case COMP6:
          if (record->event.pressed) {
              SEND_STRING("qmk compile -kb crkbd -km 6col"SS_TAP(X_ENTER));
          } else {
          }
          break;

        case COMPKB:
          if (record->event.pressed) {
            SEND_STRING("qmk compile -kb handwired/kb -km default"SS_TAP(X_ENTER));
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
            SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DELETE))));
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

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_MOD:
        case RGB_TOG:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            /* Override layer-based RGB and resume RGB effect to be able to preview changes */
            if (record->event.pressed) {
                restore_rgb_config();
                process_rgb(keycode, record);
                save_rgb_config();
            }
            return false;
        case RGBRST:
            if (record->event.pressed) {
#    ifdef RGBLIGHT_ENABLE
                eeconfig_update_rgblight_default();
                rgblight_enable();
#    elif RGB_MATRIX_ENABLE
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
#    endif
                save_rgb_config();
            }
            return false;
#endif
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
