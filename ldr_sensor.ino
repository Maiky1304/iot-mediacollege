// A0 is de inputpin voor de lichtgevoelige weerstand LDR 
// A0 is een analoge ingang
int LDR_In = A0; // de spanningsdeler wordt aangesloten op A0

// variable lichtHoeveelheid
int lichtHoeveelheid;


//leds
uint8_t Led1 = D3;//Led op D3
uint8_t Led2 = D5;//Led op D5
uint8_t Led3 = D6;//Led op D6

void setup() {  
  Serial.begin(9600); // start de serial monitor 9600 Baud
}

void loop() {
  // lees de input waarde van de LDR
  lichtHoeveelheid = analogRead(LDR_In);
  // schrijf de waarde naar de Serial Monitor
  Serial.println(lichtHoeveelheid);

  if ( lichtHoeveelheid < 400){
    //donker, Led aan
    digitalWrite(Led1, HIGH);
  } else {
    //Licht, Led uit
    digitalWrite(Led1, LOW);
  }

  if ( lichtHoeveelheid < 600){
     //donker, Led aan
     digitalWrite(Led2, HIGH);
  } else {
    //Licht Led uit
    digitalWrite(Led2, LOW);
  }

  if ( lichtHoeveelheid < 750){
     //donker, Led aan
     digitalWrite(Led3, HIGH);
  } else {
    //Licht Led uit
    digitalWrite(Led3, LOW);
  }

  delay(1000);
}