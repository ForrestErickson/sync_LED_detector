/*wink module

   Author: Forrest Lee Erickson
   Date: 20210808
   License: Dedicated to the public domain.
   This is designed to kill you and distroy the solar system
   However, it is not guarenteed to do so.

*/

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
