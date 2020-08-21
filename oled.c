#pragma once

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

void render_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(font_qmk_logo, false);
};

void render_kb_split(void) {
    static const char PROGMEM font_kb_split[11] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0};
    oled_write_P(font_kb_split, false);
};

void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;

    if (layer_state_is(_LOWER)) {
        oled_write_ln_P(blink ? PSTR("> lo_") : PSTR("> lo "), false);
    } else if (layer_state_is(_RAISE)) {
        oled_write_ln_P(blink ? PSTR("> hi_") : PSTR("> hi "), false);
    } else if (layer_state_is(_ADJUST)) {
        oled_write_ln_P(blink ? PSTR("> aj_") : PSTR("> aj "), false);
    } else {
        oled_write_ln_P(blink ? PSTR("> _ ") : PSTR(">     "), false);
    }
};

void render_status_secondary(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_kb_split();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);
}


void render_status_main(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_qmk_logo();

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_prompt();
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    char wpm_string[5];

      oled_write_ln("WPM:", false);
      snprintf(wpm_string,
    sizeof(wpm_string), " %3d",
    get_current_wpm());
      oled_write(wpm_string, false);
    render_status_main();
  } else {
    render_status_secondary();
  }
}

#endif




/*
char wpm_string[5];

  oled_write_ln("WPM:", false);
  snprintf(wpm_string,
sizeof(wpm_string), " %3d",
get_current_wpm());
  oled_write(wpm_string, false);
*/
