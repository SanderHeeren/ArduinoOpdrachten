char msg = 0; // Character dat straks moet worden ontvangen
const int ledPins[] = {2, 3, 4}; // Array van led pins

long interval1 = 12000, interval2 = 18000; // Intervals voor de duratie van de lichten 
extern volatile unsigned long timer_millis; // Timer van de Millis
unsigned long previousMillis = 0; // Vorige opgeslagen tijd
int ledState = LOW; // Status van de led voor oranje

void setup()
{
  Serial.begin(9600); // Zet Serial monitor aan

  pinMode (ledPins[0], OUTPUT); // Koppel pins aan leds uit de array
  pinMode (ledPins[1], OUTPUT);
  pinMode (ledPins[2], OUTPUT);
  digitalWrite(ledPins[0], HIGH); // Rood start op HIGH
}

void loop()
{  
  unsigned long currentMillis = millis(); // Huidige tijd 

  if (currentMillis > interval1 && 
      currentMillis < interval2) { // Als tijd groter dan interval1 (12 seconden), en korter dan interval2 (18 seconden) dan..

    digitalWrite(ledPins[0], LOW);  // Rood uit 
    digitalWrite(ledPins[1], HIGH); // Oranje aan
  }
  
  if (currentMillis > interval2 &&
     currentMillis < (interval1 + interval2)) { // Als tijd groter dan interval2 (18 seconden), en korter dan interval2 en 1 samen (30 seconden) dan..

    digitalWrite(ledPins[1], LOW);  // Oranje uit
    digitalWrite(ledPins[2], HIGH); // Groen aan
  }
  
  if(currentMillis > (interval1 + interval2)){ // Als de huidige tijd langer is dan 30 seconden
    digitalWrite(ledPins[2], LOW); // Groen uit
    
    if (currentMillis - previousMillis >= 1000) { // Voer deze code uit elke 1 seconde
      previousMillis = currentMillis; // Zet vorige millis als huidige

      if (ledState == LOW) { // Zet leds aan en uit elke 1 seconde te blinken
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      digitalWrite(ledPins[1], ledState); // Aan/Uit voor oranje
    }

    // Om berichten te ontvangen via het bluetooth device
    if (Serial.available() > 0){ // Controleer of er iets binnen komt
      msg = Serial.read(); // Lees het bericht en verander het in de waarde
      Serial.println("Android Command: " + msg); // Serial print het doorgegeven bericht
    }
  }
  
  if (msg == '1') { // Als het verzonden bericht 1 is dan
        digitalWrite(ledPins[0], HIGH); // Rood aan
        digitalWrite(ledPins[1], LOW); // Oranje uit
        noInterrupts();
        timer_millis = 0; // Reset millis timer om stoplicht loop opnieuw te beginnen
        interrupts();
        msg = 0; // Zet message weer naar 0
    }
}
