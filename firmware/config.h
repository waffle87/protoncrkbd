#pragma once
#include "config_common.h"
#undef PRODUCT
#undef MANUFACTURER
#define MANUFACTURER Waffles
#define PRODUCT Protorne Keyboard
#undef USE_I2C
#undef SSD1306OLED
#define MASTER_LEFT
#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#undef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
//#define RGBLED_NUM 42
//#define RGBLED_SPLIT { 21, 21 }
#define RGBLED_NUM 24
#define RGBLED_SPLIT { 12, 12 }
#define RGB_DI_PIN B5
#define RGBLIGHT_LIMIT_VAL 175
#endif
#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 50000
#define OLED_FONT_H "keyboards/crkbd/rev1/common/keymaps/arm/glcdfont.c"
#endif
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B6 }
#define ENCODERS_PAD_A_RIGHT { B2 }
#define ENCODERS_PAD_B_RIGHT { B6 }
