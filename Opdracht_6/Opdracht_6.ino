#include<Servo.h> // Incluse servo module 
int KNOP1 = 11; // Knop 1 op pin 11
int KNOP2 = 10; // Knop 2 op pin 10
Servo servo; // Aanmaken van de servo

void setup() {
  pinMode(KNOP1, INPUT); // Knop 1 input
  pinMode(KNOP2, INPUT); // Knop 2 input
  servo.attach(5); // Servomoter toevoegen aan pin 5
}

void loop() {
  int status1 = digitalRead(KNOP1); // De satus van knop 1 
  int status2 = digitalRead(KNOP2); // De satus van knop 2

  if (status1 == HIGH && status2 == LOW) { // Als alleen knop 1 is ingedrukt
    servostart(8, 0); // Waardes doorgeven aan de servomoter modules (120 graden draaien in 1 seconde)
  }
  
  else if (status1 == LOW && status2 == HIGH) { // Als alleen knop 2 is ingedrukt
    servostart(4, 0); // Waardes doorgeven aan de servomoter modules (120 graden draaien in 0.5 seconde)
  }
  
  else if (status1 == HIGH && status2 == HIGH) { // Als beiden knoppen tegelijk zijn ingedrukt
    servostart(8, 2000); // Waardes doorgeven aan de servomoter modules (120 graden draaien in 1 seconde, vervolgens 2 seconden stil blijven staan)
  }
  else { // geen knop is ingedrukt
    servo.write(0); 
  }
}

void servostart(int delay1, int delay2) {
  for (int positie = 0; positie <= 120; positie++) { // Servo naar positie sturen
    servo.write(positie);
    delay(delay1);
  }
  delay(delay2); // Delay om Servo terug te sturen

  for (int positie = 120; positie >= 0; positie--) { // servo terug te sturen
    servo.write(positie);
    delay(delay1);
  }
}
