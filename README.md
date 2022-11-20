### proton-c compatible crkbd pcb
### info
#### changes:
* usart full duplex communication (t**rr**s cable required!)
* move led data to pin with general purpose timer (ADC3-12/B0)
* add piezo buzzer (AST1109MLTRQ)
* add two rotary encoder positions
* add pimoroni trackball support (footprint thanks to [MangoIV](https://github.com/MangoIV))
(latest-commit pcbs are currently untested)

#### parts 
item | count
------------ | -------------
[1N4148 diodes (SOD-123)](https://www.aliexpress.com/item/3256802197190733) | 42
[SK6812 mini-e leds](https://www.aliexpress.com/item/4000475685852.html) | 42
[WS2812B leds](https://www.aliexpress.com/item/32732686773.html) | 12
[kailh mx sockets](https://www.aliexpress.com/item/4000019410050.html) | 42
[proton-c](https://qmk.fm/proton-c/) or [bonsai-c](https://github.com/customMK/Bonsai-C) | 2
[EC11 rotary encoders](https://www.aliexpress.com/item/2251832789732148) | 2
[PJ320A trrs jack](https://www.aliexpress.com/item/4000661212458.html) | 2
[reset switch](https://www.aliexpress.com/item/1255399892.html) | 2
[AST1109MLTRQ speakers](https://www.aliexpress.com/item/32558833519.html) | 2
[128x32 oled display](https://www.aliexpress.com/item/32794209149.html) | 2
[mcu/oled sockets](https://www.aliexpress.com/item/32847384633.html) | 2 (40 pos. each, 56 needed)
[oled socket pins](https://www.aliexpress.com/item/32855402975.html) | 1 (40 pos. each, 8 needed)
[mcu millmax pins](https://www.digikey.com/en/products/detail/mill-max-manufacturing-corp/3320-0-00-15-00-00-03-0/4147392) </br> alternatively, diode/resistor legs can be used | 48
pimoroni trackball [UK](https://shop.pimoroni.com/products/trackball-breakout) [EU](https://splitkb.com/collections/keyboard-parts/products/trackball-breakout) [NA](https://www.digikey.com/en/products/detail/pimoroni-ltd/PIM447/10246389) | 1
