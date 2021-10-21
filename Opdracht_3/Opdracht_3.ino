int var = 0; // Waarde die wordt doorgegeven door de potmeter
void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(A5, INPUT); // Analoge pin voor de potmeter
}

void loop(){
  var = analogRead(A5);
  
  if(var < 15){ // Hoe hoger de waarde die wordt doorgeven voor de positie/draai van de potmeter. Hoe meer Leds er steeds aan gaan.
   digitalWrite(13, 0);
   digitalWrite(12, 0);
   digitalWrite(11, 0);
   digitalWrite(10, 0);
   digitalWrite(9, 0);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 150){
   digitalWrite(13, 1);
   digitalWrite(12, 0);
   digitalWrite(11, 0);
   digitalWrite(10, 0);
   digitalWrite(9, 0);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 285){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 0);
   digitalWrite(10, 0);
   digitalWrite(9, 0);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 420){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 1);
   digitalWrite(10, 0);
   digitalWrite(9, 0);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 555){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 1);
   digitalWrite(10, 1);
   digitalWrite(9, 0);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 690){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 1);
   digitalWrite(10, 1);
   digitalWrite(9, 1);
   digitalWrite(8, 0);
   digitalWrite(7, 0);
  }else if(var < 825){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 1);
   digitalWrite(10, 1);
   digitalWrite(9, 1);
   digitalWrite(8, 1);
   digitalWrite(7, 0);
  }else if(var < 960){
   digitalWrite(13, 1);
   digitalWrite(12, 1);
   digitalWrite(11, 1);
   digitalWrite(10, 1);
   digitalWrite(9, 1);
   digitalWrite(8, 1);
   digitalWrite(7, 1);
  }
}
  
