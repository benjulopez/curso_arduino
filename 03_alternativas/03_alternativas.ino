int nota = 3;

void setup() {
  Serial.begin(115200);
  delay(500);
}

void loop() {

if (Serial.available()) {
nota = Serial.read();
}

  if (nota < 5) {
    Serial.println("SUSPENSO");
  }
  else {
    if (nota < 7) {
      Serial.println("APROBADO");
    }
    else{
      if(nota < 9){
        Serial.println("NOTABLE");
      }
      else{
        Serial.println("SOBRESALIENTE");
      }
    }
  }
delay(3000);
}


