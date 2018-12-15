# coin-relay
A coin operated relay switch, initially to operate christmas tree lights but can be used to operate any plug load.
Inserting coins into the coin acceptor turns on the relay controlled outlet and adds time to the timer. When the timer runs out, the relay turns off the outlet. What ever you'd like to control with the coin acceptor can be plugged into the relay outlet.

## Hardware Components ($112):
- Coin Acceptor (https://www.adafruit.com/product/787)
- Relay Controlled outlet (https://www.adafruit.com/product/2935)
- 7-segment display with I2C backpack (https://www.adafruit.com/product/878)
- Arduino Uno, or similar (https://www.adafruit.com/product/2488)
- Arduino proto shield (https://www.adafruit.com/product/2077)
- 10 kohm resistor (https://www.adafruit.com/product/2784)
- wire (https://www.adafruit.com/product/2051)
- 12V power supply (https://www.adafruit.com/product/798)

## Case
This repository contains the svg file for the case I made for my coin acceptor (CoinRelayBox.svg). This was cut out of 2.92mm thick cardboard with a laser cutter.

## Connecting
- For simplicity, power the arduino with the 12V power supply to the barrel connector, and connect the red wire of the coin acceptor to the Vin pin on the arduino. The Arduino Vin pin is connected to the powersupply before the rectifier, so it will output 12V if the arduino is powered with a 12V supply. 
- Connect the coin acceptor's black wire to the ground pin of the Arduino.
- Connect the coin acceptor's grey wire to digital pin 2 of Arduino.
- Connect the coin acceptor's white wire to one end of the 10 kohm resistor. Connect the other end of the resistor to 5V on the arduino.
- Connect the 7-segment display to the arduino as described by adafruit (https://learn.adafruit.com/adafruit-led-backpack/0-dot-56-seven-segment-backpack).

## Train coin acceptor
- Power and train the coin acceptor with the coins you wish to accept as described by adafruit (https://learn.adafruit.com/arcade-coin-op/train-the-coin-acceptor)
- I trained mine as follows:
- penny - 1 pulse
- nickle - 5 pulses
- dime - 10 pulses
- quarter - 25 pulses

## Software
- download and install both arduino libraries required for the display backpack from adafruit (https://learn.adafruit.com/adafruit-led-backpack/downloads).
- download CoinAcceptorRelay.ino from this repository.
- adjust seconds per pulse to your desired rate (it is currently set to 60 seconds per pulse).
- compile and upload code to arduino.
- insert coins to test.

