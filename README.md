# Proton-C compatible crkbd keyboard 
![CRKBD](https://raw.githubusercontent.com/wafflekeebs/waffle_corne/proton-c/images/crkbd.png)

* Thank you to [Drashna](https://github.com/drashna) & [Tzarc](https://github.com/tzarc) for all the help on this project :3
## PCB Info. 
The [PCB](https://github.com/foostan/crkbd.git) has been modified to accomodate the STM32F303 based [Proton-C](https://qmk.fm/proton-c/) microcontroller. Some of these changes include: 
* Moving the TRRS data line to the TX pin (A9). 
* Moving the LED data line to ADC3-12 (B0).
* Pull-up resistors between VCC and Serial Data.
Other changes that weren't required:
* Add RGB strip headers 
* Remove SMD RGB LEDs

## Firmware Info. 

 
