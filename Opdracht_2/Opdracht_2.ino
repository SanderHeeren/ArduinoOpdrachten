const int BUTTON = 1; // Knop op pin 1
const int LED = 11; // Led op pin 11
int BUTTONstate = 0; // Status van de button (HIGH of LOW)
int Count = 0;

void setup()
{
  pinMode(BUTTON, INPUT); // Button als input
  pinMode(LED, OUTPUT); // Led als output
}

void loop()
{
  BUTTONstate = digitalRead(BUTTON); // = HIGH op het moment dat de knop word ingedrukt
  if (BUTTONstate == HIGH) // Wordt de knop ingedrukt dan..
  {
    Count++; // +1 
    delay(300); // Delay van 300 milliseconden
  } 
  if (Count % 2 == 0){ // Om en om met iedere button click gaat de led aan of uit
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }
}
