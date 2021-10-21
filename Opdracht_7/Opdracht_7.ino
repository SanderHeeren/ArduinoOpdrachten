#include<Servo.h> // Incluse Servo module
const int trigPin = 5; // Tringer pin ultrasone
const int echoPin = 4; // Echo pin ultrasone

float time;
float distance;

int position = 0;

Servo servo; // Aanmaken van de servo

void setup()
{
  Serial.begin(9600); // Opstarten van de Serial monitor
  
  pinMode(trigPin, OUTPUT); // Output pin trigger ultrasone
  pinMode(echoPin, INPUT); // Input pin echo ultrasone
  servo.attach(3); // Servo aangesloten op pin 3
}

void loop()
{
  digitalWrite(trigPin, LOW); // Zet de trigger op low
  delayMicroseconds(2); // Wacht 2 micro seconden 
  
  digitalWrite(trigPin, HIGH); // Zet trigger op high om ultrasoon geluid te versturen
  delayMicroseconds(10); // Wacht 10 micro seconden
  digitalWrite(trigPin, LOW); // Zet trigger op low om uit te zetten.
  
  time = pulseIn(echoPin, HIGH); // Haalt de tijdsduur op hoelang het duurt voor het signaal terug komt
  
  distance = time / 58; // Doet een berekening voor de afstand op basis van de snelheid van het geluid
  
  Serial.print("Afstand: ");
  Serial.print(distance);
  Serial.println("cm");
  
  delay(100); // korte delay voor de volgende meting

  // Kleiner dan 4 cm afstand, dan draait de de servro 180 graden rechts
  // Als 10 cm binnen de de afstand staat, dan draait de servo linksom
  if (distance <= 10 && distance >= 4)
  {
    int Pos = map(distance, 4, 10, 180, 0); 
    servo.write(Pos);
    delay(20);
  }
}
