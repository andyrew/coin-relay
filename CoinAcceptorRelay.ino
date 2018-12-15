
#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

// This version of the code does not use attachInterrupt, because it was found
// to be affected noise from the relay switching and less reliable than checking
// the pin regularly.


// Connection Pins
int coin_pin = 2; 
int relay_pin = 10;

// Initialize timer
float seconds = 0;

// Set the number of seconds per pulse from the coin acceptor
int secondsperpulse = 60; 

// Set the frequency of the loop function in ms, has to be less
// than the length of the coin acceptor pulse length
// and must be a factor of 1000.
int looprate = 20;

// Variables for flasing colon
bool colon_flash = true;
int flashcount = 0;
int flashrate = 500 / looprate;

// Variables for checking the coin acceptor pin
bool last = HIGH;
bool now = HIGH;

// Initialize seven segment display matrix
Adafruit_7segment matrix = Adafruit_7segment();
 
void setup() 
{ 
pinMode(coin_pin, INPUT_PULLUP);
pinMode(relay_pin, OUTPUT);
digitalWrite(relay_pin, LOW);

// initialize display matrix
matrix.begin(0x70);

} 
 
void loop() 
{ 
  update_display();

  // if there is time on the timer decrement and turn on relay
  if (seconds > 0) { 
    seconds -= looprate/1000.; 
    digitalWrite(relay_pin, HIGH);
  }

  // if there is not time on the timer turn off relay
  if (seconds <= 0 ){
    digitalWrite(relay_pin, LOW);
  }
  
  // check the coin acceptor pin
  now = digitalRead(coin_pin);
  
  // if is low now and was high the last time through the loop, it's a new pusle.
  if(now == LOW and last == HIGH ) {count_pulse();}

  // update the last variable for the next time through the loop
  last = now;

  // wait the appropriate time before starting the next loop.
  delay(looprate); 

}




 
void count_pulse() 
{ 
  seconds += secondsperpulse; 
  //seconds += secondsperpulse + looprate / 1000. + 0.099; 
}



void update_display()
{
  // show seconds plus one 
  // (so the lights turn off when the timer hits zero, not a second later) 
  float disp_seconds = seconds + 0.99;

  if(seconds >= 3600) {
    // If there is more than an hour on the timer, show hours and minutes
    if(seconds >= 36000){
      //only show the tens digit if there is ten or moure hours
      matrix.writeDigitNum(0, int(disp_seconds/3600/10)%10, false);
    }else{
      matrix.writeDigitNum(0, 16, false);
    }
    matrix.writeDigitNum(1, int(disp_seconds/3600)%10, false);
    matrix.writeDigitNum(3, int(disp_seconds/60/10)%6, false);
    matrix.writeDigitNum(4, int(disp_seconds/60)%10, false);
    matrix.drawColon(colon_flash);

  }else if (seconds > 0){
    // If there is less than an hour but more than 0 seconds, display Minutes and Seconds
    if(seconds >= 600){
      // Only show the tens digit of minutes if there are ten or more minutes.
      matrix.writeDigitNum(0, int(disp_seconds/60/10)%6, false);
    }else{
      matrix.writeDigitNum(0, 16, false);
    }
    matrix.writeDigitNum(1, int(disp_seconds/60)%10, false);
    matrix.writeDigitNum(3, int(disp_seconds/10)%6, false);
    matrix.writeDigitNum(4, int(disp_seconds)%10, false);
    matrix.drawColon(colon_flash);
    
  }else{ 
    //If there is no time on the timer show nothing on the display
    matrix.writeDigitNum(0, 16, false);
    matrix.writeDigitNum(1, 16, false);
    matrix.writeDigitNum(3, 16, false);
    matrix.writeDigitNum(4, 16, false);
    matrix.drawColon(false);
  }

  // Flash the display if there are less than 10 seconds
  if(seconds > 1 and seconds < 10){
    matrix.blinkRate(2);
  }else{
    matrix.blinkRate(0);
  }

  // Update the flash variable for the colon
  flashcount += 1;
  if (flashcount >= flashrate) {
     colon_flash = not(colon_flash);
     flashcount = 0;
  }

  matrix.writeDisplay();
  
}

