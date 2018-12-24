# coin-relay: A Coin Operated Relay Switch
<img src="https://github.com/andyrew/coin-relay/blob/master/photos/IMG_5289.jpg" width="48%" alt="Coin Operated Relay">
<img src="https://github.com/andyrew/coin-relay/blob/master/photos/IMG_5292.JPG" width="48%" alt="Coin Operated Relay with Christmas Tree">
Inserting coins into the coin acceptor turns on the relay controlled outlet and adds time to the timer. When the timer runs out, the relay turns off the outlet. What ever you'd like to control with the coin acceptor can be plugged into the relay outlet. I initially used this project to operate our christmas tree lights, but can be used to operate any plug load.

#### For $114 in parts and about 6 hours of time, you too can nickel and dime your family!

## Hardware Components ($104):
- Coin Acceptor (https://www.adafruit.com/product/787)
- Relay Controlled outlet (https://www.adafruit.com/product/2935)
- 7-segment display with I2C backpack (https://www.adafruit.com/product/878)
- Arduino Uno (http://a.co/d/edHdN7I)
- 10 kohm resistor (https://www.adafruit.com/product/2784)
- wire (https://www.adafruit.com/product/2051)
- 12V power supply (https://www.adafruit.com/product/798)

### Optional Components ($10):
- Arduino proto shield (https://www.adafruit.com/product/2077)
I use proto shields for most of my projects. I start with a breadboard to make sure I've connected everything properly and that it works, then I soldier everything to a proto-shield for longeviety.

## Connecting
- For simplicity, power the arduino with the 12V power supply to the barrel connector, and connect the red wire of the coin acceptor to the Vin pin on the arduino. The Arduino Vin pin is connected to the power supply before the rectifier, so it will output 12V if the arduino is powered with a 12V supply. 
- Connect the coin acceptor's black wire to the ground pin of the Arduino.
- Connect the coin acceptor's grey wire to digital pin 2 of Arduino.
- Connect the coin acceptor's white wire to one end of the 10 kohm resistor. Connect the other end of the resistor to 5V on the arduino.
- Connect the 7-segment display to the arduino as described by adafruit (https://learn.adafruit.com/adafruit-led-backpack/0-dot-56-seven-segment-backpack).

## Train the coin acceptor
- Power and train the coin acceptor with the coins you wish to accept as described by adafruit (https://learn.adafruit.com/arcade-coin-op/train-the-coin-acceptor)
- I trained mine as follows:
  - penny - 1 pulse
  - nickle - 5 pulses
  - dime - 10 pulses
  - quarter - 25 pulses

## Software
- Install arduino ide (https://www.arduino.cc/en/Main/Software)
- download and install both arduino libraries required for the display backpack from adafruit (https://learn.adafruit.com/adafruit-led-backpack/downloads).
- download CoinAcceptorRelay.ino from this repository.
- connect your arduino to your computer with a USB cable.
- Open CoinAcceptorRelay.ino in the arduino ide.
- adjust seconds per pulse to your desired rate (it is currently set to 60 seconds per pulse).
- compile and upload code to arduino (make sure you have selected the port with tools->port menu).
- insert coins to test.

## Case
This repository contains the svg file for the case I made for my coin acceptor (CoinRelayBox.svg). This was cut out of 2.92mm thick correguated cardboard (Amazon boxes) with a laser cutter.

<img src="https://github.com/andyrew/coin-relay/blob/master/CoinRelayBox.svg" width="400" alt="Case SVG File">
