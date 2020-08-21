#pragma once

enum unicodemap_names {
  STAR,
  HAP,
  KEEB,
  SIDE,
  UPAR
};

 const uint32_t PROGMEM unicode_map[] = {
  [STAR] = 0x2605,
  [HAP] = 0x1F604,
  [KEEB] = 0x2328,
  [SIDE] = 0x30C4,
  [UPAR] = 0x16CF,
};
