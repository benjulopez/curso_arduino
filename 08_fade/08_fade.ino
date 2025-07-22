#define LED_1 15
#define LED_2AZUL 12
#define LED_1ROJO 15


void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_1ROJO, OUTPUT);
  pinMode(LED_2AZUL, OUTPUT);

}

void loop() {
  /*digitalWrite(LED_1, HIGH);  // encendido el LED_1
  delay(1000);
  digitalWrite(LED_1, LOW);     // apagado el LED_1
  delay(1000);*/
  /*analogWrite(LED_1, 20); // valor analogico, le mandamos un valor de intensidad de iluminación.
  delay(50);
  analogWrite(LED_1, 80);
  delay(500);
  analogWrite(LED_1, 160);
  delay(500); */

  // El LED_1, se enciende y se apaga progresivamente.
  
  for(int i = 0; i<=255; i++){
  analogWrite(LED_1ROJO, i);
  analogWrite(LED_2AZUL, 255-i);
  delay(10); 
}
  delay(1000);

  for(int i = 255; i>=0; i--){
  analogWrite(LED_2AZUL, i);
  analogWrite(LED_1ROJO, 255-i);
  delay(10); 
}
  delay(1000);
  
}