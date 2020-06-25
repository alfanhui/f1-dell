#!/bin/bash
echo "erasing..."
dfu-programmer atmega16u2 erase
echo "flashing... "
dfu-programmer atmega16u2 flash --debug 1 arduino-usb/firmwares/arduino-usbserial/Arduino-usbserial-uno.hex
echo "resetting..."
dfu-programmer atmega16u2 reset 
