/*sync_LED_detector
 * Syncronous LED Light Detection
 * Author: Forrest Lee Erickson
 * Date: 20210808
 * 
 * 
 * Circuit description
 * RGB LED, common cathode. Cathode ground.
 * ESP32 Pin  Resistor Pin 
 * GPIO12     R1-1
 * GPIO14     R2-1
 * GPIO27     R3-1
 * ADC0       R1-1
 * ADC3       R2-1
 * ADC6       R3-1
 * 
 * Note all resistors 300 Ohms.
 * Resistor   LED
 * R1-2       Anode red
 * R2-2       Anode green
 * R3-2       Anode blue
 * 
 * GND        LED Common cathode
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

//Functions
//Wink the LED
void wink() {
  if (((millis() - lastLEDtime) > nextLEDchange) || (millis() < lastLEDtime)) {
    if (digitalRead(LED_BUILTIN) == LOW) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = HIGH_TIME_LED;
    } else {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = LOW_TIME_LED;
    }
    lastLEDtime = millis();
  }//end LED time check
}//End wink

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
// put your setup code here, to run once:
  
  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
}

void loop() {
  // put your main code here, to run repeatedly:
  wink();   //Built in LED
}
