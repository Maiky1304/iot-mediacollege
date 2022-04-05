/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain
  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)
  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

//LED pins 
uint8_t Led1 = D3;          //LED indicator
uint8_t Led2 = D5;          //LED indicator
uint8_t Led3 = D6;          //LED indicator

void setup() {
  pinMode(Led1, OUTPUT);    //Initialize the pin as an output
  pinMode(Led2, OUTPUT);    //Initialize the pin as an output
  pinMode(Led3, OUTPUT);    //Initialize the pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Led1, HIGH); //Turn the LED on (Note that LOW is the voltage level)
  delay(1000);              //Wait for a second
  digitalWrite(Led1, LOW); //Turn the LED off by making the voltage HIGH
  delay(2000);              //Wait for a second
  digitalWrite(Led2, HIGH); //Turn the LED on (Note that LOW is the voltage level)
  delay(1000);              //Wait for a second
  digitalWrite(Led2, LOW);  //Turn the LED off by making the voltage HIGH
  delay(2000);              //Wait for a second two seconds 
  digitalWrite(Led3, HIGH); //Turn the LED on (Note that LOW is the voltage level)
  delay(1000);              //Wait for a second
  digitalWrite(Led3, LOW);  //Turn the LED off by making the voltage HIGH
  delay(2000);
}