# Proton-C compatible crkbd keyboard 
![CRKBD](https://raw.githubusercontent.com/wafflekeebs/waffle_corne/proton-c/images/crkbd.png)
![PCB_LAYOUT](https://raw.githubusercontent.com/wafflekeebs/waffle_corne/proton-c/images/pcb.png)

* Thank you to [Drashna](https://github.com/drashna) & [Tzarc](https://github.com/tzarc) for all the help on this project :3
## PCB Info. - WORKING 
The [PCB](https://github.com/foostan/crkbd.git) has been modified to accomodate the STM32F303 based [Proton-C](https://qmk.fm/proton-c/) microcontroller. Some of these changes include: 
* Moving the TRRS data line to the TX pin (A9). 
* Moving the LED data line to a pin with a general purpose time or similar (ADC3-12/B0).
* Pull-up resistors between VCC and Serial Data (4.7k).
### Other changes that weren't required:
* Add RGB strip headers 
* Remove SMD RGB LEDs

## Firmware Info. 
* Remove the `rules.mk` file in `crkbd/rev1`
* Work in the `crkbd/rev1/common/keymaps` folder as the legacy code will not work. 
* Typing will feel laggy **without** both halves connected. 
* See `rules.mk` for info. regarding using PWM for RGB. (default is bitbang)
