int red_pin= 11; // Rode pin
int green_pin = 10; // Groene pin
int blue_pin = 9; // Blauwe pin

void setup() {
  pinMode(red_pin, OUTPUT); // Rode pin output
  pinMode(green_pin, OUTPUT); // Groene pin output
  pinMode(blue_pin, OUTPUT); // Blauwe pin output
}

void loop() {
  RGB_color(255, 0, 0); // Rood
  delay(1000); // Delay van 1000 milliseconden
  RGB_color(0, 255, 0); // Groen
  delay(1000);
  RGB_color(0, 0, 255); // Blauw
  delay(1000);
  RGB_color(255, 255, 125); // Roze
  delay(1000);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Paars
  delay(1000);
  RGB_color(255, 255, 0); // Geel
  delay(1000);
  RGB_color(255, 255, 255); // Wit
  delay(1000);
}

void RGB_color(int red_value, int green_value, int blue_value) // Geef de 3 waardes van de kleuren door
 {
  analogWrite(red_pin, red_value); // Geeft de waardes van de kleuren door naar de juiste pins
  analogWrite(green_pin, green_value);
  analogWrite(blue_pin, blue_value);
}
