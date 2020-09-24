# 6col
6 Column Corne Keyboard Firmware 


# Important Info. 
**If you have updated your qmk_firmware repo anytime after September 17th, 2020, (crkbd was ported to split common) you will need to change which I2C driver is used.**

You will get an error compiling that looks something like this: 
![I2C Error Image](https://raw.githubusercontent.com/toastedmangoes/6col/master/images/new-i2c-image.png)

The fix to this error is opening up the post_config.h file in `crkbd -> rev1 -> legacy -> post_config.h`. In here, comment out lines 20 to 24 or 
```c
#ifdef SSD1306OLED
#    define USE_I2C
#endif
```
