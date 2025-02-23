# arduino_m5stickCplus_dac

Use m5stickCPlus as a fixed voltage generator from 0 to 3.3V.

 - The output dac is on PIN 26
 - press A increment DAC by 10
 - press B increment DAC by 50

Nota :
 - if DAC value is over 255, the adc is fix to 255
 - if DAC is equal of 255, the adc return to 0. 
 - The value of DAC and the voltage are noticed on the screen.
