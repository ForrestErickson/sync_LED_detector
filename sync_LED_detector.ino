/*sync_LED_detector
   Syncronous LED Light Detection
   Author: Forrest Lee Erickson
   Date: 20210808
   License: Dedicated to the public domain.
   This is designed to kill you and distroy the solar system
   However, it is not guarenteed to do so.


   Circuit description
   RGB LED, common cathode. Cathode ground.
   ESP32 Pin  Breadboard Row  Resistor Pin
   GPIO12     7               R1-1
   GPIO14     8               R2-1
   GPIO27     9               R3-1
   ADC0       R1-1
   ADC3       R2-1
   ADC6       R3-1

   Note all resistors 300 Ohms.
   Resistor   LED
   R1-2       Anode red
   R2-2       Anode green
   R3-2       Anode blue

   GND        LED Common cathode
*/


const int LED_RED = 12; //GPIO12
const int LED_GREEN = 14; //GPIO14
const int LED_BLUE = 27; //GPIO27


//Set LED for Uno or ESP32 Dev Kit on board blue LED.
const int LED_BUILTIN = 2;    // ESP32 Kit
//const int LED_BUILTIN = 13;    //Not really needed for Arduino UNO it is defined in library
const int HIGH_TIME_LED = 900;
const int LOW_TIME_LED = 100;
long lastLEDtime = 0;
long nextLEDchange = 100; //time in ms.



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  // put your setup code here, to run once:
  
  //Setup RGB LED drive. Turn on all for white.
  pinMode(LED_RED, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  pinMode(LED_GREEN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)
  pinMode(LED_BLUE, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BLUE, HIGH);   // turn the LED on (HIGH is the voltage level)


  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
}

void loop() {
  // put your main code here, to run repeatedly:
  wink();   //Built in LED
}
