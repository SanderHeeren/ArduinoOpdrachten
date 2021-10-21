//Port temp
const int tempPin = A0; // Een analoge pin die is aangesloten op een temperatuur meter

void setup()
{
// Om de Serial monitor aan te zetten 
Serial.begin(9600);
}

void loop()
{
// het uitlezen van de waardes die worden doorgegeven door de analoge pin
int temp = analogRead(tempPin);
// Waardes omzetten naar graden celsius
temp = temp * 0.48828125;
// Print naar de console
Serial.print("Temperatuur in graden Celsius: ");
Serial.println(temp);
// Delay voor het printing
delay(1000);
}
