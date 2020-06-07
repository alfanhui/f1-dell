#!/bin/bash
echo "erasing..."
dfu-programmer atmega16u2 erase
echo "flashing... "
dfu-programmer atmega16u2 flash --debug 1 arduino-usb/firmwares/arduino-keyboard/Arduino-keyboard.hex
echo "resetting..."
dfu-programmer atmega16u2 reset 
