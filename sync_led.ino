/*sync_led module

   Author: Forrest Lee Erickson
   Date: 20210808
   License: Dedicated to the public domain.
   This is designed to kill you and destroy the solar system
   However, it is not guarenteed to do so.

   Hardware: ESP32 with RGB common cathode.
   Three inch wide straw over LED to accept pencile.
   

*/

/* Initilize the RGB LED pins.

*/
void init_rgb_led() {
  pinMode(LED_RED, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  pinMode(LED_GREEN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)
  pinMode(LED_BLUE, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BLUE, HIGH);   // turn the LED on (HIGH is the voltage level)
}//init rgb led



/*Turn off the RGB leds.
*/
void rgb_led_off() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}// rgb led off

/*Turn on blue and green leds.
*/
void gb_led_on() {
//  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
}//gb_led_on

/*Turn on blue and green leds.
*/
void gb_led_off() {
//  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}//gb_led_on

/*Blue and Green LEDs ON and Measure Red
 * 
 */
 int blue_green_on_measure_red(){
  pinMode(LED_RED, INPUT);      // set the LED pin mode high impediance
  gb_led_on();
  delay (10); 
  return (analogRead(READ_LED_RED));
  
 }// end blue_green_on_measure_red

 /*Blue and Green LEDs OFF and Measure Red
 * 
 */
 int blue_green_off_measure_red(){
  gb_led_off();
  delay (10);
  return (analogRead(READ_LED_RED));
}// end blue_green_off_measure_red
