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
#include "config_common.h"

#undef PRODUCT
#undef MANUFACTURER
#define MANUFACTURER Waffle
#define PRODUCT Protorne Keyboard

#undef USE_I2C
#undef SSD1306OLED

#define EE_HANDS
//#define MASTER_LEFT
// #define MASTER_RIGHT

#define USE_SERIAL_PD2
#define RANDICT //this literally adds 8000 bytes to your compiled firmware

#undef RGBLED_NUM
#undef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 24
#define RGB_DI_PIN B5
#define RGBLED_SPLIT { 12, 12 }
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_SLEEP
//#define RGBLIGHT_LAYERS

#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 5
#endif

#ifdef BOOTMAGIC_ENABLE
// top left and top right
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif

#ifdef UNICODEMAP_ENABLE
#define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX
#define UNICODE_CYCLE_PERSIST false
#endif

#ifdef AUTOSHIFT_ENABLE
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 170
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#endif

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 150

#ifdef COMBO_ENABLE
  #define COMBO_COUNT 13
  #define COMBO_TERM 50
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 10000
#define OLED_DISABLE_TIMEOUT
#define OLED_FONT_H "keyboards/crkbd/rev1/common/keymaps/waffle_arm/glcdfont.c"
#endif

//RGB using PWM on pin B0
#define WS2812_PWM_DRIVER PWMD2  // default: PWMD2
#define WS2812_PWM_CHANNEL 2  // default: 2
#define WS2812_PWM_PAL_MODE 2  // Pin "alternate function" - default: 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP
#define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP

//Serial over USART config
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3  // USART TX pin
#define SELECT_SOFT_SERIAL_SPEED 1 // or 0, 2, 3, 4, 5
#define SERIAL_USART_DRIVER SD1 // USART driver of TX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function" - default: 7
