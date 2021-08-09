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
const int READ_LED_RED = 36; //GPIO36


//Set LED for Uno or ESP32 Dev Kit on board blue LED.
const int LED_BUILTIN = 2;    // ESP32 Kit
//const int LED_BUILTIN = 13;    //Not really needed for Arduino UNO it is defined in library
const int HIGH_TIME_LED = 900;
const int LOW_TIME_LED = 100;
long lastLEDtime = 0;
long nextLEDchange = 100; //time in ms.

const String COMPANY = "Amused Scientist";
const String MODEL_NAME = "sync_LED_detector";
const String VERSION = "0.0.1";

int difference_on_off;

//Functions
void serial_splash_print() {
    //  Serial splash message
  Serial.print(COMPANY);
  Serial.print(": ");
  Serial.println(MODEL_NAME);
  Serial.print("VERSION: ");
  Serial.println(VERSION);
  Serial.println();
}// end splash_startup


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  serial_splash_print();

  //Setup RGB LED drive. Turn on all for white.
  init_rgb_led();
  delay(1000);  // Just so we see for a second
  rgb_led_off();

  adcAttachPin(READ_LED_RED); //Clears any other modes.

  Serial.println("--- End of setup--");//
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
}

void loop() {
  // put your main code here, to run repeatedly:
  wink();   //Built in LED

  //Measure with LED on and off
//  Serial.print("blue_green_on_measure_red= ");//
//  Serial.println(blue_green_on_measure_red());
//  Serial.print("blue_green_off_measure_red= ");//
//  Serial.println(blue_green_off_measure_red());
//  Serial.println();//

Serial.print("Difference= ");//
  difference_on_off = blue_green_on_measure_red()-blue_green_off_measure_red() ;
  Serial.println( difference_on_off);

  
}
