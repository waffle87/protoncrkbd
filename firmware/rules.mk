MCU = STM32F303
CTPC = yes
DEBUG_MATRIX_SCAN_RATE_ENABLE = yes #Outputs matrix scan rate in QMK Toolbox
SERIAL_DRIVER = usart
WS2812_DRIVER = pwm
#PWM needs patch to <https://github.com/qmk/qmk_firmware/blob/master/platforms/chibios/GENERIC_STM32_F303XC/configs/proton_c.mk>, otherwise defaults to bitbang.
#See develop PR <https://github.com/qmk/qmk_firmware/pull/11864>
MOUSEKEY_ENABLE = yes
VIA_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
AUDIO_ENABLE = no
GRAVE_ESC_ENABLE = no
EXTRAKEY_ENABLE = yes
COMMAND_ENABLE = no
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes
AUTO_SHIFT_ENABLE = no
SWAP_HANDS_ENABLE = no
CONSOLE_ENABLE = yes
COMBO_ENABLE = yes
BOOTMAGIC_ENABLE = lite
TAP_DANCE_ENABLE = yes
POINTING_DEVICE_ENABLE = no
SPLIT_KEYBOARD = yes
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = yes
HAPTIC_ENABLE = no

ifdef POINTING_DEVICE_ENABLE
	SRC += i2c_master.c
endif

ifeq ($strip $(WAFFLE)), yes)
	OPT_DEFS += -DWAFFLE
endif

