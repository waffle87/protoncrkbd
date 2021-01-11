# Proton-C compatible crkbd keyboard 

The PCB has been modified to accomodate the STM32F303 based Proton-C microcontroller. Some of these changes include: 
* Moving the TRRS data line to the TX pin (A9). 
* Moving the LED data line to ADC3-12 (B0).
* Pull-up resistors between VCC and Serial Data.
Other changes that weren't required:
*Add RGB strip headers 
*Remove SMD RGB LEDs
 
